#include <stdio.h>
#include <stdlib.h>

//Author�G���x�a 10811847003
//Date�G2019/09/15 
//Purpose�G�s�@N��(N���_��)���]��}(magic square)

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
    // �q1�_������K
    int square[num + 1][num + 1] = {0};

    int i = num == 1 ? 1 : 0; //�C
    int j = (num + 1) / 2; // ��A�q�Ĥ@�椤���_��
    int k; // 1,2,3,4,...��J���Ʀr
    for(k = 1; k <= num * num; k++) {
        if((k % num) == 1) // ����񺡩��U�@���
            i++;
        else { //�����W����
            i--;
            j--;
        }

        // �����0�q�Y�}�l
        if(i == 0)
            i = num;
        if(j < 1)
            j = num;

        square[i][j] = k;
    }

    int m, n;//��}���C�P��
    for(m = 1; m <= num; m++) {
        for(n = 1; n <= num; n++) {
            printf("%2d ", square[m][n]);
        }
        printf("\n");
    }
    printf("------------------\n");

}
