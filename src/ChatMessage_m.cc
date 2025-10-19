//
// Generated file, do not edit! Created by opp_msgtool 6.2 from src/ChatMessage.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wshadow"
#  pragma clang diagnostic ignored "-Wconversion"
#  pragma clang diagnostic ignored "-Wunused-parameter"
#  pragma clang diagnostic ignored "-Wc++98-compat"
#  pragma clang diagnostic ignored "-Wunreachable-code-break"
#  pragma clang diagnostic ignored "-Wold-style-cast"
#elif defined(__GNUC__)
#  pragma GCC diagnostic ignored "-Wshadow"
#  pragma GCC diagnostic ignored "-Wconversion"
#  pragma GCC diagnostic ignored "-Wunused-parameter"
#  pragma GCC diagnostic ignored "-Wold-style-cast"
#  pragma GCC diagnostic ignored "-Wsuggest-attribute=noreturn"
#  pragma GCC diagnostic ignored "-Wfloat-conversion"
#endif

#include <iostream>
#include <sstream>
#include <memory>
#include <type_traits>
#include "ChatMessage_m.h"

namespace omnetpp {

// Template pack/unpack rules. They are declared *after* a1l type-specific pack functions for multiple reasons.
// They are in the omnetpp namespace, to allow them to be found by argument-dependent lookup via the cCommBuffer argument

// Packing/unpacking an std::vector
template<typename T, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::vector<T,A>& v)
{
    int n = v.size();
    doParsimPacking(buffer, n);
    for (int i = 0; i < n; i++)
        doParsimPacking(buffer, v[i]);
}

template<typename T, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::vector<T,A>& v)
{
    int n;
    doParsimUnpacking(buffer, n);
    v.resize(n);
    for (int i = 0; i < n; i++)
        doParsimUnpacking(buffer, v[i]);
}

// Packing/unpacking an std::list
template<typename T, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::list<T,A>& l)
{
    doParsimPacking(buffer, (int)l.size());
    for (typename std::list<T,A>::const_iterator it = l.begin(); it != l.end(); ++it)
        doParsimPacking(buffer, (T&)*it);
}

template<typename T, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::list<T,A>& l)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i = 0; i < n; i++) {
        l.push_back(T());
        doParsimUnpacking(buffer, l.back());
    }
}

// Packing/unpacking an std::set
template<typename T, typename Tr, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::set<T,Tr,A>& s)
{
    doParsimPacking(buffer, (int)s.size());
    for (typename std::set<T,Tr,A>::const_iterator it = s.begin(); it != s.end(); ++it)
        doParsimPacking(buffer, *it);
}

template<typename T, typename Tr, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::set<T,Tr,A>& s)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i = 0; i < n; i++) {
        T x;
        doParsimUnpacking(buffer, x);
        s.insert(x);
    }
}

// Packing/unpacking an std::map
template<typename K, typename V, typename Tr, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::map<K,V,Tr,A>& m)
{
    doParsimPacking(buffer, (int)m.size());
    for (typename std::map<K,V,Tr,A>::const_iterator it = m.begin(); it != m.end(); ++it) {
        doParsimPacking(buffer, it->first);
        doParsimPacking(buffer, it->second);
    }
}

template<typename K, typename V, typename Tr, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::map<K,V,Tr,A>& m)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i = 0; i < n; i++) {
        K k; V v;
        doParsimUnpacking(buffer, k);
        doParsimUnpacking(buffer, v);
        m[k] = v;
    }
}

// Default pack/unpack function for arrays
template<typename T>
void doParsimArrayPacking(omnetpp::cCommBuffer *b, const T *t, int n)
{
    for (int i = 0; i < n; i++)
        doParsimPacking(b, t[i]);
}

template<typename T>
void doParsimArrayUnpacking(omnetpp::cCommBuffer *b, T *t, int n)
{
    for (int i = 0; i < n; i++)
        doParsimUnpacking(b, t[i]);
}

// Default rule to prevent compiler from choosing base class' doParsimPacking() function
template<typename T>
void doParsimPacking(omnetpp::cCommBuffer *, const T& t)
{
    throw omnetpp::cRuntimeError("Parsim error: No doParsimPacking() function for type %s", omnetpp::opp_typename(typeid(t)));
}

