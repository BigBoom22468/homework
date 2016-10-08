#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>

int main() {
	int fd;
	pid_t pid;
	fd = open("bash", O_RDONLY);
	char c[2];
	c[0] = '1';
	char com[10000];
	int i = 0;
	while(read(fd, c, 1) != 0) {
		if(c[0] != '\n') {
			com[i] = c[0];
			i++;
		}
		else {
			com[i] = '\0';
			pid = fork();
			if(pid < 0) {
				perror("Fork!");
				exit(-1);
			}
			if(pid == 0) {
				execlp(com, com, NULL);
				perror("Exec!");
			}
			i = 0;
			com[0] = '0';
		}
	}
	
	return 0;
}


