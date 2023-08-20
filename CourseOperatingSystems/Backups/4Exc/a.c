#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <time.h>

#define BUF_SIZE 5  // porcje danych po 5 bajtów
#define MAX_DELAY 3 // maksymalny losowy czas usypiania w sekundach

// Autor = Mateusz Migdal
// Data = 2023-05-17
// Opis = Program tworzy proces potomny, który czyta dane z pliku wejściowego i przesyła je do procesu macierzystego przez potok. Proces macierzysty zapisuje dane do pliku wyjściowego. Procesy powinny działać współbieżnie, tzn. proces macierzysty powinien zapisywać dane do pliku wyjściowego w miarę ich otrzymywania od procesu potomnego. Proces potomny powinien przesyłać dane do procesu macierzystego w miarę ich czytania z pliku wejściowego. Procesy powinny działać do momentu przesłania wszystkich danych. Proces macierzysty powinien czekać na zakończenie procesu potomnego.

void print_error(char *message)
{
    perror(message);
    exit(1);
}

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Usage: %s <input-file> <output-file>\n", argv[0]);
        exit(1);
    }

    char *input_file = argv[1];
    char *output_file = argv[2];

    int pipefd[2];
    if (pipe(pipefd) == -1)
    {
        print_error("pipe");
        exit(2);
    }

    pid_t producer_pid = fork();
    if (producer_pid == -1)
    {
        print_error("fork");
        exit(3);
    }

    if (producer_pid == 0)
    {                     // producer process
        close(pipefd[0]); // close unused read end of the pipe

        int input_fd = open(input_file, O_RDONLY);
        if (input_fd == -1)
        {
            print_error("open");
            exit(4);
        }

        char buf[BUF_SIZE];
        ssize_t bytes_read;
        while ((bytes_read = read(input_fd, buf, BUF_SIZE)) > 0)
        {
            if (write(pipefd[1], buf, bytes_read) != bytes_read)
            {
                print_error("write");
                exit(5);
            }
            printf("Producer sent %ld bytes: ", bytes_read);
            printf("\n");
            sleep(rand() % MAX_DELAY); // simulate random delay
        }

        close(input_fd);
        close(pipefd[1]); // close write end of the pipe to signal end of transmission
        printf("Producer finished\n");
        exit(0);
    }

    if (producer_pid > 0)
    {                     // consumer process
        close(pipefd[1]); // close unused write end of the pipe

        int output_fd = open(output_file, O_WRONLY | O_CREAT | O_TRUNC, 0666);
        if (output_fd == -1)
        {
            print_error("open");
        }

        char buf[BUF_SIZE];
        ssize_t bytes_read;
        while ((bytes_read = read(pipefd[0], buf, BUF_SIZE)) > 0)
        {
            if (write(output_fd, buf, bytes_read) != bytes_read)
            {
                print_error("write");
            }
            printf("Consumer received %ld bytes: ", bytes_read);
            printf("\n");
            sleep(rand() % MAX_DELAY); // simulate random delay
        }
        close(output_fd);
        close(pipefd[0]); // close read end of the pipe
        printf("Consumer finished\n");
        exit(0);
    }

    close(pipefd[0]); // close both ends of the pipe to signal end of transmission
    close(pipefd[1]);

    waitpid(producer_pid, NULL, 0);

    return 0;
}
