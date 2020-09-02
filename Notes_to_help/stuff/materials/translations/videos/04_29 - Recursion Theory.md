> Recursivitatea este un mod de programare diferit fata de putinul pe care l-ati invatat pana acum. 

> Ceea ce ati invatat pana acum este programarea iterativa, un stil de programare care utilizeaza bucle de instructiuni care se repeta, care nu se evalueaza si care returneaza valori manipuland variabile.

> In exemplul functiei "ft_strlen", avem o variabila care porneste cu valoarea 0, apoi facem o bucla, iar la fiecare iteratie i se va incrementa valoarea cu 1. 

> Se va manipula o variabila externa pentru a returna la sfarsit un rezultat.

> Rezultatul este stocat intr-o variabila. 

> Aceasta este programarea iterativa, "strlen" e exemplul canonic. 

> Programarea recursiva este diferita. Vom explica acum mai in detaliu. 

> O putem vedea ca niste papusi Matryoshka. 

> Avem functii care se vor autoapela pana la un punct in care vom utiliza un mecanism pentru a returna un rezultat. 

> Pentru a intelege mai bine, ar trebui sa intelegem mai bine stiva de memorie ("stack"). 

> Aceasta este o zona de memorie a programului care se va umple pe masura ce apelam functii, si care e practic vida la inceputul programului. 

> Sa luam un program simplu. La demararea executiei programului stiva e goala. 

> Rulam programul si functia "main" este apelata. 

> Functia "main" este impinsa ("push") pe stiva. 

> Apoi undeva in cod "main"-ul apeleaza "ft_putstr". 

> Functia "ft_putstr" va fi pusa pe stiva. 

> Si functia "ft_putstr" va apela functia "ft_putchar". 

> Functia "ft_putchar" va fi pusa pe stiva. 

> "ft_putchar" va apela functia "write", "write" va fi pusa pe stiva, si asa mai departe... 

> Principiul este ca de fiecare data cand apelam o functie, aceasta va fi impinsa pe stiva. 

> Se va evalua si la un moment dat cand executia functiei se va termina, se revine in functia anterioara. 

> Functia curenta aflata in partea superioara a stivei va fi eliminata din stiva ("pop"). 

> Vorbim de "push" si "pop". 

> Functia noastra va fi eliminata din stiva, deci vom reveni la cea dinainte. 

> In cazul nostru vom elimina succesiv de pe stiva functiile "write", "ft_putchar", "ft_putstr", "main", etc. 

> Vedem ca se respecta oarecum principiul papusilor Matryoshka.

> Sunt functii care sunt imbricate unele in altele. Acesta este si principiul functiilor recursive.

> Functiile recursive sunt functii care se autoapeleaza. 

> Si ale caror instante sunt impinse pe stiva una desupra celeilalte. Principiul nu e complicat. 

> Acest mecanism se aplica pana cand se obtine unul dintre cele doua rezultate posibile. 

> Sau avem o functie recursiva care se autoapeleaza si vom tot pune instante de-ale ei in stiva. 

> Si daca nu ne oprim, stiva de memorie se va tot mari, pana cand se umple si explodeaza. 

> Programul va crapa lamentabil, pentru ca sistemul ii va spune ca si-a depasit stiva alocata. 

> Deci va imaginati ca nu e o idee prea buna. 

> Al doilea tip de rezultat, ceea ce ar trebui sa se intample daca facem recursivitatea corect, 

> e sa ajungem la un moment in care se indeplineste o conditie de oprire. 

> Sa zicem ca in functia noastra "fn", care se autoapeleaza, daca un anumit criteriu este indeplinit, functia nu se mai autoapeleaza, doar returneaza. 

> E ca si cum ati spune: "stop, acum ma opresc, nu mai continui apelurile recursive, altfel explodeaza stiva" 

> E cam acelasi lucru cu conditia de oprire dintr-o bucla. De fapt e exact acelasi principiu. 

> Doar ca e implementata diferit. 

> Deci cand ajung la conditia de oprire nu mai adaug functii in stiva, facem "pop" pe functii, si coboram stiva, pentru a reveni la starea initiala. 

> Vom vedea acum un exemplu matematic intr-un editor. 

> Stiu ca nu tuturor le place matematica, dar exemplul se preteaza foarte bine pentru notiunea de recursivitate. 

> Sa luam exemplul functiei "factorial". 

> Pentru cei care nu au facut multa matematica, sau care au memoria selectiva, functia factoriala se scrie cam asa: 

> 5! = 5*4*3*2*1; ("!" inseamna factorial) 

> Nu e foarte complicat. La fel, 6! = 6*5*4*3*2*1, etc. 

> Ati inteles care e principiul. 

> Putem sa dezvoltam putin problema, sa incercam alti factoriali. 

> Factorial de 4 e dupa cum am spus 4*3*2*1. 

> 3! = 3*2*1, etc. 

> Daca va uitati bine (si cum le-am aliniat e si mai clar), putem zice ca 5! e 5*4! (dupa cum vedeti mai sus).

> Si deci 4! = 4*3!. 

> Pot continua, pana ajung la 1!. 

> 1!, foarte simplu, e 1, pur si simplu. 

> Asa deci. Factorial de 5, 4, pana la 1. 

> Daca va uitati cred ca veti incepe sa vedeti o mica asemanare cu o functie recursiva, vedem ca 5! e 5*4!, 4! e 4*3!, pana la 1! care e 1.

> Cam e o conditie de oprire, nu? 

> Daca nu e clar, vom generaliza putin, si sper ca va fi mai clar. 

> Pentru orice n > 0, n! = n * (n-1) * (n-2) *...*3*2*1. 

> Deci urmand exemplu de mai sus, n! = n * (n-1)!. 

> Pana aici nu avem probleme. Cel putin asa sper eu. 

> (n-1)! = (n-1) * (n-2)! 

> Etc, etc, etc. Pana cand ajungem la 1, care va opri recursivitatea noastra. 

> Aceasta e o forma de recursivitate. 

> Scrisa in mod matematica, bineinteles, dar e recursivitate. 

> Vom scrie codul pentru asta. 

> Nu cod C, ar fi prea simplu dupa aceea cand va trebui sa-l faceti ca exercitiu.. 

> Voi scrie functia in pseudocod, ca sa o vedeti si voi. 

> Putem scrie ca fact(N) = N * fact(N-1). 

> Scris asa, e o functie recursiva. 

> Careia totusi ii trebuie o conditie de oprire. 

> Precizam ca fact(1) = 1. 

> Deci cu asta puteti scrie o functie recursiva cu o conditie de oprire, care se va executa fara sa va faca programul sa explodeze. 

> Sau cel putin asa speram... 

> In cazul de fata, pentru orice N, pentru a calcula factorial de N, trebuie calculat factorial de N-1. 

> Pentru N-1 trebuie calculat factorial de N-2, etc. 

> Seamana cu o bucla de altfel, putem sa scriem asta si sub forma de bucla. 

> De altfel va trebui sa o faceti. 

> Ne vom opri aici, si vom vedea niste exemple in C in videoul urmator. Pe curand.