# Write a program for DNS lookup. Given an IP address input, it should return URL and viceversa. (Use JAVA/PYTHON)

# Author: Mohit Khedkar.

import socket

url = input("Enter url : ")
ip = socket.gethostbyname(url)
print("IP address of",url, ": " ,ip)
ip2 = input("Enter IP : ")
url2 = socket.gethostbyaddr(ip2)
print("DNS Server for given IP",ip2,": ",url2[0])