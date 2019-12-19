#include <todo/config.h>

/**
 * TODO: WIN COMPATIBILITY
 */


Config::Config() {
    colors_enabled = true;
    column_width_percent = 50;
    if (check_config_data()) {
        parse_config_data();
    }
}

void Config::parse_config_data() {
    std::ifstream fs;
    std::string cur_line, option, option_val;
    int splitter;

    fs.open(Config::get_config_path(), std::ifstream::in);
    try {
        while (std::getline(fs, cur_line, '\n')) {
            if ((splitter = cur_line.find("=")) != -1) {
                option = cur_line.substr(0, splitter-1);
                option_val = cur_line.substr(splitter+1, cur_line.length());
                boost::algorithm::trim(option);
                boost::algorithm::trim(option_val);
                handle_config_options(option, option_val);
            }
        }
    }
    catch (std::exception &e) {}
}


void Config::handle_config_options(std::string option, std::string val) {
    if (option == "colors") {
        this->colors_enabled = (val == "yes" ? true : false);
        return;
    }
    if (option == "header_width") {
        int cw = std::strtol(val.c_str(), NULL, 10);
        if (cw >= 25 && cw <= 100) {
            this->column_width_percent = cw;
        }
    }

}

bool Config::check_todo_data() {

    // Check whether config directory exists
    struct stat info{};
    std::string todo_path_dir = Config::get_todo_path();

    if (stat(todo_path_dir.c_str(), &info) != 0) {
        if (!mkdir(todo_path_dir.c_str(), 0777)) {
            return false;
        }

    }
    return true;

}


bool Config::check_config_data() {

    // Check whether config directory exists
    struct stat info{};
    std::string config_file_path = Config::get_config_path();
    std::ifstream f((config_file_path).c_str());
    return f.good();
}
std::string Config::get_config_path() {
    return std::string("/home/")
           + getlogin()
           + std::string("/.config/todo/config");

}

// Get proposed config path for user
std::string Config::get_todo_path() {
    return std::string("/home/") 
        + getlogin() 
        + std::string("/.config/todo");
}


