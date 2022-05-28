#include "addressip.hpp"
#include <iostream>
#include <cstring>
#include <cmath>

#define SLASH_COUNT 1
#define DOT_COUNT 3

AddressIP::AddressIP(std::string address)
{
    this->address = address;
}

AddressIP::~AddressIP() {}

void AddressIP::showAddressIP()
{
    for(std::string val : vectorAddressIP)
        std::cout << val << std::endl;
}

std::vector<std::string> AddressIP::getAddressIP()
{
    return vectorAddressIP;
}

void AddressIP::setAddressIP(std::vector<std::string> vectorAddressIP)
{
    this->vectorAddressIP = vectorAddressIP;
}

bool AddressIP::checkIfAddressIPExist()
{
    if (vectorAddressIP.empty())
        return std::cout << "Adres IPv4 jest nieprawidlowy! " << std::endl, false;
    return true;
}

// true == 1
// false == 0

bool AddressIP::checkNumber(const std::string &str)
{
    if (str.empty())
        return false;

    std::string regex = "0123456789";
    if (str.find_first_not_of(regex) != str.npos)
        return false;

    if (stoi(str) < 0 || stoi(str) > 255)
        return false;

    return true;
}

bool AddressIP::checkString(const std::string &str)
{
    if (str.empty())
        return false;

    std::string regex = "0123456789./";
    if (str.find_first_not_of(regex) != str.npos)
        return false;

    if (str[0] == '.' || str[0] == '/' || str.length() - 1 == '.' || str.length() - 1 == '/')
        return false;

    int dotCount = 0;
    int slashCount = 0;
    bool valid = true;

    for (size_t i = 0; i < str.length(); i++)
    {
        if (str[i] == '.')
        {
            dotCount++;
            valid = false;
        }
        if (str[i] == '/')
        {
            slashCount++;
            valid = true;
        }
    }

    if (dotCount != DOT_COUNT || slashCount != SLASH_COUNT)
        return false;

    if (valid == false)
        return false;

    return true;
}

bool AddressIP::checkMask(const std::string &str)
{
    if (stoi(str) < 0 || stoi(str) > 32)
        return false;
    return true;
}

// strpbrk/strtok

std::vector<std::string> AddressIP::splitString(const std::string &str, const char *delimiter)
{
    std::vector<std::string> addressIP;

    char *cstr = new char[str.length() + 1];
    strcpy(cstr, str.c_str());

    char *pch = strtok(cstr, delimiter);

    while (pch != NULL)
    {
        addressIP.push_back(pch);
        pch = strtok(NULL, delimiter);
    }

    delete[] cstr;

    return addressIP;
}

std::vector<std::string> AddressIP::validateAddressIP(const std::string &str)
{
    if (!checkString(str))
        return std::vector<std::string>();

    std::vector<std::string> addressIP = splitString(str, "./");

    if (addressIP.size() != 5)
        return std::vector<std::string>();

    for (int i = 0; i < 4; i++)
    {
        if (!checkNumber(addressIP[i]))
            return std::vector<std::string>();
    }

    if (!checkMask(addressIP[4]))
        return std::vector<std::string>();

    return addressIP;
}

int AddressIP::getMaskLength()
{
    return maskLength;
}

void AddressIP::setMaskLength(int maskLength)
{
    this->maskLength = maskLength;
}

void AddressIP::removeMaskFromAddressIP()
{
    vectorAddressIP.pop_back();
}

std::vector<std::string> AddressIP::getMask()
{
    return mask;
}

void AddressIP::setMask(std::vector<std::string> mask)
{
    this->mask = mask;
}

std::vector<std::string> AddressIP::convertMask(int prefix)
{
    std::vector<std::string> subnet;
    unsigned long mask = (0xFFFFFFFF << (32 - prefix)) & 0xFFFFFFFF;

    subnet.push_back(std::to_string(mask >> 24));
    subnet.push_back(std::to_string((mask >> 16) & 0xFF));
    subnet.push_back(std::to_string((mask >> 8) & 0xFF));
    subnet.push_back(std::to_string(mask & 0xFF));

    return subnet;
}

std::vector<uint8_t> AddressIP::getAddressIPBytes()
{
    return addressIPBytes;
}

void AddressIP::setAddressIPBytes(std::vector<uint8_t> addressIPBytes)
{
    this->addressIPBytes = addressIPBytes;
}

std::vector<uint8_t> AddressIP::getMaskBytes()
{
    return maskBytes;
}

void AddressIP::setMaskBytes(std::vector<uint8_t> maskBytes)
{
    this->maskBytes = maskBytes;
}

std::vector<uint8_t> AddressIP::convertToBytes(std::vector<std::string> myStringVector)
{
    std::vector<uint8_t> bytes;
    for (size_t i = 0; i < myStringVector.size(); i++)
    {
        uint8_t val = atoi(myStringVector[i].c_str());
        bytes.push_back(val);
    }
    return bytes;
}

