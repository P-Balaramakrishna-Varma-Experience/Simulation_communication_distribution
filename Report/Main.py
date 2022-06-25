import os, sys, csv
import matplotlib.pyplot as plt
from numpy import double


#this function extracs the version name to be used in the legend
def extract_version(Exe_version):
    return Exe_version[Exe_version.index('x')+1: Exe_version.index('.')]


# this function returns a list of all elemenents in coloum col_no of the csv file
def readcsv(cur_dir, filename, col_no, Dir):
    filename = "./Data/" + Dir + "/" + cur_dir + "/" + filename
    with open(filename, 'r') as f:
        reader = csv.reader(f)
        Ans = [row[col_no - 1] for row in reader]
        Ans.pop(0)
        return Ans


assert(len(sys.argv) == 2)
Dir = sys.argv[1]
Dirs = os.listdir("./Data/" + Dir)
K_Values = ["10", "30", "50", "100", "200"]
#K_Values = ["1", "3", "5", "10"]
Hash_Functions = ['geeks', 'murmur3']


#ploting communication costs
for dir_name in Dirs:
    Temp_all_files = os.listdir("./Data/" + Dir +  "/" + dir_name)
    Temp_all_files_csv = [f for f in Temp_all_files if f.endswith(".csv")]
    files = [f for f in Temp_all_files_csv if "comm" in f]

    Data = []
    for file in files:
        Data.append(readcsv(dir_name, file, 2, Dir))

    for index in range(len(Data)):
        plt.plot(K_Values, Data[index], label=extract_version(files[index]))

    plt.legend()
    plt.xlabel("K values")
    plt.ylabel("Communication costs")
    plt.savefig("./Plots/" + Dir + "Comm_costs_" + dir_name + ".png")
    plt.clf()


#plotting distribution
# number of graphs = #k * #hash * #Files
# in each plot all exe results are plotted
for dir_name in Dirs:
    Temp_all_files = os.listdir("./Data/" + Dir +  "/" + dir_name)
    Temp_all_files_csv = [f for f in Temp_all_files if f.endswith(".csv")]
    files = [f for f in Temp_all_files_csv if "dist" in f]

    Data = []
    for file_name in files:
        Dict = {}
        File_Path = "./Data/" + Dir + "/" + dir_name + "/" + file_name
        with open(File_Path, 'r') as f:
            reader = csv.reader(f)
            for row in reader:
                if row[0] == "k": 
                    continue
                if (row[0], row[2]) not in Dict:
                    Dict[(row[0], row[2])] = {}
                Dict[(row[0], row[2])][int(row[1])] = float(row[3])
        Data.append(Dict)


    for hash_func in Hash_Functions:
        for K in K_Values:
            for index in range(len(files)):
                X_values = Data[index][(K, hash_func)].keys()
                Y_values = Data[index][(K, hash_func)].values()
                t_values, var_values = zip(*sorted(zip(X_values, Y_values)))
                plt.plot(t_values, var_values, label=extract_version(files[index]))
                plt.legend()
                plt.xlabel("T values")
                plt.ylabel("variance")
                plt.savefig("./Plots/" + Dir + "Dist_" + dir_name + hash_func + "_" + str(K) + "_"  + ".png")
            plt.clf()