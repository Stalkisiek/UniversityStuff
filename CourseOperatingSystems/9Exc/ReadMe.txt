# Program wzajemnego wykluczania przy użyciu muteksów

Autor: Mateusz Migdal
Data: 15-06-23

## Opis

Program demonstruje implementację wzajemnego wykluczania przy użyciu muteksów. Wykorzystuje wątki do wykonania sekcji prywatnych i sekcji krytycznych, a także wspólną zmienną licznikową.

Program tworzy muteks, który chroni sekcję krytyczną, i każdy wątek wykonuje swoją sekcję prywatną, a następnie sekcję krytyczną, w której aktualizuje wartość globalnego licznika. Po zakończeniu działania wszystkich wątków, program wyświetla ostateczną wartość licznika oraz wartość oczekiwaną.

## Uruchamianie

make run1 ARGS={liczba_sekcji}

Po zakończeniu działania programu zostanie wyświetlona ostateczna wartość licznika oraz wartość oczekiwana. Upewnij się, że ostateczna wartość licznika jest zgodna z oczekiwaną wartością.
