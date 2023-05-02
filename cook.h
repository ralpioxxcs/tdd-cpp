#include <string>

class Cook
{
public:
    virtual ~Cook() {}

    virtual std::string Cooking() const = 0;
};

class ChickenCook : public Cook
{
public:
    std::string Cooking() const override
    {
        return "This is chicken";
    }
};

class HotDogCook : public Cook
{
public:
    std::string Cooking() const override
    {
        return "This is hotdog";
    }
};

class HamburgerCook : public Cook
{
public:
    std::string Cooking() const override
    {
        return "This is hamburger";
    }
};