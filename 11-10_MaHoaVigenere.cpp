#include <iostream>
#include <string>

using namespace std;

// Hàm mã hóa Vigenère
string vigenereCipher(const string& text, const string& key) {
    string result = "";
    int keyIndex = 0;
    int keyLength = key.length();

    for (char c : text) {
        // Kiểm tra nếu ký tự là chữ cái
        if (isalpha(c)) {
            char base = islower(c) ? 'a' : 'A'; // Xác định cơ sở cho chữ hoa hoặc chữ thường
            // Mã hóa ký tự
            result += char((c - base + (toupper(key[keyIndex % keyLength]) - 'A')) % 26 + base);
            keyIndex++; // Chỉ số khóa tăng lên
        } else {
            // Nếu ký tự không phải chữ cái, thêm vào kết quả mà không thay đổi
            result += c;
        }
    }

    return result;
}

int main() {
    string text, key;

    // Nhập văn bản và khóa
    cout << "Nhap van ban can ma hoa: ";
    getline(cin, text);
    cout << "Nhap khoa: ";
    getline(cin, key);

    // Mã hóa và in ra kết quả
    string encodedText = vigenereCipher(text, key);
    cout << "Van ban da ma hoa: " << encodedText << endl;

    return 0;
}
