% Zad.1 :- rekurencja(połączenie(A,B)).
next(świnoujście,kołobrzeg).
next(świnoujście, szczecin).
next(kołobrzeg,ustka).
next(ustka, gdańsk).
next(gdańsk,toruń).
next(gdańsk,olsztyn).
next(olsztyn,toruń).
next(olsztyn,białystok).
next(szczecin,bydgoszcz).
next(szczecin, gorzów-wlkp).
next(bydgoszcz,toruń).
next(bydgoszcz,poznań).
next(poznań,toruń).
next(gorzów-wlkp,poznań).
next(gorzów-wlkp,zielona-góra).
next(zielona-góra,poznań).
next(zielona-góra,wrocław).
next(toruń,łódź).
next(toruń,warszawa).
next(białystok, warszawa).
next(białystok,lublin).
next(poznań,łódź).
next(warszawa,radom).
next(warszawa,łódź).
next(radom,lublin).
next(radom,kielce).
next(wrocław,łódź).
next(łódź,radom).
next(łódź,częstochowa).
next(częstochowa,kielce).
next(częstochowa,katowice).
next(katowice,kraków).
next(kielce,kraków).
next(kielce,rzeszów).
next(lublin,kielce).
next(lublin,rzeszów).
next(kraków,rzeszów).

połączenie(A,B) :- next(A,B).
połączenie(A,B) :- next(A,C), połączenie(C,B).

% Zad 2 :- rekurencja(zjazd(X,Y,Z)).
zjazd(X,Y,Z) :- X = Z, next(Z,Y).
zjazd(X,Y,Z) :- next(X,A), zjazd(A,Y,Z).

% Zad 3.
trasa(X,Y,obok(X,Y)) :- next(X,Y).
trasa(X,Y,obok(X,obok(Z,W))) :- next(X,Z), trasa(Z,Y,obok(Z,W)).

% Zad 4.
trasa2(X,Y,obok(X,Y)) :- next(X,Y).
trasa2(X,Y,obok(obok(W,Z),Y)) :- next(Z,Y), trasa2(X,Z,obok(W,Z)).

% Zad 5. (trzecie zadanie, tylko trzeba użyć list (jednak trzeba trochę zmienić))
trasa3(X,Y,[X,Y]) :- next(X,Y).
trasa3(X,Y,[X|W]) :- next(X,Z), trasa3(Z,Y,W). % hmm...
