// Zad3Zes1.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    string s1, s2;
    getline(cin, s1);
    vector<char> c1;
    vector<char> c2;
    for (int i = 0; i < s1.length(); i++) {
        if (s1[i] != ' ') {
            c1.push_back(tolower(s1[i]));
        }
    }
    for (int i = c1.size() - 1; i >= 0; i--) {
        c2.push_back(c1[i]);
    }
    for (char e : c2) {
        //cout << e;
    }
    cout << endl;
    if (c1 == c2) {
        cout << "Palindrom" << endl;
    }
    else {
        cout << "Nie palindrom" << endl;
    }
}

/*
char c1[1000] = {NULL};
    char c2[1000] = {NULL};
    for (int i = 0; i < s1.length(); i++) {
        if (s1[i] != ' ') {
            c1[i] = tolower(s1[i]);
        }
    }
    for (int i = 0; i < s2.length(); i++) {
        if (s2[i] != ' ') {
            c2[i] = tolower(s2[i]);
        }
    }
    int tempJ = 0;
    for (int i = 0; i < 1000; i++) {
        if (tempJ != 0) {
            if()
        }
        else if(c2[i] == NULL) {
            tempJ = i;
            i = -1;
        }
    }
*/