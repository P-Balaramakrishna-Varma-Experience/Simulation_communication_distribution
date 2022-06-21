CC = g++
CFLAGS = -g
Dir_comms = src/Communication/
Dir_dist = src/Distribution/
Dir_helper = src/Common/

install: Generate_object_files Generate_executables

clean : 
	rm src/Common/*.o
	rm src/Communication/*.o
	rm Executables/*.ex


Compile = g++  -I/home/christopher/Documents/Simulation/googletest-release-1.11.0/googletest/include/ -L/home/christopher/Documents/Simulation/googletest-release-1.11.0/lib/lib -lpthread -lgtest_main -lgtest
tests: 



############################################################

Generate_object_files: helper_object main_object

#Generate object files for common/helper files (which have header)
objects_h = ${Dir_helper}hash_interface.o ${Dir_helper}KmerReader_FASTA.o ${Dir_helper}MurmurHash3.o ${Dir_helper}Polynomial_rolling.o ${Dir_helper}Read_FASTA.o ${Dir_helper}ClassicalMinimizer.o
helper_object: $(objects_h)
$(objects_h): %.o: %.cpp %.h
	$(CC) -c $(CFLAGS) $< -o $@


#Generate object files for main files(which do not have hedear)
objects_nh = ${Dir_comms}Hash_based.o ${Dir_comms}Min_based.o
main_object: $(objects_nh)
$(objects_nh): %.o: %.cpp
	$(CC) -c $(CFLAGS) $< -o $@

##############################################################

Generate_executables: hash_based_comm_cost min_based_comm_cost hash_based_dist min_based_dist

hash_based_comm_cost: ${Dir_helper}Read_FASTA.o ${Dir_comms}Hash_based.o
	$(CC) $(CFLAGS) ${Dir_helper}Read_FASTA.o ${Dir_comms}Hash_based.o -o hash_based_comm_cost.ex
	mv hash_based_comm_cost.ex Executables/













