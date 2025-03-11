#include "CHttpUrl.h"
#include <iostream>

int main()
{
	std::string input;
	while (std::getline(std::cin, input))
	{
		try
		{
			CHttpUrl url(input);
			std::cout << "Parsed URL: " << url.GetURL() << "\n";
			std::cout << "Domain: " << url.GetDomain() << "\n";
			std::cout << "Document: " << url.GetDocument() << "\n";
			std::cout << "Protocol: " << (url.GetProtocol() == Protocol::HTTP ? "HTTP" : "HTTPS") << "\n";
			std::cout << "Port: " << url.GetPort() << "\n";
		}
		catch (const CUrlParsingError& e)
		{
			std::cerr << "Parsing error: " << e.what() << "\n";
		}
		catch (const std::invalid_argument& e)
		{
			std::cerr << "Invalid argument: " << e.what() << "\n";
		}
	}
	return 0;
}
