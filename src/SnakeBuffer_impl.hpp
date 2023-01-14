#include "SnakeBuffer.hpp"
#include <limits>

template<typename T>
SnakeBuffer<T>::SnakeBuffer(std::size_t maxSize) {
    buffer.resize(maxSize);
}

template<typename T>
T &SnakeBuffer<T>::at(size_t pos) {
    return buffer[(head + pos) % buffer.size()];
}

template<typename T>
const T &SnakeBuffer<T>::at(size_t pos) const {
    if (buffer.size())
        return buffer[(head + pos) % buffer.size()];
}

template<typename T>
T SnakeBuffer<T>::push_front(const T &object) {
    head = (head + 1) % buffer.size();
    T result = buffer.at(head);
    buffer.at(head) = object;

    return result;
}

template<typename T>
size_t SnakeBuffer<T>::size() const {
    return buffer.size();
}

template<typename T>
void SnakeBuffer<T>::resize(size_t newSize) {
    if (newSize == size()) {
        // NO-OP, short circuiting operation
    } else if (newSize > size()) {
        int originalSize = size();
        buffer.insert(buffer.cbegin() + (absolute()), newSize - size(), T());
        // If we are in the last position (usual when length = 1), then the elements are created at the beginning,
        // add to the head the added count.
        if (head == originalSize - 1) {
            head += newSize - originalSize;
        }

        if (at(0) == T()) {
            volatile int test = 0;
        }
    } else {
        int deleteCount = size() - newSize;
        int decal = head + 1 + deleteCount - size();

        buffer.erase(buffer.cbegin() + head + 1, buffer.cbegin() + head + 1 + (deleteCount - std::max(decal, 0)));

        if (decal > 0) {
            buffer.erase(buffer.cbegin(), buffer.cbegin() + decal);
            head -= decal;
        }

    }
}

template<typename T>
size_t SnakeBuffer<T>::absolute() { return (this->head + 1) % this->buffer.size(); }

template<typename T>
T &SnakeBuffer<T>::at_head() {
    return at(0);
}

template<typename T>
const T &SnakeBuffer<T>::at_head() const {
    return at(0);
}

template<typename T>
size_t SnakeBuffer<T>::find(const T &other) const {
    // std::find was not usable because of the std::distance not being seen
    for (size_t i = 0; i < size(); ++i) {
        // We use a reverse index, so we are counting from the head instead
        // of the last section of the tail.
        if (at(size() - i) == other) {
            return i;
        }
    }

    return std::numeric_limits<size_t>::max();
}