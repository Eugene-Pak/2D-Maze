#include <iostream>

using namespace std;

int fibonacci(int n) {
    if (n <= 2) { return 1; }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int num = 0;
    cin >> num;
    cout << fibonacci(num) << endl;
    return 0;
}
