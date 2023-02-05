/* A simple server in the internet domain using TCP
 * Answer the questions below in your writeup
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>

void error(const char *msg)
{
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[])
{
    /* 1. What is argc and *argv[]?
     * 
     argc and argv are an int and a char* array respectfully, relating to the arguemnts entered with the executable call. 
     argc is the number of arguments supplied, and argv is an array of char*s to each argument.
     */
    int sockfd, newsockfd, portno;
    /* 2. What is a UNIX file descriptor and file descriptor table?
     *
     A file descriptor is a positive integer used to identify an open file.
     A file descriptor table is a table stored in the kernel listing the file descriptors of open files, which processes use to manage those files.
     */
    socklen_t clilen;

    struct sockaddr_in serv_addr, cli_addr;
    /* 3. What is a struct? What's the structure of sockaddr_in?
     *
     A struct is a data structure, or in other words a new data type created by the programmer which groups variables of different existing data types
     in a specific order for the programmer's later use.
     
     sockaddr_in is a struct which represents an internet socket adrress. It contains a short called sin_family which specifies the adress family, 
     an unisgned short called sin_port which holds the port number, two structs in_addr and sin_addr which represent the IP adress, 
     and a char array sin_zero which is used to ensure that the sockaddr_in structure has the same size as the struck sockaddr, 
     which is a more generic socket address structure (so that they can be used interchangably).
     */
    
    int n;
    if (argc < 2) {
        fprintf(stderr,"ERROR, no port provided\n");
        exit(1);
    }
    
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    /* 4. What are the input parameters and return value of socket()
     *
     socket() takes three input parameters: \
     the first is an int "domain" which holds the adress family od the socket (such as AF_INET for internet adresses)
     the second is an int "type" which holds the type of the socket, for example SOCK_STREAM for a stream-oriented connection or
     SOCK_DGRAM for a connectionless communication
     the third is an int "protocol" which holds the protocol to be used, such as "IPPROTO_TCP" for TCP, "IPPROTO_UDP" for UDP,
     or 0 for the default protocol based on the first two input parameters
     */
    
    if (sockfd < 0) 
       error("ERROR opening socket");
    bzero((char *) &serv_addr, sizeof(serv_addr));
    portno = atoi(argv[1]);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);
    
    if (bind(sockfd, (struct sockaddr *) &serv_addr,
             sizeof(serv_addr)) < 0) 
             error("ERROR on binding");
    /* 5. What are the input parameters of bind() and listen()?
     *
     */
    
    listen(sockfd,5);
    clilen = sizeof(cli_addr);
    
    while(1) {
        /* 6.  Why use while(1)? Based on the code below, what problems might occur if there are multiple simultaneous connections to handle?
        *
        */
        
	char buffer[256];
        newsockfd = accept(sockfd, 
                    (struct sockaddr *) &cli_addr, 
                    &clilen);
	/* 7. Research how the command fork() works. How can it be applied here to better handle multiple connections?
         * 
         */
        
	if (newsockfd < 0) 
             error("ERROR on accept");
	bzero(buffer,256);
        
	n = read(newsockfd,buffer,255);
        if (n < 0) 
            error("ERROR reading from socket");
        printf("Here is the message: %s\n",buffer);
        n = write(newsockfd,"I got your message",19);
        buffer[255] = '\0';
        if (n < 0) 
            error("ERROR writing to socket");
        close(newsockfd);
    }
    close(sockfd);
    return 0; 
}
  
/* This program makes several system calls such as 'bind', and 'listen.' What exactly is a system call?
 *
 */
