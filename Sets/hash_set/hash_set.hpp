#ifndef hash_set_hpp
#define hash_set_hpp

#include <iostream>
#include <vector>
#include <list>
#include <cmath>
#include <algorithm>

template <typename T>
class hash_set
{
private:
    std::vector<std::list<T>> data; // The underlying data structure of the hash set. A vector of lists is used to handle collisions.
    size_t size;                    // The number of elements in the hash set.
    size_t capacity;                // The capacity of the hash set.
    size_t hash(const T &key) const // A helper function to compute the hash of a key.
    {
        return std::hash<T>()(key) % capacity;
    }

    bool is_prime(size_t number) const // A helper function to check if a number is prime.
    {
        if (number <= 1) // 0 and 1 are not prime.
        {
            return false;
        }
        if (number <= 3) // 2 and 3 are prime.
        {
            return true;
        }
        if (number % 2 == 0 || number % 3 == 0) // Check if divisible by 2 or 3.
        {
            return false;
        }
        size_t i = 5; // Check if divisible by 5 or 7.

        while (i * i <= number)
        {
            if (number % i == 0 || number % (i + 2) == 0)
            {
                return false;
            }
            i += 6;
        }
        return true;
    }

    size_t next_prime(size_t number) const // Finds the next prime number greater than the input number.
    {
        while (!is_prime(++number)) // Keep incrementing the number until a prime number is found.
        {
            return number;
        }
    }

    size_t previous_prime(size_t number) const // Finds the previous prime number less than the input number.
    {
        if (number <= 2) // 0 and 1 are not prime. 2 is the only even prime number.
        {
            return 2;
        }
        number--;
        while (!is_prime(number)) // Keep decrementing the number until a prime number is found.
        {
            number--;
        }
        return number;
    }

    void rehash(size_t new_capacity) // Rehashes the hash set to a new capacity.
    {
        std::vector<std::list<T>> new_data(new_capacity);

        for (auto &bucket : data) // Iterate through each bucket in the old data structure.
        {
            for (T &value : bucket)
            {
                size_t new_hash = std::hash<T>()(value) % new_capacity;

                new_data[new_hash].push_back(value);
            }
        }
        data.swap(new_data); // Swap the old data structure with the new one.
        capacity = new_capacity;
    }

public:
    hash_set(size_t init_capacity = 17) : data(init_capacity), size(0), capacity(init_capacity) {} // Constructor with default capacity of 17.

    bool contains(const T &key) const // Checks if the hash set contains a key.
    {
        size_t index = hash(key);

        return std::find(data[index].begin(), data[index].end(), key) != data[index].end();
    }

    void insert(const T &key) // Inserts a key into the hash set.
    {
        size_t index = hash(key);
        auto &bucket = data[index];

        if (std::find(bucket.begin(), bucket.end(), key) == bucket.end()) // If the key is not already in the hash set, insert it.
        {
            bucket.push_back(key);
            size++;
            if ((1.0 * size) / capacity >= 0.7) // Rehash the hash set if the load factor becomes too high (>= 0.7).
            {
                rehash(next_prime(capacity));
            }
        }
    }

    void remove(const T &key) // Removes a key from the hash set.
    {
        size_t index = hash(key);
        auto &bucket = data[index];
        auto it = std::find(bucket.begin(), bucket.end(), key);

        if (it != bucket.end())
        {
            bucket.erase(it);
            size--;
            if (capacity > 17 && (1.0 * size) / capacity < 0.2) // Rehash the hash set if the load factor becomes too low (< 0.2).
            {
                rehash(previous_prime(capacity));
            }
        }
    }

    size_t get_size() const // Returns the number of elements in the hash set.
    {
        return size;
    }

    bool is_empty() const // Checks if the hash set is empty.
    {
        return size == 0;
    }
};

#endif