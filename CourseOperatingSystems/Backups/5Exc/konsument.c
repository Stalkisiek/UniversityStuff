#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

#define BUFFER_SIZE 10

// Autor: Mateusz Migdal
// Data: 2023-05-17
// Opis: Program konsumenta, czyli odbierajacy dane z potoku nazwanego i zapisujacy je do pliku.

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Wrong number of arguments (expected: source and destination file names)\n");
        exit(EXIT_FAILURE);
    }

    int fdst, mf, bytesread;
    char buffer[BUFFER_SIZE];
    char *dstname = argv[1];
    char *myfifo = argv[2];

    fdst = open(dstname, O_WRONLY | O_CREAT | O_TRUNC, 0666);
    mf = open(myfifo, O_RDONLY);
    do
    {
        bytesread = read(mf, buffer, BUFFER_SIZE);
        if (bytesread == -1)
        {
            perror("read error\n");
            _exit(EXIT_FAILURE);
        }

        if (bytesread > 0)
        {
            if (-1 == write(fdst, buffer, bytesread))
            {
                perror("write error\n");
                _exit(EXIT_FAILURE);
            }
            printf("Consumer received %d bytes\n", bytesread);
        }
    } while (bytesread > 0);

    close(fdst);
    close(mf);
    _exit(EXIT_SUCCESS);
}
