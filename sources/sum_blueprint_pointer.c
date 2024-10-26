const int primes[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

int main() {
    int sum = 0;

    const int* p = primes;

    for (int i = 0; i < 10; i++) {
        sum += *p++;
    }
}
