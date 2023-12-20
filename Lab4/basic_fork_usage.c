#include <stdio.h>
#include <unistd.h>

int main() {

    pid_t pid;
    pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        return 1;
    } else if (pid == 0) {
        printf("Child process with PID: %d\n", getpid());
    } else {
        printf("Parent process with PID: %d, child PID: %d\n", getpid(), pid);
    }

    return 0;
}