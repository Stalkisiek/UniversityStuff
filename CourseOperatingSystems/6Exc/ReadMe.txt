AUTOR: Mateusz Migdal
Data: 14-06-23
--------------------------------------
Klient-Serwer z użyciem kolejek komunikatów POSIX
--------------------------------------

Prosty program klient-serwer, który umożliwia klientowi wysłanie żądania wykonania operacji arytmetycznej do serwera poprzez kolejki komunikatów POSIX. Serwer odbiera żądanie, wykonuje odpowiednią operację i odsyła wynik do klienta.

Instrukcje kompilacji:
----------------------

Aby skompilować program klienta i serwera, wykonaj poniższe kroki:

1. Skompiluj programy klienta i serwera, wykonując polecenie 'make'.

Instrukcje uruchomienia:
------------------------

Aby uruchomić program klienta i serwera, wykonaj poniższe kroki:

1. Uruchom program serwera, wpisując polecenie './server' w terminalu.
2. Uruchom program klienta, wpisując polecenie './client' w innym terminalu.
3. Wprowadź operację arytmetyczną w formacie 'liczba operator liczba' i naciśnij Enter w programie klienta.
4. Wynik operacji arytmetycznej zostanie wyświetlony na ekranie klienta.
5. Możesz kontynuować wprowadzanie kolejnych operacji arytmetycznych w programie klienta.
6. Aby zakończyć programy klienta i serwera, naciśnij kombinację klawiszy 'Ctrl+C' w odpowiednich terminalach.

Czyszczenie:
------------

Aby usunąć skompilowane pliki, wykonaj polecenie 'make clean'.

--------------------------------------
