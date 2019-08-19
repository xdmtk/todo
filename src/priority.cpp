#include <todo/priority.h>

inline bool is_priority_header(std::vector<std::string>::iterator a , std::vector<std::string>::iterator b) {

    return (a - b == 1);
}

Priority::Priority() {
    // This is probably bad practice, but I need to be able to access the string
    // constants defined by this class statically.
    return;
}


Priority::Priority(std::vector<std::string> data) {
    std::string data_str;
    for (auto it = data.begin(); it != data.end(); ++it){
        data_str += *it;
        boost::algorithm::trim(*it);
        if (*it == begin_str || *it == delimiter) {
            continue;
        }
        else if (is_priority_header(it, data.begin())) {
            parse_header(*it);
        }
        else {
            items.emplace_back(*it);
        }
    }
    this->raw = data_str;
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
    raw_data.append(Priority::delimiter + "\n");
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
    raw_data.append(Priority::delimiter + "\n");
    this->raw = raw_data;
    return this->raw;
}


void Priority::parse_header(std::string header) {

    int token_count = 0;
    std::string pri_level_str, name_str, color_str;

    for (auto it = header.begin(); it != header.end(); ++it) {
        if (*it == '.') {
            token_count++;
            continue;
        }
        switch (token_count) {
            case 0:
                pri_level_str += *it;
                break;
            case 1:
                color_str += *it;
                break;
            case 2:
                name_str += *it;
                break;
            default:
                assert(token_count < 3);
        }
    }
    this->pri_level = std::atoi(pri_level_str.c_str());
    this->name = name_str;
    this->color = static_cast<Color>(std::atoi(color_str.c_str()));

}

std::string Priority::get_color_code(bool closing) {

    std::string pretext = "\033[0;";
    if (closing)
        return pretext + "m";
    switch (this->color) {
        case Color::RED:
            return pretext + "31m";
        case Color::BLUE:
            return pretext + "34m";
        case Color::GREEN:
            return pretext + "32m";
        case Color::MAGENTA:
            return pretext + "35m";
        case Color::YELLOW:
            return pretext + "33m";
    }
}


