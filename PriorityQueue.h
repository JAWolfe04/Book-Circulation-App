#pragma once

template<typename Item_Type>
class priority_queue {
public:
    // Default Constructor initializes 
    priority_queue() : num_items(0), front_index(0), back_index(0),
        capacity(DEFAULT_CAPACITY), the_data(new Item_Type[capacity]) {}

    //Efficiency: O(n)
    priority_queue<Item_Type>(const priority_queue<Item_Type>& other) 
        : capacity(other.capacity), num_items(other.num_items),
          front_index(other.front_index), back_index(other.back_index),
          the_data(new Item_Type[other.capacity])
    { 
        for (size_t i = 0; i < num_items; i++)
            the_data[i] = other.the_data[i];
    }

    //Efficiency: O(1)
    ~priority_queue()
    {
        delete[] the_data;
        the_data = nullptr;
    }

    //Efficiency: O(1) (2 simple statements, so the expression is constant)
    void pop() {
        front_index = (front_index + 1) % capacity;
        num_items--;
    };

    //Efficiency: O(n)
    void push(const Item_Type item) {
        if (num_items == capacity)
            reallocate();

        size_t index = 0, i = 0, new_index = 0;

        for (i = 0; i < num_items; ++i) {
            index = (front_index + i) % capacity;
            if (item > the_data[index])
                break;
        }
        //shift the elements for the new element (to the right)
        for (size_t j = 0; j < num_items - i; ++j) {
            index = (back_index - j) % capacity;
            new_index = (index + 1) % capacity;
            the_data[new_index] = the_data[index];
        }
        num_items++;
        the_data[(front_index + i) % capacity] = item; //insert your element
        // Moving the back index when there is only 1 item in the queue moves it 
        // to an empty index instead of the last item index
        if (num_items > 1)
            back_index = (back_index + 1) % capacity; //adjust back index
    };

    //Efficiency: O(n) 
    void update_item(Item_Type& item) {
        size_t index = 0, new_index = 0, i = 0;
        for (i; i < num_items; ++i) {
            index = (front_index + i) % capacity;
            if (item == the_data[index])
                break;
        }
        if (i < num_items) {
            if (item > the_data[index]) {
                the_data[index] = item;
                for (size_t j = i; j > 0; --j)
                {
                    index = (front_index + j) % capacity;
                    new_index = (front_index + j - 1) % capacity;
                    if (the_data[index] > the_data[new_index])
                        swap(the_data[index], the_data[new_index]);
                    else
                        break;
                }
            }
            else if (item < the_data[index]) {
                the_data[index] = item;
                for (size_t j = i; j < num_items - 1; ++j)
                {
                    index = (front_index + j) % capacity;
                    new_index = (front_index + j + 1) % capacity;
                    if (the_data[index] < the_data[new_index])
                        swap(the_data[index], the_data[new_index]);
                    else
                        break;
                }
            }
            else
                the_data[index] = item;
        }
    }

    inline Item_Type& front() { return the_data[front_index]; }
    inline size_t size() { return num_items; }
    inline bool isEmpty() { return num_items == 0 ; }

private:
    // Data fields
    static const size_t DEFAULT_CAPACITY = 10;
    size_t capacity;
    size_t num_items;
    size_t front_index;
    size_t back_index;
    Item_Type* the_data;

    //Private functions
    //Efficiency: O(n)
    void reallocate() {
        size_t new_capacity = 2 * capacity;
        Item_Type* new_data = new Item_Type[new_capacity];

        size_t j = front_index;
        for (size_t i = 0; i < num_items; ++i)
        {
            new_data[i] = the_data[j];
            j = (j + 1) % capacity;
        }

        front_index = 0;
        back_index = num_items - 1;
        capacity = new_capacity;
        delete[] the_data;
        the_data = new_data;
    };
};
