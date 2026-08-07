#include <stdio.h>

int nums[] = {1, 2, 3};
int current[10];
int size = 0;

void backtrack(int index) {
    printf("{ ");
    for (int i = 0; i < size; i++) printf("%d ", current[i]);
    printf("}\n");

    for (int i = index; i < 3; i++) {
        current[size++] = nums[i];   // choose
        backtrack(i + 1);            // explore
        size--;                      // backtrack
    }
}

int main() {
    backtrack(0);
    return 0;
}