#pragma once
#include <fstream>
#include <map>
#include <todo/priority.h>

class Priority;
class Arguments;
class Printer;
class TodoList {
    
    public:
        explicit TodoList(bool);
        void add_priority_list(Arguments *a, Printer *p);
        void remove_priority_list(Arguments *a, Printer *p);
        void add_item(Arguments *a, Printer *p);
        void remove_item(Arguments *a, Printer *p);
        void move_item(Arguments *a, Printer *p);

private:
        void create_config();
        void write_config();
        void read_config();
        std::map<int, Priority, std::less<>> priorities;

        friend class Printer;

};
