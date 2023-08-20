// Zad2Zes1.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>

using namespace std;
void zadanie() {
    char arr1[1000]; cin.getline(arr1, 999);
    char arr2[1000]; cin.getline(arr2, 999);
    for (size_t i = 0; i < 1000; i++)
    {
        if (arr1[i] != arr2[i]) {
            cout << "Rozne" << endl;
            return;
        }
    }
    cout << "Takie same" << endl;
}
int main()
{
    zadanie();
}
