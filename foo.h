#include <string>

class Foo {
public:
    Foo() = default;

    virtual std::string DoThis(int n) = 0;
    virtual int DoThat(std::string &str) = 0;
};
