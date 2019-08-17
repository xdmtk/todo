#pragma once
#include <fstream>
#include <map>
#include <todo/priority.h>


class TodoList {
    
    public:
        TodoList(bool);

    

    private: 
        void create_config();
        void write_config();
        void read_config();
        std::map<int, Priority> priorities;
        int buffer_size = 256;

};
