#pragma once
#include <fstream>
#include <map>
#include <todo/priority.h>

class Priority;
class TodoList {
    
    public:
        explicit TodoList(bool);

    private: 
        void create_config();
        void write_config();
        void read_config();
        std::map<int, Priority, std::less<>> priorities;

        friend class Printer;
};