template<typename T>
void doParsimUnpacking(omnetpp::cCommBuffer *, T& t)
{
    throw omnetpp::cRuntimeError("Parsim error: No doParsimUnpacking() function for type %s", omnetpp::opp_typename(typeid(t)));
}

}  // namespace omnetpp

Register_Class(ChatMessage)

ChatMessage::ChatMessage(const char *name, short kind) : ::omnetpp::cPacket(name, kind)
{
}

ChatMessage::ChatMessage(const ChatMessage& other) : ::omnetpp::cPacket(other)
{
    copy(other);
}

ChatMessage::~ChatMessage()
{
}

ChatMessage& ChatMessage::operator=(const ChatMessage& other)
{
    if (this == &other) return *this;
    ::omnetpp::cPacket::operator=(other);
    copy(other);
    return *this;
}

void ChatMessage::copy(const ChatMessage& other)
{
    this->messageId = other.messageId;
    this->sourceId = other.sourceId;
    this->destinationId = other.destinationId;
    this->timestamp = other.timestamp;
    this->ttl = other.ttl;
    this->senderId = other.senderId;
    this->isKeyExchange_ = other.isKeyExchange_;
    this->isEncrypted_ = other.isEncrypted_;
    this->isEmergency_ = other.isEmergency_;
    this->payload = other.payload;
    this->iv = other.iv;
    this->tag = other.tag;
}

void ChatMessage::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cPacket::parsimPack(b);
    doParsimPacking(b,this->messageId);
    doParsimPacking(b,this->sourceId);
    doParsimPacking(b,this->destinationId);
    doParsimPacking(b,this->timestamp);
    doParsimPacking(b,this->ttl);
    doParsimPacking(b,this->senderId);
    doParsimPacking(b,this->isKeyExchange_);
    doParsimPacking(b,this->isEncrypted_);
    doParsimPacking(b,this->isEmergency_);
    doParsimPacking(b,this->payload);
    doParsimPacking(b,this->iv);
    doParsimPacking(b,this->tag);
}

void ChatMessage::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->messageId);
    doParsimUnpacking(b,this->sourceId);
    doParsimUnpacking(b,this->destinationId);
    doParsimUnpacking(b,this->timestamp);
    doParsimUnpacking(b,this->ttl);
    doParsimUnpacking(b,this->senderId);
    doParsimUnpacking(b,this->isKeyExchange_);
    doParsimUnpacking(b,this->isEncrypted_);
    doParsimUnpacking(b,this->isEmergency_);
    doParsimUnpacking(b,this->payload);
    doParsimUnpacking(b,this->iv);
    doParsimUnpacking(b,this->tag);
}

int ChatMessage::getMessageId() const
{
    return this->messageId;
}

void ChatMessage::setMessageId(int messageId)
{
    this->messageId = messageId;
}

int ChatMessage::getSourceId() const
{
    return this->sourceId;
}

void ChatMessage::setSourceId(int sourceId)
{
    this->sourceId = sourceId;
}

int ChatMessage::getDestinationId() const
{
    return this->destinationId;
}

void ChatMessage::setDestinationId(int destinationId)
{
    this->destinationId = destinationId;
}

double ChatMessage::getTimestamp() const
{
    return this->timestamp;
}

void ChatMessage::setTimestamp(double timestamp)
{
    this->timestamp = timestamp;
}

int ChatMessage::getTtl() const
{
    return this->ttl;
}

void ChatMessage::setTtl(int ttl)
{
    this->ttl = ttl;
}

int ChatMessage::getSenderId() const
{
    return this->senderId;
}

void ChatMessage::setSenderId(int senderId)
{
    this->senderId = senderId;
}

bool ChatMessage::isKeyExchange() const
{
    return this->isKeyExchange_;
}

void ChatMessage::setIsKeyExchange(bool isKeyExchange)
{
    this->isKeyExchange_ = isKeyExchange;
}

bool ChatMessage::isEncrypted() const
{
    return this->isEncrypted_;
}

void ChatMessage::setIsEncrypted(bool isEncrypted)
{
    this->isEncrypted_ = isEncrypted;
}

bool ChatMessage::isEmergency() const
{
    return this->isEmergency_;
}

