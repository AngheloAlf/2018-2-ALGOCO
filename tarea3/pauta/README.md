# README

Solutions to homework 3 of "Algoritmos y Complejidad" (INF-221),
second semester 2018.

## Problem 1

Added `master.h` with declaration of `match()`.
Added `#include "match.h"` and declarations to `match.c`.

Main program in `main.c` checks arguments,
opens the file for reading.	
If this fails,
it gives a diagnostic to `stderr`.

It reads the file line by line,
replaces the ending `'\n'` with `'\0'` as this is the ending expected,
and runs the match on the line.
If it matches,
the line is printed out.

Files `main.c`, `match.h`, `match.c`, executable `20182t3p1`;
bats tests in `test-1`.

## Problem 2

Remember that 'c+regexp' is really 'cc*regexp'.
We add a new function `matchplus()` that checks if the first character matches,
if it does we check if 'c*regexp' matches the rest of the text.

Files `match-2.c`, executable `20182t3p2`;
bats tests in `test-2`.

## Problem 3

We add a new function `matchques()` that checks if the first character matches;
if it does we check if 'regexp' matches the rest of the text,
if this last match fails,
we try matching 'rexgexp' against the full text.

Files `match-3.c`, executable `20182t3p3`;
bats tests in `test-3`.

## Problem 4

First, we integrate the changes for problems 2 and 3.

Files `match-4.c`, executable `20182t3p4`;
bats tests in `test-4` confirm the integration didn't break anything.

Next we have do decide how to go forward.

* **Quick and dirty:**
  It is seen that Pike's code
  mostly only checks the _second_ character of the regexp for special meaning.
  If it starts with e.g.`'*'`,
  it gets no special treatment,
  and `'\'` currently has no special meaning.
  Thus one way to handle `'\'` is to just skip over it.
  Need to be careful with `'^'`, `'$'`, 
  which don't operate on the previous character,
  and specially `'.'`,
  whose special meaning is considered in several places.
  This leads to a rat's hole of logic.

* **Clean, extensible:**
  The other option is to compile the given regular expression
  into an internal form that can be matched with almost the same logic,
  representing the metacharacters by special operators.
  Each position is stored in a `short int`,
  containing the plain `char` value or a code giving the operation.
  
