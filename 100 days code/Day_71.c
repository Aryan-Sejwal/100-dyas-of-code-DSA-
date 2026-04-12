#include <stdio.h>
#include <string.h>

#define SIZE 100

int table[SIZE];
int m;
void init() {
    for (int i = 0; i < m; i++) {
        table[i] = -1;
    }
}

void insert(int key) {
    int h = key % m;

    for (int i = 0; i < m; i++) {
        int index = (h + i*i) % m;

        if (table[index] == -1) {
            table[index] = key;
            return;
        }
    }

    printf("Hash Table Full\n");
}

void search(int key) {
    int h = key % m;

    for (int i = 0; i < m; i++) {
        int index = (h + i*i) % m;

        if (table[index] == key) {
            printf("FOUND\n");
            return;
        }

        if (table[index] == -1) {
            break;
        }
    }

    printf("NOT FOUND\n");
}

int main() {
    int q;
    scanf("%d", &m);  
    scanf("%d", &q);   

    init();

    while (q--) {
        char op[10];
        int key;

        scanf("%s %d", op, &key);

        if (strcmp(op, "INSERT") == 0) {
            insert(key);
        } else if (strcmp(op, "SEARCH") == 0) {
            search(key);
        }
    }

    return 0;
}