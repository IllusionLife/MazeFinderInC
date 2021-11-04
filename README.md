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
Door - Acts as a wall until corresponding pressure plate is pressed. Coding on door corresponds to pressure plate with a value of (door + 100).
Door will remain unlocked for 20 turns after plate was pressed. If player is on door on the same turn, that the door gets locked again, he will not be able to cross it and will have to turn to previous position.
Pressure plate - Can unlock doors with corresponding number. It will unlock the corresponding door for 20 turns.

Restrictions:
1 <= playerX,playerY < 50
1 <= sizeX,sizeY < 50
0 <= doors <= 20
0 <= plate <= 20
One door = One plate (No door has more than one corresponding plate and vice versa)

EXAMPLE 1:
INPUT.TXT

2 2
8 6
-1 -1 -1 -1 -1 -1 -1 -1

-1  0  0  0  7  0  0  0

-1  0 -1 -1 -1 -1 -1 -1

-1  0 -1 -1 107-1 -1 -1

-1  0  0  0  0 -1 -1 -1

-1 -1 -1 -1 -1 -1 -1 -1


OUTPUT.TXT
20
