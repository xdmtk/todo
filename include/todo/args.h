#pragma once
#include <vector>
#include <string>

/**
 *  Optional [] - Required < >
 *
 *  DEFAULT -> No arguments
 *  HELP -> -h
 *
 *  ADD_ITEM -> item -a <priority #> <item string>
 *  EDIT_ITEM -> item -e <priority #> <item #> <item string (new)>
 *  REMOVE_ITEM -> item -r <priority #> <item #>
 *
 *  ADD_PRIORITY -> priority -a <priority #> <priority name>
 *  EDIT_PRIORITY -> priority -e <priority # (old)>  <priority # (new)> [priority name (new)]
 *  REMOVE_PRIORITY -> priority -r <priority #>
 *
 */

class Arguments {

    public:
        Arguments(char **args, int argc);
        std::vector<std::string> arguments;
        enum Mode {
            DEFAULT, HELP, ADD_ITEM,
            EDIT_ITEM, REMOVE_ITEM,
            ADD_PRIORITY, EDIT_PRIORITY,
            REMOVE_PRIORITY, INVALID,
            ITEM, PRIORITY};
        Mode mode;


    private:
        void set_mode();








};