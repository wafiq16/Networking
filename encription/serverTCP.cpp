#include <unistd.h> 
#include <stdio.h> 
#include <sys/socket.h> 
#include <stdlib.h> 
#include <netinet/in.h> 
#include <string.h> 
#include <iostream>
#define PORT 8080 

using namespace std;

int main(int argc, char const *argv[]) 
{ 
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};
    // const char *pesanku = pesan.c_str();
    string pesan;
    char input[99];
    // cin >> noskipws >> huda;
    cin.getline(input,sizeof(input));
    pesan = string(input);
    
    const char *pesanku = pesan.c_str();

    // enkripsi pesan menggunakan rsa
    int p = 3,q = 7,n = p*q; // n = 21
    int m = (p-1)*(q-1); //m = 12

    // e = GCD(12,7) = 1 // e = 7

    // d = (d * e) mod m = 1 // d = 15

    // public key = (e,n) e = 7 n = 21
    // private key = (d,n) d = 15 n = 21
    int tampungValue[100][100];
    for(int i=0 ; i<pesan.length(); i++){
        for(int j=0 ; j<2 ; j++){
            tampungValue[i][j] = input[i];
            printf("tamp[%d][%d] = %d",i,j,tampungValue[i][j]);
        }
    }

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Forcefully attaching socket to the port 8080
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,
                                                  &opt, sizeof(opt)))
    {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons( PORT );

    // Forcefully attaching socket to the port 8080
    if (bind(server_fd, (struct sockaddr *)&address,
                                 sizeof(address))<0)
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    if (listen(server_fd, 3) < 0)
    {
        perror("listen");
        exit(EXIT_FAILURE);
    }
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address,
                       (socklen_t*)&addrlen))<0)
    {
        perror("accept");
        exit(EXIT_FAILURE);
    }
    
    valread = read( new_socket , buffer, 1024);
    printf("%s\n",buffer );
    send(new_socket , pesanku , strlen(pesanku) , 0 );
    
    // printf("Hello message sent\n"); 
    
    return 0; 
}