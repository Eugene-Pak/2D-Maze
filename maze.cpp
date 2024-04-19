/* CSI 3334
 * Project 1 -- 2D Maze
 * Filename: maze.cpp
 * Name: Eugene Pak
 * Version 1.4
 * Due: 2/2/24
 * This file contains implementation of the given maze header file
 */
#include "maze-proj1.h"

/* Maze()
 * Default constructor for maze object
 * Iterates all valid locations
 *
 */
Maze::Maze(void){
    this->startLocation.iterationBegin();
    this->endLocation.iterationBegin();

    this->validLocationCount = 0;
    this->validLocations = new Location[this->validLocationCount];
}

/* ~Maze()
 * Destructor for maze object, deletes valid locations list
 */
Maze::~Maze(){
    delete [] this->validLocations;
}

/* getStartLocation()
 * Returns the starting location of the maze
 *  parameters:
 *
 *  return value:
 *  maze starting location, allows quick initialization of a starting location
 */
Location Maze::getStartLocation(void) const{
    return this->startLocation;
}

/* isValidLocation()
 *  Checks if a given location is a valid location
 *  parameters:
 *  loc, location value that will be checked
 *
 *  return value:
 *  true if given location is on the valid locations array
 *  false if given location is not on the valid locations array
 */
bool Maze::isValidLocation(const Location &loc) const{
    for (int i = 0; i < this->validLocationCount; i++){
        if (loc == this->validLocations[i]){
            return true;
        }
    }
    return false;
}

/* isEndLocation()
 * Checks if the end is reached
 *  parameters:
 *  loc, location value being checked
 *
 *  return value:
 *  true if location given is on end location
 *  false if location given is not on end location
 */
bool Maze::isEndLocation(const Location &loc) const{
    if (loc == this->endLocation){
        return true;
    }
    return false;
}

/* operator>>()
 *  Allows a maze object to be inputted through the standard in
 *  parameters:
 *  is, istream which will take in data
 *  m, maze object which will store and utilize data
 *
 *  return value:
 *  allows for a simple and direct way to enter information for a maze to standard in
 */
const int MAX = 10000;
istream &operator>>(istream &is, Maze &m){
    is >> m.validLocationCount;
    if (m.validLocationCount <= MAX && m.validLocationCount >= 1){
        delete [] m.validLocations;
        m.validLocations = new Location[m.validLocationCount];
        for (int i = 0; i < m.validLocationCount; i++){
            is >> m.validLocations[i];
        }
        is >> m.startLocation >> m.endLocation;
    }
    return is;
}