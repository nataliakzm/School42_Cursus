<div align="center">

# So_long Project

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

For detailed information, refer to the [**subject of this project**](https://github.com/nataliakzm/School42_Cursus/blob/main/So_long/en.subject.pdf).

![bonus](https://user-images.githubusercontent.com/55356071/129287696-f7064eeb-1a90-4e33-bde7-58ad8f239051.gif)

## 🛠️ Usage

### Requirements

The function is written in C language and thus needs the **`gcc` compiler** and some standard **C libraries** to run.

### How to launch?

To launch the program, follow these steps:

1. Run `make` to build the executable.
2. Execute the program with `./so_long [map]`.
	- Alternatively, you can run `make run`  and choose the type of map from the menu.
	- **NB** 🔍 Available maps can be found in the `maps/` directory.

To launch the bonus version, follow these steps:

1. Run `make bonus` to build the bonus version of the program.
2. Execute the program with `./so_long_bonus maps/map_bonus.ber`.
	-Alternatively, you can run `make run` and choose option `5`.

## Keys for qwerty keyboard:

- `[FORWARD]` = W
- `[GO_LEFT]` = A
- `[GO_RIGHT]` = D
- `[BACKWARD]` = S
- `[EXIT]` = ESC

## Map Building Guide 🗺 :

When building a map, use the following symbols:

- `0` = SPACE
- `1` = WALL
- `P` = PLAYER
- `E` = EXIT
- `C` = COLLECTIBLE
- `B` = BOMB (only with bonus)
