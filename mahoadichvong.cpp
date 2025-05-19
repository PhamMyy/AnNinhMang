#include <iostream>
using namespace std;

string mahoadichvong(string text, int k) {
    string result = "";
    for (int i = 0; i < text.length(); i++) {
        if (isupper(text[i])) {
            result += char(int(text[i] + k - 65) % 26 + 65);
        } else if (islower(text[i])) {
            result += char(int(text[i] + k - 97) % 26 + 97);
        } else {
            result += text[i]; 
        }
    }
    return result;
}

int main() {
    string text;
    int k;
    cout << "Nhap chuoi can ma hoa: ";
    getline(cin, text);
    cout << "Nhap khoa k: ";
    cin >> k;
    cout << "Chuoi da ma hoa: " << mahoadichvong(text, k) << endl;
    return 0;
}

