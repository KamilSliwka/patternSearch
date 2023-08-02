#include <iostream>

using namespace std;

int main() {
    string text;
    cout<<"enter text: "<<endl;
    getline(cin, text);
    string pattern;
    cout<<"enter pattern: "<<endl;
    getline(cin, pattern);
    int* Last = new int[256];
    for(int i=0;i<256;i++){
        Last[i]=-1;
    }
    for(int i=0;i<pattern.length();i++){
        Last[pattern[i]]=i;
    }
    int patternPosition=-1;
    int i=0;
    int j;
    while(i<=text.length()-pattern.length()){
        j=pattern.length()-1;
        while((j>-1)&&(pattern[j]==text[i+j])){
            j--;
        }
        if(j>-1){
           i=i+ max(1,j-Last[text[i+j]]);
        }
        else{
            cout<<"index of the beginning of the pattern: "<<endl;
            patternPosition=i;
            cout << patternPosition << endl;
            i++;
        }
    }
    if(patternPosition == -1){
        cout<<"search pattern is missing"<<endl;
    }
    return 0;
}
