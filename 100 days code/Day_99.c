#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int position;
    int speed;
} Car;

int compareCars(const void* a, const void* b) {
    Car* car1 = (Car*)a;
    Car* car2 = (Car*)b;

    return car2->position - car1->position;
}

int carFleet(int target, int position[], int speed[], int n) {
    Car* cars = (Car*)malloc(n * sizeof(Car));

    for (int i = 0; i < n; i++) {
        cars[i].position = position[i];
        cars[i].speed = speed[i];
    }

    qsort(cars, n, sizeof(Car), compareCars);

    int fleets = 0;
    double slowestTime = 0.0;

    for (int i = 0; i < n; i++) {
        double time = (double)(target - cars[i].position) / cars[i].speed;

        if (time > slowestTime) {
            fleets++;
            slowestTime = time;
        }
    }

    free(cars);
    return fleets;
}

int main() {
    int target = 12;
    int position[] = {10, 8, 0, 5, 3};
    int speed[] = {2, 4, 1, 1, 3};
    int n = sizeof(position) / sizeof(position[0]);

    printf("Number of car fleets: %d\n", carFleet(target, position, speed, n));

    return 0;
}
