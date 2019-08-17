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
    fs.open(Config::get_config_path() + "/todo.conf", std::fstream::out);
    fs.write("hello", 6);
    fs.close();


}
