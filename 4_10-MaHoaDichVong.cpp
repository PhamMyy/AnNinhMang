#include<iostream>
#include<string>
using namespace std;

string encode(string s, int k){

    string cipher;
    int n = s.length();
    for(int i=0;i<n;i++){
        if(s[i]>=65 && s[i]<=90){
            char new_char = ((s[i] - 65) + k) % 26 + 65;
            cipher +=new_char;
        }else if(s[i]>=97 && s[i]<=122){
            char new_char = ((s[i] - 97) + k) % 26 + 97;
            cipher +=new_char;
        }else{
            cipher+=s[i];
        }

    }


    return cipher;
}

int main(){
    int k;
    string s;
    cout<<" Nhap k(k>1): "; cin>>k;
    cin.ignore();
    cout<<" Nhap xau s: "; getline(cin,s);
    string cipher = encode(s,k);
    cout<<"Chuoi sau khi duoc ma hoa la: "<<cipher;
}