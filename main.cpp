/* CSI 3334
 * Project 1 -- 2D Maze
 * Filename: main.cpp
 * Name: Eugene Pak
 * Version 1.5
 * Due: 2/2/24
 * This project reads in valid coordinates for a maze and uses depth first search to
 * find a solution to the maze. If a solution is found, the path taken is printed out.
 */
#include <iostream>
#include <string>
#include <stack>
#include <cassert>
#include <sstream>

#include "location-proj1.h"
#include "maze-proj1.h"
#include "stack-proj1.h"

using namespace std;

/* main
 * This function reads in a maze object and traverses through valid locations,
 * iterating through until a solution is found or until all valid locations have
 * been visited and thus returns that no solution was found
 *  parameters:
 *      argc -- the number of arguments from the command line
 *      argv -- the command line argument values
 *  return value: 0 (indicating a successful run)
 *
 */
/*
int main(int argc, char **argv) {
    //get maze object in
    Maze maze;
    cin >> maze;

    //creation of variables used
    Location loc, move;
    LocationStack stack;
    loc = maze.getStartLocation();
    loc.iterationBegin();
    stack.push(loc);

    //loop implementation of maze iteration
    while (!stack.isEmpty() && !maze.isEndLocation(stack.getTop())){
        loc = stack.getTop();
        move = loc.iterationCurrent();
        if (maze.isValidLocation(move)){
            if (!stack.isOn(move)){
                loc.iterationAdvance();
                stack.pop();
                stack.push(loc);
                move.iterationBegin();
                stack.push(move);
            }
            else {
                if (!move.iterationDone()){
                    loc = stack.getTop();
                    stack.pop();
                    loc.iterationAdvance();
                    stack.push(loc);
                }
                else {
                    stack.pop();
                }
            }
        }
        else {
            if (!move.iterationDone()){
                loc = stack.getTop();
                stack.pop();
                loc.iterationAdvance();
                stack.push(loc);
            }
            else {
                stack.pop();
            }
        }
    }
    if (stack.isEmpty()){
        cout << "No solution" << endl;
    }
    else {
        cout << "Solution found" << endl;
        cout << stack;
    }
    return 0;
}
 */