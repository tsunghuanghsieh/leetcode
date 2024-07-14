# Lyft variant

Given two different words of the same length and a dictionary's word list, find all shortest transformation sequences from the word1 to word2, such that:

1. Only 1 letter can be changed at a time (a transformation)
2. Each transformed word must exist in the word list. Note that first word is not a transformed word.

Output the answer as the number of shortest path results and the list of results.

For example, given our dictionary and the words `hit` and `cog`, you will output:
```
2
hit,hot,hog,cog
hit,hot,cot,cog
```

If there is no possible transformation, for example given our dictionary and the words `vault` and `crypt`, print only `0`.

The following describes the format of the input:
1. Number of pair of input words `N`
2. Followed by `2 * N` lines with `N` pair of words, each word on a separate line
3. Number of words in the dictionary `M`
4. Followed by `M` lines with a dictionary word on a separate line

Sample Input
```
2
hit
cog
vault
crypt
100
aah
aas
aba
abo
<... truncated for space ...>
zek
zep
zig
zip
zit
zoa
zoo
zuz
zzz
```

Sample Output
```
2
hit,hot,hog,cog
hit,hot,cot,cog
0
```