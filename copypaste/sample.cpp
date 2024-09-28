#include <iostream>
#include <vector>
#include <stdexcept>

// Stack class using templates
template <typename T>
class Stack {
private:
    std::vector<T> elements;  // Container to hold stack elements

public:
    // Push an element onto the stack
    void push(const T& element) {
        elements.push_back(element);
    }

    // Pop an element from the stack
    void pop() {
        if (elements.empty()) {
            throw std::out_of_range("Stack<>::pop(): Empty stack");
        }
        elements.pop_back();
    }

    // Get the top element from the stack
    T top() const {
        if (elements.empty()) {
            throw std::out_of_range("Stack<>::top(): Empty stack");
        }
        return elements.back();
    }

    // Check if the stack is empty
    bool empty() const {
        return elements.empty();
    }

    // Get the size of the stack
    size_t size() const {
        return elements.size();
    }
};

// Function to reverse a string using a stack
template <typename T>
void reverseString(T& str) {
    Stack<char> stack;
    for (char ch : str) {
        stack.push(ch);
    }
   
    for (size_t i = 0; i < str.length(); ++i) {
        str[i] = stack.top();
        stack.pop();
    }
}

int main() {
    // Example of using Stack<int>
    Stack<int> intStack;
    intStack.push(1);
    intStack.push(2);
    intStack.push(3);
    std::cout << "Top element in integer stack: " << intStack.top() << std::endl;

    // Popping an element
    intStack.pop();
    std::cout << "Top element after popping: " << intStack.top() << std::endl;

    // Reversing a string using the stack
    std::string str = "Hello, World!";
    std::cout << "Original string: " << str << std::endl;
    reverseString(str);
    std::cout << "Reversed string: " << str << std::endl;

    return 0;
}
