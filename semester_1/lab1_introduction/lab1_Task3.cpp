#include <iostream>

int main()
{
    using std::cin;
    using std::cout;
    int number;
    int fakeNumber;
    int copyNumber = 0;
    int k;
    int i = 4;
    cout << "input number 1000-9999 \n";
    cin >> number;
    if ((number > 9999) || (number < 1000))
    {
        cout << "error number";
        return -1;
    }
    fakeNumber = number;
    while (i > 0)
    {
        k = number % 10; 
        number = number / 10;
        copyNumber = copyNumber * 10 + k;
        i--;
    }
    if (copyNumber == fakeNumber)
    {
        cout << "number is palindrom";
        return 1;
    }
    else
    {
        cout << "number is not palindrom";
        return 0;
    }
}

