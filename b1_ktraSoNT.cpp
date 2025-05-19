#include <iostream>
using namespace std;

// Hàm kiểm tra số nguyên tố
bool kiemTraSoNguyenTo(int n) {
    if (n <= 1) 
        return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) 
            return false;
    }
    return true;
}

int main() {
    int n;
    cout << "Nhap mot so nguyen: ";
    cin >> n;

    if (kiemTraSoNguyenTo(n)) {
        cout << n << " la so nguyen to." << endl;
    } else {
        cout << n << " khong phai so nguyen to." << endl;
    }

    return 0;
}
