# Rock, Paper, Scissors
A tiny implementation of rock, paper, scissors in ECS!

Link to Flecs: https://github.com/SanderMertens/flecs

## How to build
Just compile the sources. Make sure to compile `flecs.c` as C and `main.cpp` as
C++ code. The following commands will build the project with GCC:

```
gcc flecs.c -c -o flecs.o
g++ main.cpp flecs.o -o rock_paper_scissors
```

## How to play
```
$ ./rock_paper_scissors
rock, paper, scissors? paper
AI is scissors, you lose!
```

## player.has(beats, ai)?
Yes! The game uses ECS relations to store the who-beats-who graph. Just like components, relations are things that can be added to entities, and that can be queried for.

This is just showing the top of the tip of the iceberg of what relations can do, make sure to [check this out](https://flecs.docsforge.com/master/relations-manual/) if you'd like to know more!
