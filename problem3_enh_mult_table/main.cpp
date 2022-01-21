////////////////////////////////////////////////////////////////////////////////
/// \file
/// \brief      Main module for Problem 3: "Enhanced Multiplication Table".
/// \author     Sergey Shershakov
/// \version    0.1.0
/// \date       19.01.2021
///             This code is for educational purposes of the course "Introduction
///             to programming" provided by the Faculty of Computer Science
///             at the Higher School of Economics.
///
/// Modification of the Problem 2 (Multiplication Table), where a user can
/// repeat a solution multiple times (with using the “do..while” loop).
///
////////////////////////////////////////////////////////////////////////////////


// установить bash в терминал

#include <iostream>
using namespace std;

const int ERR_CODE_BAD_INPUT = 1;

int main()
{
    int q = 1;
    do
    {
        cout << "Input two integers 1 <= (m, n) <= 8: ";

        unsigned int m, n;
        cin >> m >> n;

        if(!(m >= 1 && m <= 8))
        {
            cerr << "Invalid input" << endl;
            return ERR_CODE_BAD_INPUT;
        }

        if(!(n >= 1 && n <= 8))
        {
            cerr << "Invalid input" << endl;
            return ERR_CODE_BAD_INPUT;
        }

        for(size_t i = 0; i <= m; i++)
        {
            for(size_t j = 0; j <= n; j++)
            {
                cout << i * j << "\t";
            }
            cout << endl;
        }

        do
        {
            if(q == 1)
            {
            cout << "If you want to continue, press 1; else 0: ";
            cin >> q;
            }
            else
            {
                cout << "Incorrect input, please press 1 or 0: ";
                cin >> q;
            }
        } while(q != 1 && q != 0);

    } while(q == 1);


    return 0;
}
