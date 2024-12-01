#include "ManagerConnection.h"
#include "Logger.h"
#include <winsock2.h>
#include <ws2tcpip.h>
#include <string>
#include <windows.h>  // Include windows.h first
#include <winsock2.h> // Include winsock2.h after windows.h

// Constructor implementation (unchanged)
ManagerConnection::ManagerConnection(const std::string &ip, int port)
    : managerIP(ip), managerPort(port), isConnected(false) {}

// Connect method with Winsock implementation
bool ManagerConnection::connect()
{
    // Initialize Winsock
    WSADATA wsaData;
    SOCKET ConnectSocket = INVALID_SOCKET;
    struct sockaddr_in clientService;

    // Initialize Winsock
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
    {
        Logger::log("WSAStartup failed", Logger::LogLevel::error_info);
        return false;
    }

    // Create a socket for connecting to the server
    ConnectSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (ConnectSocket == INVALID_SOCKET)
    {
        Logger::log("Error at socket(): " + std::to_string(WSAGetLastError()), Logger::LogLevel::error_info);
        WSACleanup();
        return false;
    }

    // Setup the sockaddr_in structure for the connection
    clientService.sin_family = AF_INET;
    clientService.sin_addr.s_addr = inet_addr(managerIP.c_str()); // Convert IP address to binary format
    clientService.sin_port = htons(managerPort);                  // Convert port number to network byte order

    // Connect to the server
    if (::connect(ConnectSocket, (struct sockaddr *)&clientService, sizeof(clientService)) == SOCKET_ERROR)
    {
        Logger::log("Unable to connect to manager at " + managerIP + ":" + std::to_string(managerPort) +
                        ". Error code: " + std::to_string(WSAGetLastError()),
                    Logger::LogLevel::error_info);
        closesocket(ConnectSocket);
        WSACleanup();
        return false;
    }
    else
    {
        Logger::log("Successfully connected to manager at " + managerIP + ":" + std::to_string(managerPort), Logger::LogLevel::INFO);
        isConnected = true;
    }

    // Connection successful

    // Clean up and close the socket after successful connection (for testing)
    closesocket(ConnectSocket);
    WSACleanup();

    return true;
}

// Send data (no changes needed here)
bool ManagerConnection::sendData(const std::string &data)
{
    if (!isConnected)
    {
        Logger::log("Not connected. Cannot send data.", Logger::LogLevel::error_info);
        return false;
    }
    Logger::log("Sending data: " + data, Logger::LogLevel::INFO);

    // Implement your data transmission logic here
    return true; // Simulating a successful send
}

// Close the connection (no changes needed here)
void ManagerConnection::closeConnection()
{
    if (isConnected)
    {
        Logger::log("Closing connection.", Logger::LogLevel::INFO);
        // Add your disconnection logic here
        isConnected = false;
    }
}
