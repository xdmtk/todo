#include <todo/todolist.h>
#include <todo/config.h>
#include <todo/priority.h>
#include <iostream>


TodoList::TodoList(bool config_exists) {
    Config::conf_file = "/todo.conf";
    if (!config_exists) {
        this->create_config();
    }
}


void TodoList::create_config() {

    std::vector<std::string> sample_items;
    sample_items.emplace_back("Add items to your todo list!");

    Priority sample_priority = Priority("Urgent", 0, Priority::Color::RED, sample_items);

    this->priorities.insert({0, sample_priority});
    this->write_config();
}

void TodoList::write_config() {

    std::fstream fs;
    fs.open(Config::get_config_path() + Config::conf_file, std::fstream::out);
    for (auto it = this->priorities.begin(); it != this->priorities.end(); ++it) {
        fs.write(it->second.get_raw().c_str(), it->second.get_raw().size());
    }
    fs.close();
}


void TodoList::read_config() {

    Priority static_mem;
    std::ifstream fs;
    fs.open(Config::get_config_path() + Config::conf_file, std::ifstream::in);

    std::string cur_line, priority_raw;
    bool constructing = false;

    while (std::getline(fs, cur_line, '\n')) {
        if (cur_line == static_mem.begin_str) {
            priority_raw.append(cur_line + "\n");
            constructing = true;
            continue;
        }
        else if (cur_line == static_mem.delimiter) {
            priority_raw.append(cur_line + "\n");
            constructing = false;
            auto completed_priority = Priority(priority_raw);
            this->priorities.insert({completed_priority.pri_level, completed_priority});
            continue;
        }
        priority_raw.append(cur_line);
    }

}
