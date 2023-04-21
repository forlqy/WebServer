#include "bytearray.h"

namespace sylar{

Node::Node(size_t s) : ptr(new char[s]), size(s), next(nullptr) {
}

Node::Node() : ptr(nullptr), size(0), next(nullptr) {
}

Node::~Node(){
    if(ptr){
        delete[] ptr;
    }
}

ByteArray::ByteArray(size_t base_size) : m_baseSize(base_size), m_position(0), m_capacity(base_size), m_size(0), m_root(new Node(base_size)), m_cur(m_root) {
}

ByteArray::~ByteArray(){
    Node* tmp = m_root;
    while(tmp){
        m_cur = tmp;
        tmp = tmp->next;
        delete m_cur;
    }
}

bool ByteArray::isLittleEndian() const{

}

void ByteArray::setIsLittleEndian(bool val){

}

void ByteArray::writeFint8(const int8_t& value){
    write(&value, sizeof(value));
}

void ByteArray::writeFuint8(const uint8_t& value){
    write(&value, sizeof(value));
}

void writeFint16(const int16_t& value){
    write(&value, sizeof(value));
}

void writeFuint16(const uint16_t& value){
    write(&value, sizeof(value));
}

void writeFint32(const int32_t& value){
    write(&value, sizeof(value));
}

void writeFuint32(const uint32_t& value){
    write(&value, sizeof(value));
}

void writeFint64(const int64_t& value){
    write(&value, sizeof(value));
}

void writeFuint64(const uint64_t& value){
    write(&value, sizeof(value));
}

void writeInt32(const int32_t& value);
void writeUint32(const uint32_t& value);
void writeInt64(const int64_t& value);
void writeUint64(const uint64_t& value);
void writeFloat(const float& value);
void writeDouble(const double& value);
void writeStringF16(const std::string& value);
void writeStringF32(const std::string& value);
void writeStringF64(const std::string& value);
void writeStringVint(const std::string& value);
void writeStringWithoutLength(const std::string& value);
int8_t readFint8();
uint8_t readFuint8();
int16_t readFint16();
uint16_t readFuint16();
int32_t readFint32();
uint32_t readFuint32();
int64_t readFint64();
uint64_t readFuint64();
int32_t readInt32();
uint32_t readUint32();
int64_t readInt64();
uint64_t readUint64();
float readFloat();
double readDouble();
std::string readStringF16();
std::string readStringF32();
std::string readStringF64();
std::string readStringVint();
void clear();
void write(const void* buf size_t size);
void read(char* buf, size_t size);
void setPosition(size_t v);
bool writeToFile(const std::string& name) const;
void readFromFile(const std::string& name);
void addCapacity(size_t size);


}