# JEC-CPP ![C++](https://github.com/Shuzhengz/JEC-cpp/actions/workflows/C++.yml/badge.svg)

Jabacat's Easy Config, C++ edition

[JEC-py](https://github.com/JakeRoggenbuck/JEC-py) | [JEC-rs](https://github.com/JakeRoggenbuck/JEC-rs) | [JEC-go](https://github.com/JakeRoggenbuck/JEC-go) | JEC-c | [JEC-c++](https://github.com/Shuzhengz/JEC-cpp) | JEC-zig | JEC-ts | [JEC-kt](https://github.com/EdwinChang24/JEC-kt)

Works in progress

TODO:

[ ] Make Tests

## API
```rs
ConfigFile
  - from_home
  - exists
  - remove
  - create
  
ConfigDir
  - from_home
  - exists
  - remove
  - create
```

## Usage
``` cpp
// Files and Directories
static bool exists(fs::path& path);                     // Checks if file or directory exists

// Files
static void remove(fs::path& path);                     // Removes file
static void create(fs::path& path, std::string& name);  // Creates file
static std::string from_home(fs::path& path);           // Gets path from home

// Directories
static void remove(fs::path& path);                     // Removes Directory
static void create(fs::path& path, char name);          // Creates directory
static std::string from_home(fs::path& path);           // Gets directory path from home (auto delete filename)
```
