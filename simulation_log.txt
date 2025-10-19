OMNeT++ Discrete Event Simulation  (C) 1992-2025 Andras Varga, OpenSim Ltd.
Version: 6.2.0, build: 250714-83e173e93a, edition: Academic Public License -- NOT FOR COMMERCIAL USE
See the license for distribution terms and warranty disclaimer

Setting up Cmdenv...

Loading NED files from .:  2
Loading NED files from ../src:  4

Preparing for running configuration General, run #0...
Assigned runID=General-0-20251019-01:44:05-8312
Setting up network "secure_meshchat.simulations.MeshChatNetwork"...
Initializing...
Initializing module MeshChatNetwork, stage 0
Initializing module MeshChatNetwork.node[0], stage 0
[INFO]	🔧 Initializing Node 0 (Stage 0)
[INFO]	  🔗  Node 0 connected to Node 1
[INFO]	  🔗  Node 0 connected to Node 2
[INFO]	🔐 Node 0 generated cryptographic keys
Initializing module MeshChatNetwork.node[1], stage 0
[INFO]	🔧 Initializing Node 1 (Stage 0)
[INFO]	  🔗  Node 1 connected to Node 0
[INFO]	  🔗  Node 1 connected to Node 3
[INFO]	  🔗  Node 1 connected to Node 4
[INFO]	🔐 Node 1 generated cryptographic keys
Initializing module MeshChatNetwork.node[2], stage 0
[INFO]	🔧 Initializing Node 2 (Stage 0)
[INFO]	  🔗  Node 2 connected to Node 0
[INFO]	  🔗  Node 2 connected to Node 3
[INFO]	  🔗  Node 2 connected to Node 4
[INFO]	🔐 Node 2 generated cryptographic keys
Initializing module MeshChatNetwork.node[3], stage 0
[INFO]	🔧 Initializing Node 3 (Stage 0)
[INFO]	  🔗  Node 3 connected to Node 1
[INFO]	  🔗  Node 3 connected to Node 2
[INFO]	  🔗  Node 3 connected to Node 5
[INFO]	🔐 Node 3 generated cryptographic keys
Initializing module MeshChatNetwork.node[4], stage 0
[INFO]	🔧 Initializing Node 4 (Stage 0)
[INFO]	  🔗  Node 4 connected to Node 1
[INFO]	  🔗  Node 4 connected to Node 2
[INFO]	  🔗  Node 4 connected to Node 5
[INFO]	🔐 Node 4 generated cryptographic keys
Initializing module MeshChatNetwork.node[5], stage 0
[INFO]	🔧 Initializing Node 5 (Stage 0)
[INFO]	  🔗  Node 5 connected to Node 3
[INFO]	  🔗  Node 5 connected to Node 4
[INFO]	🔐 Node 5 generated cryptographic keys
Initializing module MeshChatNetwork.node[0], stage 1
[INFO]	🔧 Initializing Node 0 (Stage 1)
[INFO]	📤 Node 0 broadcast public key (65 bytes, hex:130 chars)
Initializing module MeshChatNetwork.node[1], stage 1
[INFO]	🔧 Initializing Node 1 (Stage 1)
[INFO]	📤 Node 1 broadcast public key (65 bytes, hex:130 chars)
Initializing module MeshChatNetwork.node[2], stage 1
[INFO]	🔧 Initializing Node 2 (Stage 1)
[INFO]	📤 Node 2 broadcast public key (65 bytes, hex:130 chars)
Initializing module MeshChatNetwork.node[3], stage 1
[INFO]	🔧 Initializing Node 3 (Stage 1)
[INFO]	📤 Node 3 broadcast public key (65 bytes, hex:130 chars)
Initializing module MeshChatNetwork.node[4], stage 1
[INFO]	🔧 Initializing Node 4 (Stage 1)
[INFO]	📤 Node 4 broadcast public key (65 bytes, hex:130 chars)
Initializing module MeshChatNetwork.node[5], stage 1
[INFO]	🔧 Initializing Node 5 (Stage 1)
[INFO]	📤 Node 5 broadcast public key (65 bytes, hex:130 chars)

