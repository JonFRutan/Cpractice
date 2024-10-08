#ifndef COMMANDS_H
#define COMMANDS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
    SYS_ERR = 0,
    SYS_PRINT = 1,
    SYS_HELP = 2,
    SYS_INFO = 3,
    SYS_EXIT = 4
} system_call;

typedef int (*command_function)(); //Holds a pointer to a function.

// A Command is two things: an alias and an action.
// The alias is an easy way to abstract the actions.
// "Stop!" is an alias to the act of ceasing your current process.
typedef struct {
    system_call sys_call;
    command_function function;
    char* arguments;
} Command;

int command_execute(system_call sys_call);                //return will be a completion code.
int  command_invoke(char* buffer);                        //return will be a completion code.
system_call command_parse(char* buffer);                  //FIXME
system_call get_system_call(char* token);
int command_print();
int command_help();
int command_info();
int command_exit();

// Why is this static and const? See my notes on functions.
static const Command commands[] = {
  {SYS_PRINT, command_print, NULL},
  {SYS_HELP, command_help, NULL},
  {SYS_INFO, command_info, NULL},
  {SYS_EXIT, command_exit, NULL},
  {SYS_ERR, NULL, NULL} //Marks the end of command mappings.  
};

#endif