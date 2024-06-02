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
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (child_pid == 0)
    {
        // Este é o código executado pelo processo filho

        printf("Processo filho (PID: %d) criado.\n", getpid());

        // O processo filho pausa aqui até que ele seja morto pelo processo pai
        pause();

        printf("Processo filho (PID: %d) morto.\n", getpid());
        exit(0);
    }
    else
    {
        // Este é o código executado pelo processo pai

        printf("Processo pai (PID: %d) criado.\n", getpid());

        sleep(2);

        printf("Matando o processo filho (PID: %d).\n", child_pid);
        kill(child_pid, SIGTERM);

        // O processo pai espera que o processo filho termine
        wait(NULL);

        printf("Processo pai (PID: %d) morto.\n", getpid());
        exit(EXIT_SUCCESS);
    }

    return 0;
}
