> Pana acum ati compilat sursele apeland in mod direct compilatorul "gcc" din terminal. 

> Ati scris linii de comanda de tipul "gcc source.c", in urma carora rezulta un fișier executabil "a.out". 

> Aveam posibilitatea, atunci când aveam mai multe fișiere, sa le compilam cu o comanda "gcc *.c" care genera același "a.out". 

> Unii dintre voi poate utilizează opțiunea "-o" care va permite sa specificați numele programului. Ex.: gcc -o awesomeprog source.c 

> Rezulta un fișier executabil "awesomeprog" in plus de "a.out" care exista deja. 

> Trebuie spus faptul ca "gcc" este un compilator complex, si veți avea nevoie de timp pentru a intelege cum funcționează, precum si toate opțiunile pe care le pune la dispoziție. 

> Cu cat faceți acest lucru mai repede, cu atat mai repede veți fi familiari cu compilatorul si capabili sa il utilizați la capacitate maxima. 

> Pe măsură ce veți incepe sa invatati cum funcționează "gcc", veți înțelege ca acest compilator dispune de opțiuni care pot fi foarte complexe, iar, uneori, daca vrem sa compilam ceva separat, sau sa executam acțiuni ante si post compilare, sau sa adaugam directoare pentru "include", sau biblioteci, liniile de compilare la terminal pot sa devină foarte complicate.

> Ne vom da seama repede ca avem nevoie de un script "shell" pentru a le organiza mai bine. 

> In prima parte a cursului de astazi vom descoperi o unealta numita "makefile", care permite sa rezolvați aceasta problema intr-un mod eficace, cu o granularitate destul de fina cat sa faceți exact ce doriți.