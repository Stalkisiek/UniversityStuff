#include <iostream>


using namespace std;
void zadanie(int n, int m);

int main() {
	while (true) {
		cout << "Wpisz wartosc zewnetrznego boku: ";
		int n, m;
		cin >> n;
		cout << "Wpisz wartosc wewnetrznego boku: ";
		cin >> m;
		zadanie(n, m);
		cout << endl << endl;
	}
}
//n zewnętrzne; m wewnętrzne
void zadanie(int n, int m) {
	if (n < m) {
		cout << "Inside cannot be grater than outside" << endl;
		return;
	}
	//A co jeśli jedna jest parzysta a druga nie? Wtedy pierwszy bok ma wartość mniejszą od drugiego tak jakby
	int tempI = 0;
	int tempJ = 0;
	if (true) { // jeśli obie parzyste, albo nieparzyste to git
		//cout << n << m;
		for (int i = 0; i < n; i++) {
			
			bool temp1 = false;
			for (int j = 0; j < n; j++) {
				if (i >= (n - m) / 2 && tempI < m) {
					if (j >= (n - m) / 2 && tempJ < m) {
						//cout << tempI << " " << tempJ << endl;
						temp1 = true;
						cout << " ";
						tempJ++;
					}
					else { cout << "*"; }
				}
				else {
					cout << "*";

				}
			}
			tempJ = 0;
			if (temp1 == true) {
				tempI++;
			}
			cout << endl;
		}
	}
}