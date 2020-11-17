# Part A: Setup a wired LAN using Layer 2 Switch and then IP switch of minimum four computers. It includes preparation of cable, testing of cable using line tester, configuration machine using IP addresses, testing using PING utility and demonstrate the PING packets captured traces using Wireshark Packet Analyzer Tool. Part B: Extend the same Assignment for Wireless using Access Point 

# Part A

# Author: Mohit Khedkar.

import socket

url = input("Enter url : ")
ip = socket.gethostbyname(url)
print("IP address of",url, ": " ,ip)
ip2 = input("Enter IP : ")
url2 = socket.gethostbyaddr(ip2)
print("DNS Server for given IP",ip2,": ",url2[0])