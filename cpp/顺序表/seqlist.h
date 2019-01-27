#define __SEQLIST_H__
#ifdef __SEQLIST_H__ 
#include <iostream>
#include <assert.h>
#include <string.h>
template <class T>
class Seqlist
{
    public:
        Seqlist();
        ~Seqlist();
        Seqlist(const Seqlist<T> &q);
        Seqlist<T>& operator=(const Seqlist<T>& s);

        void PushBack(const T& x);
        void PopBack();
        void Insert(size_t pos, const T& x);
        void Erase(size_t pos);
        bool Empty();
        T& operator[](size_t pos);
        const T& operator[](size_t pos) const;

        size_t Size();
    private:
        T *m_array;
        size_t m_size;
        size_t m_capacity;
};

template<class T>
size_t Seqlist<T>::Size()
{
    return m_size;
}

template<class T>
Seqlist<T>::Seqlist()
                :m_array(NULL)
                ,m_capacity(0)
                ,m_size(0)
            {}

template<class T>
Seqlist<T>::~Seqlist()
{
    if (m_array)
    {
        delete[] m_array;
        m_array = NULL;
        m_capacity = 0;
        m_size = 0;
    }
}

template<class T>
Seqlist<T>::Seqlist(const Seqlist<T> &s)
{
    if (s.m_size != 0)
    {
        m_array = new T[s.m_size];
        memcpy(m_array, s.m_array, sizeof(T)*s.m_size);
        m_size = m_capacity = s.m_szie;
    }
    else 
    {
        m_array = NULL;
        m_size = m_capacity = 0;
    }
}

template<class T>
Seqlist<T>& Seqlist<T>::operator=(const Seqlist<T>& s)
{
    if (this != &s)
    {
        if (s.m_size != 0)
        {
            delete[] m_array;
            m_array = new T[s.m_size];
            memcpy(m_array, s.m_array, sizeof(T)*s.m_size);
        }
        else 
        {
            m_size = 0;
        }
    }
    return *this;
}

///////////////////////////////
// 基本操作
template<class T>
void Seqlist<T>::PushBack(const T& x)
{
    Insert(m_size, x);
}

template<class T>
void Seqlist<T>::PopBack()
{
    Erase(m_size - 1);
}

template<class T>
void Seqlist<T>::Insert(size_t pos, const T& x)
{
    assert(pos <= m_size);
    if (m_size == m_capacity)
    {
        size_t NewCapacity = m_capacity == 0?3:m_capacity*2;
        T* NewArray = new T[NewCapacity];
        memcpy(NewArray, m_array, sizeof(T)*m_size);
        delete[] m_array;
        m_array = NewArray;
        m_capacity = NewCapacity;
    }
    size_t end = m_size;
    while (end > pos)
    {
        m_array[end - 1] = m_array[end];
        --end;
    }
    m_array[pos] = x;
    ++m_size;
}

template<class T>
void Seqlist<T>::Erase(size_t pos)
{
    assert(pos < m_size);
    size_t start = pos;
    while (start < m_size-1)
    {
        m_array[start] = m_array[start + 1];
        ++start;
    }
    --m_size;
}

template<class T>
bool Seqlist<T>::Empty()
{
    return m_size == 0;
}

template<class T>
T& Seqlist<T>::operator[](size_t pos)
{
    return m_array[pos];
}
template<class T>
const T& Seqlist<T>::operator[](size_t pos) const
{
    return m_array[pos];
}

void Test()
{
    Seqlist<int> s1;
    s1.PushBack(1);
    s1.PushBack(2);
    s1.PushBack(3);
    s1.PushBack(4);

    for (size_t i = 0; i < s1.Size(); ++i)
    {
        std::cout << s1[i] << " ";
    }
    std::cout << std::endl;

    s1.Erase(2);
    for (size_t i = 0; i < s1.Size(); ++i)
    {
        std::cout << s1[i] << " ";
    }
    std::cout << std::endl;

    s1.PopBack();
    for (size_t i = 0; i < s1.Size(); ++i)
    {
        std::cout << s1[i] << " ";
    }
    std::cout << std::endl;
}
#endif
