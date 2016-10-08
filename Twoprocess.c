#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){
	pid_t pid = fork();
	int PID;
	int status = 1;
	
	if (pid < 0) {
		perror("fork!");
		exit(-1);
	}
	
	if (pid > 0) {
		//parent
		while(pid > 0) {
			while(1) {
				waitpid(pid, &status, 0);
				if(status == 0) {
					pid = fork();
					break;
				}
				status = 0;
			}
		}	
	}
	if (pid == 0) {
		while(getppid() != 1000);
		execl("temp", "temp", NULL);
	}
	return 0;
}
