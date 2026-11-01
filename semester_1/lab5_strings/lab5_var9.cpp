#include <iostream>
#include <string>
#include <map>

bool StringChecker(std::string& a, std::string& b)
{
    std::map<char, int> arrSv;
    for (const unsigned char& c : a)
    {
        if (isalpha(c))
        {
            char lowL = tolower(c);
            arrSv[lowL]++; 
        }
    }

    for (const unsigned char& c : b)
    {
        if (isalpha(c))
        {
            char lowL = tolower(c);
            arrSv[lowL]--;
        }
    }
    for (const auto& pair : arrSv)
    {
        if (pair.second != 0)
            return false;
    }
    return true;
}
int main()
{
    std::string a, b;
    std::cout << "Input first string: ";
    getline(std::cin, a);
    std::cout << "Input second string: ";
    getline(std::cin, b);

    if (StringChecker(a,b))
        std::cout << "it is anagrama" << std::endl;
    else
        std::cout << "it isn`t anagrama" << std::endl;

    return 0;
}