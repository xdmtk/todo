# todo


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


### Usage 
```
    Usage: todo [target] [mode] [flags] [args]
```

`todo` uses _Priority Lists_ and _Items_ to structure your todo list. First time usage will generate the default Priority "Urgent", with a default item. When calling `todo` with no arguments, the current todo list is displayed. To make changes to the todo list, you must specify a target and mode to operate on ( `item`, `priority` , `add`, `remove` )


#### Adding/Removing Items
To add an item to a particular priority list, find the priority number associated with the list _Urgent **[0]**_ And type 
```
todo item add 0 "Example item to be added to Priority List 0"
```
_Adds item to Priority list 0_



Removal syntax requires the priority number and item number
```
todo item remove 0 0
```
_Removes item 0 from Priority List 0_


#### Adding/Removing Priority Lists
To add a Priority list, you must specify the priority level ( with 0 being highest priority, must be unique ), the color of the header ( `red`, `blue`, `green`, `cyan`, `magenta` ), and the name of the list
```
todo priority add 0 red "Urgent"
```
_Adds List with Priority 0, in color red with title "Urgent"_

Removal will delete the List and all the items in it
```
todo priority remove 0
```


