#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

// Hàm mã hóa
string encrypt(const string& text, const unordered_map<char, char>& cipher) {
    string encrypted_text = "";
    for (char c : text) {
        if (cipher.find(c) != cipher.end()) {
            encrypted_text += cipher.at(c);
        } else {
            encrypted_text += c; // Nếu không tìm thấy trong bảng thay thế, giữ nguyên ký tự
        }
    }
    return encrypted_text;
}

// Hàm giải mã
string decrypt(const string& text, const unordered_map<char, char>& reverse_cipher) {
    string decrypted_text = "";
    for (char c : text) {
        if (reverse_cipher.find(c) != reverse_cipher.end()) {
            decrypted_text += reverse_cipher.at(c);
        } else {
            decrypted_text += c; // Nếu không tìm thấy trong bảng thay thế, giữ nguyên ký tự
        }
    }
    return decrypted_text;
}

int main() {
    // Bảng mã thay thế (cipher) và bảng giải mã (reverse_cipher)
    unordered_map<char, char> cipher = {
        {'a', 'x'}, {'b', 'y'}, {'c', 'z'}, {'d', 'a'}, {'e', 'b'}, 
        {'f', 'c'}, {'g', 'd'}, {'h', 'e'}, {'i', 'f'}, {'j', 'g'},
        {'k', 'h'}, {'l', 'i'}, {'m', 'j'}, {'n', 'k'}, {'o', 'l'},
        {'p', 'm'}, {'q', 'n'}, {'r', 'o'}, {'s', 'p'}, {'t', 'q'},
        {'u', 'r'}, {'v', 's'}, {'w', 't'}, {'x', 'u'}, {'y', 'v'}, 
        {'z', 'w'}
    };

    unordered_map<char, char> reverse_cipher;
    for (const auto& pair : cipher) {
        reverse_cipher[pair.second] = pair.first; // Đảo ngược bảng mã để tạo bảng giải mã
    }

    // Nhập văn bản cần mã hóa
    string text;
    cout << "Nhap van ban can ma hoa: ";
    getline(cin, text);

    // Mã hóa
    string encrypted_text = encrypt(text, cipher);
    cout << "Van ban da ma hoa: " << encrypted_text << endl;

    // Giải mã
    string decrypted_text = decrypt(encrypted_text, reverse_cipher);
    cout << "Van ban da giai ma: " << decrypted_text << endl;

    return 0;
}
