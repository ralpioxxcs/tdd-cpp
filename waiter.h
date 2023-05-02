#include "cook.h"

class Waiter
{
public:
    virtual ~Waiter() {}
    virtual std::string Serving(Cook &cook) const = 0;
};

class A_Waiter : public Waiter
{
public:
    std::string Serving(Cook &cook) const override
    {
        return "serve" + cook.Cooking() + "from waiter A";
    }
};

class B_Waiter : public Waiter
{
public:
    std::string Serving(Cook &cook) const override
    {
        return "serve" + cook.Cooking() + "from waiter B";
    }
};