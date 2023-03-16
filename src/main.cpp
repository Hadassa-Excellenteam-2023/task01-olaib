#include <iostream>
#include "Vector.h"
using std::cout;
using std::endl;

int main()
{
    auto vec1 = Vector(5, 10);
    cout << "vec1: ";
    for (size_t i = 0; i < vec1.size(); i++) {
        cout << vec1[i] << " ";
    }
    cout << endl;

    auto vec2 = Vector(7, 20);
    cout << "vec2: ";
    for (size_t i = 0; i < vec2.size(); i++) {
        cout << vec2[i] << " ";
    }
    cout << endl;

    // test the < operator
    cout << "vec1 < vec2: " << (vec1 < vec2) << endl;

    // test the == operator
    cout << "vec1 == vec2: " << (vec1 == vec2) << endl;

    // test the > operator
    cout << "vec1 > vec2: " << (vec1 > vec2) << endl;

    // test push_back() and pop_back()
    vec1.push_back(15);
    vec1.push_back(20);
    vec1.pop_back();
    cout << "vec1: ";
    for (size_t i = 0; i < vec1.size(); i++) {
        cout << vec1[i] << " ";
    }
    cout << endl;

    // test insert()
    vec1.insert(1, 25);
    cout << "vec1: ";
    for (size_t i = 0; i < vec1.size(); i++) {
        cout << vec1[i] << " ";
    }
    cout << endl;

    // test erase()
    vec1.erase(2);
    cout << "vec1: ";
    for (size_t i = 0; i < vec1.size(); i++) {
        cout << vec1[i] << " ";
    }
    cout << endl;

    // test clear()
    vec1.clear();
    cout << "vec1: ";
    for (size_t i = 0; i < vec1.size(); i++) {
        cout << vec1[i] << " ";
    }
    cout << endl;

    Vector v(3, 5);
    auto vector = v.data();
    std::cout << "data(): " << vector << std::endl;
    for (size_t i = 0; i < v.size(); i++)
    {
        std::cout << "data[" << i << "]: " << *(vector + i) << std::endl;

    }

    return 0;
}