#include <iostream>

int main()
{
    int lastN = 0; 
    int currentN = 1;
    int newN = 0;
    int counter;
    int i = 1;
    std::cout << "Input N\n";
    std::cin >> counter;

    while (counter > 0)
    {
       std::cout << "num" << " " << i << " : " << newN << " \n";
        lastN = currentN;
        currentN = newN; 
        newN= lastN + currentN;  
        i++;
        counter--;     
    }
    return 1;
}