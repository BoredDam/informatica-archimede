
# Riferimento vs Copia

Creando delle funzioni in C++ (e in C), gli argomenti possono essere passati per **copia** o per **riferimento**.

- Passare un valore per **copia**, significa passarne **una copia del contenuto**.
- Passare un valore per **riferimento**, significa passarne **una copia dell'indirizzo**.

### Sintassi:
```cpp
// per valore
void stampa(int arg){
    /*...*/
}

// per riferimento
void modifica(int &arg){
    /*...*/
}
```

Il simbolo `&` in questo caso si chiama "address-of", **indirizzo di**. Estrae l'indirizzo della variabile a cui si prepone.

## Casi d'uso

- Devo creare una funzione di stampa? Va bene un passaggio per **copia**.
- Devo creare una funzione per modificare un valore? Devo passarlo per **riferimento**.

## Come mai?

Gli argomenti delle funzioni sono delle copie di ciò che viene inserito nei parametri della funzione:

```cpp
void incrementa(int numero) {
    numero++; // sbagliato! numero non verrà modificata
}
```
*"Bene, mi hanno appena dato il **valore** di questa variabile `numero`! Lo incrementerò di 1."*; **non** sto modificando l'originale! La funzione **non** si comporterà nella maniera attesa.

```cpp
void incrementa(int &numero) {
    numero++; // corretto! numero verrà modificata
}
```
*"Bene, Mi hanno appena dato **dove** si trova la variabile `numero`! La incrementerò di 1."*; sto modificando l'originale! La funzione si comporterà nella maniera attesa.