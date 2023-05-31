#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

//using namespace std;

class TrieNode {
public:
    std::unordered_map<char, TrieNode*> children;
    bool is_end_of_word;

    TrieNode() {
        is_end_of_word = false;
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    void insert(const std::string& word) {
        TrieNode* node = root;
        for (char ch : word) {
            if (node->children.find(ch) == node->children.end()) {
                node->children[ch] = new TrieNode();
            }
            node = node->children[ch];
        }
        node->is_end_of_word = true;
    }

    bool search(const std::string& word) {
        TrieNode* node = root;
        for (char ch : word) {
            if (node->children.find(ch) == node->children.end()) {
                return false;
            }
            node = node->children[ch];
        }
        return node->is_end_of_word;
    }
};

std::vector<std::string> find_words_in_grid(std::vector<std::vector<char>>& grid, std::vector<std::string>& dictionary) {
    int num_rows = grid.size();
    int num_cols = grid[0].size();
    std::unordered_set<std::string> words_found;

    std::vector<std::vector<bool>> visited(num_rows, std::vector<bool>(num_cols, false));

    std::function<void(int, int, TrieNode*, std::string)> dfs = [&](int row, int col, TrieNode* trie_node, std::string word) {
        if (trie_node->is_end_of_word) {
            words_found.insert(word);
        }

        if (row < 0 || row >= num_rows || col < 0 || col >= num_cols || visited[row][col] ||
            trie_node->children.find(grid[row][col]) == trie_node->children.end()) {
            return;
        }

        char curr_char = grid[row][col];
        visited[row][col] = true;

        TrieNode* next_node = trie_node->children[curr_char];
        grid[row][col] = '#';  // Mark cell as visited in the grid

        dfs(row + 1, col, next_node, word + curr_char);  // Explore down
        dfs(row - 1, col, next_node, word + curr_char);  // Explore up
        dfs(row, col + 1, next_node, word + curr_char);  // Explore right
        dfs(row, col - 1, next_node, word + curr_char);  // Explore left

        grid[row][col] = curr_char;  // Reset cell to original character
        visited[row][col] = false;
    };

    Trie trie;
    for (const std::string& word : dictionary) {
        trie.insert(word);
    }

    for (int i = 0; i < num_rows; ++i) {
        for (int j = 0; j < num_cols; ++j) {
            dfs(i, j, trie.root, "");
        }
    }

    std::vector<std::string> found_words;
    for (const std::string& word : words_found) {
        found_words.push_back(word);
    }

    return found_words;
}

int main() {
    std::vector<std::vector<char>> grid = {
        {'C', 'A', 'T'},
        {'O', 'S', 'K'},
        {'P', 'Y', 'U'}
    };

    std::vector<std::string> dictionary = {
        "CAT", "COPY", "ASK", "SOS", "ASU", "COS", "COSYU", "CASKU",
        "TASK", "COSAT", "CASO", "TACOS", "COPYSA", "TASO", "LASY"
    };

    std::vector<std::string> found_words = find_words_in_grid(grid, dictionary);

    std::cout << "Found Words: ";
    for (const std::string& word : found_words) {
        std::cout << word << " ";
    }
    std::cout << std::endl;

    return 0;
}
