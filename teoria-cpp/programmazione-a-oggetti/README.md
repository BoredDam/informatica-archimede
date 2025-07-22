# La programmazione ad oggetti - Object Oriented Programming

La programmazione ad oggetti è un paradigma (un tipo, un modello) di programmazione, che introduce concetti nuovi, quali **classi**, **oggetti**, **attributi** e **metodi**.

## Definizioni

In termini molto generali, definiremo
- Le classi come dei modelli che astraggono una famiglia di entità simili.
- Definiamo un oggetto come un'istanza concreta di una classe. 

Una classe è costituita da:

- **Attributi**: sono variabili interne agli oggetti della classe che (generalmente) offrono specifiche relative all'oggetto. 

- **Metodi**: sono funzioni interne alla classe, che astraggono comportamenti degli oggetti di quella classe.

```cpp
class Macchina {
    private:// ignora questa riga per ora!
        int speed;
        int fuel_level;     // ATTRIBUTI
        string model;

    public: // ignora questa riga per ora!
        int get_speed();
        void accelerate(int amount); // METODI
        void brake();
        void put_fuel(int amount);
}
```

### Per chiarire

A una classe, coincide un numero indefinito di istanze che possono essere create nel nostro codice, ovvero un numero indefinito di **oggetti**. I metodi e gli attributi sono definiti nella classe, ma il contenuto degli attributi è indipendente (generalmente) tra i vari oggetti.

## Metodi

Distinguiamo quattro tipologie principali di metodi:

- Costruttori: servono a creare gli oggetti.
- Distruttori: servono per eliminare gli oggetti creati.
- Modificatori: modificano lo stato (il valore degli attributi) di un oggetto.
- Query: ritornano lo stato (il valore degli attributi) di un oggetto.