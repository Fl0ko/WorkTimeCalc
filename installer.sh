#!/bin/bash
curl -o /usr/local/bin/wtc.exe https://github.com/Fl0ko/WorkTimeCalc/blob/master/wtc.exe?raw=true
curl -o /usr/local/bin/wtc.sh https://raw.githubusercontent.com/Fl0ko/WorkTimeCalc/master/wtc.sh
sudo chown root: /usr/local/bin/wtc.sh
sudo chmod 755 /usr/local/bin/wtc.sh
