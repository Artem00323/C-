////////////////////////////////////////////////////////////////////////////////
/// \file
/// \brief      Main module for a Problem: String-Number conversions and
///             expensive concatenations.
/// \author     Sergey Shershakov
/// \version    0.1.0
/// \date       22.01.2022
///             This code is for educational purposes of the course "Introduction
///             to programming" provided by the Faculty of Computer Science
///             at the Higher School of Economics.
///
/// TASK DESCRIPTION
///
/// A program investigates the semantics of std::string class and performs
/// string-number conversions.
///
/// 1) Use the obsolete function atoi to convert a string representation of an
/// integer to an integer value. Then use the stoi function to do the same task.
///
/// 2) Try to apply the itoa function for form the string representation of an
/// integer number. To do this you have to allocate a c-string buffer. Use it
/// with caution!
/// Try to avoid doing this and real programs and use to_string method insted.
/// Train yourself)
///
/// 3) Use the operator+ semantics of the std::string object to concatenate few
/// strings into one big string. See how expensive it is! We obviously need to
/// find some more efficient way to do this. See next problem in the current set
/// describing a possible approach.
///
////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>           // изначально нет
#include <cstdlib>  // == stdlib.h

using std::cin;
using std::cout;
using std::string;



int main()
{
    string s1, s2;
    cin >> s1 >> s2;

    // c - style approach
    // int i = atoi(s1.c_str());
    // double d = atof(s2.c_str());

    // c++ - style approach
    int i = std::stoi(s1);
    double d = std::stod(s2);

    cout << i << d;


    // make a string representation for numbers
    s1 = std::to_string(42);
    s2 = std::to_string(3.14);

    string resStr = s1 + ", " + s2; // it works, don't use it in practice,
                                    // prefer using std::stringstream helper class instead


    return 0;
}
