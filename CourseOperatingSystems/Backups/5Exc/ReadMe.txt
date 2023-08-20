!!!NAJPIERW /*make all*/!!!

// Zadanie a
Aby uruchomić program należy w konsoli wpisać : make run1 ARGS="<nazwa pliku source> <nazwa pliku destination>"
Opis zadania:
Program tworzy potok nazwany, a nastepnie uruchamia dwa programy: producent i konsument.
Program producenta, czyli wysyłający dane z pliku do potoku nazwanego.
Program konsumenta, czyli odbierający dane z potoku nazwanego i zapisujący je do pliku.
Na koncu w Makefile dochodzi do porownania plikow wejsciowego i wyjsciowego.


// Zadanie b
Aby uruchomić program należy w konsoli wpisać : make run2 src="<nazwa pliku>" dst="<nazwa pliku>"
Opis zadania:
Program tworzy potok nazwany w Makefile i przy uzyciu xterm uruchamia dwa programy: producent i konsument.
Program producenta, czyli wysyłający dane z pliku do potoku nazwanego.
Program konsumenta, czyli odbierający dane z potoku nazwanego i zapisujący je do pliku.
Na koncu w Makefile dochodzi do porownania plikow wejsciowego i wyjsciowego.

//Make 
make clean <- usuwa pliki wykonywalne + .o
make tar <- taruje wszystkie pliki