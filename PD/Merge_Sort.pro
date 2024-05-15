% £¹czenie posortowanych list wejœciowych L1 i L2. (mergowanie listy L1
% z L2)
merge([], L, L) :- !. % Jeœli pierwsza lista jest pusta, to wynikiem jest lista druga.
merge(L, [], L) :- !. % Analogicznie z drug¹ list¹.
merge([X|T1], [Y|T2], [X|T3]) :-
	X<Y, !, % Jeœli pierwszy element pierwszej listy jest mniejszy ni¿ pierwszy element drugiej listy...
	merge(T1, [Y|T2], T3). % ...to dodaj ten element do wyniku i rekurencyjnie ³¹cz resztê listy.
merge(L1, [Y|T2], [Y|T3]) :- % W przeciwnym wypadku dodaj pierwszy element drugiej listy do wyniku i rekurencyjnie ³¹cz pozosta³oœci obu list.
        merge(L1,T2,T3).

% Najlepiej zrobiæ rozdzielanie list (tak jak to dzia³a w merge sorcie)
split([], [], []). % Jeœli wejœciowa lista jest pusta, to obie listy musz¹ byæ puste.
split([], [X], [X]).
split([H1|L1], [H2|L2], [H1,H2|L]) :-
	split(L1, L2, L). % Jeœli lista zawiera co najmniej dwa elementy, pierwszy element jest dodawany do pierwszej listy wyjœciowej, drugi element do drugiej listy wyjœciowej, a reszta listy jest dzielona rekurencyjnie.



% A tutaj implementacja merge sort'a :-]
merge_sort([],[]). % Jeœli lista wejœciowa jest pusta, to lista wynikowa jest tak¿e pusta.
merge_sort([X],[X]).
merge_sort(L,S) :-
	split(L1,L2,L),
	merge_sort(L1,S1),
	merge_sort(L2,S2),
	merge(S1,S2,S).






















