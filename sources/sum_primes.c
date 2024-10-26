#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

void printSeries(const int* series, const int count);
int sumSeries(const int* series, const int count);
int getUpperBound(const int count);
int* generatePrimes(const int count);

int main(int argc, char** argv) {
    if (argc == 2) {
        const int count = atoi(argv[1]);
        const int* primes = generatePrimes(count);

        printf("\n");
        printSeries(primes, count);
        printf("\nSum: %d\n\n", sumSeries(primes, count));

        // Yep. We're freeing the memory just for show here.
        free(primes);
    } else {
        printf("Proper usage: %s <number of primes>\n", argv[0]);
        return 1;
    }
}

void printSeries(const int* series, const int count) {
    for (size_t i = 0; i < count; i++) {
        printf("%d%s", series[i], i == count - 1 ? "\n" : ", ");
    }
}

int sumSeries(const int* series, const int count) {
    int sum = 0;

    for (size_t i = 0; i < count; i++) {
        sum += series[i];
    }

    return sum;
}

int* generatePrimes(const int count) {
    const double upper_bound = getUpperBound(count);

    int sum = 0;

    bool* sieve = malloc(sizeof(bool) * (upper_bound + 1));

    // We'll just hard code 0 and 1 to being non-prime. We're not using
    // them.
    sieve[0] = sieve[1] = false;

    // We'll start by assuming all numbers from 2 through the upper bound
    // are prime. It's probably an incorrect assumption, but you have to
    // start somewhere.
    for (size_t i = 2; i <= upper_bound; i++) {
        sieve[i] = true;
    }

    // As it turns out, multiples of numbers greater than one are generally
    // not primes, so let's reflect that.
    for (size_t i = 2; i <= sqrt(upper_bound); i++) {
        if (sieve[i]) {
            for (size_t j = i * i; j <= upper_bound; j += i) {
                sieve[j] = false;
            }
        }
    }

    // The numbers have been sifted to bring out the primes. Now let's count
    // out the correct number.
    int* prime_list = malloc(sizeof(int) * count);
    for (size_t bi = 2, ii = 0; bi <= upper_bound && ii < count; bi++) {
        if (sieve[bi]) {
            prime_list[ii] = bi;
            ii++;
        }
    }

    // The sieve has served its purpose. May it rest in peace.
    free(sieve);

    return prime_list;
}

int getUpperBound(const int count) {
    return count < 6
        ? (int[]){0, 2, 3, 5, 7, 11}[count]
        : count * (log(count) + log(log(count)));
}
