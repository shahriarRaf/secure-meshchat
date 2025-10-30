package secure_meshchat.simulations;

import secure_meshchat.src.MeshNode;

channel WirelessLink extends ned.DatarateChannel
{
    parameters:
        delay = uniform(1ms, 10ms);
        datarate = 1Mbps;
}

network MeshChatNetwork
{
    parameters:
        int numNodes = default(12);  // CHANGED from 6 to 12
        
    submodules:
        node[numNodes]: MeshNode {
            @display("p=,,ring");  // Arrange in ring
        }
        
    connections allowunconnected:
        // RING TOPOLOGY for 12 nodes
        node[0].gate++ <--> WirelessLink <--> node[1].gate++;
        node[0].gate++ <--> WirelessLink <--> node[2].gate++;
        node[0].gate++ <--> WirelessLink <--> node[11].gate++;
        
        node[1].gate++ <--> WirelessLink <--> node[2].gate++;
        node[1].gate++ <--> WirelessLink <--> node[3].gate++;
        
        node[2].gate++ <--> WirelessLink <--> node[3].gate++;
        node[2].gate++ <--> WirelessLink <--> node[4].gate++;
        
        node[3].gate++ <--> WirelessLink <--> node[4].gate++;
        node[3].gate++ <--> WirelessLink <--> node[5].gate++;
        
        node[4].gate++ <--> WirelessLink <--> node[5].gate++;
        node[4].gate++ <--> WirelessLink <--> node[6].gate++;
        
        node[5].gate++ <--> WirelessLink <--> node[6].gate++;
        node[5].gate++ <--> WirelessLink <--> node[7].gate++;
        
        node[6].gate++ <--> WirelessLink <--> node[7].gate++;
        node[6].gate++ <--> WirelessLink <--> node[8].gate++;
        
        node[7].gate++ <--> WirelessLink <--> node[8].gate++;
        node[7].gate++ <--> WirelessLink <--> node[9].gate++;
        
        node[8].gate++ <--> WirelessLink <--> node[9].gate++;
        node[8].gate++ <--> WirelessLink <--> node[10].gate++;
        
        node[9].gate++ <--> WirelessLink <--> node[10].gate++;
        node[9].gate++ <--> WirelessLink <--> node[11].gate++;
        
        node[10].gate++ <--> WirelessLink <--> node[11].gate++;
        node[10].gate++ <--> WirelessLink <--> node[0].gate++;
        
        // Cross-connections for redundancy
        node[0].gate++ <--> WirelessLink <--> node[6].gate++;
        node[3].gate++ <--> WirelessLink <--> node[9].gate++;
}