#include <iostream>
#include "BoyerMoore.h"

using namespace std;

int main() {
    string text;
    cout<<"enter text: "<<endl;
    getline(cin, text);
    string pattern;
    cout<<"enter pattern: "<<endl;
    getline(cin, pattern);
    if(!pattern.empty()) {
        BoyerMoore algorithm(text, pattern);
        algorithm.patternSearch();
    }
    else{
        cout<<"empty pattern!"<<endl;
    }

    return 0;
}
