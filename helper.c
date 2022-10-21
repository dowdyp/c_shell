#include "helper.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void isQuit(char *cmd) {
    if(strcmp(cmd, "quit") == 0) {
        printf("Goodbye\n");
        exit(0);
    }
    return;
}

void runCmd(char *cmd) {

    printf("Command to run: %s\n", cmd);

    int fds[2];
    if(pipe(fds) == -1) {
        perror("pipe error");
	exit(1);
    }

    int f = fork();
    if(f == -1) {
        perror("fork issue");
	exit(1);
    } 
    
    else if(f == 0) {
	close(STDIN_FILENO);
        dup(fds[0]);
	close(fds[1]);
        close(fds[0]);

	execlp(cmd, cmd, NULL);
	perror("exec error");
	exit(1);
    } 
    
    else {

	close(fds[0]);
	close(fds[1]);
        wait(0);
    }
}




