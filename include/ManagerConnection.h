#ifndef MANAGERCONNECTION_H
#define MANAGERCONNECTION_H

#include <string>

class ManagerConnection
{
private:
    std::string managerIP;
    int managerPort;
    bool isConnected;

public:
    ManagerConnection(const std::string &ip, int port);
    bool connect();
    bool sendData(const std::string &data);
    void closeConnection();
};

#endif // MANAGERCONNECTION_H



