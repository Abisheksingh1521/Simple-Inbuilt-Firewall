#include <stdio.h>
#include <stdlib.h>

int main() {
    char command[100];

    printf("Enter a command to execute: ");
    fgets(command, sizeof(command), stdin);

    // Using system() function to execute the command
    int status = system(command);

    if (status == -1) {
        printf("Failed to execute the command.\n");
    } else {
        printf("Command executed successfully.\n");
    }

    return 0;
}

