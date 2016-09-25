#ifndef INV_H
#define INV_H

//Equipped inventory structure
template<class T>
struct Inv{
    T max; //Maximum capacity
    T size; //Number of items
    T *stock; //Pointer of items
};

#endif // INV_H