Running simulation...
** Event #1  t=0  0% completed  (0% total)   MeshChatNetwork.node[1] (MeshNode, id=3)
[INFO]	📥 Node 1 received public key from Node 0 (hex length: 130)
[INFO]	🔑 Node 1 stored public key for peer 0
[INFO]	🔐 Node 1 deriving key with peer 0 (pub key size: 65)
[INFO]	🔐 Node 1 successfully derived symmetric key with peer 0 (32 bytes)
** Event #2  t=0  0% completed  (0% total)   MeshChatNetwork.node[2] (MeshNode, id=4)
[INFO]	📥 Node 2 received public key from Node 0 (hex length: 130)
[INFO]	🔑 Node 2 stored public key for peer 0
[INFO]	🔐 Node 2 deriving key with peer 0 (pub key size: 65)
[INFO]	🔐 Node 2 successfully derived symmetric key with peer 0 (32 bytes)
** Event #3  t=0  0% completed  (0% total)   MeshChatNetwork.node[0] (MeshNode, id=2)
[INFO]	📥 Node 0 received public key from Node 1 (hex length: 130)
[INFO]	🔑 Node 0 stored public key for peer 1
[INFO]	🔐 Node 0 deriving key with peer 1 (pub key size: 65)
[INFO]	🔐 Node 0 successfully derived symmetric key with peer 1 (32 bytes)
** Event #4  t=0  0% completed  (0% total)   MeshChatNetwork.node[3] (MeshNode, id=5)
[INFO]	📥 Node 3 received public key from Node 1 (hex length: 130)
[INFO]	🔑 Node 3 stored public key for peer 1
[INFO]	🔐 Node 3 deriving key with peer 1 (pub key size: 65)
[INFO]	🔐 Node 3 successfully derived symmetric key with peer 1 (32 bytes)
** Event #5  t=0  0% completed  (0% total)   MeshChatNetwork.node[4] (MeshNode, id=6)
[INFO]	📥 Node 4 received public key from Node 1 (hex length: 130)
[INFO]	🔑 Node 4 stored public key for peer 1
[INFO]	🔐 Node 4 deriving key with peer 1 (pub key size: 65)
[INFO]	🔐 Node 4 successfully derived symmetric key with peer 1 (32 bytes)
** Event #6  t=0  0% completed  (0% total)   MeshChatNetwork.node[0] (MeshNode, id=2)
[INFO]	📥 Node 0 received public key from Node 2 (hex length: 130)
[INFO]	🔑 Node 0 stored public key for peer 2
[INFO]	🔐 Node 0 deriving key with peer 2 (pub key size: 65)
[INFO]	🔐 Node 0 successfully derived symmetric key with peer 2 (32 bytes)
** Event #7  t=0  0% completed  (0% total)   MeshChatNetwork.node[3] (MeshNode, id=5)
[INFO]	📥 Node 3 received public key from Node 2 (hex length: 130)
[INFO]	🔑 Node 3 stored public key for peer 2
[INFO]	🔐 Node 3 deriving key with peer 2 (pub key size: 65)
[INFO]	🔐 Node 3 successfully derived symmetric key with peer 2 (32 bytes)
** Event #8  t=0  0% completed  (0% total)   MeshChatNetwork.node[4] (MeshNode, id=6)
[INFO]	📥 Node 4 received public key from Node 2 (hex length: 130)
[INFO]	🔑 Node 4 stored public key for peer 2
[INFO]	🔐 Node 4 deriving key with peer 2 (pub key size: 65)
[INFO]	🔐 Node 4 successfully derived symmetric key with peer 2 (32 bytes)
** Event #9  t=0  0% completed  (0% total)   MeshChatNetwork.node[1] (MeshNode, id=3)
[INFO]	📥 Node 1 received public key from Node 3 (hex length: 130)
[INFO]	🔑 Node 1 stored public key for peer 3
[INFO]	🔐 Node 1 deriving key with peer 3 (pub key size: 65)
[INFO]	🔐 Node 1 successfully derived symmetric key with peer 3 (32 bytes)
** Event #10  t=0  0% completed  (0% total)   MeshChatNetwork.node[2] (MeshNode, id=4)
[INFO]	📥 Node 2 received public key from Node 3 (hex length: 130)
[INFO]	🔑 Node 2 stored public key for peer 3
[INFO]	🔐 Node 2 deriving key with peer 3 (pub key size: 65)
[INFO]	🔐 Node 2 successfully derived symmetric key with peer 3 (32 bytes)
** Event #11  t=0  0% completed  (0% total)   MeshChatNetwork.node[5] (MeshNode, id=7)
[INFO]	📥 Node 5 received public key from Node 3 (hex length: 130)
[INFO]	🔑 Node 5 stored public key for peer 3
[INFO]	🔐 Node 5 deriving key with peer 3 (pub key size: 65)
[INFO]	🔐 Node 5 successfully derived symmetric key with peer 3 (32 bytes)
** Event #12  t=0  0% completed  (0% total)   MeshChatNetwork.node[1] (MeshNode, id=3)
[INFO]	📥 Node 1 received public key from Node 4 (hex length: 130)
[INFO]	🔑 Node 1 stored public key for peer 4
[INFO]	🔐 Node 1 deriving key with peer 4 (pub key size: 65)
[INFO]	🔐 Node 1 successfully derived symmetric key with peer 4 (32 bytes)
** Event #13  t=0  0% completed  (0% total)   MeshChatNetwork.node[2] (MeshNode, id=4)
[INFO]	📥 Node 2 received public key from Node 4 (hex length: 130)
[INFO]	🔑 Node 2 stored public key for peer 4
[INFO]	🔐 Node 2 deriving key with peer 4 (pub key size: 65)
[INFO]	🔐 Node 2 successfully derived symmetric key with peer 4 (32 bytes)
** Event #14  t=0  0% completed  (0% total)   MeshChatNetwork.node[5] (MeshNode, id=7)
[INFO]	📥 Node 5 received public key from Node 4 (hex length: 130)
[INFO]	🔑 Node 5 stored public key for peer 4
[INFO]	🔐 Node 5 deriving key with peer 4 (pub key size: 65)
[INFO]	🔐 Node 5 successfully derived symmetric key with peer 4 (32 bytes)
** Event #15  t=0  0% completed  (0% total)   MeshChatNetwork.node[3] (MeshNode, id=5)
[INFO]	📥 Node 3 received public key from Node 5 (hex length: 130)
[INFO]	🔑 Node 3 stored public key for peer 5
[INFO]	🔐 Node 3 deriving key with peer 5 (pub key size: 65)
[INFO]	🔐 Node 3 successfully derived symmetric key with peer 5 (32 bytes)
** Event #16  t=0  0% completed  (0% total)   MeshChatNetwork.node[4] (MeshNode, id=6)
[INFO]	📥 Node 4 received public key from Node 5 (hex length: 130)
[INFO]	🔑 Node 4 stored public key for peer 5
[INFO]	🔐 Node 4 deriving key with peer 5 (pub key size: 65)
[INFO]	🔐 Node 4 successfully derived symmetric key with peer 5 (32 bytes)
** Event #17  t=1  1% completed  (1% total)   MeshChatNetwork.node[0] (MeshNode, id=2)
[INFO]	🔒 Node 0 encrypted message to Node 1 (CT:56 IV:24 TAG:32)
[INFO]	📤 Node 0 sent encrypted message to 2 neighbors
** Event #18  t=1  1% completed  (1% total)   MeshChatNetwork.node[1] (MeshNode, id=3)
[INFO]	🔒 Node 1 encrypted message to Node 0 (CT:56 IV:24 TAG:32)
[INFO]	📤 Node 1 sent encrypted message to 3 neighbors
** Event #19  t=1  1% completed  (1% total)   MeshChatNetwork.node[2] (MeshNode, id=4)
[INFO]	🔒 Node 2 encrypted message to Node 0 (CT:56 IV:24 TAG:32)
[INFO]	📤 Node 2 sent encrypted message to 3 neighbors
** Event #20  t=1  1% completed  (1% total)   MeshChatNetwork.node[3] (MeshNode, id=5)
[INFO]	🔒 Node 3 encrypted message to Node 1 (CT:56 IV:24 TAG:32)
[INFO]	📤 Node 3 sent encrypted message to 3 neighbors
** Event #21  t=1  1% completed  (1% total)   MeshChatNetwork.node[4] (MeshNode, id=6)
[INFO]	🔒 Node 4 encrypted message to Node 1 (CT:56 IV:24 TAG:32)
[INFO]	📤 Node 4 sent encrypted message to 3 neighbors
** Event #22  t=1  1% completed  (1% total)   MeshChatNetwork.node[5] (MeshNode, id=7)
[INFO]	🔒 Node 5 encrypted message to Node 3 (CT:56 IV:24 TAG:32)
[INFO]	📤 Node 5 sent encrypted message to 2 neighbors
** Event #23  t=1  1% completed  (1% total)   MeshChatNetwork.node[1] (MeshNode, id=3)
[INFO]	🔓 Node 1 decrypted message 985773 from Node 0: "Hello from Node 0 to Node 1!"
[INFO]	📤 Node 1 forwarded message 985773 to 3 neighbors (TTL=9)
** Event #24  t=1  1% completed  (1% total)   MeshChatNetwork.node[2] (MeshNode, id=4)
[INFO]	📤 Node 2 forwarded message 305712 to 3 neighbors (TTL=9)
** Event #25  t=1  1% completed  (1% total)   MeshChatNetwork.node[0] (MeshNode, id=2)
[INFO]	🔓 Node 0 decrypted message 1435830 from Node 1: "Hello from Node 1 to Node 0!"
[INFO]	📤 Node 0 forwarded message 1435830 to 2 neighbors (TTL=9)
** Event #26  t=1  1% completed  (1% total)   MeshChatNetwork.node[3] (MeshNode, id=5)
[INFO]	📤 Node 3 forwarded message 1117953 to 3 neighbors (TTL=9)
** Event #27  t=1  1% completed  (1% total)   MeshChatNetwork.node[4] (MeshNode, id=6)
[INFO]	📤 Node 4 forwarded message 1963396 to 3 neighbors (TTL=9)
** Event #28  t=1  1% completed  (1% total)   MeshChatNetwork.node[0] (MeshNode, id=2)
[INFO]	🔓 Node 0 decrypted message 2152316 from Node 2: "Hello from Node 2 to Node 0!"
[INFO]	📤 Node 0 forwarded message 2152316 to 2 neighbors (TTL=9)
** Event #29  t=1  1% completed  (1% total)   MeshChatNetwork.node[3] (MeshNode, id=5)
[INFO]	📤 Node 3 forwarded message 2882372 to 3 neighbors (TTL=9)
** Event #30  t=1  1% completed  (1% total)   MeshChatNetwork.node[4] (MeshNode, id=6)
[INFO]	📤 Node 4 forwarded message 2359784 to 3 neighbors (TTL=9)
** Event #31  t=1  1% completed  (1% total)   MeshChatNetwork.node[1] (MeshNode, id=3)
[INFO]	🔓 Node 1 decrypted message 3304138 from Node 3: "Hello from Node 3 to Node 1!"
[INFO]	📤 Node 1 forwarded message 3304138 to 3 neighbors (TTL=9)
** Event #32  t=1  1% completed  (1% total)   MeshChatNetwork.node[2] (MeshNode, id=4)
[INFO]	📤 Node 2 forwarded message 3122580 to 3 neighbors (TTL=9)
** Event #33  t=1  1% completed  (1% total)   MeshChatNetwork.node[5] (MeshNode, id=7)
[INFO]	📤 Node 5 forwarded message 3610582 to 2 neighbors (TTL=9)
** Event #34  t=1  1% completed  (1% total)   MeshChatNetwork.node[1] (MeshNode, id=3)
[INFO]	🔓 Node 1 decrypted message 4448243 from Node 4: "Hello from Node 4 to Node 1!"
[INFO]	📤 Node 1 forwarded message 4448243 to 3 neighbors (TTL=9)
** Event #35  t=1  1% completed  (1% total)   MeshChatNetwork.node[2] (MeshNode, id=4)
[INFO]	📤 Node 2 forwarded message 4374565 to 3 neighbors (TTL=9)
** Event #36  t=1  1% completed  (1% total)   MeshChatNetwork.node[5] (MeshNode, id=7)
[INFO]	📤 Node 5 forwarded message 4735832 to 2 neighbors (TTL=9)
** Event #37  t=1  1% completed  (1% total)   MeshChatNetwork.node[3] (MeshNode, id=5)
[INFO]	🔓 Node 3 decrypted message 5736327 from Node 5: "Hello from Node 5 to Node 3!"
[INFO]	📤 Node 3 forwarded message 5736327 to 3 neighbors (TTL=9)
** Event #38  t=1  1% completed  (1% total)   MeshChatNetwork.node[4] (MeshNode, id=6)
[INFO]	📤 Node 4 forwarded message 5310745 to 3 neighbors (TTL=9)
** Event #39  t=1  1% completed  (1% total)   MeshChatNetwork.node[0] (MeshNode, id=2)
** Event #40  t=1  1% completed  (1% total)   MeshChatNetwork.node[3] (MeshNode, id=5)
[INFO]	📤 Node 3 forwarded message 985773 to 3 neighbors (TTL=8)
** Event #41  t=1  1% completed  (1% total)   MeshChatNetwork.node[4] (MeshNode, id=6)
[INFO]	📤 Node 4 forwarded message 985773 to 3 neighbors (TTL=8)
** Event #42  t=1  1% completed  (1% total)   MeshChatNetwork.node[0] (MeshNode, id=2)
** Event #43  t=1  1% completed  (1% total)   MeshChatNetwork.node[3] (MeshNode, id=5)
[INFO]	📤 Node 3 forwarded message 305712 to 3 neighbors (TTL=8)
** Event #44  t=1  1% completed  (1% total)   MeshChatNetwork.node[4] (MeshNode, id=6)
[INFO]	📤 Node 4 forwarded message 305712 to 3 neighbors (TTL=8)
** Event #45  t=1  1% completed  (1% total)   MeshChatNetwork.node[1] (MeshNode, id=3)
** Event #46  t=1  1% completed  (1% total)   MeshChatNetwork.node[2] (MeshNode, id=4)
[INFO]	📤 Node 2 forwarded message 1435830 to 3 neighbors (TTL=8)
** Event #47  t=1  1% completed  (1% total)   MeshChatNetwork.node[1] (MeshNode, id=3)
** Event #48  t=1  1% completed  (1% total)   MeshChatNetwork.node[2] (MeshNode, id=4)
[INFO]	📤 Node 2 forwarded message 1117953 to 3 neighbors (TTL=8)
** Event #49  t=1  1% completed  (1% total)   MeshChatNetwork.node[5] (MeshNode, id=7)
[INFO]	📤 Node 5 forwarded message 1117953 to 2 neighbors (TTL=8)
** Event #50  t=1  1% completed  (1% total)   MeshChatNetwork.node[1] (MeshNode, id=3)
** Event #51  t=1  1% completed  (1% total)   MeshChatNetwork.node[2] (MeshNode, id=4)
[INFO]	📤 Node 2 forwarded message 1963396 to 3 neighbors (TTL=8)
** Event #52  t=1  1% completed  (1% total)   MeshChatNetwork.node[5] (MeshNode, id=7)
[INFO]	📤 Node 5 forwarded message 1963396 to 2 neighbors (TTL=8)
** Event #53  t=1  1% completed  (1% total)   MeshChatNetwork.node[1] (MeshNode, id=3)
[INFO]	📤 Node 1 forwarded message 2152316 to 3 neighbors (TTL=8)
** Event #54  t=1  1% completed  (1% total)   MeshChatNetwork.node[2] (MeshNode, id=4)
** Event #55  t=1  1% completed  (1% total)   MeshChatNetwork.node[1] (MeshNode, id=3)
[INFO]	📤 Node 1 forwarded message 2882372 to 3 neighbors (TTL=8)
** Event #56  t=1  1% completed  (1% total)   MeshChatNetwork.node[2] (MeshNode, id=4)
** Event #57  t=1  1% completed  (1% total)   MeshChatNetwork.node[5] (MeshNode, id=7)
[INFO]	📤 Node 5 forwarded message 2882372 to 2 neighbors (TTL=8)
** Event #58  t=1  1% completed  (1% total)   MeshChatNetwork.node[1] (MeshNode, id=3)
[INFO]	📤 Node 1 forwarded message 2359784 to 3 neighbors (TTL=8)
** Event #59  t=1  1% completed  (1% total)   MeshChatNetwork.node[2] (MeshNode, id=4)
** Event #60  t=1  1% completed  (1% total)   MeshChatNetwork.node[5] (MeshNode, id=7)
[INFO]	📤 Node 5 forwarded message 2359784 to 2 neighbors (TTL=8)
** Event #61  t=1  1% completed  (1% total)   MeshChatNetwork.node[0] (MeshNode, id=2)
[INFO]	📤 Node 0 forwarded message 3304138 to 2 neighbors (TTL=8)
** Event #62  t=1  1% completed  (1% total)   MeshChatNetwork.node[3] (MeshNode, id=5)
** Event #63  t=1  1% completed  (1% total)   MeshChatNetwork.node[4] (MeshNode, id=6)
[INFO]	📤 Node 4 forwarded message 3304138 to 3 neighbors (TTL=8)
** Event #64  t=1  1% completed  (1% total)   MeshChatNetwork.node[0] (MeshNode, id=2)
[INFO]	📤 Node 0 forwarded message 3122580 to 2 neighbors (TTL=8)
** Event #65  t=1  1% completed  (1% total)   MeshChatNetwork.node[3] (MeshNode, id=5)
** Event #66  t=1  1% completed  (1% total)   MeshChatNetwork.node[4] (MeshNode, id=6)
[INFO]	📤 Node 4 forwarded message 3122580 to 3 neighbors (TTL=8)
** Event #67  t=1  1% completed  (1% total)   MeshChatNetwork.node[3] (MeshNode, id=5)
** Event #68  t=1  1% completed  (1% total)   MeshChatNetwork.node[4] (MeshNode, id=6)
[INFO]	📤 Node 4 forwarded message 3610582 to 3 neighbors (TTL=8)
** Event #69  t=1  1% completed  (1% total)   MeshChatNetwork.node[0] (MeshNode, id=2)
[INFO]	📤 Node 0 forwarded message 4448243 to 2 neighbors (TTL=8)
** Event #70  t=1  1% completed  (1% total)   MeshChatNetwork.node[3] (MeshNode, id=5)
[INFO]	📤 Node 3 forwarded message 4448243 to 3 neighbors (TTL=8)
** Event #71  t=1  1% completed  (1% total)   MeshChatNetwork.node[4] (MeshNode, id=6)
** Event #72  t=1  1% completed  (1% total)   MeshChatNetwork.node[0] (MeshNode, id=2)
[INFO]	📤 Node 0 forwarded message 4374565 to 2 neighbors (TTL=8)
** Event #73  t=1  1% completed  (1% total)   MeshChatNetwork.node[3] (MeshNode, id=5)
[INFO]	📤 Node 3 forwarded message 4374565 to 3 neighbors (TTL=8)
** Event #74  t=1  1% completed  (1% total)   MeshChatNetwork.node[4] (MeshNode, id=6)
** Event #75  t=1  1% completed  (1% total)   MeshChatNetwork.node[3] (MeshNode, id=5)
[INFO]	📤 Node 3 forwarded message 4735832 to 3 neighbors (TTL=8)
** Event #76  t=1  1% completed  (1% total)   MeshChatNetwork.node[4] (MeshNode, id=6)
** Event #77  t=1  1% completed  (1% total)   MeshChatNetwork.node[1] (MeshNode, id=3)
[INFO]	📤 Node 1 forwarded message 5736327 to 3 neighbors (TTL=8)
** Event #78  t=1  1% completed  (1% total)   MeshChatNetwork.node[2] (MeshNode, id=4)
[INFO]	📤 Node 2 forwarded message 5736327 to 3 neighbors (TTL=8)
** Event #79  t=1  1% completed  (1% total)   MeshChatNetwork.node[5] (MeshNode, id=7)
** Event #80  t=1  1% completed  (1% total)   MeshChatNetwork.node[1] (MeshNode, id=3)
[INFO]	📤 Node 1 forwarded message 5310745 to 3 neighbors (TTL=8)
** Event #81  t=1  1% completed  (1% total)   MeshChatNetwork.node[2] (MeshNode, id=4)
[INFO]	📤 Node 2 forwarded message 5310745 to 3 neighbors (TTL=8)
** Event #82  t=1  1% completed  (1% total)   MeshChatNetwork.node[5] (MeshNode, id=7)
** Event #83  t=1  1% completed  (1% total)   MeshChatNetwork.node[1] (MeshNode, id=3)
[INFO]	🔁 Node 1 already saw message 985773 - dropping
** Event #84  t=1  1% completed  (1% total)   MeshChatNetwork.node[2] (MeshNode, id=4)
[INFO]	📤 Node 2 forwarded message 985773 to 3 neighbors (TTL=7)
** Event #85  t=1  1% completed  (1% total)   MeshChatNetwork.node[5] (MeshNode, id=7)
[INFO]	📤 Node 5 forwarded message 985773 to 2 neighbors (TTL=7)
** Event #86  t=1  1% completed  (1% total)   MeshChatNetwork.node[1] (MeshNode, id=3)
[INFO]	🔁 Node 1 already saw message 985773 - dropping
** Event #87  t=1  1% completed  (1% total)   MeshChatNetwork.node[2] (MeshNode, id=4)
[INFO]	🔁 Node 2 already saw message 985773 - dropping
** Event #88  t=1  1% completed  (1% total)   MeshChatNetwork.node[5] (MeshNode, id=7)
[INFO]	🔁 Node 5 already saw message 985773 - dropping
** Event #89  t=1  1% completed  (1% total)   MeshChatNetwork.node[1] (MeshNode, id=3)
[INFO]	🔓 Node 1 decrypted message 305712 from Node 0: "Hello from Node 0 to Node 1!"
[INFO]	📤 Node 1 forwarded message 305712 to 3 neighbors (TTL=7)
** Event #90  t=1  1% completed  (1% total)   MeshChatNetwork.node[2] (MeshNode, id=4)
[INFO]	🔁 Node 2 already saw message 305712 - dropping
** Event #91  t=1  1% completed  (1% total)   MeshChatNetwork.node[5] (MeshNode, id=7)
[INFO]	📤 Node 5 forwarded message 305712 to 2 neighbors (TTL=7)
** Event #92  t=1  1% completed  (1% total)   MeshChatNetwork.node[1] (MeshNode, id=3)
[INFO]	🔁 Node 1 already saw message 305712 - dropping
** Event #93  t=1  1% completed  (1% total)   MeshChatNetwork.node[2] (MeshNode, id=4)
[INFO]	🔁 Node 2 already saw message 305712 - dropping
** Event #94  t=1  1% completed  (1% total)   MeshChatNetwork.node[5] (MeshNode, id=7)
[INFO]	🔁 Node 5 already saw message 305712 - dropping
** Event #95  t=1  1% completed  (1% total)   MeshChatNetwork.node[0] (MeshNode, id=2)
[INFO]	🔁 Node 0 already saw message 1435830 - dropping
** Event #96  t=1  1% completed  (1% total)   MeshChatNetwork.node[3] (MeshNode, id=5)
[INFO]	📤 Node 3 forwarded message 1435830 to 3 neighbors (TTL=7)
** Event #97  t=1  1% completed  (1% total)   MeshChatNetwork.node[4] (MeshNode, id=6)
[INFO]	📤 Node 4 forwarded message 1435830 to 3 neighbors (TTL=7)
** Event #98  t=1  1% completed  (1% total)   MeshChatNetwork.node[0] (MeshNode, id=2)
[INFO]	🔓 Node 0 decrypted message 1117953 from Node 1: "Hello from Node 1 to Node 0!"
[INFO]	📤 Node 0 forwarded message 1117953 to 2 neighbors (TTL=7)
** Event #99  t=1  1% completed  (1% total)   MeshChatNetwork.node[3] (MeshNode, id=5)
[INFO]	🔁 Node 3 already saw message 1117953 - dropping
** Event #100  t=1  1% completed  (1% total)   MeshChatNetwork.node[4] (MeshNode, id=6)
[INFO]	📤 Node 4 forwarded message 1117953 to 3 neighbors (TTL=7)
** Event #101  t=1  1% completed  (1% total)   MeshChatNetwork.node[3] (MeshNode, id=5)
[INFO]	🔁 Node 3 already saw message 1117953 - dropping
** Event #102  t=1  1% completed  (1% total)   MeshChatNetwork.node[4] (MeshNode, id=6)
[INFO]	🔁 Node 4 already saw message 1117953 - dropping
** Event #103  t=1  1% completed  (1% total)   MeshChatNetwork.node[0] (MeshNode, id=2)
[INFO]	🔓 Node 0 decrypted message 1963396 from Node 1: "Hello from Node 1 to Node 0!"
[INFO]	📤 Node 0 forwarded message 1963396 to 2 neighbors (TTL=7)
** Event #104  t=1  1% completed  (1% total)   MeshChatNetwork.node[3] (MeshNode, id=5)
[INFO]	📤 Node 3 forwarded message 1963396 to 3 neighbors (TTL=7)
** Event #105  t=1  1% completed  (1% total)   MeshChatNetwork.node[4] (MeshNode, id=6)
[INFO]	🔁 Node 4 already saw message 1963396 - dropping
** Event #106  t=1  1% completed  (1% total)   MeshChatNetwork.node[3] (MeshNode, id=5)
[INFO]	🔁 Node 3 already saw message 1963396 - dropping
** Event #107  t=1  1% completed  (1% total)   MeshChatNetwork.node[4] (MeshNode, id=6)
[INFO]	🔁 Node 4 already saw message 1963396 - dropping
** Event #108  t=1  1% completed  (1% total)   MeshChatNetwork.node[0] (MeshNode, id=2)
[INFO]	🔁 Node 0 already saw message 2152316 - dropping
** Event #109  t=1  1% completed  (1% total)   MeshChatNetwork.node[3] (MeshNode, id=5)
[INFO]	📤 Node 3 forwarded message 2152316 to 3 neighbors (TTL=7)
** Event #110  t=1  1% completed  (1% total)   MeshChatNetwork.node[4] (MeshNode, id=6)
[INFO]	📤 Node 4 forwarded message 2152316 to 3 neighbors (TTL=7)
** Event #111  t=1  1% completed  (1% total)   MeshChatNetwork.node[0] (MeshNode, id=2)
[INFO]	🔓 Node 0 decrypted message 2882372 from Node 2: "Hello from Node 2 to Node 0!"
[INFO]	📤 Node 0 forwarded message 2882372 to 2 neighbors (TTL=7)
** Event #112  t=1  1% completed  (1% total)   MeshChatNetwork.node[3] (MeshNode, id=5)
[INFO]	🔁 Node 3 already saw message 2882372 - dropping
** Event #113  t=1  1% completed  (1% total)   MeshChatNetwork.node[4] (MeshNode, id=6)
[INFO]	📤 Node 4 forwarded message 2882372 to 3 neighbors (TTL=7)
** Event #114  t=1  1% completed  (1% total)   MeshChatNetwork.node[3] (MeshNode, id=5)
[INFO]	🔁 Node 3 already saw message 2882372 - dropping
** Event #115  t=1  1% completed  (1% total)   MeshChatNetwork.node[4] (MeshNode, id=6)
[INFO]	🔁 Node 4 already saw message 2882372 - dropping
** Event #116  t=1  1% completed  (1% total)   MeshChatNetwork.node[0] (MeshNode, id=2)
[INFO]	🔓 Node 0 decrypted message 2359784 from Node 2: "Hello from Node 2 to Node 0!"
[INFO]	📤 Node 0 forwarded message 2359784 to 2 neighbors (TTL=7)
** Event #117  t=1  1% completed  (1% total)   MeshChatNetwork.node[3] (MeshNode, id=5)
[INFO]	📤 Node 3 forwarded message 2359784 to 3 neighbors (TTL=7)
** Event #118  t=1  1% completed  (1% total)   MeshChatNetwork.node[4] (MeshNode, id=6)
[INFO]	🔁 Node 4 already saw message 2359784 - dropping
** Event #119  t=1  1% completed  (1% total)   MeshChatNetwork.node[3] (MeshNode, id=5)
[INFO]	🔁 Node 3 already saw message 2359784 - dropping
** Event #120  t=1  1% completed  (1% total)   MeshChatNetwork.node[4] (MeshNode, id=6)
[INFO]	🔁 Node 4 already saw message 2359784 - dropping
** Event #121  t=1  1% completed  (1% total)   MeshChatNetwork.node[1] (MeshNode, id=3)
[INFO]	🔁 Node 1 already saw message 3304138 - dropping
** Event #122  t=1  1% completed  (1% total)   MeshChatNetwork.node[2] (MeshNode, id=4)
[INFO]	📤 Node 2 forwarded message 3304138 to 3 neighbors (TTL=7)
** Event #123  t=1  1% completed  (1% total)   MeshChatNetwork.node[1] (MeshNode, id=3)
[INFO]	🔁 Node 1 already saw message 3304138 - dropping
** Event #124  t=1  1% completed  (1% total)   MeshChatNetwork.node[2] (MeshNode, id=4)
[INFO]	🔁 Node 2 already saw message 3304138 - dropping
** Event #125  t=1  1% completed  (1% total)   MeshChatNetwork.node[5] (MeshNode, id=7)
[INFO]	📤 Node 5 forwarded message 3304138 to 2 neighbors (TTL=7)
** Event #126  t=1  1% completed  (1% total)   MeshChatNetwork.node[1] (MeshNode, id=3)
[INFO]	🔓 Node 1 decrypted message 3122580 from Node 3: "Hello from Node 3 to Node 1!"
[INFO]	📤 Node 1 forwarded message 3122580 to 3 neighbors (TTL=7)
** Event #127  t=1  1% completed  (1% total)   MeshChatNetwork.node[2] (MeshNode, id=4)
[INFO]	🔁 Node 2 already saw message 3122580 - dropping
** Event #128  t=1  1% completed  (1% total)   MeshChatNetwork.node[1] (MeshNode, id=3)
[INFO]	🔁 Node 1 already saw message 3122580 - dropping
** Event #129  t=1  1% completed  (1% total)   MeshChatNetwork.node[2] (MeshNode, id=4)
[INFO]	🔁 Node 2 already saw message 3122580 - dropping
** Event #130  t=1  1% completed  (1% total)   MeshChatNetwork.node[5] (MeshNode, id=7)
[INFO]	📤 Node 5 forwarded message 3122580 to 2 neighbors (TTL=7)
** Event #131  t=1  1% completed  (1% total)   MeshChatNetwork.node[1] (MeshNode, id=3)
[INFO]	🔓 Node 1 decrypted message 3610582 from Node 3: "Hello from Node 3 to Node 1!"
[INFO]	📤 Node 1 forwarded message 3610582 to 3 neighbors (TTL=7)
** Event #132  t=1  1% completed  (1% total)   MeshChatNetwork.node[2] (MeshNode, id=4)
[INFO]	📤 Node 2 forwarded message 3610582 to 3 neighbors (TTL=7)
** Event #133  t=1  1% completed  (1% total)   MeshChatNetwork.node[5] (MeshNode, id=7)
[INFO]	🔁 Node 5 already saw message 3610582 - dropping
** Event #134  t=1  1% completed  (1% total)   MeshChatNetwork.node[1] (MeshNode, id=3)
[INFO]	🔁 Node 1 already saw message 4448243 - dropping
** Event #135  t=1  1% completed  (1% total)   MeshChatNetwork.node[2] (MeshNode, id=4)
[INFO]	📤 Node 2 forwarded message 4448243 to 3 neighbors (TTL=7)
** Event #136  t=1  1% completed  (1% total)   MeshChatNetwork.node[1] (MeshNode, id=3)
[INFO]	🔁 Node 1 already saw message 4448243 - dropping
** Event #137  t=1  1% completed  (1% total)   MeshChatNetwork.node[2] (MeshNode, id=4)
[INFO]	🔁 Node 2 already saw message 4448243 - dropping
** Event #138  t=1  1% completed  (1% total)   MeshChatNetwork.node[5] (MeshNode, id=7)
[INFO]	📤 Node 5 forwarded message 4448243 to 2 neighbors (TTL=7)
** Event #139  t=1  1% completed  (1% total)   MeshChatNetwork.node[1] (MeshNode, id=3)
[INFO]	🔓 Node 1 decrypted message 4374565 from Node 4: "Hello from Node 4 to Node 1!"
[INFO]	📤 Node 1 forwarded message 4374565 to 3 neighbors (TTL=7)
** Event #140  t=1  1% completed  (1% total)   MeshChatNetwork.node[2] (MeshNode, id=4)
[INFO]	🔁 Node 2 already saw message 4374565 - dropping
** Event #141  t=1  1% completed  (1% total)   MeshChatNetwork.node[1] (MeshNode, id=3)
[INFO]	🔁 Node 1 already saw message 4374565 - dropping
** Event #142  t=1  1% completed  (1% total)   MeshChatNetwork.node[2] (MeshNode, id=4)
[INFO]	🔁 Node 2 already saw message 4374565 - dropping
** Event #143  t=1  1% completed  (1% total)   MeshChatNetwork.node[5] (MeshNode, id=7)
[INFO]	📤 Node 5 forwarded message 4374565 to 2 neighbors (TTL=7)
** Event #144  t=1  1% completed  (1% total)   MeshChatNetwork.node[1] (MeshNode, id=3)
[INFO]	🔓 Node 1 decrypted message 4735832 from Node 4: "Hello from Node 4 to Node 1!"
[INFO]	📤 Node 1 forwarded message 4735832 to 3 neighbors (TTL=7)
** Event #145  t=1  1% completed  (1% total)   MeshChatNetwork.node[2] (MeshNode, id=4)
[INFO]	📤 Node 2 forwarded message 4735832 to 3 neighbors (TTL=7)
** Event #146  t=1  1% completed  (1% total)   MeshChatNetwork.node[5] (MeshNode, id=7)
[INFO]	🔁 Node 5 already saw message 4735832 - dropping
** Event #147  t=1  1% completed  (1% total)   MeshChatNetwork.node[0] (MeshNode, id=2)
[INFO]	📤 Node 0 forwarded message 5736327 to 2 neighbors (TTL=7)
** Event #148  t=1  1% completed  (1% total)   MeshChatNetwork.node[3] (MeshNode, id=5)
[INFO]	🔁 Node 3 already saw message 5736327 - dropping
** Event #149  t=1  1% completed  (1% total)   MeshChatNetwork.node[4] (MeshNode, id=6)
[INFO]	📤 Node 4 forwarded message 5736327 to 3 neighbors (TTL=7)
** Event #150  t=1  1% completed  (1% total)   MeshChatNetwork.node[0] (MeshNode, id=2)
[INFO]	🔁 Node 0 already saw message 5736327 - dropping
** Event #151  t=1  1% completed  (1% total)   MeshChatNetwork.node[3] (MeshNode, id=5)
[INFO]	🔁 Node 3 already saw message 5736327 - dropping
** Event #152  t=1  1% completed  (1% total)   MeshChatNetwork.node[4] (MeshNode, id=6)
[INFO]	🔁 Node 4 already saw message 5736327 - dropping
** Event #153  t=1  1% completed  (1% total)   MeshChatNetwork.node[0] (MeshNode, id=2)
[INFO]	📤 Node 0 forwarded message 5310745 to 2 neighbors (TTL=7)
** Event #154  t=1  1% completed  (1% total)   MeshChatNetwork.node[3] (MeshNode, id=5)
[INFO]	🔓 Node 3 decrypted message 5310745 from Node 5: "Hello from Node 5 to Node 3!"
[INFO]	📤 Node 3 forwarded message 5310745 to 3 neighbors (TTL=7)
** Event #155  t=1  1% completed  (1% total)   MeshChatNetwork.node[4] (MeshNode, id=6)
[INFO]	🔁 Node 4 already saw message 5310745 - dropping
** Event #156  t=1  1% completed  (1% total)   MeshChatNetwork.node[0] (MeshNode, id=2)
[INFO]	🔁 Node 0 already saw message 5310745 - dropping
** Event #157  t=1  1% completed  (1% total)   MeshChatNetwork.node[3] (MeshNode, id=5)
[INFO]	🔁 Node 3 already saw message 5310745 - dropping
** Event #158  t=1  1% completed  (1% total)   MeshChatNetwork.node[4] (MeshNode, id=6)
[INFO]	🔁 Node 4 already saw message 5310745 - dropping
** Event #159  t=1  1% completed  (1% total)   MeshChatNetwork.node[0] (MeshNode, id=2)
** Event #160  t=1  1% completed  (1% total)   MeshChatNetwork.node[3] (MeshNode, id=5)
[INFO]	🔁 Node 3 already saw message 985773 - dropping
** Event #161  t=1  1% completed  (1% total)   MeshChatNetwork.node[4] (MeshNode, id=6)
[INFO]	🔁 Node 4 already saw message 985773 - dropping
** Event #162  t=1  1% completed  (1% total)   MeshChatNetwork.node[3] (MeshNode, id=5)
[INFO]	🔁 Node 3 already saw message 985773 - dropping
** Event #163  t=1  1% completed  (1% total)   MeshChatNetwork.node[4] (MeshNode, id=6)
[INFO]	🔁 Node 4 already saw message 985773 - dropping
** Event #164  t=1  1% completed  (1% total)   MeshChatNetwork.node[0] (MeshNode, id=2)
** Event #165  t=1  1% completed  (1% total)   MeshChatNetwork.node[3] (MeshNode, id=5)
[INFO]	🔁 Node 3 already saw message 305712 - dropping
** Event #166  t=1  1% completed  (1% total)   MeshChatNetwork.node[4] (MeshNode, id=6)
[INFO]	🔁 Node 4 already saw message 305712 - dropping
** Event #167  t=1  1% completed  (1% total)   MeshChatNetwork.node[3] (MeshNode, id=5)
[INFO]	🔁 Node 3 already saw message 305712 - dropping
** Event #168  t=1  1% completed  (1% total)   MeshChatNetwork.node[4] (MeshNode, id=6)
[INFO]	🔁 Node 4 already saw message 305712 - dropping
** Event #169  t=1  1% completed  (1% total)   MeshChatNetwork.node[1] (MeshNode, id=3)
** Event #170  t=1  1% completed  (1% total)   MeshChatNetwork.node[2] (MeshNode, id=4)
[INFO]	🔁 Node 2 already saw message 1435830 - dropping
** Event #171  t=1  1% completed  (1% total)   MeshChatNetwork.node[5] (MeshNode, id=7)
[INFO]	📤 Node 5 forwarded message 1435830 to 2 neighbors (TTL=6)
** Event #172  t=1  1% completed  (1% total)   MeshChatNetwork.node[1] (MeshNode, id=3)
** Event #173  t=1  1% completed  (1% total)   MeshChatNetwork.node[2] (MeshNode, id=4)
[INFO]	🔁 Node 2 already saw message 1435830 - dropping
** Event #174  t=1  1% completed  (1% total)   MeshChatNetwork.node[5] (MeshNode, id=7)
[INFO]	🔁 Node 5 already saw message 1435830 - dropping
** Event #175  t=1  1% completed  (1% total)   MeshChatNetwork.node[1] (MeshNode, id=3)
** Event #176  t=1  1% completed  (1% total)   MeshChatNetwork.node[2] (MeshNode, id=4)
[INFO]	🔁 Node 2 already saw message 1117953 - dropping
** Event #177  t=1  1% completed  (1% total)   MeshChatNetwork.node[1] (MeshNode, id=3)
** Event #178  t=1  1% completed  (1% total)   MeshChatNetwork.node[2] (MeshNode, id=4)
[INFO]	🔁 Node 2 already saw message 1117953 - dropping
** Event #179  t=1  1% completed  (1% total)   MeshChatNetwork.node[5] (MeshNode, id=7)
[INFO]	🔁 Node 5 already saw message 1117953 - dropping
** Event #180  t=1  1% completed  (1% total)   MeshChatNetwork.node[1] (MeshNode, id=3)
** Event #181  t=1  1% completed  (1% total)   MeshChatNetwork.node[2] (MeshNode, id=4)
[INFO]	🔁 Node 2 already saw message 1963396 - dropping
** Event #182  t=1  1% completed  (1% total)   MeshChatNetwork.node[1] (MeshNode, id=3)
** Event #183  t=1  1% completed  (1% total)   MeshChatNetwork.node[2] (MeshNode, id=4)
[INFO]	🔁 Node 2 already saw message 1963396 - dropping
** Event #184  t=1  1% completed  (1% total)   MeshChatNetwork.node[5] (MeshNode, id=7)
[INFO]	🔁 Node 5 already saw message 1963396 - dropping
** Event #185  t=1  1% completed  (1% total)   MeshChatNetwork.node[1] (MeshNode, id=3)
[INFO]	🔁 Node 1 already saw message 2152316 - dropping
** Event #186  t=1  1% completed  (1% total)   MeshChatNetwork.node[2] (MeshNode, id=4)
** Event #187  t=1  1% completed  (1% total)   MeshChatNetwork.node[5] (MeshNode, id=7)
[INFO]	📤 Node 5 forwarded message 2152316 to 2 neighbors (TTL=6)
** Event #188  t=1  1% completed  (1% total)   MeshChatNetwork.node[1] (MeshNode, id=3)
[INFO]	🔁 Node 1 already saw message 2152316 - dropping
** Event #189  t=1  1% completed  (1% total)   MeshChatNetwork.node[2] (MeshNode, id=4)
** Event #190  t=1  1% completed  (1% total)   MeshChatNetwork.node[5] (MeshNode, id=7)
[INFO]	🔁 Node 5 already saw message 2152316 - dropping
** Event #191  t=1  1% completed  (1% total)   MeshChatNetwork.node[1] (MeshNode, id=3)
[INFO]	🔁 Node 1 already saw message 2882372 - dropping
** Event #192  t=1  1% completed  (1% total)   MeshChatNetwork.node[2] (MeshNode, id=4)
** Event #193  t=1  1% completed  (1% total)   MeshChatNetwork.node[1] (MeshNode, id=3)
[INFO]	🔁 Node 1 already saw message 2882372 - dropping
** Event #194  t=1  1% completed  (1% total)   MeshChatNetwork.node[2] (MeshNode, id=4)
** Event #195  t=1  1% completed  (1% total)   MeshChatNetwork.node[5] (MeshNode, id=7)
[INFO]	🔁 Node 5 already saw message 2882372 - dropping
** Event #196  t=1  1% completed  (1% total)   MeshChatNetwork.node[1] (MeshNode, id=3)
[INFO]	🔁 Node 1 already saw message 2359784 - dropping
** Event #197  t=1  1% completed  (1% total)   MeshChatNetwork.node[2] (MeshNode, id=4)
** Event #198  t=1  1% completed  (1% total)   MeshChatNetwork.node[1] (MeshNode, id=3)
[INFO]	🔁 Node 1 already saw message 2359784 - dropping
** Event #199  t=1  1% completed  (1% total)   MeshChatNetwork.node[2] (MeshNode, id=4)
** Event #200  t=1  1% completed  (1% total)   MeshChatNetwork.node[5] (MeshNode, id=7)
[INFO]	🔁 Node 5 already saw message 2359784 - dropping
** Event #201  t=1  1% completed  (1% total)   MeshChatNetwork.node[0] (MeshNode, id=2)
[INFO]	🔁 Node 0 already saw message 3304138 - dropping
** Event #202  t=1  1% completed  (1% total)   MeshChatNetwork.node[3] (MeshNode, id=5)
** Event #203  t=1  1% completed  (1% total)   MeshChatNetwork.node[4] (MeshNode, id=6)
[INFO]	🔁 Node 4 already saw message 3304138 - dropping
** Event #204  t=1  1% completed  (1% total)   MeshChatNetwork.node[3] (MeshNode, id=5)
** Event #205  t=1  1% completed  (1% total)   MeshChatNetwork.node[4] (MeshNode, id=6)
[INFO]	🔁 Node 4 already saw message 3304138 - dropping
** Event #206  t=1  1% completed  (1% total)   MeshChatNetwork.node[0] (MeshNode, id=2)
[INFO]	🔁 Node 0 already saw message 3122580 - dropping
** Event #207  t=1  1% completed  (1% total)   MeshChatNetwork.node[3] (MeshNode, id=5)
** Event #208  t=1  1% completed  (1% total)   MeshChatNetwork.node[4] (MeshNode, id=6)
[INFO]	🔁 Node 4 already saw message 3122580 - dropping
** Event #209  t=1  1% completed  (1% total)   MeshChatNetwork.node[3] (MeshNode, id=5)
** Event #210  t=1  1% completed  (1% total)   MeshChatNetwork.node[4] (MeshNode, id=6)
[INFO]	🔁 Node 4 already saw message 3122580 - dropping
** Event #211  t=1  1% completed  (1% total)   MeshChatNetwork.node[0] (MeshNode, id=2)
[INFO]	📤 Node 0 forwarded message 3610582 to 2 neighbors (TTL=6)
** Event #212  t=1  1% completed  (1% total)   MeshChatNetwork.node[3] (MeshNode, id=5)
** Event #213  t=1  1% completed  (1% total)   MeshChatNetwork.node[4] (MeshNode, id=6)
[INFO]	🔁 Node 4 already saw message 3610582 - dropping
** Event #214  t=1  1% completed  (1% total)   MeshChatNetwork.node[0] (MeshNode, id=2)
[INFO]	🔁 Node 0 already saw message 3610582 - dropping
** Event #215  t=1  1% completed  (1% total)   MeshChatNetwork.node[3] (MeshNode, id=5)
** Event #216  t=1  1% completed  (1% total)   MeshChatNetwork.node[4] (MeshNode, id=6)
[INFO]	🔁 Node 4 already saw message 3610582 - dropping
** Event #217  t=1  1% completed  (1% total)   MeshChatNetwork.node[0] (MeshNode, id=2)
[INFO]	🔁 Node 0 already saw message 4448243 - dropping
** Event #218  t=1  1% completed  (1% total)   MeshChatNetwork.node[3] (MeshNode, id=5)
[INFO]	🔁 Node 3 already saw message 4448243 - dropping
** Event #219  t=1  1% completed  (1% total)   MeshChatNetwork.node[4] (MeshNode, id=6)
** Event #220  t=1  1% completed  (1% total)   MeshChatNetwork.node[3] (MeshNode, id=5)
[INFO]	🔁 Node 3 already saw message 4448243 - dropping
** Event #221  t=1  1% completed  (1% total)   MeshChatNetwork.node[4] (MeshNode, id=6)
** Event #222  t=1  1% completed  (1% total)   MeshChatNetwork.node[0] (MeshNode, id=2)
[INFO]	🔁 Node 0 already saw message 4374565 - dropping
** Event #223  t=1  1% completed  (1% total)   MeshChatNetwork.node[3] (MeshNode, id=5)
[INFO]	🔁 Node 3 already saw message 4374565 - dropping
** Event #224  t=1  1% completed  (1% total)   MeshChatNetwork.node[4] (MeshNode, id=6)
** Event #225  t=1  1% completed  (1% total)   MeshChatNetwork.node[3] (MeshNode, id=5)
[INFO]	🔁 Node 3 already saw message 4374565 - dropping
** Event #226  t=1  1% completed  (1% total)   MeshChatNetwork.node[4] (MeshNode, id=6)
** Event #227  t=1  1% completed  (1% total)   MeshChatNetwork.node[0] (MeshNode, id=2)
[INFO]	📤 Node 0 forwarded message 4735832 to 2 neighbors (TTL=6)
** Event #228  t=1  1% completed  (1% total)   MeshChatNetwork.node[3] (MeshNode, id=5)
[INFO]	🔁 Node 3 already saw message 4735832 - dropping
** Event #229  t=1  1% completed  (1% total)   MeshChatNetwork.node[4] (MeshNode, id=6)
** Event #230  t=1  1% completed  (1% total)   MeshChatNetwork.node[0] (MeshNode, id=2)
[INFO]	🔁 Node 0 already saw message 4735832 - dropping
** Event #231  t=1  1% completed  (1% total)   MeshChatNetwork.node[3] (MeshNode, id=5)
[INFO]	🔁 Node 3 already saw message 4735832 - dropping
** Event #232  t=1  1% completed  (1% total)   MeshChatNetwork.node[4] (MeshNode, id=6)
** Event #233  t=1  1% completed  (1% total)   MeshChatNetwork.node[1] (MeshNode, id=3)
[INFO]	🔁 Node 1 already saw message 5736327 - dropping
** Event #234  t=1  1% completed  (1% total)   MeshChatNetwork.node[2] (MeshNode, id=4)
[INFO]	🔁 Node 2 already saw message 5736327 - dropping
** Event #235  t=1  1% completed  (1% total)   MeshChatNetwork.node[1] (MeshNode, id=3)
[INFO]	🔁 Node 1 already saw message 5736327 - dropping
** Event #236  t=1  1% completed  (1% total)   MeshChatNetwork.node[2] (MeshNode, id=4)
[INFO]	🔁 Node 2 already saw message 5736327 - dropping
** Event #237  t=1  1% completed  (1% total)   MeshChatNetwork.node[5] (MeshNode, id=7)
** Event #238  t=1  1% completed  (1% total)   MeshChatNetwork.node[1] (MeshNode, id=3)
[INFO]	🔁 Node 1 already saw message 5310745 - dropping
** Event #239  t=1  1% completed  (1% total)   MeshChatNetwork.node[2] (MeshNode, id=4)
[INFO]	🔁 Node 2 already saw message 5310745 - dropping
** Event #240  t=1  1% completed  (1% total)   MeshChatNetwork.node[1] (MeshNode, id=3)
[INFO]	🔁 Node 1 already saw message 5310745 - dropping
** Event #241  t=1  1% completed  (1% total)   MeshChatNetwork.node[2] (MeshNode, id=4)
[INFO]	🔁 Node 2 already saw message 5310745 - dropping
** Event #242  t=1  1% completed  (1% total)   MeshChatNetwork.node[5] (MeshNode, id=7)
** Event #243  t=1  1% completed  (1% total)   MeshChatNetwork.node[3] (MeshNode, id=5)
[INFO]	🔁 Node 3 already saw message 1435830 - dropping
** Event #244  t=1  1% completed  (1% total)   MeshChatNetwork.node[4] (MeshNode, id=6)
[INFO]	🔁 Node 4 already saw message 1435830 - dropping
** Event #245  t=1  1% completed  (1% total)   MeshChatNetwork.node[3] (MeshNode, id=5)
[INFO]	🔁 Node 3 already saw message 2152316 - dropping
** Event #246  t=1  1% completed  (1% total)   MeshChatNetwork.node[4] (MeshNode, id=6)
[INFO]	🔁 Node 4 already saw message 2152316 - dropping
** Event #247  t=1  1% completed  (1% total)   MeshChatNetwork.node[1] (MeshNode, id=3)
[INFO]	🔁 Node 1 already saw message 3610582 - dropping
** Event #248  t=1  1% completed  (1% total)   MeshChatNetwork.node[2] (MeshNode, id=4)
[INFO]	🔁 Node 2 already saw message 3610582 - dropping
** Event #249  t=1  1% completed  (1% total)   MeshChatNetwork.node[1] (MeshNode, id=3)
[INFO]	🔁 Node 1 already saw message 4735832 - dropping
** Event #250  t=1  1% completed  (1% total)   MeshChatNetwork.node[2] (MeshNode, id=4)
[INFO]	🔁 Node 2 already saw message 4735832 - dropping
** Event #251  t=1.5  1% completed  (1% total)   MeshChatNetwork.node[0] (MeshNode, id=2)
[INFO]	📣 Node 0 sending broadcast: "Broadcast from Node 0!"
[INFO]	📤 Node 0 sent broadcast message 170585 to 2 neighbors
** Event #252  t=1.5  1% completed  (1% total)   MeshChatNetwork.node[1] (MeshNode, id=3)
[INFO]	📣 Node 1 sending broadcast: "Broadcast from Node 1!"
[INFO]	📤 Node 1 sent broadcast message 1839053 to 3 neighbors
** Event #253  t=1.5  1% completed  (1% total)   MeshChatNetwork.node[2] (MeshNode, id=4)
[INFO]	📣 Node 2 sending broadcast: "Broadcast from Node 2!"
[INFO]	📤 Node 2 sent broadcast message 2604475 to 3 neighbors
** Event #254  t=1.5  1% completed  (1% total)   MeshChatNetwork.node[3] (MeshNode, id=5)
[INFO]	📣 Node 3 sending broadcast: "Broadcast from Node 3!"
[INFO]	📤 Node 3 sent broadcast message 3541378 to 3 neighbors
** Event #255  t=1.5  1% completed  (1% total)   MeshChatNetwork.node[4] (MeshNode, id=6)
[INFO]	📣 Node 4 sending broadcast: "Broadcast from Node 4!"
[INFO]	📤 Node 4 sent broadcast message 4949735 to 3 neighbors
** Event #256  t=1.5  1% completed  (1% total)   MeshChatNetwork.node[5] (MeshNode, id=7)
[INFO]	📣 Node 5 sending broadcast: "Broadcast from Node 5!"
[INFO]	📤 Node 5 sent broadcast message 5674344 to 2 neighbors
** Event #257  t=1.5  1% completed  (1% total)   MeshChatNetwork.node[1] (MeshNode, id=3)
[INFO]	📨 Node 1 received broadcast message 170585 from Node 0: "Broadcast from Node 0!"
[INFO]	📤 Node 1 forwarded message 170585 to 3 neighbors (TTL=9)
** Event #258  t=1.5  1% completed  (1% total)   MeshChatNetwork.node[2] (MeshNode, id=4)
[INFO]	📨 Node 2 received broadcast message 170585 from Node 0: "Broadcast from Node 0!"
[INFO]	📤 Node 2 forwarded message 170585 to 3 neighbors (TTL=9)
** Event #259  t=1.5  1% completed  (1% total)   MeshChatNetwork.node[0] (MeshNode, id=2)
[INFO]	📨 Node 0 received broadcast message 1839053 from Node 1: "Broadcast from Node 1!"
[INFO]	📤 Node 0 forwarded message 1839053 to 2 neighbors (TTL=9)
** Event #260  t=1.5  1% completed  (1% total)   MeshChatNetwork.node[3] (MeshNode, id=5)
[INFO]	📨 Node 3 received broadcast message 1839053 from Node 1: "Broadcast from Node 1!"
[INFO]	📤 Node 3 forwarded message 1839053 to 3 neighbors (TTL=9)
** Event #261  t=1.5  1% completed  (1% total)   MeshChatNetwork.node[4] (MeshNode, id=6)
[INFO]	📨 Node 4 received broadcast message 1839053 from Node 1: "Broadcast from Node 1!"
[INFO]	📤 Node 4 forwarded message 1839053 to 3 neighbors (TTL=9)
** Event #262  t=1.5  1% completed  (1% total)   MeshChatNetwork.node[0] (MeshNode, id=2)
[INFO]	📨 Node 0 received broadcast message 2604475 from Node 2: "Broadcast from Node 2!"
[INFO]	📤 Node 0 forwarded message 2604475 to 2 neighbors (TTL=9)
** Event #263  t=1.5  1% completed  (1% total)   MeshChatNetwork.node[3] (MeshNode, id=5)
[INFO]	📨 Node 3 received broadcast message 2604475 from Node 2: "Broadcast from Node 2!"
[INFO]	📤 Node 3 forwarded message 2604475 to 3 neighbors (TTL=9)
** Event #264  t=1.5  1% completed  (1% total)   MeshChatNetwork.node[4] (MeshNode, id=6)
[INFO]	📨 Node 4 received broadcast message 2604475 from Node 2: "Broadcast from Node 2!"
[INFO]	📤 Node 4 forwarded message 2604475 to 3 neighbors (TTL=9)
** Event #265  t=1.5  1% completed  (1% total)   MeshChatNetwork.node[1] (MeshNode, id=3)
[INFO]	📨 Node 1 received broadcast message 3541378 from Node 3: "Broadcast from Node 3!"
[INFO]	📤 Node 1 forwarded message 3541378 to 3 neighbors (TTL=9)
** Event #266  t=1.5  1% completed  (1% total)   MeshChatNetwork.node[2] (MeshNode, id=4)
[INFO]	📨 Node 2 received broadcast message 3541378 from Node 3: "Broadcast from Node 3!"
[INFO]	📤 Node 2 forwarded message 3541378 to 3 neighbors (TTL=9)
** Event #267  t=1.5  1% completed  (1% total)   MeshChatNetwork.node[5] (MeshNode, id=7)
[INFO]	📨 Node 5 received broadcast message 3541378 from Node 3: "Broadcast from Node 3!"
[INFO]	📤 Node 5 forwarded message 3541378 to 2 neighbors (TTL=9)
** Event #268  t=1.5  1% completed  (1% total)   MeshChatNetwork.node[1] (MeshNode, id=3)
[INFO]	📨 Node 1 received broadcast message 4949735 from Node 4: "Broadcast from Node 4!"
[INFO]	📤 Node 1 forwarded message 4949735 to 3 neighbors (TTL=9)
** Event #269  t=1.5  1% completed  (1% total)   MeshChatNetwork.node[2] (MeshNode, id=4)
[INFO]	📨 Node 2 received broadcast message 4949735 from Node 4: "Broadcast from Node 4!"
[INFO]	📤 Node 2 forwarded message 4949735 to 3 neighbors (TTL=9)
** Event #270  t=1.5  1% completed  (1% total)   MeshChatNetwork.node[5] (MeshNode, id=7)
[INFO]	📨 Node 5 received broadcast message 4949735 from Node 4: "Broadcast from Node 4!"
[INFO]	📤 Node 5 forwarded message 4949735 to 2 neighbors (TTL=9)
** Event #271  t=1.5  1% completed  (1% total)   MeshChatNetwork.node[3] (MeshNode, id=5)
[INFO]	📨 Node 3 received broadcast message 5674344 from Node 5: "Broadcast from Node 5!"
[INFO]	📤 Node 3 forwarded message 5674344 to 3 neighbors (TTL=9)
** Event #272  t=1.5  1% completed  (1% total)   MeshChatNetwork.node[4] (MeshNode, id=6)
[INFO]	📨 Node 4 received broadcast message 5674344 from Node 5: "Broadcast from Node 5!"
[INFO]	📤 Node 4 forwarded message 5674344 to 3 neighbors (TTL=9)
** Event #273  t=1.5  1% completed  (1% total)   MeshChatNetwork.node[0] (MeshNode, id=2)
** Event #274  t=1.5  1% completed  (1% total)   MeshChatNetwork.node[3] (MeshNode, id=5)
[INFO]	📨 Node 3 received broadcast message 170585 from Node 0: "Broadcast from Node 0!"
[INFO]	📤 Node 3 forwarded message 170585 to 3 neighbors (TTL=8)
** Event #275  t=1.5  1% completed  (1% total)   MeshChatNetwork.node[4] (MeshNode, id=6)
[INFO]	📨 Node 4 received broadcast message 170585 from Node 0: "Broadcast from Node 0!"
[INFO]	📤 Node 4 forwarded message 170585 to 3 neighbors (TTL=8)
** Event #276  t=1.5  1% completed  (1% total)   MeshChatNetwork.node[0] (MeshNode, id=2)
** Event #277  t=1.5  1% completed  (1% total)   MeshChatNetwork.node[3] (MeshNode, id=5)
[INFO]	🔁 Node 3 already saw message 170585 - dropping
** Event #278  t=1.5  1% completed  (1% total)   MeshChatNetwork.node[4] (MeshNode, id=6)
[INFO]	🔁 Node 4 already saw message 170585 - dropping
** Event #279  t=1.5  1% completed  (1% total)   MeshChatNetwork.node[1] (MeshNode, id=3)
** Event #280  t=1.5  1% completed  (1% total)   MeshChatNetwork.node[2] (MeshNode, id=4)
[INFO]	📨 Node 2 received broadcast message 1839053 from Node 1: "Broadcast from Node 1!"
[INFO]	📤 Node 2 forwarded message 1839053 to 3 neighbors (TTL=8)
** Event #281  t=1.5  1% completed  (1% total)   MeshChatNetwork.node[1] (MeshNode, id=3)
** Event #282  t=1.5  1% completed  (1% total)   MeshChatNetwork.node[2] (MeshNode, id=4)
[INFO]	🔁 Node 2 already saw message 1839053 - dropping
** Event #283  t=1.5  1% completed  (1% total)   MeshChatNetwork.node[5] (MeshNode, id=7)
[INFO]	📨 Node 5 received broadcast message 1839053 from Node 1: "Broadcast from Node 1!"
[INFO]	📤 Node 5 forwarded message 1839053 to 2 neighbors (TTL=8)
** Event #284  t=1.5  1% completed  (1% total)   MeshChatNetwork.node[1] (MeshNode, id=3)
** Event #285  t=1.5  1% completed  (1% total)   MeshChatNetwork.node[2] (MeshNode, id=4)
[INFO]	🔁 Node 2 already saw message 1839053 - dropping
** Event #286  t=1.5  1% completed  (1% total)   MeshChatNetwork.node[5] (MeshNode, id=7)
[INFO]	🔁 Node 5 already saw message 1839053 - dropping
** Event #287  t=1.5  1% completed  (1% total)   MeshChatNetwork.node[1] (MeshNode, id=3)
[INFO]	📨 Node 1 received broadcast message 2604475 from Node 2: "Broadcast from Node 2!"
[INFO]	📤 Node 1 forwarded message 2604475 to 3 neighbors (TTL=8)
** Event #288  t=1.5  1% completed  (1% total)   MeshChatNetwork.node[2] (MeshNode, id=4)
** Event #289  t=1.5  1% completed  (1% total)   MeshChatNetwork.node[1] (MeshNode, id=3)
[INFO]	🔁 Node 1 already saw message 2604475 - dropping
** Event #290  t=1.5  1% completed  (1% total)   MeshChatNetwork.node[2] (MeshNode, id=4)
** Event #291  t=1.5  1% completed  (1% total)   MeshChatNetwork.node[5] (MeshNode, id=7)
[INFO]	📨 Node 5 received broadcast message 2604475 from Node 2: "Broadcast from Node 2!"
[INFO]	📤 Node 5 forwarded message 2604475 to 2 neighbors (TTL=8)
** Event #292  t=1.5  1% completed  (1% total)   MeshChatNetwork.node[1] (MeshNode, id=3)
[INFO]	🔁 Node 1 already saw message 2604475 - dropping
** Event #293  t=1.5  1% completed  (1% total)   MeshChatNetwork.node[2] (MeshNode, id=4)
** Event #294  t=1.5  1% completed  (1% total)   MeshChatNetwork.node[5] (MeshNode, id=7)
[INFO]	🔁 Node 5 already saw message 2604475 - dropping
** Event #295  t=1.5  1% completed  (1% total)   MeshChatNetwork.node[0] (MeshNode, id=2)
[INFO]	📨 Node 0 received broadcast message 3541378 from Node 3: "Broadcast from Node 3!"
[INFO]	📤 Node 0 forwarded message 3541378 to 2 neighbors (TTL=8)
** Event #296  t=1.5  1% completed  (1% total)   MeshChatNetwork.node[3] (MeshNode, id=5)
** Event #297  t=1.5  1% completed  (1% total)   MeshChatNetwork.node[4] (MeshNode, id=6)
[INFO]	📨 Node 4 received broadcast message 3541378 from Node 3: "Broadcast from Node 3!"
[INFO]	📤 Node 4 forwarded message 3541378 to 3 neighbors (TTL=8)
** Event #298  t=1.5  1% completed  (1% total)   MeshChatNetwork.node[0] (MeshNode, id=2)
[INFO]	🔁 Node 0 already saw message 3541378 - dropping
** Event #299  t=1.5  1% completed  (1% total)   MeshChatNetwork.node[3] (MeshNode, id=5)
** Event #300  t=1.5  1% completed  (1% total)   MeshChatNetwork.node[4] (MeshNode, id=6)
[INFO]	🔁 Node 4 already saw message 3541378 - dropping
** Event #301  t=1.5  1% completed  (1% total)   MeshChatNetwork.node[3] (MeshNode, id=5)
** Event #302  t=1.5  1% completed  (1% total)   MeshChatNetwork.node[4] (MeshNode, id=6)
[INFO]	🔁 Node 4 already saw message 3541378 - dropping
** Event #303  t=1.5  1% completed  (1% total)   MeshChatNetwork.node[0] (MeshNode, id=2)
[INFO]	📨 Node 0 received broadcast message 4949735 from Node 4: "Broadcast from Node 4!"
[INFO]	📤 Node 0 forwarded message 4949735 to 2 neighbors (TTL=8)
** Event #304  t=1.5  1% completed  (1% total)   MeshChatNetwork.node[3] (MeshNode, id=5)
[INFO]	📨 Node 3 received broadcast message 4949735 from Node 4: "Broadcast from Node 4!"
[INFO]	📤 Node 3 forwarded message 4949735 to 3 neighbors (TTL=8)
** Event #305  t=1.5  1% completed  (1% total)   MeshChatNetwork.node[4] (MeshNode, id=6)
** Event #306  t=1.5  1% completed  (1% total)   MeshChatNetwork.node[0] (MeshNode, id=2)
[INFO]	🔁 Node 0 already saw message 4949735 - dropping
** Event #307  t=1.5  1% completed  (1% total)   MeshChatNetwork.node[3] (MeshNode, id=5)
[INFO]	🔁 Node 3 already saw message 4949735 - dropping
** Event #308  t=1.5  1% completed  (1% total)   MeshChatNetwork.node[4] (MeshNode, id=6)
** Event #309  t=1.5  1% completed  (1% total)   MeshChatNetwork.node[3] (MeshNode, id=5)
[INFO]	🔁 Node 3 already saw message 4949735 - dropping
** Event #310  t=1.5  1% completed  (1% total)   MeshChatNetwork.node[4] (MeshNode, id=6)
** Event #311  t=1.5  1% completed  (1% total)   MeshChatNetwork.node[1] (MeshNode, id=3)
[INFO]	📨 Node 1 received broadcast message 5674344 from Node 5: "Broadcast from Node 5!"
[INFO]	📤 Node 1 forwarded message 5674344 to 3 neighbors (TTL=8)
** Event #312  t=1.5  1% completed  (1% total)   MeshChatNetwork.node[2] (MeshNode, id=4)
[INFO]	📨 Node 2 received broadcast message 5674344 from Node 5: "Broadcast from Node 5!"
[INFO]	📤 Node 2 forwarded message 5674344 to 3 neighbors (TTL=8)
** Event #313  t=1.5  1% completed  (1% total)   MeshChatNetwork.node[5] (MeshNode, id=7)
** Event #314  t=1.5  1% completed  (1% total)   MeshChatNetwork.node[1] (MeshNode, id=3)
[INFO]	🔁 Node 1 already saw message 5674344 - dropping
** Event #315  t=1.5  1% completed  (1% total)   MeshChatNetwork.node[2] (MeshNode, id=4)
[INFO]	🔁 Node 2 already saw message 5674344 - dropping
** Event #316  t=1.5  1% completed  (1% total)   MeshChatNetwork.node[5] (MeshNode, id=7)
** Event #317  t=1.5  1% completed  (1% total)   MeshChatNetwork.node[1] (MeshNode, id=3)
[INFO]	🔁 Node 1 already saw message 170585 - dropping
** Event #318  t=1.5  1% completed  (1% total)   MeshChatNetwork.node[2] (MeshNode, id=4)
[INFO]	🔁 Node 2 already saw message 170585 - dropping
** Event #319  t=1.5  1% completed  (1% total)   MeshChatNetwork.node[5] (MeshNode, id=7)
[INFO]	📨 Node 5 received broadcast message 170585 from Node 0: "Broadcast from Node 0!"
[INFO]	📤 Node 5 forwarded message 170585 to 2 neighbors (TTL=7)
** Event #320  t=1.5  1% completed  (1% total)   MeshChatNetwork.node[1] (MeshNode, id=3)
[INFO]	🔁 Node 1 already saw message 170585 - dropping
** Event #321  t=1.5  1% completed  (1% total)   MeshChatNetwork.node[2] (MeshNode, id=4)
[INFO]	🔁 Node 2 already saw message 170585 - dropping
** Event #322  t=1.5  1% completed  (1% total)   MeshChatNetwork.node[5] (MeshNode, id=7)
[INFO]	🔁 Node 5 already saw message 170585 - dropping
** Event #323  t=1.5  1% completed  (1% total)   MeshChatNetwork.node[0] (MeshNode, id=2)
[INFO]	🔁 Node 0 already saw message 1839053 - dropping
** Event #324  t=1.5  1% completed  (1% total)   MeshChatNetwork.node[3] (MeshNode, id=5)
[INFO]	🔁 Node 3 already saw message 1839053 - dropping
** Event #325  t=1.5  1% completed  (1% total)   MeshChatNetwork.node[4] (MeshNode, id=6)
[INFO]	🔁 Node 4 already saw message 1839053 - dropping
** Event #326  t=1.5  1% completed  (1% total)   MeshChatNetwork.node[3] (MeshNode, id=5)
[INFO]	🔁 Node 3 already saw message 1839053 - dropping
** Event #327  t=1.5  1% completed  (1% total)   MeshChatNetwork.node[4] (MeshNode, id=6)
[INFO]	🔁 Node 4 already saw message 1839053 - dropping
** Event #328  t=1.5  1% completed  (1% total)   MeshChatNetwork.node[0] (MeshNode, id=2)
[INFO]	🔁 Node 0 already saw message 2604475 - dropping
** Event #329  t=1.5  1% completed  (1% total)   MeshChatNetwork.node[3] (MeshNode, id=5)
[INFO]	🔁 Node 3 already saw message 2604475 - dropping
** Event #330  t=1.5  1% completed  (1% total)   MeshChatNetwork.node[4] (MeshNode, id=6)
[INFO]	🔁 Node 4 already saw message 2604475 - dropping
** Event #331  t=1.5  1% completed  (1% total)   MeshChatNetwork.node[3] (MeshNode, id=5)
[INFO]	🔁 Node 3 already saw message 2604475 - dropping
** Event #332  t=1.5  1% completed  (1% total)   MeshChatNetwork.node[4] (MeshNode, id=6)
[INFO]	🔁 Node 4 already saw message 2604475 - dropping
** Event #333  t=1.5  1% completed  (1% total)   MeshChatNetwork.node[1] (MeshNode, id=3)
[INFO]	🔁 Node 1 already saw message 3541378 - dropping
** Event #334  t=1.5  1% completed  (1% total)   MeshChatNetwork.node[2] (MeshNode, id=4)
[INFO]	🔁 Node 2 already saw message 3541378 - dropping
** Event #335  t=1.5  1% completed  (1% total)   MeshChatNetwork.node[1] (MeshNode, id=3)
[INFO]	🔁 Node 1 already saw message 3541378 - dropping
** Event #336  t=1.5  1% completed  (1% total)   MeshChatNetwork.node[2] (MeshNode, id=4)
[INFO]	🔁 Node 2 already saw message 3541378 - dropping
** Event #337  t=1.5  1% completed  (1% total)   MeshChatNetwork.node[5] (MeshNode, id=7)
[INFO]	🔁 Node 5 already saw message 3541378 - dropping
** Event #338  t=1.5  1% completed  (1% total)   MeshChatNetwork.node[1] (MeshNode, id=3)
[INFO]	🔁 Node 1 already saw message 4949735 - dropping
** Event #339  t=1.5  1% completed  (1% total)   MeshChatNetwork.node[2] (MeshNode, id=4)
[INFO]	🔁 Node 2 already saw message 4949735 - dropping
** Event #340  t=1.5  1% completed  (1% total)   MeshChatNetwork.node[1] (MeshNode, id=3)
[INFO]	🔁 Node 1 already saw message 4949735 - dropping
** Event #341  t=1.5  1% completed  (1% total)   MeshChatNetwork.node[2] (MeshNode, id=4)
[INFO]	🔁 Node 2 already saw message 4949735 - dropping
** Event #342  t=1.5  1% completed  (1% total)   MeshChatNetwork.node[5] (MeshNode, id=7)
[INFO]	🔁 Node 5 already saw message 4949735 - dropping
** Event #343  t=1.5  1% completed  (1% total)   MeshChatNetwork.node[0] (MeshNode, id=2)
[INFO]	📨 Node 0 received broadcast message 5674344 from Node 5: "Broadcast from Node 5!"
[INFO]	📤 Node 0 forwarded message 5674344 to 2 neighbors (TTL=7)
** Event #344  t=1.5  1% completed  (1% total)   MeshChatNetwork.node[3] (MeshNode, id=5)
[INFO]	🔁 Node 3 already saw message 5674344 - dropping
** Event #345  t=1.5  1% completed  (1% total)   MeshChatNetwork.node[4] (MeshNode, id=6)
[INFO]	🔁 Node 4 already saw message 5674344 - dropping
** Event #346  t=1.5  1% completed  (1% total)   MeshChatNetwork.node[0] (MeshNode, id=2)
[INFO]	🔁 Node 0 already saw message 5674344 - dropping
** Event #347  t=1.5  1% completed  (1% total)   MeshChatNetwork.node[3] (MeshNode, id=5)
[INFO]	🔁 Node 3 already saw message 5674344 - dropping
** Event #348  t=1.5  1% completed  (1% total)   MeshChatNetwork.node[4] (MeshNode, id=6)
[INFO]	🔁 Node 4 already saw message 5674344 - dropping
** Event #349  t=1.5  1% completed  (1% total)   MeshChatNetwork.node[3] (MeshNode, id=5)
[INFO]	🔁 Node 3 already saw message 170585 - dropping
** Event #350  t=1.5  1% completed  (1% total)   MeshChatNetwork.node[4] (MeshNode, id=6)
[INFO]	🔁 Node 4 already saw message 170585 - dropping
** Event #351  t=1.5  1% completed  (1% total)   MeshChatNetwork.node[1] (MeshNode, id=3)
[INFO]	🔁 Node 1 already saw message 5674344 - dropping
** Event #352  t=1.5  1% completed  (1% total)   MeshChatNetwork.node[2] (MeshNode, id=4)
[INFO]	🔁 Node 2 already saw message 5674344 - dropping
** Event #353  t=2  2% completed  (2% total)   MeshChatNetwork.node[0] (MeshNode, id=2)
[INFO]	🚨 Node 0 sending EMERGENCY ALERT!
[INFO]	📤 Node 0 sent emergency alert 370776 to 2 neighbors
** Event #354  t=2  2% completed  (2% total)   MeshChatNetwork.node[1] (MeshNode, id=3)
[INFO]	🚨 Node 1 sending EMERGENCY ALERT!
[INFO]	📤 Node 1 sent emergency alert 1745049 to 3 neighbors
** Event #355  t=2  2% completed  (2% total)   MeshChatNetwork.node[2] (MeshNode, id=4)
[INFO]	🚨 Node 2 sending EMERGENCY ALERT!
[INFO]	📤 Node 2 sent emergency alert 2887634 to 3 neighbors
** Event #356  t=2  2% completed  (2% total)   MeshChatNetwork.node[3] (MeshNode, id=5)
[INFO]	🚨 Node 3 sending EMERGENCY ALERT!
[INFO]	📤 Node 3 sent emergency alert 3255654 to 3 neighbors
** Event #357  t=2  2% completed  (2% total)   MeshChatNetwork.node[4] (MeshNode, id=6)
[INFO]	🚨 Node 4 sending EMERGENCY ALERT!
[INFO]	📤 Node 4 sent emergency alert 4606746 to 3 neighbors
** Event #358  t=2  2% completed  (2% total)   MeshChatNetwork.node[5] (MeshNode, id=7)
[INFO]	🚨 Node 5 sending EMERGENCY ALERT!
[INFO]	📤 Node 5 sent emergency alert 5924426 to 2 neighbors
** Event #359  t=2  2% completed  (2% total)   MeshChatNetwork.node[1] (MeshNode, id=3)
[INFO]	🚨 Node 1 received EMERGENCY message 370776 from Node 0
[INFO]	📨 Node 1 received broadcast message 370776 from Node 0: "EMERGENCY from Node 0!"
[INFO]	📤 Node 1 forwarded message 370776 to 3 neighbors (TTL=9)
** Event #360  t=2  2% completed  (2% total)   MeshChatNetwork.node[2] (MeshNode, id=4)
[INFO]	🚨 Node 2 received EMERGENCY message 370776 from Node 0
[INFO]	📨 Node 2 received broadcast message 370776 from Node 0: "EMERGENCY from Node 0!"
[INFO]	📤 Node 2 forwarded message 370776 to 3 neighbors (TTL=9)
** Event #361  t=2  2% completed  (2% total)   MeshChatNetwork.node[0] (MeshNode, id=2)
[INFO]	🚨 Node 0 received EMERGENCY message 1745049 from Node 1
[INFO]	📨 Node 0 received broadcast message 1745049 from Node 1: "EMERGENCY from Node 1!"
[INFO]	📤 Node 0 forwarded message 1745049 to 2 neighbors (TTL=9)
** Event #362  t=2  2% completed  (2% total)   MeshChatNetwork.node[3] (MeshNode, id=5)
[INFO]	🚨 Node 3 received EMERGENCY message 1745049 from Node 1
[INFO]	📨 Node 3 received broadcast message 1745049 from Node 1: "EMERGENCY from Node 1!"
[INFO]	📤 Node 3 forwarded message 1745049 to 3 neighbors (TTL=9)
** Event #363  t=2  2% completed  (2% total)   MeshChatNetwork.node[4] (MeshNode, id=6)
[INFO]	🚨 Node 4 received EMERGENCY message 1745049 from Node 1
[INFO]	📨 Node 4 received broadcast message 1745049 from Node 1: "EMERGENCY from Node 1!"
[INFO]	📤 Node 4 forwarded message 1745049 to 3 neighbors (TTL=9)
** Event #364  t=2  2% completed  (2% total)   MeshChatNetwork.node[0] (MeshNode, id=2)
[INFO]	🚨 Node 0 received EMERGENCY message 2887634 from Node 2
[INFO]	📨 Node 0 received broadcast message 2887634 from Node 2: "EMERGENCY from Node 2!"
[INFO]	📤 Node 0 forwarded message 2887634 to 2 neighbors (TTL=9)
** Event #365  t=2  2% completed  (2% total)   MeshChatNetwork.node[3] (MeshNode, id=5)
[INFO]	🚨 Node 3 received EMERGENCY message 2887634 from Node 2
[INFO]	📨 Node 3 received broadcast message 2887634 from Node 2: "EMERGENCY from Node 2!"
[INFO]	📤 Node 3 forwarded message 2887634 to 3 neighbors (TTL=9)
** Event #366  t=2  2% completed  (2% total)   MeshChatNetwork.node[4] (MeshNode, id=6)
[INFO]	🚨 Node 4 received EMERGENCY message 2887634 from Node 2
[INFO]	📨 Node 4 received broadcast message 2887634 from Node 2: "EMERGENCY from Node 2!"
[INFO]	📤 Node 4 forwarded message 2887634 to 3 neighbors (TTL=9)
** Event #367  t=2  2% completed  (2% total)   MeshChatNetwork.node[1] (MeshNode, id=3)
[INFO]	🚨 Node 1 received EMERGENCY message 3255654 from Node 3
[INFO]	📨 Node 1 received broadcast message 3255654 from Node 3: "EMERGENCY from Node 3!"
[INFO]	📤 Node 1 forwarded message 3255654 to 3 neighbors (TTL=9)
** Event #368  t=2  2% completed  (2% total)   MeshChatNetwork.node[2] (MeshNode, id=4)
[INFO]	🚨 Node 2 received EMERGENCY message 3255654 from Node 3
[INFO]	📨 Node 2 received broadcast message 3255654 from Node 3: "EMERGENCY from Node 3!"
[INFO]	📤 Node 2 forwarded message 3255654 to 3 neighbors (TTL=9)
** Event #369  t=2  2% completed  (2% total)   MeshChatNetwork.node[5] (MeshNode, id=7)
[INFO]	🚨 Node 5 received EMERGENCY message 3255654 from Node 3
[INFO]	📨 Node 5 received broadcast message 3255654 from Node 3: "EMERGENCY from Node 3!"
[INFO]	📤 Node 5 forwarded message 3255654 to 2 neighbors (TTL=9)
** Event #370  t=2  2% completed  (2% total)   MeshChatNetwork.node[1] (MeshNode, id=3)
[INFO]	🚨 Node 1 received EMERGENCY message 4606746 from Node 4
[INFO]	📨 Node 1 received broadcast message 4606746 from Node 4: "EMERGENCY from Node 4!"
[INFO]	📤 Node 1 forwarded message 4606746 to 3 neighbors (TTL=9)
** Event #371  t=2  2% completed  (2% total)   MeshChatNetwork.node[2] (MeshNode, id=4)
[INFO]	🚨 Node 2 received EMERGENCY message 4606746 from Node 4
[INFO]	📨 Node 2 received broadcast message 4606746 from Node 4: "EMERGENCY from Node 4!"
[INFO]	📤 Node 2 forwarded message 4606746 to 3 neighbors (TTL=9)
** Event #372  t=2  2% completed  (2% total)   MeshChatNetwork.node[5] (MeshNode, id=7)
[INFO]	🚨 Node 5 received EMERGENCY message 4606746 from Node 4
[INFO]	📨 Node 5 received broadcast message 4606746 from Node 4: "EMERGENCY from Node 4!"
[INFO]	📤 Node 5 forwarded message 4606746 to 2 neighbors (TTL=9)
** Event #373  t=2  2% completed  (2% total)   MeshChatNetwork.node[3] (MeshNode, id=5)
[INFO]	🚨 Node 3 received EMERGENCY message 5924426 from Node 5
[INFO]	📨 Node 3 received broadcast message 5924426 from Node 5: "EMERGENCY from Node 5!"
[INFO]	📤 Node 3 forwarded message 5924426 to 3 neighbors (TTL=9)
** Event #374  t=2  2% completed  (2% total)   MeshChatNetwork.node[4] (MeshNode, id=6)
[INFO]	🚨 Node 4 received EMERGENCY message 5924426 from Node 5
[INFO]	📨 Node 4 received broadcast message 5924426 from Node 5: "EMERGENCY from Node 5!"
[INFO]	📤 Node 4 forwarded message 5924426 to 3 neighbors (TTL=9)
** Event #375  t=2  2% completed  (2% total)   MeshChatNetwork.node[0] (MeshNode, id=2)
** Event #376  t=2  2% completed  (2% total)   MeshChatNetwork.node[3] (MeshNode, id=5)
[INFO]	🚨 Node 3 received EMERGENCY message 370776 from Node 0
[INFO]	📨 Node 3 received broadcast message 370776 from Node 0: "EMERGENCY from Node 0!"
[INFO]	📤 Node 3 forwarded message 370776 to 3 neighbors (TTL=8)
** Event #377  t=2  2% completed  (2% total)   MeshChatNetwork.node[4] (MeshNode, id=6)
[INFO]	🚨 Node 4 received EMERGENCY message 370776 from Node 0
[INFO]	📨 Node 4 received broadcast message 370776 from Node 0: "EMERGENCY from Node 0!"
[INFO]	📤 Node 4 forwarded message 370776 to 3 neighbors (TTL=8)
** Event #378  t=2  2% completed  (2% total)   MeshChatNetwork.node[0] (MeshNode, id=2)
** Event #379  t=2  2% completed  (2% total)   MeshChatNetwork.node[3] (MeshNode, id=5)
[INFO]	🔁 Node 3 already saw message 370776 - dropping
** Event #380  t=2  2% completed  (2% total)   MeshChatNetwork.node[4] (MeshNode, id=6)
[INFO]	🔁 Node 4 already saw message 370776 - dropping
** Event #381  t=2  2% completed  (2% total)   MeshChatNetwork.node[1] (MeshNode, id=3)
** Event #382  t=2  2% completed  (2% total)   MeshChatNetwork.node[2] (MeshNode, id=4)
[INFO]	🚨 Node 2 received EMERGENCY message 1745049 from Node 1
[INFO]	📨 Node 2 received broadcast message 1745049 from Node 1: "EMERGENCY from Node 1!"
[INFO]	📤 Node 2 forwarded message 1745049 to 3 neighbors (TTL=8)
** Event #383  t=2  2% completed  (2% total)   MeshChatNetwork.node[1] (MeshNode, id=3)
** Event #384  t=2  2% completed  (2% total)   MeshChatNetwork.node[2] (MeshNode, id=4)
[INFO]	🔁 Node 2 already saw message 1745049 - dropping
** Event #385  t=2  2% completed  (2% total)   MeshChatNetwork.node[5] (MeshNode, id=7)
[INFO]	🚨 Node 5 received EMERGENCY message 1745049 from Node 1
[INFO]	📨 Node 5 received broadcast message 1745049 from Node 1: "EMERGENCY from Node 1!"
[INFO]	📤 Node 5 forwarded message 1745049 to 2 neighbors (TTL=8)
** Event #386  t=2  2% completed  (2% total)   MeshChatNetwork.node[1] (MeshNode, id=3)
** Event #387  t=2  2% completed  (2% total)   MeshChatNetwork.node[2] (MeshNode, id=4)
[INFO]	🔁 Node 2 already saw message 1745049 - dropping
** Event #388  t=2  2% completed  (2% total)   MeshChatNetwork.node[5] (MeshNode, id=7)
[INFO]	🔁 Node 5 already saw message 1745049 - dropping
** Event #389  t=2  2% completed  (2% total)   MeshChatNetwork.node[1] (MeshNode, id=3)
[INFO]	🚨 Node 1 received EMERGENCY message 2887634 from Node 2
[INFO]	📨 Node 1 received broadcast message 2887634 from Node 2: "EMERGENCY from Node 2!"
[INFO]	📤 Node 1 forwarded message 2887634 to 3 neighbors (TTL=8)
** Event #390  t=2  2% completed  (2% total)   MeshChatNetwork.node[2] (MeshNode, id=4)
** Event #391  t=2  2% completed  (2% total)   MeshChatNetwork.node[1] (MeshNode, id=3)
[INFO]	🔁 Node 1 already saw message 2887634 - dropping
** Event #392  t=2  2% completed  (2% total)   MeshChatNetwork.node[2] (MeshNode, id=4)
** Event #393  t=2  2% completed  (2% total)   MeshChatNetwork.node[5] (MeshNode, id=7)
[INFO]	🚨 Node 5 received EMERGENCY message 2887634 from Node 2
[INFO]	📨 Node 5 received broadcast message 2887634 from Node 2: "EMERGENCY from Node 2!"
[INFO]	📤 Node 5 forwarded message 2887634 to 2 neighbors (TTL=8)
** Event #394  t=2  2% completed  (2% total)   MeshChatNetwork.node[1] (MeshNode, id=3)
[INFO]	🔁 Node 1 already saw message 2887634 - dropping
** Event #395  t=2  2% completed  (2% total)   MeshChatNetwork.node[2] (MeshNode, id=4)
** Event #396  t=2  2% completed  (2% total)   MeshChatNetwork.node[5] (MeshNode, id=7)
[INFO]	🔁 Node 5 already saw message 2887634 - dropping
** Event #397  t=2  2% completed  (2% total)   MeshChatNetwork.node[0] (MeshNode, id=2)
[INFO]	🚨 Node 0 received EMERGENCY message 3255654 from Node 3
[INFO]	📨 Node 0 received broadcast message 3255654 from Node 3: "EMERGENCY from Node 3!"
[INFO]	📤 Node 0 forwarded message 3255654 to 2 neighbors (TTL=8)
** Event #398  t=2  2% completed  (2% total)   MeshChatNetwork.node[3] (MeshNode, id=5)
** Event #399  t=2  2% completed  (2% total)   MeshChatNetwork.node[4] (MeshNode, id=6)
[INFO]	🚨 Node 4 received EMERGENCY message 3255654 from Node 3
[INFO]	📨 Node 4 received broadcast message 3255654 from Node 3: "EMERGENCY from Node 3!"
[INFO]	📤 Node 4 forwarded message 3255654 to 3 neighbors (TTL=8)
** Event #400  t=2  2% completed  (2% total)   MeshChatNetwork.node[0] (MeshNode, id=2)
[INFO]	🔁 Node 0 already saw message 3255654 - dropping
** Event #401  t=2  2% completed  (2% total)   MeshChatNetwork.node[3] (MeshNode, id=5)
** Event #402  t=2  2% completed  (2% total)   MeshChatNetwork.node[4] (MeshNode, id=6)
[INFO]	🔁 Node 4 already saw message 3255654 - dropping
** Event #403  t=2  2% completed  (2% total)   MeshChatNetwork.node[3] (MeshNode, id=5)
** Event #404  t=2  2% completed  (2% total)   MeshChatNetwork.node[4] (MeshNode, id=6)
[INFO]	🔁 Node 4 already saw message 3255654 - dropping
** Event #405  t=2  2% completed  (2% total)   MeshChatNetwork.node[0] (MeshNode, id=2)
[INFO]	🚨 Node 0 received EMERGENCY message 4606746 from Node 4
[INFO]	📨 Node 0 received broadcast message 4606746 from Node 4: "EMERGENCY from Node 4!"
[INFO]	📤 Node 0 forwarded message 4606746 to 2 neighbors (TTL=8)
** Event #406  t=2  2% completed  (2% total)   MeshChatNetwork.node[3] (MeshNode, id=5)
[INFO]	🚨 Node 3 received EMERGENCY message 4606746 from Node 4
[INFO]	📨 Node 3 received broadcast message 4606746 from Node 4: "EMERGENCY from Node 4!"
[INFO]	📤 Node 3 forwarded message 4606746 to 3 neighbors (TTL=8)
** Event #407  t=2  2% completed  (2% total)   MeshChatNetwork.node[4] (MeshNode, id=6)
** Event #408  t=2  2% completed  (2% total)   MeshChatNetwork.node[0] (MeshNode, id=2)
[INFO]	🔁 Node 0 already saw message 4606746 - dropping
** Event #409  t=2  2% completed  (2% total)   MeshChatNetwork.node[3] (MeshNode, id=5)
[INFO]	🔁 Node 3 already saw message 4606746 - dropping
** Event #410  t=2  2% completed  (2% total)   MeshChatNetwork.node[4] (MeshNode, id=6)
** Event #411  t=2  2% completed  (2% total)   MeshChatNetwork.node[3] (MeshNode, id=5)
[INFO]	🔁 Node 3 already saw message 4606746 - dropping
** Event #412  t=2  2% completed  (2% total)   MeshChatNetwork.node[4] (MeshNode, id=6)
** Event #413  t=2  2% completed  (2% total)   MeshChatNetwork.node[1] (MeshNode, id=3)
[INFO]	🚨 Node 1 received EMERGENCY message 5924426 from Node 5
[INFO]	📨 Node 1 received broadcast message 5924426 from Node 5: "EMERGENCY from Node 5!"
[INFO]	📤 Node 1 forwarded message 5924426 to 3 neighbors (TTL=8)
** Event #414  t=2  2% completed  (2% total)   MeshChatNetwork.node[2] (MeshNode, id=4)
[INFO]	🚨 Node 2 received EMERGENCY message 5924426 from Node 5
[INFO]	📨 Node 2 received broadcast message 5924426 from Node 5: "EMERGENCY from Node 5!"
[INFO]	📤 Node 2 forwarded message 5924426 to 3 neighbors (TTL=8)
** Event #415  t=2  2% completed  (2% total)   MeshChatNetwork.node[5] (MeshNode, id=7)
** Event #416  t=2  2% completed  (2% total)   MeshChatNetwork.node[1] (MeshNode, id=3)
[INFO]	🔁 Node 1 already saw message 5924426 - dropping
** Event #417  t=2  2% completed  (2% total)   MeshChatNetwork.node[2] (MeshNode, id=4)
[INFO]	🔁 Node 2 already saw message 5924426 - dropping
** Event #418  t=2  2% completed  (2% total)   MeshChatNetwork.node[5] (MeshNode, id=7)
** Event #419  t=2  2% completed  (2% total)   MeshChatNetwork.node[1] (MeshNode, id=3)
[INFO]	🔁 Node 1 already saw message 370776 - dropping
** Event #420  t=2  2% completed  (2% total)   MeshChatNetwork.node[2] (MeshNode, id=4)
[INFO]	🔁 Node 2 already saw message 370776 - dropping
** Event #421  t=2  2% completed  (2% total)   MeshChatNetwork.node[5] (MeshNode, id=7)
[INFO]	🚨 Node 5 received EMERGENCY message 370776 from Node 0
[INFO]	📨 Node 5 received broadcast message 370776 from Node 0: "EMERGENCY from Node 0!"
[INFO]	📤 Node 5 forwarded message 370776 to 2 neighbors (TTL=7)
** Event #422  t=2  2% completed  (2% total)   MeshChatNetwork.node[1] (MeshNode, id=3)
[INFO]	🔁 Node 1 already saw message 370776 - dropping
** Event #423  t=2  2% completed  (2% total)   MeshChatNetwork.node[2] (MeshNode, id=4)
[INFO]	🔁 Node 2 already saw message 370776 - dropping
** Event #424  t=2  2% completed  (2% total)   MeshChatNetwork.node[5] (MeshNode, id=7)
[INFO]	🔁 Node 5 already saw message 370776 - dropping
** Event #425  t=2  2% completed  (2% total)   MeshChatNetwork.node[0] (MeshNode, id=2)
[INFO]	🔁 Node 0 already saw message 1745049 - dropping
** Event #426  t=2  2% completed  (2% total)   MeshChatNetwork.node[3] (MeshNode, id=5)
[INFO]	🔁 Node 3 already saw message 1745049 - dropping
** Event #427  t=2  2% completed  (2% total)   MeshChatNetwork.node[4] (MeshNode, id=6)
[INFO]	🔁 Node 4 already saw message 1745049 - dropping
** Event #428  t=2  2% completed  (2% total)   MeshChatNetwork.node[3] (MeshNode, id=5)
[INFO]	🔁 Node 3 already saw message 1745049 - dropping
** Event #429  t=2  2% completed  (2% total)   MeshChatNetwork.node[4] (MeshNode, id=6)
[INFO]	🔁 Node 4 already saw message 1745049 - dropping
** Event #430  t=2  2% completed  (2% total)   MeshChatNetwork.node[0] (MeshNode, id=2)
[INFO]	🔁 Node 0 already saw message 2887634 - dropping
** Event #431  t=2  2% completed  (2% total)   MeshChatNetwork.node[3] (MeshNode, id=5)
[INFO]	🔁 Node 3 already saw message 2887634 - dropping
** Event #432  t=2  2% completed  (2% total)   MeshChatNetwork.node[4] (MeshNode, id=6)
[INFO]	🔁 Node 4 already saw message 2887634 - dropping
** Event #433  t=2  2% completed  (2% total)   MeshChatNetwork.node[3] (MeshNode, id=5)
[INFO]	🔁 Node 3 already saw message 2887634 - dropping
** Event #434  t=2  2% completed  (2% total)   MeshChatNetwork.node[4] (MeshNode, id=6)
[INFO]	🔁 Node 4 already saw message 2887634 - dropping
** Event #435  t=2  2% completed  (2% total)   MeshChatNetwork.node[1] (MeshNode, id=3)
[INFO]	🔁 Node 1 already saw message 3255654 - dropping
** Event #436  t=2  2% completed  (2% total)   MeshChatNetwork.node[2] (MeshNode, id=4)
[INFO]	🔁 Node 2 already saw message 3255654 - dropping
** Event #437  t=2  2% completed  (2% total)   MeshChatNetwork.node[1] (MeshNode, id=3)
[INFO]	🔁 Node 1 already saw message 3255654 - dropping
** Event #438  t=2  2% completed  (2% total)   MeshChatNetwork.node[2] (MeshNode, id=4)
[INFO]	🔁 Node 2 already saw message 3255654 - dropping
** Event #439  t=2  2% completed  (2% total)   MeshChatNetwork.node[5] (MeshNode, id=7)
[INFO]	🔁 Node 5 already saw message 3255654 - dropping
** Event #440  t=2  2% completed  (2% total)   MeshChatNetwork.node[1] (MeshNode, id=3)
[INFO]	🔁 Node 1 already saw message 4606746 - dropping
** Event #441  t=2  2% completed  (2% total)   MeshChatNetwork.node[2] (MeshNode, id=4)
[INFO]	🔁 Node 2 already saw message 4606746 - dropping
** Event #442  t=2  2% completed  (2% total)   MeshChatNetwork.node[1] (MeshNode, id=3)
[INFO]	🔁 Node 1 already saw message 4606746 - dropping
** Event #443  t=2  2% completed  (2% total)   MeshChatNetwork.node[2] (MeshNode, id=4)
[INFO]	🔁 Node 2 already saw message 4606746 - dropping
** Event #444  t=2  2% completed  (2% total)   MeshChatNetwork.node[5] (MeshNode, id=7)
[INFO]	🔁 Node 5 already saw message 4606746 - dropping
** Event #445  t=2  2% completed  (2% total)   MeshChatNetwork.node[0] (MeshNode, id=2)
[INFO]	🚨 Node 0 received EMERGENCY message 5924426 from Node 5
[INFO]	📨 Node 0 received broadcast message 5924426 from Node 5: "EMERGENCY from Node 5!"
[INFO]	📤 Node 0 forwarded message 5924426 to 2 neighbors (TTL=7)
** Event #446  t=2  2% completed  (2% total)   MeshChatNetwork.node[3] (MeshNode, id=5)
[INFO]	🔁 Node 3 already saw message 5924426 - dropping
** Event #447  t=2  2% completed  (2% total)   MeshChatNetwork.node[4] (MeshNode, id=6)
[INFO]	🔁 Node 4 already saw message 5924426 - dropping
** Event #448  t=2  2% completed  (2% total)   MeshChatNetwork.node[0] (MeshNode, id=2)
[INFO]	🔁 Node 0 already saw message 5924426 - dropping
** Event #449  t=2  2% completed  (2% total)   MeshChatNetwork.node[3] (MeshNode, id=5)
[INFO]	🔁 Node 3 already saw message 5924426 - dropping
** Event #450  t=2  2% completed  (2% total)   MeshChatNetwork.node[4] (MeshNode, id=6)
[INFO]	🔁 Node 4 already saw message 5924426 - dropping
** Event #451  t=2  2% completed  (2% total)   MeshChatNetwork.node[3] (MeshNode, id=5)
[INFO]	🔁 Node 3 already saw message 370776 - dropping
** Event #452  t=2  2% completed  (2% total)   MeshChatNetwork.node[4] (MeshNode, id=6)
[INFO]	🔁 Node 4 already saw message 370776 - dropping
** Event #453  t=2  2% completed  (2% total)   MeshChatNetwork.node[1] (MeshNode, id=3)
[INFO]	🔁 Node 1 already saw message 5924426 - dropping
** Event #454  t=2  2% completed  (2% total)   MeshChatNetwork.node[2] (MeshNode, id=4)
[INFO]	🔁 Node 2 already saw message 5924426 - dropping
** Event #455  t=3  3% completed  (3% total)   MeshChatNetwork.node[4] (MeshNode, id=6)
[INFO]	💀 Node 4 has FAILED!
** Event #456  t=100  100% completed  (100% total)   

