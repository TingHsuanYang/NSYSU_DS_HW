#include <iostream>
#include <fstream>
#include <algorithm>
#include <time.h>
#include <vector>
#include <limits>

using namespace std;

void printArray(vector<int> &vec)
{
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i];
        if(i > 0 && i % 10 == 0) cout << endl;
        else cout << " ";
    }
    cout << endl << endl;
}

void merge(vector<int> &vec, int front, int mid, int end)
{
    // preconditions:
    // Array[front...mid] is sorted
    // Array[mid+1 ... end] is sorted

    // Copy Array[front ... mid] to LeftSubArray
    // Copy Array[mid+1 ... end] to RightSubArray
    vector<int> leftSubArray(vec.begin() + front, vec.begin() + mid + 1);
    vector<int> rightSubArray(vec.begin() + mid + 1, vec.begin() + end + 1);

    int idxLeft = 0, idxRight = 0;

    leftSubArray.insert(leftSubArray.end(), numeric_limits<int>::max());
    rightSubArray.insert(rightSubArray.end(), numeric_limits<int>::max());

    // Pick min of LeftSubArray[idxLeft] and RightSubArray[idxRight], and put into Array[i]
    for (int i = front; i <= end; i++) {
        if (leftSubArray[idxLeft] < rightSubArray[idxRight]) {
            vec[i] = leftSubArray[idxLeft];
            idxLeft++;
        } else {
            vec[i] = rightSubArray[idxRight];
            idxRight++;
        }
    }
}

void mergeSort(vector<int> &vec, int front, int end)
{
    if (front >= end)
        return;
    int mid = (front + end) / 2;
    mergeSort(vec, front, mid);
    mergeSort(vec, mid + 1, end);
    merge(vec, front, mid, end);
}

int main()
{

    for(int k = 0; k < 10; k++) {

        string filename = "input500000.txt";
        int N = 0; // test size
        ifstream inputfile;
        inputfile.open(filename.c_str());
        inputfile >> N;
        cout << "Test Case Size:" << N << endl;
        vector<int> vec;
        int data;
        for(int i = 0; i < N; i++) {
            inputfile >> data;
            vec.push_back(data);
        }

//    cout << "origin array:" << endl;
//    printArray(vec);

        clock_t tStart, tEnd; // execution time

        /*merge sort*/
        cout << "Merge Sort:" << endl;
        tStart = clock();
        mergeSort(vec, 0, N - 1);
        tEnd = clock();
        printf("Time taken: %.3fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);
//   // PrintArray(data, N);
//    //WriteToFile(arrB, N, "outputB.txt");


    }

    return 0;
}
