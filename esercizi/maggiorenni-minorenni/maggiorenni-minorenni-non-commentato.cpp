/**
 * Scrivere un programma che carica un vettore di età e stampa 
 * in output il numero di maggiorenni e minorenni presenti nell'array.
 * 
 * 07/07/2025
 * 
 */

#include <iostream>
using namespace std;

void carica_vec(int vec[], int dim) {

    for (int i=0; i<dim; i++) {
        cout<<"inserisci l'eta' numero "<<i+1<<" su "<<dim<<".\n";
        cin>>vec[i];
    }
}

void print_mag_min(int x[], int dim) {

    int mag=0;
    int min=0;

    for (int i=0; i<dim; i++) {
        if (x[i]>=18) {
            mag++;
        } else {
            min++;
        }
    }

    cout<<"I minorenni sono: "<<min<<"\n";
    cout<<"i maggiorenni sono: "<<mag<<"\n";

}

int main () {
    cout<<"inserisci quante eta' vuoi inserire nel tuo array!\n";
    int dim;
    cin>>dim;

    int* x = new int[dim];
    carica_vec(x, dim);
    print_mag_min(x, dim);
    free(x);
}