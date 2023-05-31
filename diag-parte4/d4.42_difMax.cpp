#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int findMinMax(int nums_[], int size) {
    //min_ = numeric_limits<int>::max();
    //max_ = numeric_limits<int>::min();

    int min_ = nums_[0];
    int max_ = nums_[0];

    for (int i=1, num; i < size; i++) {
        //num = nums_[i];
        if (nums_[i] < min_) {
            min_ = nums_[i];
        }
        if (nums_[i] > max_) {
            max_ = nums_[i];
        }
    }
    return max_ - min_;
}

int main() {
    int nums[] = {5, 2, 9, 1, 7};
    int minimo, maximo;
    int size = sizeof(nums) / sizeof(nums[0]);

    findMinMax(nums, size);

    cout << "Diferencia máxima: " 
        << findMinMax(nums, size) 
        << endl;

    return 0;
}