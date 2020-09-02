> Buna ziua si bine ati venit la aceasta a 11-a zi a piscinei. 

> Vom aborda astazi o noțiune importanta: listele inlantuite. 

> Listele înlănțuite sunt, in forma lor cea mai simpla, un ansamblu de noduri, stocate ca elemente separate de memorie, legate intre ele prin referințe, formând astfel un lanț. 

> Aceste noduri sunt structuri C ce conțin date arbitrare, precum si un element particular pe care as vrea sa il subliniez aici, o legătură (pointer) la următorul nod din lista.

> Adaugarea sau ștergerea unui element sau schimbarea ordinii elementelor din lista

> este o operațiune destul de simpla si tine de manipularea pointerilor. 

> In cazul tablourilor, pentru adaugarea unui nou element, este necesara alocarea unei zone de memorie mai mari decât pentru tabloul necesar, copierea tuturor elementelor din tabloul inițial, adaugarea elementului dorit si eliberarea zonei de memorie ocupata de primul tablou. 

> Chiar daca aceasta nu este o problema când manipulați cantitati mici de date, pot sa apara probleme in gasirea unei zone contigue de memorie de dimensiune potrivita atunci când lucrați cu cantitati mari de date. 

> Lista inlantuita insa e pur si simplu legata la noul element.