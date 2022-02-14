////////////////////////////////////////////////////////////////////////////////
/// \file
/// \brief      Main module for Problem 2: Titanic.
/// \author     Georgii Zhulikov
/// \author     Sergey Shershakov
/// \version    0.1.0
/// \date       01.02.2021
///             This code is for educational purposes of the course "Introduction
///             to programming" provided by the Faculty of Computer Science
///             at the Higher School of Economics.
///
/// 1) Define an alias VecStrings for the std::vector<std::string> datatype
/// using the typedef keyword.
///
/// 2) Create a function called toCountSurvived that obtains an input stream
/// object (given by reference) istream& (input.csv), reads the whole file
/// line by line and saves surnames ("Braund; Mr. Owen Harris" will be just
/// "Braund") of survived people from input.csv (Survived column).
/// The function returns data of type VecStrings -- vector of surnames of survivors.
///
/// Use intermediate functions in task 2 to do the following:
/// 2.1) Extract data (surname and whether the person survived or not) from one line of input.
/// 2.2) Extract surname from a string containing full name.
/// 
///
/// 3) Create a function printVec.
/// The function prints the content of the given vector out to the standard output.
/// It should takes a vector as argument by reference and print the value of the 
/// elements as well as their enumeration.
/// 1) Name_1
/// 2) Name_2
/// ...
/// N) Name_n
///
///
///
/// 4) Create a function called getFareForClass that takes an input stream object
/// istream& and an integer number representing class (Pclass, 1 to 3), reads the stream 
/// until the end and returns the mean fare value of people of the given class.
/// The function returns a single value of type double -- the mean fair value.
/// Use at least two intermediate functions in problem 4.
///
///
/// Additional problems
///
/// 5) Create a function called genThreeDigitNumber(const int& randomState).
/// The function returns a random three digit number as std::string.
/// Use:
/// std::mt19937 gen(randomState);
/// std::uniform_int_distribution<int> distr(0,9);
/// int rNum = distr(gen); // random number
///
/// 6) Create a new vector newVec as VecStrings and fill it with random numbers.
/// newVec size should be the same as the size of the vector obtained from toCountSurvived
///
///
///   Workshop 8
///
/// 6) Reverse the vector containing names of surviving passengers using std::reverse.
/// Sort this vector using std::sort
/// Include library <algorithm> to access these functions.
///
/// 7) Implement a function printVecIter that takes two vector iterators as arguments
/// and prints the elements of the underlying vector. The iterators should represent
/// the start and the end of the vector.
///
/// 8) Use a regular iterator and a reverse iterator (.rbegin()) to print the vector 
/// containing survivor names in a straightforward order and in a reverse order
/// with the function printVecIter.
/// 
/// 9) Using the sorted list of surnames find the first and last surname that starts with
/// the letter "H".
/// Create a new vector and use functions std::find and std::copy to copy all surnames
/// starting with "H" into it.
///
////////////////////////////////////////////////////////////////////////////////


#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <random>
#include <algorithm>
#include <cstdlib> // atof and strtod
#include <algorithm>
#include <typeinfo>


//typedef std::vector<std::string> VecStrings;
using VecStrings = std::vector<std::string>;
using VecDouble = std::vector<double_t>;


bool isPersonAlive(const std::string& line, std::string& surname);
void printVec(const VecStrings& strVec);
VecStrings toCountSurvived(std::istream& input_file);
std::string checkClass(const std::string& line, std::string& fare);
VecDouble vecFare(std::istream& input_file, const std::string& pasClass);
double getFareForClass(std::istream& input_file, const std::string& pasClass);
void printDoubleVec(const VecDouble& strVec);
std::string genThreeDigitNumber(int& randomState);
VecStrings createRandomNumVec(std::istream& input_file);


//tests
void testIsPersonAlive();
void testToCountSurvived(std::istream& input_file);
void testPrintVec();
void testCheckClass();
void testPrintVec2(std::istream& ss);


int main ()
{
    const std::string INP_FILE_NAME = "../../../data/problem2_titanic/titanic.csv";
    std::ifstream input_file;   // can read only from the file
    input_file.open(INP_FILE_NAME);

    //toCountSurvived(input_file);
    //testPrintVec2(input_file);
    //testCheckClass();

//    std::string b = "1";
//    std::cout << getFareForClass(input_file, b);

//    createRandomNumVec(input_file);

    return 0;
}


