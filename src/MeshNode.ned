package secure_meshchat.src;

simple MeshNode
{
    parameters:
        double messageSendInterval @unit(s) = default(5s);
        int initialTTL = default(3);
    gates:
        inout gate[];
}