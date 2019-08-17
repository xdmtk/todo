#include <todo/todolist.h>
#include <todo/config.h>
#include <todo/priority.h>
#include <iostream>

TodoList::TodoList(bool config_exists) {
    if (!config_exists) {
        this->create_config();
    }
}


void TodoList::create_config() {

    std::vector<std::string> sample_items;
    sample_items.emplace_back("Add items to your todo list!");

    Priority sample_priority = Priority("Urgent", 0, Priority::Color::RED, sample_items);
    this->priorities.insert({0, sample_priority});
}

void TodoList::write_config() {

    std::fstream fs;
    fs.open(Config::get_config_path() + "/todo.conf", std::fstream::out);
    for (auto it = this->priorities.begin(); it != this->priorities.end(); ++it) {
        fs.write(it->second.get_raw().c_str(), it->second.get_raw().size());
    }

    fs.close();


}


void TodoList::read_config() {

}
