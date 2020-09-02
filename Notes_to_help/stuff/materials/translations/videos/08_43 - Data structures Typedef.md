> Buna ziua. 

> Am terminat cu preprocesorul, si in acest video vom trece la cuvinte cheie din C pe care inca nu le-am invatat, cum ar fi "typedef'.

> "typedef' e un cuvânt cheie care va permite sa redefiniti un tip. 

> Adică veți putea crea propriile tipuri. 

> Exista mari diferente fata de "define", care definea un macrou si ne permitea sa facem o inlocuire cuvânt cu cuvânt, pe când "typedef' chiar creaza un nou tip, si va voi arata cateva diferente intre "typedef' si "define". 

> Cum creem un "typedef’: foarte simplu, deja "typedef’, tipul de baza pe care vreți sa-l transformați, aici "int", si acum as vrea ca tipul "int" sa se numească "cacahuete". 

> Din cauza ca nu e un cuvânt de-al preprocesorului, e ceva executabil după cum veți vedea, deci trebuie pus la sfarsit. 

> E un lucru important 

> O data ce am făcut asta, in mod normal, in codul meu voi putea scrie "cacahuete a;" de exemplu. 

> Apoi voi face "a = 10;". Si in mod normal, daca totul merge bine, voi putea sa compilez fara nici o eroare. 

> Deocamdată nu vedeți nici o diferența cu "define", in afara de faptul ca intr-un "define" ar fi fost "cacahuete" in stanga si in dreapta lucrul inlocuit. 

> Adevăratele diferente sunt, unu, ca se executa in momentul compilării, deci nu preprocesorul se ocupa de asta. 

> Deci implica alte lucruri, si anume ca "typedef’ e de asemenea dependent de domeniu. 

> Ce inseamna ca "typedef' e dependent de domeniu? 

> Inseamna ca in funcție de unde voi pune "typedef'-ul, va acționa doar in anumite parti. 

> In cazul de fata va acționa doar in "main". 

> Va voi arata acum. 

> Daca de exemplu încerc sa fac alta funcție "void ft_fct" care nu ia nimic in parametru, si va declara o noua variabila de tip "cacahuete", pe care o voi numi a , si cu care voi face același lucru ca mai jos, a = 10;", in mod normal nu ar trebui sa compileze.

> upă cum vedeți, spune ca e o problema in "ft_fct". 

> "cacahuete" e "undeclared", pentru ca am declarat "cacahuete" aici, mai jos. 

> Deci după cum spuneam, e dependent de domeniu. 

> Daca repun "typedef' sus, înainte de domeniul "main"-ului, compilează. 

> Aceasta e prima mare diferența. 

> A doua diferența, ceva ce n-am fi putut face cu un "define", nu e standard dar va voi arata oricum, ca sa acoperim tot, avem un "int si-l numim "int_p". 

> Acum va voi arata un nou tip de variabila, "int_p", si e un "int*". 

> Daca am fi scris asta, ”int* a, b, c;", (de fapt steluta n-am pus-o la locul potrivit... de asta trebuie pusa steluta la dreapta, ca sa vedeți si mai binej asa vedem bine ca doar "a" va fi un pointer către "int". 

> "b" 

> Asta se intampla când scriem in felul acesta. 

> Daca as fi făcut un "#define INTP", de exemplu, înlocuit printr-un "int*", si aici puneam "INTP", e exact același lucru. 

> Steluta e la stanga nu la dreapta pentru ca e o înlocuire cuvânt cu cuvânt, dar "a" va fi un "int*", dar "b” si c vor fi "int'-uri. 

> In schimb folosind "typedef', daca aici scriu "int_p", "a", ”b" si "c" sunt toti trei pointeri către "int". 

> Deocamdată nu vedeți importanta "typedef'-ului, dar sunt multe posibilități. 

> Exemplul cel mai evident (ultimul pe care vi-l voi arata acum): ma întorc in "man 2 write", pe care l-am văzut deja când am vorbit de "include", după cum vedeți aici folosim "write" care ia un "size_t", si returneaza un "ssize_t". 

> Acestea sunt "typedef'-uri; daca vreodată cel care a scris "write"-ul vrea sa modifice tipul de date, avantajul "typedef' e ca voi, facand un "include" de "unistd" aveți "typedef' pentru "size_t", deci daca mâine schimba "size_t" sa nu mai fie un "unsigned int", ci un "long unsinged int", ajunge sa-l schimbe intr-un singur loc, si daca voi ati folosit in cod "size_t", se vor schimba automat in "long usigned int”.

> Si un alt avantaj e ca va face o verificare la compilare, si mesajele vor conține "cacahuete", nu "int", (nu face o înlocuire cuvânt cu cuvânt), deci daca faceți un "typedef int cacahuete", 

> I va va spune daca exista erori cu o variabila de tip cacahuete , ceea ce va va permite sa găsiți mai ușor problemele. 

> Asta e tot despre "typedef'.