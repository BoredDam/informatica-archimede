# Input e Output da file di testo

In C++, per operare con i file di testo, andremo ad utilizzare delle classi appartenenti alla la libreria

```cpp
#include <fstream>
```
che importeremo così.

Questa libreria contiene varie classi, di cui potremmo creare delle istanze. Tra queste, abbiamo

- La classe specializzata per la lettura da file, ossia `ifstream`. Si ottiene dell'input da un file, quindi **i**fstream.
- La classe specializzata per la scrittura su file, ossia `ofstream`. Si indirizza dell'output verso un file, quindi **o**fstream.
- La classe `fstream`, che permette sia lettura che scrittura.


## Come aprire e chiudere i file

1. Il primo passo è creare l'oggetto, che sia un `ifstream`, `ofstream` o `fstream`. Per comodità, ci riferiremo a questo parlando sempre di `fstream`.

```cpp
#include <fstream>
#include <iostream>

using namespace std;

int main() {
    fstream text_file; // <---
}
```

2. Usare il metodo `.open("nome_file.txt")` per associare un file all'oggetto in questione.

```cpp
#include <fstream>
#include <iostream>

using namespace std;

int main() {
    fstream text_file;
    text_file.open("nome_file.txt"); // <---
}
```

3. **Passaggio opzionale**, ma **fortemente consigliato**. Verificare se il file è stato aperto correttamente, con l'ausilio del metodo `.is_open()`. Questo ritorna un valore booleano, `true` **se il file è stato aperto con successo**, altrimenti `false`. Un file non verrà aperto con successo in caso di errori e anomalie. Ne consegue che è molto importante verificare che il file sia stato aperto

```cpp
#include <fstream>
#include <iostream>

using namespace std;

int main() {
    fstream text_file;
    text_file.open("nome_file.txt"); 
    if (text_file.is_open()) { // <---
        /*operazioni di lettura e/o scrittura*/
    } 
}
```

4. Effettua tutte le operazioni di lettura e scrittura che ti interessano. Parleremo dopo di come effettuare le operazioni di lettura e scrittura vere e proprie.

5. **Chiudi il file**. È buona pratica e rende più sicuri i codici.

```cpp
#include <fstream>
#include <iostream>

using namespace std;

int main() {
    fstream text_file;
    text_file.open("nome_file.txt"); 
    if (text_file.is_open()) { 
        /*operazioni di lettura e/o scrittura*/

        text_file.close(); // <---
    } else {
        cout<<"errore nell'apertura del file.\n";
    }

}
```

## Scrittura su file
*Il codice d'esempio utilizzato è "scrittura.cpp"*

Riutilizziamo la sintassi del `cout`, con il simbolo `<<`.
```cpp
#include <fstream>
#include <iostream>

using namespace std;

int main() {
    fstream text_file;
    text_file.open("rick.txt", ios::out);
    if (text_file.is_open()) {
        text_file<<"I turned myself in a text file, Morty!\n";
        text_file.close(); 
    } else {
        cout<<"errore nell'apertura del file.\n";
    }

}
```

Il contenuto del nostro file di testo sarà:
```
I turned myself in a text file, Morty!
```

#### Flags out e app
Notiamo come abbiamo dovuto specificare il flag `ios::out`, per specificare di sovrascrivere (o creare) un file chiamato "rick.txt".

```cpp
text_file.open("rick.txt", ios::out);
```

Per aggiungere il testo alla fine del file senza sovrascriverlo, possiamo specificare la flag `ios::app`.

```cpp
text_file.open("rick.txt", ios::app);
```

## Lettura da file

*Il codice d'esempio utilizzato è "lettura.cpp"*

```cpp
#include <iostream>
#include <fstream>

using namespace std;
int main(){
	string testo;
	fstream text_file("something.txt", ios::in);
    
    while (!text_file.eof()) {
        getline(text_file, testo, ',');
	    cout<<testo;
    }

    text_file.close();
}
```

### Leggere parole
Riutilizziamo ``>>`` per assegnare valori dal file di testo a variabili. Questo metodo permette anche la conversione delle letture in variabili int, float, double, char e string da file.

```cpp
#include <iostream>
#include <fstream>

using namespace std;
int main(){
	string testo;
	fstream text_file("something.txt", ios::in);
    
    while (!text_file.eof()) {
        text_file>>testo;
        cout<<testo<<"\n";
    }

    text_file.close();
}
```

Output:

```
i       
like    
cooking,
my      
family  
and     
my
pet.
commas
are
important.
this
is
a
test
text
file.
```
### Leggere righe

Utilizziamo la funzione `getline(nome_variabile_fstream, variabile_destinazione)`. La destinazione deve essere una stringa. La riga viene letta fino al carattere di fine riga.

```cpp
#include <iostream>
#include <fstream>

using namespace std;
int main(){
	string testo;
	fstream text_file("something.txt", ios::in);
    
    while (!text_file.eof()) {
        getline(text_file, testo);
	    cout<<testo<<"\n";
    }

    text_file.close();
}
```
Output:
```
i like cooking, my family and my pet.

commas are important.

this is a test text file.
```

Possiamo anche specificare un carattere di terminazione personalizzati, oltre il carattere di fine linea `"\n"`, come la virgola.

```cpp
#include <iostream>
#include <fstream>

using namespace std;
int main(){
	string testo;
	fstream text_file("something.txt", ios::in);
    
    while (!text_file.eof()) {
        getline(text_file, testo, ',');
	    cout<<testo<<"\n";
    }

    text_file.close();
}
```

Output:
```
i like cooking
 my family and my pet.

commas are important.

this is a test text file.
```
[ops]

### Leggere caratteri

```cpp
#include <iostream>
#include <fstream>

using namespace std;
int main(){
	char testo;
	fstream text_file("something.txt", ios::in);
    
    while (!text_file.eof()) {
        text_file.get(testo);
	    cout<<testo<<"\n";
    }

    text_file.close();
}
```

Output:

```
i
 
l
i
k
e
 
c
o
o
k
i
n
g
,

m
y

f
a
m
i
l
y

a
n
d

m
y

p
e
t
.




c
o
m
m
a
s

a
r
e

i
m
p
o
r
t
a
n
t
.





t
h
i
s

i
s

a

t
e
s
t

t
e
x
t

f
i
l
e
.
.
```


### Leggere fino alla fine del file. `eof()`

Sta per **end of file**. È un metodo che ritorna `true` se si è già alla fine del file, altrimenti `false`.

Ciò implicherà che, per leggere righe, parole o caratteri fino alla fine del file, sarà necessario inserire le operazioni di lettura all'interno di un ciclo cui condizione sia

```cpp
while (!text_file.eof()) {
    /*codice di lettura*/
}
```
*"effettua queste operazioni WHILE, finché non siamo alla fine del file."* Tradurre in linguaggio umano quello che viene espresso nel codice, ne facilita la comprensione.


## Quando usare le classi ifstream, ofstream e fstream

- `ifstream` è specializzata nelle funzioni di lettura.
- `ofstream` è specializzata nelle funzioni di scrittura, e di default crea il file su cui scrivere, se non esiste già.
- `fstream` è generico. Nella `open("file.txt", *flag*)` sarà necessario inserire uno dei seguenti flag

    - `ios::in` per leggere.
    - `ios::out` per scrivere. Crea o sovrascrive il file.
    - `ios::app` **append**. Apre il file e scrive sempre in fondo.
    - `ios::trunc` **truncate**. Svuota il file all'apertura e scrive il contenuto. È la modalità standard usata in `ios::out`.