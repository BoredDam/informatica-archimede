// Creare una classe Lampadina che può essere accesa o spenta, 
// e se accesa, può essere modificata l’intensità (tra 1 e 5) tramite un metodo dedicato. 
// Tuttavia, è necessario impedire modifiche all’intensità quando la lampadina è spenta, 
// e non deve essere possibile impostare intensità negative. Scrivere la funzione main in cui creare un oggetto lampadina e testare i suoi metodi.
// Rappresentare il diagramma UML della classe.

#include <iostream>
using namespace std;

class Lampadina {
    private: 
        int intensita;
        bool acceso;
    public: 
    Lampadina () {
        intensita=0;
        acceso=0;
    };
    void set_intensita (int intensita_input) {
        if ( intensita_input>5 ||  intensita_input<1) {
            cout<<"intesnita non valida "<<endl;
            return;
        }
        if (acceso==1) {
            intensita=intensita_input;


        } else cout<<"errore "<<endl;
    };
    void interruttore () {
       if (acceso==1) {
        acceso=0;
        cout<<"ho spento la luce "<<endl;

    } else {
        acceso=1;
        cout<<"ho acceso la luce "<<endl;
    }
    };
};

int main() {
    Lampadina lampadina1;
    lampadina1.interruttore();
    lampadina1.set_intensita(-1);
}
