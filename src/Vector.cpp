#include <Vector.h>

const auto MAX_CAPACITY = 128;
const auto LESS = std::strong_ordering::less;
const auto EQUAL = std::strong_ordering::equal;
const auto GREATER = std::strong_ordering::greater;

auto checkSize(const int& size) {
    // check if valid size
    if (size < 0)
        throw(std::invalid_argument("Size must be positive"));
    return size;
}

bool compareSizes(const size_t& s1, const size_t& s2, std::strong_ordering op)
{
    return (op == LESS ? s1 < s2 : 
        (op == GREATER ? s1 > s2 : s1 == s2));
}

void checkIndex(const size_t& index, const size_t& maxRange) {
    if (index < 0 || index > maxRange)
        throw std::out_of_range("Index out of range");
}

// ======================== CONSTRUCTOR ==================================

Vector::Vector(const int& size, const int& value)
{
    m_size = m_capacity = checkSize(size);
    m_vector = new int[size];
    // fill the vector by zeroes
    for (size_t i = 0; i < size; i++)
    {
        m_vector[i] = value;

    }
}

// ========================================================================

const int& Vector::operator[](const size_t& index) const
{
    if (0 > index || index >= m_size)
        throw(std::out_of_range("Index out of range"));

    return m_vector[index];
}

int* Vector::data() const noexcept
{
    return m_vector;
}

void Vector::clear() noexcept
{
    m_size = 0;
    
    delete[] m_vector;
    m_vector = nullptr;
}

void Vector::resize()
{
    if (m_size < m_capacity)
        return;

    m_capacity = (m_capacity > MAX_CAPACITY ? 2 : static_cast<size_t>(m_capacity * 1.5));

    auto newVector = new int[m_capacity];

    for (size_t i = 0; i < m_size; i++)
    {
        newVector[i] = m_vector[i];
    }

    delete[] m_vector;
    m_vector = newVector;
}

void Vector::swap(Vector& other)
{
    // swap sizes
    auto size = m_size;
    m_size = other.m_size;
    other.m_size = m_size;
    // swap capactities
    size = m_capacity;
    m_capacity = other.m_capacity;
    other.m_capacity = size;
    // swap vectors
    auto swapVector = m_vector;
    m_vector = other.m_vector;
    other.m_vector = swapVector;
}

void Vector::push_back(const int& newVal)
{
    if (m_size == m_capacity)
    {
        resize();
    }
    m_vector[m_size++] = newVal;
}

void Vector::pop_back()
{
    if (empty()) return;
    m_size--;
}

void Vector::erase(const size_t& index)
{
    checkIndex(index, m_size);
    m_size--;
    //if last index
    if (m_size == index)
        pop_back();

    else {
        // shift elements to the left start from index till the end
        for (size_t i = index; i < m_size; i++)
            m_vector[i] = m_vector[i + 1];
    }
}

void Vector::insert(const size_t& index, const int& value)
{
    checkIndex(index, m_size + 1);
    // if at the end of the vector
    if (m_size == index)
        push_back(value);
    else
    {
        if (m_size == m_capacity)
            resize();
        // shift elements to the right start from the end till index
        for (size_t i = m_size; i > index; i--)
            m_vector[i] = m_vector[i - 1];
        m_vector[index] = value;
        m_size++;
    }
}

Vector::~Vector()
{
    delete[] m_vector;
}

bool operator<(const Vector& lhs, const Vector& rhs)
{
    const auto size = lhs.size();

    if (compareSizes(size, rhs.size(), LESS))
        for (size_t i = 0; i < size; ++i)
            if (lhs[i] >= rhs[i])
                return false;
    return true;
}

bool operator==(const Vector& lhs, const Vector& rhs)
{
    const auto size = lhs.size();

    if (compareSizes(size, rhs.size(), LESS))
        for (size_t i = 0; i < size; ++i)
            if (lhs[i] != rhs[i])
                return false;
    return true;
}

bool operator>(const Vector& lhs, const Vector& rhs)
{
    const auto size = lhs.size();

    if (compareSizes(size, rhs.size(), GREATER))
        for (size_t i = 0; i < size; ++i)
            if (lhs[i] <= rhs[i])
                return false;
    return true;
}
