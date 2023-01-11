#ifndef LABO_SDL_RINGBUFFER_H
#define LABO_SDL_RINGBUFFER_H

#include <vector>

template<typename T>
class RingBuffer {

private:
    std::vector<T> buffer = std::vector<T>();
    size_t head = 0;

public:
    RingBuffer(std::size_t maxSize);
    T& at(size_t pos) const;
    T& push_front(const T& object);
    size_t size() const;
    void resize(size_t newSize);
};

#endif //LABO_SDL_RINGBUFFER_H
