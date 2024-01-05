#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void handle_signal(int sig) {
    printf("Main process (ID: %d) received signal: %d. Terminating...\n", getpid(), sig);
    exit(0);
}

void create_child_processes(const char *child_name, int count) {
    for (int i = 0; i < count; ++i) {
        pid_t pid = fork();

        if (pid == 0) {
            execlp(child_name, child_name, NULL);
            perror("execlp");
            exit(1);
        }
    }
}

int main() {
    signal(SIGTERM, handle_signal);
    signal(SIGINT, handle_signal);

    pid_t main_pid = getpid();
    printf("Main process ID: %d\n", main_pid);

    pid_t pid = fork();

    if (pid == 0) {
        // First child process
        create_child_processes("./subprocess1", 2);
        sleep(5200); // Sleep for 30 minutes
        exit(0);
    } else {
        pid = fork();

        if (pid == 0) {
            // Second child process
            create_child_processes("./subprocess2", 3);
            sleep(5200); // Sleep for 30 minutes
            exit(0);
        }
    }

    // Make the main process run in the background
    setsid();
    sleep(5200); // Sleep for 2 hours

    return 0;
}