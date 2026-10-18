#include<sys/socket.h>
#include<iostream>
#include<cstring>
#include<unistd.h>
#include<netinet/in.h>

/*Essentially GeeksforGeeks example*/

int main(int argc, char* argv[])
{
    // Create socket
    int serverSocket = socket(AF_INET, SOCK_STREAM, 0);


    // Specify Address
    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(8080);
    serverAddress.sin_addr.s_addr = INADDR_ANY;

    // Binding socket
    bind(serverSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress));

    std::cout << "HTTPME Server running" << '\n';

    // Listening to assigned socket
    listen(serverSocket, 5);

    // Accepting connection request
    int clientSocket = accept(serverSocket, nullptr, nullptr);

    // Receiving data
    char buffer[1024] = {0};
    recv(clientSocket, buffer, sizeof(buffer), 0);
    std::cout << "Message from client: " << buffer << '\n';
        
    catch(const char* message)
    {
        // Closing the socket
        close(serverSocket);
    }

    return 0;
    
}
