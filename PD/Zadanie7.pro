% Zad 1
sumuj([],0).
sumuj([H|T],S) :- 
    sumuj(T,S1), 
    S is S1+H.

podzielniki(N,N,[]).
podzielniki(N,D,L) :- 
    D < N, R is N mod D, 
    R =:= 0, L = [D|T], 
    D2 is D + 1, 
    podzielniki(N,D2,T).
podzielniki(N,D,L) :- 
    D < N, 
    R is N mod D, 
    R=\=0, D2 is D + 1, 
    podzielniki(N,D2,L).

doskonala(N) :-	
    podzielniki(N,1,L), 
    sumuj(L,S), 
    S =:= N.
    
% Zad 2
przekroj([], _, []).
przekroj(_, [], []).
przekroj([H|T], [H1|T1], [H|T2]) :- 
    H =:= H1, 
    przekroj(T, T1, T2).
przekroj([H|T], [H1|T1], L) :- 
    H < H1, 
    przekroj(T, [H1|T1], L).
przekroj([H|T], [H1|T1], L) :- 
    H > H1, 
    przekroj([H|T], T1, L).


% Zad 3
glowyogony([], [], []).
glowyogony([[H|T]|O], [H|LG], [T|LO]) :- 
    glowyogony(O, LG, LO).
slad([[X]], X).
slad(M, S) :- 
    glowyogony(M, [G|_], [_|LO]), 
    slad(LO, NS), 
    S is NS + G.



% Zad 4
rozszerzaj([[X,Y]],[X,Y]).
rozszerzaj([[X,Y]|S],[X,Y]) :- 
    rozszerzaj(S,[M,N]),X=<M,Y>=N.
rozszerzaj([[X,Y]|S],[X,N]) :- 
    rozszerzaj(S,[M,N]),X=<M,Y=<N.
rozszerzaj([[X,Y]|S],[M,Y]) :- 
    rozszerzaj(S,[M,N]),X>=M,Y>=N.
rozszerzaj([[X,Y]|S],[M,N]) :- 
    rozszerzaj(S,[M,N]),X>=M,Y=<N.



% Zad 5
ciagliczb(X, X, [X]) :- X>0.
ciagliczb(M, N, [M|T]) :- 
    M>0, N>0, 
    M=<N, !, M1 is M+1, 
    ciagliczb(M1, N, T).

liczpodziel(N, N, 0).
liczpodziel(N, D, C) :- 
    D < N, mod(N,D) =:= 0, 
    !, ND is D+1, 
    liczpodziel(N, ND, OC), C is OC+1, !.
liczpodziel(N, D, C) :- 
    D < N, ND is D+1, 
    liczpodziel(N, ND, C), !.

antyp([], _).
antyp([H|T], LP) :- 
    liczpodziel(H, 1, C), 
    C < LP, antyp(T, LP), !.

antypierwsza(N) :- 
    CN is N - 1, 
    ciagliczb(1, CN, CL), 
    liczpodziel(N, 1, LP), !, antyp(CL, LP).


% Zad 6
rozmien(L, X, [X]) :- 
    append(_, [X], L).
rozmien(L, N, R) :- 
    append(_, [T], L), T < N, !, 
    NN is N-T, rozmien(L, NN, OR), 
    append(OR, [T], R).
rozmien(L, N, R) :- 
    append(P, [T], L), T > N, 
    !, rozmien(P, N, R).


% Zad 7 
wpolu([], _, []).

wpolu([[X, Y]|T], [[X1, Y1], [X2, Y2]], [[X, Y]|RP]) :-
    X1 =< X, X =< X2, Y1 =< Y, Y =< Y2,
    wpolu(T, [[X1, Y1], [X2, Y2]], RP).

wpolu([[X, Y]|T], [[X1, Y1], [X2, Y2]], RP) :-
    (X < X1; X > X2; Y < Y1; Y > Y2),
    wpolu(T, [[X1, Y1], [X2, Y2]], RP).


% Zad 8 ???
minX([[X,_]], X).
minX([[H,_]|T], H) :- minX(T, X), H < X.
minX([[H,_]|T], X) :- minX(T, X), H >= X.
maxX([[X,_]], X).
maxX([[H,_]|T], H) :- maxX(T, X), H > X.
maxX([[H,_]|T], X) :- maxX(T, X), H =< X.
minY([[_,X]], X).
minY([[_,H]|T], H) :- minY(T, X), H < X.
minY([[_,H]|T], X) :- minY(T, X), H >= X.
maxY([[_,X]], X).
maxY([[_,H]|T], H) :- maxY(T, X), H > X.
maxY([[_,H]|T], X) :- maxY(T, X), H =< X.
minpole(L, [[MinX,MinY],[MaxX, MaxY]]) :- minX(L, MinX), minY(L, MinY), maxX(L, MaxX), maxY(L, MaxY).


% Zad 9
zamien_g([],[]).
zamien_g([X],[X]).
zamien_g([X,Y|T], [X|NT]) :- Y >= X, zamien_g([Y|T], NT).
zamien_g([X,Y|T], [Y|NT]) :- Y < X, zamien_g([X|T], NT).
zamien_d([],[]).
zamien_d([X],[X]).
zamien_d([X,Y|T], [X|NT]) :- Y =< X, zamien_d([Y|T], NT).
zamien_d([X,Y|T], [Y|NT]) :- Y > X, zamien_d([X|T], NT).
odwracaj([], []).
odwracaj([H|L1], L2) :- odwracaj(L1, L), append(L,[H],L2).
koktajl([],[]).
koktajl([X],[X]).
koktajl(L, S) :- 
    zamien_g(L, L1), odwracaj(L1, [Najwiekszy|L2]), 
    zamien_d(L2, L3), odwracaj(L3, [Najmniejszy|L4]), 
    koktajl(L4, CS), append([Najmniejszy|CS], [Najwiekszy], S).



% Zad 10
ciagFib(N, F1, F2, [F1, F2]) :- F3 is F1 + F2, N < F3, !.
ciagFib(N, F1, F2, [F1|T]) :- F3 is F1 + F2, N >= F3, ciagFib(N, F2, F3, T).
rozklad(L, X, [X]) :- append(_, [X], L).
rozklad(L, N, R) :- append(_, [T], L), T < N, !, NN is N-T, rozklad(L, NN, OR), append(OR, [T], R).
rozklad(L, N, R) :- append(P, [T], L), T > N, !, rozklad(P, N, R).
rozklad_fib(N, L) :- ciagFib(N, 0, 1, CF), rozklad(CF, N, L).
