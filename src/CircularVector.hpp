#ifndef LABO_SDL_CIRCULARVECTOR_HPP
#define LABO_SDL_CIRCULARVECTOR_HPP

#include <vector>
#include <limits>

template<typename T>
class CircularVector {

private:
    std::vector<T> buffer = std::vector<T>();
    size_t head = -1;

public:
    /**
     * Used in CircularVector<T>::find() to represent the absence of the element
     */
    static constexpr size_t NO_MATCH = std::numeric_limits<size_t>::max();

    CircularVector(std::size_t maxSize);

    T &at(size_t pos);

    const T &at(size_t pos) const;

    T &at_head();

    const T &at_head() const;

    T push_front(const T &object);

    size_t size() const;

    void resize(size_t newSize);

    size_t find(const T &other) const;

    size_t absolute();

    CircularVector<T>& operator=(const CircularVector<T>& other);
};

#include "CircularVector_impl.hpp"

#endif //LABO_SDL_CIRCULARVECTOR_HPP
