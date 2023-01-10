//
// Created by arthu on 10.01.2023.
//

#ifndef LABO_SDL_CIRCULARBUFFER_H
#define LABO_SDL_CIRCULARBUFFER_H

#include <vector>

template<typename T>
class CircularBuffer {

private:
    size_t pointer;
    std::vector<T> buffer;

public:
    std::vector<T>& Buffer;
    std::vector<T>& At;
};


#endif //LABO_SDL_CIRCULARBUFFER_H
