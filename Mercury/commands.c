#include "commands.h"

//int main() {
//    char* test_input = "help";
//    command_invoke(test_input);
//}

int command_invoke(char* buffer) {
    return command_execute(command_parse(buffer));
}

//FIXME
//This should return a Command not a system_call, it should add arguments to the return as needed.
system_call command_parse(char* buffer) {
    char* token = strtok(buffer, " ");
    system_call sys_call = get_system_call(token);
    if (sys_call == 0) {
        return 0;
    }
    return sys_call;

}

//This is ugly and I hate it.
system_call get_system_call(char* token) {
    if (strcmp(token, "print") == 0) {
        return SYS_PRINT;
    }
    else if (strcmp(token, "help") == 0) {
        return SYS_HELP;
    }
    else if (strcmp(token, "info") == 0) {
        return SYS_INFO;
    }
    else if (strcmp(token, "exit") == 0) {
        return SYS_EXIT;
    }
    else {return SYS_ERR;}
}

int command_execute(system_call sys_call) {
    for (int i=0; commands[i].function != NULL; i++) {
        if (commands[i].sys_call == sys_call) {
        commands[i].function();
        return 1;
        }
   }
    printf("Invalid Command.");
    return 0;
}

int command_print(){
    printf("You've reached the print command. ");
    return 11;
}

int command_help(){
    printf("You've reached the help command. ");
    return 12;
}

int command_info(){
    printf("You've reached the info command. ");
    return 13;
}

int command_exit() {
    printf("You've reached the exit command. ");
    return 14;
}