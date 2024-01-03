#include "dynamic_array.hpp"

dynamic_array::dynamic_array(int n)
{
	elements = new int[n](); // () initializes all elements to 0
	array_size = n;
}

dynamic_array::dynamic_array(const dynamic_array &other)
{
	num_elements = other.num_elements;
	array_size = other.array_size;
	elements = new int[array_size];
	for (int i = 0; i < num_elements; ++i)
	{
		elements[i] = other.elements[i];
	}
}

dynamic_array &dynamic_array::operator=(const dynamic_array &other)
{
	if (this != &other)
	{
		delete[] elements;
		num_elements = other.num_elements;
		array_size = other.array_size;
		elements = new int[array_size];
		for (int i = 0; i < num_elements; ++i)
		{
			elements[i] = other.elements[i];
		}
	}
	return *this;
}

dynamic_array::~dynamic_array()
{
	delete[] elements;
}

void dynamic_array::resize(int new_size)
{
	int *new_array = new int[new_size]();

	for (int i = 0; i < num_elements; ++i)
	{
		new_array[i] = elements[i];
	}
	delete[] elements;
	elements = new_array;
	array_size = new_size;
}

int dynamic_array::get_len() const
{
	return num_elements;
}

int dynamic_array::get_at(int index) const
{
	if (index < 0 || index >= num_elements)
	{
		throw std::out_of_range("Index out of bounds");
	}
	return elements[index];
}

void dynamic_array::set_at(int i, int x)
{
	if (i < 0 || i >= num_elements)
	{
		throw std::out_of_range("The input index is out of bounds");
	}
	elements[i] = x;
}

void dynamic_array::insert_at(int i, int x)
{
	if (i < 0 || i > num_elements)
	{
		throw std::out_of_range("The input index is out of bounds");
	}
	if (num_elements == array_size)
	{
		resize(array_size ? 2 * array_size : 1); // If array_size is 0, set it to 1
	}
	for (int j = num_elements - 1; j >= i; --j) // Shift elements to the right
	{
		elements[j + 1] = elements[j];
	}
	elements[i] = x;
	++num_elements;
}

void dynamic_array::delete_at(int i)
{
	if (i < 0 || i >= num_elements)
	{
		throw std::out_of_range("Delete at index failed due to being out of bounds");
	}
	for (int j = i; j < num_elements - 1; ++j) // Shift elements to the left
	{
		elements[j] = elements[j + 1];
	}
	--num_elements;
	if (num_elements < array_size / 4) // Resize if the array is 1/4 full
	{
		resize(array_size / 2);
	}
}

void dynamic_array::insert_first(int x)
{
	insert_at(0, x);
}

void dynamic_array::insert_last(int x)
{
	insert_at(num_elements, x);
}

void dynamic_array::delete_first()
{
	delete_at(0);
}

void dynamic_array::delete_last()
{
	delete_at(num_elements - 1);
}

void dynamic_array::print_all() const
{
	std::cout << "Size: " << array_size << ", Elements: ";
	for (int i = 0; i < num_elements; ++i)
	{
		std::cout << elements[i] << " ";
	}
	std::cout << std::endl;
}