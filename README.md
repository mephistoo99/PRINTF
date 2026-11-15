*This project has been created as part of the 42 curriculum by mchaarou.*

# ft_printf

## Description

**ft_printf** is a custom implementation of the standard C library function `printf` (`<stdio.h>`), built from scratch as part of the 42 curriculum. The primary goal of this project is to master **variadic functions** in C (`<stdarg.h>`), understand how arguments are passed at the hardware and ABI level (CPU registers vs. stack memory), and design a modular, extensible string-formatting engine.

The `ft_printf` library replicates the core behavior of `printf` by parsing a format string and handling the required conversion specifiers (`%c`, `%s`, `%p`, `%d`, `%i`, `%u`, `%x`, `%X`, and `%%`), returning the total number of characters written to standard output (`fd 1`) or `-1` if a write error occurs.

---

## Instructions

### Compilation

The project compiles into a static library named `libftprintf.a` using a `Makefile` with the standard 42 compilation flags (`-Wall -Wextra -Werror`).

1. Clone the repository and navigate to the project root:
   ```bash
   git clone <https://github.com/mephistoo99/PRINTF.git> ft_printf
   cd ft_printf
   ```

2. Build the static library:
   ```bash
   make
   ```

3. Available `Makefile` rules:
   * `make` or `make all` — Compiles the source files and archives them into `libftprintf.a`.
   * `make clean` — Removes all compiled object files (`.o`).
   * `make fclean` — Removes object files and the `libftprintf.a` archive.
   * `make re` — Performs a full rebuild (`fclean` followed by `all`).

### Usage & Execution

To use `ft_printf` in your own C project, include the header file `"ft_printf.h"` and link `libftprintf.a` during compilation:

```c
#include "ft_printf.h"

int main(void)
{
    int count;

    count = ft_printf("Hello %s! Hex: %x | Ptr: %p\n", "42", 255, &count);
    ft_printf("Total characters printed: %d\n", count);
    return (0);
}
```

Compile your test file with the library:
```bash
cc -Wall -Wextra -Werror main.c libftprintf.a -o test_printf
./test_printf
```

---

## Algorithm & Data Structure Justification

### Single-Pass Format String Parsing (Direct `write()` Output)

Rather than allocating dynamic memory (`malloc`) to build the full formatted output string before printing, `ft_printf` reads the format string in a single forward loop and writes directly to file descriptor `1` using `write()`:

* **How it works:** A `while` loop iterates through the `const char *` format string one character at a time. Normal characters are written immediately with `write(1, &str[i], 1)`. Whenever a `%` character is encountered, the next character (`str[i + 1]`) is passed to a specifier dispatcher (`print_spf`) that calls the matching conversion helper (`%c`, `%s`, `%p`, `%d`/`%i`, `%u`, `%x`/`%X`, or `%%`) and accumulates the total printed character count.
* **Justification:** Writing directly without `malloc`/`free` avoids heap allocation overhead and eliminates memory leak risks, keeping extra memory usage at $O(1)$ while processing the string in $O(N)$ time (where $N$ is the length of the format string).

### Variadic Argument Handling (`va_list`) & x86-64 System V ABI

To accept an unknown number of arguments of different types, `ft_printf` uses the standard `<stdarg.h>` macros (`va_start`, `va_arg`, `va_end`) and the `va_list` structure:

* **How it works:** Under the x86-64 System V ABI, the first six integer/pointer arguments are passed in CPU registers (`RDI`, `RSI`, `RDX`, `RCX`, `R8`, `R9`), and any remaining arguments are placed on the stack. `va_start` anchors `va_list` right after the fixed `const char *` format parameter, and each call to `va_arg` reads the next argument in sequence.
* **Justification:** Using `<stdarg.h>` abstracts away register-vs-stack offsets cleanly so every specifier helper can extract its expected type safely in a single left-to-right pass.

### Iterative Base Conversion with a Fixed Stack Array (`char str[21]`)

All numeric and pointer conversions (`%d`, `%i`, `%u`, `%x`, `%X`, `%p`) are converted iteratively using a fixed-size local character array (`char str[20]`) on the stack and unsigned integer arithmetic (`unsigned long`):

* **How it works:** Signed integers (`%d`, `%i`) check for negative values first, output `-`, and cast the magnitude to `unsigned long`. The base-conversion loop then extracts digits from right to left using modulo (`% base`) and integer division (`/ base`), storing them backward from the end of `str[20]` before printing the resulting slice in one `write()` call.
* **Justification:** Casting to `unsigned long` after handling the minus sign prevents signed overflow on edge cases like `INT_MIN` (`-2147483648`) and `LONG_MIN`. A 20-byte stack array is large enough to hold the maximum 19 decimal digits of a 64-bit `unsigned long` (plus sign/null safety), avoiding both `malloc` and recursion while printing the entire number in a single `write()` syscall.

---

## Resources

### Technical References & Documentation

* **Man Pages (`man 3 printf`, `man 3 stdarg`, `man 2 write`)** — Official Linux programmer's manual detailing conversion rules, return values, and variadic macros.
* **GeeksforGeeks — [Difference between Register and Memory](https://www.geeksforgeeks.org/computer-organization-architecture/difference-between-register-and-memory/)** — Used to understand low-level storage hierarchy and how CPU registers differ from main stack memory when passing function arguments.
* **Medium (Ayyoub Oussama) — [Deep Dive into Variadic Arguments in C: An x86-64 System V ABI Analysis](https://medium.com/@ayyouboussamas/deep-dive-into-variadic-arguments-in-c-an-x86-64-system-v-abi-analysis-a2ee0ba64834)** — Used to study how `va_list` tracks register save areas (`reg_save_area`) and stack overflow arguments under the x86-64 System V ABI.
* **YouTube Tutorial — [ft_printf / Variadic Functions Walkthrough](https://youtu.be/7Sph8JlRo0g?si=5GcWLX26YU8lSnPt)** — Used to visualize format string parsing, variadic argument extraction, and modular function structuring.

### Use of AI

AI tools were used strictly as a learning and debugging assistant during the development of this project:

* **Conceptual Understanding:** Used to clarify how `va_list` pointer offsets behave across functions and how OS-specific implementations handle edge cases (such as `NULL` pointers in `%p` vs. `NULL` strings in `%s`).
* **Edge-Case Analysis & Debugging:** Used to review return-value propagation when `write()` fails, verify `LONG_MIN` / `INT_MIN` unsigned conversion logic, and catch C syntax/edge-case bugs (such as trailing `%` characters in format strings).
* **Documentation:** Used to structure and format this `README.md` file according to the 42 curriculum guidelines. All C source code and architectural decisions were written and tested manually.