#ifndef MERCURY_H
#define MERCURY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include "commands.h"

#define INPUT_SIZE 1024;
#define COMMAND_COUNT 10;
const char key[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ/!1234567890 ";

char* readInput(char* buffer, size_t bufferSize);
void cleanInput(char* input);
void shellLoop();

#endif