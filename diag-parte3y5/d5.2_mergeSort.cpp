#include <iostream>
#include <vector>

using namespace std;

// Merge two sorted subarrays nums[left..mid] and nums[mid+1..right]
void merge(vector<int>& nums, int left, int mid, int right) {
    int i, j, k; 
    //int i = left, j = mid + 1, k = 0;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temporary arrays
    vector<int> L(n1), R(n2);

    // Copy data to temporary arrays L[] and R[]
    for (i = 0; i < n1; i++)
        L[i] = nums[left + i];    
    for (j = 0; j < n2; j++)
        R[j] = nums[mid + 1 + j];

    // Merge the temporary arrays back into nums[left..right]
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray 
    k = left; // Initial index of merged subarray

    while (i < n1 && j < n2){
        if (L[i] <= R[j]) {
            nums[k] = L[i];
            i++;
        } else {
            nums[k] = R[j];
            j++;
        }
        k++;
    }
    
    // Copy the remaining elements of L[], if there are any
    while (i < n1) {
        nums[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if there are any
    while (j < n2) {
        nums[k] = R[j];
        j++;
        k++;
    }
    
}

// Sort subarray nums[left..right] using Merge Sort
void mergeSort(vector<int>& nums, int left, int right) {
    if (left < right) {
        // Same as (left + right) / 2, but avoids overflow for large left and right
        int mid = left + (right - left) / 2;

        mergeSort(nums, left, mid); // Sort first half
        mergeSort(nums, mid + 1, right); // Sort second half

        merge(nums, left, mid, right); // Merge the sorted halves
    }
}

// Utility function to print the contents of an array
void printArray(vector<int>& nums) {
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    vector<int> nums = { 85,24,63,45,31,96,50, 25,8,11,9,19,10,2 };
    int size = nums.size();

    cout << "Arreglo original: ";
    printArray(nums);

    mergeSort(nums, 0, size - 1);

    cout << "Arreglo ordenado: ";
    printArray(nums);

    return 0;
}