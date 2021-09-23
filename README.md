# Simple Shell Project 

This is a simple shell program, a program that takes commands of user, execute them and output the result to user.

### Description

The shell is the command interpretor in an operating system such as Unix or GNU/Linux, it is a program that executes other programs. It provides a computer user an interface to the Unix/GNU Linux system so that the user can run different commands or utilities/tools with some input data.
When the shell has finished executing a program, it sends an output to the user on the screen, which is the standard output device. For this reason, it is referred to as the “command interpretor”.

### Installation && how to use

```sh
$ gcc *.c -o shell
$ Interactive mode : ./shell
$ Non interactive mode example : echo "ls -la" | ./shell
```

### Functions prototype and description

List of function used for this project of each file.c

| File | Function | Description | 
| --- |:---:| --- |
`string_fn.c` | **\_putchar** | Writes the character c to stdout. |
`string_fn.c` | **\_puts** | Function that prints a string like a puts function. |
`string_fn.c` | **\_strlen** | Function that returns the length of a string. |
`string_fn.c` | **str\_concat** | Function that concatenates two strings. |
`string_fn.c` | **\_strcmp** | Function that compares two strings. |
`string_fn2.c` | **\_strdup** | Function that returns a pointer which contains a copy of the string. |
`string_fn2.c` | **\_calloc** | Function that allocates memory for an array, using malloc. |
`string_fn2.c` | **free_grid** | Function that frees a 2 dimensional grid. |
`string_fn2.c` | **\_getsubtoken** |  Function that split a token with a specified delimiter |
`states_fn.c` | **\_which** | Function to check if the program exist in PATH directories. |
`states_fn.c` | **\_error** | Write a message in the standard error output |
`states_fn.c` | **\_shsign** | Print the shell sign in interactive mode |
`env_fn.c` | **\_getenv** | Function that gets an environment variable. |
`env_fn.c` | **\_setenv** | Function that changes or adds an environment variable. |
`env_fn.c` | **\_unsetenv** | Function that deletes the variable name from the environment. |

### Development
Made by **Yassine Chayrrou** and **Taieb Chaâbini** for **Holberton School** Project
