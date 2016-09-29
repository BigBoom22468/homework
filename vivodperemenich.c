#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
int main() {
	int i=0; 
	char* word;
	word = malloc(sizeof(char)*255);
	extern char ** environ;
	scanf ("%s", word);
	for (i = 0; i < 61; i++){       
		if ((strstr(environ[i], word)) != NULL) {	
		printf("%s\n",environ[i]);
		i++;
		}	
	}
    return 0;
}
