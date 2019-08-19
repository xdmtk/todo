#include <todo/todolist.h>
#include <todo/config.h>
#include <todo/priority.h>
#include <todo/printer.h>
#include <iostream>
#include <todo/args.h>


TodoList::TodoList(bool config_exists) {
    if (config_exists) {
        read_config();
    }
    else {
        create_config();
    }

}


void TodoList::create_config() {

    std::vector<std::string> sample_items;
    sample_items.emplace_back("Add items to your todo list!");

    Priority sample_priority = Priority("Urgent", 0, Priority::Color::RED, sample_items);

    priorities.insert({0, sample_priority});
    write_config();
}


void TodoList::write_config() {

    std::fstream fs;
    Config c_static = Config();
    fs.open(Config::get_config_path() + c_static.conf_file, std::fstream::out | std::fstream::trunc);
    fs.close();
    std::ofstream of;
    std::string full_pri_data;
    for (auto it = priorities.begin(); it != priorities.end(); ++it) {
        full_pri_data += it->second.get_raw();
    }
    of.open(Config::get_config_path() + c_static.conf_file, std::ofstream::app | std::ofstream::out);
    of << full_pri_data;
    of.close();
    read_config();
}


void TodoList::read_config() {

    Priority static_mem;
    std::ifstream fs;
    Config c_static = Config();

    fs.open(Config::get_config_path() + c_static.conf_file, std::ifstream::in);

    std::string cur_line;
    std::vector<std::string> priority_raw;

    // Reads through the config file and constructs the raw string to pass to the
    // Priority constructor to create a Priority object, which will then be appended
    // to the TodoList priorities map
    while (std::getline(fs, cur_line, '\n')) {

        priority_raw.emplace_back(cur_line + "\n");
        if (cur_line == static_mem.begin_str) {
            continue;
        }
        else if (cur_line == static_mem.delimiter) {
            auto completed_priority = Priority(priority_raw);
            priorities.insert({completed_priority.pri_level, completed_priority});
            priority_raw.clear();
            continue;
        }
    }
}

void TodoList::add_priority_list(Arguments *a, Printer *p) {
    if (a->arguments.size() != 6 ) {
        p->print_help(true);
        return;
    }

    int pri_level, color_code;
    std::string pri_name;
    Priority::Color color;
    std::vector<std::string> items_vec;

    try {

        // Priority levels must be unique
        pri_level = std::atoi(a->arguments[3].c_str());
        if (priorities.count(pri_level)) {
            p->print_error("Priority level must be unique! Priority " +
                a->arguments[3] + " already exists");
            exit(0);
        }
        pri_name = a->get_pri_name();
        color_code = std::atoi(a->arguments[4].c_str());
        color = static_cast<Priority::Color>(color_code);
    }
    catch (const std::exception& ){
        p->print_help(true);
        return;
    }
    priorities.insert({pri_level, Priority(pri_name, pri_level, color, items_vec)});
    write_config();
    p->print_success("Successfully added priority list ");
}


void TodoList::remove_priority_list(Arguments *a, Printer *p) {

    if (a->arguments.size() != 4 ) {
        p->print_help(true);
        return;
    }

    try {

        int pri_level, color_code;
        // Priority levels must be unique
        pri_level = std::atoi(a->arguments[3].c_str());
        if (!priorities.count(pri_level)) {
            p->print_error("Priority level " + a->arguments[3] + " does not exist");
            exit(0);
        }
        priorities.erase(pri_level);
    }
    catch (const std::exception& ){
        p->print_help(true);
        return;
    }
    write_config();
    p->print_success("Successfully removed priority list ");
}

/* TODO: Implement this later
 *
void TodoList::edit_priority_list(Arguments *a, Printer *p) {
    if (a->arguments.size() >= 6 ) {
        p->print_help(true);
        return;
    }

    int pri_level, color_code;
    std::string pri_name;
    Priority::Color color;
    std::vector<std::string> items_vec;

    try {

        // Priority levels must be unique
        pri_level = std::atoi(a->arguments[3].c_str());
        if (!priorities.count(pri_level)) {
            p->print_error("Priority level " + a->arguments[3] + " does not" +
                " currently exist, you can create it with `todo add " + a->arguments[3] +
                " <color code> <priority name>");
            exit(0);
        }
        priorities[pri_level].name = a->arguments.size() > 6 ? a->arguments[6] : priorities[pri_level].name;
        priorities[pri_level]

    }
    catch (const std::exception& ){
        p->print_help(true);
        return;
    }
    priorities.insert({pri_level, Priority(pri_name, pri_level, color, items_vec)});
    write_config();
}
 */
