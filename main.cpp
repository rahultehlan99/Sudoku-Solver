#include<bits/stdc++.h>
using namespace std;

// function for checking if we can place value(val) at given row(r),col(c)
bool issafe(vector<vector<int>>& sudoku,int r,int c,int val)
{
    for(int i=0;i<9;i++)
    {
        // if we find val in given row or column return false

        // checks for val in row
        if(sudoku[i][c]==val)
        return false;

        // checks for val in column
        if(sudoku[r][i]==val)
        return false;
    }

    // rowStart and colStart represents the starting indexes for the box which contains row(r) and col(c)
    int rowStart = (r/3)*3;
    int colStart = (c/3)*3;

    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if(sudoku[rowStart+i][colStart+j]==val)
            return false;
        }
    }

    return true;
}

bool solveSudoku(vector<vector<int>>& sudoku)
{
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            // if given cell is empty
            if(sudoku[i][j]==0)
            {
                // check by putting every value from (1-9) int the cell
                for(int k=1;k<=9;k++)
                {
                    if(issafe(sudoku,i,j,k))
                    {
                        // if it is possible to place val=k at given cell, place it
                        sudoku[i][j]=k;

                        // recur for the next empty cell
                        if(solveSudoku(sudoku))
                            return true;

                        // the given value of k is incorrect, make the cell empty again
                        sudoku[i][j]=0;
                    }
                }

                // backtrack
                return false;
            }
        }
    }

    // the sudoku is completed
    return true;
}

int main(){

    vector<vector<int>> sudoku = {{0,0,0,0,0,0,0,0,0},
                                  {1,0,0,0,7,0,9,0,0},
                                  {0,3,0,0,4,0,0,0,6},
                                  {2,0,0,0,0,0,0,0,5},
                                  {9,0,0,0,6,0,0,0,7},
                                  {0,0,1,0,5,7,0,0,3},
                                  {0,0,2,4,0,0,6,0,0},
                                  {4,0,0,0,1,0,8,0,0},
                                  {0,0,0,5,0,2,0,0,0}
                                  };

    // function for solving sudoku
    solveSudoku(sudoku);

    // print soduku solution
    for(auto i:sudoku)
    {
        for(auto j:i)
        cout<<j<<" ";
        cout<<'\n';
    }

    return 0;
}
