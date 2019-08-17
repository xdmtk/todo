#include <todo/config.h>

/**
 * Class to handle config file operations. 
 * For the time being, this is where the TODO data
 * will be stored
 */

bool Config::check_config() {
    
    // Check whether config directory exists
    struct stat info;
    if (stat(Config::get_config_path().c_str(), &info) != 0) {
        std::cout << "Cannot access path";
    }

}

// Get proposed config path for user
std::string Config::get_config_path() {
    return std::string("/home/") 
        + getlogin() 
        + std::string("/.config/todo");
}
