import threading
import time
def produce():
    print('producing')
    time.sleep(1)
    print('done')
def insert():
    global storage
    storage = storage + 1
def consume():
    print('consuming')
    time.sleep(1)
    print('done')
def take():
    global storage
    storage = storage - 1
def producer():
    i = 0
    while i < 2:
        produce()
        Empty.acquire()
        mutex.acquire()
        insert()
        mutex.release()
        Full.release()
        i = i + 1
def consumer():
    j = 0
    while j < 2:
        Full.acquire()
        mutex.acquire()
        take()
        mutex.release()
        Empty.release()
        consume()
        j = j + 1
def run2(f1, f2):
    a = threading.Thread(target= f1)
    b = threading.Thread(target= f2)
    a.start()
    b.start()
    a.join()
    b.join()

storage= 0
Empty= threading.Semaphore(10)
Full = threading.Semaphore(0)
mutex= threading.Semaphore()
run2(producer, consumer)
print("storage = ", storage)