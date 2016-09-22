import subprocess
import time
import sys

p = subprocess.Popen(["python3", sys.argv[1]], stdin=subprocess.PIPE)    

msg = ["3","8","2B","9F","58","5","B9","40","5A","2","91","BE","A8"]

for i in msg:
    print("{}".format(i))
    #sys.stdin.write(msg_stub)
    time.sleep(0.001)
