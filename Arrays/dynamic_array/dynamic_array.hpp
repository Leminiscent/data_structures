#ifndef dynamic_array_hpp
#define dynamic_array_hpp

#include <iostream>

class dynamic_array
{
private:
	int num_elements = 0;	   // Tracks the number of actual elements in the array
	int array_size = 0;		   // Tracks the current size of the underlying storage
	int *elements;			   // Pointer to the underlying int array storage
	void resize(int new_size); // Private helper function to resize the underlying storage

public:
	dynamic_array(int n);								  // Initialize array with storage of size n
	dynamic_array(const dynamic_array &other);			  // Copy constructor
	dynamic_array &operator=(const dynamic_array &other); // Copy assignment operator
	~dynamic_array();									  // Destructor to clean up allocated memory

	int get_len() const;		  // Get the number of elements
	int get_at(int i) const;	  // Get the value at index i
	void set_at(int i, int x);	  // Set the value at index i to x
	void insert_at(int i, int x); // Insert value x at index i
	void delete_at(int i);		  // Delete value at index i
	void insert_first(int x);	  // Insert value x at the beginning
	void insert_last(int x);	  // Insert value x at the end
	void delete_first();		  // Delete the first element
	void delete_last();			  // Delete the last element
	void print_all() const;		  // Print all elements and size of the array
};

#endif