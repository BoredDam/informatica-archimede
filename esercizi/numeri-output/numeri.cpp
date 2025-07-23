/**
 * Realizzare un programma che scriva sul file “numeri.txt” 
 * i numeri dati in input da tastiera, separati da spazi, 
 * fino a quando viene inserito il numero 0.
 */

#include <fstream>
#include <iostream>

using namespace std;

int main() {
    ofstream file_numeri; 
    file_numeri.open("numeri.txt");

    int numero;
    cin >> numero;

    while (numero != 0) {
        file_numeri << numero << " ";
        cin >> numero;
    }

    file_numeri.close();
}