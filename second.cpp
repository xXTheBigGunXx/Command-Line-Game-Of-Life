#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <cstdlib>
#include <ctime>
#include <windows.h>

const int rows = 40;
const int columns = 78;

const std::string space = std::string(1, char(176)) + std::string(1, char(176));
const std::string cell = std::string(1, char(219)) + std::string(1, char(219));

void PrintGrid(std::string grid[][columns]);

int CountCells(std::string grid[][columns], int y, int x);

void Change(std::string (&grid)[rows][columns]);

int main() {
    system("cls");
    srand(static_cast<unsigned>(time(0)));
    std::string grid[rows][columns];

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            grid[i][j] = rand() % 2 == 1 ? cell : space;
        }
    }

    while(true){
        PrintGrid(grid);
        Change(grid);
        Sleep(200);
    }

    system("pause");
}

void PrintGrid(std::string grid[][columns]){
    std::cout << "\033[H";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            std::cout << grid[i][j];
        }
        std::cout << '\n';
    }
}

int CountCells(std::string grid[][columns], int y, int x){
    std::vector<std::pair<int, int>> neighbors = {
        {y - 1, x - 1}, {y - 1, x}, {y - 1, x + 1},
        {y, x - 1},             {y, x + 1},
        {y + 1, x - 1}, {y + 1, x}, {y + 1, x + 1}
    };
    int count = 0;

    for (const auto& neighbor : neighbors){
        int i = neighbor.first;
        int j = neighbor.second;

        if ((i >= 0 && i < rows) && (j >= 0 && j < columns) && grid[i][j] == space){
            count++;
        }
    }
    return count;
}

void Change(std::string (&grid)[rows][columns]){
    std::string copy[rows][columns];

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            int count = CountCells(grid, i, j);

            if(grid[i][j] == space){
                if(count == 2 or count == 3){
                    copy[i][j] = space;
                }else{
                    copy[i][j] = cell;
                }
            }else{
                if(count == 3){
                    copy[i][j] = space;
                }else{
                    copy[i][j] = cell;
                }
            }
        }
    }
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < columns; j++){
            grid[i][j] = copy[i][j];
        }
    }
}