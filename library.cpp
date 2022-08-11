#include "library.hpp"

using namespace std;

namespace fs = std::experimental::filesystem;

namespace library {

    fs::path Config::rm_filename(fs::path& path) {
        if (path.has_filename()) {
            return path.remove_filename();
        } else {
            return path;
        }
    }

    bool Config::exists (fs::path& path) {
        struct stat buffer{};
        return (stat (path.c_str(), &buffer) == 0);
    }


    void ConfigFile::remove(fs::path& path) {
        if (exists(path)){
            const char *file = path.c_str();
            std::remove(file);
        } else {
            throw std::invalid_argument("path does not exist \n");
        }

    }

    void ConfigFile::create(fs::path& path, string& name) {
        ofstream file;
        if (exists(path)){
            file.open(path.c_str() + name);
        } else {
            throw std::invalid_argument("path does not exist \n");
        }
    }


    string ConfigFile::from_home(fs::path& path) {
        if (exists(path)){
            return fs::absolute(path);
        } else {
            throw std::invalid_argument("path does not exist \n");
        }
    }

    void ConfigDir::remove(fs::path& path) {
        fs::path p = rm_filename(path);
        if (exists(p)){
            rmdir(p.c_str());
        } else {
            throw std::invalid_argument("path does not exist \n");
        }
    }

    void ConfigDir::create(fs::path& path, char name) {
        fs::path p = rm_filename(path);
        if (exists(p)){
            mkdir(p.c_str() + name, S_IRWXU);
        } else {
            throw std::invalid_argument("path does not exist \n");
        }
    }

    string ConfigDir::from_home(fs::path& path) {
        if (exists(path)){
            return fs::absolute(path);
        } else {
            throw std::invalid_argument("path does not exist \n");
        }
    }

} // namespace library
