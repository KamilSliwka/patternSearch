//
// Created by kamil on 02.08.2023.
//
#include <iostream>
#include <windows.h>
#include "BoyerMoore.h"
#define NUMBEROFCHARINASCII 256

using namespace std;

BoyerMoore::BoyerMoore(const string &text, const string &pattern) : text(text), pattern(pattern) {
    int m=pattern.length();
    Last = new int[NUMBEROFCHARINASCII];
    tempArray = new int[m+1];
    BMNext = new int[m+1];
    patternPosition = -1;
    patternArray = new bool[text.length()];
}

void BoyerMoore::patternSearch() {
    initialization();
    goodSuffixHeuristics();
    algorithm();
}

void BoyerMoore::initialization() {
    for(int i=0;i<NUMBEROFCHARINASCII;i++){
        Last[i]=-1;
    }
    for(int i=0;i<pattern.length()+1;i++){
        BMNext[i]=0;
    }
    for(int k=0;k<pattern.length();k++){
        Last[pattern[k]]=k;
    }
    for(int k=0;k<text.length();k++){
        patternArray[k]=false;
    }

}

void BoyerMoore::goodSuffixHeuristics(){
    int m = pattern.length();
    int i = m;
    int b=m+1;//prefix-suffix location of the current suffix
    tempArray[i]=b;
    searchForPrefixSuffixPatternSuffixes();
    longestPrefixSuffix();
}

void BoyerMoore::searchForPrefixSuffixPatternSuffixes() {
    int i=pattern.length();
    int b=pattern.length()+1;
    while(i>0){
        while((b<=pattern.length())&&(pattern[i-1]!=pattern[b-1])){
            if(BMNext[b]==0){
                BMNext[b]=b-i;
            }
            b=tempArray[b];
        }
        b=b-1;
        i=i-1;
        tempArray[i]=b;
    }
}

void BoyerMoore::longestPrefixSuffix(){
    int  b=tempArray[0];
    for(int j=0;j<=pattern.length();j++){
        if(BMNext[j]==0){
            BMNext[j]=b;
        }
        if(j==b){
            b=tempArray[b];
        }
    }
}

void BoyerMoore::algorithm(){
    int i=0;
    int j;
    while(i<=text.length()-pattern.length()){
        j=pattern.length()-1;
        while((j>-1)&&(pattern[j]==text[i+j])){
            j--;
        }
        if(j==-1){
           patternSelection(i);
            i=i+BMNext[0];
        }
        else {
            i = i + optimalOffset(i,j);
        }
    }
   isPattern();
    for(int i=0;i<text.length();i++){
        HANDLE hOut;
        hOut = GetStdHandle( STD_OUTPUT_HANDLE );
        SetConsoleTextAttribute( hOut,  FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED );
        if(patternArray[i]==true){
            SetConsoleTextAttribute( hOut, FOREGROUND_BLUE | FOREGROUND_INTENSITY );
            cout << text[i];
        }else {
            cout << text[i];
        }
    }
}

void BoyerMoore::positionOfPattern(int i){
    cout<<"index of the beginning of the pattern: "<<endl;
    patternPosition=i;
    cout << patternPosition << endl;
}

void BoyerMoore::patternSelection(int i){
    positionOfPattern(i);
    for(int l=0;l<pattern.length();l++){
        patternArray[i+l]=true;
    }
}

int BoyerMoore::optimalOffset(int i,int j){
    return max(BMNext[j + 1], j - Last[text[i + j]]);
}

void BoyerMoore::isPattern(){
    if(patternPosition == -1){
        cout<<"search pattern is missing"<<endl;
    }
}