#include <iostream>
#include <vector>
using namespace std;
int maximum(const vector<int>& arr) {
    int maxi = 0;
    for(int i : arr){
        maxi = max(maxi,i);
    }
    return maxi;
}
void countingSort(vector<int>& arr, int exp) {
    int n = arr.size();
    vector<int> output(n); 
    int count[10] = {0};   

    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}
void radixSort(vector<int>& arr) {
    int maxNum = maximum(arr);

    for (int exp = 1; maxNum / exp > 0; exp *= 10)
        countingSort(arr, exp);
}
void printArray(const vector<int>& arr) {
    for (int num : arr)
        cout << num << " ";
    cout << endl;
}
int main() {
    vector<int> arr = {170, 45, 75, 90, 802, 24, 2, 66};
    cout << "Original array: ";
    printArray(arr);

    radixSort(arr);
    
    cout << "Sorted array: ";
    printArray(arr);
    return 0;
}