#include <stdio.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);

    char names[n][50];     
    int count[n];          
    int unique = 0;        

    for (int i = 0; i < n; i++) {
        char temp[50];
        scanf("%s", temp);

        int found = 0;

        for (int j = 0; j < unique; j++) {
            if (strcmp(names[j], temp) == 0) {
                count[j]++;
                found = 1;
                break;
            }
        }

        if (!found) {
            strcpy(names[unique], temp);
            count[unique] = 1;
            unique++;
        }
    }

    int maxVotes = 0;
    char winner[50];

    for (int i = 0; i < unique; i++) {
        if (count[i] > maxVotes) {
            maxVotes = count[i];
            strcpy(winner, names[i]);
        }
        else if (count[i] == maxVotes) {
            if (strcmp(names[i], winner) < 0) {
                strcpy(winner, names[i]);
            }
        }
    }

    printf("%s %d\n", winner, maxVotes);

    return 0;
}