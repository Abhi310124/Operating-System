#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        // Child process
        printf("Child process exiting...\n");
        exit(0);
    } else {
        // Parent process
        printf("Parent sleeping, child will become zombie...\n");
        sleep(30);   // Parent alive, but not calling wait()
    }

    return 0;
}