VecStrings createRandomNumVec(std::istream& input_file)
{
    size_t sizeOfFile = toCountSurvived(input_file).size();
    std::vector<std::string> strVec;
    for (int i = 0; i < sizeOfFile; ++i)
    {
        int randomState = i;
        strVec.push_back(genThreeDigitNumber(randomState));
    }


    std::reverse(strVec.begin(),strVec.end()); // reversing the vector
    std::sort(strVec.begin(), strVec.end()); // sorting the vector from the least to the highest number

//    printVec(strVec);

    return strVec;
}


std::string genThreeDigitNumber(int& randomState)
{
    std::string s;
    std::mt19937 gen(randomState);
    std::uniform_int_distribution<int> distr(0,9);

    for (int i = 0; i < 3; ++i)
        s += std::to_string(distr(gen));

    return s;
}


double getFareForClass(std::istream& input_file, const std::string& pasClass)
{
    double i = 0;
    double sum = 0;
    double meanFear = 0;
    std::vector<std::double_t> dubVec = vecFare(input_file, pasClass);
    for (VecDouble::const_reference s : dubVec)
    {
        i++;
        sum += s;
    }
    if (i != 0)
    {
        meanFear = sum / i;
    }
    return meanFear;
}


VecDouble vecFare(std::istream& input_file, const std::string& pasClass)
{
    std::vector<std::double_t> strVec;
    std::string line;
    std::string fare;
    while (input_file && !input_file.eof())
    {
        std::getline(input_file, line);
        if (checkClass(line, fare) == pasClass)
        {
            double fareDouble = strtod(fare.c_str(), nullptr); // == atof(fare.c_str())
            strVec.push_back(fareDouble);
        }
    }
    return strVec;
}


VecStrings toCountSurvived(std::istream& input_file)
{
    std::vector<std::string> strVec;
    while (input_file && !input_file.eof())
    {
        std::string forVec;
        std::string surname;
        std::getline(input_file, forVec);
        if (isPersonAlive(forVec, surname))
        {
            strVec.push_back(surname);
        }
    }
    return strVec;
}


void printVec(const VecStrings& strVec)
{
    unsigned long i = 1;
    for (VecStrings::const_reference s : strVec)
    {
        std::cout << i << ") " << s << std::endl;
        i++;
    }
}


void printDoubleVec(const VecDouble& strVec)
{
    unsigned long i = 1;
    for (VecDouble ::const_reference s : strVec)
    {
        std::cout << i << ") " << s << std::endl;
        i++;
    }
}


bool isPersonAlive(const std::string& line, std::string& surname)
{
    std::stringstream ss(line);
    std::string data;

    std::getline(ss, data, ',');
    std::getline(ss, data, ',');
    bool survivedStatus = (data == "1");

    std::getline(ss, data, ',');
    std::getline(ss, data, ';');
    surname = data;

    return survivedStatus;
}


std::string checkClass(const std::string& line, std::string& fare)
{
    std::stringstream ss(line);
    std::string data;
    std::string pasClass;


    std::getline(ss, data, ',');
    std::getline(ss, data, ',');
    std::getline(ss, data, ',');
    pasClass = data;

    std::getline(ss, data, ',');
    std::getline(ss, data, ',');
    std::getline(ss, data, ',');
    std::getline(ss, data, ',');
    std::getline(ss, data, ',');
    std::getline(ss, data, ',');
    std::getline(ss, data, ',');
    fare = data;

    return pasClass;
}


//void testIsPersonAlive()
//{
//    std::string s = "1,0,3,Braund; Mr. Owen Harris,male,22,1,0,A/5 21171,7.25,,S";
//    isPersonAlive(s);
//}

//void testPrintVec()
//{
//    std::vector<std::string> v = {"Braund", "Harris"};
//    printVec(v);
//}

//void testToCountSurvived(std::istream& input_file)
//{
////    std::string input_file = "1, 1, 2, jiih; rv\n"
////                             "1, 0, 1, uihih;fyt\n"
////                             "1, 1, 1, hukhu;  t\n";
////    std::stringstream ss;
////    ss << input_file;
////    toCountSurvived(ss);
//    toCountSurvived(input_file);
//}


//void testCheckClass()
//{
//    std::string s = "1,0,3,Braund; Mr. Owen Harris,male,22,1,0,A/5 21171,7.25,,S";
//    std::string fare;
//    std::string pasClass = checkClass(s, fare);
//    std::cout << pasClass << " " << fare;
//}


//void testPrintVec2(std::istream& ss)
//{
//    printVec(toCountSurvived(ss));
//}