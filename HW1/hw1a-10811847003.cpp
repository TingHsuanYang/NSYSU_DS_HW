#include <stdio.h>
#include <stdlib.h>

//Author：楊庭軒 10811847003
//Date：2019/09/15 
//Purpose：製作N階(N為奇數)的魔方陣(magic square)

void printMatrix(int num);
int main()
{
    printMatrix(1);
    printMatrix(3);
    printMatrix(5);
    printMatrix(7);
    printMatrix(9);
    return 0;
}
void printMatrix(int num )
{
    // 從1起算比較方便
    int square[num + 1][num + 1] = {0};

    int i = num == 1 ? 1 : 0; //列
    int j = (num + 1) / 2; // 行，從第一行中間起算
    int k; // 1,2,3,4,...填入的數字
    for(k = 1; k <= num * num; k++) {
        if((k % num) == 1) // 此行填滿往下一行填
            i++;
        else { //往左上角填
            i--;
            j--;
        }

        // 減到變0從頭開始
        if(i == 0)
            i = num;
        if(j < 1)
            j = num;

        square[i][j] = k;
    }

    int m, n;//方陣的列與行
    for(m = 1; m <= num; m++) {
        for(n = 1; n <= num; n++) {
            printf("%2d ", square[m][n]);
        }
        printf("\n");
    }
    printf("------------------\n");

}
