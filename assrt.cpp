#include <cassert>
#include <iostream>

enum class Type {
    tInt,
    tFloat,
    tCString
};

void printValue(void* ptr, Type type) {
    switch (type) {
        case Type::tInt:
            std::cout << *static_cast<int*>(ptr) << '\n';
            break;
        case Type::tFloat:
            std::cout << *static_cast<float*>(ptr) << '\n';
            break;
        case Type::tCString:
            std::cout << static_cast<char*>(ptr) << '\n';
            break;
        default:
            assert(false && "type not found"); // Always triggers assertion failure with message
            break;
    }
}

int main() {
    int nValue = 5;
    printValue(&nValue, Type::tInt); // Invalid type to trigger assertion
    return 0;
}

