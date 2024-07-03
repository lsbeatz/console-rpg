# console-rpg
Simple rpg game using c under ubuntu

## Environment
I have tested on Ubuntu 22.04

## Initial setup
    sudo apt install libncurses5-dev libncursesw5-dev

## Build

    git clone https://github.com/lsbeatz/console-rpg.git
    cd cosole-rpg
    make

It generates `build` directory and executable ***console-rpg.app***

## Run app
    make run

Or you can run file explicitly with command `./console-rpg.app`

## Libraries
+ ncureses
	+ You can check manual by installing ncurses-doc or [here](https://tldp.org/HOWTO/NCURSES-Programming-HOWTO/ "ncurses")
	+ **apt install ncurses-doc**
