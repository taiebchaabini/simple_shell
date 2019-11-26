# Simple Shell Project 

### Installation && how to use

```sh
$ gcc *.c -o shell
$ Interactive mode : ./shell
$ Non interactive mode example : echo "ls -la" | ./shell
```

### Functions prototype and description

List of function used for this project of each file.c
| File | Function | Description | 
| --- | --- | --- |
string\_fn.c | \_putchar | writes the character c to stdout. |
string\_fn.c | \_puts | Function that prints a string like a puts function. |
string\_fn.c | \_strlen | Function that returns the length of a string. |
string\_fn.c | str\_concat | Function that concatenates two strings. |
string\_fn.c | \_strcmp | Function that compares two strings. |
string\_fn2.c | \_strdup | Function that returns a pointer which contains a copy of the string. |
states\_fn.c | \_which | Function to check if the program exist in PATH directories. |
env\_fn.c | \_getenv | Function that gets an environment variable. |
env\_fn.c | \_setenv | Function that changes or adds an environment variable. |
env\_fn.c | \_unsetenv | Function that deletes the variable name from the environment. |



### Development

Made by Yassine Chayrrou and Taieb Chaâbini for Holberton School Project

### Todos
- Implement built-ins
- Handle special characters : ", ', `, \, *, &, #
- Be able to move the cursor
