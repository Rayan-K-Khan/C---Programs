#include <iostream>
using namespace std;

bool knightTour(int arr[][8], int x, int y, int move);
bool isValid(int arr[][8], int x, int y);

int main()
{
    int board[8][8];

    for (int i = 0; i<8; i++)
    {
        for (int j = 0; j<8; j++)
        {
            board[i][j]=0;
        }
    }
	
		knightTour(board, 0, 0, 1);
		
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 8; j++)
			{
                if (board[i][j]/10==0)
                {
                    cout<<"0";
                }

				cout<<board[i][j]<<" ";
			}
			
			cout<<"\n";
		}	
}

bool knightTour(int arr[][8], int x, int y, int move)
{
        if (!isValid(arr, x, y) || arr[y][x] != 0) 
        {
            return false;
        }
    
    arr[y][x] = move;
    
    if (move == 64)
    {
        return true;
    }
    
    //down 1 left 2
    if (knightTour(arr, x-2, y+1, move+1))
    {
        return true;
    }	
    
    //down 2 left 1
    if (knightTour(arr, x-1, y+2, move+1))
    {
        return true;
    }	
    
    //down 2 right 1
    if (knightTour(arr, x+1, y+2, move+1))
    {
        return true;
    }
    
    //down 1 right 2	
    if (knightTour(arr, x+2, y+1, move+1))
    {
        return true;
    }
    
    //up 1 right 2
    if (knightTour(arr, x+2, y-1, move+1))
    {
        return true;
    }
    
    //up 2 right 1
    if (knightTour(arr, x+1, y-2, move+1))
    {
        return true;
    }
    
    //up 2 left 1
    if (knightTour(arr, x-1, y-2, move+1))
    {
        return true;
    }
    
    //up 1 left 2
    if (knightTour(arr, x-2, y-1, move+1))
    {
        return true;
    }
    
    arr[y][x]=0;
    return false;		
}

bool isValid(int arr[][8], int x, int y)
{
    return x >= 0 && x < 8 && y >= 0 && y < 8;
}	