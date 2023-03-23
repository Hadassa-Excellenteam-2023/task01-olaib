#include <Stack.h>


// ======================== C-TOR ====================================

Stack::Stack(const int& size, const int& value)
{
    m_stack = Vector(size, value);
}

// ========================= COPY C-TOR ==============================

Stack::Stack(const Stack& other)
{
    m_stack = other.m_stack;
}
// ========================= MOVE C-TOR ==============================
Stack::Stack(Stack&& other) noexcept
{
    m_stack = Vector(std::move(other.m_stack));
}

Stack& Stack::operator=(const Stack& other) {
    return (*this = Stack(other));
}

//cause error
Stack& Stack::operator=(Stack&& other) {
    this->m_stack = std::move(other.m_stack);
    return *this;
}


Stack& Stack::operator+=(const int& factor)
{
    for (size_t i = 0; i < m_stack.size(); i++)
    {
        m_stack[i] += factor;
    }
    return *this;
}

Stack& Stack::operator-=(const int& factor)
{
    //using operator += from above to achieve operator-=
    *this += (-factor);
    return *this;
}

Stack& Stack::operator*=(const int& factor)
{
    for (size_t i = 0; i < m_stack.size(); i++)
    {
        m_stack[i] += factor;
    }
    return *this;
}

Stack& Stack::operator/=(const int& factor)
{
    if(factor == 0)
        throw std::invalid_argument("Division by zero");
    //using operator *= from above to achieve operator/=
    *(this) *= 1/factor;
    return *this;
}

Stack& Stack::operator+=(const Stack& other)
{
    for(size_t i = 0; i < other.size(); i++)
    {
        m_stack.push_back(other[i]);
    }
    return *this;
}

// ========================= METHODS ==================================

void Stack::push(const int& value)
{
    m_stack.push_back(value);
}

void Stack::pop()
{
    m_stack.pop_back();
}


// ===================== GLOBAL OPERATORS =============================
bool operator<(const Stack& lhs, const Stack& rhs)
{
	return lhs.size() < rhs.size();
}

bool operator==(const Stack& lhs, const Stack& rhs)
{
    if (lhs.size() != rhs.size())
        return false;
    for (size_t i = 0; i < lhs.size(); i++)
    {
        if (lhs[i] != rhs[i])
            return false;
    }
    return true;
}

bool operator>(const Stack& lhs, const Stack& rhs)
{
	return lhs.size() > rhs.size();
}

bool operator!=(const Stack& lhs, const Stack& rhs)
{
    return !(lhs == rhs);
}
Stack operator+(const Stack& lhs, const Stack& rhs)
{
    Stack result(lhs);
    result += rhs;
    return result;
}


