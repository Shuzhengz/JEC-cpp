#ifndef JEC_CPP_LIBRARY_HPP
#define JEC_CPP_LIBRARY_HPP

#include <string>

namespace library {

    class Config {
    protected:

    public:
        static bool exists (std::string& path);

    };

    class ConfigFile : public Config{
    public:
        void remove(std::string& path);

        void create(std::string& path, const char name);

        static void from_home();
    };

    class ConfigDir : public Config {
        void remove(std::string& path);

        void create(std::string& path, char name);

        static void from_home();
    };
}

#endif //JEC_CPP_LIBRARY_HPP
