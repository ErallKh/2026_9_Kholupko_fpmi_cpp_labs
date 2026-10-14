#include <iostream>
#include <random>

using namespace std;

const int MAX = 10000;

int RandomNumber(int a, int b)
{
    random_device rd;
    mt19937 gen(rd());
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
void NewMassiveCreator(int* numbers, int n)
{
    int positive[MAX];
    int negative[MAX];
    int indexM = 0, indexP = 0;

    for(int i = 0; i < n; i++)
    {
        if (numbers[i] >= 0)
        {
            positive[indexP] = numbers[i];
            indexP++;
        }
        else if (numbers[i] < 0)
        {
            negative[indexM] = numbers[i];
            indexM++;
        }
    }
    int minusC = 0, plusC = 0;
    while(indexM > 0)
    {
        numbers[minusC] = negative[minusC];
        indexM--;
        minusC++;
    }
    while (indexP > 0)
    {
        numbers[minusC] = positive[plusC];
        indexP--;
        minusC++;
        plusC++;
    }
}
void ChoseInputer(int* numbers, int n)
{
    int checker = 0;
    cout << "Input: 0-for random numbers; 1-for manual input numbers" << endl;
    cin >> checker;
    
     switch (checker)
    {
    case 0:
    {
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
    }
    case 1:
    {
        for (int i = 0; i < n; i++)
            numbers[i] = WriteNumber();
        break;
    }
    default:
    {
    cout << "Error";
        exit(1);
    }
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
    if (n <= 0 || n > MAX)
    {
        cout << "Error";
        exit(1);
    }
    return n;
}

int main()
{
    int n = EnterNumber();
    int numbers[MAX];
    ChoseInputer(numbers, n);
    NewMassiveCreator(numbers, n);
    Result(numbers, n);
    return 0;
}
