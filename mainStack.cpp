#include "Stack.hpp"

int main() {
    MyStack<char> stack;
    stack.push('a');
    stack.push('b');
    stack.push('c');
    stack.push('d');
    stack.push('e');
    std::cout << stack.top() << " ";
    stack.pop();
    std::cout << stack.top() << " ";
    stack.pop();
    std::cout << stack.top() << " ";
    stack.pop();
    std::cout << stack.top() << " ";
    stack.pop();
    std::cout << stack.top() << " ";
    stack.pop();
    

    MyStack<char> stack1;
    stack1 = stack;

    return 0;
}