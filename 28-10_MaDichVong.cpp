#include <iostream>
using namespace std;
string maHoaDichVong(string text, int k) {                   // Hàm mã hóa d?ch vòng
    string result = "";                            // Chu?i l?u k?t qu? sau khi mã hóa
    for (int i = 0; i < text.length(); i++) {      // Duy?t t?ng ký t? trong chu?i v?n b?n
        if (isupper(text[i])) {                    // N?u ký t? là ch? hoa
            result += char(int(text[i] + k - 65) % 26 + 65); // D?ch vòng và chuy?n l?i v? mã ASCII c?a ch? hoa
        } else if (islower(text[i])) {             // N?u ký t? là ch? th??ng
            result += char(int(text[i] + k - 97) % 26 + 97); // D?ch vòng và chuy?n l?i v? mã ASCII c?a ch? th??ng
        } else {                                   // N?u là ký t? khác nh? kho?ng tr?ng, d?u câu
            result += text[i];                     // Gi? nguyên ký t? không mã hóa
        }
    }
    return result;                                 // Tr? v? chu?i k?t qu? ?ã mã hóa
}
int main() {
    string text;
    int k;
    cout << "Nhap chuoi can ma hoa: ";
    getline(cin, text);                            
    cout << "Nhap khoa k: ";
    cin >> k;                                      // Nh?p khóa mã hóa (s? nguyên) t? ng??i dùng
    cout << "Chuoi da ma hoa: " << maHoaDichVong(text, k) << endl; // In k?t qu? mã hóa
    return 0;                                      // K?t thúc ch??ng trình
}
