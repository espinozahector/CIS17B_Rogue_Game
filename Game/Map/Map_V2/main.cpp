/* 
 * File:   main.cpp
 * Author: Victor Alcaraz & Hector Espinoza
 * Created on September 22, 2016, 10:01 PM
 * Purpose: Starter Map V1
 */

/*
 * Build Map with random room selection
 * room selection dictates where next room is placed
 * Current Version goes out of bounds. needs FIX!!! ("easy" -Hector)
 * 
 * Need to un-clump rooms? ("hard" -Hector)
 * -- rooms need to sometimes have space between rooms
 *      1 1 1 1 
 *      1 1 0 1 
 *      1 1 1 1
 * 
 * -->> needs to be more like this
 *      1 1 1 1 
 *      1 0 1 0
 *      1 1 0 0
 * 
 *      **1 = room
 *      **0 = space
 */
// System Libraries

// User Libraries
//#include "Row.h"  //Rows for building map
#include "Cols.h" //Cols for builing map

// Global Constants

// Function Prototypes

// Execution

int main(int argc, char** argv) {
    srand(static_cast<unsigned int> (time(0)));
        Cols base(9,9);

        for(int i = 0; i < base.getRows(); i++)
        {
            for(int j = 0; j < base.getCols(); j++)
            {
                if(base.getData(i,j)) cout << "1" << ' ';
                else cout << "0" << " ";
            }
            cout << endl;
        }
    return 0; // Exit
}

