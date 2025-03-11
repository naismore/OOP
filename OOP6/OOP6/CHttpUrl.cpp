#include "CHttpUrl.h"

// Регулярное выражение для проверки корректности полного URL
const std::regex url_regex(R"((http|https)://([a-zA-Z0-9.-]+)(:[0-9]{1,5})?(/.*)?)");

CHttpUrl::CHttpUrl(std::string const& url)
{
	ValidateURL(url);
}

CHttpUrl::CHttpUrl(std::string const& domain,
	std::string const& document,
	Protocol protocol)
{
	ValidateDomain(domain);

	if (document.empty() || document.front() != '/')
		m_document = '/' + document;
	else
		m_document = document;

	m_domain = domain;
	m_protocol = protocol;

	m_port = (protocol == Protocol::HTTP) ? 80 : 443;
}

CHttpUrl::CHttpUrl(std::string const& domain,
	std::string const& document,
	Protocol protocol,
	unsigned short port)
{
	ValidateDomain(domain);

	if (document.empty() || document.front() != '/')
		m_document = '/' + document;
	else
		m_document = document;

	m_domain = domain;
	m_protocol = protocol;

	if (port == 80 && protocol == Protocol::HTTPS)
		throw std::invalid_argument("Port 80 is invalid for HTTPS");

	m_port = port;
}

void CHttpUrl::ValidateURL(const std::string& url)
{
	std::smatch match;

	if (!std::regex_match(url, match, url_regex))
		throw CUrlParsingError("Invalid URL format");

	// Устанавливаем протокол
	m_protocol = (match[1] == "http") ? Protocol::HTTP : Protocol::HTTPS;

	// Устанавливаем домен
	m_domain = match[2];

	// Устанавливаем порт, если он указан
	if (match[3].length() > 0)
		m_port = static_cast<unsigned short>(std::stoi(match[3].str().substr(1)));
	else
		m_port = (m_protocol == Protocol::HTTP) ? 80 : 443; // Стандартный порт

	// Устанавливаем документ
	if (match[4].length() > 0)
	{
		m_document = match[4];
	}
	else
	{
		m_document = "/";
	}
}

void CHttpUrl::ValidateDomain(const std::string& domain)
{
	if (domain.empty() || !std::regex_match(domain, std::regex(R"(^([a-zA-Z0-9.-]+)$)")))
		throw CUrlParsingError("Domain cannot be empty or invalid");
}

std::string CHttpUrl::GetURL() const
{
	return static_cast<std::string>(m_protocol == Protocol::HTTP ? "http://" : "https://") + m_domain + (m_port == ((m_protocol == Protocol::HTTP) ? 80 : 443) ? "" : ":" + std::to_string(m_port)) + m_document;
}

std::string CHttpUrl::GetDomain() const { return m_domain; }
std::string CHttpUrl::GetDocument() const { return m_document; }
Protocol CHttpUrl::GetProtocol() const { return m_protocol; }
unsigned short CHttpUrl::GetPort() const { return m_port; }
