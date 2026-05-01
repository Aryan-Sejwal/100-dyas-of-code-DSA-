#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start;
    int end;
} Interval;

int compareIntervals(const void* a, const void* b) {
    Interval* x = (Interval*)a;
    Interval* y = (Interval*)b;
    return x->start - y->start;
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapPush(int heap[], int* size, int value) {
    int i = (*size)++;
    heap[i] = value;

    while (i > 0) {
        int parent = (i - 1) / 2;

        if (heap[parent] <= heap[i]) {
            break;
        }

        swap(&heap[parent], &heap[i]);
        i = parent;
    }
}

void heapPop(int heap[], int* size) {
    heap[0] = heap[--(*size)];

    int i = 0;

    while (1) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int smallest = i;

        if (left < *size && heap[left] < heap[smallest]) {
            smallest = left;
        }

        if (right < *size && heap[right] < heap[smallest]) {
            smallest = right;
        }

        if (smallest == i) {
            break;
        }

        swap(&heap[i], &heap[smallest]);
        i = smallest;
    }
}

int minMeetingRooms(Interval intervals[], int n) {
    if (n == 0) {
        return 0;
    }

    qsort(intervals, n, sizeof(Interval), compareIntervals);

    int* heap = (int*)malloc(n * sizeof(int));
    int heapSize = 0;
    int maxRooms = 0;

    for (int i = 0; i < n; i++) {
        while (heapSize > 0 && heap[0] <= intervals[i].start) {
            heapPop(heap, &heapSize);
        }

        heapPush(heap, &heapSize, intervals[i].end);

        if (heapSize > maxRooms) {
            maxRooms = heapSize;
        }
    }

    free(heap);
    return maxRooms;
}

int main() {
    Interval intervals[] = {
        {0, 30},
        {5, 10},
        {15, 20}
    };

    int n = sizeof(intervals) / sizeof(intervals[0]);

    printf("Minimum rooms required: %d\n", minMeetingRooms(intervals, n));

    return 0;
}
