#include <iostream>
#include <string.h>
using namespace std;

namespace Test 
{
    template<class T>
    class vector
    {
        public:
            typedef T* reverse_iterator;
            typedef T* iterator;
        public:
            vector()
                :m_star(nullptr)
                ,m_last(nullptr)
                ,m_endOfStorage(nullptr)
            {}

            vector(size_t n, const T& data)
                :m_star(new T[n])
                ,m_last(m_star+n)
                ,m_endOfStorage(m_last)
            {
                for (size_t i = 0; i < n; ++i)
                {
                    m_star[i] = data;
                }
            }

            vector(T *first, T *last)
            {
                size_t size = last -last;
                m_star = new T[size];
                for (size_t i = 0; i < size; ++i)
                {
                    m_star[i] = first[i];
                }

                //memcpy(m_star, first, size*sizeof(T));

                m_last = m_star + size;
                m_endOfStorage = m_last;
            }

            vector(const vector<T>& v)
            {
            }

            ~vector()
            {
                if (m_star)
                {
                    delete[] m_star;
                    m_star = m_last = m_endOfStorage = nullptr;
                }
            }

            vector<T>& operator=(const vector<T> v)
            {}

            iterator begin()
            {
                return m_star;
            }
            iterator engd()
            {
                return m_last;
            }
            reverse_iterator rbegin()
            {
                return rend();
            }
            reverse_iterator rend()
            {
                return rbegin();
            }

            size_t size() const 
            {
                return m_last-m_star;
            }
            size_t capacity() const 
            {
                return m_endOfStorage;
            }
            bool empty() const 
            {
                return m_star == m_last;
            }

            void resize(size_t newSize, const T* data = T())
            {
                size_t oldSize = size();
                if (newSize <= oldSize)
                {
                    m_last = m_star + newSize;
                }
                else
                {
                    size_t _capacity = capacity();
                    if (newSize <= _capacity)
                    {
                        for (size_t i = 0; i < newSize; ++i)
                        {
                            *m_last++ = data;
                        }
                    }
                    else 
                    {
                        T *pTemp = new T[newSize];
                        for (size_t i = 0; i < oldSize; ++i)
                        {
                            pTemp[i] = m_star[i];
                        }
                        for (size_t i = oldSize; i < newSize; ++i)
                        {
                            pTemp[i] = data;
                        }
                        delete [] m_star;
                        m_star = pTemp;
                        m_last = m_star + newSize;
                        m_endOfStorage = m_last;
                    }
                }
            }

            void reserve(size_t newCapacity)
            {
                size_t oldCapacity = capacity();
                if (newCapacity > oldCapacity)
                {
                    T *pTemp = new T[newCapacity];
                    size_t count = size();
                    for (size_t i = 0; i < count; ++i)
                    {
                        pTemp[i] = m_star[i];
                    }
                    delete [] m_star;
                    m_star = pTemp;
                    m_last = m_star + count;
                    m_endOfStorage = m_star +newCapacity;
                }
            }

            T& operator[](size_t index)
            {
                return m_star[index];
            }
            const T& operator[](size_t index) const 
            {
                return m_star[index];
            }
            T& Front()
            {
                return *m_star;
            }
            const T& Front() const 
            {
                return *m_star;
            }
            T& Back()
            {
                return *(m_last-1);
            }
            const T& Back() const 
            {
                return *(m_last-1);
            }

            void pushback(const T& data)
            {
                if (size() == capacity())
                {
                    reserve(capacity()*2);
                }
                *m_last++ = data;
            }

            void popback()
            {
                --m_last;
            }

            void clear()
            {
                m_last = m_star;
            }

            void swap(vector<T>& v)
            {
                swap(m_star, v.m_star);
                swap(m_last, v.m_last);
                swap(m_endOfStorage, v.m_endOfStorage);
            }

            iterator insert(iterator pos, const T& data)
            {
            }

            iterator erase(iterator pos)
            {
            }

        private:
            iterator m_star;
            iterator m_last;
            iterator m_endOfStorage;
    };

}

void TestVector()
{
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    Test::vector<int> v(array, array+sizeof(array)/sizeof(array[0]));
    cout << v.size() << endl;
    cout << v.capacity() << endl;
    for (auto e : v)
    {
        cout << e << " ";
    }
    cout << endl;
}
