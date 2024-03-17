import threading
import time
def PUT():
    global S
    mutex.acquire()
    x = S
    time.sleep(2)
    x+= 50
    S = x
    mutex.release()
def ECDL():
    global S
    mutex.acquire()
    x = S
    x+= 70
    S = x
    mutex.release()
def run2(f1, f2):
    a = threading.Thread(target= f1)
    b = threading.Thread(target= f2)
    a.start()
    b.start()
    a.join()
    b.join()
S= 7
mutex = threading.Semaphore()
run2(PUT, ECDL)
print("S= ", S)