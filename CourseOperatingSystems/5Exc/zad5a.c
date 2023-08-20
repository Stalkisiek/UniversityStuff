/*Oliwia Rogowska*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <wait.h>
#define myfifo "/tmp/myfifo"

// Autor: Mateusz Migdal
// Data: 2023-05-17
// Opis: Program tworzy potok nazwany, a nastepnie uruchamia dwa programy: producent i konsument.

void removepipe(void)
{
    if (remove(myfifo) != 0)
    {
        perror("Error deleting pipe file\n");
        exit(EXIT_FAILURE);
    }
}

int main(int argc, char *argv[])
{
    atexit(removepipe);
    int id, id2;
    char *src_file_name = argv[1];
    char *dst_file_name = argv[2];

    mkfifo(myfifo, 0666);

    id = fork();

    if (id > 0)
    {
        execlp("./konsument", "konsument", dst_file_name, myfifo, NULL);
        perror("execlp error\n");
    }
    else if (id == 0)
    {
        execlp("./producent", "producent", src_file_name, myfifo, NULL);
        perror("execlp error\n");
    }
    else
    {
        perror("fork error\n");
        exit(EXIT_FAILURE);
    }
    close(*myfifo);
    exit(EXIT_SUCCESS);
}