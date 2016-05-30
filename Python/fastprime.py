import time

def isPrime(num, prime_list):
    prev = 0
    if prime_list:
        for prime_no in prime_list:
            if num % prime_no == 0:
                return False
                prev = prime_no
            if num / prime_no < prev:
                break
    return True

start = time.clock()
p_list = []
max = 100000
i = 2
while True:
    if isPrime(i, p_list) == True:
        p_list.append(i)
    if i == max:
        break
    i+=1

print("Done: ", p_list[-1])
print("List: ", len(p_list))
print("Time: ", time.clock() - start)
