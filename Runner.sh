#Taking input
Dir=$1
FileName=$2
Exe_Name=$3
Version=$4
#echo $Dir $Exe_Name $File_Path


#Initalizing file
mkdir ./Data/$Dir
mkdir ./Data/$Dir/$FileName
rm "./Data/${Dir}/${FileName}/${Exe_Name}x${Version}.csv"
touch "./Data/${Dir}/${FileName}/${Exe_Name}x${Version}.csv"


if [[ "$Exe_Name" == "hash_based_comm_cost" || "$Exe_Name" == "min_based_comm_cost" ]]; then
    echo "k,cost" > "./Data/${Dir}/${FileName}/${Exe_Name}x${Version}.csv"
else
    echo "k,t,hash,variance" > "./Data/${Dir}/${FileName}/${Exe_Name}x${Version}.csv"
fi


#Filling data to the file
K_values=("10" "30" "50" "100" "200")
K_values=("1" "3" "5" "10")
for K in ${K_values[@]}; do 
    #echo $K
    ./Executables/$Exe_Name ./Input_DNA/$FileName $K >> "./Data/${Dir}/${FileName}/${Exe_Name}x${Version}.csv"
done
