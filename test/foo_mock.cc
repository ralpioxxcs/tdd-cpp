#include "foo.h"

#include <gmock/gmock.h>

class FakeFoo : public Foo {
public:
    std::string DoThis(int n) override {
        return (n > 0) ? "+" : (n < 0) ? "-" : "0";
    }
    
    int DoThat(std::string &str) override {
        return str.size();
    }
};

class MockFoo : public Foo {
public:
    MOCK_METHOD(std::string, DoThis, (int n), (override));
    MOCK_METHOD(int, DoThat, (std::string & str), (override));

    void DelegateToFake() {
        ON_CALL(*this, DoThis).WillByDefault([this](int n)
                                             { return fake_.DoThis(n); });

        ON_CALL(*this, DoThat).WillByDefault([this](std::string &str)
                                             { return fake_.DoThat(str); });
    }

private:
    FakeFoo fake_;
};

//------------------------------------------------------------------------------------------------------------

using ::testing::_;

TEST(FooTest, xyz) {
    MockFoo foo;
    foo.DelegateToFake();

    EXPECT_CALL(foo, DoThis);
    EXPECT_CALL(foo, DoThat(_));

    int n = 0;
    EXPECT_EQ("+", foo.DoThis(5));      // FakeFoo::DoThis() is invoked.

    std::string greeting{"hi"};
    n = foo.DoThat(greeting);           // FakeFoo::DoThat() is invoked.
    EXPECT_EQ(2, n);
}