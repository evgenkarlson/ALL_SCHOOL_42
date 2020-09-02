> Buna ziua tuturor. 

> Bine ati venit la aceasta sesiune depre pointeri către funcții. 

> Pana acum ati descoperit noțiunea de pointeri si ati folosit-o pentru a stoca adrese de variabile. 

> Sa ne reamintim pe scurt. 

> Putem declara o variabila:
> int x; 

> deci o variabila de tip "int", numita "x". 

> Am văzut ca putem declara variabila care au ca tip adresa altei variabile, vorbim aici de pointeri. 

> Spre exemplu, o variabila care are ca valoare adresa unui "int" se declara in felul următor. 

> Avem o variabila "x" de tip "int" si un pointer la "int" numit "y". 

> Avem posibilitatea sa ii dam o valoare lui "x", de exemplu 42, apoi sa referentiem adresa lui "x" in pointerul "y". 

> Pentru aceasta scriem "y = &x;". 

> Aceasta este o sintaxa pe care sper ca ati inteles-o deja. 

> Acum vom putea modifica valoarea lui "x" folosind pointerul "y". 

> Pentru aceasta vom dereferentia "y" folosind operatorul de dereferentiere 

> Vom atribui valoarea 0 pentru "x". 

> Conținutul lui "y" (adresa lui "x" dereferentiata) ia valoarea 0 in loc de 42. 
> adresa unui funcții intr-un pointer folosind ceea ce numim
> pointeri la funcții. 

> Ne vedem in cateva momente pentru a descoperi impreuna sintaxa acestor pointeri la funcții.