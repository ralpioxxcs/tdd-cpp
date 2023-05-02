#include "waiter.h"
#include <iostream>

A_Waiter waiterA;
B_Waiter waiterB;

void CustomerOrder(Cook &cook)
{
    std::cout << waiterA.Serving(cook) << std::endl;
    std::cout << waiterB.Serving(cook) << std::endl;
}

int main()
{
    ChickenCook chicken;

    CustomerOrder(chicken);

    return 0;
}