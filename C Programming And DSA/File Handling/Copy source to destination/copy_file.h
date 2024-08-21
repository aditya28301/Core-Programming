#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SUCCESS 0
#define BUFFER_SIZE 128
typedef int status_t;

status_t copyFile(const char* source_string, const char* destination_string);