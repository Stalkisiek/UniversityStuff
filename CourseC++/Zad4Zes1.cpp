// Zad4Zes1.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <chrono>

using namespace std;

int a(int n) {
    if (n <= 2) {
        return 1;
    }
    return a(n - 1) + a(n - 2);
}

int b(int n) {
    n--;
    long long x = 0, y = 1;
    for (int i = 0; i < n; i++) {
        //cout << y << " ";
        y += x;
        x = y - x;
    }
    return y;
}

int main()
{
    while (true) {
        cout << "Wpisz n: ";
        int n;
        cin >> n;
        auto start = chrono::high_resolution_clock::now();
        cout << "Rekurencyjnie " << a(n) << endl;
        auto stop = chrono::high_resolution_clock::now();
        auto dur = chrono::duration_cast<chrono::microseconds>(stop - start);
        cout <<"Komplikacja czasowa rekurencyjnego rozwiazania: " << dur.count() << endl;

        start = chrono::high_resolution_clock::now();
        cout << " Iteracyjnie: " << b(n) << endl;
        stop = chrono::high_resolution_clock::now();
        dur = chrono::duration_cast<chrono::microseconds>(stop - start);
        cout << "Komplikacja czasowa iteracyjnego rozwiazania: " << dur.count() << endl << endl;
    }
}
