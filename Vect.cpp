#include <iostream>
#include <iomanip>
#include "Vect.h"



Vect::Vect()
    : vectArray{NULL}, vectSize{0}{}

Vect::Vect(int size)
    : vectArray{NULL}, vectSize{size}
{
    vectArray = (double*)malloc(size*sizeof(double));
    if(vectArray == NULL)
    {
        exit(EXIT_FAILURE);
    }
}

Vect::Vect(const Vect &source)
{
    vectSize = source.vectSize;
    for(int i =0;i < vectSize;i++)
    {
        vectArray[i] = source.vectArray[i];
    }
}

int Vect::getSize()
{
    return vectSize;
}

double Vect::getAverage()
{
    if(vectSize == 0)
    {
        return 0;
    }
    double sumOfAllElements = 0;
    for(int i = 0;i < vectSize;i++)
    {
        sumOfAllElements += vectArray[i];
    }
    return sumOfAllElements/vectSize;
}

double Vect::getMin()
{
    if(vectSize == 0)
    {
        return 0;
    }
    else if(vectSize == 1)
    {
        return vectArray[0];
    }
    double min = vectArray[0];
    for(int i = 1;i < vectSize;i++)
    {
        if(vectArray[i] < min)
        {
            min = vectArray[i];
        }
    }
    return min;
}
        
Vect Vect::concatenate(const Vect secondVect)
{
    Vect vectResult(vectSize + secondVect.vectSize);
    for(int i = 0;i < vectSize; i++)
    {
        vectResult.vectArray[i] = vectArray[i];
    }
    for(int j = 0;j < secondVect.vectSize; j++)
    {
        vectResult.vectArray[j+vectSize] = secondVect.vectArray[j];
    }
    return vectResult;
}


void Vect::setElement(int index, double element)
{
    if(index < 0 || index >= vectSize)
    {
        std::cout<<"Wrong index! - stopping program...";
        exit(EXIT_FAILURE);
    }
    vectArray[index] = element;
}

void Vect::print()
{
    std::cout<<"[";
    for(int i = 0; i < vectSize; i++)
    {
        std::cout<<vectArray[i];
        if(i != vectSize-1)
        {
            std::cout<<", ";
        }
    }
    std::cout<<"]";
}