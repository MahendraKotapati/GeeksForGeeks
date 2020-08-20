#include <bits/stdc++.h>
using namespace std;
// UNASSIGNED is used for empty cells in sudoku grid 
#define UNASSIGNED 0  
// N is used for the size of Sudoku grid.  
// Size will be NxN  
#define N 9  
bool SolveSudoku(int grid[N][N]);
void printGrid(int grid[N][N]);

bool check(int grid[N][N],int i,int j)
{   
    int p,q,c=0,x,y;

    for(p=0;p<N;p++)  //   is used in column
      if(grid[i][j]==grid[i][p])
        c++;
    
    for(p=0;p<N;p++)    // is used in row
      if(grid[i][j]==grid[p][j])
        c++;
    
    if(c>2)  return false;
    
    /*x=i/3;  x*=3;
    y=j/3;  y*=3;
    */
    x=i-i%3; y=j-j%3;
    c=0;

    for(p=x;p<x+3;p++)  // used in box
    {
        for(q=y;q<y+3;q++)
            if(grid[i][j]==grid[p][q])
               c++;
    }

    if(c>1)  return false;
    
    return true;
}

bool rec(int grid[N][N],int i,int j)
{
    
    if(j>=N)  {  i++; j=0; }
    if(i>=N||j>=N)
       return true;

    int k;
    if(grid[i][j]!=0)
        return rec(grid,i,j+1);   

    for(k=1;k<=N;k++)
    {
        grid[i][j]=k;
        if(check(grid,i,j))
        {   
            if(rec(grid,i,j+1))
              return true;
            
        }
    }

    grid[i][j]=0;
    return false;
}


int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int grid[N][N];
		
		for(int i=0;i<9;i++)
		    for(int j=0;j<9;j++)
		        cin>>grid[i][j];
		
		if (SolveSudoku(grid) == true)  
            printGrid(grid);  
        else
            cout <<"No solution exists";  
        
        cout<<"\n";
	}
	
	return 0;
}

/*This is a function problem.You only need to complete the function given below*/

bool SolveSudoku(int grid[N][N])  
{ 
   /* int i,j;
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {     if(grid[i][j]==0)  continue;
              if(!check(grid,i,j))
                return false;
        }
    }
    */
    return rec(grid,0,0);  
}

void printGrid(int grid[N][N])
{
    int i,j;
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
          cout<<grid[i][j]<<" ";
        cout<<"\n";
    }
}
