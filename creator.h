#include "food.h"

class Creator {
    public:
    virtual ~Creator(){};
    virtual Food* FactoryMethod() const  = 0;

    int GetCalorie() const {
        Food* food = this->FactoryMethod();
        return food->Calorie();
    }
};

class ChickenCreator : public Creator {
    public:
    Food* FactoryMethod() const override {
        return new Chicken();
    }
};
class PizzaCreator : public Creator {
    public:
    Food* FactoryMethod() const override {
        return new Pizza();
    }
};
