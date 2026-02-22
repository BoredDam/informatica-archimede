//Creare una classe Televisione sapendo che lo stato di una televisione è caratterizzato dal fatto di essere accesa o spenta,
//dal volume (che è compreso tra 0 e 10), dal canale (che è compreso tra 0 e 99).
// Creare un opportuno costruttore, e i seguenti metodi:
//pulsanteRosso(), canaleSuccessivo(), canalePrecedente(), aumentaVolume(), abbassaVolume(), impostaCanale(int). 
//Si impostino gli attributi privati e i metodi pubblici.
//Scrivere la funzione main in cui creare un oggetto televisione e testare i metodi.


#include <iostream>
using namespace std;

class televisione {
	private: 
        bool accesa;
        int volume;
        int canale;
	
	public: 
        televisione();
        ~televisione();
        void pulsante_rosso();
        void canale_successivo();
        void canale_precedente();
        void aumenta_volume();
        void abbassa_volume();
        void imposta_canale(int);

};

televisione::televisione () {
	volume=1;
	canale=5;
	accesa=false;
}

televisione::~televisione () {
	cout << "l'oggetto televisione e' stato distrutto!" << endl;
}

void televisione::pulsante_rosso () {
	accesa = !accesa;
	if (accesa) {
		cout << "la televisione e' stata accesa correttamente " <<endl;
		
	} else cout << "televisione spenta " << endl;
}

void televisione::canale_successivo () {
	if (accesa) {
		if (canale<99) {
			canale++;
		}
		cout<<"stai andando avanti e sei al canale "<<canale<<endl;
	} else cout<<"televisione spenta "<<endl;
}

void televisione::canale_precedente () {
	if (accesa) {
		if (canale>0) {
			canale--;
		}
		cout<<"stai andando indietro e sei al canale "<<canale<<endl;
	} else cout<<"televisione spenta "<<endl;
}

void televisione::aumenta_volume ()  {
	if (accesa) {
		if (volume<10) {
			volume++;
			cout<<"il volume ora e' "<<volume<<endl;
		} 
	} else cout<<"televisione spenta "<<endl;

}

void televisione::abbassa_volume()  {
	if (accesa) {
		if (volume>0) {
			cout<<"stai diminuendo il volume "<<endl;
			volume--;
			cout<<"il volume ora e' "<<volume<<endl;
		} 
	} else cout<<"televisione spenta "<<endl;
}

void televisione::imposta_canale (int c) {
    if (accesa) {                    
        if (c >= 0 && c <= 99) {    
            canale = c;
            cout << "canale e' " << canale << endl;
        } else {                    
            cout << "canale non valido" << endl;
        }
    } else {                          
        cout << "televisione spenta" << endl;
    }
}
	

int main () {
	televisione tel;
	tel.pulsante_rosso();
	tel.aumenta_volume();
	tel.abbassa_volume();
	tel.imposta_canale(10);
	tel.canale_successivo();
	tel.canale_precedente();
	tel.pulsante_rosso();
}

