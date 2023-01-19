#!/bin/bash
curl -o /usr/local/bin/wtc.exe https://github.com/Fl0ko/WorkTimeCalc/blob/master/wtc.exe?raw=true
curl -o /usr/local/bin/wtc.sh https://github.com/Fl0ko/WorkTimeCalc/blob/master/wtc.sh?raw=true
sudo chown root: /usr/local/bin/wtc.sh
sudo chmod 755 /usr/local/bin/wtc.sh
