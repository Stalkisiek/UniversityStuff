#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <mqueue.h>

#define MAX_EXPRESSION_LENGTH 50

/*AUTOR: Mateusz Migdal
Data: 14-06-23

*/

int main()
{
    char server_queue_name[] = "/server_queue";
    char client_queue_name[20];
    pid_t pid = getpid();
    snprintf(client_queue_name, sizeof(client_queue_name), "/%d", pid);

    struct mq_attr attr;
    attr.mq_flags = 0;
    attr.mq_maxmsg = 10;
    attr.mq_msgsize = MAX_EXPRESSION_LENGTH;
    attr.mq_curmsgs = 0;

    mqd_t server_queue, client_queue;
    server_queue = mq_open(server_queue_name, O_WRONLY);
    client_queue = mq_open(client_queue_name, O_RDONLY | O_CREAT, 0666, &attr);

    if (server_queue == -1 || client_queue == -1)
    {
        perror("mq_open");
        exit(1);
    }

    char expression[MAX_EXPRESSION_LENGTH];
    char message_buffer[MAX_EXPRESSION_LENGTH + sizeof(pid_t)];
    ssize_t bytes_read;

    printf("Enter an arithmetic expression (e.g., 2+3): ");
    while (fgets(expression, sizeof(expression), stdin) != NULL)
    {
        snprintf(message_buffer, sizeof(message_buffer), "%d %s", pid, expression);

        if (mq_send(server_queue, message_buffer, strlen(message_buffer), 0) == -1)
        {
            perror("mq_send");
            exit(1);
        }

        bytes_read = mq_receive(client_queue, message_buffer, sizeof(message_buffer), NULL);
        if (bytes_read == -1)
        {
            perror("mq_receive");
            exit(1);
        }

        printf("Result: %.*s\n", (int)bytes_read, message_buffer);
        printf("Enter an arithmetic expression (e.g., 2+3): ");
    }

    mq_close(server_queue);
    mq_close(client_queue);
    mq_unlink(client_queue_name);

    return 0;
}
