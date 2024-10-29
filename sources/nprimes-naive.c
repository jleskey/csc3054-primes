#include <stdio.h>
#include <math.h>
#include <stdbool.h>

int isPrime(int x);

int main() {
    int sum = 0;

    for (int count = 0, num = 2; count < 10; num++) {
        if (isPrime(num)) {
            sum += num;
            count++;
        }
    }

    printf("Sum: %d\n", sum);
}

int isPrime(int x) {
    for (int i = 2; i <= sqrt(x); i++)
        if (x % i == 0)
            return false;
    return true;
}
