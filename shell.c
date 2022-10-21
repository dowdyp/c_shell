#include "helper.h"

#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main() {
    
    bool quit = false;
    char *curr;
    char *name;

    curr = (char *) malloc(256*sizeof(char));
    name = (char *) malloc(256*sizeof(char));
    getlogin_r(name, 256);

    while(!quit) {
	printf("%s$ ", name);
    	scanf("%256s", curr);
	
	/* check if is quit */
	isQuit(curr);
	runCmd(curr);
    }
}

