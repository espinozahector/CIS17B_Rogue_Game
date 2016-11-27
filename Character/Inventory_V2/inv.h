#ifndef INV_H
#define INV_H


class Inv
{
    private:
        int iCap;       //Inventory capacity
        int iSize;      //Inventory size
        Item *stock;    //Inventory stock

        void fill();    //Fills stock

    public:
        //Constructors
        Inv();
        //Param(Size)
        Inv(int);
        //Param(Item array)
        Inv(Item&);
        ~Inv();

        //Inv capacity get/set
        void setCap(int);
        int getCap();

        //Inv size get/set
        void setSize(int);
        int getSize();

        //Inventory
        void addItem(Item); //Add item
        Item getItem(int);  //return item


};


#endif // INV_H
