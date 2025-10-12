#include "main.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

/**
* print_error - prints error message to stderr and exits
* @code: exit code
* @message: error message format
* @arg: argument for the message
*/
void print_error(int code, const char *message, const char *arg)
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
int ret;

ret = close(fd);
if (ret == -1)
{
dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
exit(100);
}
}

/**
* open_files - opens source and destination files
* @argv: argument vector containing filenames
* @fd_from: pointer to store source file descriptor
* @fd_to: pointer to store destination file descriptor
*/
void open_files(char *argv[], int *fd_from, int *fd_to)
{
*fd_from = open(argv[1], O_RDONLY);
if (*fd_from == -1)
print_error(98, "Error: Can't read from file %s\n", argv[1]);

*fd_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
if (*fd_to == -1)
{
close_fd(*fd_from);
print_error(99, "Error: Can't write to %s\n", argv[2]);
}
}

/**
* copy_content - copies content from one file to another
* @fd_from: source file descriptor
* @fd_to: destination file descriptor
* @argv: argument vector for error messages
*/
void copy_content(int fd_from, int fd_to, char *argv[])
{
char buffer[BUFFER_SIZE];
int read_bytes, write_bytes;

while ((read_bytes = read(fd_from, buffer, BUFFER_SIZE)) > 0)
{
write_bytes = write(fd_to, buffer, read_bytes);
if (write_bytes == -1 || write_bytes != read_bytes)
{
close_fd(fd_from);
close_fd(fd_to);
print_error(99, "Error: Can't write to %s\n", argv[2]);
}
}

if (read_bytes == -1)
{
close_fd(fd_from);
close_fd(fd_to);
print_error(98, "Error: Can't read from file %s\n", argv[1]);
}
}

/**
* main - copies the content of a file to another file
* @argc: argument count
* @argv: argument vector
*
* Return: 0 on success, or exits with error code
*/
int main(int argc, char *argv[])
{
int fd_from, fd_to;

if (argc != 3)
{
dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
exit(97);
}

open_files(argv, &fd_from, &fd_to);
copy_content(fd_from, fd_to, argv);
close_fd(fd_from);
close_fd(fd_to);

return (0);
}
