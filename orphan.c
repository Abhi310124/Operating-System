#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        // Child process
        sleep(5);
        printf("Child running after parent exit. My PID: %d, Parent PID: %d\n",
               getpid(), getppid());
    } else {
        // Parent exits immediately
        printf("Parent exiting...\n");
        exit(0);
    }

    return 0;
}
