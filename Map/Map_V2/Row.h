/* 
 * File:   Map.h
 * Author: Victor Alcaraz
 * Created on September 22, 2016, 10:02 PM
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
    int rows;
    bool *table;
public:
    Row();
    Row(int);
    ~Row();
    int getRows() {return rows;}
    void setRows(int newRows) {rows = newRows;}
    bool getEl(int y) {return table[y];}
    void setEl(int);
};

#endif /* ROW_H */

