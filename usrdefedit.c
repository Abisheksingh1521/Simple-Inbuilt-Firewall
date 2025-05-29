#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    // Command to add a rule to allow incoming SSH connections
    char *command = "sudo iptables -D INPUT -p tcp --dport 80 -j ACCEPT";

    // Execute the command
    int status = system(command);

    if (status == -1) {
        printf("Failed to add firewall rule.\n");
        return 1;
    } else {
        printf("Firewall rule added successfully.\n");
    }

    return 0;
}

