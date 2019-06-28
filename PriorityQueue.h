#pragma once
template<typename Item_Type>

class priority_queue {
public:	
	void pop() {
		front_index = (front_index + 1) % capacity;
		num_items--;
	};
	void push(const Item_Type item) {
		if (num_items == capacity)
			reallocate();
		int index = 0, i = 0, new_index = 0;
		for (i = 0; i < num_items; ++i) {
			index = (front_index + i) % capacity;
			if (item > the_data[index])
				break;
		}
		//shift the elements for the new element (to the right)
		for (int j = 0; j < num_items - i; ++j) {
			index = (back_index - j) % capacity;
			new_index = (index + 1) % capacity;
			the_data[new_index] = the_data[index];
		}
		num_items++;
		the_data[(front_index + i) % capacity] = item; //insert your element
		back_index = (back_index + 1) % capacity; //adjust back index
	};
	size_t front() { return *front_index; };
	size_t size() { return num_items; }
	bool isEmpty { };

private:
	// Data fields
	static const size_t DEFAULT_CAPACITY = 10;
	size_t capacity;
	size_t num_items;
	size_t front_index;
	size_t rear_index;
	Item_Type* the_data;
	void reallocate() {
		size_t new_capacity = 2 * capacity;
		Item_Type* new_data = newItem_Type[new_capacity];
		size_t j = front_index;
		for (size_t i = 0; i < num_items; i++) {
			new_data[i] = the_data[j];
			j = (j + 1) % capacity;
		}
		front_index = 0;
		rear_index = num_items - 1;
		capacity = new_capacity;
		std::swap(the_data, new_data);
		delete[] new_data;
	};
	void MergeSort() {
		/*if (num_items % 2 = 0) {
			size_t midpoint = num_items / 2;
		}
		else {
			size_t midpoint = (num_items / 2) + 1;
		}
		To be finished
		*/
	};
};

