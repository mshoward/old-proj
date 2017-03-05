isDigit(1).
isDigit(2).
isDigit(3).
isDigit(4).
isDigit(5).
isDigit(6).
isDigit(7).
isDigit(8).
isDigit(9).


numDig(X, [Y|Z], In, Out) :- X =:= Y, NextIn is In + 1, numDig(X, Z, NextIn, Out).
numDig(X, [Y|Z], In, Out) :- X =\= Y, numDig(X, Z, In, Out).
numDig(X, [], In, Out) :- Out is In.



hasOneOfEach([Y|Z]) :- 	length([Y|Z], 9),
						numDig(1, [Y|Z], 0, Ones), Ones =:= 1,
						numDig(2, [Y|Z], 0, Twos), Twos =:= 1,
						numDig(3, [Y|Z], 0, Threes), Threes =:= 1,
						numDig(4, [Y|Z], 0, Fours), Fours =:= 1,
						numDig(5, [Y|Z], 0, Fives), Fives =:= 1,
						numDig(6, [Y|Z], 0, Sixes), Sixes =:= 1,
						numDig(7, [Y|Z], 0, Sevens), Sevens =:= 1,
						numDig(8, [Y|Z], 0, Eights), Eights =:= 1,
						numDig(9, [Y|Z], 0, Nines), Nines =:= 1.

checkRows([[A|AA],[B|BB],[C|CC],[D|DD],[E|EE],[F|FF],[G|GG],[H|HH],[I|II]]) :-
	hasOneOfEach([A|AA]),
	hasOneOfEach([B|BB]),
	hasOneOfEach([C|CC]),
	hasOneOfEach([D|DD]),
	hasOneOfEach([E|EE]),
	hasOneOfEach([F|FF]),
	hasOneOfEach([G|GG]),
	hasOneOfEach([H|HH]),
	hasOneOfEach([I|II]).

checkCols([[A|AA],[B|BB],[C|CC],[D|DD],[E|EE],[F|FF],[G|GG],[H|HH],[I|II]]) :-
	hasOneOfEach([A,B,C,D,E,F,G,H,I]), checkCols([AA, BB, CC, DD, EE, FF, GG, HH, II]).
checkCols([[    ],[    ],[    ],[    ],[    ],[    ],[    ],[    ],[    ]]).

sudoku([[A|AA],[B|BB],[C|CC],[D|DD],[E|EE],[F|FF],[G|GG],[H|HH],[I|II]]) :-
	checkRows([[A|AA],[B|BB],[C|CC],[D|DD],[E|EE],[F|FF],[G|GG],[H|HH],[I|II]]),
	checkCols([[A|AA],[B|BB],[C|CC],[D|DD],[E|EE],[F|FF],[G|GG],[H|HH],[I|II]]).
sudoku([
[6,5,1,4,9,8,2,3,7],
[8,3,7,5,2,6,4,9,1],
[9,4,2,1,3,7,6,5,8],
[2,9,4,7,6,5,8,1,3],
[3,1,6,9,8,4,5,7,2],
[5,7,8,3,1,2,9,6,4],
[1,8,3,2,5,9,7,4,6],
[7,2,9,6,4,3,1,8,5],
[4,6,5,8,7,1,3,2,9]]).

add([X|Y], In, Out) :- NextIn is (In + 1), add(Y, NextIn, Out).
add([], In, Out) :- Out is In.
