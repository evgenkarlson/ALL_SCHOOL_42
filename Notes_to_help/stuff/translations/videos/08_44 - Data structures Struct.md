> Buna ziua. 

> In cursul pe care-l vom vedea azi, va voi vorbi de un alt cuvânt cheie, "struct". 

> "struct" e un cuvânt cheie care va va permite sa creați grupuri de date. 

> care vor fi legate unele de altele intr-o structura. 

> Vom vedea asta imediat, va voi arata un exemplu. 

> Imaginati-va ca avem o problema, am vrea sa facem calcule geometrice pe niște puncte. 

> Sa zicem ca am zece puncte in spațiu. 

> Una dintre metode pentru a defini zece puncte intr-un spațiu 2D, ar fi cu variabile "int" (nu ne batem capurcu "float"). 

> Puteti alege sa faceți asta: "int x[10];" (coordonata "x" a celor zece puncte), si "int y[10];" e coordonata "y" a celor zece puncte.

> Veți fi obligați tot timpul sa mențineți "x"-urile si "y"-urile împreuna, in paralel, si sa va plimbați cu ambele. 

> E puțin cam incomod, după cum v-ati dat seama. 

> Am fi putut de asemenea un lucru numit "point" (punct), si am fi pus o lungime de 20. 

> Si am fi spus ca locațiile impare sunt "x"-uri, si cele pare, "y"-uri. Sau invers, e același lucru. 

> Ati fi fost obligați de fiecare data când accesați un punct sa acessati o valoare, apoi indexul plus unu, sa inmultiti cu 2 ca sa treceti la următorul punct, etc.

> E cam dezastru... 

> Va voi arata deci o metoda prin care puteti utiliza puncte, etc., si sa definiți ce e un punct, "struct"-urile. 

> Pentru ca pentru mine un punct inseamna doua "int"-uri. 

> Cum se scrie? Se declara "struct", apoi numele, de exemplu "s_point". 

> Putem doar declara o structura facand asta, si asa doar spuneți ca exista. 

> E cam ca si cu prototipurile de funcții, diferența intre a declara si a defini ceva. 

> Acum o voi defini chiar aici. Definiția e cam ca si a unei funcții, cu acolade	s* se termina cu 

> Si acum in structura mea voi defini niște date, care vor fi incluse in structura construita. 

> De exemplu un "int x" si un "int y". 

> De acum pot sa declar o noua variabila de tip "struct s_point". 

> Trebuie scris si "struct", e important, atentie pentru cei care ati făcut alte limbaje unde "struct" dispărea. 

> Deci "struct s_point a;" de exemplu, si acum, daca vreau sa modific "x"-ul structurii "a", va trebui sa scriu "a.x".

> Punând punctul accesez variabila "x" a variabilei "a" care e o structura de tip "s_point". 

> Si de exemplu acum in "a.x" pot pune "10". Si in "a.y" pot pune "42". 

> Unul dintre avantajele structurilor e ca daca vreți sa copiati un "s_point" in altul, puteti sa faceți asta.

> Si acum "b" e o copie a lui "a"; deci daca modicati "a" acum, "b" nu va fi atins, si invers. 

> Si acum "x"-ul lui "b" e "10", iar "y"-ul, "42". 

> Deci e un mare avantaj. 

> Atentie totuși când faceți un apel de funcție faceți tot o copie, deci daca puneți in parametru o structura veți avea aceeași problema, veți copia in cazul asta doua "int"-uri, si riscati sa faceți operațiuni foarte greoaie, si sa folosiți multa memorie, mai ales pentru structuri mari, si se poate intampla. 

> In general folosim pointeri către structuri când incercam sa le pasam in parametru, doar daca stiti ce faceți, si in cazul acela nu e nici o problema. 

> Deci pana acum am văzut cum construim o structura, si cum punem apoi date in ea. 

> Ce putem pune in ea? 

> Putem pune "float"-uri, putem pune "char"-uri, putem pune chiar si alte structuri, de fapt putem pune cate* date vrem noi in structura. 

> Trebuie doar sa nu aiba aceiași nume, de exempfu aici "x"-ul si "y"-ul nu trebuie sa aiba același nume (ca si niște variabile normale). 

> Pentru ca daca nu, nu știm ce câmp accesam. 

> Acum va voi arata avantajul "typedef'-ului pentru structuri. 

> Daca scrieți asta, "typedef struct s_point", si-i spunem "t_point", acum in loc sa scriem "struct s_point" si numele variabilei, veți putea scrie doar "t_point", si ar fi exact același lucru. 

> Deci "typedef' folosește la a castiga din lățime, e un mic avantaj, e mai puțin de tastat. E destul de util.

> Va voi arata in același timp si altceva, un ultim punct despre structuri. 

> Am văzut ca puteti pune date înăuntru, mai invatam o mica regula. 

> Avem un nou operator, punctul, dar e o regula speciala pentru pointeri. 

> Daca vreau sa fac un pointer care se numește "ptr". 

> "ptr" va lua valoarea adresei structurii "a". 

> Pentru a putea accesa elementul ”x" al lui "a" prin ati fi crezut ca putem scrie asta: "(*ptr)" pentru ca ”*ptr" e de fapt "a", deci ”(*ptr).x". 

> Daca as scrie asta, nici o problema, merge. 

> Mai exista un tip de scriere, si folosește sageata, si sageata înlocuiește combinația steluta si punct. 

> Deci dereferentiati pointerul, si apoi cautati un element al structurii, 

> pentru ca elementul către care arata pointerul e o structura. 

> Am făcut turul structurilor, asta e tot, si cu asta puteti face foarte multe lucruri, 

> e o noțiune foarte folosita in C, si deci incercati sa va antrenați cu ea, pentru ca o vom folosi foarte mult.