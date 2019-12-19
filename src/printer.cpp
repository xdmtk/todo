#include <vector>
#include <todo/printer.h>
#include <todo/config.h>
#include <todo/todolist.h>
#include <todo/priority.h>
#include <sys/ioctl.h>
#include <boost/range/irange.hpp>



Printer::Printer(TodoList *t, Config *c) {
    this->config = c;
    this->target = t;
    set_win_size();
}


void Printer::set_win_size() {

    struct winsize w{};
    try {
        ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
        rows = w.ws_row ? w.ws_row : 150;
        columns = w.ws_col ? w.ws_col : 150;
        header_width = int(columns * .5);
    }
    catch (std::exception &ex){
        rows = 150;
        columns = 150;
        header_width = int(columns * .5);
    }
}


void Printer::print_default() {

    set_win_size();
    print_last_updated();
    for (auto & it : target->priorities) {
        print_header(&it.second);
        print_items(&it.second.items);
    }
}

void Printer::print_last_updated() {
    std::string last_accessed;
    try {
        if (!(last_accessed = this->target->get_last_accessed()).empty()) {
            std::cout << "Last Modified: " << last_accessed << std::endl << std::endl;
        }
    }
    catch (std::exception &e) {

    }
}


void Printer::print_header(Priority * p) {

    int title_placement = int (header_width/2 - ((p->name.size() + std::to_string(p->pri_level).size() + 3 )/2));

    std::string color_code_open = p->get_color_code(false);
    std::string color_code_close = p->get_color_code(true);

    for (auto x : boost::irange(0, header_width)) {
        print_color(color_code_open, "=", color_code_close);
    }
    std::cout << std::endl;
    for (auto x : boost::irange(0, int(header_width + 1 - p->name.size()))) {
        if (!x || x == header_width-(p->name.size() + std::to_string(p->pri_level).size() + 3)) {
            print_color(color_code_open, "!", color_code_close);
        }
        else if (x == title_placement) {
            print_color(color_code_open, p->name + " [" + std::to_string(p->pri_level) + "]", color_code_close);
        }
        else {
            std::cout << " ";
        }
    }
    std::cout << std::endl;
    for (auto x : boost::irange(0, header_width)) {
        print_color(color_code_open, "=", color_code_close);
    }
    std::cout << std::endl;
}


void Printer::print_items(std::vector<std::string> *v) {

    int index = 0;
    for (auto s : *v) {
        std::cout << " " << index++ << ") ";
        int col_count = 3 + std::to_string(index).size();
        std::vector<std::string> tokens = tokenize_item(s);
        for (auto c : tokens) {
            if (col_count + c.size() > header_width) {
                std::cout << std::endl << "   ";
                col_count = 3 + std::to_string(index).size();
            }
            std::cout << c << " ";
            col_count += c.size() + 1;
        }
        std::cout << std::endl << std::endl;


    }

}


void Printer::print_color(const std::string& open, std::string ch, const std::string& close) {

    if (config->colors_enabled) {
        std::cout << open << ch << close;
    }
    else {
        std::cout << ch ;
    }
}


std::vector<std::string> Printer::tokenize_item(std::string i) {
    std::vector<std::string> tokens;
    std::string token = "";

    for (auto c : i) {
        if (c == ' '){
            tokens.emplace_back(token);
            token.clear();
            continue;
        }
        token += c;
    }
    if (!token.empty())
        tokens.emplace_back(token);

    return tokens;
}


void Printer::print_help(bool invalid) {
    auto p = Priority();
    p.color = p.RED;
    std::string help_str = "";
    if (invalid)
        print_color(p.get_color_code(false), "\nInvalid mode or option set\n", p.get_color_code(true));
    help_str += R"(

████████╗ ██████╗       ██████╗  ██████╗
╚══██╔══╝██╔═══██╗      ██╔══██╗██╔═══██╗
   ██║   ██║   ██║█████╗██║  ██║██║   ██║
   ██║   ██║   ██║╚════╝██║  ██║██║   ██║
   ██║   ╚██████╔╝      ██████╔╝╚██████╔╝
   ╚═╝    ╚═════╝       ╚═════╝  ╚═════╝
---------------------------------------------
  Nick Martinez - nick@xdmtk.org - 2019

    Usage: todo [target] [mode] [flags] [args]

    * Configuration settings are located at ~/.config/todo/config *

    To display this help page, use `todo help`

       Targets:
         item         Targets individual todo items for a given priority list
         priority     Targets the priority list

       Modes:
          add   move    remove

       Colors:
          red   green   cyan    magenta     blue    brown

       Item Flags:
         todo item add <priority #> <item string>                          Add item to list <priority #> with message <item string>
         todo item remove <priority #> <item #>                            Remove item <item #> of list <priority #>
         todo item move <priority # old> <item #> <priority # new>         Move item <item #> of list <proririty # old> to list <priority # new>

       Priority Flags:
         todo priority add <priority #> <color> <priority name>            Add list with priority level <priority #> and name <priority name>
         todo priority remove <priority #>                                 Remove list with priority level <priority #>

                  )";
    std::cout << help_str << std::endl;
}

void Printer::print_error(std::string err) {

    auto p = Priority();
    p.color = p.RED;

    print_color(p.get_color_code(false), err, p.get_color_code(true));
    std::cout << std::endl
              << std::endl
              << std::endl
              << std::endl;
}

void Printer::print_success(std::string msg) {

    auto p = Priority();
    p.color = p.GREEN;

    print_color(p.get_color_code(false), msg, p.get_color_code(true));
    std::cout << std::endl
              << std::endl
              << std::endl
              << std::endl;
}


Priority::Color Printer::get_color_from_str(const std::string& color_arg) {
    if (color_arg == "red")
        return Priority::Color::RED;
    if (color_arg == "blue")
        return Priority::Color::BLUE;
    if (color_arg == "green")
        return Priority::Color::GREEN;
    if (color_arg == "magenta")
        return Priority::Color::MAGENTA;
    if (color_arg == "cyan")
        return Priority::Color::CYAN;
    if (color_arg == "brown")
        return Priority::Color::CYAN;
    print_error("Invalid color \"" + color_arg + "\" specified");
    exit(0);
}
