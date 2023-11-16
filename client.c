#include<stdio.h>
#include<winsock.h>
int main()
{
    char Sendbuf[100];
    char Receivebuf[100];
    int Sendlen;
    int Receivelen;
    SOCKET socket_send;
    SOCKADDR_IN Server_add;
    WORD wVersionRequested;
    WSADATA wsaData;
    int error;
    wVersionRequested=MAKEWORD(2,2);
    error=WSAStartup(wVersionRequested,&wsaData);
    if(error!=0)
    {
        printf("加载套接字失败\n");
        return 0;
    }
    if(LOBYTE(wsaData.wVersion)!=2||HIBYTE(wsaData.wVersion)!=2)
    {
        WSACleanup();
        return 0;
    }
    Server_add.sin_family=AF_INET;
    Server_add.sin_addr.S_un.S_addr=inet_addr("127.0.0.1");
    Server_add.sin_port=htons(5000);
    socket_send=socket(AF_INET,SOCK_STREAM,0);
    if(connect(socket_send,(SOCKADDR*)&Server_add,sizeof(SOCKADDR))==SOCKET_ERROR)
    {
        printf("连接失败\n");
    }
    while(1)
    {
        printf("请输入信息：\n");
        scanf("%s",Sendbuf);
        Sendlen=send(socket_send,Sendbuf,100,0);
        if(Sendlen<0)
        {
            printf("发送失败\n");
        }
        Receivelen=recv(socket_send,Receivebuf,100,0);
        if(Receivelen<0)
        {
            printf("接收失败\n");
            printf("程序退出\n");
            break;
        }
        else
        {
            printf("Server say:%s\n",Receivebuf);
        }
    }
    closesocket(socket_send);
    WSACleanup();
    return 0;
}