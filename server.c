#include<stdio.h>
#include<Winsock.h>
int main()
{
    char Sendbuf[100];
    char Receivebuf[100];
    int SendLen;
    int ReceiveLen;
    int Length;
    SOCKET socket_server;
    SOCKET socket_receive;

    SOCKADDR_IN Server_add;
    SOCKADDR_IN Client_add;

    WORD wVersionRequested;
    WSADATA wsaData;
    int error;

    wVersionRequested=MAKEWORD(2,2);
    error=WSAStartup(wVersionRequested,&wsaData);
    if(error!=0)
    {
        printf("加载套接字失败");
        return 0;
    }
    if(LOBYTE(wsaData.wVersion)!=2 || HIBYTE(wsaData.wVersion)!=2)
    {
        WSACleanup();
        return 0;
    }

    Server_add.sin_family=AF_INET;
    Server_add.sin_addr.S_un.S_addr=htonl(INADDR_ANY);
    Server_add.sin_port=htonl(5000);

    socket_server=socket(AF_INET,SOCK_STREAM,0);

    if(bind(socket_server,(SOCKADDR*)&Server_add,sizeof(SOCKADDR))==SOCKET_ERROR)
    {
        printf("绑定失败\n");
    }

    if(listen(socket_server,5)<0)
    {
        printf("监听失败\n");
    }

    Length=sizeof(SOCKADDR);
    socket_receive=accept(socket_server,(SOCKADDR*)&Client_add,&Length);
    if(socket_receive==SOCKET_ERROR)
    {
        printf("接受连接失败\n");
    }

    while(1)
    {
        ReceiveLen=recv(socket_server,Receivebuf,100,0);
        if(ReceiveLen<0)
        {
            printf("接收失败\n");
            printf("程序退出\n");
            break;
        }
        else
        {
            printf("client:%s\n",Receivebuf);
        }
        printf("请输入信息");
        scanf("%s,Sendbuf");
        SendLen=send(socket_server,Sendbuf,100,0);
        if(Sendbuf<0)
        {
            printf("发送失败\n");
        }
    }
    closesocket(socket_receive);
    closesocket(socket_server);
    WSACleanup();
    return 0;
}