#include <stdio.h>
#include <math.h>
#include <string.h>

// Example: gcc -o test -lm sources/test.c && ./test | grep "not equal" | wc -l

#define TOLERANCE 1e-15

int countIntBits(const double x) {
    if (x == 0) return 1;

    int integer = (int)x;

    int count = 0;

    while (integer > 0) {
        count++;
        integer >>= 1;
    }

    return count;
}

double customSqrt(const double x) {
    if (x < 0) return -1;
    if (x == 0) return 0;

    double guess = x / 2.0;
    double previous = 0;

    do {
        previous = guess;
        guess = 0.5 * (previous + x / previous);
    } while (guess - previous > TOLERANCE || previous - guess > TOLERANCE);

    return guess;
}


int main() {
    printf("%d\n", countIntBits(4));
    for (int i = 0; i <= 1000; i++) {
        char test1[50], test2[50];

        char *winner;

        double sqrt_value = sqrt(i);
        double custom_value = customSqrt(i);

        double sqrt_offset = fabs(i - sqrt_value * sqrt_value);
        double custom_offset = fabs(i - custom_value * custom_value);

        if (sqrt_offset < custom_offset)
            winner = "math.h";
        else if (sqrt_offset > custom_offset)
            winner = "custom";
        else
            winner = "tie";


        snprintf(test1, sizeof(test1), "%.15f", sqrt_value);
        snprintf(test2, sizeof(test2), "%.15f", custom_value);
        printf("%d\t%s\t%s\t%s\t%s\n", i, test1, test2, winner, fabs(sqrt_value - custom_value) < TOLERANCE ? "equal" : "not equal");
    }
}
