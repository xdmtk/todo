#pragma once
#include <string>
#include <iostream>
#include <unistd.h>
#include <sys/stat.h>
#include <fstream>

class Config {

    public:
        static bool check_config();
        static std::string get_config_path();
        static std::string conf_file;

};
