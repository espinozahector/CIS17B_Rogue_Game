/* 
 * File:   Row.h
 * Author: Hector and victor
 * Created on September 24, 2016
 * Purpose: Base Row of map
 */

#ifndef ROW_H
#define ROW_H

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
using namespace std;

class Row
{
private:
    int cols;    // number of columns (array size)
    bool *table; // single dimension array of 0's
public:
    Row();       //Default constructor
    Row(int);    //Constructor with columns parameter
    ~Row();      //Destructor
    int getRows() {return cols;} //Get size of rows
    void setRows(int newRows) {cols = newRows;} // Sets the size of rows
    bool getEl(int y) {return table[y];} // Gets elements in row location
    void setEl(int); // sets the element in the row to true
    void setEl(int,int);
};

#endif /* ROW_H */


