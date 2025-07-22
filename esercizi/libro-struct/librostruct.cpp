#include <iostream>
#include <string>


/**
 * Dati 3 (N) autori, mettere il loro nome, il titolo del loro libro e anno di pubblicazione in un array di struct. 
 * Inserire poi un nome, e se questo nome è uguale a quello di uno dei 3 autori dei 
 * libri della lista, stampa cosa ha scritto l'autore e l'anno pubblicazione.
 */


#define N 3
using namespace std;

struct libro {
	string titolo, autore;
	int annopub;
};

void carica(libro l[]) {

	for (int i = 0; i < N; i++) {
		cout << "inserisci il titolo del libro:" << endl;
		getline(cin, l[i].titolo);
		cout << "inserisci il nome dell'autore:" << endl;
		getline(cin, l[i].autore);
		cout << "inserisci l'anno di pubblicazione:" << endl;
		cin >> l[i].annopub;
        cin.ignore();       // <--- pulisci il buffer d'input prima del prossimo getline(). 
                            // Sfortunatamente "cin >>" e getline() sono delle istruzioni con comportamenti molto differenti
                            // attenzione massima quando li usi assieme nel codice.  
    }	
}

int main() {
	libro l[N];
	carica(l);

	string autore1;
    bool autore_trovato = false; // utile per fare debugging
	cout << "inserisci un autore" << endl;

	getline(cin, autore1);

    
	for (int i = 0; i < N; i++) {
		if (l[i].autore == autore1) {
			cout << l[i].autore << " ha scritto " << l[i].titolo << " nel " << l[i].annopub << endl;
			autore_trovato = true;
			//break; // nell'ipotesi in cui ogni autore appaia solo una volta, questo break interrompe il for, in modo da non fare cicli inutili nel caso in cui l'autore sia già stato trovato
		}
	} 
    
    if (autore_trovato == false) { // nulla veniva stampato nel caso in cui l'autore non fosse stato trovato.
        cout << "autore non trovato..." << endl;
    }

}