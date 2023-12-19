#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

void handle_signal(int sig) {
    printf("Child1 process (ID: %d) received signal: %d. Terminating...\n", getpid(), sig);
    exit(0);
}

int main() {
    signal(SIGTERM, handle_signal);
    signal(SIGINT, handle_signal);

    printf("I am child1 with process ID: %d and parent process ID: %d\n", getpid(), getppid());
    sleep(1800); // Sleep for 30 minutes
    return 0;
}
