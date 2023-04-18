#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
   int client = socket(AF_INET, SOCK_STREAM,IPPROTO_TCP);

struct sockaddr_in addr;
addr.sin_family = AF_INET;
addr.sin_addr.s_addr = inet_addr("127.0.0.1");
addr.sin_port = htons(9000);

char tenMT[15];
unsigned int soODia;
struct thongSoODia {
    char tenOdia;
    unsigned short kichThuoc;
};
struct thongSoODia* tsod;
char tsoOdia[64];
char sender[256];
while (1)
{
    /* code */
    printf("Nhap vao ten May tinh: ");
    scanf("%s", tenMT);

    printf("Nhap vao so o dia: ");
    scanf("%d", &soODia);

    tsod = malloc(sizeof(*tsod)*soODia);
    for (int i = 0; i < soODia;i++){
        printf("Nhap vao thong so o dia thu %d \n",i+1);
        getchar();
        printf("Nhap vao ten o dia: \n");
        scanf("%c",&tsod[i].tenOdia);
        printf("Nhap vao kich thuoc: \n");
        scanf("%hd",&tsod[i].kichThuoc);
    }
    int pos=0;
    for (int i = 0; i < soODia;i++){
        memcpy(tsoOdia+pos,&tsod[i].tenOdia,1);
        memcpy(tsoOdia+pos+1,&tsod[i].kichThuoc,2);
        pos+=3;
    }
    strcat(sender,tenMT);
    strcat(sender," ");
    strcat(sender,tsoOdia);
    printf("%s\n",sender);
    

}

}
