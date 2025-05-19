#include <iostream>
using namespace std;

// Hàm kiểm tra số nguyên tố
bool isPrime(int num) {
    if (num < 2) return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0)
            return false;
    }
    return true;
}

int main() {
    int N;
    cout << "Nhap so luong N so nguyen to dau tien can in: ";
    cin >> N;

    int count = 0; // Đếm số lượng số nguyên tố đã tìm được
    int num = 2;   // Bắt đầu từ số 2 là số nguyên tố đầu tiên

    // Vòng lặp tìm số nguyên tố
    while (count < N) {
        if (isPrime(num)) {
            cout << num << " ";
            count++;
        }
        num++;
    }

    cout << endl;
    return 0;
}
