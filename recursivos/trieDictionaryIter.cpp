#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    vector<std::string> words = {"CAT", "COPY", "ASK", "SOS", "ASU", "COS", "COSYU", "CASKU", "TASK",
                                      "COSAT", "CASO", "TACOS", "COPYSA", "TASO", "LASY"};
    string chars = "CATOSKPYU";

    for (const string& word : words) {
        bool is_in = true;
        vector<pair<int, int>> used;
        int row = -1, col = -1;

        for (char ch : word) {
            if (chars.find(ch) != string::npos) {
                int row_ch = chars.find(ch) / 3;
                int col_ch = chars.find(ch) % 3;

                if (row < 0 || col < 0) {
                    row = row_ch;
                    col = col_ch;
                    used.push_back(make_pair(row, col));
                } else if ((row_ch == row && (col_ch == col + 1 || col_ch == col - 1)) ||
                           (col_ch == col && (row_ch == row + 1 || row_ch == row - 1))) {
                    // Complejidad en tiempo O(n), espacio auxiliar O(1) 
                    if (find(used.begin(), used.end(), make_pair(row_ch, col_ch)) == used.end()) {
                        row = row_ch;
                        col = col_ch;
                        used.push_back(make_pair(row, col));
                    } else {
                        is_in = false;
                        break;
                    }
                } else {
                    is_in = false;
                    break;
                }
            } else {
                is_in = false;
                break;
            }
        }

        if (is_in) {
            cout << word << " was found" << endl;
        }
    }

    return 0;
}
