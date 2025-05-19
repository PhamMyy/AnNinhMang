#include <iostream>
#include <string>
using namespace std;
string vigenereCipher(const string& text, const string& key) {        // H�m m� h�a Vigen�re
    string result = "";                          // Chu?i l?u k?t qu? m� h�a
    int keyIndex = 0;                            // Bi?n theo d�i v? tr� c?a k� t? trong kh�a
    int keyLength = key.length();                // ?? d�i c?a kh�a
    for (int i = 0; i < text.length(); i++) {   // L?p qua ch? s? t? 0 ??n ?? d�i c?a v?n b?n
        char c = text[i];                        // L?y k� t? t?i v? tr� i
        if (isalpha(c)) {                        // Ki?m tra n?u k� t? l� ch? c�i
            char base = islower(c) ? 'a' : 'A';  // X�c ??nh c? s? l� 'a' ho?c 'A' d?a v�o ch? th??ng ho?c hoa
            // M� h�a k� t?: t�nh to�n v? tr� m?i sau khi d?ch, chuy?n v? m� ASCII v� th�m v�o k?t qu?
            result += char((c - base + (toupper(key[keyIndex % keyLength]) - 'A')) % 26 + base);
            keyIndex++;                          // T?ng v? tr� kh�a ?? s? d?ng k� t? ti?p theo trong kh�a
        } else {                                 // N?u kh�ng ph?i ch? c�i
            result += c;                         // Gi? nguy�n k� t? kh�ng m� h�a
        }
    }
    return result;                               // Tr? v? chu?i k?t qu? ?� m� h�a
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
