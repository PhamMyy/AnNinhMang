#include <iostream>
#include <vector>

int main() {
    int n, m;
    std::cout << "Nhap gia tri n (modulo): ";
    std::cin >> n;

    std::cout << "Nhap so luong phan tu trong day: ";
    std::cin >> m;

    std::vector<int> arr(m);
    std::cout << "Nhap cac phan tu trong day: ";
    for (int i = 0; i < m; i++) {
        std::cin >> arr[i];
    }

    int sum = 0;
    for (int i = 0; i < m; i++) {
        sum += arr[i];
    }

    sum = sum % n; // Tính tổng theo modulo n

    std::cout << "Tong cua day so trong Z_" << n << " la: " << sum << std::endl;

    return 0;
}
