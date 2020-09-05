> Am invatat sintaxa si semantica de baza a fișierelor "Makefile", asa ca vom putea crea un prim exemplu care va compila un program. 

> Vom defini variabile si reguli standard. 

> Acest "Makefile" nu are ambiția de a fi complet, bun, sau suficient pentru a va implementa proiectele. 

> Vreau doar sa va initiez in problematica fara a va oferi un răspuns complet. 

> Daca veți analiza si utiliza acest fișier, veți constata ca exista multe erori, ca sunt lucruri pe care nu le face deși ar putea.

> Este datoria voastra sa descoperit! aceste probleme sau lipsuri citind documentația. 

> Așadar, luati acest cod ca pe un simplu exemplu pentru a va da o impresie despre ce se poate face cu "Makefile" ca sa ne compilam un program. 

> rimi ca valoarea numele fișierului executabil pe care
> doresc sa il generez. 

> Este o convertie, puteti numi aceasta variabila cum vreți. "NAME” mi se pare un nume rezonabil. 


> •e va primi ca valoare numele fișierelor sursa pe care vreau sa le
> compilez. 

> In cazul de fata fișierul "source.c" din directorul meu. 

> Dar as putea adauga pe toate de care am nevoie. 

> Daca e nevoie de mai multe linii pentru a specifica numele fișierelor sursa, va trebuie sa folosiți la finalul fiecărei linii 

> La fel cum faceți pentru macrourile preprocesorului in C. 

> Aici am doar un fișier deci nu se pune problema. 

> Mai jos am declarat cinci reguli standard pentru un fișier "Makefile". 

> all", apoi o regula care va avea același nume cu fișierul executabil ce va fi generat, "clean", "fclean" 

Știm ca daca invocam "make" fara parametru, este executata prima regula din fișier, in cazul nostru regula
"all". 

>  o convenție care ne va permite sa apelem regula care va realiza efectiv compilarea, regula "$(NAME)". 

> Valoarea efectiva pentru numele regulii va fi in acest caz "awesomeprog". 

> ’-o’
> pentru a specifica numele fișierului executabil ce
> va fi generat,

> si voi folosi variabila "$(NAME)" pentru a specifica numele. 

> irsele care sunt transmise compilatorului, iar pentru aceasta vom folosi variabila "$(SRC)"
> definita anterior. 

> Celelalte 3 reguli de mai jos au scop utilitar, care va vor ajuta in proiect. 

> Prima este regula "clean" care va șterge toate fișierele obiect generate in procesul de compilare. 
> Aveți posibilitatea sa utilizați aceasta regula pentru a șterge alte fișiere care nu va sunt utile, de exemplu anumite fișiere 

> Aici n-am făcut asta, dar va încurajez sa o faceți. 

> A doua regula este "fclean" care apeleaza regula "clean" ca si dependenta, iar aceasta regula va șterge executabilul creat. 

> La ce folosesc deci aceste reguli? 

> Compilez programul, se generează fișierele "*.o" si executabilul. 

> Daca apelez "clean", voi șterge fișierele dar voi păstră fișierul executabil. 

> Daca apelez "fclean", voi șterge atat fișierele cat si executabilul. 

> Ultima regula utilitara este "re", care permite resetarea compilării. 

> Reluam totul intr-un mediu curat. 

> Avem un apel al regulii "fclean" ca si dependenta, apoi a regulii "all". 

> erate in urma compilării vor fi sterse, apoi se va reapela compilarea. 

> Sa vedem împreuna un exemplu de utilizare a acestui fișier "Makefile". 

> Am in directorul curent un fișier "source.c" si fișierul "Makefile". 

> Daca invoc "make", prima regula este "all", care apeleaza regula "$(NAME)" care la rândul ei va compila programul, 

> facand:
> gcc -o awesomeprog source.c 

> Remarcați ca variabilele ”$(NAME)" si "$(SRC)" au fost înlocuite cu valorile lor. 

> Avem posibilitatea sa apelam regula "clean", dar neavand fișiere obiect "*.o" in cazul nostru, aceasta regula nu va face nimic, dar e un caz rar. 

> Daca vreau sa șterg executabilul, voi apela "fclean". 

> Si aceasta imi va curata directorul ștergând si fișierele ".o" dar si executabilul. 

> Daca vreau sa șterg fișierele generate la compilare si sa recompilez voi apela regula "re”. 

> Vedem ca totul este sters si apoi recompilat. 

> Pot sa vad in director executabilul care a fost recreat. 

> Cred ca am făcut turul asupra elementelor de baza pentru "Makefile". 

> După cum am spus de mai multe ori, acest curs este unul introductiv, 

> veți găsit pe Internet multe tutoriale si articole pe internet pe subiectul "Makefile". 

> Veți vedea ca este posibil sa faceți lucruri interesante, astfel incat compilarea sa nu fie doar generarea unor fișiere "*.o" si a unui executabil. 

> Chestiuni mai complexe care implica directoare de lucru, copii, legaturi, tot ceea ce este necesar pentru realiza un proiect veritabil care sa fie livrabil la final. 

> Va rog sa treceti la exerciții si va doresc mult curaj!