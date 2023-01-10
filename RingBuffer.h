//
// Created by arthu on 10.01.2023.
//

#ifndef LABO_SDL_RINGBUFFER_H
#define LABO_SDL_RINGBUFFER_H

#include <vector>

template<typename T>
class RingBuffer {

private:
    std::vector<T> buffer = std::vector<T>();
    size_t head = 0;
    const size_t MAX_SIZE;

public:
    RingBuffer(std::size_t maxSize);
    T& get() const;
    T& at(size_t pos) const;
    T& pop_last();
    T& push_front(const T& object);
    void clear();
    bool empty() const;
    size_t size() const;
};

#endif //LABO_SDL_RINGBUFFER_H
