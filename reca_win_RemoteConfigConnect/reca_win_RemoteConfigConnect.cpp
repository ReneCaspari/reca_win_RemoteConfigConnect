#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <windows.h>

// Structure to hold server data
struct ServerInfo {
    std::string location;
    std::string serverName;
    std::string username;
    std::string ip;
};

// Function to create a default configuration file
void createDefaultConfig(const std::string& configFilePath) {
    std::ofstream configFile(configFilePath);
    if (configFile.is_open()) {
        configFile << "Location1 RODC1 adminUser1 192.168.0.11\n";
        configFile << "Location1 RODC2 adminUser2 192.168.0.12\n";
        configFile << "Location2 RODC3 adminUser3 192.168.0.13\n";
        configFile << "Location2 RODC4 adminUser4 192.168.0.14\n";
        configFile.close();
    }
    else {
        std::cerr << "Error creating the configuration file!" << std::endl;
    }
}

// Function to load the configuration file
std::unordered_map<std::string, std::vector<ServerInfo>> loadConfig(const std::string& configFilePath) {
    std::unordered_map<std::string, std::vector<ServerInfo>> config;
    std::ifstream configFile(configFilePath);
    if (configFile.is_open()) {
        std::string line;
        while (std::getline(configFile, line)) {
            std::istringstream iss(line);
            ServerInfo server;
            if (!(iss >> server.location >> server.serverName >> server.username >> server.ip)) {
                break;
            }
            config[server.location].push_back(server);
        }
        configFile.close();
    }
    else {
        std::cerr << "Error loading the configuration file!" << std::endl;
    }
    return config;
}

// Function to start the Remote Desktop connection
void startRemoteDesktop(const std::string& ip) {
    std::string command = "mstsc /v:" + ip;
    system(command.c_str());
}

int main() {
    const std::string configFilePath = "config.txt";
    std::ifstream configFile(configFilePath);

    // Check if the configuration file exists, if not, create it
    if (!configFile) {
        createDefaultConfig(configFilePath);
    }

    // Load the configuration file
    auto config = loadConfig(configFilePath);

    // Prompt user for location
    std::string chosenLocation;
    std::cout << "Please enter a location: ";
    std::cin >> chosenLocation;

    // Check if the chosen location is valid
    if (config.find(chosenLocation) == config.end()) {
        std::cerr << "Invalid location!" << std::endl;
        return 1;
    }

    // List available servers in the chosen location
    std::cout << "Available servers in " << chosenLocation << ":\n";
    const auto& servers = config[chosenLocation];
    for (size_t i = 0; i < servers.size(); ++i) {
        std::cout << i + 1 << ": " << servers[i].serverName << " (" << servers[i].ip << ")" << std::endl;
    }

    // Prompt user for server
    int selectedServer;
    std::cout << "Please choose a server (1, 2, ...): ";
    std::cin >> selectedServer;

    if (selectedServer < 1 || selectedServer > static_cast<int>(servers.size())) {
        std::cerr << "Invalid choice!" << std::endl;
        return 1;
    }

    const auto& chosenServer = servers[selectedServer - 1];
    std::cout << "Connecting to " << chosenServer.serverName << " (" << chosenServer.ip << ") as user " << chosenServer.username << std::endl;

    // Start the Remote Desktop connection
    startRemoteDesktop(chosenServer.ip);

    return 0;
}
