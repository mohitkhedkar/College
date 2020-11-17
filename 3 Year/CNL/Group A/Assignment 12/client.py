# Installing and configure DHCP server and write a program to install the software on remote machine.

# Author: Mohit KHedkar.

import os
#Install DHCP Package

os.system("sudo dhclient -r wlp2s0")
os.system("sudo dhclient -r -v wlp2s0")
os.system("sudo dhclient -v wlp2s0")