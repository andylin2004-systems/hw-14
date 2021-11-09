#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <fcntl.h>
#include <stdlib.h>

static void sighandler(int signo){
    if (signo == SIGINT){
        FILE *file = open("error.log", O_CREAT | O_WRONLY | O_TRUNC, 0644);
        write(file, "Operation terminated because of a SIGINT\n", sizeof("Operation terminated because of a SIGINT\n"));
        close(file);
        exit(0);
    }
    else if (signo == SIGUSR1){
        printf("Parent PID: %d\n", getppid());
    }
}

int main()
{
    signal(SIGINT, sighandler);
    signal(SIGUSR1, sighandler);
    while (1){
        printf("PID %d\n", getpid());
        sleep(1);
    }
}