#include <sys/types.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

pid_t pid;

int main(int argc, char **argv){
	int pid, status;

	pid = fork();
	switch(pid){
		case -1:
			exit(-1);
		case 0:
			if(argc > 1){

				printf("Soy el hijo y tengo argumentos para hacer un berrinchito.\n");
				sleep(1);
				while(1)
					printf("BUAA CUÑAA BUAA XO WAA XO BUAAA :'( :'( XO BUAA\t");				
			}
			else{
				printf("Soy el hijo y me porto bien\n");
				exit(0);
			}

		default:
			sleep(5);
			kill(pid, 9);
	}
	exit(0);
}