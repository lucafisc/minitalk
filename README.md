# minitalk
<h1 align="center">minitalk</h1>

<p align="center">
<img src="https://i.imgur.com/KIzJ2vu.png" alt="drawing" width="120"/>
</p>

minitalk is a program that allows inter-process communication between a client and a server. The client sends messages to the server one bit at a time. The server should then receive and reconstruct the original message. It utilizes the use of signals to transfer the data.

The program has the bonus functionality of confirming the message received by the server and supporting unicode characters.

External functions: [`write`](https://man7.org/linux/man-pages/man2/write.2.html)  [`sigemptyset`](https://man7.org/linux/man-pages/man3/sigemptyset.3.html) [`sigaction`](https://man7.org/linux/man-pages/man2/sigaction.2.html) [`kill`](https://man7.org/linux/man-pages/man2/kill.2.html) [`getpid`](https://man7.org/linux/man-pages/man2/getpid.2.html) [`malloc`](https://man7.org/linux/man-pages/man3/malloc.3.html) [`free`](https://man7.org/linux/man-pages/man1/free.1.html) [`pause`](https://man7.org/linux/man-pages/man2/pause.2.html) [`usleep`](https://man7.org/linux/man-pages/man3/usleep.3.html)

- [How it works](#how-it-works)
- [Hot to use](#how-to-use)

## How it works

## How to use

