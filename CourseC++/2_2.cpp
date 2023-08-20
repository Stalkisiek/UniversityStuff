#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

// random number generator
int randNum(int min, int max)
{
    return rand() % (max - min + 1) + min;
}

// quicksort
void quickSort(vector<int> &v, int left, int right)
{
    int i = left, j = right;
    int tmp;
    int pivot = v[(left + right) / 2];

    while (i <= j)
    {
        while (v[i] < pivot)
            i++;
        while (v[j] > pivot)
            j--;
        if (i <= j)
        {
            tmp = v[i];
            v[i] = v[j];
            v[j] = tmp;
            i++;
            j--;
        }
    };

    if (left < j)
        quickSort(v, left, j);
    if (i < right)
        quickSort(v, i, right);
}

vector<int> randomNrS(10000);

int main()
{
    for (int i = 0; i < 10000; i++)
    {
        randomNrS[i] = randNum(1, 10000);
    }
    for (int e : randomNrS)
    {
        cout << e << endl;
    }
    quickSort(randomNrS, 0, randomNrS.size() - 1);
    for (int e : randomNrS)
    {
        cout << e << endl;
    }

    return 0;
}