#include "Logger.h"
#include <cstdlib>
#include "ConfigParser.h"
#include "ManagerConnection.h"
#include <string>
#include <conio.h>
#include <exception>

// #include <iostream>
// #include <string>
// #include "ManagerConnection.h"
// #include "Logger.h"

int main(int argc, char *argv[])
{
    system("pause");
    // Check if the correct number of arguments are passed
    if (argc != 3)
    {
        std::cerr << "Usage: " << argv[0] << " <IP> <Port>" << std::endl;
        return 1;
    }

    // Get IP and port from command line arguments
    std::string managerIP = argv[1];      // First argument: IP address
    int managerPort = std::stoi(argv[2]); // Second argument: Port number

    // Log the start of the client connection attempt
    Logger::log("Starting Wazuh Client...", Logger::LogLevel::INFO);

    // Create a ManagerConnection object
    ManagerConnection connection(managerIP, managerPort);
    system("pause");
    // Try to connect to the manager
    if (!connection.connect())
    {
        Logger::log("Failed to connect to manager. Exiting...", Logger::LogLevel::error_info);
        return 1;
    }
    system("pause");
    // Simulate sending data (for example, send a simple message)
    std::string data = "Hello, Wazuh Manager!";
    if (!connection.sendData(data))
    {
        system("pause");
        Logger::log("Failed to send data.", Logger::LogLevel::error_info);
        system("pause");
        return 1;
    }

    // Close the connection once data is sent
    connection.closeConnection();
    system("pause");

    return 0;
}

// int main(int argc, char **argv)
// {
//     // Log the start of the client
//     Logger::log("Starting Wazuh Client...", Logger::LogLevel::INFO);
//     // std::cout << "aftab" << std::endl;
//     // Parse command-line arguments
//     ConfigParser config(argc, argv);
//     std::string managerIP = config.get("--manager-ip", "127.0.0.1");
//     std::string portStr = config.get("--manager-port", "1514");

//     int managerPort;
//     try
//     {
//         managerPort = std::stoi(portStr);
//         // std::cout << "aftab1" << std::endl;
//     }
//     catch (...)
//     {
//         Logger::log("Invalid port number. Exiting...", Logger::LogLevel::error_info);
//         return 1;
//     }

//     // Establish connection
//     ManagerConnection connection(managerIP, managerPort);
//     if (!connection.connect())
//     {
//         Logger::log("Failed to connect to manager. Exiting...", Logger::LogLevel::error_info);
//         return 1;
//     }

//     // Simulate data transmission
//     // std::cout << "aftab3" << std::endl;
//     std::string data = "Sample data to send.";
//     if (!connection.sendData(data))
//     {
//         Logger::log("Failed to send data. Exiting...", Logger::LogLevel::error_info);
//         return 1;
//     }

//     connection.closeConnection();
//     // std::cout << "aftab4" << std::endl;
//     Logger::log("Client terminated successfully.", Logger::LogLevel::INFO);

//     try
//     {
//         // Any additional operations that might throw an exception
//     }
//     catch (const std::exception &e)
//     {
//         Logger::log(std::string("Unexpected error: ") + e.what(), Logger::LogLevel::error_info);
//         return 1;
//     }
//     system("pause");

//     return 0;
// }
