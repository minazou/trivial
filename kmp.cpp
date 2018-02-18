#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> compute_f(const string& pattern) {
    vector<int> f;
    f.push_back(1);
    return f; 
}

int main() {
    string pattern = "ABCDABD";
    vector<int> f = compute_f(pattern);
    cout << f.size() << endl;
    return 0;
}
