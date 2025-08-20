#include <iostream>

using namespace std;

class Animale {
    private:
        string nome;
    public:
        Animale(string nome_input) {
            nome = nome_input;
        }

        virtual void spostamento() = 0; 
};



class Pesce : public Animale {

    private:
        int profondita;
    
    public:
        int get_profondita() {
            return profondita;
        }

        void set_profondita(int profondita_input) {
            profondita = profondita_input;
        }

        void spostamento() {
            cout << "sto nuotando" << endl;
        }
};

class Uccello : public Animale {
    
    private:
        int altezza;
    
    public:
        int get_altezza() {
            return altezza;
        }

        void set_altezza(int altezza_input) {
            altezza = altezza_input;
        }

        void spostamento() {
            cout << "sto volando" << endl;
        }
};


int main() {
    Pesce animal("pec");
}