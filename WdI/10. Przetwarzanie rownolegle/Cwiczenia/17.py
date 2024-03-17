import threading
import time
def funA():
    global X
    global Y
    muteX.acquire()
    time.sleep(1)
    muteY.acquire()
    X= X+2
    Y= Y+2
    print("A:", X, Y)
    muteY.release()
    muteX.release()
def funB():
    global X
    global Y
    muteX.acquire()
    muteY.acquire()
    X= X+2
    Y= Y+2
    print("B:", X, Y)
    muteY.release()
    muteX.release()
def run2(f1, f2):
    a = threading.Thread(target= f1)
    b = threading.Thread(target= f2)
    a.start()
    b.start()
    a.join()
    b.join()

X= 2
muteX= threading.Semaphore()
Y= 2
muteY= threading.Semaphore()
run2(funA, funB)