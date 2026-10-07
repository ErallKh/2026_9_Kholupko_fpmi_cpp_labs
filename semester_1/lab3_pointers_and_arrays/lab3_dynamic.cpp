#include <iostream>
#include <random>
#include <cmath>

using std::cin;
using std::cout;
using std::endl;

std::mt19937 gen(45218965);
int RandomNumber(int a, int b)
{
    if (a > b)
    {
        cout << "Error";
        std::exit(1);
    }
    
    int outNum = 0;
    std::uniform_int_distribution<int> dist(a, b);
    outNum = dist(gen);
    return outNum;
}
int InputNumsInMassive()
{
    int outNum;
    cout << "Input N(count of nums in vector)" << endl;
    cin >> outNum;
    if (outNum <= 0)
    {
        cout << "Error";
        std::exit(1);
    }
    
    return outNum;
}
void OutputVectZ(double* vectZ, int n)
{
    for(int i = 0; i < n; i++)
        cout << vectZ[i] << " ";
}
void MassiveEdit(int* curMassive, int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << "input element" << " " << i << ": ";
        cin >> curMassive[i];
    }
}
void MassiveRandom(int* curMassive, int n)
{
    int a, b;
    cout << "input a,b - border for random numbers" << endl;
    cin >> a >> b;
    for(int i = 0; i < n; i++)
    {
        curMassive[i] = RandomNumber(a, b);
    }
}
void ChooseVar(int* xVect, int* yVect, int n)
{
    int k = 0;
    cout << "Input 1 for manual input, 2 for auto input" << endl;
    cin >> k;
    switch (k)
    {
    case 1:
    cout << "Input X vector" << endl;
        MassiveEdit(xVect, n);
    cout << "Input Y vector" << endl;
        MassiveEdit(yVect, n);
        break;
    case 2:
    cout << "X vector" << endl;
        MassiveRandom(xVect, n);
    cout << "Y vector" << endl;
        MassiveRandom(yVect, n);
        break;
    
    default:
    cout << "Error";
    std::exit(1);
        break;
    }
}
void NewVectorZ(double* zVect, int n)
{
    int* yVect = new int[n];
    int* xVect = new int[n];
    double vectProizved = 0;
    ChooseVar(xVect, yVect, n);
    for (int i = 0; i < n; i++)
        vectProizved += xVect[i] * yVect[i];
    if (vectProizved == 0)
    {
        cout << "Error";
        std::exit(1);
    }
    
    for(int i = 0; i < n; i++)
        zVect[i] = sqrt((xVect[i] * xVect[i]) + yVect[i]*yVect[i])/vectProizved;
    delete[] yVect;
    delete[] xVect;
    OutputVectZ(zVect, n);
}

int main()
{
    int n = InputNumsInMassive();
    double* zVect = new double[n];
    NewVectorZ(zVect, n);
    delete[] zVect;
}
