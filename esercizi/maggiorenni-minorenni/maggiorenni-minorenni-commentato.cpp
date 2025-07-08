/**
 * Scrivere un programma che carica un vettore di età e stampa 
 * in output il numero di maggiorenni e minorenni presenti nell'array.
 * 
 * 07/07/2025
 * 
 */

#include <iostream>
using namespace std;


// funzione per caricare i valori all'interno del vettore, 
// ARGOMENTI: vettore di interi e dimensione di quest'ultimo
// RITORNA: nulla
void carica_vec(int vec[], int dim) {

    for (int i=0; i<dim; i++) {
        cout<<"inserisci l'eta' numero "<<i+1<<" su "<<dim<<".\n";
        cin>>vec[i];
    }
}


// funzione per contare e stampare il numero di over e under 18, 
// ARGOMENTI: vettore di età (interi) e dimensione di quest'ultimo
// RITORNA: nulla
void print_mag_min(int x[], int dim) {

    int mag=0;
    int min=0;

    for (int i=0; i<dim; i++) {
        if (x[i]>=18) {
            mag++;
        } else {    // esistono solo due tipi di persone: chi ha più o esattamente 18 anni, e chi ne ha meno. basta un if else :)
            min++; 
        }

    }

    cout<<"I minorenni sono: "<<min<<"\n"; // "\n" lo preferisco a endl, ma cambia poco, anzi nulla 
    cout<<"i maggiorenni sono: "<<mag<<"\n";

}

int main () {
    cout<<"inserisci quante eta' vuoi inserire nel tuo array!\n"; // potresti creare un'altra funzione per questo... c'è bisogno?
    int dim;
    cin>>dim; 

    int* x = new int[dim];
    carica_vec(x, dim);     // consiglio! se dai nomi autoesplicativi alle funzioni, ti faciliti il lavoro a lungo termine
    print_mag_min(x, dim);  // (ed eviterai di inserire commenti idioti tipo i miei, shh)
    free(x); 
}



/***
 *                ORDINE DEGLI EVENTI NEL CODICE
 * 
 * 
 * 1. prendo in input la dimensione dell'array delle età (riga 50)
 * 2. alloco dinamicamente l'array delle età             (riga 52)   
 * 3. carico il vettore inserendo i valori delle età     (riga 53)
 * 4. stampo il numero di over e under 18                (riga 54)
 * 5. libero memoria deallocando l'array con la free()   (riga 55)
 */


