#include <iostream>
#include "addressip.hpp"
#include <string>

#define EXISTS 1
#define NOT_EXIST 0

#define SUCCESS 0
#define FAIL 1

int main()
{
	while (1)
	{
		std::string address;
		std::cout << "Podaj adres IPv4: ";
		// 192.168.0.1/24
		getline(std::cin, address);

		AddressIP addressIP = AddressIP(address);

		addressIP.setAddressIP(addressIP.validateAddressIP(address));
		if (addressIP.checkIfAddressIPExist() == NOT_EXIST)
			return FAIL;

		// addressIP.showAddressIP();

		addressIP.setMaskLength(std::stoi(addressIP.getAddressIP()[4]));
		addressIP.removeMaskFromAddressIP();

		addressIP.setMask(addressIP.convertMask(addressIP.getMaskLength()));

		// addressIP.showMask();

		addressIP.setAddressIPBytes(addressIP.convertToBytes(addressIP.getAddressIP()));
		addressIP.setMaskBytes(addressIP.convertToBytes(addressIP.getMask()));

		addressIP.setNetworkAddress(addressIP.calculateNetworkAddress(addressIP.getAddressIPBytes(), addressIP.getMaskBytes()));
		addressIP.setBroadcastAddress(addressIP.calculateBroadcastAddress(addressIP.getAddressIPBytes(), addressIP.getMaskBytes()));

		addressIP.setMinHost(addressIP.calculateMinHost(addressIP.getNetworkAddress()));
		addressIP.setMaxHost(addressIP.calculateMaxHost(addressIP.getBroadcastAddress()));

		addressIP.setNumberOfHosts(addressIP.calculateNumberOfHosts(addressIP.getMaskLength()));

		// addressIP.showAddressIP();

		addressIP.showInfo();

		std::string option;
		std::cout << std::endl << "Wybierz opcje:" << std::endl << "1) [e] - exit" << std::endl << "2) [enter] - kolejny adres" << std::endl;
		std::cout << "Opcja: " << std::endl;
		getline(std::cin, option);

		if (option.empty())
			continue;

		if (option.compare("e") == 0)
			return SUCCESS;
	}

	return SUCCESS;
}