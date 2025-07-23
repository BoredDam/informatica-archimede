/**
 * Realizzare un programma che letto un file di testo chiamato “input.txt” 
 * visualizzi in output da quanti caratteri è formato.
 */
#include <fstream>
#include <iostream>
using namespace std;

int main() {
    int contatore=0;
    ifstream input;
    input.open("input.txt");
    while (!input.eof()) {
        input.get();
        contatore++;
    }
    input.close();

    cout<<contatore-1;

}