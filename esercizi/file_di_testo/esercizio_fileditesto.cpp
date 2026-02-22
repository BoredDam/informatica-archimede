// prendi in input dei numeri, scrivili su un file di testo, e per ogni due numeri inseriti, scrivi la somma. scrivili nella forma "input1 + input2 = somma \n"


#include <stdlib.h>
#include <iostream>
#include <fstream>

using namespace std;

struct operazione {
    char op;
    
    int add1, add2, risultato;
};

struct operazione calcola (int add1, int add2, char op) {
    struct operazione return_op;
    return_op.add1 = add1;
    return_op.add2= add2;
    return_op.op = op;
    if (op=='+') {
        cout<<"addizione"<<endl;
        return_op.risultato=add1+add2;

    } else if (op=='-') {
        cout<<"sottrazione"<<endl;
        return_op.risultato=add1-add2;
    }
    return return_op;
}

int main() {
ofstream file ("output.txt", ios::app);
int menu = 0;
struct operazione monomio;
struct operazione risultato;

if (!file.is_open()) {
    cout<<"file non aperto "<<endl;
    return 1;
}

do { 
    cout << "inserisci 0 per uscire o qualsiasi altro numero per continuare";
    cin>>menu;
    if (menu == 0) {

        return 0;
    }
    cout<<"inserisci add1 e add2"<<endl;
    cin>>monomio.add1>>monomio.add2;
    cout<<"inserisci tipo di operazione "<<endl;
    cin>>monomio.op;

    risultato = calcola(monomio.add1, monomio.add2, monomio.op);
    file<<risultato.add1;
    file<<risultato.op;

    file<<risultato.add2<<" = "<<endl;
    file<<risultato.risultato; 
    file<<endl;


} while(menu == 0);
}