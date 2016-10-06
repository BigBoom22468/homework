#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
int main(int argc, char* arcv[], char** envp) {
	int i=0; 
	char* word;
	word = malloc(sizeof(char)*255);
	scanf ("%s", word);
	for (i = 0; i < 61; i++){       
		if ((strstr(envp[i], word)) != NULL) {	
		printf("%s\n", envp[i]);
		i++;
		}	
	}
        return 0;
}

