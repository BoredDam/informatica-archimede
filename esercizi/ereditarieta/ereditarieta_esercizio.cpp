// Creare una classe Persona (nome e cognome) e ereditare le classi Studente e Professore. 
// Lo studente contiene come attributo un array di 10 voti, mentre il professore la materia che insegna. 
// Creare un metodo che restituisca la media dei voti dello studente. 
// Nel main creare un vettore di 3 studenti e per ogni studente stampare cognome, nome e media voti.

#include <iostream>
#include <stdlib.h>
using namespace std;

#define NUMERO_VOTI 10

class Persona {
    protected:
        string nome;
        string cognome;
};

class Studente : public Persona {
    private:
        float voti[NUMERO_VOTI];
    public:
        Studente();
        void carica_voti();
        float calcola_media();
};

class Professore : public Persona{

};

Studente::Studente() {
}

void Studente::carica_voti() {
    for (int i = 0; i < NUMERO_VOTI; i++) {
        cout << "inserisci il voto numero "<< i << "."<<endl;
        cin>>voti[i];
    }
}

float Studente::calcola_media() {
    return 
}
