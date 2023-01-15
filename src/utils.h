//---------------------------------------------------------
// File           : utils.h
// Author(s)      : Valentin Ricard & Arthur Menétrey
// Course         : PRG1-E
// Date           : 2023-01-12
// Objective      : Implementation of a toolbox reused across projects.
// Modifications  :
//   2023-01-12 / vri - Translation of the header and implementation in english
// Remarks        : This file contains reusable methods that can be used across
//                  multiple projects
//---------------------------------------------------------


#ifndef LABO_ROBOT_UTILS_H
#define LABO_ROBOT_UTILS_H

// Note: Necessary includes for the definitions in this file
#include <iostream> //cout
#include <string>   //class string
#include <vector>   //class vector
#include <random>   //default_random_engine
#include <chrono>   //chrono::system_clock::now().time_since_epoch().count()

/**
 * Generate a random number between 0 and n exclusive
 *
 * @param max Upper limit
 * @return Lower limit
 *
 * @note The implementation is in the header to support generics.
 */
template<typename T>
T randomNumber(T max) {
    // Implementation inspired by
    // - https://cplusplus.com/reference/random/linear_congruential_engine/linear_congruential_engine/ for the seed definition
    // - https://cplusplus.com/reference/random/ for the uniform distribution

    // We are using static avoiding re-instanciation of the random generator
    static std::default_random_engine random((unsigned long) std::chrono::system_clock::now().time_since_epoch().count());
    // Decrementing the max value for consistency with other programming languages which enables
    // randomNumber(vector.size())
    std::uniform_int_distribution<T> distribution(0, max - 1);
    return distribution(random);
}

/**
 * Create a vector containing distinct values from 1 to `lenght`-1
 * in a random order
 *
 * @param length of the desired vector
 *
 * @returns Vector of distinct numbers in a random order
 */
std::vector<size_t> randomOrder(size_t length);


/**
 * Realise une input d'utilisateur avec contrôle de limite
 *
 * @param invitMessage Input message
 * @param errorMessage Error message if out of bounds
 * @param lowerLimit Input lower limit
 * @param upperLimit Input upper limit
 * @return
 */
int input(const std::string &invitMessage, const std::string &errorMessage,
          int lowerLimit, int upperLimit);

#endif //LABO_ROBOT_UTILS_H
