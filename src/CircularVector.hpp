//---------------------------------------------------------
// Fichier        : CircularVector.hpp
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

#ifndef LABO_SDL_CIRCULARVECTOR_HPP
#define LABO_SDL_CIRCULARVECTOR_HPP

#include <vector>   //Vector definition
#include <limits>   //Size_t numeric limit

/**
 * Custom datastructure useful for cycling pattern.
 * The implementation depends on an underlying std::vector<T> and a head cursor.
 * @tparam T The type of the elements of the vector
 */
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

    /**
     * Creates a new instance of the CircularVector
     *
     * @param size the initial size
     */
    CircularVector(std::size_t size);

    /**
     * Gets the element at the specified position (relative to the head)
     * @param pos The position of the element wanted
     * @return a mutable reference to the element
     */
    T &at(size_t pos);

    /**
     * Gets the element at the specified position (relative to the head)
     * @param pos The position of the element wanted
     * @return a const reference to the element
     */
    const T &at(size_t pos) const;

    /**
     * Gets the element at the head
     * @return A mutable reference to the element at the head position
     *
     * @see CircularBuffer<T>::at(0)
     */
    T &at_head();

    /**
     * Gets the element at the head
     *
     * @return A constant reference to the element at the head position
     *
     * @see CircularBuffer<T>::at(0)
     */
    const T &at_head() const;

    /**
     * Push an element to the front, overwriting the last element if the size was reached.
     * @param object The object to push at the front
     * @return A copy of the overwritten element
     */
    T push_front(const T &object);

    /**
     * Gets the size of the CircularVector
     * @return The size of the circular vector.
     */
    size_t size() const;

    /**
     * Resizes the CircularVector to the size wanted.
     * If the size is reduced, the last elements are removed.
     * @param newSize The new target size.
     */
    void resize(size_t newSize);

    /**
     * Finds the wanted element in the vector.
     * @return The index of the element (relative to the head) if found, CircularVector<T>::NO_MATCH if not.
     */
    size_t find(const T &other) const;

    /**
     * Overrides the = operator to manages changes.
     * @param other The other object to assign.
     * @return A reference to this element.
     *
     * @note For some reason, without this override, the internal buffer isn't copied over, and becomes empty.
     */
    CircularVector<T>& operator=(const CircularVector<T>& other);

private:
    /**
     * Increments the head by one, and wraps if reached the size.
     *
     * @return The incremented head
     *
     * @internal
     */
    size_t incrementHead();

};

#include "CircularVector_impl.hpp"

#endif //LABO_SDL_CIRCULARVECTOR_HPP
