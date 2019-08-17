#include <todo/config.h>
#include <todo/todolist.h>

/**
 * Class to handle config file operations. 
 * For the time being, this is where the TODO data
 * will be stored
 */

bool Config::check_config() {
    
    // Check whether config directory exists
    struct stat info{};
    std::string config_dir_path = Config::get_config_path();

    if (stat(config_dir_path.c_str(), &info) != 0) {
        if (mkdir(config_dir_path.c_str(), 0777)) {
            return true;
        }
    }

}


// Get proposed config path for user
std::string Config::get_config_path() {
    return std::string("/home/") 
        + getlogin() 
        + std::string("/.config/todo");
}