std::vector<std::string> AddressIP::getNetworkAddress()
{
    return networkAddress;
}

void AddressIP::setNetworkAddress(std::vector<std::string> networkAddress)
{
    this->networkAddress = networkAddress;
}

std::vector<std::string> AddressIP::getBroadcastAddress()
{
    return broadcastAddress;
}

void AddressIP::setBroadcastAddress(std::vector<std::string> broadcastAddress)
{
    this->broadcastAddress = broadcastAddress;
}

std::vector<std::string> AddressIP::calculateNetworkAddress(std::vector<uint8_t> addressIP, std::vector<uint8_t> mask)
{
    std::vector<std::string> networkAddress;
    for (int i = 0; i < 4; i++)
        networkAddress.push_back(std::to_string(addressIP[i] & mask[i]));
    return networkAddress;
}

std::vector<std::string> AddressIP::calculateBroadcastAddress(std::vector<uint8_t> addressIP, std::vector<uint8_t> mask)
{
    std::vector<std::string> broadcastAddress;
    for (int i = 0; i < 4; i++)
        broadcastAddress.push_back(std::to_string(static_cast<uint8_t>(addressIP[i] | ~(mask[i]))));
    return broadcastAddress;
}

std::vector<std::string> AddressIP::getMinHost()
{
    return minHost;
}

void AddressIP::setMinHost(std::vector<std::string> minHost)
{
    this->minHost = minHost;
}

std::vector<std::string> AddressIP::getMaxHost()
{
    return maxHost;
}

void AddressIP::setMaxHost(std::vector<std::string> maxHost)
{
    this->maxHost = maxHost;
}

std::vector<std::string> AddressIP::calculateMinHost(std::vector<std::string> networkAddress)
{
    std::vector<std::string> minHost;
    for (int i = 0; i < 4; i++)
    {
        if (i != 3)
            minHost.push_back(networkAddress[i]);
        else
            minHost.push_back(std::to_string(std::stoi(networkAddress[i]) + 1));
    }
    return minHost;
}

std::vector<std::string> AddressIP::calculateMaxHost(std::vector<std::string> broadcastAddress)
{
    std::vector<std::string> maxHost;
    for (int i = 0; i < 4; i++)
    {
        if (i != 3)
            maxHost.push_back(broadcastAddress[i]);
        else
            maxHost.push_back(std::to_string(std::stoi(broadcastAddress[i]) - 1));
    }
    return maxHost;
}

int AddressIP::getNumberOfHosts()
{
    return numberOfHosts;
}

void AddressIP::setNumberOfHosts(int numberOfHosts)
{
    this->numberOfHosts = numberOfHosts;
}

unsigned long AddressIP::calculateNumberOfHosts(int mask)
{
    return pow(2, (32 - mask)) - 2;
}

void AddressIP::showInfo()
{
    std::cout << "Wynik:" << std::endl;
    showNetworkAddress();
    showMask();
    if (maskLength < 32)
    {
        showMinHost();
        showMaxHost();
        showHostRange();
        showNumberOfHosts();
        showBroadcastAddress();
    }
    if (maskLength == 32)
        std::cout << "To jest pojedynczy host, nie siec!" << std::endl;
}

void AddressIP::showNetworkAddress()
{
    std::cout << "1) Adres sieci: " << networkAddress[0] << '.' << networkAddress[1] << '.' << networkAddress[2] << '.' << networkAddress[3] << '/' << maskLength << std::endl;
}

void AddressIP::showMask()
{
    std::cout << "Maska: " << mask[0] << '.' << mask[1] << '.' << mask[2] << '.' << mask[3] << std::endl;
}

void AddressIP::showMinHost()
{
    std::cout << "Host min = " << minHost[0] << '.' << minHost[1] << '.' << minHost[2] << '.' << minHost[3] << std::endl;
}

void AddressIP::showMaxHost()
{
    std::cout << "Host max = " << maxHost[0] << '.' << maxHost[1] << '.' << maxHost[2] << '.' << maxHost[3] << std::endl;
}

void AddressIP::showHostRange()
{
    std::cout << "2) Zakres hostow = " << minHost[0] << '.' << minHost[1] << '.' << minHost[2] << '.' << minHost[3] << " - " << maxHost[0] << '.' << maxHost[1] << '.' << maxHost[2] << '.' << maxHost[3] << std::endl;
}

void AddressIP::showNumberOfHosts()
{
    std::cout << "3) Ilosc hostow = " << numberOfHosts << std::endl;
}

void AddressIP::showBroadcastAddress()
{
    std::cout << "4) Adres broadcast: " << broadcastAddress[0] << '.' << broadcastAddress[1] << '.' << broadcastAddress[2] << '.' << broadcastAddress[3] << std::endl;
}