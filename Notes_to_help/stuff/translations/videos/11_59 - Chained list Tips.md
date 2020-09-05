> Pana acum ati înțeles principiul listelor inlantuite. 

> O sa va arat o șmecherie. 

> Exista mai multe posibilititati de a implementa funcția "add_link". 

> O putem scrie sub forma următoare: funcția returneaza un "int" reprezentând un cod de eroare, si primește ca parametri un pointer dublu la lista si un pointer la "char", pentru a umple nodul. 

> Ce vrea sa însemne asta? 

> Atunci când vom apela "addjink" din cadrul funcției "main", vom scrie: 

> "add_link", si ii vom da adresa lui "list", si valoarea "titi". 

> Daca facem asta, avand in vedere ca am avut deja un pointer, si ca transmitem adresa pointerului, obținem un dublu pointer.

> Știm ca, daca avem o variabila "i” de tip "int" cu valoarea 10, putem crea un pointer la "int" numit "p" care va conține adresa variabilei "i". 

> Ce se intampla cu un pointer dublu? 

> Declaram "int **pp". 

> "pp" va conține adresa lui "p". 

> wroxe /userț/DOCti/j11/tist.c
> Inseamna ca funcția care a fost apelata poate modifica adresa pointerului in funcția apelanta. 

> Altfel spus, vom putea aloca dinamic memorie in funcția "add_link" pentru lista noastra. 

> In acest fel, "list" va pointa spre o zona de memorie valida si va fi setata in funcția "main". 

> Succes!