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
    int m=pattern.length();
    int* tempArray = new int[m+1];
    int* BMNext = new int[m+1];
    for(int i=0;i<m+1;i++){
        BMNext[i]=0;
    }
    int i = m;
    int b=m+1;
    tempArray[i]=b;
    while(i>0){
        while((b<=m)&&(pattern[i-1]!=pattern[b-1])){
            if(BMNext[b]==0){
                BMNext[b]=b-i;
            }
            b=tempArray[b];
        }
        b=b-1;
        i=i-1;
        tempArray[i]=b;
    }
    b=tempArray[0];
    for(int j;j<m+1;j++){
        if(BMNext[i]==0){
            BMNext[i]=b;
        }
        if(i==b){
            b=tempArray[b];
        }
    }
    for(int k=0;k<pattern.length();k++){
        Last[pattern[k]]=k;
    }
    int patternPosition=-1;
    i=0;
    int j;
    while(i<=text.length()-pattern.length()){
        j=pattern.length()-1;
        while((j>-1)&&(pattern[j]==text[i+j])){
            j--;
        }
        if(j==-1){
            cout<<"index of the beginning of the pattern: "<<endl;
            patternPosition=i;
            cout << patternPosition << endl;
            i=i+1;
        }
        else {
            i = i + max(BMNext[j + 1], j - Last[text[i + j]]);
        }
    }
    if(patternPosition == -1){
        cout<<"search pattern is missing"<<endl;
    }
    return 0;
}
