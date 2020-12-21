#include <stdio.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <unistd.h> 
#include <string.h> 
#include <iostream>
#define PORT 8080 
   
using namespace std;

int main(int argc, char const *argv[]) 
{ 
     int sock = 0, valread;
    struct sockaddr_in serv_addr;
    // const char * pesanku = "hallo saya wafiq hahahaha";
    // const char *pesanku = pesan.c_str();
    string pesan;
    char input[99];
    // cin >> noskipws >> huda;
    cin.getline(input,sizeof(input));
    pesan = string(input);
    
    const char *pesanku = pesan.c_str();
    
    int p = 3,q = 7,n = p*q;
    int m = (p-1)*(q-1); //m = 12

    // e = GCD(12,7) = 1 // e = 7

    // d = (d * e) mod m = 1 // d = 15

    // public key = (e,n) e = 7 n = 21
    // private key = (d,n) d = 15 n = 21

    char buffer[1024] = {0};
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("\n Socket creation error \n");
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if(inet_pton(AF_INET, "192.168.43.231", &serv_addr.sin_addr)<=0)
    {
        printf("\nInvalid address/ Address not supported \n");

    }

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        printf("\nConnection Failed \n");
    }
    send(sock , pesanku , strlen(pesanku) , 0 );
    // printf("Hello message sent\n");
    valread = read( sock , buffer, 1024);

    printf("%s\n",buffer );
    
    return 0; 
} 