#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <windows.h>
#include <cstdlib>
#include <time.h>

const int rows = 30;
const int columns = 50;

const std::string space = std::string(1, char(176)) + std::string(1, char(176));
const std::string cell = std::string(1, char(219)) + std::string(1, char(219));

void PrintGrid(std::string grid[][columns]);

int CountCells(std::string grid[][columns], int y, int x);

int main()
{
    system("cls");
    srand(time(0));
    std::string grid[rows][columns];

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            grid[i][j] = rand() % 2 == 1 ? cell : space;
        }
    }
    
    grid[rows/2][columns/2] = "88";
    PrintGrid(grid);
    std::cout<<CountCells(grid, rows/2, columns/2)<<'\n';
    system("pause");
}

void PrintGrid(std::string grid[][columns]){
    std::cout << "\033[H";
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            std::cout<<grid[i][j];
        }std::cout<<'\n';
    }
}

int CountCells(std::string grid[][columns], int y, int x){
    std::vector<std::pair<int, int>> Matrix = {
        {y-1, x-1},{y-1, x},{y-1, x+1},{y,x-1},{y,x+1},{y+1,x-1},{y+1,x},{y+1,x+1}
    };
    int count = 0;

    for(auto values : Matrix){
        int i = values.first;
        int j = values.second;

        if((i < rows and i > -1) and (j < columns and j > -1) and grid[i][j] == cell){
            count++;
        }
    }
    return count;
}