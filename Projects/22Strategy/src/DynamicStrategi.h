#pragma once
#include <sstream>
#include <string>
#include <memory>
#include <vector>

enum class OutputFormat
{
	markdown,
	html
};

class ListStrategy
{
	public:
		virtual void start(std::ostringstream& os) {};
		virtual void end(std::ostringstream& os) {};

		virtual void add_list_item(std::ostringstream& os, const std::string& item) = 0;
};


class MarkdownStrategy
	:public ListStrategy
{
	public:
		void add_list_item(std::ostringstream& os, const std::string& item)
		{
			os << "* " << item << "\n";
		}
};

class HtmlStrategy
	:public ListStrategy
{
	public:
		void start(std::ostringstream& os) { os << "<ul>\n"; }
		void end(std::ostringstream& os) { os << "</ul>\n"; }

		void add_list_item(std::ostringstream& os, const std::string& item)
		{
			os << "  <li>" << item << "</li>\n";
		}
};

class TextFormating
{
	public:
		TextFormating() {}

		void add_list(const std::vector<std::string>& list)
		{
			if (m_strategyType)
			{
				m_strategyType->start(os);
				for (auto& it : list)
				{
					m_strategyType->add_list_item(os, it);
				}
				m_strategyType->end(os);
			}
		}

		void set_format_type(const OutputFormat& format)
		{
			switch (format)
			{
			case OutputFormat::markdown:
				m_strategyType = std::make_unique<MarkdownStrategy>();				
				break;
			case OutputFormat::html:
				m_strategyType = std::make_unique<HtmlStrategy>();
				break;
			default:
				break;
			}
		}


		std::string str() { return os.str(); }



	private:
		std::ostringstream os;
		std::unique_ptr<ListStrategy> m_strategyType{nullptr};
};



//static strategy
template<typename T>
class TextFormating2
{
public:
	TextFormating() {}

	void add_list(const std::vector<std::string>& list)
	{
		m_strategyType.start(os);
		for (auto& it : list)
		{
			m_strategyType.add_list_item(os, it);
		}
		m_strategyType.end(os);
	}

	std::string str() { return os.str(); }

private:
	std::ostringstream os;
	T m_strategyType;
};