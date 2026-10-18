#include<iostream>
#include<sys/socket.h>
#include<cstring>
#include<netinet/in.h>
#include<unistd.h>

/*Essentially GeeksforGeeks example*/

int main(int argc, char* argv[])
{
    // Creating Socket
    int clientSocket = socket(AF_INET, SOCK_STREAM, 0);

    // Specifying Address
    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(8080);
    serverAddress.sin_addr.s_addr = INADDR_ANY;

    // Sending connection request
    connect(clientSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress));

    // Sending data
    const char* message = argv[1];
    send(clientSocket, message, strlen(message), 0);

    // Close socket
    close(clientSocket);

    return 0;

}
