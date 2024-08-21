#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SUCCESS 1
#define BUFFER_SIZE 1024
typedef int status_t;

status_t wordCount(int count, char* string[]);
void fileCount(const char* buffer, size_t* word, size_t* line, size_t* ch);