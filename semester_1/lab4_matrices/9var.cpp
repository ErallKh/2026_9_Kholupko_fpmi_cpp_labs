#include <iostream>
#include <random>

void ErrorFunc()
{
    std::cout << "Error";
    std::exit(1);
}

void RandomMassive(int** matrix, int a, int b, int x, int y)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(a, b);
    for(int j = 0; j < y; j++)
    {
        for(int i = 0; i < x; i++)
            matrix[i][j] = dist(gen);
    }
}
void HandleWriteMassive(int** matrix, int x, int y)
{
    for(int j = 0; j < y; j++)
    {
        for(int i = 0; i < x; i++)
        {
            int dynamic;
            std::cout << "Enter elemnt - " << i << "," << j << "-";
            std::cin >> dynamic;
            matrix[i][j] = dynamic;
        }
    }
}
void ChooserMas(int** matrix, int x, int y)
{
    int ch = 0;
    std::cout << "Choose var 0 - autoInput, 1 - manualInput" << std::endl;
    std::cin >> ch;
    switch (ch)
    {
    case 0:
    {
        int a,b;
        std::cout << "Input Border for random numbers(a, b)" << std::endl;
        std::cin >> a;
        std::cin >> b;
        if (a > b)
            ErrorFunc();
        
        RandomMassive(matrix, a, b, x, y);
        break;
    }
    case 1:
    {
        HandleWriteMassive(matrix, x, y);
        break;
    }
    
    default:
    {
    ErrorFunc();
        break;
    }
    }
}
void VivodMatrix(int** matrix, int x, int y)
{
    for(int j = 0; j < y; j++)
    {
        for(int i = 0; i < x; i++)
            std::cout << matrix[i][j] << "  ";
        
        std::cout << std::endl;
    }
}
void FinderLocalMaximum(int** matrix, int x, int y)
{

    for(int jFor = 1; jFor < (y - 1); jFor++) 
    {
        for(int iFor = 1; iFor < (x -1); iFor++)
        {
            int bufNumb = matrix[iFor][jFor];
            if ((bufNumb > matrix[iFor-1][jFor]) && (bufNumb > matrix[iFor+1][jFor]) && (bufNumb > matrix[iFor][jFor - 1]) && (bufNumb > matrix[iFor][jFor + 1]))
            {
                std::cout << bufNumb << "-is a local maximum" << std::endl; 
            }
        }
    }
}
int main()
{
    int x, y;

    std::cout << "Enter x lenght" << std::endl;
    std::cin >> x;
    if(x < 0)
        ErrorFunc();

    std::cout << "Enter y lenght" << std::endl;
    std::cin >> y;
    if (y < 0)
        ErrorFunc();
    

    int** matrix = new int*[x];
    for (int j = 0; j < x; j++)
        matrix[j] = new int[y];

    ChooserMas(matrix, x, y);
    VivodMatrix(matrix, x, y);
    FinderLocalMaximum(matrix, x ,y);
    for (int i = 0; i < x; i++)
        delete[] matrix[i];
    delete [] matrix;
    return 0;
}