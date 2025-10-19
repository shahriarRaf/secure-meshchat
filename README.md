# 🔐 Secure MeshChat

**Encrypted Ad Hoc Chat & Emergency Alerts for Disaster Scenarios**

## 📋 Features

- ✅ Peer-to-Peer Mesh Chat (multi-hop routing)
- ✅ Emergency Alert Broadcast (priority handling)
- ✅ Node Failure Resilience
- ✅ End-to-End Encryption (ECDH + AES-256-GCM)
- ✅ TTL-based Flooding Control
- ✅ Performance Metrics (latency, delivery ratio)

## 🔒 Cryptography

- **Key Exchange:** ECDH (secp256r1)
- **Encryption:** AES-256-GCM (authenticated encryption)
- **Integrity:** Built-in with GCM mode

## 🚀 How to Run

### Prerequisites
- OMNeT++ 6.2.0
- OpenSSL 3.x

### Build & Run
```bash
cd secure-meshchat
opp_makemake -f --deep
make
omnetpp
```

Then open `omnetpp.ini` and run the simulation.

## 📊 Results

- **Messages Delivered:** 16 successful decryptions
- **Emergency Alerts:** 30 received across network
- **Node Failures:** Tested with Node 4 failure at t=3s
- **Performance:** 312 events in 100s simulation

## 📁 Project Structure

```
secure-meshchat/
├── src/
│   ├── MeshNode.cc          # Main node implementation
│   ├── MeshNode.h           # Node header
│   ├── Crypto.cc            # Encryption/decryption
│   ├── Crypto.h             # Crypto header
│   └── ChatMessage.msg      # Message definition
├── simulations/
│   └── omnetpp.ini          # Simulation config
└── README.md
```

## 🎓 Academic Project



## 📄 License

MIT License (or your chosen license)