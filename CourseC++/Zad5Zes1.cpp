// Zad5Zes1.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <chrono>
#include <vector>

const int c1 = 1000;

using namespace std;
vector<long long int> f(c1);
int last = 0;
long long int fib(int n) {
	auto start = chrono::high_resolution_clock::now();
	n--;
	if (f[n] == 0 && last == 0) {
		long long x = 0, y = 1;
		for (size_t i = 0; i < n; i++)
		{
			f[i] = y;
			y += x;
			x = y - x;
			last++;
		}
		return y;
	}
	else if (f[n] == 0 && last > 0) {
		long long x = f[last - 1], y = f[last - 1] + f[last - 2];
		for (size_t i = last; i < n; i++){
			f[i] = y;
			y += x;
			x = y - x;
			last++;
		}
		return y;
	}
	else {
		return f[n];
	}
}

int main()
{
	while (true) {

		cout << "Wpisz n: ";
		int n;
		cin >> n;
		cout << fib(n) << endl;
	}

}