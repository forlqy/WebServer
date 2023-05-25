#ifndef __SYLAR_ADDRESS_H__
#define __SYLAR_ADDRESS_H__

#include <memory>
#include <string>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/un.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <iostream>
#include <vector>
#include <map>


namespace sylar{

class IPAddress;
class Address{
public:
    using ptr = std::shared_ptr<Address>;

    static Address::ptr Create(const sockaddr* addr, socklen_t addrlen);
    static bool Lookup(std::vector<Address::ptr>& result, const std::string& host,
            int family = AF_UNSPEC, int type = 0, int protocol = 0);
    static Address::ptr LookupAny(const std::string& host,
            int family = AF_UNSPEC, int type = 0, int protocol = 0);
    static std::shared_ptr<IPAddress> LookupAnyIPAddress(const std::string& host,
            int family = AF_UNSPEC, int type = 0, int protocol = 0); 

    static bool GetInterfaceAddresses(std::multimap<std::string
                    ,std::pair<Address::ptr, uint32_t> >& result,
                    int family = AF_UNSPEC);
    static bool GetInterfaceAddresses(std::vector<std::pair<Address::ptr, uint32_t> >&result
                    ,const std::string& iface, int family = AF_UNSPEC);

    virtual ~Address(){}

    int getFamily() const;

    virtual const sockaddr* getAddr() const = 0;
    virtual sockaddr* getAddr() = 0;
    virtual socklen_t getAddrLen() const = 0;

    virtual std::ostream& insert(std::ostream& os) const = 0;
    std::string toString() const;

    bool operator< (const Address& rhs) const;
    bool operator== (const Address& rhs) const;
    bool operator!= (const Address& rhs) const;
};

class IPAddress : public Address{
public:
    using ptr = std::shared_ptr<IPAddress>;

    static IPAddress::ptr Create(const char* address, uint16_t port = 0);

    virtual IPAddress::ptr broadcastAddress(uint32_t prefix_len) = 0; //通过IP地址找到广播地址
    virtual IPAddress::ptr networdAddress(uint32_t prefix_len) = 0; //网络地址
    virtual IPAddress::ptr subnetMask(uint32_t prefix_len) = 0; //子网掩码

    virtual uint32_t getPort() const = 0;
    virtual void setPort(uint16_t v) = 0;
};

class IPv4Address : public IPAddress{
public:
    using ptr = std::shared_ptr<IPv4Address>;

    static IPv4Address::ptr Create(const char* address, uint16_t port = 0);

    IPv4Address(const sockaddr_in& address);
    IPv4Address(uint32_t address = INADDR_ANY, uint16_t port = 0);

    const sockaddr* getAddr() const override;
    sockaddr* getAddr() override;
    socklen_t getAddrLen() const;
    std::ostream& insert(std::ostream& os) const override;

    IPAddress::ptr broadcastAddress(uint32_t prefix_len) override; //通过IP地址找到广播地址
    IPAddress::ptr networdAddress(uint32_t prefix_len) override; //网络地址
    IPAddress::ptr subnetMask(uint32_t prefix_len) override; //子网掩码
    uint32_t getPort() const override;
    void setPort(uint16_t v) override;
private:
    sockaddr_in m_addr;
};

class IPv6Address : public IPAddress{
public:
    using ptr = std::shared_ptr<IPv6Address>;
    IPv6Address();
    IPv6Address(const sockaddr_in6& address);
    IPv6Address(const uint8_t address[16], uint16_t port = 0);

    static IPv6Address::ptr Create(const char* address, uint16_t port = 0); //转为明文IP

    const sockaddr* getAddr() const override;
    sockaddr* getAddr() override;
    socklen_t getAddrLen() const;
    std::ostream& insert(std::ostream& os) const override;

    IPAddress::ptr broadcastAddress(uint32_t prefix_len) override; //通过IP地址找到广播地址
    IPAddress::ptr networdAddress(uint32_t prefix_len) override; //网络地址
    IPAddress::ptr subnetMask(uint32_t prefix_len) override; //子网掩码
    uint32_t getPort() const override;
    void setPort(uint16_t v) override;
private:
    sockaddr_in6 m_addr;
};

class UnixAddress : public Address{
public:
    using ptr = std::shared_ptr<UnixAddress>;
    UnixAddress();
    UnixAddress(const std::string& path);

    const sockaddr* getAddr() const override;
    sockaddr* getAddr() override;
    socklen_t getAddrLen() const;
    void setAddrLen(uint32_t v);
    std::ostream& insert(std::ostream& os) const override;
private:
    sockaddr_un m_addr;
    socklen_t m_length;
};

class UnknowAddress : public Address{
public:
    using ptr = std::shared_ptr<UnknowAddress>;
    UnknowAddress(int family);
    UnknowAddress(const sockaddr& addr);
    const sockaddr* getAddr() const override;
    sockaddr* getAddr() override;
    socklen_t getAddrLen() const;
    std::ostream& insert(std::ostream& os) const override;
private:
    sockaddr m_addr;
};

std::ostream& operator<< (std::ostream& os, const Address& addr);


}


#endif
