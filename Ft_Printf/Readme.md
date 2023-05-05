<div align="center">

# Ft_printf Project <img align="right" src="https://user-images.githubusercontent.com/102881479/215298013-ff93daf3-6f0c-4226-9474-65b280e579fe.png" /> 

<p align="center">
    <img src="https://img.shields.io/badge/OS-Linux-blue" alt="OS">
    <img src="https://img.shields.io/badge/Language-C%20%7C%20C%2B%2B-blue.svg" alt="Language">
    <img src="https://img.shields.io/badge/Status-Completed-brightgreen.svg" alt="Status">
</p>

</div>

<h3 align="center">
	<a href="#%EF%B8%8F-about">About</a>
	<span> · </span>
	<a href="#%EF%B8%8F-usage">Usage</a>
</h3>

---

## 🗣️ About

> _The aim of this project is to recode printf. It's also a possibility to learn how to use variadic arguments._

For detailed information, refer to the [**subject of this project**](https://github.com/nataliakzm/School42_Cursus/blob/main/Ft_Printf/en.subject.pdf).

	🚀 TLDR: This project is pretty straightforward. It asks students to recode `printf()` in order to make them learn 
	about how a variadic function works. It also aims to make students think about how they are going 
	to implement the project. After all, the key to a successful `ft_printf` is a well-structured and extensible code.

## Implemented features

#### Mandatory

- ✅ The function has to implement the following conversions: `cspdiuxX%`

| Conversion | Description |
|:----|:-----|
| `c`  | Prints a single character. |
| `s`  | Prints a string (as defined by the common C convention). |
| `p`  | The `void *` pointer argument has to be printed in hexadecimal format. |
| `d`  | Prints a decimal (base 10) number. |
| `i`  | Prints an integer in base 10. |
| `u`  | Prints an unsigned decimal (base 10) number. |
| `x`  | Prints a number in hexadecimal (base 16) lowercase format. |
| `X`  | Prints a number in hexadecimal (base 16) uppercase format. |
| `%`  | Prints a percent sign. |


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
