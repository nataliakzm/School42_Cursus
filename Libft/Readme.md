<div align="center">

# Libft Project

![Build Status](https://camo.githubusercontent.com/76cd252b21c19b4cf767c62782fdcdf046afb7c14435a5604e364e9dace48fe4/68747470733a2f2f696d672e736869656c64732e696f2f62616467652f4c616e67756167652d432d4138423943433f7374796c653d666f722d7468652d6261646765266c6f676f3d43)

</div>

<h3 align="center">
	<a href="#%EF%B8%8F-about">About</a>
	<span> · </span>
	<a href="#%EF%B8%8F-usage">Usage</a>
</h3>

---

## 🗣️ About

> _The aim of this project is to code a C library regrouping usual functions that you'll be allowed to use in all your other projects._

For detailed information, refer to the [**subject of this project**](https://github.com/nataliakzm/School42_Cursus/blob/main/Libft/Libft.pdf).

    🚀 TLDR: this project consists of coding basic C functions (see below), which are then compiled
    into a library for use in other projects of the cursus.

### Functions from `<ctype.h>` library

- [`ft_isascii`](https://github.com/nataliakzm/School42_Cursus/blob/main/Libft/ft_isascii.c) - test for ASCII character.
- [`ft_isalnum`](https://github.com/nataliakzm/School42_Cursus/blob/main/Libft/ft_isalnum.c) - alphanumeric character test.
- [`ft_isalpha`](https://github.com/nataliakzm/School42_Cursus/blob/main/Libft/ft_isalpha.c) - alphabetic character test.
- [`ft_isdigit`](https://github.com/nataliakzm/School42_Cursus/blob/main/Libft/ft_isdigit.c) - decimal-digit character test.
- [`ft_isprint`](https://github.com/nataliakzm/School42_Cursus/blob/main/Libft/ft_isprint.c) - printing character test (space character inclusive).
- [`ft_tolower`](https://github.com/nataliakzm/School42_Cursus/blob/main/Libft/ft_tolower.c) - upper case to lower case letter conversion.
- [`ft_toupper`](https://github.com/nataliakzm/School42_Cursus/blob/main/Libft/ft_toupper.c) - lower case to upper case letter conversion.

### Functions from `<stdlib.h>` library

- [`ft_atoi`](https://github.com/nataliakzm/School42_Cursus/blob/main/Libft/ft_atoi.c) - convert ASCII string to integer.
- [`ft_calloc`](https://github.com/nataliakzm/School42_Cursus/blob/main/Libft/ft_calloc.c) - memory allocation.

### Functions from `<strings.h>` library

- [`ft_bzero`](https://github.com/nataliakzm/School42_Cursus/blob/main/Libft/ft_bzero.c) - write zeroes to a byte string.
- [`ft_memset`](https://github.com/nataliakzm/School42_Cursus/blob/main/Libft/ft_memset.c) - write a byte to a byte string.
- [`ft_memchr`](https://github.com/nataliakzm/School42_Cursus/blob/main/Libft/ft_memchr.c) - locate byte in byte string.
- [`ft_memcmp`](https://github.com/nataliakzm/School42_Cursus/blob/main/Libft/ft_memcmp.c) - compare byte string.
- [`ft_memmove`](https://github.com/nataliakzm/School42_Cursus/blob/main/Libft/ft_memmove.c) - copy byte string.
- [`ft_memcpy`](https://github.com/nataliakzm/School42_Cursus/blob/main/Libft/ft_memcpy.c) - copy memory area.

### Functions from `<string.h>` library

- [`ft_strlen`](https://github.com/nataliakzm/School42_Cursus/blob/main/Libft/ft_strlen.c) - find length of string.
- [`ft_strchr`](https://github.com/nataliakzm/School42_Cursus/blob/main/Libft/ft_strchr.c) - locate character in string (first occurrence).
- [`ft_strrchr`](https://github.com/nataliakzm/School42_Cursus/blob/main/Libft/ft_strrchr.c) - locate character in string (last occurence).
- [`ft_strnstr`](https://github.com/nataliakzm/School42_Cursus/blob/main/Libft/ft_strnstr.c) - locate a substring in a string (size-bounded).
- [`ft_strncmp`](https://github.com/nataliakzm/School42_Cursus/blob/main/Libft/ft_strncmp.c) \* - compare strings (size-bounded).
- [`ft_strdup`](https://github.com/nataliakzm/School42_Cursus/blob/main/Libft/ft_strdup.c) - save a copy of a string (with malloc).
- [`ft_strlcpy`](https://github.com/nataliakzm/School42_Cursus/blob/main/Libft/ft_strlcpy.c) - size-bounded string copying.
- [`ft_strlcat`](https://github.com/nataliakzm/School42_Cursus/blob/main/Libft/ft_strlcat.c) - size-bounded string concatenation.

### Non-standard functions

- [`ft_putchar_fd`](https://github.com/nataliakzm/School42_Cursus/blob/main/Libft/ft_putchar_fd.c) - output a character to given file.
- [`ft_putstr_fd`](https://github.com/nataliakzm/School42_Cursus/blob/main/Libft/ft_putstr_fd.c) - output string to given file.
- [`ft_putendl_fd`](https://github.com/nataliakzm/School42_Cursus/blob/main/Libft/ft_putendl_fd.c) - output string to given file with newline.
- [`ft_putnbr_fd`](https://github.com/nataliakzm/School42_Cursus/blob/main/Libft/ft_putnbr_fd.c) - output integer to given file.
- [`ft_itoa`](https://github.com/nataliakzm/School42_Cursus/blob/main/Libft/ft_itoa.c) - convert integer to ASCII string.
- [`ft_substr`](https://github.com/nataliakzm/School42_Cursus/blob/main/Libft/ft_substr.c) - extract substring from string.
- [`ft_strtrim`](https://github.com/nataliakzm/School42_Cursus/blob/main/Libft/ft_strtrim.c) - trim beginning and end of string with the specified characters.
- [`ft_strjoin`](https://github.com/nataliakzm/School42_Cursus/blob/main/Libft/ft_strjoin.c) - concatenate two strings into a new string (with malloc).
- [`ft_split`](https://github.com/nataliakzm/School42_Cursus/blob/main/Libft/ft_split.c) - split string, with specified character as delimiter, into an array of strings.
- [`ft_striteri`](https://github.com/nataliakzm/School42_Cursus/blob/main/Libft/ft_striteri.c) - applies a function to each character of a string
- [`ft_strmapi`](https://github.com/nataliakzm/School42_Cursus/blob/main/Libft/ft_strmapi.c) - create new string from modifying string with specified function.

### Linked list functions

- [`ft_lstnew`](https://github.com/nataliakzm/School42_Cursus/blob/main/Libft/ft_lstnew.c) - create new list.
- [`ft_lstsize`](https://github.com/nataliakzm/School42_Cursus/blob/main/Libft/ft_lstsize.c) - count elements of a list.
- [`ft_lstlast`](https://github.com/nataliakzm/School42_Cursus/blob/main/Libft/ft_lstlast.c) - find last element of list.
- [`ft_lstadd_back`](https://github.com/nataliakzm/School42_Cursus/blob/main/Libft/ft_lstadd_back.c) - add new element at end of list.
- [`ft_lstadd_front`](https://github.com/nataliakzm/School42_Cursus/blob/main/Libft/ft_lstadd_front.c) - add new element at beginning of list.
- [`ft_lstdelone`](https://github.com/nataliakzm/School42_Cursus/blob/main/Libft/ft_lstdelone.c) - delete element from list.
- [`ft_lstclear`](https://github.com/nataliakzm/School42_Cursus/blob/main/Libft/ft_lstclear.c) - delete sequence of elements of list from a starting point.
- [`ft_lstiter`](https://github.com/nataliakzm/School42_Cursus/blob/main/Libft/ft_lstiter.c) - apply function to content of all list's elements.
- [`ft_lstmap`](https://github.com/nataliakzm/School42_Cursus/blob/main/Libft/ft_lstmap.c) - apply function to content of all list's elements into new list.

_Note: functions marked with \* are bonus functions (not mandatory by the project's subject)._

## 🛠️ Usage

### Requirements

The library is written in C language and thus needs the **`gcc` compiler** and some standard **C libraries** to run.

### Instructions

**1. Compiling the library**

To compile the library, run:

```shell
$ cd path/to/libft && make
```

**2. Using it in your code**

To use the library functions in your code, simply include its header:

```C
#include "libft.h"
```

and, when compiling your code, add the required flags:

```shell
-lft -L path/to/libft.a -I path/to/libft.h
```
