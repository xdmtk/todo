#include <todo/priority.h>


// This constructor can take raw data from the config and build the request priority object
Priority::Priority(std::string data) {
    


}

// This constructor is meant to be called when internal usage wants to define a Priority object
// to insert into the config. It will formulate the raw string data
Priority::Priority(std::string name, int pri_level, Priority::Color color, std::string description) {
    std::string raw_data = std::string(std::to_string(pri_level))
            + "."
            + std::to_string(color)
            + "."
            + name
            + "\n"
            + description
            + "\n"
            + this->delimiter;
    this->raw = raw_data;
    this->name = name;
    this->pri_level = pri_level;
    this->color = color;
    this->description = description;
}


std::string Priority::get_raw() {

}
