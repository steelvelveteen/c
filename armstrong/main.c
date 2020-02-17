#include <stdio.h>
#include <math.h>

int main(void) {
    double candidate = 1153;

    int n = log10(candidate);
    printf("Log10 of candidate: %d\n", n);

    printf("Candidate mod 10: %d\n", (int)candidate %10);

    return 0;
}

int is_armstrong_number(int candidate) {

    int p = ceil(log10((candidate % 10) == 0 ? candidate + 2 : candidate));
    int s = 0;
    for (int v = candidate; v > 0; v = v/10) {
        s += pow(v % 10, p);
    }

    return s == candidate;
}
