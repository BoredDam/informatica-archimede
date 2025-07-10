/**
 * banale test delle operazioni di lettura con
 * la classe fstream
 * 
 * 10/07/2025
 */

#include <fstream>
#include <iostream>

using namespace std;

int main() {
    fstream text_file;
    text_file.open("rick.txt", ios::out); 

    if (text_file.is_open()) { 
        text_file<<"I turned myself in a text file, Morty!\n";
        text_file.close(); 
    } else {
        cout<<"errore nell'apertura del file.\n";
    }

}