#include "main.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

#define BUFFER_SIZE 1024

/**
* open_files - opens source and destination files
* @file_from: source filename
* @file_to: destination filename
* @fd_from: pointer to store source fd
* @fd_to: pointer to store destination fd
*/
void open_files(const char *file_from, const char *file_to,
int *fd_from, int *fd_to)
{
mode_t permissions = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH;

*fd_from = open(file_from, O_RDONLY);
if (*fd_from == -1)
{
dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file_from);
exit(98);
}

*fd_to = open(file_to, O_CREAT | O_WRONLY | O_TRUNC, permissions);
if (*fd_to == -1)
{
dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file_to);
close(*fd_from);
exit(99);
}
}

/**
* copy_content - copies content from source to destination
* @fd_from: source file descriptor
* @fd_to: destination file descriptor
* @file_from: source filename for errors
* @file_to: destination filename for errors
*/
void copy_content(int fd_from, int fd_to,
const char *file_from, const char *file_to)
{
ssize_t bytes_read, bytes_written;
char buffer[BUFFER_SIZE];

while ((bytes_read = read(fd_from, buffer, BUFFER_SIZE)) > 0)
{
bytes_written = write(fd_to, buffer, bytes_read);
if (bytes_written == -1 || bytes_written != bytes_read)
{
dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file_to);
close(fd_from);
close(fd_to);
exit(99);
}
}

if (bytes_read == -1)
{
dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file_from);
close(fd_from);
close(fd_to);
exit(98);
}
}

/**
* close_files - closes file descriptors with error handling
* @fd_from: source file descriptor
* @fd_to: destination file descriptor
*/
void close_files(int fd_from, int fd_to)
{
if (close(fd_from) == -1)
{
dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_from);
close(fd_to);
exit(100);
}

if (close(fd_to) == -1)
{
dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_to);
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

if (ac != 3)
{
dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
exit(97);
}

open_files(av[1], av[2], &fd_from, &fd_to);
copy_content(fd_from, fd_to, av[1], av[2]);
close_files(fd_from, fd_to);
return (0);
}
