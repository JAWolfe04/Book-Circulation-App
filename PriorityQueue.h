#pragma once

template<typename itemType>
class PriorityQueue {
public:
    // Default Constructor initializes 
    PriorityQueue<itemType>() : numItems(0), frontIndex(0), backIndex(0),
        capacity(DEFAULT_CAPACITY), data(new itemType[capacity]) {}

    //Efficiency: O(n)
    PriorityQueue<itemType>(const PriorityQueue<itemType>& other)
        : capacity(other.capacity), numItems(other.numItems),
          frontIndex(other.frontIndex), backIndex(other.backIndex),
          data(new itemType[other.capacity])
    { 
        for (size_t i = 0; i < numItems; i++)
            data[i] = other.data[i];
    }

    //Efficiency: O(1)
    ~PriorityQueue()
    {
        delete[] data;
        data = nullptr;
    }

    //Efficiency: O(1) (2 simple statements, so the expression is constant)
    void pop() {
        frontIndex = (frontIndex + 1) % capacity;
        numItems--;
    };

    //Efficiency: O(n)
    void push(const itemType item) {
        if (numItems == capacity)
            reallocate();

        size_t index = 0, i = 0, newIndex = 0;

        for (i = 0; i < numItems; ++i) {
            index = (frontIndex + i) % capacity;
            if (item > data[index])
                break;
        }
        //shift the elements for the new element (to the right)
        for (size_t j = 0; j < numItems - i; ++j) {
            index = (backIndex - j) % capacity;
            newIndex = (index + 1) % capacity;
            data[newIndex] = data[index];
        }
        numItems++;
        data[(frontIndex + i) % capacity] = item; //insert your element
        // Moving the back index when there is only 1 item in the queue moves it 
        // to an empty index instead of the last item index
        if (numItems > 1)
            backIndex = (backIndex + 1) % capacity; //adjust back index
    };

    //Efficiency: O(n) 
    void update_item(itemType& item) {
        size_t index = 0, newIndex = 0, i = 0;
        for (i; i < numItems; ++i) {
            index = (frontIndex + i) % capacity;
            if (item == data[index])
                break;
        }
        if (i < numItems) {
            if (item > data[index]) {
                data[index] = item;
                for (size_t j = i; j > 0; --j)
                {
                    index = (frontIndex + j) % capacity;
                    newIndex = (frontIndex + j - 1) % capacity;
                    if (data[index] > data[newIndex])
                        std::swap(data[index], data[newIndex]);
                    else
                        break;
                }
            }
            else if (item < data[index]) {
                data[index] = item;
                for (size_t j = i; j < numItems - 1; ++j)
                {
                    index = (frontIndex + j) % capacity;
                    newIndex = (frontIndex + j + 1) % capacity;
                    if (data[index] < data[newIndex])
                        std::swap(data[index], data[newIndex]);
                    else
                        break;
                }
            }
            else
                data[index] = item;
        }
    }

    inline itemType& front() { return data[frontIndex]; }
    inline size_t size() { return numItems; }
    inline bool isEmpty() { return numItems == 0 ; }

private:
    // Data fields
    static const size_t DEFAULT_CAPACITY = 10;
    size_t capacity;
    size_t numItems;
    size_t frontIndex;
    size_t backIndex;
    itemType* data;

    //Private functions
    //Efficiency: O(n)
    void reallocate() {
        size_t newCapacity = 2 * capacity;
        itemType* newData = new itemType[newCapacity];

        size_t j = frontIndex;
        for (size_t i = 0; i < numItems; ++i)
        {
            newData[i] = data[j];
            j = (j + 1) % capacity;
        }

        frontIndex = 0;
        backIndex = numItems - 1;
        capacity = newCapacity;
        delete[] data;
        data = newData;
    };
};
