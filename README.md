<img width="616" height="614" alt="omnet jpg" src="https://github.com/user-attachments/assets/36843944-f29b-4221-8cbd-c6466e9c34f3" />
<img width="1091" height="693" alt="omneet jpg" src="https://github.com/user-attachments/assets/5578fb70-6ed8-4047-80bd-a2683954133c" />
<img width="616" height="614" alt="omnet jpg" src="https://github.com/user-attachments/assets/647c107c-1e34-47f0-b80d-d6315a6573b1" />
# 🔐 Secure MeshChat

**Encrypted ad hoc mesh chat and emergency alert simulation for disaster scenarios (OMNeT++).**

Secure MeshChat models a decentralized communication network where nodes exchange encrypted chat messages and high-priority emergency alerts without relying on central infrastructure. The project focuses on resilience, multi-hop forwarding, mobility, and secure message exchange under realistic network conditions.

---

## 📌 Table of Contents

- [Project Overview](#-project-overview)
- [Key Features](#-key-features)
- [Security & Cryptography](#-security--cryptography)
- [How It Works](#-how-it-works)
- [Repository Structure](#-repository-structure)
- [Requirements](#-requirements)
- [Build & Run](#-build--run)
- [Simulation Configurations](#-simulation-configurations)
- [Outputs & Results](#-outputs--results)
- [Known Limitations](#-known-limitations)
- [License](#-license)

---

## 🌐 Project Overview

In emergency or disaster contexts, traditional communication infrastructure may be unavailable. This project explores a **peer-to-peer mesh communication model** where each node can:

- Discover nearby peers via static topology connections.
- Exchange encrypted payloads using shared keys derived from ECDH.
- Relay messages across multiple hops.
- Broadcast emergency alerts with high propagation priority.
- Continue operation under packet loss, mobility, and node/link failures.

The system is implemented as an OMNeT++ simulation and designed to help evaluate behavior under stress conditions.

---

## ✅ Key Features

- **Multi-hop mesh forwarding** with TTL-based flood control.
- **End-to-end encrypted messaging** between peers.
- **Emergency alert broadcasting** for network-wide dissemination.
- **Mobility simulation** for selected nodes.
- **Link and node failure simulation** to test resilience.
- **Queue-based transmission handling** for per-gate traffic control.
- **Performance metrics collection** (delivery ratio, sent/dropped/delivered counts).

---

## 🔒 Security & Cryptography

The cryptographic module (`src/Crypto.cc`) uses OpenSSL to secure message exchange.

- **Key Exchange:** ECDH using `secp256r1` (`prime256v1`)
- **Key Derivation:** HKDF with SHA-256
- **Message Encryption:** AES-256-GCM
- **Integrity/Authentication:** Provided by GCM authentication tag
- **Randomness:** OpenSSL `RAND_bytes` for IV/random material

> Note: This is a simulation-focused implementation and should be additionally hardened before production use.

---

## ⚙️ How It Works

At a high level:

1. Nodes initialize and generate local EC key pairs.
2. Neighboring nodes exchange public keys.
3. Shared session keys are derived per peer.
4. Nodes generate chat/emergency traffic using scheduled events.
5. Messages are encrypted, forwarded hop-by-hop, and decrypted at recipients.
6. TTL and duplicate controls reduce uncontrolled flooding.
7. Node mobility, link failures, and node failures affect delivery paths.

Core modules:

- `MeshNode` — node behavior, routing/forwarding, timers, failure handling, metrics.
- `Crypto` — key generation, shared-key derivation, AES-GCM encryption/decryption.
- `ChatMessage.msg` — OMNeT++ message definition used across nodes.

---

## 📁 Repository Structure

```text
secure-meshchat/
├── src/
│   ├── MeshNode.cc / MeshNode.h      # Main mesh node logic
│   ├── MeshNode.ned                  # Node NED definition
│   ├── Crypto.cc / Crypto.h          # Crypto primitives and key handling
│   ├── ChatMessage.msg               # Message schema
│   ├── MeshChatApp.*                 # Additional app-level module files
│   ├── EmergencyAlert.*              # Emergency alert module files
│   └── EncryptionModule.*            # Encryption module files
├── simulations/
│   ├── network.ned                   # MeshChatNetwork topology
│   ├── omnetpp.ini                   # Runtime/simulation configurations
│   └── results/                      # Generated simulation outputs (.sca/.vec/.vci)
├── Makefile
└── README.md
```

---

## 🧰 Requirements

- **OMNeT++** 6.2.0 (or compatible 6.x environment)
- **C++ toolchain** supported by OMNeT++
- **OpenSSL** 3.x development libraries

Ensure OMNeT++ environment variables are configured in your shell before building.

---

## 🚀 Build & Run

From the repository root:

```bash
cd /home/runner/work/secure-meshchat/secure-meshchat
opp_makemake -f --deep
make
```

Then launch the simulation environment (GUI mode):

```bash
omnetpp
```

Inside OMNeT++:

1. Open the project/workspace.
2. Load `simulations/omnetpp.ini`.
3. Choose a configuration (e.g., `QuickDemo`, `SuperFast`, `Broadcast`).
4. Run and inspect vectors/scalars in the results view.

---

## 🧪 Simulation Configurations

Defined in `simulations/omnetpp.ini`:

- **General**: baseline parameters (packet loss, TTL, message interval, mobility split).
- **Broadcast**: emergency broadcast test profile.
- **Scalability**: 12-node scenario.
- **Mobility**: mobility enabled for all nodes.
- **FullTest**: longer simulation with mobility and failures.
- **QuickDemo**: fast 60s demonstration setup.
- **SuperFast**: very fast 30s demonstration setup.

You can tune node count, packet loss, mobility speed, TTL, and message generation rates directly in the `.ini` file.

---

## 📊 Outputs & Results

Simulation results are typically written under `simulations/results/`:

- `.sca` — scalar summaries
- `.vec` — vector time-series metrics
- `.vci` — index files for vectors

Typical metrics include:

- messages sent / delivered / dropped
- delivery ratio over time
- emergency alert reception counts
- behavior during node/link failures

---

## ⚠️ Known Limitations

- Topology and behavior are simulation-centric and simplified.
- Security design is strong for academic demonstration but not fully production-hardened.
- Real-world wireless effects and adversarial models are abstracted.

---

## 🎓 Academic Context

This repository appears intended for educational/research experimentation on secure mesh communication and resilient emergency messaging.

---

## 📄 License

MIT License (or your chosen license).

If you plan to share or publish this project, update this section with the exact license text/reference used in the repository.
