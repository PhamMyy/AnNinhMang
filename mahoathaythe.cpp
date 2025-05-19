#include <iostream>
#include <string>
using namespace std;

string maHoaThayThe(string text, string khoa) {
    string result = "";
    string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    
    for (int i = 0; i < text.length(); i++) {
        if (isupper(text[i])) {
            result += khoa[alphabet.find(text[i])];
        } else if (islower(text[i])) {
            result += tolower(khoa[alphabet.find(toupper(text[i]))]);
        } else {
            result += text[i]; 
        }
    }
    return result;
}

int main() {
    string text, khoa;
    cout << "Nhap chuoi can ma hoa: ";
    getline(cin, text);
    cout << "Nhap khoa (26 ky tu - hoan vi): ";
    cin >> khoa;
    
    if (khoa.length() != 26) {
        cout << "Khoa khong hop le!" << endl;
        return 1;
    }
    
    cout << "Chuoi da ma hoa: " << maHoaThayThe(text, khoa) << endl;
    return 0;
}

