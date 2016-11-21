/*
 * File:   Map.cpp
 * Author: Victor Alcaraz
 * Created on September 25, 2016, 12:08 PM
 * Purpose:
 */

#include "Level.h"

Level::Level() : Cols() //Default Constructor
{
    numRoom = 10;
}
Level::Level(int newRow, int newCols) : Cols(newRow,newCols) //Constructor with two parameters
{
    numRoom = 10;

    setStrt(5,5); // sets the start of the map
    bldLevel();   // Build map function


}

Level::~Level() // destructor
{

}
void Level::setRoom(int x, int y) // Sets room to true
{
    level[x]->setEl(y); // sets the bool array location to true
    RoomX.push_back(x); // adds the x location of the start to the vector
    RoomY.push_back(y); // adds the y location of the start to the vector
}

void Level::setStrt(int x, int y) // Sets the start of the level
{
    xStart = x;
    yStart = y;
    level[xStart - 1]->setEl(yStart - 1);
    RoomX.push_back(xStart - 1);
    RoomY.push_back(yStart - 1);
}

void Level::printmap()
{
    for(int i = 0;i<getSzRows();i++)
    {
        for(int j = 0; j < getSzCols();j++)
        {
            cout << level[i]->getEl(j) << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void Level::bldLevel()   // Builds the level / room locations
{
    int XorY = 0;           // move in the x directon by 1 or the y direction by 1
    int PosOrNeg = 0;       // moves the x or y coord by 1
    int tempX;              // temp x to grab a random room to branch off of
    int tempY;              // temp x to grab a random room to branch off of
    int index;              // index to grab a random room
    bool create;            // decides to create a room or not
    int times=0;            // test of number of calculations
    float crtPcnt = 0.15f;  // Create Percentage
    int roomCnt;            // counts the surrounding rooms

    do
    {
        times++;
        create = false;
        index = rand() % RoomX.size();
        roomCnt = 0;

        tempX = RoomX[index];
        tempY = RoomY[index];

        if(tempY - 1 >= 0)
        {
            if (level[tempY - 1]->getEl(tempY))     // check room above
            {
                roomCnt++;
            }
        }
        if(tempY + 1 < getSzCols())
        {
            if (level[tempY + 1]->getEl(tempY))     // check room below
            {
                roomCnt++;
            }
        }
        if(tempX - 1 >= 0)
        {
            if (level[tempX]->getEl(tempX - 1))     // check room left
            {
                roomCnt++;
            }
        }
        if(tempX + 1 < getSzRows())
        {
            if (level[tempX]->getEl(tempX + 1))     // check room right
            {
                roomCnt++;
            }
        }

        if (roomCnt >= 4)   //if there are 4 surrounding rooms do not create room
        {
                create = false;
        }
        else if (roomCnt == 3) //if there are 3 surrounding rooms, chances of creating are lower
        {
                float pTemp = rand();
                if (pTemp <= crtPcnt) create = true; // * 90 is safe
                else create = false;
        }
        else if (roomCnt == 2) //if there are 2 surrounding rooms, chances are normal
        {
                float pTemp = rand();
                if (pTemp <= crtPcnt * 4) create = true; // * 125 is safe
                else create = false;
        }
        else                 //if there are no surrounding rooms, than build room
                create = true;


        if(create)
        {
            create = false;
            XorY = (rand() % 2) + 1;
            PosOrNeg = (rand() % 2) + 1;
//            cout << "XorY " << XorY << endl;
//            cout << "PosOrNeg " << PosOrNeg << endl;

            //can be more efficient
            if(XorY == 1) // Change x
            {
                if(PosOrNeg == 1)//right
                {
                    ++tempX;
                    for(unsigned int i = 0; i < RoomX.size(); i++)
                    {
                        if(RoomX[i] == tempX && RoomY[i] == tempY) //checks to make sure new location doesnt build on an already built room
                        {
                            --tempX;
                            create = false;
                            break;
                        }
                        create = true;
                    }
                    if(tempX >= getSzRows()) //checks to make sure the movement is within bounds
                    {
                       tempX--;
                       create = false;
                    }
                }
                else if(PosOrNeg == 2) // left
                {
                    --tempX;
                    for(unsigned int i = 0; i < RoomX.size(); i++)
                    {
                        if(RoomX[i] == tempX && RoomY[i] == tempY) //checks to make sure new location doesnt build on an already built room
                        {
                            --tempX;
                            create = false;
                            break;
                        }
                        create = true;
                    }
                    if(tempX < 0)//checks to make sure the movement is within bounds
                    {
                       tempX++;
                       create = false;
                    }
                }
            }
            else if(XorY == 2) // change y
            {
                if(PosOrNeg == 1)//down
                {
                    ++tempY;
                    for(unsigned int i = 0; i < RoomY.size(); i++)
                    {
                        if(RoomX[i] == tempX && RoomY[i] == tempY) //checks to make sure new location doesnt build on an already built room
                        {
                            --tempY;
                            create = false;
                            break;
                        }
                        create = true;
                    }
                    if(tempY >= getSzCols())//checks to make sure the movement is within bounds
                    {
                       tempY--;
                       create = false;
                    }
                }
                else if(PosOrNeg == 2) // up
                {
                    --tempY;
                    for(unsigned int i = 0; i < RoomY.size(); i++)
                    {
                        if(RoomX[i] == tempX && RoomY[i] == tempY) //checks to make sure new location doesnt build on an already built room
                        {
                            --tempY;
                            create = false;
                            break;
                        }
                        create = true;
                    }
                    if(tempY < 0)//checks to make sure the movement is within bounds
                    {
                       tempY++;
                       create = false;
                    }
                }
            }
        }

        if(create)
        {
            setRoom(tempX,tempY); //adds the x and y location of the new room
        }
    }while(RoomX.size() != numRoom); //loops until there are numRoom elements in the array


    for(unsigned int i = 0; i < RoomX.size(); i++)
    {
        cout << RoomX[i] << ',' << RoomY[i] << endl;
    }
    cout << endl;
    cout << "times: " << times << endl;
}

void Level::findEnd() //used to find the farthest location from the center
{
    int temp = 0;
    int length = 0;

    int tempX = 0;
    int tempY = 0;
    int a=0,b=0;
    for(unsigned int i = 0; i < numRoom; i++) //Distance Formula
    {
        a = getXStrt() - RoomX[i];
        a *= a;
        b = getXStrt() - RoomY[i];
        b *= b;
        temp = sqrt(a + b);
        if(temp >= length)
        {
            length = temp;
            temp = 0;
            tempX = RoomX[i];
            tempY = RoomY[i];
        }
    }
    cout << "length:" << length << endl;
    cout << "coordinate: " << tempX << " " << tempY << endl;
}
