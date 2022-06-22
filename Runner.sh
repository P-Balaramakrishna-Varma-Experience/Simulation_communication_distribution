#Taking input
Dir=$1
Exe_Name=$2
FileName=$3
#echo $Dir $Exe_Name $File_Path


#Initalizing file
mkdir ./Data/$Dir
rm ./Data/$Dir/$Exe_Name_$FileName.csv
touch ./Data/$Dir/$Exe_Name_$FileName.csv
echo "k,cost" > ./Data/$Dir/$Exe_Name$FileName.csv


#Filling data to the file
K_values=("10" "30" "50" "100" "200")
for K in ${K_values[@]}; do 
    #echo $K
    ./Executables/$Exe_Name ./Input_DNA/$FileName $K >> ./Data/$Dir/$Exe_Name$FileName.csv
done
