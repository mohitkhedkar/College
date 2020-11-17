# Write a program to simulate Go back N and Selective Repeat Modes of Sliding Window Protocol in peer to peer mode and demonstrate the packets captured traces using Wireshark Packet Analyzer Tool for peer to peer mode.

# Author: Mohit Khedkar.

import socket
import time
import sys
s = socket.socket(socket.AF_INET,socket.SOCK_STREAM)

HOST = 'localhost'
PORT = 8827
s.connect((HOST,PORT))
s.bind((HOST,PORT))
s.listen()

print('Waiting.. for client to request')
client, addr = s.accept()
print(client,'connected with',addr)

client.send(bytes('Welcome Client','utf-8'))
win = client.recv(1024).decode()

print('Window Size by client:',win)
lst = ['1','2','3','4','5','6','7','8','9','10','11']
print('Frames: ', lst)
l = []
dict = {}
def gobackn(win,cnt=0,flag=True):
    win_content = lst[cnt:win+cnt]
    print('Sliding Window : ',win_content)
    count = 0
    if len(win_content) == 0:
        client.close()
        s.close()
        return
    if flag == True:
        while count < win:
            client.settimeout(0.3)
            client.send(bytes(win_content[count],'utf-8'))

            try:
                data = client.recv(8).decode()
                print(win_content[count],':',data)
                ack = True
            except socket.timeout:
                print(win_content[count],' : NAck')
                ack = False
                data = 'NAck'
            dict[win_content[count]] = data
            count = count+1
    else:
        client.settimeout(0.3)
        client.send(bytes(win_content[-1],'utf-8'))

        try:
            data = client.recv(8).decode()
            print(win_content[-1],':',data)
            ack = True
        except socket.timeout:
            print(win_content[-1],' : NAck')
            ack = False
            data = 'NAck'
        dict[win_content[-1]] = data
        count = count+1
    finalst = list(dict.items())

    finalst = finalst[cnt:win+cnt]
    if lst[-1] == finalst[-1][0]:
        for item in finalst:
            if item[0] == lst[-1]:
                if item[1] == 'Ack':
                    sys.exit()
                else:
                    flag = False
                    gobackn(win,cnt,flag)
                return
            if item[1] == 'Ack':
                cnt = cnt+1
                win = win-1
            elif item[1] == 'NAck':
                flag = True
                #cnt = cnt+1
                gobackn(win,cnt,flag)
        return

    elif finalst[0][1] == 'NAck':
        flag= True
        gobackn(win,cnt,flag)
    else:
        cnt += 1
        flag = False
        gobackn(win,cnt,flag)


gobackn(int(win))

client.close()
s.close()