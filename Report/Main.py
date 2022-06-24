import os, sys, csv
import matplotlib.pyplot as plt


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


# type == comm or dist
def PlotAll(Dir, Dirs, type):
    assert(type == 'comm' or type == 'dist')
    for dir_name in Dirs:
        Temp_all_files = os.listdir("./Data/" + Dir +  "/" + dir_name)
        Temp_all_files_csv = [f for f in Temp_all_files if f.endswith(".csv")]
        files = [f for f in Temp_all_files_csv if type in f]

        Data = []
        for file in files:
            Data.append(readcsv(dir_name, file, 2, Dir))

        for index in range(len(Data)):
            plt.plot(K_Values, Data[index], label=extract_version(files[index]))

        plt.legend()
        plt.xlabel("K values")
        if type == "comm":
            plt.ylabel("Communication costs")
            plt.savefig("./Plots/" + dir_name + "Comm_costs_" + dir_name + ".png")
        else:
            plt.ylabel("Variance of distribution")
            plt.savefig("./Plots/" + dir_name + "dist_var" + dir_name + ".png")
        plt.clf()






# Get the directory name
assert(len(sys.argv) == 2)
Dir = sys.argv[1]
Dirs = os.listdir("./Data/" + Dir)
K_Values = [1, 3, 5, 10]

PlotAll(Dir, Dirs, 'comm')
#PlotAll(Dir, Dirs, 'dist')


