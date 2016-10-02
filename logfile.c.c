#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>

#define BUFSIZE 255

int main() {
    FILE *f;
    f = fopen("logfile.log","r");
    int i, j, temp = 0;
    if (f == NULL) {
        printf("Error open file");
        fclose(f);
        exit(-1);
    }
    char* s;
    s = malloc(sizeof(char)*BUFSIZE);
    while(!feof(f)) {
        for(i = 0; i < 255; i++) {
            s[i] = fgetc(f);
            temp = i-4;
            if((s[i-3] == '2') && (s[i-2] == '0') && (s[i-1] == '1') && (s[i] == '6')) {
                i = 255;
            }
        }

        if (((strstr(s, "ERROR")) != NULL) && ((strstr(s, "http://")) != NULL)) {
            for (i = 0; i < temp; i++) {
                if ((s[i] == 'h') && (s[i+1] == 't') && (s[i+2] == 't')) {
                    for(j = i; j < temp; j++) {
                        printf("%c", s[j]);
                    }
                }
            }
        printf("\n");
        }
    }
      return 0;
}
