#ifndef ADDRESSIP_HPP
#define ADDRESSIP_HPP

#include <string>
#include <vector>

class AddressIP
{
private:
    std::string address;
    std::vector<std::string> vectorAddressIP;

    int maskLength;
    std::vector<std::string> mask;

    std::vector<uint8_t> addressIPBytes;
    std::vector<uint8_t> maskBytes;

    std::vector<std::string> networkAddress;
    std::vector<std::string> broadcastAddress;

    std::vector<std::string> minHost;
    std::vector<std::string> maxHost;

    unsigned long numberOfHosts;

public:
    AddressIP(std::string addressIP);
    ~AddressIP();

    void showAddressIP();

    std::vector<std::string> getAddressIP();
    void setAddressIP(std::vector<std::string> vectorAddressIP);

    bool checkIfAddressIPExist();

    bool checkNumber(const std::string &str);
    bool checkString(const std::string &str);
    bool checkMask(const std::string &str);

    std::vector<std::string> splitString(const std::string &str, const char *delimiter);
    std::vector<std::string> validateAddressIP(const std::string &str);

    int getMaskLength();
    void setMaskLength(int maskLength);

    void removeMaskFromAddressIP();

    std::vector<std::string> getMask();
    void setMask(std::vector<std::string> mask);

    std::vector<std::string> convertMask(int prefix);

    std::vector<uint8_t> getAddressIPBytes();
    void setAddressIPBytes(std::vector<uint8_t> addressIPBytes);

    std::vector<uint8_t> getMaskBytes();
    void setMaskBytes(std::vector<uint8_t> maskBytes);

    std::vector<uint8_t> convertToBytes(std::vector<std::string> myStringVector);

    std::vector<std::string> getNetworkAddress();
    void setNetworkAddress(std::vector<std::string> networkAddress);

    std::vector<std::string> getBroadcastAddress();
    void setBroadcastAddress(std::vector<std::string> broadcastAddress);

    std::vector<std::string> calculateNetworkAddress(std::vector<uint8_t> addressIP, std::vector<uint8_t> mask);
    std::vector<std::string> calculateBroadcastAddress(std::vector<uint8_t> addressIP, std::vector<uint8_t> mask);

    std::vector<std::string> getMinHost();
    void setMinHost(std::vector<std::string> minHost);

    std::vector<std::string> getMaxHost();
    void setMaxHost(std::vector<std::string> maxHost);

    std::vector<std::string> calculateMinHost(std::vector<std::string> networkAddress);
    std::vector<std::string> calculateMaxHost(std::vector<std::string> broadcastAddress);

    int getNumberOfHosts();
    void setNumberOfHosts(int numberOfHosts);

    unsigned long calculateNumberOfHosts(int mask);

    void showInfo();

    void showNetworkAddress();
    void showMask();

    void showMinHost();
    void showMaxHost();
    
    void showHostRange();
    void showNumberOfHosts();

    void showBroadcastAddress();
};

#endif // ADDRESSIP_HPP