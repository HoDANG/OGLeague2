#include <iostream>
#include "net/netserver.h"

using namespace std;

NetServer *server;

class BasicClient : public NetClient
{
public:
    void OnConnected(uint32_t cid)
    {
        cout<<"Got client: "<<cid<<endl;
    }
};


int main()
{
    enet_initialize();
    auto client = new BasicClient;
    server = new NetServer(client, ENET_HOST_ANY, 5119, "GLzvuWtyCfHyGhF2", 2);
    if(!server->start())
    {
        cout<<"Failed to start server!"<<endl;
        return 0;
    }
    while(true)
    {
        server->host();
    }
    return 0;
}
