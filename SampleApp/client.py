#import socket 
#import os

#HOST = '127.0.0.1'
#PORT = 5551

#def userInput(p):

#    m = input("s: set path \nf : show files \nd : show dirs \nq: Quit \nEnter Choice")
#    while m not in ['s','f','d','q']:
#        m = input("s: set path \nf : show files \nd : show dirs \nq: Quit \nEnter Choice")

#    s.send(m.encode('utf-8'))

#    if m == 's':
#        newpath = input("ENter path starting from the current directory")
#        s.send(newpath.encode('utf-8'))

#    return m

#def display():
#    print()

#def client():
#    with socket.socket() as s:
#        s.connect((HOST,PORT))
#        print("Client connect to:",HOST,"port:",PORT)
#        p = os.getcwd()
#        s.send(p.encode('utf-8'))
#        print("Current Directory:",p)

#        mesg = userInput(p)
#        while mesg != 'q':
#            fromServer = s.recv(1024).decode('utf-8')
#            print(formServer)
#            mesg = userInput(p)

