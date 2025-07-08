#include <iostream>
#include <cmath>

using namespace std;

struct punto {
    float x;
    float y;
};

struct punto punto_intermedio(struct punto p1, struct punto p2) {
    struct punto p_intermedio;

    p_intermedio.x = (p1.x + p2.x)/2;
    p_intermedio.y = (p1.y + p2.y)/2;

    return p_intermedio;
}

float distanza_tra_i_punti(struct punto p1, struct punto p2){
    
    /* definisci tu il comportamento di questa funzione!
    ho inserito una libreria che supporta una funzione chiamata sqrtf()
    che calcola la radice quadrata tra due valori float.
    
    Esempio d'uso:
        float result = sqrtf(9);
    */
    return 1; // sostituisci il valore di ritorno, chiaramente. ù
            // Temporaneamente ho messo 1 per evitare errori di compilazione.
}

void cambio_coordinate(struct punto &p, float nuovo_x, float nuovo_y) {
    p.x = nuovo_x;
    p.y = nuovo_y;
}


int main() {
    struct punto p1; 
    struct punto p2;

    p1.x = 2;
    p1.y = 3; // punto di coordinate (2,3)

    p2.x = 4;
    p2.y = 9; // punto di coordinate (4,9)

    struct punto pm;
    pm = punto_intermedio(p1, p2);

    cout<<"Punto intermedio di coordinate ("<<pm.x<<","<<pm.y<<").\n";

    cambio_coordinate(p1, 1, 2);
    
    cout<<"Coordinate appena cambiate ("<<p1.x<<","<<p1.y<<").\n";
}