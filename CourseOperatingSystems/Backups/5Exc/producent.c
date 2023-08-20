#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

#define BUFFER_SIZE 10

// Autor: Mateusz Migdal
// Data: 2023-05-17
// Opis: Program producenta, czyli wysylajacy dane z pliku do potoku nazwanego.

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Wrong number of arguments (expected: source and destination file names)\n");
        exit(EXIT_FAILURE);
    }

    int fsrc, mf, bytesread;
    char buffer[BUFFER_SIZE];
    char *fsrcname = argv[1];
    char *myfifo = argv[2];

    fsrc = open(fsrcname, O_RDONLY, 0666);
    mf = open(myfifo, O_WRONLY);
    do
    {
        bytesread = read(fsrc, buffer, BUFFER_SIZE);
        if (bytesread == -1)
        {
            perror("read error\n");
            _exit(EXIT_FAILURE);
        }
        if (bytesread > 0)
        {
            if (-1 == write(mf, buffer, bytesread))
            {
                perror("write error\n");
                _exit(EXIT_FAILURE);
            }
            printf("Producer sent %d bytes\n", bytesread);
        }
    } while (bytesread > 0);

    close(fsrc);
    close(mf);
    _exit(EXIT_SUCCESS);
}
