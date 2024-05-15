% Zad 1
klonuj([], []).
klonuj([H|T], [[H,H]|T1]) :- klonuj(T, T1).

% Zad 2
srodek(L, S) :-
    append(L1, [S|_], L),
    length(L1, Len),
    Len =:= (Length-1) // 2.

% Zad 3
polowki(L, LL, LP) :-
    append(LL, LP, L),
    length(L, Length),
    length(LL, Length1),
    Length1 =:= Length // 2.

% Zad 4
sumuj([], 0).
sumuj([H|T], S) :-
    sumuj(T, S1),
    S is H + S1.

% Zad 5
ile_wiekszych([], _, 0).
ile_wiekszych([H|T], X, N) :-
    H > X,
    ile_wiekszych(T, X, N1),
    N is N1 + 1.
ile_wiekszych([H|T], X, N) :-
    H =< X,
    ile_wiekszych(T, X, N).

% Zad 6
plus_minus([], 0).
plus_minus([+|T], N) :-
    plus_minus(T, N1),
    N is N1 + 1.
plus_minus([-|T], N) :-
    plus_minus(T, N1),
    N is N1 - 1.
plus_minus([_|T], N) :-
    plus_minus(T, N).


% Zad 7
wstawiaj([], X, 1, [X]).
wstawiaj([H|T], X, 1, [X,H|T]).
wstawiaj([H|T], X, I, [H|T1]) :-
    I > 1,
    I1 is I - 1,
    wstawiaj(T, X, I1, T1).

% Zad 8
usuwaj(L, 0, L).
usuwaj([_|T], N, L1) :-
    N > 0,
    N1 is N - 1,
    usuwaj(T, N1, L1).

% Zad 9
rozdziel([], _, [], []).
rozdziel([H|T], X, [H|L1], L2) :-
    H < X,
    rozdziel(T, X, L1, L2).
rozdziel([H|T], X, L1, [H|L2]) :-
    H >= X,
    rozdziel(T, X, L1, L2).

% Zad 10
powiel([], [], []).
powiel([H1|T1], [H2|T2], L) :-
    powiel1(H1, H2, L1),
    powiel(T1, T2, L2),
    append(L1, L2, L).

powiel1(_, 0, []).
powiel1(X, N, [X|T]) :-
    N > 0,
    N1 is N - 1,
    powiel1(X, N1, T).
