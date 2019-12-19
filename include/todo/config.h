#pragma once
#include <string>
#include <iostream>
#include <unistd.h>
#include <sys/stat.h>
#include <fstream>
#include <boost/algorithm/string/trim.hpp>

class Config {

    public:
        Config();
        bool check_todo_data();
        bool check_config_data();
        std::string get_todo_path();
        std::string get_config_path();
        const std::string todo_file = "/todo.conf";
        const std::string conf_file = "/config";

        bool colors_enabled;
        int column_width_percent;

    void parse_config_data();
    void handle_config_options(std::string, std::string);
};
