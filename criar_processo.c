#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
    pid_t pid;
    pid = fork();
    if (pid < 0)
    {
        printf("Erro ao criar processo\n");
        exit(-1);
    }
    else if (pid == 0)
    {
        printf("Processo filho\n");
        printf("PID: %d\n", getpid());
        printf("PID: %d\n", pid);
    }
    else
    {
        printf("Processo pai\n");
        printf("PID: %d\n", getpid());
        printf("PID: %d\n", pid);
    }

    sleep(10);
    return 0;
}