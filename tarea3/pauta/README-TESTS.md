# README
## Test framework

We use `bats`
(package of that name on Fedora,
 [upstream](https://github.com/sstephenson/bats))
to run tests and report in [TAP](https://testanything.org) format.

## Problem 1

### `test-args`

Checks argument handling
(not really required,
 but I like to cover all bases).

### `test-1`

Checks several expressions
against the `match.c` source (as edited)
and `testdata`.

### `test-2`

Checks several expressions
against the `match.c` source (as edited)
and `testdata`.
Adds `matchplus()`.

### `test-3`

Checks several expressions
against the `match.c` source (as edited)
and `testdata`.
Adds `matchques()`.
