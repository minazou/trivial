#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<size_t> prefix_function(const string &pattern) {
    vector<size_t> f(pattern.size(), 0);
    for (size_t i = 1, j = 0; i < pattern.size(); i++) {
        while (j > 0 && pattern[j] != pattern[i])
            j = f[j-1];
        if (pattern[j] == pattern[i])
            j++;
        f[i] = j;
    }
    return f;
}

vector<size_t> kmp_match(const string &input, const string &pattern) {
    vector<size_t> f = prefix_function(pattern);
    vector<size_t> idx;

    for (size_t i = 0, j = 0; i < input.size(); i++) {
        // find pattern start point
        while (j > 0 && input[i] != pattern[j]) 
            j = f[j - 1]; // next longest prefix
        if (input[i] == pattern[j]) 
            j++;
        if (j == pattern.size()) 
            idx.push_back(i - j + 1);
    }
    return idx;
}

int main(int argc, char **argv) {
    if (argc < 3) {
        cout << "usage:" << argv[0] << " INPUT PATTERN\n";
        return 0;
    }
    string input = argv[1];
    string pattern = argv[2];
    vector<size_t> idx = kmp_match(input, pattern);

    cout << "index:";
    for (size_t i = 0; i < idx.size(); i++)
        cout << idx[i] << " ";
    cout << endl;

    return 0;
}
