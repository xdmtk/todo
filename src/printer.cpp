#include <vector>
#include <todo/printer.h>
#include <todo/todolist.h>
#include <todo/priority.h>
#include <sys/ioctl.h>
#include <boost/range/irange.hpp>



Printer::Printer(TodoList *t) {

    this->target = t;
    set_win_size();
}


void Printer::set_win_size() {

    struct winsize w{};
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    rows = w.ws_row ? w.ws_row : 150;
    columns = w.ws_col ? w.ws_col : 150;
    header_width = int(columns * .5);
}


void Printer::print_default() {

    set_win_size();
    for (auto & it : target->priorities) {
        print_header(&it.second);
        print_items(&it.second.items);
    }
}


void Printer::print_header(Priority * p) {

    int title_placement = int (header_width/2 - (p->name.size() + std::to_string(p->pri_level).size() + 3 /2));

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

    std::cout << open << ch << close;
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

    Usage: todo [mode] [flags] [args]
    To display this help page, use `todo -h`

       Modes:
         item         Add / edit / remove items from specified priority list
         priority     Add / edit / remove priority lists

       Colors:
          red
          green
          yellow
          magenta
          blue


       Item Flags:
         -a <priority #> <item string>                      Add item to list <priority #> with message <item string>
         -r <priority #> <item #>                           Remove item <item #> of list <priority #>

       Priority Flags:
         -a <priority #> <color> <priority name>            Add list with priority level <priority #> and name <priority name>
         -r <priority #> <priority #>                       Remove list with priority level <priority #>

                  )";
    std::cout << help_str << std::endl;
}

void Printer::print_error(std::string err) {

    auto p = Priority();
    p.color = p.RED;

    print_color(p.get_color_code(false), err, p.get_color_code(true));
    std::cout << std::endl;
    std::cout << std::endl;
}

void Printer::print_success(std::string msg) {

    auto p = Priority();
    p.color = p.GREEN;

    print_color(p.get_color_code(false), msg, p.get_color_code(true));
    std::cout << std::endl;
    std::cout << std::endl;
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
    if (color_arg == "yellow")
        return Priority::Color::YELLOW;
    print_error("Invalid color \"" + color_arg + "\" specified");
    exit(0);
}
