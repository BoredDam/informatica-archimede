// Creare una classe Matita memorizzando il  tipoe la lunghezza in cm. 
// Implementare, oltre ai metodi getter e setter, un metodo tempera che accorcia la lunghezza della matita di 1 mm ogni giro. 
// Ereditare due sottoclassi:  MatitaConGommino, memorizzando il numero di cancellature a disposizione tramite il gommino e MatitaColorata che memorizza il colore. 
// Scrivere la funzione main per creare staticamente tre matite, una per tipologia, e testare i metodi. 

#include <iostream>
using namespace std;

class Matita {
    protected:
    string tipo;
    float lunghezza;

    public:
    Matita();

    float get_lunghezza();
    void set_lunghezza();
    void tempera();
};

class MatitaColorata : public Matita {
    private:
    string colore;

    public:
    MatitaColorata();
};


class Matita_con_gommino : public Matita  {
    private:
    int numero_cancell;
    void cancella();

    public:
    Matita_con_gommino();
};