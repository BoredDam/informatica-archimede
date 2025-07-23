#include <string>

using namespace std;

struct indirizzo{
    int numero_civico;
    string via;
};

struct carta_identita{
    float altezza;
    string nome, cognome;
    struct indirizzo indirizzo;
};

int main() {
    carta_identita carta;
    carta.nome;
    carta.indirizzo.numero_civico;
}