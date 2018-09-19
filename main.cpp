#include <iostream>
using namespace std;
void nextMove (int [8][8]);
int main() {
    int board [8][8] ={0};
    board[0][0]=1;
    nextMove(board);
    return 0;
}
void nextMove (int myboard[8][8])
{
    int max=0;
    int x=0;
    int y=0;
    for (int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            if (myboard[i][j]>max)
            {
                max = myboard[i][j];
                x=i;
                y=j;
            }
        }
    }
    if (max>63)
    {
        for(int i=0; i<8; i++)
        {
            for(int j=0; j<8; j++)
            {
                cout<<"\t"<<myboard[i][j];
            }
            cout<<endl<<endl;
        }
        exit(0);
    }

    for(int i=0; i<8; i++)
    {
        for(int j=0; j<8; j++)
        {
            if((myboard[i][j]==0)&& ((x-i)*(x-i)+(y-j)*(y-j)==5) )
            {
                myboard[i][j]=max+1;
                nextMove(myboard);
                myboard[i][j]=0;
            }
        }
    }
}