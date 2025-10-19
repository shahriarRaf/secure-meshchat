package secure_meshchat.simulations;

import secure_meshchat.src.MeshNode;

network MeshChatNetwork
{
    parameters:
        int numNodes = default(6);
    submodules:
        node[numNodes]: MeshNode;
    connections allowunconnected:
        node[0].gate++ <--> node[1].gate++;
        node[0].gate++ <--> node[2].gate++;
        node[1].gate++ <--> node[3].gate++;
        node[1].gate++ <--> node[4].gate++;
        node[2].gate++ <--> node[3].gate++;
        node[2].gate++ <--> node[4].gate++;
        node[3].gate++ <--> node[5].gate++;
        node[4].gate++ <--> node[5].gate++;
}