#include "algo.h"
#include <time.h> 
#include <sys/time.h>

#define NR_TESTS 25

int power(int a, int p, int m) {// folosim: 3^4 mod 7 = ((3 mod 7) * (3 mod 7) * (3 mod 7) * (3 mod 7)) mod 7

    long long int res = 1;
    for(int i = 0; i < p; i++) { 
        res = (res * a) % m;
    }
    return res;
}


void rabin_Miller(int *p, int n, int nr_iterations, int *prime_vector, int *nr_primes) {
    int  k = 0;

    for (int i = 0; i < n; i++) {
        int prim = 1;

        if(p[i] % 2 == 0 && prim != 2) { //pt a elimina cazurile evident neprime si a face algoritmul mai eficient
            prim = 0;
        }
        int s = 0;
        int d = p[i] - 1;
        while (d % 2 == 0) {
            s++;
            d /= 2;
        } //  p - 1 = (2 ^ s) * d 

        if(prim && p[i] != 2) {
            for(int j = 0; j < nr_iterations; j++) {
                int a;
                do {
                    a = rand();
                }while(a > p[i]); 

                if(!prim) {
                    break;
                }
                
                int res = power(a, d, p[i]);

                if(res != 1) {
                    int sw = 0;
                    for(int z = 0; z < s; z++) {
                        if(res == p[i] - 1) {
                            sw = 1;
                            break;
                        }
                        res = power(res, 2, p[i]);
                    }
                    if(!sw) {
                        prim = 0;
                        break;
                    }
                }
            }
            if(prim) {
                prime_vector[k++] = p[i];
            }
        }
    }

    *nr_primes = k;
}

int main(void ) {

    // FILE *in[NR_TESTS];
    // FILE *out[NR_TESTS];
    
    int nr_primes;

    // char in_filenames[NR_TESTS][15];
    // char out_filenames[NR_TESTS][17];
    
    // for(int i = 0; i < NR_TESTS; i++) {
        
    //     sprintf(in_filenames[i], "./in/test%d.in", i);
    //     in[i] = fopen(in_filenames[i], "r");

    //     sprintf(out_filenames[i], "./out/test%d.out", i);
    //     out[i] = fopen(out_filenames[i], "w");

    // }
    
    // for(int i = 0; i < NR_TESTS; i++) {

    //     int n;
    //     int p[n];

    //     fscanf(in[i], "%d", &n);
    //     for (int j = 0; j < n; j++) {
    //         fscanf(in[i], "%d", (p + j));
    //     }
        
    //     int primes[n];
    //     rabin_Miller(p, n, 50, primes, &nr_primes);

    //     fprintf(out[i], "%d\n", nr_primes);
    //     for(int j = 0; j < nr_primes; j++) {
    //         fprintf(out[i], "%d ", primes[j]);
    //     }

    //     fclose(out[i]);
    //     fclose(in[i]);
    // }

    FILE *testin;
    FILE *testout;

    testin = fopen("in/test4.in", "r");
    testout = fopen("out/test4.out", "w");

    int no;
    

    fscanf(testin, "%d", &no);
    int v[no];
    for (int j = 0; j < no; j++) {
        fscanf(testin, "%d", (v + j));
    }
    
    int primes[no];

    struct timeval start, end;
 
    gettimeofday(&start, NULL);

    rabin_Miller(v, no, 5, primes, &nr_primes);

    gettimeofday(&end, NULL);
 
    long seconds = (end.tv_sec - start.tv_sec);

    long micros = ((seconds * 1000000) + end.tv_usec) - (start.tv_usec);
 
    printf("The elapsed time is %ld seconds and %ld micros\n", seconds, micros);



    fprintf(testout, "%d\n", nr_primes);
    for(int j = 0; j < nr_primes; j++) {
        fprintf(testout, "%d ", primes[j]);
    }

    fclose(testout);
    fclose(testin);

    return 0;
}

