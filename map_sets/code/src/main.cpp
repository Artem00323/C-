#include <iostream>
#include <vector>
#include <random>
#include <ctime>


using VecStrings = std::vector<std::string>;


void printVec(const VecStrings& strVec);
VecStrings createRandomNumVec(int n, int r, int q);


int main()
{
    int n;
    int r;
    int q;
    std::cin >> n >> r >> q;

    printVec(createRandomNumVec(n, r, q));

    return 0;
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


VecStrings createRandomNumVec(int n, int r, int q)
{
    std::vector<std::string> strVec;
    std::string s;
    std::mt19937 gen(time(0));
    std::uniform_int_distribution<int> distr(r, q);

    for (int i = 0; i < n; ++i)
    {
        strVec.push_back(std::to_string(distr(gen)));
    }


    return strVec;
}
