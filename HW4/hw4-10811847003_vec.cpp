#include <iostream>
#include <cstring>
#include <vector>
using namespace std;


// 騎士的走的步數
int row[8] = {  -2, -1, 1, 2, 2, 1, -1, -2 };
int col[8] = {  1, 2, 2, 1, -1, -2, -2, -1 };

// 判斷是否可走，一開始還被vector<vector<int> > 的角括號雷到，少一空格，廢到笑 
bool isValid(int x, int y, vector<vector<int> > &board)
{
    return ( x >= 0 && x < board.size() && y >= 0 &&   y < board[0].size() && board[x][y] == -1);
}

// 印出棋盤
void printMap(vector<vector<int> > &board)
{
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[0].size(); j++)
            printf(" %2d ", board[i][j]+1); //0起算，因此+1
        printf("\n");
    }
}

// 傳入的參數為騎士的下一個位置，step為下一步，在step>=N*N時剛好可以return true 
int walk(int x, int y,   vector<vector<int> > &board, int step)
{
 	// k:騎士有幾種走法 newX,newY:騎士之後的位置 
    int k, newX, newY;
    if (step >= board.size() * board[0].size()) //邊界條件 
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

    for (int x=1; x<=6; x++) {
      printf("\nTest: %d\n", x);
      vector<vector<int> > board;

      for (int i = 0; i < x; i++) {
        board.push_back({});
        for (int j = 0; j < x; j++) {
          board[i].push_back(-1);
        }
      }
      
      board[0][0] = 0;//需要先給第一個位置 
      if (walk(0, 0, board, 1) == false) {
          printf("Solution does not exist\n");
          
      } else
          printMap(board);
    }

    return 0;
}
