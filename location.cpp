/* CSI 3334
 * Project 1 -- 2D Maze
 * Filename: location.cpp
 * Name: Eugene Pak
 * Version 2.2
 * Due: 2/2/24
 * This file contains implementation of the given location header file
 */
#include "location-proj1.h"

/* Location()
 * Default constructor for location class
 */
Location::Location(){
    row = col = 0;
    nextDirection = RIGHT;
}

/* iterationBegin()
 * This function begins the iteration of a location, setting all values to 0
 */
void Location::iterationBegin(){
    this->nextDirection = RIGHT;
    return;
}

/* iterationCurrent()
 * This function returns the neighbor of the current location
 *  parameters:
 *
 *  return value:
 *  location of next iteration neighbor
 *
 */
Location Location::iterationCurrent() const{
    Location that = *this;
    if (that.nextDirection == RIGHT){
        that.col++;
        that.nextDirection = RIGHT;
    }
    else if (that.nextDirection == DOWN){
        that.row++;
        that.nextDirection = RIGHT;
    }
    else if (that.nextDirection == LEFT){
        that.col--;
        that.nextDirection = RIGHT;
    }
    else if (that.nextDirection == UP){
        that.row--;
        that.nextDirection = RIGHT;
    }
    return that;
}

/* iterationAdvance()
 * This function iterates the location's next direction
 *  parameters:
 *
 *  return value:
 *
 */
void Location::iterationAdvance(){
    this->nextDirection++;
    return;
}

/* iterationDone()
 * This functions tells us if a location's iteration is done
 *  parameters:
 *
 *  return value:
 *  true if next direction is done
 *  false if next direction is not done
 */
bool Location::iterationDone() const{
    if (this->nextDirection == DONE){
        return true;
    }
    return false;
}

/* operator==()
 * This function tells us whether 2 locations are equal
 *  parameters:
 *  loc, location value used to compare with
 *
 *  return value:
 *  true if the row and column both match up
 *  false if either row or column are not the same
 */
bool Location::operator==(const Location &loc) const{
    if (this->row == loc.row){
        if (this->col == loc.col){
            return true;
        }
    }
    return false;
}

/* operator<<()
 * Allows for location object to be printed using standard out
 *  parameters:
 *  os, ostream which will store output data
 *  loc, location data that will be printed out
 *
 *  return value:
 *  ostream with the location's row and column separated with a space
 *  allows for simple and direct output to the standard out
 */
ostream &operator<<(ostream &os, const Location &loc){
    os << loc.row << " " << loc.col;
    return os;
}

/* operator>>()
 * Allows for location object to be received as an input using standard in
 *  parameters:
 *  is, istream which will take in and store data
 *  loc, location that will be inputted
 *
 *  return value:
 *  allows for simpler direct inputs from standard in
 */
istream &operator>>(istream &is, Location &loc){
    is >> loc.row >> loc. col;
    return is;
}
