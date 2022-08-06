#include "library.hpp"
#include <filesystem>
#include <sys/stat.h>
#include <fstream>

#include <string>

using namespace std;

namespace library {

    bool Config::exists (string& path) {
        struct stat buffer{};
        return (stat (path.c_str(), &buffer) == 0);
    }


    void ConfigFile::remove(string& path) {
        if (exists(path)){
            const char *file = path.c_str();
            std::remove(file);
        } else {
            printf("path does not exist \n");
        }

    }

    void ConfigFile::create(string& path, const char name) {
        ofstream file;
        if (exists(path)){
            file.open(path + name);
        } else {
            printf("path does not exist \n");
        }
    }


    void ConfigFile::from_home() {

    }

    void ConfigDir::remove(string& path) {
        if (exists(path)){
            rmdir(path.c_str());
        } else {
            printf("path does not exist \n");
        }
    }

    void ConfigDir::create(string& path, char name) {
        if (exists(path)){
            mkdir(path.c_str() + name);
        } else {
            printf("path does not exist \n");
        }
    }
}
