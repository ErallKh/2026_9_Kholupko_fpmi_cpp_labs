#include <iostream>
using namespace std;
int Vivod(string a)
{
    int b = 0;
    cout << a;
    cin >> b;
    return b;
}
void Checker(int a, int b)
{
    if ((a < 0) || (b < 0) || (a > b))
    {
        cout << "Error" << std::endl;
        exit(1);
    }
}
void PalindromFinder(int a, int b)
{
    int currentNumber = 0, checkNumber = 0;
    
    for( int i = a; i<=b; i++)
    {
        currentNumber = i;
        checkNumber = i;
        int newNumber = 0;
        while (currentNumber > 0)
        {
            newNumber = newNumber * 10 + (currentNumber % 10);
            currentNumber /= 10;
        }
        if (newNumber == checkNumber)
            cout << checkNumber << std::endl;       
    }
}
int main()
{
    int a, b;
    a = Vivod("Input positive Number for left border A :");
    b = Vivod("Input positive Number for right border B :");
    Checker(a, b);
    PalindromFinder(a, b);
    return 0;
}
