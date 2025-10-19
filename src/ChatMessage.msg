packet ChatMessage {
    int    messageId;
    int    sourceId;
    int    destinationId;
    double timestamp;
    int    ttl;
    int    senderId;
    bool   isKeyExchange;
    bool   isEncrypted;
    bool   isEmergency;
    string payload;
    string iv;
    string tag;
}