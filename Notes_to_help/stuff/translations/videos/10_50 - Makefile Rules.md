> Regulile din "makefile" au o sintaxa foarte simpla. 

> Ele sunt compuse dintr-un nume, o lista de dependente si din definiția regulii, care este de fapt o succesiune de instrucțiuni "shell" de executat. 

> Va propun sa scriem împreuna un exemplu pentru a vedea toate acestea in practica. 

> Voi edita un fișier pe care il voi numi "Makefile". Atentie, M trebuie sa fie majuscula! 

> Voi adauga un "header" si voi incepe sa scriu o regula. 

> O voi numi "regle_a". 

> Apoi, voi adauga sî la dreapta voi putea scrie o lista de alte reguli care vor trebui executate inainte de a executa regula "regle_a”. 

> Intr-un exemplu atat de simplu, voi renunța sa adaug aceste reguli si vom reveni mai târziu. 

> Definiția regulii incepe pe linia ce succede numele regulii. 

> Fiecare linie trebuie sa fie indentata printr-un "tab". 

> regula mea sa afișeze ceva pe ecran voi putea scrie:
> echo "regie A" 

> Salvez fișierul "Makefile". 

> Apelez "make" cu numele regulii anterior create ("regle_a"). 

> Sunt mai multe lucruri de remarcat in urma acestei execuții. 

> Vedem ca se afiseaza linia: echo "regie A". Este exact ceea ce am scris in fișier. 

> Trebuie sa stiti ca atunci când o regula din "makefile" este executata, 

> fiecare linie "shell" va fi afisata pe ecran inainte de a fi executata. 


> Asa se explica de ce se afiseaza intai:
> echo "regie A"
> ...si apoi:
> regie A 

> Putem sa inhibam acest comportament implicit, punând inainte liniei de "shell" caracterul 
> ceea ce face ca linia sa nu fie afisata inainte de a fi executata.

> Sa mergem mai departe... 

> Revenim la fișierul "Makefile” deja creat, voi defini o noua regula pe care o voi numi "regle_b" pentru care voi specifica drept dependenta "regle_a". 

> Vreau ca regula "b" sa afișeze mesajul "regie B". 

> Salvez si execut "regle_b". 

> Datorita faptului ca "regle_b" avea ca dependenta "regle_a", "make" a executat intai "regle_a", apoi "regle_b", după cum se poate observa pe ecran. 

> Acesta este modul prin care vom putea face ca o regula sa poata apela alta regula din dependente. 

> Prin acest mecanism vom putea instantia variabile, modifica un conținut etc. 

> Pentru ca am văzut cum putem defini un fișier "Makefile", vom discuta in sesiunea următoare cum putem sa definim variabile si cum putem sa le utilizam pentru a realiza lucruri mai complexe.