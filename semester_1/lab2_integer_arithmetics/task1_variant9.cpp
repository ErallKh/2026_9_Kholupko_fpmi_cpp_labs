#include <iostream>

int main()
{
    using std::cin;
    using std::cout;

    int a, b;
    cout << "Input Number for left border A :";
    cin >> a;
    cout << "Input Number for right border B :";
    cin >> b;

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
    return 0;
}
