#include <stdio.h>
#include <string.h>

int main() {
    char s[100];
    int visited[26] = {0}; 

    printf("Enter string: ");
    scanf("%s", s);

    for (int i = 0; i < strlen(s); i++) {
        if (visited[s[i] - 'a'] == 1) {
            printf("%c\n", s[i]);
            return 0;
        }
        visited[s[i] - 'a'] = 1;
    }

    printf("-1\n");
    return 0;
}