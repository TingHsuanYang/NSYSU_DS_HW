#include <iostream>
#include <unistd.h>
#define N 5
#define STACK_MAX_SIZE N*N 
using namespace std;

struct Step {
    int i, j;
};

Step steps[] = {
    {-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}
};

// 取得騎士走的方向步數 
const Step& GetStep(int n)
{
    return steps[n - 1];
}

// i,j為上一步的位置，k方向 
struct StackRecord {
    int i, j, k;
};

// stack實作 
class Stack
{
public:
    bool Push(StackRecord r)
    {
    	// stack overflow 
        if (size == STACK_MAX_SIZE) {
            return false;
        }

        records[size] = r;
        size++;
        return true;
    }

    bool Pop()
    {
    	// empty
        if (size == 0) {
            return false;
        }

        size--;
        return true;
    }

	// 檢查是否走過 
    bool IsSet(const StackRecord& r)
    {
        for (int n = 0; n < size; n++) {
            if (r.i == records[n].i && r.j == records[n].j) {
                return true;
            }
        }

        return false;
    }

	//返回最上方的值 
    const StackRecord& Top()
    {
        return records[size - 1];
    }

    int Size()
    {
        return size;
    }

	// 印出剛走過的步驟 
    void Print()
    {
        int m[N][N] = {};
        int k[N][N] = {};
        for (int i = 0; i < size; i++) {
            m[records[i].i - 1][records[i].j - 1] = i + 1;
            k[records[i].i - 1][records[i].j - 1] = records[i].k;
        }

        for(int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
            	// 印出第幾步與k的方向 
                printf("%2d(%d) ", m[i][j], k[i][j]);
            }

            cout << endl;
        }

        cout << endl;
    }

private:
    StackRecord records[STACK_MAX_SIZE];
    int size = 0;
};

bool IsInBound(const StackRecord& r)
{
    return r.i >= 1 && r.i <= N && r.j >= 1 && r.j <= N;
}


int main()
{
    Stack s;
    s.Push({1, 1, 1});

    bool needPop = false;
    // 還沒走滿時繼續走 
    while (s.Size() > 0 && s.Size() < STACK_MAX_SIZE) {
        int next_k = 1;
        //返回上一步 
        if (needPop) {
            next_k = s.Top().k + 1;
            s.Pop();
        }

        needPop = true;
        //走過8個方向 
        for (int k = next_k; k <= 8; k++) {
        	// 下個位置 
            StackRecord next = {s.Top().i + GetStep(k).i, s.Top().j + GetStep(k).j, k};

			// 可以走到這位置 
            if (IsInBound(next) && !s.IsSet(next)) {
                s.Push(next);
                needPop = false; //不需回到上一步 
                break;
            }
        }
    }

	// 走滿時印出 
    if (s.Size() == STACK_MAX_SIZE) {
        s.Print();
    } else {
        cout << "No Solution" << endl;
    }

    return 0;
}
