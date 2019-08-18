#include <todo/args.h>

Arguments::Arguments(char **args, int argc){
    std::vector<std::string> arg_vec;
    std::string arg_str = "";
    for (char **arg = args; *arg; ++arg) { // for each arg
        for (char *p = *arg; *p; ++p) {      // for each character
            arg_str += *p;
        }
        arg_vec.emplace_back(arg_str);
        arg_str.clear();
    }
    arguments = arg_vec;
    set_mode();
}

void Arguments::set_mode() {
    short index = 0;
    for (auto argument : arguments) {

        if (!index) {
            index++;
            continue;
        }

        if (index == 1) {
            if (argument != "item" && argument != "priority" && argument != "-h")
                mode = Arguments::INVALID;
            else if (argument == "item")
                mode = Arguments::ITEM;
            else if (argument == "priority")
                mode = Arguments::PRIORITY;
            else if (argument == "-h")
                mode = Arguments::HELP;
            index++;
            continue;
        }

        switch (mode) {
            case Arguments::INVALID:
                return;
            case Arguments::ITEM:
                if (argument == "-a")
                    mode = Arguments::ADD_ITEM;
                else if (argument == "-e")
                    mode = Arguments::EDIT_ITEM;
                else if (argument == "-r")
                    mode = Arguments::REMOVE_ITEM;
                else
                    mode = Arguments::INVALID;
                return;
            case Arguments::PRIORITY:
                if (argument == "-a")
                    mode = Arguments::ADD_PRIORITY;
                else if (argument == "-e")
                    mode = Arguments::EDIT_PRIORITY;
                else if (argument == "-r")
                    mode = Arguments::REMOVE_PRIORITY;
                else
                    mode = Arguments::INVALID;
                return;
        }
        index++;
    }
    if (index == 1) {
        mode = Arguments::DEFAULT;
        return;
    }
}