> Vom vedea in acest video cum putem citi dintr-un descriptor de fișier. 

> Se foloste funcția sistem "read" care primește trei parametrii: primul parametru este descriptorul de fișier de la care citim, al doilea parametru este un buffer destinație, si al treilea parametru este numărul de octeti de citit.

> Funcția "read" returneaza numărul de octeti cititi sau -1 

> Sa vedem cum aplicam la nivel de cod. 

> Am preluat programul de baza pentru deschiderea unui fișier. 

> Fișierul 42 este deschis in mod citire. 

> Voi defini dimensiunea bufferului la voaloarea 4096. 

> Voi crea o variabila "int" pentru a stoca valoara returnata de funcția "read". 

> Si voi crea un buffer. 

> Am făcut alocari statice, dar puteti folosi fara probleme alocari dinamice cu malloc. 

> Cresc dimensiunea bufferului cu un octet, vedem mai târziu la ce folosește. 

> Apelez funcția "read" pentru a citi 4096 octeti pe care ii stochez in "buf. 

> Nu uitati de caracterul "\0" pentru a termina șirul de caractere. 

> Vom afișa conținutul bufferului si numărul de caractere citite.

> Compilez. 

> Execut. 

> Se afiseaza conținutul bufferului. 

> Am citit 31 de octeti, mult mai puțin decât 4096. 

> In unele cazuri, nu veți cunoaște numărul de octeti inainte de a citi. 

> Va trebui, in acest caz, sa utilizați o bucla de citire. 

> Va arat asta imediat. 

> Funcția "read" returneaza O când ajunge la finalul fișierului. 

> Folosim aceasta condiție pentru a termina bucla. 

> Voi limita dimensiunea bufferului la 10 caractere. 

> Fișierul conține 31. 

> Voi compila. 

> La fiecare iterație a buclei, funcția "read” returneaza 10 caractere, iar la ultima iterație se returneaza O si părăsim bucla. 

> încheiem aici cu citirea unui fișier folosind descriptorul de fișier, ne revedem in video următor pentru a vorbi despre offset.