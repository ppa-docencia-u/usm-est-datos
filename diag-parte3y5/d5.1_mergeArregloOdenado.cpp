#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> mergeSortedArrays(const vector<int>& arr1, const vector<int>& arr2){
    vector<int> merged;

    int size1 = arr1.size();
    int size2 = arr2.size();
    int i = 0, j = 0;

    while (i < size1 && j < size2) {
        if (arr1[i] < arr2[j]) {
            merged.push_back(arr1[i]);
            i++;
        } else {
            merged.push_back(arr2[j]);
            j++;
        }
    }
    
    while (i < size1) {
        merged.push_back(arr1[i]);
        i++;
    }

    while (j < size2) {
        merged.push_back(arr2[j]);
        j++;
    }
    
    return merged;
}

void printArray(const vector<int>& nums){
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;
}

int main(){
    vector<int> arr1 = {1, 3, 5, 7, 9};
    vector<int> arr2 = {2, 4, 6, 8, 10};

    vector<int> merged = mergeSortedArrays(arr1, arr2);

    cout << "Arreglo 1: ";
    printArray(arr1);

    cout << "Arreglo 2: ";
    printArray(arr2);

    cout << "Arreglo ordenado: ";
    printArray(merged);

    return 0;
}