/**
 * negli appunti sono presenti altre varianti del codice
 * per ottenere letture diverse dal file.
 * 
 * 10/07/25
 */

#include <iostream>
#include <fstream>

using namespace std;

int main(){
	char testo;
	fstream text_file("something.txt", ios::in);
    
    while (!text_file.eof()) {
        text_file.get(testo);
	    cout<<testo<<"\n";
    }

    text_file.close();
}