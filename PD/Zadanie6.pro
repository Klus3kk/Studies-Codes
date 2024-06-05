% Zad 1
najwiekszy([H], H).
najwiekszy([H|T], M) :-
    najwiekszy(T, MT),
    H >= MT,
    M is H.

najwiekszy([H|T], M) :-
    najwiekszy(T,MT),
    H < MT,
    M is MT.
    
% Zad 2
liniowa([X,Y]).
liniowa([X,Y,Z|T]) :-
    liniowa([Y,Z|T]),
    X-Y=:=Y-Z. 

% Zad 3
rozbij([],[],[]).
rozbij(L, [H|T], [H1|T1]) :-
    H > 0,
    length(H1,H),
    append(H1,L1,L),
    rozbij(L1,T,T1).

% Zad 4 
przynaleznosc([], _, [], []).
przynaleznosc([H|T], [L, P], [H|T1], LZ) :- 
    H >= L, 
    H =< P, 
    przynaleznosc(T, [L, P], T1, LZ), !.

przynaleznosc([H|T], [L, P], LW, [H|T1]) :- 
    H < L,
    przynaleznosc(T, [L, P], LW, T1).

przynaleznosc([H|T], [L, P], LW, [H|T1]) :- 
    H > P,
    przynaleznosc(T, [L, P], LW, T1).
    
% Zad 5 
decnabin(0,[0]) :- !.
decnabin(1,[1]) :- !.
decnabin(N,B) :- 
    N>=0, 
    N1 is N div 2,
    X is N mod 2,
    decnabin(N1,Y),
    append(Y,[X],B).

% Zad 6
szybkisort([],[]).
szybkisort([H|T], S) :-
    rozdziel(H, T, M, W),
    szybkisort(M, S1),
    szybkisort(W, S2),
    append(S1, [H|S2], S).

rozdziel(_,[],[],[]).
rozdziel(P, [H|T], [H|M], W) :-
    H =< P,
    rozdziel(P, T, M, W).
rozdziel(P, [H|T], M, [H|W]) :-
    H > P,
    rozdziel(P, T, M, W).
    

% Zad 7 
wstawsort([],[]).
wstawsort([H|T], S) :- 
    wstawsort(T, S1), 
    doposort(S1, H, S).


doposort([],X,[X]).
doposort([X], Y, [X,Y]) :- 
    Y>X, !.
doposort([X], Y, [Y,X]).
doposort([A,B|T], X, [A,X,B|T]) :- 
    X>=A, X=<B, !.
doposort([A,B|T], X, [X,A,B|T]) :- 
    X < A, !.
doposort([A,B|T], X, [A|S]) :- 
    X > B, !, 
    doposort([B|T], X, S).



% Zad 8
unikalne([], []).
unikalne([H|T], [H|U]) :-
    \+ member(H,T),
    unikalne(T,U).
unikalne([H|T], U) :-
    member(H,T),
    unikalne(T,U).
    
% Zad 9 (czyli implementacja seta)
najblizszy(_, [X], X).
najblizszy(X, [H|T], C) :-
    najblizszy(X,T,C),
    abs(H-X) > abs(C-X), !.
najblizszy(X, [H|T], H) :-
    najblizszy(X,T,C),
    abs(H-X) =< abs(C-X), !.

% Zad 10 
eratostenes(N, L) :- 
    ciagliczb(2,N,C), 
    sito(C,L).

ciagliczb(X,X,[X]) :- X > 0.
ciagliczb(X,Y, [X|Z]) :-
    X > 0, Y > 0,
    X =< Y, !,
    X1 is X+1,
    ciagliczb(X1,Y,Z).

sito([], []).
sito([H|T], [H|P]) :- 
    odsiewaj(H,T,R), 
    sito(R,P).

odsiewaj(_, [], []).
odsiewaj(X, [H|T], N) :- 
    mod(H,X) =:= 0, 
    odsiewaj(X,T,N).
odsiewaj(X, [H|T], [H|N]) :- 
    mod(H,X) =\= 0,
    odsiewaj(X,T,N).