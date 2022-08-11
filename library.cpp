#include "library.hpp"

using namespace std;

namespace fs = std::experimental::filesystem;

namespace library {

    bool Config::exists (fs::path& path) {
        struct stat buffer{};
        return (stat (path.c_str(), &buffer) == 0);
    }


    void ConfigFile::remove(fs::path& path) {
        if (exists(path)){
            const char *file = path.c_str();
            std::remove(file);
        } else {
            printf("path does not exist \n");
        }

    }

    void ConfigFile::create(fs::path& path, string& name) {
        ofstream file;
        if (exists(path)){
            file.open(path.c_str() + name);
        } else {
            printf("path does not exist \n");
        }
    }


    void ConfigFile::from_home(fs::path& path) {

    }

    void ConfigDir::remove(fs::path& path) {
        if (exists(path)){
            rmdir(path.c_str());
        } else {
            printf("path does not exist \n");
        }
    }

    void ConfigDir::create(fs::path& path, char name) {
        if (exists(path)){
            mkdir(path.c_str() + name, S_IRWXU);
        } else {
            printf("path does not exist \n");
        }
    }

    void ConfigDir::from_home(fs::path& path) {

    }

} // namespace library
