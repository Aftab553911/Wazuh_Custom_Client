#include "ConfigParser.h"
#include <string>
#include <map>

ConfigParser::ConfigParser(int argc, char **argv)
{
    for (int i = 1; i < argc - 1; i += 2)
    {
        std::string key(argv[i]);
        std::string value(argv[i + 1]);
        options[key] = value;
    }
}

std::string ConfigParser::get(const std::string &key, const std::string &defaultValue)
{
    if (options.find(key) != options.end())
    {
        return options[key];
    }
    return defaultValue;
}
