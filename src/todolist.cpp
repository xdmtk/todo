#include <todo/todolist.h>
#include <todo/config.h>
#include <iostream>

TodoList::TodoList(bool config_exists) {
    if (!config_exists) {
        this->create_config();
    }
}


void TodoList::create_config() {
    std::fstream fs;
    std::string sample_config = std::string("0.R.Urgent\nAdd things todo to the todo list!\n<><><>");

    fs.open(Config::get_config_path() + "/todo.conf", std::fstream::out);
    fs.write(sample_config.c_str(), sample_config.size());
    fs.close();
}

void TodoList::read_config() {

}
