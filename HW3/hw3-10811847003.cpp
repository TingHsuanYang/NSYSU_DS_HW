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

// ���o�M�h������V�B�� 
const Step& GetStep(int n)
{
    return steps[n - 1];
}

// i,j���W�@�B����m�Ak��V 
struct StackRecord {
    int i, j, k;
};

// stack��@ 
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

	// �ˬd�O�_���L 
    bool IsSet(const StackRecord& r)
    {
        for (int n = 0; n < size; n++) {
            if (r.i == records[n].i && r.j == records[n].j) {
                return true;
            }
        }

        return false;
    }

	//��^�̤W�誺�� 
    const StackRecord& Top()
    {
        return records[size - 1];
    }

    int Size()
    {
        return size;
    }

	// �L�X�訫�L���B�J 
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
            	// �L�X�ĴX�B�Pk����V 
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
    // �٨S�������~�� 
    while (s.Size() > 0 && s.Size() < STACK_MAX_SIZE) {
        int next_k = 1;
        //��^�W�@�B 
        if (needPop) {
            next_k = s.Top().k + 1;
            s.Pop();
        }

        needPop = true;
        //���L8�Ӥ�V 
        for (int k = next_k; k <= 8; k++) {
        	// �U�Ӧ�m 
            StackRecord next = {s.Top().i + GetStep(k).i, s.Top().j + GetStep(k).j, k};

			// �i�H����o��m 
            if (IsInBound(next) && !s.IsSet(next)) {
                s.Push(next);
                needPop = false; //���ݦ^��W�@�B 
                break;
            }
        }
    }

	// �����ɦL�X 
    if (s.Size() == STACK_MAX_SIZE) {
        s.Print();
    } else {
        cout << "No Solution" << endl;
    }

    return 0;
}
