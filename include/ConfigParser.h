#ifndef CONFIGPARSER_H
#define CONFIGPARSER_H

#include <string>
#include <map>

class ConfigParser
{
private:
    std::map<std::string, std::string> options;

public:
    ConfigParser(int argc, char **argv);

    std::string get(const std::string &key, const std::string &defaultValue = "");
};

#endif // CONFIGPARSER_H