<!> Simulation time limit reached -- at t=100s, event #456

Calling finish() at end of Run #0...
[INFO]	
[INFO]	📊 ========== Node 0 Statistics ==========
[INFO]	   Messages received: 16
[INFO]	   Successful decryptions: 6
[INFO]	   Emergency alerts: 5
[INFO]	   Average latency: 0s
[INFO]	   Min latency: 0s
[INFO]	   Max latency: 0s
[INFO]	   Node failed: NO
[INFO]	================================================
[INFO]	
[INFO]	
[INFO]	📊 ========== Node 1 Statistics ==========
[INFO]	   Messages received: 18
[INFO]	   Successful decryptions: 8
[INFO]	   Emergency alerts: 5
[INFO]	   Average latency: 0s
[INFO]	   Min latency: 0s
[INFO]	   Max latency: 0s
[INFO]	   Node failed: NO
[INFO]	================================================
[INFO]	
[INFO]	
[INFO]	📊 ========== Node 2 Statistics ==========
[INFO]	   Messages received: 10
[INFO]	   Successful decryptions: 0
[INFO]	   Emergency alerts: 5
[INFO]	   Average latency: 0s
[INFO]	   Min latency: 0s
[INFO]	   Max latency: 0s
[INFO]	   Node failed: NO
[INFO]	================================================
[INFO]	
[INFO]	
[INFO]	📊 ========== Node 3 Statistics ==========
[INFO]	   Messages received: 12
[INFO]	   Successful decryptions: 2
[INFO]	   Emergency alerts: 5
[INFO]	   Average latency: 0s
[INFO]	   Min latency: 0s
[INFO]	   Max latency: 0s
[INFO]	   Node failed: NO
[INFO]	================================================
[INFO]	
[INFO]	
[INFO]	📊 ========== Node 4 Statistics ==========
[INFO]	   Messages received: 10
[INFO]	   Successful decryptions: 0
[INFO]	   Emergency alerts: 5
[INFO]	   Average latency: 0s
[INFO]	   Min latency: 0s
[INFO]	   Max latency: 0s
[INFO]	   Node failed: YES
[INFO]	================================================
[INFO]	
[INFO]	
[INFO]	📊 ========== Node 5 Statistics ==========
[INFO]	   Messages received: 10
[INFO]	   Successful decryptions: 0
[INFO]	   Emergency alerts: 5
[INFO]	   Average latency: 0s
[INFO]	   Min latency: 0s
[INFO]	   Max latency: 0s
[INFO]	   Node failed: NO
[INFO]	================================================
[INFO]	

End.
