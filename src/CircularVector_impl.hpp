//---------------------------------------------------------
// Fichier        : CircularVector_impl.hpp
// Auteur(s)      : Valentin Ricard & Arthur Menétrey
// Classe         : PRG1-E
// Date           : 2023.01.15
// But            : Classe used for data storage in a circular buffer
//                  This data structure can be used for exemple for storing snakes positions
//                  in a more optimized and fluent way
//
// Modifications  : -
// Remarque(s)    : -
//---------------------------------------------------------

#include "CircularVector.hpp"   //Corresponding definition
#include <limits>               //Size_t numeric limit

template<typename T>
CircularVector<T>::CircularVector(std::size_t size) {
    buffer.resize(size);
}

template<typename T>
T &CircularVector<T>::at(size_t pos) {
    return buffer[(head + pos) % buffer.size()];
}

template<typename T>
const T &CircularVector<T>::at(size_t pos) const {
    return buffer[(head + pos) % buffer.size()];
}

template<typename T>
T CircularVector<T>::push_front(const T &object) {
    head = incrementHead();
    T result = buffer.at(head);
    buffer.at(head) = object;

    return result;
}

template<typename T>
size_t CircularVector<T>::size() const {
    return buffer.size();
}

template<typename T>
void CircularVector<T>::resize(size_t newSize) {
    if (newSize == size()) {
        // NO-OP, short circuiting operation
        return;
    }

    if (newSize > size()) {
        size_t originalSize = size();
        buffer.insert(buffer.cbegin() + ((long int) incrementHead()), newSize - size(), T());
        // If we are in the last position (usual when length = 1), then the elements are created at the beginning,
        // add to the head the added count.
        if (head == originalSize - 1) {
            head += newSize - originalSize;
        }
    } else {
        // Long long is needed to make sure it still fits
        long int deleteCount = (long int) (size() - newSize);
        long int decal = (long int) head + 1 + deleteCount - (int) size();

        buffer.erase(buffer.cbegin() + ((long int) head + 1),
                     buffer.cbegin() + ((long int) head + 1 + (deleteCount - std::max<long int>(decal, 0))));

        if (decal > 0) {
            buffer.erase(buffer.cbegin(), buffer.cbegin() + decal);
            // We are sure that decal > 0, so we can cast
            head -= (unsigned int) decal;
        }
    }
}

template<typename T>
size_t CircularVector<T>::incrementHead() {
    if (size() == 0) {
        return 0;
    }
    return (this->head + 1) % this->buffer.size();
}

template<typename T>
T &CircularVector<T>::at_head() {
    return at(0);
}

template<typename T>
const T &CircularVector<T>::at_head() const {
    return at(0);
}

template<typename T>
size_t CircularVector<T>::find(const T &other) const {
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

template<typename T>
CircularVector<T> &CircularVector<T>::operator=(const CircularVector<T> &other) {
    this->buffer = other.buffer;
    this->head = other.head;

    return *this;
}