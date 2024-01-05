#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

void handle_signal(int sig) {
    printf("Subprocess1 (ID: %d) received signal: %d. Terminating...\n", getpid(), sig);
    exit(0);
}

int main() {
    signal(SIGTERM, handle_signal);
    signal(SIGINT, handle_signal);

    printf("I am subprocess1 with process ID: %d and mainprocess process ID: %d\n", getpid(), getppid());
    sleep(5200); // Sleep for 2 hours
    return 0;
}
