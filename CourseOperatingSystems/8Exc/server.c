#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <mqueue.h>
#include <signal.h>

#define MAX_EXPRESSION_LENGTH 50
char server_queue_name[] = "/server_queue";
mqd_t server_queue;

void handle_exit()
{
    // Zamknięcie i usunięcie kolejki serwera
    mq_close(server_queue);
    mq_unlink(server_queue_name);
}

void handle_sigint(int sig)
{
    exit(0);
}

int main()
{

    char client_queue_name[20];
    char expression[MAX_EXPRESSION_LENGTH];
    char message_buffer[MAX_EXPRESSION_LENGTH + sizeof(pid_t)];
    pid_t client_pid;
    struct mq_attr attr;

    // Inicjalizacja atrybutów kolejki serwera
    attr.mq_flags = 0;
    attr.mq_maxmsg = 10;
    attr.mq_msgsize = MAX_EXPRESSION_LENGTH;
    attr.mq_curmsgs = 0;

    // Utworzenie kolejki serwera
    server_queue = mq_open(server_queue_name, O_RDONLY | O_CREAT, 0666, &attr);
    if (server_queue == -1)
    {
        perror("mq_open");
        exit(1);
    }

    // Rejestracja funkcji obsługującej zamknięcie kolejki serwera
    atexit(handle_exit);

    // Rejestracja obsługi sygnału SIGINT
    signal(SIGINT, handle_sigint);

    while (1)
    {
        ssize_t bytes_read = mq_receive(server_queue, message_buffer, sizeof(message_buffer), NULL);
        if (bytes_read == -1)
        {
            perror("mq_receive");
            exit(1);
        }

        sscanf(message_buffer, "%d %[^\n]", &client_pid, expression);
        snprintf(client_queue_name, sizeof(client_queue_name), "/%d", client_pid);

        // Otwarcie kolejki klienta w trybie do nadawania komunikatów
        mqd_t client_queue = mq_open(client_queue_name, O_WRONLY);
        if (client_queue == -1)
        {
            perror("mq_open");
            exit(1);
        }

        // Wykonanie operacji arytmetycznej
        int num1, num2;
        char operator;
        sscanf(expression, "%d %c %d", &num1, &operator, & num2);

        int result;
        switch (operator)
        {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            result = num1 / num2;
            break;
        default:
            result = 0;
        }

        // Wysłanie wyniku do kolejki klienta
        snprintf(message_buffer, sizeof(message_buffer), "%d", result);
        if (mq_send(client_queue, message_buffer, strlen(message_buffer), 0) == -1)
        {
            perror("mq_send");
            exit(1);
        }

        mq_close(client_queue);
    }

    return 0;
}
