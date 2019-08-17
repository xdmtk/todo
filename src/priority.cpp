#include <todo/priority.h>

Priority::Priority() {

    // This is probably bad practice, but I need to be able to access the string
    // constants defined by this class statically.
    return;
}


Priority::Priority(std::vector<std::string> data) {

    for (auto it = data.begin(); it != data.end(); ++it){
        if (*it == begin_str || *it == delimiter) {
            continue;
        }
        else if (is_priority_header(it, data.begin()))
            parse_header(*it);
        }




    }
}


// This constructor is meant to be called when internal usage wants to define a Priority object
// to insert into the config. It will formulate the raw string data
Priority::Priority(std::string name, int pri_level, Priority::Color color, std::vector<std::string> items) {

    std::string raw_data = begin_str
            + "\n"
            + std::to_string(pri_level)
            + "."
            + std::to_string(color)
            + "."
            + name
            + "\n";

    for (auto it = items.begin(); it != items.end(); ++it) {
        raw_data.append((*it) + "\n");
    }
    raw_data.append(Priority::delimiter);
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


void parse_header(std::string header) {



}

inline bool is_priority_header(std::vector<std::string>::iterator a , std::vector<std::string>::iterator b) {
    return (a - b == 1);
}
