#include <bits/stdc++.h>
using namespace std;

void sultan(int n) {
    if (n == 0) {
        return;
    }
    cout << n << endl;
    sultan(n - 1);
}

int main() {
    cout << "Enter n: ";
    int n;
    cin >> n;
    sultan(n);
}