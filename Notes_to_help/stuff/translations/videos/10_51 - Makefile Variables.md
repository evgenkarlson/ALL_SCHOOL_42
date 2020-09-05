> Acum ca ati invatat cum sa scrieți definiția unei reguli in "Makefile", vom descoperi impreuna cum se folosesc variabilele. 

> Vom vedea repede ca exista reguli care devin complicate, care va trebui sa fie dinamice, sau vor fi create plecând de la altceva, si va fi foarte practic sa putem regrupa aceste expresii complicate intr-o variabila pe care sa o putem reutiliza in "Makefile". 

> Sintaxa pentru variabile este foarte simpla: numele variabile urmat de simbolul "=" si definiția variabilei. 

> TEXT = "42 is for the braves" 

> Scuzati-mi accentul.. 

> a variabila "TEXT" care va fi inlocuita cu valoarea "42 is for the braves". 

> Am ales sa numesc variabila folosim doar majuscule. 

> Vom incerca sa utilizam variabila declarata. 

> Voi defini o regula "regle_a" care va folosi variabila "TEXT". 

> Sintaxa este un pic speciala: folosim urmat de numele variabilei la care facem referire, si 

> Comanda "make" va sti sa înlocuiască "$(TEXT)" cu valoarea "42 is for the braves". 

> Sa testam împreuna. 

> Va propun sa exploatam o convenție de utilizare: daca invocam "make" fara argumente, prima regula din fișierul "Makefile" va fi executata.

> Este o convenție practica ce permite executarea unei reguli implicite. 

> In cazul nostru, regula "regle_a" este prima din fișier si ea va fi executata. 

> Dovada:
> echo "42 is for the braves"
> unde variabila "TEXT" a fost inlocuita. 

> Si vedem ca corespunde si afisajul de mai jos. 

> Putem face lucruri mult mai complicate. Veți vedea ca putem genera date. Sunt lucruri pe care o sa va las sa le descoperiti singuri. 

> Exista sute de tutoriale pe internet care va vor ajuta sa invatati bazele folosirii variabilelor. 

> Ne revedem in videoul următor pentru un exemplu de "Makefile" ceva mai complet.