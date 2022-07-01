import threading, subprocess, sys, itertools, os

def runner(exe, k, file, lock):
    Exe_line = "./Executables/" + exe + " " + "./Input_DNA/" + File_name + " " + str(k) + " " + M_value
    proc = subprocess.Popen(Exe_line, stdout=subprocess.PIPE, shell=True)
    (out, err) = proc.communicate()
    lock.acquire()
    file.write(out.decode("utf-8"))
    lock.release()
 

def Program_handler(exe, ver):
    lock = threading.Lock()
    file_path = "./Data/" + Dir + "/" + File_name + "/" + exe + "x" + ver + ".csv"
    f = open(file_path, "w", encoding="utf-8")

    if("comm" in exe):
        f.write("K,cost\n")
    else:
        #f.write("K,t,hash,variance\n")
        pass


    Specif_Threads = []
    for k in K_values:
        t = threading.Thread(target=runner, args=(exe, k, f, lock,))
        Specif_Threads.append(t)
        t.start()

    for t in Specif_Threads:
        t.join()

    f.close()





assert(len(sys.argv) == 4)
Dir = sys.argv[1]
File_name = sys.argv[2]
M_value = sys.argv[3]
#Executables = ["hash_based_comm_cost", "hash_based_dist", "min_based_comm_cost", "min_based_dist", "min_based_dist_up"]
Executables = ["min_based_dist"]
#Versions = ["hash", "hash", "min", "min", "min_remap"]
Versions = ["min"]
K_values = [10, 30, 50, 100, 200]


if not os.path.exists("./Data/" + Dir):
    os.makedirs("./Data/" + Dir)
if not os.path.exists("./Data/" + Dir + "/" + File_name):
    os.mkdir("./Data/" + Dir + "/" + File_name)



Exe_Threads = []
for (exe, ver) in zip(Executables, Versions):
    t = threading.Thread(target=Program_handler, args=(exe, ver,))
    Exe_Threads.append(t)
    t.start()

for thread in Exe_Threads:
    thread.join()