void ChatMessage::setIsEmergency(bool isEmergency)
{
    this->isEmergency_ = isEmergency;
}

const char * ChatMessage::getPayload() const
{
    return this->payload.c_str();
}

void ChatMessage::setPayload(const char * payload)
{
    this->payload = payload;
}

const char * ChatMessage::getIv() const
{
    return this->iv.c_str();
}

void ChatMessage::setIv(const char * iv)
{
    this->iv = iv;
}

const char * ChatMessage::getTag() const
{
    return this->tag.c_str();
}

void ChatMessage::setTag(const char * tag)
{
    this->tag = tag;
}

class ChatMessageDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertyNames;
    enum FieldConstants {
        FIELD_messageId,
        FIELD_sourceId,
        FIELD_destinationId,
        FIELD_timestamp,
        FIELD_ttl,
        FIELD_senderId,
        FIELD_isKeyExchange,
        FIELD_isEncrypted,
        FIELD_isEmergency,
        FIELD_payload,
        FIELD_iv,
        FIELD_tag,
    };
  public:
    ChatMessageDescriptor();
    virtual ~ChatMessageDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyName) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyName) const override;
    virtual int getFieldArraySize(omnetpp::any_ptr object, int field) const override;
    virtual void setFieldArraySize(omnetpp::any_ptr object, int field, int size) const override;

    virtual const char *getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const override;
    virtual std::string getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const override;
    virtual omnetpp::cValue getFieldValue(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual omnetpp::any_ptr getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const override;
    virtual void setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const override;
};

Register_ClassDescriptor(ChatMessageDescriptor)

ChatMessageDescriptor::ChatMessageDescriptor() : omnetpp::cClassDescriptor(omnetpp::opp_typename(typeid(ChatMessage)), "omnetpp::cPacket")
{
    propertyNames = nullptr;
}

ChatMessageDescriptor::~ChatMessageDescriptor()
{
    delete[] propertyNames;
}

bool ChatMessageDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<ChatMessage *>(obj)!=nullptr;
}

const char **ChatMessageDescriptor::getPropertyNames() const
{
    if (!propertyNames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
        const char **baseNames = base ? base->getPropertyNames() : nullptr;
        propertyNames = mergeLists(baseNames, names);
    }
    return propertyNames;
}

const char *ChatMessageDescriptor::getProperty(const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? base->getProperty(propertyName) : nullptr;
}

int ChatMessageDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    return base ? 12+base->getFieldCount() : 12;
}

unsigned int ChatMessageDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeFlags(field);
        field -= base->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,    // FIELD_messageId
        FD_ISEDITABLE,    // FIELD_sourceId
        FD_ISEDITABLE,    // FIELD_destinationId
        FD_ISEDITABLE,    // FIELD_timestamp
        FD_ISEDITABLE,    // FIELD_ttl
        FD_ISEDITABLE,    // FIELD_senderId
        FD_ISEDITABLE,    // FIELD_isKeyExchange
        FD_ISEDITABLE,    // FIELD_isEncrypted
        FD_ISEDITABLE,    // FIELD_isEmergency
        FD_ISEDITABLE,    // FIELD_payload
        FD_ISEDITABLE,    // FIELD_iv
        FD_ISEDITABLE,    // FIELD_tag
    };
    return (field >= 0 && field < 12) ? fieldTypeFlags[field] : 0;
}

const char *ChatMessageDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldName(field);
        field -= base->getFieldCount();
    }
    static const char *fieldNames[] = {
        "messageId",
        "sourceId",
        "destinationId",
        "timestamp",
        "ttl",
        "senderId",
        "isKeyExchange",
        "isEncrypted",
        "isEmergency",
        "payload",
        "iv",
        "tag",
    };
    return (field >= 0 && field < 12) ? fieldNames[field] : nullptr;
}

int ChatMessageDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    int baseIndex = base ? base->getFieldCount() : 0;
    if (strcmp(fieldName, "messageId") == 0) return baseIndex + 0;
    if (strcmp(fieldName, "sourceId") == 0) return baseIndex + 1;
    if (strcmp(fieldName, "destinationId") == 0) return baseIndex + 2;
    if (strcmp(fieldName, "timestamp") == 0) return baseIndex + 3;
    if (strcmp(fieldName, "ttl") == 0) return baseIndex + 4;
    if (strcmp(fieldName, "senderId") == 0) return baseIndex + 5;
    if (strcmp(fieldName, "isKeyExchange") == 0) return baseIndex + 6;
    if (strcmp(fieldName, "isEncrypted") == 0) return baseIndex + 7;
    if (strcmp(fieldName, "isEmergency") == 0) return baseIndex + 8;
    if (strcmp(fieldName, "payload") == 0) return baseIndex + 9;
    if (strcmp(fieldName, "iv") == 0) return baseIndex + 10;
    if (strcmp(fieldName, "tag") == 0) return baseIndex + 11;
    return base ? base->findField(fieldName) : -1;
}

const char *ChatMessageDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldTypeString(field);
        field -= base->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "int",    // FIELD_messageId
        "int",    // FIELD_sourceId
        "int",    // FIELD_destinationId
        "double",    // FIELD_timestamp
        "int",    // FIELD_ttl
        "int",    // FIELD_senderId
        "bool",    // FIELD_isKeyExchange
        "bool",    // FIELD_isEncrypted
        "bool",    // FIELD_isEmergency
        "string",    // FIELD_payload
        "string",    // FIELD_iv
        "string",    // FIELD_tag
    };
    return (field >= 0 && field < 12) ? fieldTypeStrings[field] : nullptr;
}

const char **ChatMessageDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldPropertyNames(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *ChatMessageDescriptor::getFieldProperty(int field, const char *propertyName) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldProperty(field, propertyName);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int ChatMessageDescriptor::getFieldArraySize(omnetpp::any_ptr object, int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldArraySize(object, field);
        field -= base->getFieldCount();
    }
    ChatMessage *pp = omnetpp::fromAnyPtr<ChatMessage>(object); (void)pp;
    switch (field) {
        default: return 0;
    }
}

void ChatMessageDescriptor::setFieldArraySize(omnetpp::any_ptr object, int field, int size) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldArraySize(object, field, size);
            return;
        }
        field -= base->getFieldCount();
    }
    ChatMessage *pp = omnetpp::fromAnyPtr<ChatMessage>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set array size of field %d of class 'ChatMessage'", field);
    }
}

const char *ChatMessageDescriptor::getFieldDynamicTypeString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldDynamicTypeString(object,field,i);
        field -= base->getFieldCount();
    }
    ChatMessage *pp = omnetpp::fromAnyPtr<ChatMessage>(object); (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string ChatMessageDescriptor::getFieldValueAsString(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValueAsString(object,field,i);
        field -= base->getFieldCount();
    }
    ChatMessage *pp = omnetpp::fromAnyPtr<ChatMessage>(object); (void)pp;
    switch (field) {
        case FIELD_messageId: return long2string(pp->getMessageId());
        case FIELD_sourceId: return long2string(pp->getSourceId());
        case FIELD_destinationId: return long2string(pp->getDestinationId());
        case FIELD_timestamp: return double2string(pp->getTimestamp());
        case FIELD_ttl: return long2string(pp->getTtl());
        case FIELD_senderId: return long2string(pp->getSenderId());
        case FIELD_isKeyExchange: return bool2string(pp->isKeyExchange());
        case FIELD_isEncrypted: return bool2string(pp->isEncrypted());
        case FIELD_isEmergency: return bool2string(pp->isEmergency());
        case FIELD_payload: return oppstring2string(pp->getPayload());
        case FIELD_iv: return oppstring2string(pp->getIv());
        case FIELD_tag: return oppstring2string(pp->getTag());
        default: return "";
    }
}

