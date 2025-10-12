#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

/* _putchar function */
int _putchar(char c);

/* Custom string printing function for errors */
void print_error(char *message);

/* CP function */
int main(int argc, char *argv[]);

#endif /* MAIN_H */
