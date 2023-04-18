#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <ctype.h>
#include <unistd.h>
int main(){
int listener = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
if (listener == -1) {
    perror("socket failed");
    return 1;
}

struct sockaddr_in addr;
addr.sin_family = AF_INET;
addr.sin_addr.s_addr = htonl(INADDR_ANY);
addr.sin_port = htons(9000);

if (bind(listener,(struct sockaddr *)&addr,sizeof(addr))){
    perror("bind failed");
    return 1;
}

if (listen(listener,5)){
    perror("listen failed");
    return 1;
}
struct sockaddr_in client_addr;
int client_addr_len = sizeof(client_addr);

int client = accept(listener,(struct sockaddr *)&client_addr,&client_addr_len);

if (client == -1) {
    perror("accept failed");
    return 1;
}
printf("Accepted socket %d from IP: %s:%d \n ",client,inet_ntoa(client_addr.sin_addr),ntohs(client_addr.sin_port));


}
