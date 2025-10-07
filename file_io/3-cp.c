#include "main.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

#define BUFFER_SIZE 1024

/**
* error_exit - prints error message and exits with specified code
* @code: exit code
* @message: error message
* @arg: argument for the message (filename or fd)
*/
void error_exit(int code, const char *message, const char *arg)
{
dprintf(STDERR_FILENO, message, arg);
exit(code);
}

/**
* close_fd - closes a file descriptor and handles errors
* @fd: file descriptor to close
*/
void close_fd(int fd)
{
if (close(fd) == -1)
{
dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
exit(100);
}
}

/**
* main - copies the content of a file to another file
* @ac: argument count
* @av: argument vector
*
* Return: 0 on success, or appropriate error code
*/
int main(int ac, char **av)
{
int fd_from, fd_to;
ssize_t bytes_read, bytes_written;
char buffer[BUFFER_SIZE];
mode_t permissions = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH;

if (ac != 3)
error_exit(97, "Usage: cp file_from file_to\n", NULL);

fd_from = open(av[1], O_RDONLY);
if (fd_from == -1)
error_exit(98, "Error: Can't read from file %s\n", av[1]);

fd_to = open(av[2], O_CREAT | O_WRONLY | O_TRUNC, permissions);
if (fd_to == -1)
{
close_fd(fd_from);
error_exit(99, "Error: Can't write to %s\n", av[2]);
}

while ((bytes_read = read(fd_from, buffer, BUFFER_SIZE)) > 0)
{
bytes_written = write(fd_to, buffer, bytes_read);
if (bytes_written == -1 || bytes_written != bytes_read)
{
close_fd(fd_from);
close_fd(fd_to);
error_exit(99, "Error: Can't write to %s\n", av[2]);
}
}

if (bytes_read == -1)
{
close_fd(fd_from);
close_fd(fd_to);
error_exit(98, "Error: Can't read from file %s\n", av[1]);
}

close_fd(fd_from);
close_fd(fd_to);
return (0);
}
