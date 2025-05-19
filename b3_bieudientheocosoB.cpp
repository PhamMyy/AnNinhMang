#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Hàm chuyển đổi số n sang cơ số B
void convertToBase(int n, int B) {
    if (B < 2) {
        cout << "Cơ số không hợp lệ! Cơ số phải lớn hơn hoặc bằng 2." << endl;
        return;
    }

    vector<int> digits;

    // Xử lý trường hợp n = 0
    if (n == 0) {
        cout << 0 << endl;
        return;
    }

    // Chuyển đổi số n sang cơ số B
    while (n > 0) {
        digits.push_back(n % B);
        n /= B;
    }

    // In ra các chữ số theo thứ tự từ cao đến thấp
    reverse(digits.begin(), digits.end());

    for (int digit : digits) {
        cout << digit;
    }
    cout << endl;
}

int main() {
    int n, B;

    cout << "Nhập số nguyên cần chuyển đổi: ";
    cin >> n;

    cout << "Nhập cơ số B (lớn hơn hoặc bằng 2): ";
    cin >> B;

    cout << "Số " << n << " trong hệ cơ số " << B << " là: ";
    convertToBase(n, B);

    return 0;
}
