package secure_meshchat.src;

simple MeshChatApp
{
    parameters:
        double sendMessageAt @unit(s) = default(-1s);
        int destinationNode = default(-1);
        string messageText = default("");
        
    gates:
        input in;
        output out;
}