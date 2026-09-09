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
    /*int a1, a2, a3, a4;
    a1 = (int)(n / 1000); //1902 -1-
    a2 = (int)(n / 100 - a1 * 10); //1902 19-10=-9-
    a3 = (int)(n / 10 - a1 *100 - a2 * 10); //1902/10=190 - 100 -90=0
    a4 = (int)(n - a1 * 1000 - a2 *100 - a3 * 10); //1912-1000-900-10=2 
    if ((a1 == a4) && (a2 == a3))
    {
        cout << "Palindrom";
        return 0;
    }
    else
    {
        cout << "Don`t palidrom";
        return 0;
    }*/            
}

