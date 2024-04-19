/* CSI 3334
 * Project 1 -- 2D Maze
 * Filename: stack.cpp
 * Name: Eugene Pak
 * Version 1.5
 * Due: 2/2/24
 * This file contains implementation of the given stack header file
 */
#include "stack-proj1.h"

/* LocationStackNode()
 * Copy constructor of LocationStackNode class
 *  parameters:
 *  loc, location to be stored in node
 *  next, pointer either pointing to null if no input, or to another node
 */
LocationStackNode::LocationStackNode(const Location &loc, LocationStackNode *next){
    this->location = loc;
    this->nextNode = next;
}

/* ~LocationStackNode()
 * Destructor for LocationStackNode
 *  Deletes the next node object
 *  Works in tandem with the location stack destructor
 */
LocationStackNode::~LocationStackNode(){
    delete this->nextNode;
}

/* getLocation()
 * Gets location information of a node
 *  parameters:
 *
 *  return value:
 *  the current node's location value
 */
const Location& LocationStackNode::getLocation() const{
    return this->location;
}

/* getNextNode()
 * Gets the address of the next node
 *  parameters:
 *
 *  return value:
 *  gets the value contained in the current location node's next pointer
 */
LocationStackNode* LocationStackNode::getNextNode() const{
    return this->nextNode;
}

/* setNextNode()
 * Sets the address of the current node's next pointer
 *  parameters:
 *  next, pointer pointing at the next node of the current node
 *
 *  return value:
 *
 */
void LocationStackNode::setNextNode(LocationStackNode *next){
    this->nextNode = next;
    return;
}


/* LocationStack()
 * Default constructor for location stack
 */
LocationStack::LocationStack(void){
    this->top = nullptr;
}

/* ~LocationStack()
 * Destructor for LocationStack
 *  Deletes the top node
 *  Works in tandem with the location stack node destructor
 */
LocationStack::~LocationStack(){
    if (this->top != nullptr){
        delete this->top;
    }
}

/* push()
 * Enters a location node to the top of the stack
 *  parameters:
 *  loc, location value to be entered into stack
 *
 *  return value:
 *
 */
void LocationStack::push(const Location &loc){
    if (this->top != nullptr){
        LocationStackNode *temp = new LocationStackNode(loc);
        temp->setNextNode(this->top);
        this->top = temp;
    }
    else {
        this->top = new LocationStackNode(loc);
    }
    return;
}

/* pop()
 * Removes the location at the top of the stack
 *  parameters:
 *
 *  return value:
 *
 */
void LocationStack::pop(void){
    assert(this->top != nullptr);
    LocationStackNode *temp = this->top->getNextNode();
    this->top->setNextNode(nullptr);
    delete this->top;
    this->top = temp;
    return;
}

/* getTop()
 * Shows the location value at the top of the stack
 *  parameters:
 *
 *  return value:
 *  if stack is not empty, returns last entered location value of stack
 */
const Location& LocationStack::getTop(void) const{
    assert(this->top != nullptr);
    return this->top->getLocation();
}

/* isEmpty()
 * Checks if a location stack is empty
 *  parameters:
 *
 *  return value:
 *  true if the top node is a null pointer
 *  false if the top node points to a valid address
 */
bool LocationStack::isEmpty(void) const{
    if (this->top == nullptr){
        return true;
    }
    return false;
}

/* isOn()
 * Checks if a location is already on the stack
 *  parameters:
 *  loc, a location data that gets checked to see if it is on the stack
 *
 *  return value:
 *  true if given location is on the stack
 *  false if given location is not on the stack
 */
bool LocationStack::isOn(const Location &loc) const{
    if (this->top != nullptr){
        LocationStackNode* temp = this->top->getNextNode();
        if (this->top->getLocation() == loc){
            return true;
        }
        while (temp != nullptr){
            if (temp->getLocation() == loc){
                return true;
            }
            temp = temp->getNextNode();
        }
    }
    return false;
}

/* operator<<()
 * Allows stack item to be printed through standard out
 *  parameters:
 *  os, output stream being sued to store print information
 *  s, location stack containing all valid locations visited to reach solution
 *
 *  return value:
 *  ostream with all the location values of the stack
 *  Allows for direct and simple output of a location stack through standard out
 */
ostream &operator<<(ostream &os, const LocationStack &s){
    assert(!s.isEmpty());
    LocationStackNode* temp1 = s.top->getNextNode();
    if (temp1 != nullptr){
        LocationStackNode* temp2 = temp1->getNextNode();
        temp1->setNextNode(s.top);
        s.top->setNextNode(nullptr);
        if (temp2 != nullptr){
            LocationStackNode* temp3 = temp2->getNextNode();
            while(temp3 != nullptr){
                temp2->setNextNode(temp1);
                temp1 = temp2;
                temp2 = temp3;
                temp3 = temp3->getNextNode();
            }
            temp2->setNextNode(temp1);
            while (temp1 != nullptr){
                os << temp2->getLocation() << endl;
                temp2->setNextNode(temp3);
                temp3 = temp2;
                temp2 = temp1;
                temp1 = temp1->getNextNode();
            }
            s.top->setNextNode(temp3);
            os << s.getTop() << endl;
        }
        else {
            os << temp1->getLocation() << endl;
            temp1->setNextNode(nullptr);
            s.top->setNextNode(temp1);
            os << s.getTop() << endl;
        }
    }
    else {
        os << s.getTop() << endl;
    }
    return os;
}