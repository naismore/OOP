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
	// Конструктор для парсинга URL
	explicit CHttpUrl(std::string const& url);

	// Конструктор с параметрами
	CHttpUrl(std::string const& domain,
		std::string const& document,
		Protocol protocol = Protocol::HTTP);

	// Конструктор с параметрами и портом
	CHttpUrl(std::string const& domain,
		std::string const& document,
		Protocol protocol,
		unsigned short port);

	// Возвращает строковое представление URL-а
	std::string GetURL() const;

	// Возвращает доменное имя
	std::string GetDomain() const;

	// Возвращает имя документа
	std::string GetDocument() const;

	// Возвращает тип протокола
	Protocol GetProtocol() const;

	// Возвращает номер порта
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
