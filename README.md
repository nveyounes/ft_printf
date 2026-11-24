*This project has been created as part of the 42 curriculum by yfarhat.*

# ft_printf

## Description

`ft_printf` is a custom, standalone reimplementation of the standard C library function `printf` (`<stdio.h>`). The goal of this project is to master variadic functions in C (`<stdarg.h>`), low-level formatted output via the `write(2)` system call, type promotion rules, and modular software architecture compliant with the 42 Norm.

Unlike the standard `glibc` implementation—which relies on user-space `FILE` stream buffering—this version writes directly to standard output (`fd 1`) without dynamic heap allocation for formatting buffers, returning the exact total number of printed bytes or `-1` if an I/O error occurs.

### Supported Conversions

* `%c`: Prints a single character (`int` promoted from `char`).
* `%s`: Prints a null-terminated string (outputs `(null)` when passed a `NULL` pointer).
* `%p`: Prints a `void *` pointer address in lowercase hexadecimal prefixed with `0x` (outputs `(nil)` on Linux when passed `NULL`).
* `%d` / `%i`: Prints a signed decimal integer (base 10).
* `%u`: Prints an unsigned decimal integer (base 10).
* `%x`: Prints an unsigned integer in lowercase hexadecimal (base 16).
* `%X`: Prints an unsigned integer in uppercase hexadecimal (base 16).
* `%%`: Prints a literal percent sign.

## Instructions

### Compilation

The project compiles into a static library named `libftprintf.a` at the root of the repository using `cc` with `-Wall -Wextra -Werror`.

```bash
# Build the mandatory library (libftprintf.a)
make

# Remove object files (.o)
make clean

# Remove object files and libftprintf.a
make fclean

# Recompile everything from scratch
make re
```

### Integration & Usage

1. Include the header in your C source file:
   ```c
   #include "ft_printf.h"

   int	main(void)
   {
   	int	count;

   	count = ft_printf("User: %s | ID: %d | Hex: %x | Addr: %p\n",
   			"yfarhat", 42, 1337, (void *)0x7fff);
   	ft_printf("Total bytes written: %d\n", count);
   	return (0);
   }
   ```
2. Link against `libftprintf.a` when compiling:
   ```bash
   cc -Wall -Wextra -Werror main.c libftprintf.a -o test_printf
   ./test_printf
   ```

## Algorithm & Data Structure Justification

### 1. Function-Pointer Dispatch Table (`t_fmt_fn arr[128]`)

Instead of routing format specifiers through a long chain of `if / else if` statements—which degrades readability and easily exceeds the 42 Norm's 25-line function limit—the parser uses an $O(1)$ lookup table of function pointers:

```c
typedef int	(*t_fmt_fn)(va_list *);
```

* **Structure:** A 128-slot array (`t_fmt_fn arr[128]`) zero-initialized via `ft_bzero` and populated with handlers at their exact ASCII indices (`arr['c']`, `arr['s']`, `arr['d']`, etc.).
* **Safety:** Before indexing `arr`, the character following `%` is cast to `unsigned char` and bounds-checked (`< 128`). On architectures where `char` is signed by default, this prevents negative out-of-bounds reads when encountering extended ASCII or multi-byte UTF-8 characters (`0x80`–`0xFF`).
* **Extensibility:** Adding new specifiers or isolating bug fixes requires modifying only a single handler without touching the core parsing loop.

### 2. Shared Variadic Cursor via Pointer (`va_list *`)

The `va_list` state initialized by `va_start` in `ft_printf` is passed by address (`&args`) into every handler. While x86_64 Linux defines `va_list` as a 1-element array that decays to a pointer, passing `va_list *` explicitly guarantees that nested helper functions advance the exact same argument cursor across all target ABIs rather than operating on a local copy.

### 3. Iterative Stack-Buffer Base-Conversion Engine (`ft_all_in_one_base`)

All unsigned and base-encoded conversions (`%u`, `%x`, `%X`, `%p`) share a single iterative division-remainder routine (`ft_all_in_one_base`) parameterized by base alphabet and radix (`10` or `16`), avoiding recursive call overhead and heap allocations:

* **Width Safety (~~(`uintptr_t`)~~ (`unsigned long`)):** Because `<stdint.h>` (`uintptr_t`) is not permitted by the subject, thin type-specific wrappers extract the exact ABI type first (`unsigned int` for `%u`/`%x`/`%X` to prevent 64-bit sign-extension on negative inputs, and `void *` for `%p` to preserve full 64-bit addresses) before passing the value as ~~(`uintptr_t`)~~ (`unsigned long`), which matches `sizeof(void *)` (8 bytes) on 64-bit Linux (`LP64`).
* **Fixed Stack Buffer & Digit Ordering (`char buff[21]`):** Remainders (`n % base_number`) are stored sequentially into a 21-byte stack array—large enough to hold the 20 digits of `ULONG_MAX` (`18446744073709551615`) plus a null terminator—and then written in reverse (`while (i-- > 0)`) to emit digits from most significant to least significant.

### 4. Fail-Fast Syscall Error Propagation

Every `write()` call checks its return value immediately. If `write()` returns `-1` (for example, on a closed file descriptor or broken pipe), `-1` propagates immediately up the call chain to `ft_printf`, which still executes `va_end(args)` before returning `-1`.

## Resources

### Documentation & Technical References

* `man 3 printf` — Standard conversion specifications, argument type requirements, and return value behavior.
* `man 3 stdarg` — Specification of `va_start`, `va_arg`, `va_copy`, and `va_end` macros and default argument promotions.
* `man 2 write` — POSIX system call interface, return semantics, and error conditions.
* *System V Application Binary Interface (AMD64 Architecture Processor Supplement), Section 3.5.7* — Register passing conventions (`%rdi`–`%r9`, `%xmm0`–`%xmm7`) and variable argument save-area layout on 64-bit Unix systems.
* *ISO/IEC 9899 (C99 Standard), Section 6.5.2.2* — Default argument promotions in variadic calls and `LP64` integer-pointer widths (`unsigned long`).

### Use of AI

AI tools were used strictly as a learning and reference aid during this project—specifically to understand the underlying fundamentals of variadic macros, System V AMD64 register mechanics, default argument promotions, and 64-bit data models (`LP64`), as well as to locate relevant primary documentation (`man` pages and C standard sections) and design edge-case test scenarios. All architectural design decisions, source code, and debugging were written and verified independently.