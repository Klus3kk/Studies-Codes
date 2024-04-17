% Zad 1
ostatni(X,[X]).
ostatni(X,[_|T]) :- ostatni(X,T).
% Zad 2
przedostatni(X,[X,_]).
przedostatni(X,[_|T]) :- przedostatni(X,T).
% Zad 3
bezostatniego([_],[]).
bezostatniego([H|T],[H|T2]) :- bezostatniego(T,T2).
% Zad 4
nakoniec(X,[],[X]).
nakoniec(X,[H|T],[H|T2]) :- nakoniec(X,T,T2).
% Zad 5
zakazdym([], _, []).
zakazdym([H|T], X, [H, X|T2]) :- zakazdym(T,X,T2).
% Zad 6
codrugi([],[]).
codrugi([_],[]).
codrugi([_,X|T],[X|T2]):-codrugi(T,T2).
% Zad 7
wstaw_za([X|T], X, Y, [X, Y|T]).
wstaw_za([H|T], X, Y, [H|T2]) :- wstaw_za(T,X,Y,T2).
% Zad 8
lewoprawo(X, [X|T], [], T).
lewoprawo(X, [H|T], [H|L], R) :- lewoprawo(X,T,L,R)
% Zad 9
wymiana(_, _, [], []).
wymiana(X, Y, [X|T], [Y|T2]) :- wymiana(X, Y, T, T2).
wymiana(X, Y, [H|T], [H|T2]) :- wymiana(X, Y, T, T2).
% Zad 10
polacz([], []).
polacz([H|T], L) :- polacz(T, LT), append(H, LT, L).
