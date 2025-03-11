#ifndef CHTTPURL_H
#define CHTTPURL_H

#include <regex>
#include <stdexcept>
#include <string>

enum class Protocol
{
	HTTP,
	HTTPS
};

class CUrlParsingError : public std::invalid_argument
{
public:
	explicit CUrlParsingError(const std::string& message)
		: std::invalid_argument(message)
	{
	}
};

class CHttpUrl
{
public:
	// ����������� ��� �������� URL
	explicit CHttpUrl(std::string const& url);

	// ����������� � �����������
	CHttpUrl(std::string const& domain,
		std::string const& document,
		Protocol protocol = Protocol::HTTP);

	// ����������� � ����������� � ������
	CHttpUrl(std::string const& domain,
		std::string const& document,
		Protocol protocol,
		unsigned short port);

	// ���������� ��������� ������������� URL-�
	std::string GetURL() const;

	// ���������� �������� ���
	std::string GetDomain() const;

	// ���������� ��� ���������
	std::string GetDocument() const;

	// ���������� ��� ���������
	Protocol GetProtocol() const;

	// ���������� ����� �����
	unsigned short GetPort() const;

private:
	void ValidateURL(const std::string& url);
	void ValidateDomain(const std::string& domain);

	std::string m_domain;
	std::string m_document;
	Protocol m_protocol;
	unsigned short m_port;
};

#endif // CHTTPURL_H
