#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <fcntl.h>

static void sighandler(int signo){
    if (signo == SIGINT){
        FILE *file = open("error.log", O_WRONLY | O_TRUNC);
        write(file, "Operation terminated because of a SIGINT", sizeof("Operation terminated because of a SIGINT"));
        exit(0);
    }
    else if (signo == SIGUSR1){
        printf("Parent PID: %d\n", getppid());
    }
}

int main(){
    while (1){
        printf("PID %d\n", getpid());
        sleep(1);
    }
}