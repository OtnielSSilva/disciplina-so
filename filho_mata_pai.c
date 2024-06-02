#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <sys/wait.h>

int main()
{
    pid_t child_pid;

    child_pid = fork();

    if (child_pid == -1)
    {
        printf("Erro ao criar processo\n");
        exit(EXIT_FAILURE);
    }

    if (child_pid == 0)
    {
        // Este é o código executado pelo processo filho

        printf("Processo filho (PID: %d) criado.\n", getpid());

        // Aguarde um curto período para garantir que o processo pai tenha tempo para ser criado
        sleep(2);

        // Mate o processo pai
        printf("Processo filho (PID: %d) vai matar o processo pai (PID: %d).\n", getpid(), getppid());
        kill(getppid(), SIGTERM);

        sleep(10);

        printf("Processo pai morto. Processo filho (PID: %d) morto.\n", getpid());
        exit(0);
    }
    else
    {
        // Este é o código executado pelo processo pai

        printf("Processo pai (PID: %d) criado.\n", getpid());

        // Espere pelo processo filho terminar
        wait(NULL);

        printf("Processo pai (PID: %d) morto.\n", getpid());
        exit(EXIT_SUCCESS);
    }

    return 0;
}
