#include <todo/priority.h>


// This constructor can take raw data from the config and build the request priority object
Priority::Priority(std::string data) {
    


}

// This constructor is meant to be called when internal usage wants to define a Priority object
// to insert into the config. It will formulate the raw string data
Priority::Priority(std::string name, int pri_level, Priority::Color color, std::vector<std::string> items) {

    std::string raw_data = "\n"
            + std::to_string(pri_level)
            + "."
            + std::to_string(color)
            + "."
            + name
            + "\n";

    for (auto it = items.begin(); it != items.end(); ++it) {
        raw_data.append((*it) + "\n");
    }
    raw_data.append(this->delimiter);
    this->set_properties(name, pri_level, color, items, raw_data);
}

void Priority::set_properties(std::string n, int l, Priority::Color c, std::vector<std::string> i, std::string r) {
    this->raw = r;
    this->name = n;
    this->pri_level = l;
    this->color = c;
    this->items = i;
}


std::string Priority::get_raw() {
    return this->raw;
}
