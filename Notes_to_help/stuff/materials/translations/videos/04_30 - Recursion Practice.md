> Acum ca am terminat cu teoria, vom face cateva exemple in cod. 

> Cu permisiunea voastra, voi incepe cu exemple care nu functioneaza. 

> Sunt erori despre care sunt sigur ca jumatate dintre voi le vor face... 

> prefer sa le fac eu pentru voi, si sa nu le mai repetati dupa aceea.

> Voi aplica literalmente ce am spus in primul video: 

> Voi face o functie recursiva "fn". O functie este recursiva daca se autoapeleaza. 

> Asta e tot. Fac o functie care se autoapeleaza. 

> Fac o functie "main" care apeleaza functia "fn". 

> Pentru ca altfel programul nu va face mare lucru. 

> Si cu un "return(O)", sa fie un program curat. 

> Voi compila programul. 

> Programul nu va afisa mare lucru, dar va face ceva simpatic. 

> Eroare segmentation fault... 

> De ce? In primul video (daca retin bine ce-am spus acum 10 minute), am zis ca o functie care nu are conditie de oprire cand se autoapeleaza e pusa pe stiva, dupa un apel e iar pusa pe stiva, o repunem, o repunem, etc., si dupa un timp imi va exploda in fata, pentru ca am depasit marimea stivei. Ceea ce trebuie neaparat evitat.

> Daca nu, veti avea surprize. 

> Deci probabil ca trebuie sa pun o conditie de oprire? 

> Pentru ca functia sa nu se repete la infinit. 

> Voi declara o variabila (ca pentru o bucla, cum sunt eu obisnuit), pe care o initializez cu 0, sa fac un contor. 

> Si voi face un test. Daca i <= 5 atunci apelez "fn". Daca nu, fac "return". 

> Inainte sa apeleze "fn", voi incrementa "i"-ul, altfel va fi tot timpul 0 si nu va merge treaba niciodata. 

> Voi compila asta... 

> Va merge asta, nu? 

> Am un "warning", nimic grav... Dar tot nu merge! Ce ridicol! 

> Bine... Oare ce-am gresit? 

> Uitati-va la functia "fn".

> Intru in functie, declar variabila "i". 

> Initializez "i" cu valoarea 0. 

> Testez daca i <= 5. "i" are valoarea 0. 

> Deci pot sa incrementez "i" cu 1 si sa apelez "fn". 

> Reintru i
> "fn"...

> ...aaa, da, am declarat o variabila, si am pus-o la 0. 

> Evident ca nu merge. 

> Reamintiti-va: atunci cand salvez o instanta "fn" pe stiva, aceasta instanta va avea propriul context, deci propriile variabile. 

> Deci va avea propria variabila "i" cu valoarea 0. 

> Apoi "i" va avea valoarea 1. Apoi apelez din nou "fn 

> Deci pun o noua "fn" pe stiva, de asemenea cu propriul context si propriile variabile, etc. 

> Vedeti ce va spun? 

> Deci noua "fn" are si el "i"-ul propriu, initializat la 0. 

> Apoi devine 1, dar tot nu e 5. 

> Deci reapelez "fn".

> Si reincep, si reincep, si vedeti ce rezulta. 

> Cum putem corecta aceasta eroare? 

> Daca va amintiti bazele invatate pana acum, transmiterea parametrilor si returnarea de valori, stiti ca exista un mijloc de a transmite valori intre functii.

> Ce pot sa fac? 

> As putea sa nu declar "i" in interiorul functiei, ci as putea sa il transmit ca parametru. 

> Apoi, voi putea retesta. 

> Si voi adauga un "return (0)" sa scap de warning. 

> Voi transmite valoarea lui "i" actuala in noul apel la "fn". 

> Voi face apelul in "main" cu valoarea intiala 0. 

> Voi avea primul apel cu i = 0. 

> "i” este mai mic decat 5, deci pot sa incrementez "i" si sa apelez "fn(1)". 

> 1 este mai mic decat 5, il incrementez pe "i" si apelez ”fn(2) 

> Si acesta este comportamentul pe care il doream. 

> Ca sa va demontrez ca merge bine, voi adauga un apel al functiei "write", afisand "D" (de la "debut") inaintea apelului unei noi functii. 

> Voi compila asta. 

> lata, imi afiseaza de 6 ori caracterul "D". 

> De ce 6? Pentru ca am mers de la 0 pana la 5 inclusiv, deci 6 apeluri. 

> Deci afîsez de 6 ori "D", ceea ce demonsteraza ca functia "fn" se apeleaza de 6 ori, si nu mai mult, exact ceea ce voiam. 

> Va arat un ultim exemplu menit sa clarifice conceptul stivei de apel. 

> Voi adauga un nou apel al functiei "write", scriind "F" dupa apelul functiei "fn". 

> Exista doua posibilitati: sau afîseaza "DF" de 6 ori, sau afiseaza altceva... 

> Dupa parerea voastra, ce se va afisa? 

> Sa vedem... Eu nu am nici o parere, eu descopar... 

> Ce afiseaza? De 6 ori "D" si de 6 ori "F". 

> De ce, dupa parerea voastra? 

> E foarte simplu: La inceput imping ("push") instantele functiei "fn" pe stiva. 

> Instantele functiei "fn" sunt executate pana la un anumit punct: afisez "D", apoi vine noul apel la "fn". 

> Deci se afîseaza "D" apoi se apeleaza 

> Care e pus peste prima "fn", care inca nu e terminata. 

> O pun deasupra. 

> Execut pana se afiseaza "D", reapelez "fn", etc. 

> Dupa un timp nu mai apelez "fn", revin inapoi. 

> Revin la "fn" dinainte, care avansase pana la apelul lui "fn", care tocmai s-a terminat, deci acum sunt la "write" de "F". 

> Deci mi-am afisat toti "D". Acum afisez un "F", revin, afisez un "F", revin, etc. 

> Pana ajung jos in stiva, revin in "main" si inchei programul. 

> Acesta este un exemplu de functie recursiva, care, chiar daca nu face nimic constructiv, este un bun exemplu. 

> Are o conditie de oprire, si afiseaza ceva, si care merge foarte bine. 

> Daca va uitati cu atentie, puteti vedea o asemanare cu o bucla: avem un bloc de instructiuni, avem un contor, iar blocul de instructiuni se repeta de o anumita maniera. 

> Recursivitatea si iteratiile sunt doua principii diferite, sunt multe lucruri pe care le putem face cu ambele, 

> exista operatii care sunt mai simplu de realizat iterativ, altele care sunt mai simplu de realizat recursiv. 

> Veti vedea asta pe masura ce acumulati experienta. 

> Trebuie sa retineti doua lucruri importante din acest video, bazele functiilor recursive: 
> O functie recursiva este o functie care se autoapeleaza.

> O functie recursiva (cel putin una care nu explodeaza) are o conditie de terminare. 

> Daca folositi un contor, trebuie sa gasiti o modalitate pnn care sa transmiteti valoarea contorului de la o instanta la alta. 

> Pentru asta exista parametri si retururi de valoare. 

> Atat pentru azi. Succes la rezolvarea exercitiilor! Pe curand!
