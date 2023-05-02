#include "waiter.h"

class MockCook : public Cook
{
public:
    MOCK_METHOD(std::string, Cooking, (), (const override));

}

using ::testing::_;

TEST(WaiterTest, order)
{
    MockCook mockCook;

    EXPECT_CALL(mockCook, Cooking).Times(3);
}