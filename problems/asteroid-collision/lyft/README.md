# Lyft variant

Assume you are in a space station close to an asteroid belt. In this particular asteroid belt there are N asteroids of varying sizes (no two asteroids have the same size). All of the asteroids move at the same speed, but their direction is either towards you or away from you.

**Collision Rules**
Leetcode question uses variant 1. Choose one of the variants below to ask:
1. **No Mass Loss**: When two asteroids collide, the larger asteroid completely destroys the smaller asteroid and continue moving in the same direction.
2. **Mass Loss**: When two asteroids collide, the larger asteroid completely destroys the smaller asteroid and continue moving in the same direction. The mass of the smaller asteroid is removed from the larger asteroid.

Your task is to write a function to find the number of asteroids that will hit your space station. Your function will be gievn a list of Asteroid objects with `.mass` and `.direction` properties. `.mass` will be between `1` and `Integer.MAX_VALUE`. Direction will be -1 for leftwards (away from you) or +1 rightwards (towards you). The position in the list represents the asteroid's position in space and your space station's position is past the end of the list, as illustrated below:

```
              .   0   O   o    #=# <- space station
             ->  <-  ->  <-
mass          1   5   7   3
direction     1  -1   1  -1
```

**Inputs**
```
asteroids: a list of Asteroids objects
```

**Output**
The number of asteroids that hit you.


**No Mass Loss**
```
              .   0   O   o    #=# <- space station
             ->  <-  ->  <-
mass          1   5   7   3
direction     1  -1   1  -1
answer: 1

              .   o   0   O    #=# <- space station
             ->  ->  ->  <-
mass          1   3   5   7
direction     1   1   1  -1
answer: 0

              0   .   o     #=# <- space station
             ->  ->  ->
mass          5   1   4
direction     1   1  -1
answer: 1

              .   0   o    #=# <- space station
             ->  ->  <-
mass          1   5   4
direction     1   1  -1
answer: 2
```

**Mass Loss**
```
              .   0   O   o    #=# <- space station
             ->  <-  ->  <-
mass          1   5   7   3
direction     1  -1   1  -1
answer: 1

              .   o   0   O    #=# <- space station
             ->  ->  ->  <-
mass          1   3   5   7
direction     1   1   1  -1
answer: 2

              0   .   o     #=# <- space station
             ->  ->  ->
mass          5   1   4
direction     1   1  -1
answer: 1

              .   0   o    #=# <- space station
             ->  ->  <-
mass          1   5   4
direction     1   1  -1
answer: 2

              0   .   o   0   O    #=# <- space station
             ->  ->  ->  ->  <-
mass          5   1   3   5  10
direction     1   1   1   1  -1
answer: 1
```