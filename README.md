#CMPUT 403 Project: Comparison of String Matching Algorithm
-
## Introduction:
This is an implementation of comparison of Boyer-Moore algorithm, Knuth–Morris–Pratt algorithm, and Brute Force (Naïve) algorithm, which are the three popular string matching algorithms.

String Matching:
Given a string X, to find its all positions in a given text Y.

## Running Times:
Length of **X (pattern) is m**, length of **Y (text) is n**.

Boyer-Moore algorithm: **O(n+m)** worest: **O(mn)**

Knuth–Morris–Pratt: **O(m+2*n)**

Brute Force (Naïve): **O(mn)**

## Test Steps:
Compile two execution files by use

```
$ make
```
followed by:

```
$ make clean
```
Then you will get two execution files, one is called `generate`, the other is called `string_test`.

### Generate Input File:

**Note: Please leave 1GB space for generating an input file**

use `generate`, you can use two modes for generating an input file with size of **1GB**, one is generating an input file with random characters, the other is an input file with repeat strings.

By default, you will get an input file with all random characters by running:

```
$ ./generate
```
or

```
$ ./generate 1
```
You will get a file like this:

```
7ykJAj (Q3P% iVTZ6((cxt5+ijV{eF.c2Rol0i$3?]%swh...
```

If you want to generate an input file with **random characters with your own string bases**, you can type:

```
$ ./generate 1 abcde
``` 
You will get a file like this:

```
bdbcaaaeecdbdacdceb...
``` 

If you want to generate a input file with **repeat string of "CMPUT403."**, you can type:

```
$ ./generate 2
```
You will get a file like this:

```
CMPUT403.CMPUT403.CMPUT403.CMPUT403. ...
```
or base on your own string:

```
$./generate 2 abcde
```
You will get a file like this:

```
abcdeabcdeabcdeabcdeabcde...
```

After this, you will get an input file called `test.in` which is almost 1GB.

### Test:
use `string_test`, you can test the three algorithms at the same time.

By default, it will set the first 100 characters from input file as the pattern to search, and you just need to type:

```
$ ./string_test
```
If you want to search a custom string you can enter the string as a parameter: **e.g. if you want to search "CMPUT Teacher", you can type:**

```
$ ./string_test CMPUT\ Teacher
```
### Test Result:
You may get a result like this:

```
-----------------------------
Test Start...
-----------------------------
Reading file costs: 8.80972s
-----------------------------
Search for first 100 characters in the input file
-----------------------------
Boyer-Moore Algorithm Found: 111111100
Boyer-Moore costs: 35.65747s
-----------------------------
KMP Algorithm Found: 111111100
KMP costs: 9.51662s
-----------------------------
BruteForce Algorithm Found: 111111100
BruteForce costs: 42.95952s
-----------------------------
```

## Reference:
https://github.com/zhuozhongcao/Boyer_Moore

https://www.cs.ubc.ca/~hoos/cpsc445/Handouts/kmp.pdf

http://www.personal.kent.edu/~rmuhamma/Algorithms/MyAlgorithms/StringMatch/boyerMoore.htm

http://programmers.stackexchange.com/questions/183725/which-string-search-algorithm-is-actually-the-fastest

http://www.stoimen.com/blog/2012/04/17/computer-algorithms-boyer-moore-string-search-and-matching/

http://www.cppblog.com/oosky/archive/2006/07/06/9486.html


