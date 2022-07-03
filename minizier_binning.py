import matplotlib.pyplot as plt
import json, random, time


#using a variant of the standard algorithm
def genearte_random_permutation(n):
    random.seed(time.time())
    perm = []
    for i in range(n):
        perm.append(i)
    for i in range(n):
        j = int(n * random.random())
        perm[i], perm[j] = perm[j], perm[i]
    return perm

def genmap_rand(t, n):
    assert(t > n and t % n == 0)
    func = {}
    perm = genearte_random_permutation(t)
    for i in range(n):
        func[i] = []
    for i in range(t):
        func[i % n].append(perm[i])
    return func

def convert_record(t, n, func, record):
    converted = []
    for i in range(n): 
        total_count = 0
        for bin_no in func[i]:
            total_count += record[bin_no]
        converted.append(total_count)
    return converted 

def Measure(record):
    mean = sum(record) / len(record)
    variance = 0
    for i in record:
        variance = variance + (i - mean) ** 2
    variance = variance / len(record)
    return variance



#For a given distribution find variance for various threads values
#recrod is list of size 16384
def plot_dist(record, Threads):
    x_values = Threads
    y_values = []
    for no_threads in Threads:
        Map = genmap_rand(16384, no_threads)
        Distribution = convert_record(16384, no_threads, Map, record)
        y_value = Measure(Distribution)
        y_values.append(y_value)
    plt.xscale('log')
    plt.plot(x_values, y_values, marker = 'o')
    plt.xlabel("No of threads")
    plt.ylabel("Variance")
    plt.savefig("testing.png")

def give_var(record, Threads):
    x_values = Threads
    y_values = []
    for no_threads in Threads:
        Map = genmap_rand(16384, no_threads)
        Distribution = convert_record(16384, no_threads, Map, record)
        y_value = Measure(Distribution)
        y_values.append(y_value)
    return y_values

def Fist_smaller(A, B):
    assert(len(A) == len(B))
    sum = 0
    for i in range(len(A)):
        sum = sum + (A[i] - B[i]) 
    if(sum < 0):
        return True
    else:
        return False

Threads = [4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192]

data_json = open('data.json')
Data = json.load(data_json)
record = Data[0]['record'][0]['Data']

N = 10000

min = [111111 for _ in range(len(Threads))]
max = [0 for _ in range(len(Threads))]
for _ in range(N):
    cur = give_var(record, Threads)
    if(Fist_smaller(cur, min)):
        min = cur
    if(Fist_smaller(max, cur)):
        max = cur

plt.xscale('log')
plt.plot(Threads, max, marker = 'o')
plt.plot(Threads, min, marker = 'o')
plt.xlabel("No of threads")
plt.ylabel("Variance")
plt.savefig("testing.png")
print(min)
print(max)