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
        printf("Child process %d is running\n", getpid());
        sleep(2);
        printf("Child process %d is exiting\n", getpid());
        return 0;
    } else {
        // Parent process
        printf("Parent process %d is waiting for child process %d\n", getpid(), pid);
        wait(NULL);
        printf("Parent process %d resumes execution\n", getpid());
    }

    return 0;
}