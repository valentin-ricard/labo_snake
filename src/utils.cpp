//---------------------------------------------------------
// File           : utils.cpp
// Author(s)      : Valentin Ricard & Arthur Menétrey
// Course         : PRG1-E
// Date           : 2023-01-12
// Objective      : Implementation of a toolbox reused across projects.
// Modifications  :
//   2023-01-12 / vri - Translation of the header and implementation in english
// Remarks        : This file contains reusable methods that can be used across
//                  multiple projects
//---------------------------------------------------------

#include <string>       // std::string
#include <iostream>     // cin et cout
#include <limits>       // numeric_limits<streamsize>
#include <random>       // default_random_engine
#include <chrono>       // chrono::system_clock::now().time_since_epoch().count()
#include <numeric>      // std::iota
#include "utils.h"      // Random number generator

using namespace std; // Implicit call to the std namespace

//Clear cache and line break definition for clearer code
#define CLEAR_BUFFER_CIN cin.ignore(numeric_limits<streamsize>::max(), '\n')
#define LINE_BREAK cout << endl

vector<size_t> randomOrder(size_t length) {
    // Random engine created once per function avoiding useless init if neither function is used
    static default_random_engine random((unsigned long) chrono::system_clock::now().time_since_epoch().count());

    vector<size_t> vector(length);
    // Indexing values
    std::iota(vector.begin(), vector.end(), 0);
    shuffle(vector.begin(), vector.end(), random);

    return vector;
}

int input(const string &invitMessage, const string &errorMessage, int lowerLimit, int upperLimit) {
    int input;
    bool isError;

    do{
        // Invit message
        cout << invitMessage
             << " ["
             << lowerLimit
             << " - "
             << upperLimit
                << "] "
                << " :";

        // User input
        cin >> input;

        // Input validation
        isError = cin.fail()
                  or input < lowerLimit
                  or input > upperLimit;

        // Error ?
        if (isError) {
            // Show isError message
            cout << errorMessage << endl;
            // Fix cin buffer
            cin.clear();
        }

        //Clear input buffer
        CLEAR_BUFFER_CIN;
    }while(isError);

    //Return user input
    return input;
}