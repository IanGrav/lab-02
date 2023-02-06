# Lab 2
[Fork](https://docs.github.com/en/get-started/quickstart/fork-a-repo) this repo and clone it to your machine to get started!

## Team Members
- Ian Gravallese


## Lab Question Answers

QA.1 - QA.3)

Question 1: How did the reliability of UDP change when you added 50% loss to your local
environment? Why did this occur?

Answer for Question 1: 
Only around %50 of the messages were sent (actually, it was 4/10), so the reliability of the connection was affected essentially 1:1 with the imposed loss.

Question 2: How did the reliability of TCP change? Why did this occur?

Answer for Question 2: 
The reliability of TCP did not change; all meesages were delivered.

Question 3: How did the speed of the TCP response change? Why might this happen?

Answer for Question 3: 
The speed of the TCP response was slower with the imposed %50 loss. This is likely because the network has to work to establish which packets were lost (not delivered) and to retreive/retransmit them.



QC.1 - QC.7)

/* 1. What is argc and *argv[]?
     * 
     argc and argv are an int and a char* array respectfully, relating to the arguemnts entered with the executable call. 
     argc is the number of arguments supplied, and argv is an array of char*s to each argument.
*/

/* 2. What is a UNIX file descriptor and file descriptor table?
     *
     A file descriptor is a positive integer used to identify an open file.
     A file descriptor table is a table stored in the kernel listing the file descriptors of open files, which processes use to manage those files.
*/

/* 3. What is a struct? What's the structure of sockaddr_in?
     *
     A struct is a data structure, or in other words a new data type created by the programmer which groups variables of different existing data types
     in a specific order for the programmer's later use.
     
     sockaddr_in is a struct which represents an internet socket adrress. It contains a short called sin_family which specifies the adress family, 
     an unisgned short called sin_port which holds the port number, two structs in_addr and sin_addr which represent the IP adress, 
     and a char array sin_zero which is used to ensure that the sockaddr_in structure has the same size as the struct sockaddr, 
     which is a more generic socket address structure (so that they can be used interchangably).
*/

/* 4. What are the input parameters and return value of socket()
     *
     socket() takes three input parameters:
     The first is an int "domain" which holds the adress family of the socket (such as AF_INET for an IPv4 internet adress).
     The second is an int "type" which holds the type of the socket, for example SOCK_STREAM for a stream-oriented connection or
     SOCK_DGRAM for a connectionless communication.
     The third is an int "protocol" which holds the protocol to be used, such as "IPPROTO_TCP" for TCP, "IPPROTO_UDP" for UDP,
     or 0 for the default protocol based on the first two input parameters.
     
     The return value of the socket() function is an integer which holds the file descriptor for the newly created socket 
     (which is a positive number), or a negative number if there was an error creating the socket.
*/

/* 5. What are the input parameters of bind() and listen()?
     *
     bind() takes three input parameters:
     The first, an int "sockfd", holds the file descriptor of the socket which will be binded to a local adress.
     The second, an addr*, is a pointer to a sockaddr struct which holds the local adress to be binded to. In the case of
     internet sockets, the sockaddr struct will be of the sockadr_in type.
     The third input parameter is the size of the sockaddr structure in bytes, held in an unsigned integer type "socklen_t".
     
     listen() takes two input parameters:
     The first is an int "sockfd" which holds the file descriptor of the socket to be listened to.
     The second is an int "backlog" which indicates highest number of pending connections that can be queued to
     be accepted by the accept() function.
*/

/* 6.  Why use while(1)? Based on the code below, what problems might occur if there are multiple simultaneous connections to handle?
        *
	A while loop is used here so that the server continuously listens for incomming connections; 
	it will accept and process incoming connections one by one
	If there are multiple connections to handle, the server might not handle all of them efficiently, 
	so there might be delays or dropped connections.
*/

/* 7. Research how the command fork() works. How can it be applied here to better handle multiple connections?
         * 
	 The fork() command duplicates the calling process to create a new child process. It returns 0 in the child process, and the process
	 ID of the child process in the parent (calling) process.
	 The fork() command can be applied here by being used to create a child process for for every incoming connection request,
	 so that the parent function accept() can continue accepting incoming connections without having to wait for the previous
	 connections to be completed, because each connection will be handled in its own child process.
*/

/* This program makes several system calls such as 'bind', and 'listen.' What exactly is a system call?
    *
     A system call is a call made from a user program to the operating system to complete a certain task. The OS then completes that task
     and returns the result of said task to the user program. 
     Basically, system calls interface between user programs and the OS so that users can make use of the OS and the capabilities it provides.
*/

