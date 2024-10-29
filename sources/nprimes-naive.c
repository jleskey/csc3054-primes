#include <stdio.h>
#include <math.h>
#include <stdbool.h>

int main() {
    int counter = 0;
    int sum = 0;
    int num = 2;

    while (counter < 10) {
        int isPrime = true;

        for (int i = 2; i <= sqrt(num) && isPrime; i++) {
            if (num % i == 0) {
                isPrime = false;
            }
        }

        if (isPrime) {
            sum += num;
            counter++;
        }

        num++;
    }

    printf("Sum: %d\n", sum);
}
