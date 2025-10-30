package secure_meshchat.src;

simple MeshNode
{
    parameters:
        int initialTTL = default(5);
        double packetLossRate = default(0.0);
        int maxMessages = default(10);
        
        // ✅ ADD THESE MOBILITY PARAMETERS:
        bool enableMobility = default(false);
        double mobilityUpdateInterval @unit(s) = default(1s);
        double mobilitySpeed @unit(mps) = default(5mps);
        double areaWidth @unit(m) = default(1000m);
        double areaHeight @unit(m) = default(1000m);
        
        @display("i=block/routing");
        
    gates:
        inout gate[];
}