#include <iostream>
#include "Stack.h"
using std::cout;
using std::endl;

void print(const Stack& stack)
{
    const auto size = stack.size();
    cout << "[";
    for (size_t i = 0; i < size; i++)
    {
        cout << stack[i] << ((i == size - 1) ? "]" : ", ");
    }
}

int main()
{
    auto stack = Stack(5, 1);
    cout<< "stack: ";
    print(stack);
    cout << endl;
    // =================== operators =======================
    stack += 5;
    print(stack);
    cout<< " += 5: ";
    print(stack);
    cout<<endl;

    stack -= 5;
    print(stack);
    cout<< "stack -= 5: ";
    print(stack);
    cout<<endl;


    stack *= 5;
    cout<< "stack *= 5: ";
    print(stack);
    cout<<endl;


    stack /= 5;
    cout<< "stack /= 5: ";
    print(stack);
    cout<<endl;


    auto stack2 = Stack(5, 1);
    cout<< "stack2: [";
    print(stack2);
    cout << "stack3 = stack + stack2: ";
    auto stack3 = stack + stack2;
    print(stack3);
    cout<<endl;
    // copy assignment

    auto stack4 = stack = stack2;
    print(stack);
    cout << " + ";
    print(stack2);
    cout << " = ";
    print(stack4);
    cout << endl;
    // =================== copy -ctor and assignment =======================
    Stack stack5 = Stack(stack);
    cout << "stack5 = stack: ";
    print(stack5);
    cout << endl;
    // =================== move -ctor and assignment =======================
    Stack stack6 (std::move(stack5));
    cout << "stack6 = std::move(stack): ";
    print(stack6);
    cout << endl;
    // =================== move -ctor and assignment =======================
    Stack stack7 = std::move(stack6);
    cout << "stack7 = std::move(stack5): ";
    print(stack7);
    cout << endl;
    // move c-tor
    Stack stack8 = Stack(std::move(stack7));
    cout << "stack8 = std::move(stack7): ";
    print(stack8);
    cout << endl;
    
    // =================== push_back =======================
    stack.push(5);
    cout << "stack.push: ";
    print(stack);
    cout << endl;
    // =================== pop_back =======================
    stack.pop();
    cout << "stack.pop: ";
    print(stack);
    cout << endl;

    // =================== isEmpty =======================
    cout << "stack.isEmpty(): " << stack.isEmpty() << endl;
    // =================== isFull =======================
    cout << "stack.isFull(): " << stack.isFull() << endl;
    // =================== size =======================
    cout << "stack.size(): " << stack.size() << endl;
    // =================== operator[] =======================
    cout << "stack[0]: " << stack[0] << endl;
    // =================== operator== =======================
    print(stack);
    cout << " == ";
    print(stack2);
    cout << ": " << (stack == stack2) << endl;
    // =================== operator!= =======================
    print(stack);
    cout << " != ";
    print(stack2);
    cout << ": " << (stack != stack2) << endl;
    // =================== operator> =======================
    print(stack);
    cout << " > ";
    print(stack2);
    cout << ": " << (stack > stack2) << endl;
    // =================== operator< =======================
    print(stack);
    cout << " < ";
    print(stack2);
    cout << ": " << (stack < stack2) << endl;
    // =================== clear =======================
    stack.clear();
    cout << "stack.clear(): ";
    print(stack);
    cout << endl;

    return EXIT_SUCCESS;
}