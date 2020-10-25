#include <iostream>
#include <stdio.h>
#include <string.h>
// 砞﹚计
#define max 10000
using namespace std;


//Author法畑癮 10811847003
//Date2019/09/15
//Purpose1Nぇ丁┮Τ俱计ぇ顶 (factorial)N 50

void calculate(int n)
{
    int ans[max] = {0};
    ans[0] = 1; //材计砞1
    for(int i = 1; i <= n; i++) { //┮Τ计
        int tmp = 0; // 秈ノ
        for(int j = 0; j < max; j++) { //峨秈皚
            int s = ans[j] * i + tmp;
            ans[j] = s % 10;
            tmp = s / 10;
        }
    }

    // 眖秨﹍
    printf("%d!=", n);
    bool flag = false;//ノㄓ耞ぃ计秨繷
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
    int n; //饼璸衡计
    while(cin >> n) {
        if(n == 0) break;
        for(int i = 1; i <= n; i++) {
            calculate(i);
        }
    }
    return 0;
}
