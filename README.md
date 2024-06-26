# RemoteConfigConnect

RemoteConfigConnect is a simple C++ tool designed to initiate a Remote Desktop connection using a configuration file. This tool allows you to specify server locations and details in a config file, and easily connect to any server by selecting from the available options.

## Features

- Automatically creates a default configuration file if it doesn't exist.
- Reads server information from a configuration file.
- Prompts the user to select a location and lists available servers.
- Initiates Remote Desktop connections based on user selection.

## Prerequisites

- Windows Operating System
- C++ Compiler (e.g., MSVC, MinGW)
- Remote Desktop Connection (mstsc) installed

## Installation

1. **Clone the repository:**
    ```sh
    git clone https://github.com/ReneCaspari/reca_win_RemoteConfigConnect.git
    cd reca_win_RemoteConfigConnect
    ```

2. **Build the project:**
    - Open the project in your preferred C++ IDE or use a command line.
    - Compile the `main.cpp` file.

## Usage

1. **Run the application:**
    ```sh
    reca_win_RemoteConfigConnect.exe
    ```

2. **Follow the prompts:**
    - Enter the desired location.
    - Choose from the listed servers in that location.

## Configuration File

The configuration file (`config.txt`) is automatically created if it doesn't exist. It should contain entries in the following format:

Location1 RODC1 adminUser1 192.168.0.11
Location1 RODC2 adminUser2 192.168.0.12
Location2 RODC3 adminUser3 192.168.0.13
Location2 RODC4 adminUser4 192.168.0.14


Each line represents a server with the format:
<Location> <ServerName> <Username> <IP>


## Example

Here's an example session:

Please enter a location: Location1
Available servers in Location1:
1: RODC1 (192.168.0.11)
2: RODC2 (192.168.0.12)
Please choose a server (1, 2, ...): 1
Connecting to RODC1 (192.168.0.11) as user adminUser1

csharp
Code kopieren

## Contribution

Feel free to fork this repository, make changes, and submit pull requests. Any contributions are welcome!

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
Just replace yourusername with your actual GitHub username. This README file is formatted for GitHub and provides a clear guide for users to understand, install, and use the RemoteConfigConnect tool.
