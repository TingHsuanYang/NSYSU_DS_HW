#include <iostream>
#include <cstring>
#include <vector>
using namespace std;


// �M�h�������B��
int row[8] = {  -2, -1, 1, 2, 2, 1, -1, -2 };
int col[8] = {  1, 2, 2, 1, -1, -2, -2, -1 };

// �P�_�O�_�i���A�@�}�l�ٳQvector<vector<int> > �����A���p��A�֤@�Ů�A�o�쯺 
bool isValid(int x, int y, vector<vector<int> > &board)
{
    return ( x >= 0 && x < board.size() && y >= 0 &&   y < board[0].size() && board[x][y] == -1);
}

// �L�X�ѽL
void printMap(vector<vector<int> > &board)
{
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[0].size(); j++)
            printf(" %2d ", board[i][j]+1); //0�_��A�]��+1
        printf("\n");
    }
}

// �ǤJ���ѼƬ��M�h���U�@�Ӧ�m�Astep���U�@�B�A�bstep>=N*N�ɭ�n�i�Hreturn true 
int walk(int x, int y,   vector<vector<int> > &board, int step)
{
 	// k:�M�h���X�ب��k newX,newY:�M�h���᪺��m 
    int k, newX, newY;
    if (step >= board.size() * board[0].size()) //��ɱ��� 
        return true;

    for (k = 0; k < 8; k++) {
        newX = x + row[k];
        newY = y + col[k];
        if (isValid(newX, newY, board)) {
            board[newX][newY] = step; //��J�ĴX�B  
            if (walk(newX, newY, board, step + 1) == true) // return true���ɭԡA�N��w�g����board 
                return true;
            else
                board[newX][newY] = -1; //�٭� 
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
      
      board[0][0] = 0;//�ݭn�����Ĥ@�Ӧ�m 
      if (walk(0, 0, board, 1) == false) {
          printf("Solution does not exist\n");
          
      } else
          printMap(board);
    }

    return 0;
}
