#include <stdio.h>
#include <string.h>
//program < text.txt >> text.txt
int main() {
    FILE *f;
    char s[255];
    int line, word, flag, i;
    line = 0;
    word = 0;
    f = fopen("text.txt","r");
    while (fgets(s, 255, f) != NULL) {
        line += 1;
        flag = 0;
        for (i=0; i < strlen(s); i++)
            if (s[i] != ' ' && flag == 0) {
                word += 1;
                flag = 1;
            } else
                if (s[i] == ' ') flag = 0;


    }
    printf("%d lines\n%d words\n", line, word);
    fclose(f);
}
