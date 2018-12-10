#include <iostream>
using namespace std;

namespace monologue
{
    template <class T>
    class list_node
    {
        public:
            list_node(const T& value = T())
                : prev(nullptr)
                , next(nullptr)
                , val(value)
            {}
            list_node<T>* prev; 
            list_node<T>* next; 
            T val;
    };
    template<class T>
    class list
    {
        typedef list_node<T> node;
        typedef node* PNode;
        public:
            list()
            {
                createhead();
            }

            list(size_t n, const T& val)
            {
                for (size_t i = 0; i < n; ++i)
                {
                    push_back(val);
                }
            }

            list(T* first, T* last)
            {
                createhead();
                while (first != last)
                {
                    push_nack(*first++);
                }
            }

            //list(const list<T>& l);
            //list<T>& operator(const list<T>& l);

            ~list()
            {
                clear();
                delete m_pHead;
                m_pHead = nullptr;
            }

            // capacity
            size_t size()const
            {
                size_t count;
                PNode pCur = m_pHead->next;
                while (pCur != m_pHead)
                {
                    count++;
                    pCur = pCur->next;
                }
                return count;
            }

            bool Empty()const
            {
                return m_pHead == m_pHead->next;
            }

            void resize(size_t newSize, const T& val)
            {
                size_t oldSize = size();
                if (newSize > oldSize)
                {
                    for (size_t i = oldSize; i < newSize; i++)
                    {
                        push_back(val);
                    }
                }
                else 
                {
                    for (size_t i = newSize; i < oldSize; ++i)
                    {
                        pop_back(val);
                    }
                }
            }

            // acess
            T& front()
            {
                return m_pHead->next->val;
            }

            const T& front()const
            {
                return m_pHead->next->val;
            }

            T& back()
            {
                return m_pHead->next-prev;
            }

            const T& back()const
            {
                return m_pHead->next->prev;
            }

            //modify
            void push_back(const T& val)
            {
                insert(end(), val);
            }
            void pop_back()
            {
                insert(--end());
            }

            void push_front(const T& val)
            {
                insert(begin(), val);
            }

            void pop_front()
            {
                erase(begin());
            }

            iterator insert(iterator position, cont T& val)
            {

            }

            iterator erase(iterator position) 
            {

            }

            void wap(list<T>& l)
            {
                swap(m_pHead, l.m_pHead);
            }

            void clear()
            {
                PNode *pCur = m_pHead->next;
                while (pCur != m_pHead)
                {
                    m_pHead->next = pCur->next;
                    delete pCur;
                    pCur = m_pHead->next;
                }
                m_pHead->next = m_pHead;
                m_pHead->prev = m_pHead;
            }
        private:
            PNode createhead(const T& val = T())
            {
                m_pHead = new node();
                m_pHead->next = m_pHead;  
                m_pHead->prev = m_pHead;
            }
        private:
            PNode m_pHead;
    };
}

int main()
{
    
    return 0;
}
