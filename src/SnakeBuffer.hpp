#ifndef LABO_SDL_SNAKEBUFFER_HPP
#define LABO_SDL_SNAKEBUFFER_HPP

#include <vector>
#include <limits>

static constexpr size_t NO_MATCH = std::numeric_limits<size_t>::max();

template<typename T>
class SnakeBuffer {

private:
    std::vector<T> buffer = std::vector<T>();
    size_t head = -1;

public:
    SnakeBuffer(std::size_t maxSize);

    T &at(size_t pos);

    const T &at(size_t pos) const;

    T &at_head();

    const T &at_head() const;

    T push_front(const T &object);

    size_t size() const;

    void resize(size_t newSize);


    size_t find(const T &other) const;

    size_t absolute();
};

#include "SnakeBuffer_impl.hpp"

#endif //LABO_SDL_SNAKEBUFFER_HPP
