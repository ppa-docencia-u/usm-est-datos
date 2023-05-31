#include <iostream>
#include <vector>

using namespace std;

void reverse(vector<int>& S, int start, int stop) {
    if (start < stop - 1) {
        // swap especializado en tiempo constante: O(1)
        swap(S[start], S[stop - 1]); 
        reverse(S, start + 1, stop - 1);
    }
}

int binary_sum(const vector<int>& S, int start, int stop) {
    if (start >= stop) {
        return 0;
    } else if (start == stop - 1) {
        return S[start];
    } else {
        int mid = (start + stop) / 2;
        return binary_sum(S, start, mid) + binary_sum(S, mid, stop);
    }
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8};
    cout << "nums = ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    reverse(nums, 0, nums.size());
    cout << "nums = ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Suma binaria: " << binary_sum(nums, 0, nums.size()) << endl;

    return 0;
}
