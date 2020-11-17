# Installing and configure DHCP server and write a program to install the software on remote machine.

# Author: Mohit KHedkar.

import os
#Install DHCP Package
os.system("apt-get install isc-dhcp-server")
#Change Subnet mask ip address to 192.168.5.0
os.system("gedit /etc/dhcp/dhcpd.conf")
os.system("gedit /etc/default/isc-dhcp-server")
os.system("gedit /etc/network/interfaces")
#Starting DHCP Service
os.system("systemctl start isc-dhcp-server")
os.system("systemctl enable isc-dhcp-server")
os.system("systemctl status isc-dhcp-server")