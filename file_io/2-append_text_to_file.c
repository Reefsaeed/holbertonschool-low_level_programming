#include "main.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

/**
* append_text_to_file - appends text at the end of a file
* @filename: name of the file
* @text_content: NULL terminated string to add at the end of the file
*
* Return: 1 on success, -1 on failure
*/
int append_text_to_file(const char *filename, char *text_content)
{
int fd;
ssize_t bytes_written = 0;
size_t len = 0;

/* Check for NULL filename */
if (filename == NULL)
return (-1);

/* Open file for appending (do not create if it doesn't exist) */
fd = open(filename, O_WRONLY | O_APPEND);
if (fd == -1)
return (-1);

/* If text_content is not NULL, append it to the file */
if (text_content != NULL)
{
/* Calculate the length of text_content */
while (text_content[len])
len++;

/* Write the content to the file */
bytes_written = write(fd, text_content, len);
if (bytes_written == -1 || (size_t)bytes_written != len)
{
close(fd);
return (-1);
}
}

close(fd);
return (1);
}
