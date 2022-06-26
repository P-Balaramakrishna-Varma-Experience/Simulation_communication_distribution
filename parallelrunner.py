import time, threading, subprocess, sys, itertools

#    Exe_line = "./Executables/" + exe + " " + "./Input_DNA/covid.fasta" + " " + "6"
#    proc = subprocess.Popen(Exe_line, stdout=subprocess.PIPE, shell=True)
#   (out, err) = proc.communicate()
 
def runner(exe, k):
    pass

def Program_handler(exe, ver):
    Specif_Threads = []

    for k in K_values:
        t = threading.Thread(target=runner, args=(exe, ver, k,))
        Specif_Threads.append(t)
        t.start()

    for t in Specif_Threads:
        t.join()






assert(len(sys.argv) == 3)
Dir = sys.argv[1]
File_name = sys.argv[2]

Executables = ["hash_based_comm_cost", "hash_based_dist", "min_based_comm_cost", "min_based_dist"]
Versions = ["hash", "hash", "min", "min"]
K_values = [10, 30, 50, 100, 200]


Exe_Threads = []
for (exe, ver) in zip(Executables, Versions):
    t = threading.Thread(target=Program_handler, args=(exe, ver))
    Exe_Threads.append(t)
    t.start()

for thread in Exe_Threads:
    thread.join()