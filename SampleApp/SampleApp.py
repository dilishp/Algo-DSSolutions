#import socket
#import threading
#import os

#HOST = "localhost"
#PORT = 5551

#def setPath(curdir,np,conn):
#    print("setting new path")
#    print("from :",curdir)
#    print("to: ",np)

#    m = "New Path:  "+np

#    conn.send(m.encode('utf-8'))

#def showfiles(p,conn):
#    ffound = "Files found under: " + p + "\n"
#    conn.send(ffound.encode('utf-8'))
#    for(path,dirlist,filelist) in os.walk(p):
#        for f in filelist:
#            print(f)
#            f = f + "\n"
#            conn.send(f.encode('utf-8'))


#def showdir(p,conn):
#    dfound = "Directories found under : " + p + "\n"
#    conn.send(dfound.encode('utf-8'))
#    for(path,dirlist,filelist) in os.walk(p):
#        for d in dirlist:
#            print(os.path.join(path,d))
#            dr = os.path.join(path,d) + '\n'
#            conn.send(dr.encode('utf-8'))

#def clientSocket():
#    s.listen()
#    (conn,addr) = s.accept()

#    FCL = []

#    while True:
#        fromclient = conn.recv(1024).decode('utf-8')
#        FCL.append(fromclient)
#        if fromclient == 's':
#            fc = conn.recv(1024).decode('utf-8')
#            setpath(FCL[0],fc,conn)
#            FCL.pop()
#        if fromclient == 'f':
#            showfiles(FCL[0],conn)
#            FCL.pop()
#        if fromclient == 'd':
#            showdir(FCL[0],conn)
#            FCL.pop()
#        if fromclient == 'q':
#            break

#HOSTCLIENT = '127.0.0.1'
#PORT = 5551

#def userInput(p):

#    m = input("s: set path \nf : show files \nd : show dirs \nq: Quit \nEnter Choice")
#    while m not in ['s','f','d','q']:
#        m = input("s: set path \nf : show files \nd : show dirs \nq: Quit \nEnter Choice")

#    s1.send(m.encode('utf-8'))

#    if m == 's':
#        newpath = input("ENter path starting from the current directory")
#        s1.send(newpath.encode('utf-8'))

#    return m

#def display():
#    print()

#def client():
#    with socket.socket() as s1:
#        s1.connect((HOSTCLIENT,PORT))
#        print("Client connect to:",HOST,"port:",PORT)
#        p = os.getcwd()
#        s1.send(p.encode('utf-8'))
#        print("Current Directory:",p)

#        mesg = userInput(p)
#        while mesg != 'q':
#            fromServer = s1.recv(1024).decode('utf-8')
#            print(formServer)
#            mesg = userInput(p)

#with socket.socket() as s:
#    s.bind((HOST,PORT))
#    print("Server Hostname:",HOST,"port:",PORT)

#    try:
#        s.settimeout(10)
#        threads = []
#        t= threading.Thread(target = clientSocket)
#        t1 = threading.Thread(target = client);
#        threads.append(t)
#        threads.append(t1)
#        t.start()
#        t1.start()
#        for th in threads:
#            th.join()

#    except socket.timeout:
#        print("Caught timeout! No client Connected.")



import numpy as np
import matplotlib.pyplot as plt

canvas = [[[255,255,255] for j in range(100)] for i in range(100)]

def square(x,y,side,color):
    plt.imshow(canvas,aspect='auto')

s




