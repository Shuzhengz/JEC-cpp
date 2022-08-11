#ifndef JEC_CPP_LIBRARY_HPP
#define JEC_CPP_LIBRARY_HPP

#include <experimental/filesystem>
#include <sys/stat.h>
#include <fstream>
#include <unistd.h>

namespace fs = std::experimental::filesystem;

namespace library {

    class Config {
    protected:
        static fs::path rm_filename(fs::path& path);

    public:
        static bool exists (fs::path& path);

    };

    class ConfigFile : public Config{
    public:
        static void remove(fs::path& path);

        static void create(fs::path& path, std::string& name);

        static std::string from_home(fs::path& path);
    };

    class ConfigDir : public Config {
        static void remove(fs::path& path);

        static void create(fs::path& path, char name);

        static std::string from_home(fs::path& path);
    };
}

#endif //JEC_CPP_LIBRARY_HPP
