#include <iostream>
#include <cstring>
using namespace std;

// N x N 這邊要改成1~6
#define N 5

// 騎士的走的步數
int row[8] = {  -2, -1, 1, 2, 2, 1, -1, -2 };
int col[8] = {  1, 2, 2, 1, -1, -2, -2, -1 };

// 判斷是否可走 
bool isValid(int x, int y, int board[N][N])
{
    return ( x >= 0 && x < N && y >= 0 &&   y < N && board[x][y] == -1);
}

// 印出棋盤 
void printMap(int board[N][N])
{
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf(" %2d ", board[i][j]+1); //0起算，因此+1 
        printf("\n");
    }
}

// 傳入的參數為騎士的下一個位置，step為下一步，在step>=N*N時剛好可以return true  
int walk(int x, int y,   int board[N][N], int step)
{
	// k:騎士有幾種走法 newX,newY:騎士之後的位置 
    int k, newX, newY;
    if (step >= N * N) //邊界條件 
        return true;

    for (k = 0; k < 8; k++) {
        newX = x + row[k];
        newY = y + col[k];
        if (isValid(newX, newY, board)) {
            board[newX][newY] = step; //填入第幾步 
            if (walk(newX, newY, board, step + 1) == true) // return true的時候，代表已經走完board 
                return true;
            else
                board[newX][newY] = -1; //還原 
        }
    }

    return false;
}

int main()
{
    int board[N][N];

    memset(board, -1, sizeof board); //之所以用-1，是為了0起算，因為walk的參數為下一步 
	board[0][0] = 0;//需要先給第一個位置 
    if (walk(0, 0, board, 1) == false) {
        printf("Solution does not exist");
        return false;
    } else
        printMap(board);

    return 0;
}
