// Se vengono estratti tre numeri uguali si vince il 100% della somma giocata, ad eccezione di tre zeri che fanno vincere il 200%.
// Con due numeri uguali si vince il 50% della posta. Si perde in tutti gli altri casi. 

// La classe deve implementare i metodi per scegliere se effettuare una giocata o immettere un nuovo saldo, visualizzare il totale accumulato o chiudere il gioco.

#include <iostream>
#include <stdlib.h>
#include <ctime>

using namespace std;

class Slot_machine {
    private:
        float saldo;
    public:
        Slot_machine();
        void set_saldo(float);
        float get_saldo();
        void gioca(float);
};

Slot_machine::Slot_machine () {
    saldo=100;

}

void Slot_machine :: set_saldo (float numero) {
saldo=numero;

}

float Slot_machine::get_saldo() {
    return saldo;
}

void Slot_machine :: gioca(float puntata) {

    if (puntata > saldo) {
        cout << "saldo insufficiente" << endl;
        return;
    }

    int slot[3];
    srand(time(NULL));
    saldo=saldo-puntata;

    for (int i=0; i<3; i++) {
        slot[i] = rand()%10;
        cout << "|" << slot[i] << "|";
    }
    cout << endl;

    if (slot[0]==slot[1] && slot[0]==slot[2]) { 

        if (slot[0]==0) {
            saldo = puntata*3 + saldo;
            cout << "hai vinto il 200% della puntata"<<endl;
            return;
        }
        saldo = puntata*2 + saldo;
        cout << "hai vinto il 100% della puntata"<<endl;
        return;
    } else if (slot[0]==slot[1] || slot[1]==slot[2] || slot[0]==slot[2]) {
        saldo = puntata*1.5 + saldo;
        cout << "hai vinto il 50% della puntata"<<endl;
        return;
    } else {
        cout << "non hai vinto nulla"<<endl;
    }
    
}

int main () {
    float saldo;
    int menu = 0;
    Slot_machine slot;

    do {
        cout<<"inserisci 0 uscire, 1 per aggiornare il saldo, e 2 per giocare"<<endl;
        cin>>menu;
        if (menu==1) {
            cout<<"reinserisci il saldo"<<endl;
            cin>>saldo;
            slot.set_saldo(saldo);

        } else if (menu==2) {
            cout<<"inserisci puntata "<<endl;
            float puntata;
            cin>>puntata;
            slot.gioca(puntata);
            cout<<"nuovo saldo: "<<slot.get_saldo()<<endl;
        }
    } while (menu !=0);
}

