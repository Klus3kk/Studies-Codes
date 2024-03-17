import threading
import time
def PUT():
    global S
    x = S
    time.sleep(2)
    x+= 50
    S = x
def ECDL():
    global S
    x = S
    x+= 70
    S = x
def run2(f1, f2):
    a = threading.Thread(target= f1)
    b = threading.Thread(target= f2)
    a.start()
    b.start()
    a.join()
    b.join()
S= 7
run2(PUT, ECDL)
print("S= ", S)