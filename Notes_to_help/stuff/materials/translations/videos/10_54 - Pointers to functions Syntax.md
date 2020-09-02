> Sintaxa pentru declararea unui pointer la funcție poate parea surprinzătoare la inceput pentru ca diferă de ceea ce am văzut pana acum. 

> Am pastrat din exemplul prezentat in videoclipul anterior declararea unei variabile de tip "int" si a unui pointer la "int”. 

> Declaram un prototip
> void f(char c); 


> Am declarat o funcție care nu returneaza nimic, care se numește "f" si care primește un parametru numit "c de tip "char".

> Pentru a declara un pointer la o funcție vom utiliza o sintaxa asemanatoare, dar nu identica. 

> Sintaxa este următoare: pentru a declara un pointer la o funcție care returneaza "void" si care preia un caracter ca si parametru, 

> vom scrie:
> void (*funptr)(char); 
> letrului. As fi putut sa o fac, dar pointerii la funcții ne permit sa nu facem acest lucru. 

> Va rog sa remarcați ca am pus intre paranteze numele pointerului la funcție precedat de operatorul 

> Va propun sa facem un exemplu ceva mai complet pe care-l vom compila sa vedem cum funcționează. 

> Voi declara o variabila de tip pointer la funcție pe care o voi numi "f'. 

> Va avea un parametru de tip "char". 

> Voi asigna adresa unei funcții la pointerul meu la funcție. 

> In cazul nostru, voi asigna adresa funcției "ft_putchar" definita mai sus. 

> Si voi apela funcția "ft_putchar" folosind pointerul la funcție "f'. 

> Sintaxa este identica cu cea pentru apelul unei funcții:
> f('z’); 

> Vom compila. 
> Vedem ca programul este compilat. A fost creat fișierul executabil "a.out". Si daca il execut, se afiseaza pe ecran caracterul "z". 

> Dat fiind faptul ca pointerii la funcții au o sintaxa delicata, exista posibilitatea de a folosi "typedef’ pentru a ușura utilizarea. 

> Sintaxa este următoarea:
> typedef void (*funptr)(char); 

> Voi scrie numele tipului pe care doresc sa il folosesc ca alias in locul variabilei pe care as fi folosit-o daca as fi declarat un pointer la funcție. 

> Deci aici voi pune "funptr". 
> li dau un parametru, un "char" de exemplu, si termin cu 

> Am posibilitatea de a folosi acest "typedef ca un tip. 

> putea declara: funptr f; 

> Compilam si executam. Rezultatul este același. 

> Ne vedem imediat pentru ultima partea a sesiunii, unde voi face niște remarci suplimentare despre pointerii către funcții,  si va voi arata un exemplu ceva mai complex.