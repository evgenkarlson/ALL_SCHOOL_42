> Veți descoperi azi ca exista unelte cu rolul de a scripta compilarea pe baza unui limbaj specific. 

> Comanda "make" face parte din aceasta categorie de unelte, dar nu este singura disponibila. 

> Va recomand sa cautati pe internet si in documentație pentru a vedea daca exista altele, si, de ce nu, sa incepeti sa utilizați aceste unelte.

> Astăzi ne vom concentra pe "make" si pe fișierele de tip "makefile". 

> Comanda "make" se utilizează împreuna cu unul sau mai multe fișiere "makefile" care vor descrie cu ajutorul unui set de reguli cum sa fie compilat programul. 

> Folosim comanda "make" care va face apel la "makefile", il va citi si il va executa. 

> Un "makefile" este pur si simplu un fișier numit "makefile", care va conține un set de reguli si variabile pentru a descrie comportamentul pe care compilarea trebuie sa il adopte. 

> Regulile vor putea sa se apeleze intre ele, vor putea sa utilizeze variabile etc. 
> -â *

> Esențialul este sa ajungem sa structuram întregul fișier pentru a ne atingem scopul fixat. 

> Consideram ca fișierul nostru conține o regula "clean". 

> Pentru a apela aceasta regula executam comanda: make clean 

> Ceea ce este important de precizat este ca nu toate regulile din fișierul "makefile" sunt executate de fiecare data când invocam comanda "make". 

> Din contra, de cele mai multe ori, o singura regula este executata, cu dependentele ei, pentru a realiza acțiunile pe care vrem sa le facem cu ea. 

> Sintaxa uneltei "make" este simpla, dar foarte puternica. 

> Vom consacra următoarea parte a acestui curs ca sa ii descoperim bazele. 

> Ce este important de notat aici este ca nu avem pretenția de a realiza un curs care sa fie exhaustiv sau perfect. 

> Dorim sa va sensibilizam si sa va aratam bazele sintaxei pentru a va putea descurca, dar partea esențiala se gaseste pe internet in documentația pe care va trebui sa o cautati si sa o cititi.

> Vom vedea imediat bazele sintaxei "makefile".
