#ifndef JEC_CPP_LIBRARY_HPP
#define JEC_CPP_LIBRARY_HPP

#include <string>
#include <experimental/filesystem>

namespace fs = std::experimental::filesystem;

namespace library {

    class Config {
    protected:

    public:
        static bool exists (fs::path& path);

    };

    class ConfigFile : public Config{
    public:
        void remove(fs::path& path);

        void create(fs::path& path, std::string& name);

        static void from_home(fs::path& path);
    };

    class ConfigDir : public Config {
        void remove(fs::path& path);

        void create(fs::path& path, char name);

        static void from_home(fs::path& path);
    };
}

#endif //JEC_CPP_LIBRARY_HPP
