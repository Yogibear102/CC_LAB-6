#include <stdio.h>
#include <unistd.h>
#include <netinet/in.h>
#include <string.h>

int main()
{
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char hostname[1024];
    gethostname(hostname, sizeof(hostname));

    char buffer[1024];
    char response[2048];

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(8080);

    bind(server_fd, (struct sockaddr *)&address, sizeof(address));
    listen(server_fd, 3);

    while (1)
    {
        new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen);
        read(new_socket, buffer, 1024);
        snprintf(response, sizeof(response),
                 "HTTP/1.1 200 OK\r\nContent-Type: text/plain\r\n\r\nServed by backend: %s\n",
                 hostname);
        write(new_socket, response, strlen(response));
        close(new_socket);
    }
}