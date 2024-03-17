import threading
import time

def funA():
    global X
    global Y
    mutex.acquire()
    time.sleep(1)
    X= X+2
    Y= Y+2
    print("A:", X, Y)
    mutex.release()
def funB():
    global X
    global Y
    mutex.acquire()
    X= X+2
    Y= Y+2
    print("B:", X, Y)
    mutex.release()
def run2(f1, f2):
    a = threading.Thread(target= f1)
    b = threading.Thread(target= f2)
    a.start()
    b.start()
    a.join()
    b.join()

X= 2
Y= 2
mutex= threading.Semaphore()
run2(funA, funB)