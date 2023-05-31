#include <iostream>
#include <vector>
#include <limits>

using namespace std;

void findMinMax(int nums_[], int size, int& min_, int& max_) {
    //min_ = numeric_limits<int>::max();
    //max_ = numeric_limits<int>::min();

    min_ = nums_[0];
    max_ = nums_[0];

    for (int i=1, num; i < size; i++) {
        //num = nums_[i];
        if (nums_[i] < min_) {
            min_ = nums_[i];
        }
        if (nums_[i] > max_) {
            max_ = nums_[i];
        }
    }
}

int main() {
    int nums[] = {5, 2, 9, 1, 7};
    int minimo, maximo;
    int size = sizeof(nums) / sizeof(nums[0]);

    findMinMax(nums, size, minimo, maximo);

    cout << "Mínimo: " << minimo << endl;
    cout << "Máximo: " << maximo << endl;

    return 0;
}