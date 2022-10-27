// https://www.codingninjas.com/codestudio/problems/rotate-array_1230543
#include <stdio.h>
#include <iostream>

using namespace std;

void RotateStart(int arr[], int start, int end)
{

    while(start <end)
    {

        int temp = arr[start];
        arr[start]=arr[end];
        arr[end]=temp;
        start++;
        end--;
    }
}

void Rotate(int arr[], int d, int n)
{
    RotateStart(arr, 0, d-1);
     RotateStart(arr, d, n-1);
      RotateStart(arr, 0, n-1);
}

// Function to print elements of array
void PrintTheArray(int arr1[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr1[i] << " ";
    }
}
// Driver code
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int N = sizeof(arr) / sizeof(arr[0]);
    int d = 2;

    // Function calling
    Rotate(arr, d, N);
    PrintTheArray(arr, N);

    return 0;
}
