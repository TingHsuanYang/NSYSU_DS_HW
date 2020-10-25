#include <iostream>
#include <fstream>
#include <algorithm>
#include <time.h>
using namespace std;

/*
A類題號:2
B類題號:2
C類題號:1
D類題號:C函式庫 stdlib.h　或 cstdlib，qsort( )函式
E類題號:C++函式庫 (STL) sort( )函式
*/

/* insertion sort */
void InsertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        /* Compare i with elements before and move elements after i  if greater than i */
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}


/* merge sort */
/* Merges two subarrays of data[], first subarray is data[1..m], second is data[m+1..r] */
/* 此處使用in-place的方式，因我的電腦在測試500000的資料時會overflow */
void Merge(int arr[], int l, int m, int r)
{
    // initial index of second array
    int l2 = m + 1;

    // If the direct merge is already sorted
    if (arr[m] <= arr[l2]) {
        return;
    }

    // Two pointers to maintain start of both arrays to merge
    while (l <= m && l2 <= r) {

        // If first element is in right place
        if (arr[l] <= arr[l2]) {
            l++;
        } else {
            int value = arr[l2];
            int index = l2;

            // shift all element right by onen and move l2 to l
            while (index != l) {
                arr[index] = arr[index - 1];
                index--;
            }
            arr[l] = value;

            // Update all the pointers
            l++;
            m++; // the element between l and l2 has been shifted right by 1, so midlle need to shift right by 1 too
            l2++;
        }
    }
}

// l is for left index and r is right index of the sub-array of arr to be sorted
void MergeSort(int arr[], int l, int r)
{
    if (l < r) {
        // Same as (l+r)/2
        int m = l + (r - l) / 2;

        MergeSort(arr, l, m);
        MergeSort(arr, m + 1, r);
        Merge(arr, l, m, r);
    }
}

/* quick sort */
// swap two elements
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

/* last element as pivot, places smaller elements to the left and greater elements to the right */
int partition(int arr[], int l, int h) //low, high
{
    int pivot = arr[h];    // last one as pivot
    int i = (l - 1);  // index of smaller element

    // compare element from first to the one before pivot(last)
    for (int j = l; j <= h - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[h]); // replace pivot
    return (i + 1); // return pivot index
}

void QuickSort(int arr[], int l, int h) // low for starting index, high for ending index
{
    if (l < h) {
        //pivot index
        int pi = partition(arr, l, h);

        // Separately sort first partition and second partition
        QuickSort(arr, l, pi - 1);
        QuickSort(arr, pi + 1, h);
    }
}

/* c lib  qsort */
int comparetor (const void * a, const void * b)
{
    return ( *(int*)a - * (int*)b );
}

// print array
void PrintArray(int arr[], int n)
{
    for (int i = 0; i < n; i++) {
        cout << arr[i];
        if(i > 0 && i % 10 == 0) cout << endl;
        else cout << " ";
    }

    cout << endl << endl;
}

void WriteToFile(int arr[], int n, string fileName)
{
    ofstream outputfile;
    outputfile.open (fileName.c_str());

    // add first line
    if(fileName == "outputA.txt") outputfile << "Insertion Sort" << endl;
    if(fileName == "outputB.txt") outputfile << "Merge Sort" << endl;
    if(fileName == "outputC.txt") outputfile << "Quick Sort" << endl;
    if(fileName == "outputD.txt") outputfile << "C qsort( )" << endl;
    if(fileName == "outputE.txt") outputfile << "C++ sort( )" << endl;

    for (int i = 0; i < n; i++)
        outputfile << arr[i] << endl;
    outputfile.close();
}

/* copy A[] to B[] */
void CopyArr(int A[], int B[], int n)
{
    for(int i = 0; i < n; ++i)
        B[i] = A[i];
}

int main()
{
//	string filename = "input.txt";
//  string filename = "input100.txt";
//	string filename = "input500.txt";
//	string filename = "input1000.txt";
//	string filename = "input5000.txt";
//	string filename = "input10000.txt";
//	string filename = "input50000.txt";
//	string filename = "input100000.txt";
	string filename = "input500000.txt";


    int N = 0; // test size
    ifstream inputfile;
    inputfile.open(filename.c_str());
    inputfile >> N;
    cout << "Test Case Size:" << N << endl;
    int data[N];
    for(int i = 0; i < N; i++) {
        inputfile >> data[i];
    }

    // copy data[] to new array
//    int arrA[N];
//    int arrB[N];
//    int arrC[N];
//    int arrD[N];
//    int arrE[N];
//    CopyArr(data, arrA, N);
//    CopyArr(data, arrB, N);
//    CopyArr(data, arrC, N);
//    CopyArr(data, arrD, N);
//    CopyArr(data, arrE, N);

    cout << "origin array:" << endl;
    PrintArray(data, N);

	clock_t tStart; // execution time

//    /*insertion sort*/
//    cout << "Insertion Sort:" << endl;
//    tStart = clock();
//    InsertionSort(arrA, N);
//	printf("Time taken: %.3fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
//    PrintArray(arrA, N);
//    WriteToFile(arrA, N, "outputA.txt");

    /*merge sort*/
    cout << "Merge Sort:" << endl;
    tStart = clock();
//    MergeSort(arrB, 0, N - 1);
    MergeSort(data, 0, N - 1);
    printf("Time taken: %.3fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
//    PrintArray(data, N);
//    WriteToFile(arrB, N, "outputB.txt");

//    /*quick sort*/
//    cout << "Quick Sort:" << endl;
//    tStart = clock();
//    QuickSort(arrC, 0, N - 1);
//    printf("Time taken: %.3fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
//    PrintArray(arrC, N);
//    WriteToFile(arrC, N, "outputC.txt");
//
//    /*C qsort*/
//    cout << "C qsort:" << endl;
//    tStart = clock();
//    qsort(arrD, N, sizeof(int), comparetor );
//    printf("Time taken: %.3fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
//    PrintArray(arrD, N);
//    WriteToFile(arrD, N, "outputD.txt");
//
//    /*C++ sort*/
//    cout << "C++ sort:" << endl;
//    tStart = clock();
//    sort(arrE, arrE + N);
//    printf("Time taken: %.3fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
//    PrintArray(arrE, N);
//    WriteToFile(arrE, N, "outputE.txt");


}
