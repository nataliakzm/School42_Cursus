<div align="center">

# Get_next_line Project <img align="right" src="https://user-images.githubusercontent.com/102881479/215228915-72cdc235-c3b5-4793-be79-e5e2f36d8336.png" /> 

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
	<span> · </span>
</h3>

---

## 🗣️ About

> _The aim of this project is to make students learn about **static variables**_

For detailed information, refer to the [**subject of this project**](https://github.com/nataliakzm/School42_Cursus/blob/main/Get_Next_Line/en.subject%20(1).pdf).

	🚀 TLDR: Because reading a line from a fd is way too tedious, this project is about creating your own function that 
	returns a line read from one file descriptor. The function get_next_line() returns NULL, if there is nothing else 
	to read or if an error occurred. It should work as expected both when reading a file and when reading from the standard output.

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
