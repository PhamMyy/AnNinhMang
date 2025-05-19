#include <iostream>
#include <string>

using namespace std;

// Hàm để tìm nghịch đảo modular của a với mod m
int modInverse(int a, int m) {
    a = a % m;
    for (int x = 1; x < m; x++) {
        if ((a * x) % m == 1)
            return x;
    }
    return -1;
}

// Hàm mã hóa Affine Cipher
string affineEncrypt(string text, int a, int b) {
    string result = "";

    for (int i = 0; i < text.length(); i++) {
        // Chỉ mã hóa ký tự chữ cái
        if (isalpha(text[i])) {
            char ch = tolower(text[i]);
            // Mã hóa công thức: E(x) = (a * x + b) % 26
            char encrypted = (a * (ch - 'a') + b) % 26 + 'a';
            result += encrypted;
        } else {
            result += text[i]; // Giữ nguyên các ký tự không phải chữ cái
        }
    }
    return result;
}

// Hàm giải mã Affine Cipher
string affineDecrypt(string text, int a, int b) {
    string result = "";
    int a_inv = modInverse(a, 26); // Nghịch đảo modular của a

    if (a_inv == -1) {
        cout << "Khong the tim thay nghich dao modular cho khoa a." << endl;
        return "";
    }

    for (int i = 0; i < text.length(); i++) {
        // Chỉ giải mã ký tự chữ cái
        if (isalpha(text[i])) {
            char ch = tolower(text[i]);
            // Giải mã công thức: D(x) = a^(-1) * (x - b) % 26
            char decrypted = (a_inv * ((ch - 'a' - b + 26) % 26)) % 26 + 'a';
            result += decrypted;
        } else {
            result += text[i]; // Giữ nguyên các ký tự không phải chữ cái
        }
    }
    return result;
}

int main() {
    string text;
    int a, b;

    cout << "Nhap van ban: ";
    getline(cin, text);
    cout << "Nhap khoa a: ";
    cin >> a;
    cout << "Nhap khoa b: ";
    cin >> b;

    string encryptedText = affineEncrypt(text, a, b);
    cout << "Van ban sau khi ma hoa: " << encryptedText << endl;

    string decryptedText = affineDecrypt(encryptedText, a, b);
    cout << "Van ban sau khi giai ma: " << decryptedText << endl;

    return 0;
}
