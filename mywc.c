#include <stdio.h>
#include <string.h>
//program < text.txt >> text.txt
int main() {
    char s;
    int line, word;
    line = 0;
    word = 0;
    while ((s = getchar()) != EOF) {
	if (s == '\n' ) {
        	line += 1;
		word += 1;
	}
	if (s == ' ') {
                word += 1;
	}
    }
    printf("%d lines\n%d words\n", line, word);
}
