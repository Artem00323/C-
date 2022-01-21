////////////////////////////////////////////////////////////////////////////////
/// \file
/// \brief      Main module for Problem 1: "Hello, %username%".
/// \author     Sergey Shershakov
/// \version    0.1.0
/// \date       19.01.2021
///             This code is for educational purposes of the course "Introduction
///             to programming" provided by the Faculty of Computer Science
///             at the Higher School of Economics.
///
/// Program asks a user for their name and then outputs "Hello, <user>",
/// where <user> is the name the user.
///
////////////////////////////////////////////////////////////////////////////////

#include <iostream>
//using namespace std;

int main()
{
    std::string userName;
    std::string age;

    std::cout << "your name and surename with space: ";
    std::getline(std::cin, userName);

    std::cout << "your age: ";
    std::cin >> age;

    std::cout << "Hello, " << userName << ", " << age << std::endl;

    return 0;
}

void foo()
{

}
