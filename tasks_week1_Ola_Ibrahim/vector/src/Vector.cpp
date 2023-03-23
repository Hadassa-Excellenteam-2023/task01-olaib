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

    // fill the vector by value - memset
    for (size_t i = 0; i < size; i++)
        m_vector[i] = value;
}


Vector::Vector(const Vector& other) : m_size(other.m_size), m_capacity(other.m_capacity),
m_vector(new int[m_capacity])
{
    for (size_t i = 0; i < m_size; i++) {
        m_vector[i] = other.m_vector[i];
    }
}

Vector::Vector(Vector&& other)
{
    *this = std::move(other);
}


Vector& Vector::operator=(const Vector& other)
{
    if (this != &other) {
        m_size = other.m_size;
        m_capacity = other.m_capacity;
        delete[] m_vector;
        m_vector = new int[m_capacity];
        for (size_t i = 0; i < m_size; i++) {
            m_vector[i] = other.m_vector[i];
        }
    }
    return *this;
}

Vector& Vector::operator=(Vector&& other) noexcept
{
    if (this != &other) {
        std::swap(m_size, other.m_size);
        std::swap(m_capacity, other.m_capacity);
        std::swap(m_vector, other.m_vector);
        other.m_vector = nullptr;
        other.m_size = other.m_capacity = 0;
    }
    return *this;
}
// ======================== COMPARISON ===================================
bool Vector::operator<=(const Vector& other) const
{
    if (compareSizes(m_size, other.m_size, GREATER))
        return false;
    for (size_t i = 0; i < m_size; i++)
    {
        if (m_vector[i] > other.m_vector[i])
            return false;
    }

    return true;
}

bool Vector::operator>=(const Vector& other) const
{
    if (compareSizes(m_size, other.m_size, LESS))
        return false;
    for (size_t i = 0; i < m_size; i++)
    {
        if (m_vector[i] < other.m_vector[i])
            return false;
    }

    return true;
}

//=======================================================================
const int& Vector::operator[](const size_t& index) const {
    checkIndex(index, m_size - 1);
    return m_vector[index];
}

int& Vector::operator[](const size_t& index) {
    checkIndex(index, m_size - 1);
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
    m_vector = new int[m_capacity];
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

void Vector::push_back(int&& newVal)
{
    if (m_size == m_capacity)
    {
        resize();
    }
    m_vector[m_size++] = std::move(newVal);
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
    m_vector = nullptr;
}

bool operator<(const Vector& lhs, const Vector& rhs)
{
    return !(lhs >= rhs);
}

bool operator==(const Vector& lhs, const Vector& rhs)
{
    const auto size = lhs.size();

    if (compareSizes(size, rhs.size(), EQUAL))
        for (size_t i = 0; i < size; ++i)
            if (lhs[i] != rhs[i])
                return false;
    return true;
}

bool operator>(const Vector& lhs, const Vector& rhs)
{
    return !(lhs <= rhs);
}

bool operator!=(const Vector& lhs, const Vector& rhs)
{
    return !(lhs == rhs);
}



