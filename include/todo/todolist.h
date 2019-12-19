#pragma once
#include <fstream>
#include <map>
#include <todo/priority.h>

class Priority;
class Arguments;
class Printer;
class Config;
class TodoList {
    
    public:
        explicit TodoList(bool, Config *c);
        void add_priority_list(Arguments *a, Printer *p);
        void remove_priority_list(Arguments *a, Printer *p);
        void add_item(Arguments *a, Printer *p);
        void remove_item(Arguments *a, Printer *p);
        void move_item(Arguments *a, Printer *p);
        std::string get_last_accessed();

private:
        void create_todo_list();
        void write_config();
        void read_todo_list();
        std::map<int, Priority, std::less<>> priorities;
        std::string last_accessed_date;
        Config *config;
        friend class Printer;

};
