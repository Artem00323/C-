////////////////////////////////////////////////////////////////////////////////
/// \file
/// \brief      Main module for Problem 4: "Length of a C-string (strlen)".
/// \author     Sergey Shershakov
/// \version    0.1.0
/// \date       19.01.2021
///             This code is for educational purposes of the course "Introduction
///             to programming" provided by the Faculty of Computer Science
///             at the Higher School of Economics.
///
/// Count the length of a C-style string variable initialized with a string
/// literal (implement strlen() ).
///
////////////////////////////////////////////////////////////////////////////////

// C-style string -

#include <iostream>


int main()
{
    char str[] = "mir trud"; // 9 symbols with 0 at the end (stands for the end of the sequence)
    int i = 0;

    while (str[i] != '\0')
    {
        ++i;
    }

    std::cout << i << std::endl;

    return 0;
}
