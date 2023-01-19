# WorkTimeCalc
A Calculator to calculate your worktime. 

To use the WorkTimeCalc in your terminal you first need to download main.c to `/usr/local/bin` and compile it to get an `.exe` file.
You also need to create a bash script in the same directory to make a terminal command.
First use `sudo nano wtc` to create a file.
In this file you want to write: 

`#!/bin/bash`

`./wtc.exe`

Now you still need to make it executable with the following two commands:

`sudo chown root: /usr/local/bin/wtc`

`sudo chmod 755 /usr/local/bin/wtc`

Now you should be able to use `wtc` as a command!
