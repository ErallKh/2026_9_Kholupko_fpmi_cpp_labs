#include <iostream>
#include <random>

using namespace std;
static mt19937 gen(45218965);

int RandomNumber(int a, int b)
{
    uniform_int_distribution<int> dist(a, b);
    int outN = dist(gen);
    cout << outN << ", ";
    return outN;
}
int WriteNumber()
{
    int outN;
    cout << "Input number: "  << endl;
    cin >> outN;
    return outN;
}
int PosNum(int* numbers, int n)
{
    int outN = 0;
    for (int a = 0; a < n; a++) 
    {
        if (numbers[a] > 0)
            outN++;
    }
    return outN;
        
}
void NewMassiveCreator(int* numbers, int n)
{
    int pN = PosNum(numbers, n); 
    int mN = n - pN;
    int* positive = new int[pN];
    int* negative = new int[mN];
    int iM = 0, iP = 0;

    for(int i = 0; i < n; i++)
    {
        if (numbers[i] >= 0)
        {
            positive[iP] = numbers[i];
            iP++;
        }
        else if (numbers[i] < 0)
        {
            negative[iM] = numbers[i];
            iM++;
        }
    }
    int mC = 0, pC = 0;
    while(iM > 0)
    {
        numbers[mC] = negative[mC];
        iM--;
        mC++;
    }
    while (iP > 0)
    {
        numbers[mC] = positive[pC];
        iP--;
        mC++;
        pC++;
    }
    delete[] negative;
    delete[] positive;
}
void ChoseInputer(int* numbers, int n)
{
    int checker = 0;
    cout << "Input: 0-for random numbers; 1-for manual input numbers" << endl;
    cin >> checker;
    
     switch (checker)
    {
    case 0:
        int bl, br;
        cout << "Input left border" << endl;
        cin >> bl;
        cout << "Input right border" << endl;
        cin >> br;
        if (bl >= br)
        {
            cout << "Error";
            exit(1);
        }
        for (int i = 0; i < n; i++)
            numbers[i] = RandomNumber(bl, br);
        break;

    case 1:
        for (int i = 0; i < n; i++)
            numbers[i] = WriteNumber();
        break;
    default:
    cout << "Error";
        exit(1);
    }
}
void Result(int* numbers, int n)
{
    cout << endl;
    for (int i = 0; i < n; i++)
        cout << numbers[i] << ", ";
}
int EnterNumber()
{
    int n;
    cout << "Input count of numbers in massive:" << endl;
    cin >> n;
    if (n <= 0)
    {
        cout << "Error";
        exit(1);
    }
    return n;
}

int main()
{
    int n = EnterNumber();
    int* numbers = new int[n];
    ChoseInputer(numbers, n);
    NewMassiveCreator(numbers, n);
    Result(numbers, n);
    delete[] numbers;
    return 0;
}
