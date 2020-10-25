#include <iostream>
#include <cstring>
using namespace std;

// N x N �o��n�令1~6
#define N 5

// �M�h�������B��
int row[8] = {  -2, -1, 1, 2, 2, 1, -1, -2 };
int col[8] = {  1, 2, 2, 1, -1, -2, -2, -1 };

// �P�_�O�_�i�� 
bool isValid(int x, int y, int board[N][N])
{
    return ( x >= 0 && x < N && y >= 0 &&   y < N && board[x][y] == -1);
}

// �L�X�ѽL 
void printMap(int board[N][N])
{
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf(" %2d ", board[i][j]+1); //0�_��A�]��+1 
        printf("\n");
    }
}

// �ǤJ���ѼƬ��M�h���U�@�Ӧ�m�Astep���U�@�B�A�bstep>=N*N�ɭ�n�i�Hreturn true  
int walk(int x, int y,   int board[N][N], int step)
{
	// k:�M�h���X�ب��k newX,newY:�M�h���᪺��m 
    int k, newX, newY;
    if (step >= N * N) //��ɱ��� 
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
    int board[N][N];

    memset(board, -1, sizeof board); //���ҥH��-1�A�O���F0�_��A�]��walk���ѼƬ��U�@�B 
	board[0][0] = 0;//�ݭn�����Ĥ@�Ӧ�m 
    if (walk(0, 0, board, 1) == false) {
        printf("Solution does not exist");
        return false;
    } else
        printMap(board);

    return 0;
}
