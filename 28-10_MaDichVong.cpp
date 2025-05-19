#include <iostream>
using namespace std;
string maHoaDichVong(string text, int k) {                   // H�m m� h�a d?ch v�ng
    string result = "";                            // Chu?i l?u k?t qu? sau khi m� h�a
    for (int i = 0; i < text.length(); i++) {      // Duy?t t?ng k� t? trong chu?i v?n b?n
        if (isupper(text[i])) {                    // N?u k� t? l� ch? hoa
            result += char(int(text[i] + k - 65) % 26 + 65); // D?ch v�ng v� chuy?n l?i v? m� ASCII c?a ch? hoa
        } else if (islower(text[i])) {             // N?u k� t? l� ch? th??ng
            result += char(int(text[i] + k - 97) % 26 + 97); // D?ch v�ng v� chuy?n l?i v? m� ASCII c?a ch? th??ng
        } else {                                   // N?u l� k� t? kh�c nh? kho?ng tr?ng, d?u c�u
            result += text[i];                     // Gi? nguy�n k� t? kh�ng m� h�a
        }
    }
    return result;                                 // Tr? v? chu?i k?t qu? ?� m� h�a
}
int main() {
    string text;
    int k;
    cout << "Nhap chuoi can ma hoa: ";
    getline(cin, text);                            
    cout << "Nhap khoa k: ";
    cin >> k;                                      // Nh?p kh�a m� h�a (s? nguy�n) t? ng??i d�ng
    cout << "Chuoi da ma hoa: " << maHoaDichVong(text, k) << endl; // In k?t qu? m� h�a
    return 0;                                      // K?t th�c ch??ng tr�nh
}
