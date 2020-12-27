#include <stdio.h>


void shift_element(int *arr, int i) {
    int *temp = arr + i;
    while (temp != arr) {
        int move = *(temp - 1);
        *temp = move;
        temp = temp - 1;
    }
}

void insertion_sort(int *arr, int len) {
    for (int i = 1; i < len; i++) {
        int *temp = arr + i;
        int *swap = temp - 1;
        int count = 0;
        while (swap >= arr) {
            if (*temp < *swap) {
                count++;
                swap--;
            } else {
                break;
            }
        }
        swap++;
        int t = *temp;
        shift_element(swap, count);
        *swap = t;
    }
}

int main() {

#define N 50

    int m[N];
    int count = 0;
    printf("\nEnter 50 positive integers ");
    while (count < N) {
        int num;

        if (scanf("%d", &num)) {
            *(m+count)=num;
            count++;
        }

    }
    insertion_sort(m, N);
    for (int *i = m; i < m + N-1; i++) {
        printf("%d,", *i);
    }
    printf("%d\n", *(m + N-1));
    return 0;
}