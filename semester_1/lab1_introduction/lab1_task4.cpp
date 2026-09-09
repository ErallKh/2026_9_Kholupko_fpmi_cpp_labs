#include <iostream>

int main()
{
    using std::cout;
    using std::cin;

    int number;
    int firstN = 0;
    int secondN = 0;
    int i = 6;

    cout << "input N( 100000 - 999999 )\n";
    cin >> number;

    while (i > 0)
    {
        if(i >= 4)
        {
            firstN += number%10;
        }
        else if(i <= 3)
        {
            secondN += number%10;
        }
        i--;
        number = number/10;
    }
    if (firstN == secondN)
    {
        cout << "number is lucky";
        return 0;
    }
    else
    {
    cout << "number is not lucky";
    return 0;
    }
}  