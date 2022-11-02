<h1 align="center">

Get_next_line
	
![Build Status](https://camo.githubusercontent.com/76cd252b21c19b4cf767c62782fdcdf046afb7c14435a5604e364e9dace48fe4/68747470733a2f2f696d672e736869656c64732e696f2f62616467652f4c616e67756167652d432d4138423943433f7374796c653d666f722d7468652d6261646765266c6f676f3d43)

</div>
</h1>

<h3 align="center">
	<a href="#%EF%B8%8F-about">About</a>
	<span> · </span>
	<a href="#%EF%B8%8F-usage">Usage</a>
	<span> · </span>
</h3>

---

## 🗣️ About

> _The aim of this project is to make you code a function that returns a line ending with a newline, read from a file descriptor._

For detailed information, refer to the [**subject of this project**](https://github.com/nataliakzm/School42_Cursus/blob/main/Get_Next_Line/en.subject%20(1).pdf).

	🚀 TLDR: this project consists of coding a function that returns one line at a time from a text file.

### Functions in `get_next_line.c`

* `ft_free_null`	- free and null a pointer.
* `ft_cpy_exc_buff`	- copy read excess (string after \n) to static variable (buffer).
* `ft_buff2line`	- copy read line from buffer.
* `get_next_line`	- main function.

### Functions in `get_next_line_utils.c`

* `ft_strlen`		- find length of string.
* `ft_strdup`		- save a copy of a string (with malloc).

## 🛠️ Usage

### Requirements

The function is written in C language and thus needs the **`gcc` compiler** and some standard **C libraries** to run.

### Instructions

**1. Using it in your code**

To use the function in your code, simply include its header:

```C
#include "get_next_line.h"
```

and, when compiling your code, add the source files and the required flag:

```shell
get_next_line.c get_next_line_utils.c -D BUFFER_SIZE=<size>
```

If you're on Linux, you may as well need the following flags:

```shell
-D ARG_MAX="sysconf(_SC_ARG_MAX)" -D OPEN_MAX=1024
```
