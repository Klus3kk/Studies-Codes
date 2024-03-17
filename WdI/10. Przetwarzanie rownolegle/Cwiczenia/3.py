import threading

def PUT():
    global S
    x = S
    x += 50
    S = x

def ECDL():
    global S
    x = S
    x += 70
    S = x

S = 7
PUTthread = threading.Thread(target=PUT)
ECDLthread = threading.Thread(target=ECDL)
PUTthread.start()
ECDLthread.start()
PUTthread.join()
ECDLthread.join()
print("S =", S)