#include <iostream>
#include <stack>

using namespace std;

int main() { // Diperbaiki dari "int main{" menjadi "int main() {"
    stack<int> s;
    int input;

    // Input berhenti ketika input bukan angka
    while (cin >> input) {
        s.push(input);w
    }

    // Mengeluarkan semua data dari stack
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }

    cout << endl;

    return 0;
}