#ifndef array_deque_hpp
#define array_deque_hpp

#include <iostream>

template <typename T>
class array_deque
{
private:
    T *buffer;                            // Pointer to the dynamically allocated array that stores the deque elements.
    std::size_t capacity;                 // Capacity of the buffer.
    std::size_t head;                     // Index of the first element in the deque.
    std::size_t tail;                     // Index one past the last element in the deque.
    void resize(std::size_t new_capacity) // Helper function to resize the buffer.
    {
        T *new_buffer = new T[new_capacity]; // Allocate a new buffer of the specified capacity.
        std::size_t i = 0;

        for (std::size_t j = head; j != tail; j = (j + 1) % capacity) // Copy the elements from the old buffer to the new buffer.
        {
            new_buffer[i++] = std::move(buffer[j]);
        }
        delete[] buffer;     // Free the old buffer.
        buffer = new_buffer; // Point buffer to the new buffer.
        head = 0;
        tail = i;
        capacity = new_capacity;
    }

public:
    array_deque(std::size_t initial_capacity = 8) // Constructor to initialize the deque. Default capacity is 8.
        : capacity(initial_capacity), head(0), tail(0)
    {
        while (capacity & (capacity - 1)) // Check if the capacity is a power of 2.
        {
            capacity++;
        }
        buffer = new T[capacity];
    }

    ~array_deque()
    {
        delete[] buffer;
    }

    array_deque(const array_deque &other)
        : capacity(other.capacity), head(0), tail(other.size())
    {
        buffer = new T[capacity];
        std::copy(other.buffer + other.head, other.buffer + other.tail, buffer);
    }

    array_deque(array_deque &&other) noexcept
        : buffer(other.buffer), capacity(other.capacity), head(other.head), tail(other.tail)
    {
        other.buffer = nullptr; // Null out the other's buffer pointer.
        other.capacity = 0;
        other.head = other.tail = 0;
    }

    friend void swap(array_deque &first, array_deque &second) noexcept // Swap function for the copy-and-swap idiom.
    {
        using std::swap; // Enable ADL (Argument Dependent Lookup).
        swap(first.buffer, second.buffer);
        swap(first.capacity, second.capacity);
        swap(first.head, second.head);
        swap(first.tail, second.tail);
    }

    array_deque &operator=(array_deque other) noexcept // Assignment operator using the copy-and-swap idiom.
    {
        swap(*this, other); // Swap this object with the temporary `other`.
        return *this;
    }

    bool is_empty() const
    {
        return head == tail;
    }

    std::size_t get_size() const
    {
        if (tail >= head)
            return tail - head;
        return capacity - head + tail; // Handle wrap-around.
    }

    void push_back(const T &value)
    {
        if (((tail + 1) & (capacity - 1)) == head) // Check if a resize is necessary (if increasing tail would overlap with head).
        {
            resize(2 * capacity);
        }
        buffer[tail] = value;
        tail = (tail + 1) & (capacity - 1); // Increment tail and handle wrap-around.
    }

    void push_front(const T &value)
    {
        if (((head - 1 + capacity) & (capacity - 1)) == tail) // Check if a resize is necessary (if decreasing head would overlap with tail).
        {
            resize(2 * capacity);
        }
        head = (head - 1 + capacity) & (capacity - 1); // Decrement head and handle wrap-around.
        buffer[head] = value;
    }

    void pop_back() // Remove the last element of the deque.
    {
        if (is_empty())
        {
            throw std::out_of_range("Deque is empty");
        }
        tail = (tail - 1 + capacity) & (capacity - 1); // Decrement tail and handle wrap-around.
    }

    void pop_front() // Remove the first element of the deque.
    {
        if (is_empty())
        {
            throw std::out_of_range("Deque is empty");
        }
        head = (head + 1) & (capacity - 1); // Increment head and handle wrap-around.
    }

    T &get_front() // Get the first element of the deque.
    {
        if (is_empty())
        {
            throw std::out_of_range("Deque is empty");
        }
        return buffer[head];
    }

    T &get_back() // Get the last element of the deque.
    {
        if (is_empty())
        {
            throw std::out_of_range("Deque is empty");
        }
        return buffer[(tail - 1 + capacity) & (capacity - 1)]; // Handle wrap-around.
    }

    void print_deque() const
    {
        std::cout << "Deque Contents: ";
        for (std::size_t i = head; i != tail; i = (i + 1) % capacity)
        {
            std::cout << buffer[i] << " ";
        }
        std::cout << std::endl;
    }
};

#endif