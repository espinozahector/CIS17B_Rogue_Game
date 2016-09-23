/* 
 * File:   Cols.cpp
 * Author: Victor Alcaraz
 * Created on September 22, 2016, 10:42 PM
 * Purpose: 
 */

#include "Cols.h"

Cols::Cols() 
{
    szCols = 9;
    szRows = 9;
    map = new Row*[szRows];
    
    for(int i = 0; i < szCols; i++)
    {
        map[i] = new Row(szCols);
    }
}

Cols::Cols(int newRows, int newCols) 
{
    szRows = newRows;
    szCols = newCols;
    numRoom = 15;
    map = new Row*[szRows];
    
    for(int i = 0; i < szRows; i++)
    {
        map[i] = new Row(szCols);
    }
    this->setStrt(5,5);
    this->buildMap();
}
    
bool Cols::getData(int x, int y) 
{
    return map[x]->getEl(y);
}

Cols::~Cols()
{
    for(int i = 0; i < szRows; i++)
    {
        delete map[i];
    }
    delete map;
}

void Cols::setRoom(int x, int y)
{
    map[x]->setEl(y);
    RoomX.push_back(x);
    RoomY.push_back(y);
}

void Cols::setStrt(int x, int y)
{
    xStart = x;
    yStart = y;
    map[xStart - 1]->setEl(yStart - 1);
    RoomX.push_back(xStart - 1);
    RoomY.push_back(yStart - 1);
}

void Cols::buildMap() {
    int count = 0;
    int XorY = 0;
    int PosOrNeg = 0;
    int tempX;
    int tempY;
    int index;
    bool create;
    int times=0;
    
    do
    {
        times++;
        create = false;
        index = rand() % RoomX.size();
//        cout << "index: " << index << endl;
//        cout << "size: " << RoomX.size() << endl;
        
        tempX = RoomX[index];
        tempY = RoomY[index];
        
        XorY = (rand() % 2) + 1;
        PosOrNeg = (rand() % 2) + 1;
//        cout << "XorY " << XorY << endl;
//        cout << "PosOrNeg " << PosOrNeg << endl;
        
        if(XorY == 1) // Change x
        {
            if(PosOrNeg == 1)//up
            {
                ++tempX;
                for(int i = 0; i < RoomX.size(); i++)
                {
                    if(RoomX[i] == tempX && RoomY[i] == tempY) {
                        --tempX;
                        count--;
                        create = false;
                        break;
                    }
                    create = true;
                }
            }
            else if(PosOrNeg == 2) // down
            {
                --tempX;
                for(int i = 0; i < RoomX.size(); i++)
                {
                    if(RoomX[i] == tempX && RoomY[i] == tempY) {
                        --tempX;
                        count--;
                        create = false;
                        break;
                    }
                    create = true;
                }
            }
        }
        else if(XorY == 2) // change y
        {
            if(PosOrNeg == 1)//up
            {
                ++tempY;
                for(int i = 0; i < RoomY.size(); i++)
                {
                    if(RoomX[i] == tempX && RoomY[i] == tempY) {
                        --tempY;
                        count--;
                        create = false;
                        break;
                    }
                    create = true;
                }
            }
            else if(PosOrNeg == 2) // down
            {
                --tempY;
                for(int i = 0; i < RoomY.size(); i++)
                {
                    if(RoomX[i] == tempX && RoomY[i] == tempY) {
                        --tempY;
                        count--;
                        create = false;
                        break;
                    }
                    create = true;
                }
            }
        }
        if(create)
        {
            setRoom(tempX,tempY);
        }
        count++;
    }while(RoomX.size() != numRoom);
    cout << "times: " << times << endl;
}

/*
 void move_baddies(Player &p,vector<int>& Ex,vector<int>& Ey) {
	int which = 0;
	int dir=0;
	int last = 0;
	
	for(int i = 0; i < Ex.size();i++) 
	{
		which = (rand()%2)+1;
		dir = (rand()%2)+1;
		
		if(which == 1) // change x
		{	
			if(dir == 1)
			{
				// cout << Ex[i] << endl;
				Ex[i]++;
				// cout << Ex[i] << endl;
				for(int j=0;j<Ex.size();j++) 
				{
					if(i != j && Ex[i] == Ex[j] && Ey[i] == Ey[j]) 
					{
						Ex[i]--;
						break;
					}
				}
				if(Ex[i] > MAXX) Ex[i]--;
			}
			else if(dir == 2) 
			{
				Ex[i]--;
				for(int j=0;j<Ex.size();j++) 
				{
					if(i != j && Ex[i] == Ex[j] && Ey[i] == Ey[j]) 
					{
						Ex[i]++;
						break;
					}
				}
				if(Ex[i] < 1) Ex[i]++;
			} 
		}
                else if (which == 2) // or the y
		{
			if(dir == 1) // +
			{
				Ey[i]++;
				for(int j=0;j<Ey.size();j++) 
				{
					if(i != j && Ey[i] == Ey[j] && Ex[i] == Ex[j]) 
					{
						Ey[i]--;
						break;
					}
				}
				if(Ey[i] > MAXY) Ey[i]--;
			}
			else if(dir == 2) //-
			{
				Ey[i]--;
				for(int j=0;j<Ey.size();j++) 
				{
					if(i != j && Ey[i] == Ey[j] && Ex[i] == Ex[j]) 
					{
						Ey[i]++;
						break;
					}
				}
				if(Ey[i] < 1) Ey[i]++;
			} 
		}
	}
}
 
 */