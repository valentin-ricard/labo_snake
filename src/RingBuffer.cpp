#include "RingBuffer.h"

template<typename T>
RingBuffer<T>::RingBuffer(std::size_t maxSize) : MAX_SIZE(maxSize) {
    buffer.reserve(maxSize);
}

template<typename T>
T& RingBuffer<T>::get() const {
    return buffer[head];
}

template<typename T>
T& RingBuffer<T>::at(size_t pos) const {
    return buffer[(head + pos) % buffer.size()];
}

template<typename T>
T& RingBuffer<T>::pop_last() {
    T& result = buffer.erase(buffer.size() - 1);
    return result;
}

template<typename T>
T& RingBuffer<T>::push_front(const T& object) {

    T& result = buffer[head];

    if(buffer.size() == MAX_SIZE)
        buffer[head] == object;

    head = (head + 1) % MAX_SIZE;

    return head;
}

template<typename T>
void RingBuffer<T>::clear() {
    buffer.clear();
    head = 0;
}

template<typename T>
bool RingBuffer<T>::empty() const {
    return buffer.empty();
}

template<typename T>
size_t RingBuffer<T>::size() const {
    return buffer.size();
}