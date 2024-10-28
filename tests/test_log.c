#include <stdio.h>
#include <math.h>
#include <string.h>

// Example: gcc -o test -lm sources/test.c && ./test | grep "not equal" | wc -l

#define TOLERANCE 1e-15

double customLog(double x) {
    if (x <= 0) return -1;

    double transformation = (x - 1) / (x + 1);
    double squared_transformation = transformation * transformation;

    double result = 0.0;
    double term = transformation;

    int i = 1;

    while (term > TOLERANCE || -term > TOLERANCE) {
        result += term / i;
        term *= squared_transformation;
        i += 2;
    }

    return 2 * result;
}

int main() {
    for (int i = 0; i <= 1000; i++) {
        char test1[50], test2[50];

        char *winner;

        double log_value = log(i);
        double custom_value = customLog(i);

        double log_offset = fabs(i - exp(log_value));
        double custom_offset = fabs(i - exp(custom_value));

        if (log_offset < custom_offset)
            winner = "math.h";
        else if (log_offset > custom_offset)
            winner = "custom";
        else
            winner = "tie";


        snprintf(test1, sizeof(test1), "%.15f", log_value);
        snprintf(test2, sizeof(test2), "%.15f", custom_value);
        printf("%d\t%s\t%s\t%s\t%s\n", i, test1, test2, winner, fabs(log_value - custom_value) < TOLERANCE ? "equal" : "not equal");
    }
}
