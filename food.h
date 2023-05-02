class Food
{
public:
    virtual ~Food() {}

    virtual int Calorie() const = 0;
};

class Chicken : public Food
{
public:
    int Calorie() const override
    {
        return calorie;
    }

private:
    int calorie{245};
};

class Pizza : public Food
{
public:
    int Calorie() const override
    {
        return calorie;
    }

private:
    int calorie{266};
};

class Ramen : public Food
{
public:
    int Calorie() const override
    {
        return calorie;
    }

private:
    int calorie{436};
};