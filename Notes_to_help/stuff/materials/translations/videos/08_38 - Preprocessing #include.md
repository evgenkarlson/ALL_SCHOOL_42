> Buna ziua. In primul video al zilei, vom vorbi despre o comanda de preprocesor numita "include". 

> Va trebui tastat inainte, pentru ca toate comenzile de preprocesor in general iau un in fata după cum veți vedea. 

> Si aceasta comanda "include" va permite sa includeți un fișier in alt fișier, inainte de compilare. 

> Deci in faza de preprocesare. 

> Va voi arata imediat un exemplu de utilizare si va va fi mai ușor sa intelegeti. 

> In general ati folosit funcția "write", sau vi s-a aratat funcția "write". 

> Daca vreți sa o folosiți in "main", sunteti obligați sa-i scrieți prototipul mai sus. 

> Pentru a cunoaște prototipul funcției "write", ar fi trebuit sa faceți un "man 2 write", si aici ati fi văzut ca "write" ia de fapt un "int", un "const void *" un "size_t" (care nici nu stiti ce e, dar deocamdată va spună ca e un "unsigned int", si veți vedea intr-un alt video cum se folosește un "size_t"), si returneaza un "ssize_t" (care e un "int"). 

> Deci daca voiam sa folosesc "write", ar fi trebuit sa pun prototipul deasupra "main"-ului. 

> Dar daca va uitati in "man", vedeți marcat aici
> "#include <unistd.h>". 

> Si asta vrea sa spună ca prototipul lui "write" exista deja intr-un fișier ",h", care e numit "unistd.h". 

> Deci in loc sa scriu aici prototipul si sa compilez cu asta, 

> acum vom utiliza un lucru de "adulti", un lucru de adevarati programatori, vom folosi "include". 

> Cum scriem un "include"? Scriem "#include" si după, intre "<" si "unistd.h". 

> Intre "<" si ">" inseamna ca vom cauta fișierul in PATH-ul de fișiere in care va cauta compilatorul. 

> Veți vedea ca puteti preciza acest PATH din compilator, va las pe voi sa cautati. 

> Exista si un alt mod de scriere, care va permite sa includeți fișierele din directorul vostru, 

> "#include" si de data asta adaugam ghilimele ("). 

> Deci de exemplu pentru a include un fișier "fct.h", putem sa-l includem asa (n-o sa fac asta chiar acum). 

> Deci ce se intampla când includ "unistd.h", veți vedea, acum voi incerca sa compilez, 

> Deci ce se intampla când includ "unistd.h", veți vedea, acum voi incerca sa compilez, inca o data cu "-Wall -W -Werror”, fara probleme, fara erori, si chiar si acum pot apela funcția "write". 

> Va voi arata mai precis ce s-a intamplat. 

> Exista comanda preprocesor numita "cpp", care va permite sa vedeți ce se intampla înainte de compilare. 

> Va reamintiți cum arata "main.c", va voi face un "cat" pe el sa vedeți. 

> Acesta este "main”-ul, cu un "#include", si daca va arat acum cu "cpp", iata ce a fost adaugat in el. 

> Tot ce vedeți e fișierul "unistd.h", care si el probabil a inclus alte fișiere, de altfel se vede. 

> Deci vedeți ca sunt foarte multe prototipuri in el, si care va va permite de fapt sa folosiți funcția "write" fara sa va puneți intrebari despre prototipul ei. 

> bSLva permite sa fiți portabili, pentru ca de fiecare data "unistd.h" va fi actualizat in funcție de distribuția pe care sunteti, si puteti sa-l includeți si deci veți avea valorile corecte pentru "write" si prototipul corect. 

> Deci singurul luqrufie care trebuie sa va aduceți aminte din acest video e ca atunci când faceți un ”#include" de un fișier, bQrițe fișier, nicLmpcar nu trebuie sa fie un *'.h", puteti face un *'#include" de orice dar va sfătuiesc sa faceți doar de ".h", puteti efectiv,jnqlude inaintea compilării textul propriu-zis al unui fișier, fara a fi tratat, si apoi veți putea compila.