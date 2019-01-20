# maze

## Description

A sample program to find a way from a start point to a goal point in a maze. The logic is based on reinforcement learning with epsilon-greedy and Q-learning. This program comes from a sample C program in a Japanese book "Imprimenting Reinforcement Learning - Robot Programming with C Language" (ISBN978-4-274-22287-0), modified to C++.

## Installatiion

In a directory, type following commands.

```
git clone https://github.com/attosci/maze.git
mkdir -p maze/build
cd maze/build
cmake ../src
make
```

## Play with the program

Execute the following commands.

```
maze
```

Then, you see the results during finding a way from a start point to the goal on a screen.

You can change the structure of the maze by editing `Maze.cpp`.

