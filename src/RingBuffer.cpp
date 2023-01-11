#include "RingBuffer.h"

template<typename T>
RingBuffer<T>::RingBuffer(std::size_t maxSize) {
    buffer.resize(maxSize);
}

template<typename T>
T& RingBuffer<T>::at(size_t pos) const {
    return buffer[(head + pos) % buffer.size()];
}

template<typename T>
T& RingBuffer<T>::push_front(const T& object) {
    head = (head + 1) % buffer.size();

    T& result = buffer[head];
    result[head] = object;

    return result;
}

template<typename T>
size_t RingBuffer<T>::size() const {
    return buffer.size();
}

template<typename T>
void RingBuffer<T>::resize(size_t newSize) {

    if (newSize > size()) {
        buffer.insert((head + 1) % buffer.size(), newSize - size(), T());
    } else {

    }
}