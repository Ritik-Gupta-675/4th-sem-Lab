#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void bucketSort(vector<float>& arr) {
    int n = arr.size();
    vector<vector<float>> buckets(n);
    for (float num : arr) {
        int index = n * num;
        buckets[index].push_back(num);
    }
    for (auto& bucket : buckets)
        sort(bucket.begin(), bucket.end());
    int idx = 0;
    for (auto& bucket : buckets)
        for (float num : bucket)
            arr[idx++] = num;
}
void printArray(const vector<float>& arr) {
    for (float num : arr)
        cout << num << " ";
    cout << endl;
}
int main() {
    vector<float> arr = {0.78, 0.17, 0.39, 0.26, 0.72, 0.94, 0.21, 0.12, 0.23, 0.68};
    cout << "Original array: ";
    printArray(arr);
    bucketSort(arr);
    cout << "Sorted array: ";
    printArray(arr);
    return 0;
}
