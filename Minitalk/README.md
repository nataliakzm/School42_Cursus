<div align="center">

# Minitalk Project <img align="right" src="https://user-images.githubusercontent.com/102881479/215282296-839ce5e6-5982-41f6-ba56-7e408f6ca9f8.png" /> 

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

For detailed information, refer to the [**subject of this project**](https://github.com/nataliakzm/School42_Cursus/blob/main/Minitalk/en.subject.pdf).

The purpose of this project is to code a small data exchange program using UNIX signals. Therefore, the communication program between a `client` and a `server` has to be done using **only** UNIX signals. Thus, it was allowed to use only two signals: `SIGUSR1` and `SIGUSR2`.

The `server` should be able to receive strings from several clients in a row without needing to restart. For the bonus project, the `server` also acknowlegdes every message received by sending back a signal to the `client` and supports Unicode characters.

## 🛠️ Usage

#### 1) Copy this repository to your local workstation

```html
git@github.com:nataliakzm/School42_Cursus.git
cd School42_Cursus/Minitalk
```

#### 2) Compile the project with Makefile

```html
make
```

#### 3) Open two instances of the command terminal and, in one of them, launch the `server` program

```html
./server
```

It will print something to the standard output, such as:

```html
Server PID is: 1084.
```

If you want to run the program looking for memory leaks, just start it as follows:

```html
valgrind --leak-check=full --show-leak-kinds=all ./server
```

#### 4) In the other terminal, launch the `client` program

It must receive the following three arguments: the executable program, the server PID and the text to be sent. For example:

```html
./client 1024 "This is an amazing but not so long sentence, minitalk!"
```

#### 5) Usage example

After completing the four steps above, the `server` will receive and print the message from `client`. After the message has been fully printed, the `server` will send a message back to the `client` signaling that data has been successfully received. The `client` will then show the following information:

```html
1084 server PID: data received.
```

To send another message to the `server`, the `client` program must be executed once again.

## Demo

![minitalk demo](https://github.com/pvaladares/42cursus-02-minitalk/blob/main/img/minitalk_demo.gif)

- Above is a demonstration of the usage of the `server` and `client` programs
	- Erro handling, e.g. incorrect number of arguments and invalid PID server
	- Sending empty messages with `""` and `''` - transmission of empty message is received by server (length 0) and displayed
	- Sending Large message sent +1000 chars using [Lorem Ipsum site](https://lipsum.com/feed/html)
	- Receiving a message from a 2nd client after 1st client (in a row)
	- Client showing transmission log
