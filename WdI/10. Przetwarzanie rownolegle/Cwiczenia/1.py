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
PUT()
ECDL()
print("S = ", S)