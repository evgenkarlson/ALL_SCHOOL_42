> Buna ziua si bine ati venit la aceasta a 12-a zi a piscinei. 

> Vom discuta astazi despre utilizarea fișierelor in C. 

> Vom vedea cum sa deschidem un fișier, cum sa il închidem, cum sa citim date din el sau cum sa scriem in el. 

> Intai, sa analizam noțiunea de descriptor de fișier ("file descriptor"). 

> Atunci când ii cereți sistemului sa deschidă un fișier, acesta va returna un descriptor de fișier (un număr intreg).

> Sistemul stochează in memorie un tabel care asociaza fiecare descriptor de fișier cu fișierul corespondent. 

> Din momentul in care obțineți acest descriptor de fișier, il veți utiliza pentru a executa operații asupra fișierului.

> După cum vedeți in exemplul pe care l-am reprezentat, programul ii cere sistemului sa deschidă fișierul "README”.

> Sistemul il deschide si asociaza descriptorul de fișier 42. 

> Din acest moment, va trebui sa folosesc descriptorul de fișier 42 pentru a efectua operații asupra acestui fișier. 

> Va voi arata ca ati folosit deja descriptorii de fișier, fara sa va dati seama. 

> In funcția write, pe care o cunoașteți bine, cereți sa scrieți caracterul pe "1". 

> Daca analizați pagina de ajutor man a funcției write, veți vedea ca primul parametru este un descriptor de fișier. 

> Descriptorul de fișier 1 face parte dintr-un set de descriptori de fișier standard. 

> Exista 3 astfel de descriptori standard. 

> O sau «stdin» este intrarea standard. 

> Atunci când folosiți tastatura, scrieți la intrarea standard. 
> 1 sau «stdout» reprezintă ieșirea standard, de exemplu afișarea pe ecran.
> 2 sau «stderr» este ieșirea de eroare care se afiseaza de asemenea pe ecran. 

> Ne revedem in videoclipul următor pentru a vedea cum deschidem si închidem fișierele.