# Write a program to simulate Go back N and Selective Repeat Modes of Sliding Window Protocol in peer to peer mode and demonstrate the packets captured traces using Wireshark Packet Analyzer Tool for peer to peer mode.

# Author: Mohit Khedkar.

import socket
import time
s = socket.socket(socket.AF_INET,socket.SOCK_STREAM)

HOST = 'localhost'
PORT = 8827

s.connect((HOST,PORT))

data = s.recv(1024).decode()
print(data)
window = input("Enter Window Size : ")

s.send(bytes(window,'utf-8'))

count = 0
while 2:

    try:
        time.sleep(0.3)
        data = s.recv(8)
        print("=> ",data.decode())
        s.send(bytes('Ack','utf-8'))
    except:
        s.close()
        break