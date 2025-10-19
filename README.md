# Secure MeshChat: Encrypted Ad Hoc Chat & Emergency Alerts for Disaster Scenarios

## Overview
Secure MeshChat is a decentralized communication application designed for disaster scenarios where traditional internet connectivity may be unavailable. This project implements an ad hoc mesh network that allows users to send encrypted messages and emergency alerts, ensuring secure and reliable communication in critical situations.

## Features
- **Ad Hoc Mesh Networking**: Nodes can connect and communicate without a central server, making it ideal for emergency situations.
- **End-to-End Encryption**: All messages are encrypted to protect user privacy and data integrity.
- **Emergency Alerts**: Users can send urgent alerts to all connected nodes, ensuring timely dissemination of critical information.

## Project Structure
```
secure-meshchat
├── src
│   ├── MeshChatApp.cc
│   ├── MeshChatApp.h
│   ├── MeshNode.cc
│   ├── MeshNode.h
│   ├── EncryptionModule.cc
│   ├── EncryptionModule.h
│   ├── EmergencyAlert.cc
│   └── EmergencyAlert.h
├── simulations
│   ├── omnetpp.ini
│   └── network.ned
├── networks
│   ├── MeshNetwork.ned
│   └── DisasterScenario.ned
├── results
├── Makefile
└── README.md
```

## Setup Instructions
1. **Clone the Repository**: Download the project files to your local machine.
2. **Install OMNeT++**: Ensure you have OMNeT++ installed on your system. Follow the installation instructions on the [OMNeT++ website](https://omnetpp.org).
3. **Build the Project**: Navigate to the project directory and run `make` to compile the source files.
4. **Run Simulations**: Use the provided `omnetpp.ini` configuration file to run simulations in OMNeT++.

## Usage Guidelines
- To start a chat session, initialize the `MeshChatApp` on each node.
- Use the `sendMessage` method to communicate with other nodes.
- In case of an emergency, utilize the `EmergencyAlert` class to broadcast alerts to all connected nodes.

## Contribution
Contributions to enhance the functionality and performance of Secure MeshChat are welcome. Please submit a pull request or open an issue for discussion.

## License
This project is licensed under the MIT License. See the LICENSE file for more details.