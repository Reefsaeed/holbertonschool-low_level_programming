#include "main.h"

/**
* print_error_exit - prints error message and exits
* @code: exit code
* @msg1: first part of message
* @msg2: second part (filename or fd)
* @is_num: 1 if msg2 is a number, 0 if string
*/
void print_error_exit(int code, char *msg1, char *msg2, int is_num)
{
int i;

for (i = 0; msg1[i]; i++)
;
write(STDERR_FILENO, msg1, i);

if (is_num)
{
for (i = 0; msg2[i]; i++)
;
write(STDERR_FILENO, msg2, i);
}
else
{
for (i = 0; msg2[i]; i++)
;
write(STDERR_FILENO, msg2, i);
}
write(STDERR_FILENO, "\n", 1);
exit(code);
}

/**
* close_fd - closes a file descriptor and handles errors
* @fd: file descriptor to close
*/
void close_fd(int fd)
{
int ret, i = 0, temp = fd, j;
char fd_str[12], c;

ret = close(fd);
if (ret == -1)
{
write(STDERR_FILENO, "Error: Can't close fd ", 22);
if (temp == 0)
write(STDERR_FILENO, "0", 1);
else
{
while (temp > 0)
{
fd_str[i++] = (temp % 10) + '0';
temp /= 10;
}
for (j = i - 1; j >= 0; j--)
{
c = fd_str[j];
write(STDERR_FILENO, &c, 1);
}
}
write(STDERR_FILENO, "\n", 1);
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
print_error_exit(98, "Error: Can't read from file ", argv[1], 0);

*fd_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
if (*fd_to == -1)
{
close_fd(*fd_from);
print_error_exit(99, "Error: Can't write to ", argv[2], 0);
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

while (1)
{
read_bytes = read(fd_from, buffer, BUFFER_SIZE);
if (read_bytes == 0)
break;
if (read_bytes < 0)
{
print_error_exit(98, "Error: Can't read from file ", argv[1], 0);
}

write_bytes = write(fd_to, buffer, read_bytes);
if (write_bytes < 0 || write_bytes != read_bytes)
{
print_error_exit(99, "Error: Can't write to ", argv[2], 0);
}
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
write(STDERR_FILENO, "Usage: cp file_from file_to\n", 28);
exit(97);
}

open_files(argv, &fd_from, &fd_to);
copy_content(fd_from, fd_to, argv);
close_fd(fd_from);
close_fd(fd_to);

return (0);
}
