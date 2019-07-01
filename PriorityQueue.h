#pragma once
#include <list>

template<typename itemType>
class priorityQueue {
public:
    // Default Constructor initializes 
    priorityQueue<itemType>() { data = std::list<itemType>(); }

    priorityQueue(const priorityQueue<itemType>& other) { data = other.data; }

    // O(n)
    itemType& front() { return *getFront(); }

    // O(n)
    void pop() { data.erase(getFront()); };

    // O(1)
    void push(const itemType& item) { data.push_back(item); };

    inline size_t size() { return data.size(); }
    inline bool isEmpty() { return data.empty(); }

private:
    // Data fields
    std::list<itemType> data;

    typename std::list<itemType>::iterator getFront()
    {
        auto front = data.begin();
        for (auto itr = ++data.begin(); itr != data.end(); ++itr)
        {
            if (std::is_pointer<itemType>::value) {
                if (**front < **itr)
                    front = itr;
            }
            else {
                if (*front < *itr)
                    front = itr;
            }
        }

        return front;
    }
};
