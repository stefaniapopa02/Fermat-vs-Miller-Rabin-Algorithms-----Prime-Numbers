#include <stdio.h>
#include <stdlib.h>
#define NR_TESTS 25
#define NR 100

void test_generator(){

    FILE* tests[NR_TESTS];
    char filename[25][20];

    for(int i = 0; i < NR_TESTS; i++) {
        sprintf(filename[i], "./in/test%d.in", i);
        tests[i] = fopen(filename[i], "w");
    }

    int p[NR * NR_TESTS]; //fiecare test va avea NR numere cu valori cuprinse intre 1000 si 1 000 000
    
    for (int i = 0; i < NR_TESTS; i++) {
        fprintf(tests[i], "%d\n", NR);
        for(int j = 0; j < NR; j++) {
            srand((i * 100) + j); 
            int randval;         
            do {                  
                randval = rand();
            }while(randval == 0  || randval < 1000 || randval > 1000000); //  sss
            p[(i * 100) + j] = randval; // generam nr aleatorii pt verificarea algoritmilor
            fprintf(tests[i], "%d ", p[(i * 100) + j]);
        }

        fclose(tests[i]);
    }

}
int main(void) {
    test_generator();
     return 0;
}