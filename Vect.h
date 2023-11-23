#include <iostream>
#include <iomanip>
#include <cmath>

#pragma once

class Vect
{
    private:
        double* vectArray;
        int vectSize;
    public:
        Vect();
        Vect(int size);

        Vect(const Vect &source);

        int getSize();
        double getAverage();
        double getMin();
        
        Vect concatenate(Vect secondVect);
        void setElement(int index, double element);
        void print();
};