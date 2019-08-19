# todo


![](https://xdmtk.org/images/todo-demo.gif)
[![GitHub issues](https://img.shields.io/github/issues/xdmtk/todo)](https://github.com/xdmtk/todo/issues)
[![GitHub license](https://img.shields.io/github/license/xdmtk/todo)](https://github.com/xdmtk/todo/blob/master/LICENSE)
[![GitHub stars](https://img.shields.io/github/stars/xdmtk/todo)](https://github.com/xdmtk/todo/stargazers)

### Introduction
`todo` is a powerful and intuitive CLI todo-list utility. In contrast to other CLI todo-list programs, the `todo` interface is incredibly simple, with only a couple key commands to know in order to get started. One of the most notable and important features of `todo` is the ability to create and categorize tasks into _Priorities_. 

Priorities are indexed from 0, with importance being sorted in descending order.  For each Priority list, individual to-do items can be added to each Priority, and removed when completed. 

### Dependencies

  For building and installation, `python3` is required to execute the installation script, and both `cmake` and `make` are used to generate the build. During runtime, `todo` uses a few functions from the C++ Boost libraries and ncurses. 

  ##### Debian / Ubuntu:
  `sudo apt install libboost-all-dev libncurses5-dev python3 cmake make`


### Installation

The install process has been simplified to a simple Python script. Run `install.py` with `python3` and the executable will be created and copied to the user's local `~/bin` directory. During the final stage of installation, the script will ask for `sudo` permissions to install the bash auto-completion script into `/etc/bash_completion.d`. 

If this directory does not exist, the script will create it, but you will probably need to include a source directive for that directory in your `.bashrc`. 
