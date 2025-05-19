#include <iostream>
#include <string>
using namespace std;
string vigenereCipher(const string& text, const string& key) {        // Hàm mã hóa Vigenère
    string result = "";                          // Chu?i l?u k?t qu? mã hóa
    int keyIndex = 0;                            // Bi?n theo dõi v? trí c?a ký t? trong khóa
    int keyLength = key.length();                // ?? dài c?a khóa
    for (int i = 0; i < text.length(); i++) {   // L?p qua ch? s? t? 0 ??n ?? dài c?a v?n b?n
        char c = text[i];                        // L?y ký t? t?i v? trí i
        if (isalpha(c)) {                        // Ki?m tra n?u ký t? là ch? cái
            char base = islower(c) ? 'a' : 'A';  // Xác ??nh c? s? là 'a' ho?c 'A' d?a vào ch? th??ng ho?c hoa
            // Mã hóa ký t?: tính toán v? trí m?i sau khi d?ch, chuy?n v? mã ASCII và thêm vào k?t qu?
            result += char((c - base + (toupper(key[keyIndex % keyLength]) - 'A')) % 26 + base);
            keyIndex++;                          // T?ng v? trí khóa ?? s? d?ng ký t? ti?p theo trong khóa
        } else {                                 // N?u không ph?i ch? cái
            result += c;                         // Gi? nguyên ký t? không mã hóa
        }
    }
    return result;                               // Tr? v? chu?i k?t qu? ?ã mã hóa
}
int main() {
    string text, key;
    cout << "Nhap van ban can ma hoa: ";
    getline(cin, text);                          
    cout << "Nhap khoa: ";
    getline(cin, key);                           
    string encodedText = vigenereCipher(text, key);
 cout << "Van ban da ma hoa: " << encodedText << endl; 
return 0; 
}
