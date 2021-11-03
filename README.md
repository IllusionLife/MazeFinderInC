# MazeFinderInC
A program that finds finds the exit of a maze.

This project was given from Code Academy during a study course. The point of this program is to take an input text file with the mentioned below information and return a file with the minimum steps required to get out of the maze (0 for no exit).

Input file format:
X Y <--Player coordinated
SizeX SizeY <-- Maze size
x * y entries <-- Maze structure

Legend:
-1      <-- Wall
 0      <-- Path
1-20    <-- Door 
101-120 <-- Pressure Plate

Rules:
Walls - Unable to cross under any curcumstances
Path - Can be freely crossed
Door - Acts as a wall until corresponding pressure plate is pressed. Coding on door corresponds to pressure plate with a value of (door + 100)

EXAMPLE 1:
INPUT.TXT

_**2 2
8 6
-1 -1 -1 -1 -1 -1 -1 -1
-1  0  0  0  7  0  0  0
-1  0 -1 -1 -1 -1 -1 -1
-1  0 -1 -1 107-1 -1 -1
-1  0  0  0  0 -1 -1 -1
-1 -1 -1 -1 -1 -1 -1 -1
**_

OUTPUT.TXT
20
