import threading
import time
def r_using():
    print('r_using')
    time.sleep(1)
    print('done')   
def r_reading():
    print('r_reading')
    time.sleep(2)
    print('done')
def a_thinking():
    print('a_thinking')
    time.sleep(1)
    print('done')
def a_writing():
    print('a_writing')
    time.sleep(3)
    print('done')
def reader():
    global numRe
    i = 0
    while i < 2:
        mutex.acquire()
        numRe+= 1
        if numRe == 1:
            db.acquire()
        mutex.release()
        r_reading()
        mutex.acquire()
        numRe-= 1
        if numRe == 0:
            db.release()
        mutex.release()
        r_using()
        i = i + 1
def writer():
    j = 0
    while j < 2:
        a_thinking()
        db.acquire()
        a_writing()
        db.release()
        j = j + 1
def run4(f1, f2):
    a = threading.Thread(target= f1)
    b = threading.Thread(target= f1)
    c = threading.Thread(target= f1)
    d = threading.Thread(target= f2)
    a.start()
    b.start()
    c.start()
    d.start()
    a.join()
    b.join()
    c.join()
    d.join()
numRe = 0
db= threading.Semaphore()
mutex= threading.Semaphore()
run4(reader, writer)