# About Structs

## A cosa servono?
Le struct offrono un modo per creare variabili composte (per le **struct standard**) e dei tipi personalizzati (cosiddette **named struct**) componendo variabili di tipi preesistenti (tra tipi standard e altre struct precedentemente definite). 

Alcune idee per delle struct:

- Punto `float coordinataX, float coordinataY`
- Voto `string materia, int voto`
- Data `int giorno, int mese, int anno`
- Account `string email, string password, struct Data data_creazione`

**Data** contenuta all'interno di **Account** è un esempio di **struct annidata**. 

## Differenza tra struct e named struct

### Esempio di struct senza nome
*Per qualche motivo*, il mio programma ha bisogno di una variabile che contenga la **data di oggi**.

```cpp
struct {
    int giorno;
    int mese;
    int anno;
} data_corrente;
```
Avrò creato una di **variabile**. È un'ottima idea se non ho intenzione di creare altre variabili con questi **campi** (giorno, mese, anno). Se il mio programma aggiorna una e una sola variabile `ultimo_accesso`, potrebbe essere un'idea non creare una named struct: non ho mica bisogno di un'altra variabile del genere!

```cpp
struct {
    int giorno;
    int mese;
    int anno;
} data_corrente, compleanno;
```

Ne posso dichiare più di una, quindi è un buon metodo anche se ne conosco il numero necessario a priori.


### Esempio di named struct - Più importanti!!
Il mio programma deve permettere la creazione di tante variabili di un tipo che non esiste già in C. Che si fa? Creo il mio nuovo tipo!

Immaginiamo di voler creare un programma che permetta di raccogliere una serie di punti su un piano 2D. Un punto in un piano a due dimensioni, è definito con una coppia di coordinate.

```cpp
struct punto {
    float x;
    float y;
};
```
Fatto ciò, abbiamo modo di **riutilizzare** questo **tipo personalizzato** all'interno del nostro codice!


```cpp
int main() {

    struct punto p1; 
    struct punto p2;

    p1.x = 2;
    p1.y = 3; // punto di coordinate (2,3)

    p2.x = 4;
    p2.y = 9; // punto di coordinate (4,9)
}
```

## Per accedere ai campi di una struct

La sintassi è molto semplice.

```cpp
struct punto {
    float x;
    float y;
};

struct punto p1;
```
- `p1.x` per accedere a x, `p1.y` per accedere a y.
- `cin>>punto.x;` per scrivere dentro `x`;


Proviamo con un esempio più complesso.
```cpp
struct triangolo {
    struct punto p1;
    struct punto p2;
    struct punto p3;
};

struct triangolo tri;
```

- `tri.p1.x` per accedere al campo x del punto numero 1.
- `tri.p3.y` per accedere al campo y del punto numero 3.

## Array di struct

Nulla di degno di nota da dire. È possibile creare un array di struct. Sono ottimi per creare delle vere e proprie tabelle.

```cpp
struct data {
    int giorno;
    int mese;
    int anno;
};

int main() {

    struct data assenze[25];

    assenze[0].giorno = 08;
    assenze[0].mese = 07;
    assenze[0].anno = 2025;

    assenze[1].giorno = 09;
    /* e così via...*/
}
```
