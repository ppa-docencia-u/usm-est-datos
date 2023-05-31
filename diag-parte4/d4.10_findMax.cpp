#include <iostream>

using namespace std;

int find_max(int nums[], int size) {
    int max = nums[0];

    for (int i = 1; i < size; i++) {
        if (nums[i] > max) {
            max = nums[i];
        }
    }
    return max;
}

int main(){
    int nums[] = {5, 2, 9, 1, 7};
    int size = sizeof(nums) / sizeof(nums[0]);

    cout << "Arreglo: ";
    for (int i = 0; i < size; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    cout << "Máximo: " << find_max(nums, size) << endl;

    return 0;
}