// Server side C/C++ program to demonstrate Socket programming 
// Here's some include statements that might be helpful for you
#include <string> 
#include <cstring>
#include <iostream>
#include <stdlib.h>
#include <sys/socket.h> 
#include <netdb.h>
#include <netinet/in.h> 
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char const *argv[]) 
{ 
	// check to see if user input is valid
	char socket_read_buffer[1024];
	
	// TODO: Fill out the server ip and port
	std::string server_ip = "";
	std::string server_port = "";

	int opt = 1;
	int client_fd = -1;

	// TODO: Create a TCP socket()
	client_fd = socket(AF_INET, SOCK_STREAM, 0);
	
	// Enable reusing address and port
	if (setsockopt(client_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) { 
		return -1;
	}

	// Check if the client socket was set up properly
	if(client_fd < 0){
		printf("Error- Client socket setup failed");
		return -1;
	}
	
	// Helping you out by pepping the struct for connecting to the server
	struct addrinfo hints;
	struct addrinfo *server_addr;
	memset(&hints, 0, sizeof(hints));
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;
	getaddrinfo(server_ip.c_str(), server_port.c_str(), &hints, &server_addr);

	// TODO: Connect() to the server (hint: you'll need to use server_addr)
	if (connect(client_fd, server_addr->ai_addr, len(server_addr->ai_addr)) < 0) {
		std::cout << "Failed to connect to server" << std::endl;
		return 1;
	}
	
	// TODO: Retreive user input
	std::cout << "Enter a message to send: << std::endl;
	char userInput[256];
	std::cin >> userInput;
	userInput[255] = '\0';
	
	// TODO: Send() the user input to the server
	send(client_fd, userInput, strlen(userInput), 0);
	    
	// TODO: Recieve any messages from the server and print it here. Don't forget to make sure the string is null terminated!
	char serverMessage[256];
	recv(client_fd, &serverMessage, sizeof(serverMessage), 0);
	serverMessage[255] = '\0';
	std::cout << "Server Message: " << serverMessage << std::endl;
	     
	// TODO: Close() the socket
	close(client_fd);

	return 0; 
} 
