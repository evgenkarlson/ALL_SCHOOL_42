> Vom vedea cum putem deschide un fișier in C.

> Operația se realizează prin folosirea funcției "open" cu 2 sau 3 parametri, in funcție de cazul de utilizare.

> Primul parametru este calea relativa sau absoluta spre fișier, apoi modalitatea de deschidere a fișierului (in mod citire, in mod scriere sau ambele), si permisiunile in cazul creării unui fișier. 

> "open" va returna un descriptor de fișier de tip "int" pozitiv sau -1 in caz de eroare. 

> înainte de a va arata in cod cum putem deschide un fișier, sa vorbim puțin despre parametrul "flags".

Avem 3 flaguri care permit controlul accesului la fișiere:

> "O_RDONLY" care permite deschiderea in mod lectura,

> "O_WRONI_Y" care permite deschiderea in mod scriere

> "O_WRONLY" care permite deschiderea in mod scriere 

> si "O_RDWR" care permite deschiderea in ambele moduri. 

> Exista, de asemenea, cateva flaguri care permit modificarea comportamentului funcției "open". 

> Este vorba in special despre "O_CREAT" care permite crearea unui fișier daca acesta nu exista. 

> Flagurile pot fi înlănțuite folosind operația "sau" logic (binar). 

> Va las sa analizați in "man" cum se utilizează.

> Vom trece acum sa vedem codul. 

> In acest exemplu simplu, am inclus headerele necesare pentru "open", am declarat o variabila de tip "int" numita "fd”,careia i-am asignat valoarea returnata de funcția "open” cu parametri: fișierul "alph" (care conține cateva litere), si modul "read only".

> Voi afișa variabila "fd" pentru a verifica faptul ca obțin un descriptor de fișier valid. 

> Compilam exemplul. 

> Se afiseaza valoarea 3. 

> Sa revenim la cod. 

> Funcția "open" a returnat 3, iar aceasta valoare a fost afisata pe ecran. 

> Fișierul este deschis si il pot utiliza folosind acest descriptor de fișier cu valoarea 3. 

> Sa vedem cum putem deschide un fișier in modul scriere. 

> Vom deschide un fișier "42" in mod scriere (O_WRONLY), il vom crea daca nu exista (O_CREAT), vom recupera drepturile de scriere si citire (S_IRUSR) si vom afișa descriptorul de fișier (S_IWUS).

> Compilez codul. 

> Se afiseaza valoarea 3, deci fișierul a fost deschis cu succes. 

> Fișierul "42" a fost creat si putem vedea drepturile de citire si scriere asociate. 

> înainte de a trece mai departe, va voi arata ca valoarea returnata de funcția "open" este intotdeauna importanta. 

> Trebuie sa verificați de fiecare data valoarea descriptorului. 

> Va reamintesc ca valoarea returnata in caz de eroare este -1 
> si nu se poate utiliza un descriptor de fișier cu valoarea -1.

> Vom verifica faptul ca "fd" nu este egal cu -1. 

> Voi lașa "putnbr" după pentru a vedea ca descriptorul de fișier e -1. 

> Voi încerca sa deschid un fișier intr-un director in care nu am drepturi: 7dev/". 

> Compilez codul. 

> Execut codul. 

> Vedem ca descriptorul de fișier are valoarea -1. 

> Funcția "open" a returnat eroare si din acest moment nu pot sa utilizez fișierul. 

> Va voi arata cum sa închidem un fișier. 

> Aceasta operație se efectuează prin funcția sistem "close" 
> care primește un singur parametru, descriptorul de fișier, 
> si returneaza O in mod obișnuit sau -1 

> Revin la cod. 

> Repun la loc fișierul "42". 

> Voi parași funcția aici in caz de eroare. 

> Voi închide fișierul la finalul codului. 

> Recompilez codul. 

> Se afiseaza valoarea 3. Fișierul a fost deschis. 

> Fișierul va fi inchis in mod transparent pentru utilizator. 
> încheiem aici videoul despre deschiderea si închiderea fișierelor.

> Ne revedem in videoul următor sa vedem cum putem citi dintr-un fișier.