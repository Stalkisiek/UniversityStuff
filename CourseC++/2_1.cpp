#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

// Funkcja pomocnicza, która dzieli wiersz na słowa
vector<string> split(string line)
{
    vector<string> words;
    istringstream iss(line);
    string word;
    while (iss >> word)
    {
        words.push_back(word);
    }
    return words;
}

int main(int argc, char *argv[])
{
    // W przypadku błędnego wywołania
    if (argc < 3)
    {
        cout << "Użycie: " << argv[0] << " plik_wejściowy szerokość_kolumny" << endl;
        return 1;
    }

    // Wczytaj nazwę pliku wejściowego i szerokość kolumny z argumentów wiersza poleceń. Łatwiej będzie odwoływać się do zmiennych ni indexu tablicy
    string input_file = argv[1];
    int column_width = stoi(argv[2]);

    // Otwórz plik wejściowy. Prosta obsługa błędu
    ifstream infile(input_file);
    if (!infile)
    {
        cout << "Nie można otworzyć pliku " << input_file << endl;
        return 1;
    }

    // Wczytaj wiersze z pliku i podziel na słowa
    vector<vector<string>> lines;
    string line;
    while (getline(infile, line))
    {
        vector<string> words = split(line);
        lines.push_back(words);
    }

    // Wyrównaj wiersze do zadanej szerokości kolumny
    for (vector<string> words : lines)
    {
        int line_length = 0;
        for (string word : words)
        {
            // Jeśli dodanie kolejnego słowa przekroczy szerokość kolumny, przejdź do nowej linii
            if (line_length + word.length() + 1 > column_width)
            {
                cout << endl;
                line_length = 0;
            }
            // Wypisz słowo z odstępem
            cout << word << " ";
            line_length += word.length() + 1;
        }
        cout << endl;
    }

    return 0;
}
