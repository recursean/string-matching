# String Matching Algorithms
Compare implementations of string matching algorithms in C. 

## Overview
`algorithm_comparison.c` is the main driver module. It is responsible for:
- Defining dictionary of valid words that will be suggested
- Defining words that will be tested as input
- Testing each string matching algorithm

## Algorithms
- [Levenshtein Distance](https://en.wikipedia.org/wiki/Levenshtein_distance)
- [Damerau-Levenshtein Distance](https://en.wikipedia.org/wiki/Damerau%E2%80%93Levenshtein_distance)

## Build
To build this project, run `make` from the root directory

## Run
To run this project, run `./match` from the root directory after building the code. 

## Sample Output
```
*** Levenshtein Distance *** 
Source:              bat    Suggest:      cat
Source:             lard    Suggest:     bird
Source:             hogg    Suggest:      dog

Average Execution Time: 0.000002


*** Damerau-Levenshtein Distance *** 
Source:              bat    Suggest:      cat
Source:             lard    Suggest:     bird
Source:             hogg    Suggest:      dog

Average Execution Time: 0.000001
```