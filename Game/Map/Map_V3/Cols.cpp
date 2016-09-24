/* 
 * File:   Cols.cpp
 * Author: Victor Alcaraz & David Jenkins
 * Created on September 23, 2016, 11:00 PM
 * Purpose: 
 */

#include "Cols.h"
#include <map>
#define map std::map

Cols::Cols()
{
	szCols = 9;
	szRows = 9;
	level = new Row*[szRows];

	for (int i = 0; i < szCols; i++)
	{
		level[i] = new Row(szCols);
	}
}

Cols::Cols(int newCols, int newRows)
{
	szRows = newRows;
	szCols = newCols;
	numRoom = 10;
	level = new Row*[szRows];

	for (int i = 0; i < szRows; i++)
	{
		level[i] = new Row(szCols);
	}
	this->setStrt(5, 5);
	this->buildMap();
}

Cols::Cols(int newCols, int newRows, int numRooms) //Constructor that lets you set the number of rooms when object created
{
	szRows = newRows;
	szCols = newCols;
	numRoom = numRooms;
	level = new Row*[szRows];

	for (int i = 0; i < szRows; i++)
	{
		level[i] = new Row(szCols);
	}
	this->setStrt(newRows /2, newCols /2);  //Starts in roughly the middle of map regardless of how big the map is.
	this->buildMap();
}

bool Cols::getData(int x, int y)
{
	return level[x]->getEl(y);
}

Cols::~Cols()
{
	for (int i = 0; i < szRows; i++)
	{
		delete level[i];
	}
	delete[] level;
}

void Cols::setRoom(int x, int y)
{
	level[x]->setEl(y);
	RoomX.push_back(x);
	RoomY.push_back(y);
}

void Cols::setStrt(int x, int y)
{
	xStart = x;
	yStart = y;
	level[xStart - 1]->setEl(yStart - 1);
	RoomX.push_back(xStart - 1);
	RoomY.push_back(yStart - 1);
}

void Cols::buildMap() {
	int XorY = 0;
	int PosOrNeg = 0;
	int tempX;
	int tempY;
	int index;
	bool create;
	int times = 0;            // test of number of calculations
	float crtPcnt = 0.25f;   // Create Percentage
	map <char, bool> roomChck;
	roomChck['N'] = false;
	roomChck['S'] = false;
	roomChck['W'] = false;
	roomChck['E'] = false;
	int roomCnt = 0;
	//


	/*
	* (RoomX, RoomY)
	*
	* (RoomX - 1, RoomY), (RoomX + 1, RoomY),
	* (RoomX, RoomY - 1), (RoomX, RoomY + 1)
	* if(at least 2 of those is true, than run again)
	* if any of those are true, the chance of building
	*      (RoomX, RoomY) is lower
	*/


	do
	{
		times++;
		create = false;
		index = rand() % RoomX.size();
		//        cout << "index: " << index << endl;
		//        cout << "size: " << RoomX.size() << endl;

		tempX = RoomX[index];
		tempY = RoomY[index];

		if (level[tempY - 1]->getEl(tempY))
			roomChck['N'] = true;
		if (level[tempY + 1]->getEl(tempY))
			roomChck['S'] = true;
		if (level[tempX]->getEl(tempX - 1))
			roomChck['W'] = true;
		if (level[tempX]->getEl(tempX + 1))
			roomChck['E'] = true;

		for (pair<char, bool> direction : roomChck)
		{
			if (direction.second == true) roomCnt++;
		}


		if (roomCnt >= 4)
		{
			create = false;
		}
		else if (roomCnt = 3)
		{
			int pTemp = rand() % 100 + 1;
			if (pTemp <= crtPcnt * 100) create = true;
			else create = false;
		}
		else if (roomCnt = 2)
		{
			int pTemp = rand() % 100 + 1;
			if (pTemp <= crtPcnt * 200) create = true;
			else create = false;
		}
		else
			create = true;

		if (create)
		{
			create = false;
			XorY = (rand() % 2) + 1;
			PosOrNeg = (rand() % 2) + 1;
			//            cout << "XorY " << XorY << endl;
			//            cout << "PosOrNeg " << PosOrNeg << endl;

			if (XorY == 1) // Change x
			{
				if (PosOrNeg == 1)//up
				{
					++tempX;
					for (int i = 0; i < RoomX.size(); i++)
					{
						if (RoomX[i] == tempX && RoomY[i] == tempY) {
							--tempX;
							create = false;
							break;
						}
						create = true;
					}
					if (tempX >= szRows)
					{
						tempX--;
						create = false;
					}
				}
				else if (PosOrNeg == 2) // down
				{
					--tempX;
					for (int i = 0; i < RoomX.size(); i++)
					{
						if (RoomX[i] == tempX && RoomY[i] == tempY) {
							--tempX;
							create = false;
							break;
						}
						create = true;
					}
					if (tempX < 0)
					{
						tempX++;
						create = false;
					}
				}
			}
			else if (XorY == 2) // change y
			{
				if (PosOrNeg == 1)//up
				{
					++tempY;
					for (int i = 0; i < RoomY.size(); i++)
					{
						if (RoomX[i] == tempX && RoomY[i] == tempY) {
							--tempY;
							create = false;
							break;
						}
						create = true;
					}
					if (tempY >= szCols)
					{
						tempY--;
						create = false;
					}
				}
				else if (PosOrNeg == 2) // down
				{
					--tempY;
					for (int i = 0; i < RoomY.size(); i++)
					{
						if (RoomX[i] == tempX && RoomY[i] == tempY) {
							--tempY;
							create = false;
							break;
						}
						create = true;
					}
					if (tempY < 0)
					{
						tempY++;
						create = false;
					}
				}
			}
		}

		if (create)
		{
			setRoom(tempX, tempY);
		}

		//Reset roomChcks at the end of loops

		roomChck['N'] = false;
		roomChck['S'] = false;
		roomChck['W'] = false;
		roomChck['E'] = false;
		roomCnt = 0;

	} while (RoomX.size() != numRoom);
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