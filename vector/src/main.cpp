#include <iostream>
#include<Vector.h>
using std::cout;
using std::endl;


void print(const Vector& stack)
{
    const auto size = stack.size();
    cout << "[";
    for (size_t i = 0; i < size; i++)
    {
        cout << stack[i] << ((i == size - 1) ? "]" : ", ");
    }
    cout << endl;
}

int main(){
    auto vec1 = Vector(5, 10);
    cout << "vec1: ";
    print(vec1);

    auto vec2 = Vector(7, 20);
    cout << "vec2: ";
    print(vec2);

    // test the [] operator of int&
    vec1[0] = 100;
    cout << vec1[0] << endl;

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
    print(vec1);

    // test insert()
    vec1.insert(1, 25);
    cout << "vec1: ";
    print(vec1);

    // test erase()
    vec1.erase(2);
    cout << "vec1: ";
    print(vec1);

    Vector v(3, 5);
    auto vector = v.data();
    std::cout << "data(): " << vector << std::endl;
    for (size_t i = 0; i < v.size(); i++)
    {
        std::cout << "data[" << i << "]: " << *(vector + i) << std::endl;

    }
    cout << "copy: ";
    // test the copy constructor
    Vector vec3(vec1);
    cout << "vec3: ";
    print(vec3);

    // test the assignment operator
    auto vec4 = Vector(3, 10);
    vec4 = vec1;
    cout << "vec4: ";
    print(vec4);

    // test the move constructor
    auto vec5 = Vector(std::move(vec1));
    cout << "vec5: ";
    print(vec5);

    // test the move assignment operator
    auto vec6 = Vector(3, 10);
    vec6 = std::move(vec2);
    cout << "vec6: ";
    print(vec6);

    // test clear()
    vec1.clear();
    cout << "vec1: ";
    print(vec1);

    return EXIT_SUCCESS;

}