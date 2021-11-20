#include <fstream>
#include <iostream>
#include <mutex>
#include <sstream>
#include <stdexcept>
#include <thread>

#include "xml2json.hpp"

class MyConvertXmlToJson final
{
private:
    std::string m_xmlInFileName;
    std::string m_jsonOutFileName;
    std::string m_json;
    std::mutex m_mtx;

public:
    MyConvertXmlToJson(const std::string &xmlInFileName, const std::string &jsonOutFileName)
        : m_xmlInFileName(xmlInFileName), m_jsonOutFileName(jsonOutFileName)
    {}
    MyConvertXmlToJson(const char *xmlInFileName, const char *jsonOutFileName)
        : m_xmlInFileName(xmlInFileName), m_jsonOutFileName(jsonOutFileName)
    {}
    ~MyConvertXmlToJson() = default;

    MyConvertXmlToJson(const MyConvertXmlToJson &) = delete;
    MyConvertXmlToJson &operator=(const MyConvertXmlToJson &) = delete;
    MyConvertXmlToJson(MyConvertXmlToJson &&) = delete;
    MyConvertXmlToJson &operator=(MyConvertXmlToJson &&) = delete;

    auto convert() -> void
    {
        std::lock_guard<std::mutex> guard(m_mtx);

        std::ostringstream oss;
        std::ifstream inFile(m_xmlInFileName);
        if (inFile.is_open()) {
            oss << std::ifstream(m_xmlInFileName).rdbuf();
            inFile.close();
            try {
                m_json = xml2json(oss.str().data());
            } catch (const std::exception &e) {
                std::cout << e.what() << std::endl;
            } catch (...) {
                std::cout << "Convert Error" << std::endl;
            }
        } else {
            std::cout << "Unable to open file: " + m_xmlInFileName << std::endl;
        }
    }
    auto writeFile() -> void
    {
        std::lock_guard<std::mutex> guard(m_mtx);

        if (m_json.empty()) {
            return;
        }
        std::ofstream outfile(m_jsonOutFileName);
        if (outfile.is_open()) {
            outfile << m_json;
            outfile.close();
        } else {
            std::cout << "Unable to open file: " + m_jsonOutFileName << std::endl;
        }
    }
};

auto main(const int argc, const char *const argv[]) -> int
{
    if (argc == 3) {
        MyConvertXmlToJson xmlToJson(argv[1], argv[2]);

        std::thread th1([&xmlToJson]() { xmlToJson.convert(); });
        std::thread th2([&xmlToJson]() { xmlToJson.writeFile(); });

        th1.join();
        th2.join();
    } else {
        std::cout << "Invalid number of parameters" << std::endl;
    }

    return 0;
}
