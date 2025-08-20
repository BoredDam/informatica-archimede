#include <iostream>

using namespace std;

class Macchina {
    // attributi
    private:
        string targa;
        int cavalli;
        int velocita;
        float chilometri;

    // metodi
    public:      
        Macchina(int cavalli_input, string targa_input) { // costruttore
            velocita = 0;
            chilometri = 0;
            cavalli = cavalli_input;
            targa = targa_input;
        }

        Macchina(int cavalli_input, string targa_input, int velocita_input) { // costruttore
            velocita = velocita_input;
            chilometri = 0;
            cavalli = cavalli_input;
            targa = targa_input;
        }

        void accelera(int incremento) { // metodo setter o modificatore
            velocita = velocita + incremento;
        }

        int get_velocita() { // metodo getter o query
            return velocita;
        }
};





int main() {
    Macchina macchina1(100, "AAAAA");
    macchina1.accelera(20);
    cout<<macchina1.get_velocita()<<endl;
    Macchina macchina2(120, "BBBBB", 50);
    cout<<macchina2.get_velocita()<<endl;
}