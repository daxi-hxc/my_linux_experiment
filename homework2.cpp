#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

#define LOOP 3

int main()
{
    pid_t pid;
    int i;
    for (i=0; i<LOOP; i++)
    {
        /*fork another process*/
        pid = fork();
        if (pid < 0)
            {/*error occurred*/
                fprintf(stderr, "Fork Faild");
                exit(-1);
            }
        else if (pid == 0) {/*child process*/
            fprintf(stdout, "i=%d, pid=%d, parent pid=%d\n", i, getpid(), getppid());
        }
    }
    wait(NULL);
    exit(0);
}