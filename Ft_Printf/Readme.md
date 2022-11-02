<h1 align="center">

Ft_printf

![Build Status](https://camo.githubusercontent.com/76cd252b21c19b4cf767c62782fdcdf046afb7c14435a5604e364e9dace48fe4/68747470733a2f2f696d672e736869656c64732e696f2f62616467652f4c616e67756167652d432d4138423943433f7374796c653d666f722d7468652d6261646765266c6f676f3d43)

</div>
</h1>


<h3 align="center">
	<a href="#%EF%B8%8F-about">About</a>
	<span> · </span>
	<a href="#%EF%B8%8F-usage">Usage</a>
</h3>

---

## 🗣️ About

> _The aim of this project is to recode printf. It's also a possibility to learn how to use variadic arguments._

For detailed information, refer to the [**subject of this project**](https://github.com/appinha/42cursus/tree/master/_PDFs).

	🚀 TLDR: this project consists of coding a library that contains a simplified version (more
	information below) of the printf function.

### Mandatory

* **format specifiers** - `cspdiuxX%`
* **flags** - `-0.*` and minimum field width with all conversions

### Bonus

* **format specifiers** - `nfge` (one or more)
* **flags** - `l ll h hh` (one or more) and `# +` (all)

**Functions in `ft_printf.c`**

* `ft_printf` (and auxiliary static functions) - Initialization function: start/end variadic arguments functions `<stdarg.h>`; in between that, goes through the input string printing plain characters or collecting + treating format specifiers to the FORMAT SPECIFIER STRUCT thus printing each occurrance with the corresponding function.

**Functions in `ft_printf_flags.c`**

* `print_flags` (and auxiliary static functions) - Prints each format specifier function's outputted string with formatting in accordance with the collected format specifiers.

**Functions in `ft_printf_csp_pct.c`**

The following functions output the input variable (collected by `va_arg` function) as a pointer to a string to be printed by the `print_flags` function.

* `print_spec_c`	- **character** (`%c`) type input variable;
* `print_spec_s`	- **string** (`%s`) type input variable;
* `print_spec_pct`	- **percent** (`%%`) character.

**Functions in `ft_printf_iduxo.c`**

The following functions output the input variable (collected by `va_arg` function) as a pointer to a string to be printed by the `print_flags` function.

* `print_spec_i_d_u`	- **int** (`%i` and `%d`) and **unsigned int** (`%u`)type input variables;
* `print_spec_x`		- **lower** (`%x`) and **upper hexadecimal** (`%X`) type input variables;
* `print_spec_o`		- **octal** (`%o`) type input variable;
* `print_spec_p`		- **pointer** (`%p`) type input variable.

**Functions in `ft_printf_f_g.c`**

The following functions output the input variable (collected by `va_arg` function) as a pointer to a string to be printed by the `print_flags` function.

* `print_spec_f_e_g`	- triage for **float** (`%f`), **scientific notation** (`%e`) and **general format** (`%g`) type input variables;
* `print_spec_f`		- **float** (`%f`) type input variable;
* `print_spec_g`		- **general format** (`%g`) type input variable.

**Functions in `ft_printf_f_g.c`**

The following functions output the input variable (collected by `va_arg` function) as a pointer to a string to be printed by the `print_flags` function.

* `print_spec_e` - **scientific notation** (`%e`) type input variable.

**Functions in `ft_printf_utils.c`**

Basic Libc functions - _Note: some were adapted and thus named with a suffix to indicate the nature of the customization._

* `ft_strlen`		- find length of string;
* `ft_strchr_01`	- check the occurence of a character in a string;
* `ft_putchar_len`	- writes the input character to the output stream of stdout;
* `ft_putcstr_len`	- writes the input string to the output stream of stdout;

**Functions in `ft_printf_utils_2.c`**

Basic Libc functions - _Note: some were adapted and thus named with a suffix to indicate the nature of the customization._

* `ft_strlcpy`	- copy string to another location;
* `ft_strlcat`	- concatenate strings;
* `ft_strdup`	- save a copy of a string (with malloc);
* `ft_strjoin`	- join two strings (with malloc);
* `ft_substr`	- extract a substring (with malloc).

**Functions in `ft_printf_utils_3.c`**

Basic Libc functions - _Note: some were adapted and thus named with a suffix to indicate the nature of the customization._

* `ft_pow`			- returns the value of first argument raised to the power of second argument.
* `ft_ullitoa_base`	- allocates (with malloc) and returns a string representing the integer received as an argument according to the given base.
* `ft_fmod`			- returns the modulo of the float received as an argument.

**Functions in `ft_ftoa_rnd.c`**

* `ft_ftoa_rnd` - allocates (with malloc) and returns a string representing the float received as an argument.

## 🛠️ Usage

### Requirements

The library is written in C language and thus needs the **`gcc` compiler** and some standard **C libraries** to run.

### Instructions

**1. Compiling the library**

To compile the library, run:

```shell
$ cd path/to/ft_printf && make
```

**2. Using it in your code**

To use the library functions in your code, simply include its header:

```C
#include "ft_printf.h"
```

and, when compiling your code, add the required flags:

```shell
-lftprintf -L path/to/libftprintf.a -I path/to/ft_printf.h
```
