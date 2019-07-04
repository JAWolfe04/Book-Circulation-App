#pragma once
#include <list>

// Maintains a queue of items based on item priority
// Items must be comparable
template<typename itemType>
class priorityQueue {
public:
    // Default Constructor initializes an empty queue
    priorityQueue<itemType>() { container = std::list<itemType>(); }

    // Copy constructor
    priorityQueue(const priorityQueue<itemType>& other) { container = other.container; }

    // Returns the item with the highest priority in the queue
    // O(n)
    itemType& front() { return *getFront(); }

    // Removes item with the highest priority from queue
    // O(n)
    void pop() { container.erase(getFront()); };

    // Adds item to the queue
    // O(1)
    void push(const itemType& item) { container.push_back(item); };

    //Returns the size of the queue
    // O(1)
    inline size_t size() { return container.size(); }

    // Returns if queue has no items
    // O(1)
    inline bool isEmpty() { return container.empty(); }

private:
    std::list<itemType> container; // Container to store data

    // Returns the item in the queue with the highest priority
    // O(n)
    typename std::list<itemType>::iterator getFront()
    {
        auto front = container.begin(); // Highest priority item
        // Iterate through the remaining items and find highest priority item
        for (auto itr = ++container.begin(); itr != container.end(); ++itr)
        {
            // Test for queue of pointers to dereference them
            // for comparison of the items then compare and if
            // front is lower replace front with the current item
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
