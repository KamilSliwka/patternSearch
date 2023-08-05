//
// Created by kamil on 02.08.2023.
//

#ifndef PATTERNSEARCH_BOYERMOORE_H
#define PATTERNSEARCH_BOYERMOORE_H
#include "iostream"

using namespace std;

class BoyerMoore {
private:
    string text;
    string pattern;
    int* Last;
    int* tempArray;
    int* BMNext;
    int patternPosition;
    bool* patternArray;
public:
    BoyerMoore(const string &text, const string &pattern);

    void initialization();

    void goodSuffixHeuristics();

    void searchForPrefixSuffixPatternSuffixes();

    void longestPrefixSuffix();

    void patternSearch();

    void isPattern();

    void positionOfPattern(int i);

    int optimalOffset(int i, int j);

    void algorithm();

    void patternSelection(int i);
};


#endif //PATTERNSEARCH_BOYERMOORE_H
