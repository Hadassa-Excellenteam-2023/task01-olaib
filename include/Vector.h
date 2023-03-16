#pragma once
#include <stdexcept>// std::out_of_range

class Vector
{
public:
    // ======================= C-TOR =============================
    explicit Vector(const int& size = 0, const int& value = 0);
    // ====================== METHODS ============================
    const int& operator[](const size_t& index) const;
    auto empty() const { return m_size == 0; }
    auto capacity() const { return m_capacity; }
    auto size() const { return m_size; }
    int* data() const noexcept;
    void clear() noexcept;
    void resize();
    void swap(Vector& other);
    void push_back(const int& newVal);
    void pop_back();
    void erase(const size_t& index);
    void insert(const size_t& index, const int& value);
    // ======================= D-TOR =============================
    ~Vector();
private:
    // ====================== PRIVATE MEMBERS ======================
    size_t m_size, 
           m_capacity;
    int* m_vector;
};
// ========================== GLOBAL OPERATORS =====================
bool operator<(const Vector& lhs, const Vector& rhs);
bool operator==(const Vector& lhs, const Vector& rhs);
bool operator>(const Vector& lhs, const Vector& rhs);