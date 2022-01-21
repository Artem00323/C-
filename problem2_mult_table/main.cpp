////////////////////////////////////////////////////////////////////////////////
/// \file
/// \brief      Main module for Problem 2: "Multiplication Table".
/// \author     Sergey Shershakov
/// \version    0.1.0
/// \date       19.01.2021
///             This code is for educational purposes of the course "Introduction
///             to programming" provided by the Faculty of Computer Science
///             at the Higher School of Economics.
///
/// Program asks a user for two numbers, 1 <= (m, n) <= 8 and prints a rectangle
/// multiplication table aligning output at tab positions.
///
////////////////////////////////////////////////////////////////////////////////
#include <iostream>
using namespace std;

int main()
{
    cout << "Input two integers 1 <= (m, n) <= 8: ";

    unsigned int m, n;
    cin >> m >> n;

    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cout << i * j << "\t";
        }
        cout << endl;
    }

    return 0;
}
