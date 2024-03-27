% Zad.1 :- rekurencja(po��czenie(A,B)).
next(�winouj�cie,ko�obrzeg).
next(�winouj�cie, szczecin).
next(ko�obrzeg,ustka).
next(ustka, gda�sk).
next(gda�sk,toru�).
next(gda�sk,olsztyn).
next(olsztyn,toru�).
next(olsztyn,bia�ystok).
next(szczecin,bydgoszcz).
next(szczecin, gorz�w-wlkp).
next(bydgoszcz,toru�).
next(bydgoszcz,pozna�).
next(pozna�,toru�).
next(gorz�w-wlkp,pozna�).
next(gorz�w-wlkp,zielona-g�ra).
next(zielona-g�ra,pozna�).
next(zielona-g�ra,wroc�aw).
next(toru�,��d�).
next(toru�,warszawa).
next(bia�ystok, warszawa).
next(bia�ystok,lublin).
next(pozna�,��d�).
next(warszawa,radom).
next(warszawa,��d�).
next(radom,lublin).
next(radom,kielce).
next(wroc�aw,��d�).
next(��d�,radom).
next(��d�,cz�stochowa).
next(cz�stochowa,kielce).
next(cz�stochowa,katowice).
next(katowice,krak�w).
next(kielce,krak�w).
next(kielce,rzesz�w).
next(lublin,kielce).
next(lublin,rzesz�w).
next(krak�w,rzesz�w).

po��czenie(A,B) :- next(A,B).
po��czenie(A,B) :- next(A,C), po��czenie(C,B).

% Zad 2 :- rekurencja(zjazd(X,Y,Z)).
zjazd(X,Y,Z) :- X = Z, next(Z,Y).
zjazd(X,Y,Z) :- next(X,A), zjazd(A,Y,Z).

% Zad 3.
trasa(X,Y,obok(X,Y)) :- next(X,Y).
trasa(X,Y,obok(X,obok(Z,W))) :- next(X,Z), trasa(Z,Y,obok(Z,W)).

% Zad 4.
trasa2(X,Y,obok(X,Y)) :- next(X,Y).
trasa2(X,Y,obok(obok(W,Z),Y)) :- next(Z,Y), trasa2(X,Z,obok(W,Z)).

% Zad 5. (trzecie zadanie, tylko trzeba u�y� list (jednak trzeba troch� zmieni�))
trasa3(X,Y,[X,Y]) :- next(X,Y).
trasa3(X,Y,[X|W]) :- next(X,Z), trasa3(Z,Y,W). % hmm...

