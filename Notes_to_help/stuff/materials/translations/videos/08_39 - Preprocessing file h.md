> Buna ziua. In acest video vom continua sa vorbim despre "#include", si acum va voi spune care e interesul sa facem fișiere ".h" pentru a va putea projeta funcțiile împotriva erorilor de prototip. 

> Uitati un exemplu: am un "main" care va apela o funcție "ft_fct". 

> l-am scris prototipul mai sus: ia un "int" ca parametru, si nu returneaza nimic. 

> Si aceasta funcție nu face mare lucru, va afișa doar "coucou", ceea ce nu e prea grav. 

> Ce va voi arata e următorul lucru: imaginati-va ca ati avea vreo zece fișiere ".c", care toate apeleaza "ft_fct". 

> Ati fi obligat sa puneți de fiecare data prototipul. 

> Deja primul avantaj al "#include" e ca pentru ca veți putea include fișierul peste tot, ajunge sa-l includeți, după care daca schimbați prototipul funcției "ft_fct", nu va trebui sa-l schimbați in zece fișiere.

> II vetî scrie doar intr-un fișier, si pentru ca preprocesorul il va copia înainte de compilare, noua versiune de "ft_fct" va fi inclusa peste tot. 

> Si de asemenea va evita alte probleme. 

> Va voi arata un exemplu simplu: aceasta e funcția mea "ft_fct". 

> Pusesem deja include-ul, acum il șterg. 

> Deci "ft_fct" lua un "int" ca parametru; voi șterge faptul ca ia un "int" in parametru, si acum nu mai ia nimic. 

> Deci acum "ft_fct" nu ia nimic in parametru. Acum in "main" nu modific nimic. 

> In "main" declar ca "ft_fct" ia ca parametru un "int", deci ii trimit un parametru. 

> Daca compilez, iata ce se intampla (cu "fct.c"), compilează! Si merge! 

> Doar ca am făcut o harababura: pentru ca aici nu am dat nimic in parametru, iar in "main" i-am trimis ceva. 

> Puteam sa luam problema in sens invers,	putea sa ia un parametru, si sa declar ca nu ia nimic. 

> Si in acest caz, unde ar fi cautat informațiile? 

> In stack, si am fi avut o problema, codul meu ar avut un efect nedeterminat. 

> După cum vedeți am avea probleme de diferente intre fișierele care definesc funcțiile, si fișierele care le utilizează, in care ati pus un prototip. 

> Deci ideea corecta pentru a împiedica asta, e de a folosi "#include". 

> Am creat un fișier "fct.h", care e in local, deci de asta folosesc ghilimele, si el definește funcția "ft_fct" in mod corect. 

> II voi include in "fct.c", veți vedea imediat ce interes are; e un fel de securizare. 

> Si-I voi include de asemenea si in "main.c"; deci il voi include in loc de prototip. 

> Si acum ma voi uita in fișierul "fct.h" pe care l-am creat; am zis ca ia "int" ca parametru. 

> Si in "main"-ul meu ia un "int" in parametru, si acum vom compila si vom vedea ce da.

> Si veți vedea ca, din cauza ca e o problema undeva intre prototip si funcția mea, e treaba mea sa decid. 

> "ft_fct" pana la urma nu ia parametru. 

> Deci imi spun: ok, deci funcția pe care am facut-o nu ia nimic in parametru, trebuie deci sa-i schimb prototipul in "fct.h". 

> Deci acum il voi schimba si-i voi da "void". 

> Recompilez, si acum am alta eroare, dar acum nu mai e in "fct.c", e in "main.c 

> Pentru ca de data asta in "main", cum am schimbat prototipul, "main’-ul imi va spune: 

> "Am încercat sa o apelez dandu-i 10 ca parametru, nu merge." 

> Deci si aici va trebui sa șterg apelul cu parametru, si de data asta va compila. 

> Chiar va pot arata, daca fac "cpp main.c", veți vedea ca avem aici fișierul nostru "fct.h", care a fost rescris si conține prototipul de mai sus. 

> Principiul e sa evitati sa refaceti prototipuri la fiecare inceput de fișier, si sa folosiți in loc de asta "#include" de acum înainte, sinu ui ta ti sa includeți fișierul ”.h" care corespunde la unul dintre fișierele *'.c" (in mod normal prototipul va fi in fișierul ".h"), deci sa-l includeți in fișierele ".c" corespunzătoare, asa daca modificați o funcție, veți fi imediatla șurent când compilați, si puteti mai departe sa modificați fișierele ".h" si ".c" in funcție de asta.
