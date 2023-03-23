#pragma once
#include <stdexcept>// std::out_of_range
#include "Vector.h"



// This class for stack that using our custom vector class
class Stack
{
public:
    // ======================= C-TOR =============================
    explicit Stack(const int& size = 0, const int& value = 0);
    Stack(const Stack& other);
    Stack(Stack&& other) noexcept;
    // ================= COPY ASSIGNMENT =========================
    Stack& operator=(const Stack& other);
    Stack& operator=(Stack&& other);
    // ================= ARITHMETIC OPERATORS ====================
    Stack& operator+=(const int& factor);
    Stack& operator-=(const int& factor);
    Stack& operator*=(const int& factor);
    Stack& operator/=(const int& factor);
    // ================= SEQUENCE OPERATOR ======================
    Stack& operator+=(const Stack& other);
    // ====================== METHODS ============================
    void push(const int& value);
    void pop();
    auto isFull() const{return m_stack.size() == m_stack.capacity();};
    auto isEmpty() const{return m_stack.empty();};
    auto size() const { return m_stack.size(); }
    const auto& operator[](const size_t& index) const { return m_stack[index]; }
    auto& operator[](const size_t& index) { return m_stack[index]; }
    auto clear() { m_stack.clear(); }
    // ======================= D-TOR =============================
    ~Stack() {};
private:
    Vector m_stack;
};
// ========================== GLOBAL OPERATORS =====================
bool operator<(const Stack& lhs, const Stack& rhs);
bool operator>(const Stack& lhs, const Stack& rhs);
bool operator!=(const Stack& lhs, const Stack& rhs);
bool operator==(const Stack& lhs, const Stack& rhs);
// ==========================Global SEQUENCE OPERATORS  =====================
Stack operator+(const Stack& lhs, const Stack& rhs);

