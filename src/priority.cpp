#include <todo/priority.h>
#include <iostream>


// This constructor can take raw data from the config and build the request priority object
Priority::Priority(std::string data) {
    


}

// This constructor is meant to be called when internal usage wants to define a Priority object
// to insert into the config. It will formulate the raw string data
Priority::Priority(std::string name, int pri_level, Color color, std::string description) {




}


std::string Priority::get_raw() {




}
