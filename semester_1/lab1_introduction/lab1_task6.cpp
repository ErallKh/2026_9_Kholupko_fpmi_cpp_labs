#include <iostream>

int main()
{
    using std::cout;
    using std::cin;
    int baseA,newA,b,d;
    cout << "Input a, b, d\n";
    cin >> baseA;
    cin >> b;
    cin >> d;
    newA = baseA;
    while(newA < b)
    {
        if (newA%3==0)
        {
            cout << newA << "\n";
        }
        newA += d;
    }
}