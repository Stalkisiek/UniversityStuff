#include <iostream>
#include <filesystem>

using namespace std;

// g++ -std=gnu++17 2_3.cpp -o 2_3 <- while creating so it would be in correct standard (if not some dumb filesytem problem on my mac)

int main()
{
    // Poproś użytkownika o podanie ścieżki do katalogu
    std::cout << "Podaj ścieżkę do katalogu: ";
    string path_str;
    getline(cin, path_str);
    filesystem::path path(path_str);

    // Sprawdź, czy podana ścieżka jest katalogiem
    if (!filesystem::is_directory(path))
    {
        cout << "Podana ścieżka nie jest katalogiem." << endl;
        return 1;
    }

    // Przejdź przez katalog i wypisz nazwy zwykłych plików oraz ich rozmiary
    for (const auto &entry : filesystem::directory_iterator(path))
    {
        if (entry.is_regular_file())
        {
            cout << entry.path().filename().string() << " " << entry.file_size() << " B" << endl;
        }
    }

    return 0;
}
