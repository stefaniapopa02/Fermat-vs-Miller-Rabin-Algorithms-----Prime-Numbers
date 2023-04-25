#include<stdlib.h>
#include<stdio.h>
#include<math.h>

int power(int a, int p, int m);
/* Calculeaza a^p mod m, unde:
   - a = baza
   - p = exponentul
   - m = numarul la care se imparte pt a se afla restul 
*/


void fermat(int *p, int n, int nr_iterations, int *prime_vector, int *nr_primes);
/* Calculeaza cu o anumita acuratete (in functie de numarul de iteratii)
daca numerele din vectorul dat sunt prime sau compuse si le retine pe cele prime 
intr-un alt vector. Programul reprezinta algoritmul lui Fermat,
ce se bazeaza pe Mica Teorema a lui Fermat.

    - p: vectorul de numere ce trebuie evaluate 
    - n: numarul de numere din vector
    - nr_iterations: numarul de iteratii folosite pentru a evalua un numar ca fiind 
    prim sau compus
    - prime_vector: vectorul in care punem numerele pe care algoritmul le gaseste ca
    fiind prime
    - nr_primes: numarul de numere prime gasite de algoritm
*/


void rabin_Miller(int *p, int n, int nr_iterations, int *prime_vector, int *nr_primes);
/* Calculeaza cu o anumita acuratete (in functie de numarul de iteratii)
daca numerele din vectorul dat sunt prime sau compuse si le retine pe cele prime 
intr-un alt vector. Programul reprezinta algoritmul Miller-Rabin, ce reprezinta
o forma imbunatatita a Micii Teorema a lui Fermat.

    - p: vectorul de numere ce trebuie evaluate 
    - n: numarul de numere din vector
    - nr_iterations: numarul de iteratii folosite pentru a evalua un numar ca fiind 
    prim sau compus
    - prime_vector: vectorul in care punem numerele pe care algoritmul le gaseste ca
    fiind prime
    - nr_primes: numarul de numere prime gasite de algoritm
*/


void trivial_primality_test(int *p, int n, int *prime_vector, int *nr_primes);
/*Acesta reprezinta algoritmul bine cunoscut, clasic de determinare a primalitatii
unui numar, verificand daca acesta are vreun divizor. Rata de succes a acaestuia este
de 100%, algoritmul fiind folosit pentru calcularea corectitudinii celorlalti.
    Rezultatele oferite de acest algoritm sunt retinute in folderul ref.

    - p: vectorul de numere ce trebuie evaluate 
    - n: numarul de numere din vector
    - prime_vector: vectorul in care punem numerele pe care algoritmul le gaseste ca
    fiind prime
    - nr_primes: numarul de numere prime gasite de algoritm
*/