void ChatMessageDescriptor::setFieldValueAsString(omnetpp::any_ptr object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValueAsString(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    ChatMessage *pp = omnetpp::fromAnyPtr<ChatMessage>(object); (void)pp;
    switch (field) {
        case FIELD_messageId: pp->setMessageId(string2long(value)); break;
        case FIELD_sourceId: pp->setSourceId(string2long(value)); break;
        case FIELD_destinationId: pp->setDestinationId(string2long(value)); break;
        case FIELD_timestamp: pp->setTimestamp(string2double(value)); break;
        case FIELD_ttl: pp->setTtl(string2long(value)); break;
        case FIELD_senderId: pp->setSenderId(string2long(value)); break;
        case FIELD_isKeyExchange: pp->setIsKeyExchange(string2bool(value)); break;
        case FIELD_isEncrypted: pp->setIsEncrypted(string2bool(value)); break;
        case FIELD_isEmergency: pp->setIsEmergency(string2bool(value)); break;
        case FIELD_payload: pp->setPayload((value)); break;
        case FIELD_iv: pp->setIv((value)); break;
        case FIELD_tag: pp->setTag((value)); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'ChatMessage'", field);
    }
}

omnetpp::cValue ChatMessageDescriptor::getFieldValue(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldValue(object,field,i);
        field -= base->getFieldCount();
    }
    ChatMessage *pp = omnetpp::fromAnyPtr<ChatMessage>(object); (void)pp;
    switch (field) {
        case FIELD_messageId: return pp->getMessageId();
        case FIELD_sourceId: return pp->getSourceId();
        case FIELD_destinationId: return pp->getDestinationId();
        case FIELD_timestamp: return pp->getTimestamp();
        case FIELD_ttl: return pp->getTtl();
        case FIELD_senderId: return pp->getSenderId();
        case FIELD_isKeyExchange: return pp->isKeyExchange();
        case FIELD_isEncrypted: return pp->isEncrypted();
        case FIELD_isEmergency: return pp->isEmergency();
        case FIELD_payload: return pp->getPayload();
        case FIELD_iv: return pp->getIv();
        case FIELD_tag: return pp->getTag();
        default: throw omnetpp::cRuntimeError("Cannot return field %d of class 'ChatMessage' as cValue -- field index out of range?", field);
    }
}

void ChatMessageDescriptor::setFieldValue(omnetpp::any_ptr object, int field, int i, const omnetpp::cValue& value) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldValue(object, field, i, value);
            return;
        }
        field -= base->getFieldCount();
    }
    ChatMessage *pp = omnetpp::fromAnyPtr<ChatMessage>(object); (void)pp;
    switch (field) {
        case FIELD_messageId: pp->setMessageId(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_sourceId: pp->setSourceId(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_destinationId: pp->setDestinationId(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_timestamp: pp->setTimestamp(value.doubleValue()); break;
        case FIELD_ttl: pp->setTtl(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_senderId: pp->setSenderId(omnetpp::checked_int_cast<int>(value.intValue())); break;
        case FIELD_isKeyExchange: pp->setIsKeyExchange(value.boolValue()); break;
        case FIELD_isEncrypted: pp->setIsEncrypted(value.boolValue()); break;
        case FIELD_isEmergency: pp->setIsEmergency(value.boolValue()); break;
        case FIELD_payload: pp->setPayload(value.stringValue()); break;
        case FIELD_iv: pp->setIv(value.stringValue()); break;
        case FIELD_tag: pp->setTag(value.stringValue()); break;
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'ChatMessage'", field);
    }
}

const char *ChatMessageDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructName(field);
        field -= base->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    };
}

omnetpp::any_ptr ChatMessageDescriptor::getFieldStructValuePointer(omnetpp::any_ptr object, int field, int i) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount())
            return base->getFieldStructValuePointer(object, field, i);
        field -= base->getFieldCount();
    }
    ChatMessage *pp = omnetpp::fromAnyPtr<ChatMessage>(object); (void)pp;
    switch (field) {
        default: return omnetpp::any_ptr(nullptr);
    }
}

void ChatMessageDescriptor::setFieldStructValuePointer(omnetpp::any_ptr object, int field, int i, omnetpp::any_ptr ptr) const
{
    omnetpp::cClassDescriptor *base = getBaseClassDescriptor();
    if (base) {
        if (field < base->getFieldCount()){
            base->setFieldStructValuePointer(object, field, i, ptr);
            return;
        }
        field -= base->getFieldCount();
    }
    ChatMessage *pp = omnetpp::fromAnyPtr<ChatMessage>(object); (void)pp;
    switch (field) {
        default: throw omnetpp::cRuntimeError("Cannot set field %d of class 'ChatMessage'", field);
    }
}

namespace omnetpp {

}  // namespace omnetpp

