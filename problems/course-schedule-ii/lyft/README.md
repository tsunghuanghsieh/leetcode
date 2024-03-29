# Lyft variant

Given the input of map that represents directed graphs. Find the linearization where nodes are ordered in ascending order.

**Example 1**:
```
2 -----> 7
   \     |
    \    v
     >   5 -> 3

1 -> 4 -> 6
```

Valid linearizations:
```
2,7,5,3,1,4,6
2,1,4,6,7,5,3
1,4,6,2,7,5,3
1,4,2,7,5,3,6
1,2,4,6,7,5,3
...
```

**Input**
```
[
    1: [4],
    2: [5,7],
    3: [],
    4: [6],
    5: [3],
    6: [],
    7: [5],
]
```

**Output:**
```
1,2,4,6,7,5,3
```

**Example 2**:
```
2 -----> 7
   \     |
    \    v
     >   5 -> 3

1 -> 4 -> 6
     ^
    /
9 -/
```

**Input**
```
[
    1: [4],
    2: [5,7],
    3: [],
    4: [6],
    5: [3],
    6: [],
    7: [5],
    9: [4]
]
```

**Output:**
```
1,2,7,5,3,9,4,6
```