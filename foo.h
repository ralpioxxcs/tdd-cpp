#include <string>

class Foo {
public:
    Foo() = default;

    int GetSize() const;

private:
    int n{5};
};
