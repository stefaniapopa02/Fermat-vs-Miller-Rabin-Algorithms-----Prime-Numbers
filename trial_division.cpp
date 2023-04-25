#include "algo.h"

#define NR_TESTS 25

void trial_division(int *p, int n, int *prime_vector, int *nr_primes) {
    int k = 0;
    for(int i = 0; i < n; i++) {
        int prim = 1;
        if(p[i] % 2 == 0) {
            prim = 0;
        }
        for(int d = 3; d < sqrt(p[i]) && prim; d+=2) {
            if(p[i] % d == 0) {
                prim = 0;
            }
        }
        if(prim) {
            prime_vector[k++] = p[i];
        }
    }
    *nr_primes = k;
}

int main(void ) {
    FILE *in[NR_TESTS];
    FILE *ref[NR_TESTS];
    
    int nr_primes;

    char in_filenames[NR_TESTS][15];
    char ref_filenames[NR_TESTS][17];
    
    for(int i = 0; i < NR_TESTS; i++) {
        
        sprintf(in_filenames[i], "./in/test%d.in", i);
        in[i] = fopen(in_filenames[i], "r");

        sprintf(ref_filenames[i], "./ref/test%d.ref", i);
        ref[i] = fopen(ref_filenames[i], "w");

    }
    
    for(int i = 0; i < NR_TESTS; i++) {

        int n;
        int p[n];

        fscanf(in[i], "%d", &n);
        for (int j = 0; j < n; j++) {
            fscanf(in[i], "%d", (p + j));
        }
        
        int primes[n];
        trial_division(p, n, primes, &nr_primes);

        fprintf(ref[i], "%d\n", nr_primes);
        for(int j = 0; j < nr_primes; j++) {
            fprintf(ref[i], "%d ", primes[j]);
        }

        fclose(ref[i]);
        fclose(in[i]);
    }
    return 0;
}

