#include <iostream>
#include <vector>
#include <limits>

using namespace std;

void findMinMax(const vector<int>& nums_, int& min_, int& max_) {
    //min_ = numeric_limits<int>::max();
    //max_ = numeric_limits<int>::min();

    min_ = nums_[0];
    max_ = nums_[0];

    for (int num : nums_) {
        if (num < min_) {
            min_ = num;
        }
        if (num > max_) {
            max_ = num;
        }
    }
}

int main() {
    vector<int> nums = {5, 2, 9, 1, 7};
    int minimo, maximo;
    findMinMax(nums, minimo, maximo);

    cout << "Mínimo: " << minimo << endl;
    cout << "Máximo: " << maximo << endl;

    return 0;
}