#include <iostream>
#include <stdio.h>
#include <string.h>
// �]�w���
#define max 10000
using namespace std;


//Author�G���x�a 10811847003
//Date�G2019/09/15
//Purpose�G�L�X1��N�����Ҧ���Ƥ����� (factorial)�AN 50�C

void calculate(int n)
{
    int ans[max] = {0};
    ans[0] = 1; //�Ĥ@�ӼƳ]��1
    for(int i = 1; i <= n; i++) { //���W�Ҧ���
        int tmp = 0; // �i���
        for(int j = 0; j < max; j++) { //��i�}�C
            int s = ans[j] * i + tmp;
            ans[j] = s % 10;
            tmp = s / 10;
        }
    }

    // �q�᭱�}�l�L
    printf("%d!=", n);
    bool flag = false;//�ΨӧP�_�����j�ƪ��}�Y
    for(int index = max - 1; index >= 0; index--) {
        if(ans[index] != 0 && !flag) {
            flag = true;
        }
        if(flag) {
            printf("%d", ans[index]);
        }
    }
    printf("\n");

}


int main()
{
    int n; //���p�⪺��
    while(cin >> n) {
        if(n == 0) break;
        for(int i = 1; i <= n; i++) {
            calculate(i);
        }
    }
    return 0;
}
