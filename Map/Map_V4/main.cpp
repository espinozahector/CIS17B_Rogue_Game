/* 
 * File:   main.cpp
 * Author: Victor Alcaraz, Hector Espinoza & David Jenkins
 * Created on September 24, 2016, 10:01 PM
 * Purpose: Starter Map V2 V-Hector
 */

/*  NOTES:
 *      - We are still having a rare build error. Be warned.
 *      Might have to do with the level builder's random generator
 *      Working on a fix to possibly build using 3's instead of 1 at a time
 *      - In Room.cpp, deallocation needs to be fixed.
 */

// System Libraries

// User Libraries
//#include "Row.h"  //Rows for building map
#include "Room.h"

// Global Constants

// Function Prototypes



// Execution
int main(int argc, char** argv) {
    srand(static_cast<unsigned int> (time(0)));
    Room base(9,9,7,13);

    for(int i = 0; i < base.getRows(); i++)
    {
        for(int j = 0; j < base.getCols(); j++)
        {
            if(base.getData(i,j)) cout << "1" << ' ';
            else cout << "0" << " ";
        }
        cout << endl;
    }
    cout << endl;
    
    //which room do you want to see?
    //user input -> 4,5
    //output -> room at location from level
    
//    base.findEnd();
    return 0; // Exit
}

