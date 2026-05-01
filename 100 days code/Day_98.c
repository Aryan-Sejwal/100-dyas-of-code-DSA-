#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start;
    int end;
} Interval;

int compareIntervals(const void* a, const void* b) {
    Interval* x = (Interval*)a;
    Interval* y = (Interval*)b;

    if (x->start == y->start) {
        return x->end - y->end;
    }

    return x->start - y->start;
}

int mergeIntervals(Interval intervals[], int n, Interval result[]) {
    if (n == 0) {
        return 0;
    }

    qsort(intervals, n, sizeof(Interval), compareIntervals);

    int count = 0;
    result[count] = intervals[0];

    for (int i = 1; i < n; i++) {
        if (intervals[i].start <= result[count].end) {
            if (intervals[i].end > result[count].end) {
                result[count].end = intervals[i].end;
            }
        } else {
            count++;
            result[count] = intervals[i];
        }
    }

    return count + 1;
}

int main() {
    Interval intervals[] = {
        {1, 3},
        {2, 6},
        {8, 10},
        {15, 18}
    };

    int n = sizeof(intervals) / sizeof(intervals[0]);
    Interval result[n];

    int mergedCount = mergeIntervals(intervals, n, result);

    printf("Merged intervals:\n");
    for (int i = 0; i < mergedCount; i++) {
        printf("[%d, %d]\n", result[i].start, result[i].end);
    }

    return 0;
}
