
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <time.h>

int main(int argc, char* argv[]) {
        int i;
        pid_t pid;
	int N = atoi(argv[1]);
	int a[N];
	int status = 1;
	int nStartValue = time(NULL);
	srand(nStartValue);
	for (i = 0; i < N; i++) {
		pid = fork();
		a[i] = pid;
		if (pid == 0) {
			//child
			printf("Start of child's process: PID is %d\n", getpid());
	      		sleep(rand() % 15 + 1);
                	printf("End of child's process: PID is %d\n", getpid());
			exit(-1);
	      	}
	}
	while(1) {
		while(1) {
			for(i = 0; i < N; i++) {
				//parent
				waitpid(a[i], &status, 0);
				if(status == 0) {
					pid = fork();
					a[i] = pid;
					if (pid == 0) {
						//child
						printf("Start of child's process: PID is %d\n", getpid());
	      					sleep(rand() % 15 + 1);
                				printf("End of child's process: PID is %d\n", getpid());
						exit(-1);
	      				}	
					break;
				}
				status = 0;
			}
		}
	}
	return 0;
} 
