Dir=$1
FileName=$2
M_value=$3

Exe_Names=("hash_based_comm_cost" "hash_based_dist" "min_based_comm_cost" "min_based_dist")
Version_Names=("hash" "hash" "min" "min")

#iterate over all Exe_Names using index
for (( i=0; i<${#Exe_Names[@]}; i++ ));
do
    bash Runner.sh $Dir $FileName ${Exe_Names[$i]} ${Version_Names[$i]} $M_value
done
