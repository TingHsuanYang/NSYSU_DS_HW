#include <cstdlib>
#include <sstream>
#include <string>
#include <iostream>
#include <fstream>
#include <ctime> // to provide time based seed generation
using namespace std;

int main()
{
    int N = 0;
    cout << "input test number size:" << endl;
    cin >> N;

    srand( time(NULL) );

    /* ���w�üƽd�� */
    int min = 1;
    int max = N;
    int r;

    // �ɦW�R�W
    ostringstream s;
    s << N;
    string fileNum(s.str());
    string name = "input" + fileNum + ".txt"; // file name seperate with 100, 500, 1000, 5000 ...

    // �}���ɮרüg�J
    ofstream myfile;
    myfile.open (name.c_str());
    myfile << N << endl;
    for(int index = 0; index < N; index++) {
        r = rand() % (max - min + 1) + min;
        cout << r << endl;
        myfile << r << endl;
    }
    myfile.close();
    return 0;
}
