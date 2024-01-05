#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid;

    pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        return 1;
    } else if (pid == 0) {
        // Child process
        char *args[] = {"ls", "-l", "-a", NULL};
        execvp("ls", args);
    } else {
        // Parent process
        wait(NULL);
    }

    return 0;
}