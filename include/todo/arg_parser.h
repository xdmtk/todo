#pragma once
class ArgParser {

    public:
        enum Mode(VIEW, APPEND, REMOVE);
        static Mode parse_mode(int arg_count, char **args);

}
