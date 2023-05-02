#include "creator.h"

#include <gmock/gmock.h>

class FakeFood : public Food
{
public:
    int Calorie() const override
    {
        return 0;
    }
};

class FakeCreator : public Creator
{
public:
    Food *FactoryMethod() const override
    {
        return new FakeFood();
    }
};

class MockCreator : public Creator
{
public:
    MOCK_METHOD((Food *), FactoryMethod, (), (const override));

    void DelegateToFake()
    {
        ON_CALL(*this, FactoryMethod).WillByDefault([this]() -> Food*
                                                    { return fake_.FactoryMethod(); });
    }

private:
    FakeCreator fake_;
};

using ::testing::_;

TEST(FooTest, xyz)
{
    MockCreator mockCreator;
    mockCreator.DelegateToFake();

    EXPECT_CALL(mockCreator, FactoryMethod).Times(2);

    EXPECT_EQ(0, mockCreator.GetCalorie());
    EXPECT_NE(1, mockCreator.GetCalorie());
}