CC = g++
CFLAGS = -g
Compile = g++  -I/home/christopher/Documents/Simulation/googletest-release-1.11.0/googletest/include/ -L/home/christopher/Documents/Simulation/googletest-release-1.11.0/lib/lib -lpthread -lgtest_main -lgtest
Dir_comms = src/Communication/
Dir_dist = src/Distribution/
Dir_helper = src/Common/
Dir_test = Test/
objects_h = ${Dir_helper}hash_interface.o ${Dir_helper}KmerReader_FASTA.o ${Dir_helper}MurmurHash3.o ${Dir_helper}Polynomial_rolling.o ${Dir_helper}Read_FASTA.o ${Dir_helper}ClassicalMinimizer.o ${Dir_helper}supermer_reader.o ${Dir_helper}hash_table_dist.o
objects_nh = ${Dir_comms}Hash_based.o ${Dir_comms}Min_based.o ${Dir_comms}Min_based_faster.o ${Dir_dist}Hash_based.o ${Dir_dist}Min_based.o
objects_tt = ${Dir_test}test_minimizer.o ${Dir_test}test_hash_function.o ${Dir_test}test_file_reader.o ${Dir_test}test_kmer_reader.o ${Dir_test}test_super_reader.o

install: Generate_object_files Generate_executables

clean : 
	rm src/Common/*.o
	rm src/Communication/*.o
	rm src/Distribution
	rm Executables/*
	rm Test/*.o
	rm unittests


gentests: tests test_object
tests: $(objects_tt) $(objects_h)
	$(Compile) $^ -o unittests



############################################################

Generate_object_files: helper_object main_object

#Generate object files for common/helper files (which have header)
helper_object: $(objects_h)
$(objects_h): %.o: %.cpp %.h
	$(CC) -c $(CFLAGS) $< -o $@


#Generate object files for main files(which do not have hedear)
main_object: $(objects_nh)
$(objects_nh): %.o: %.cpp
	$(CC) -c $(CFLAGS) $< -o $@

##############################################################

Generate_executables: hash_based_comm_cost min_based_comm_cost hash_based_dist min_based_dist min_based_comm_fast

hash_based_comm_cost: ${Dir_helper}Read_FASTA.o ${Dir_comms}Hash_based.o
	$(CC) $(CFLAGS) $^ -o $@
	mv $@ Executables/


min_based_comm_cost: ${Dir_helper}Read_FASTA.o ${Dir_helper}KmerReader_FASTA.o ${Dir_helper}ClassicalMinimizer.o ${Dir_comms}Min_based.o
	$(CC) $(CFLAGS) $^ -o $@
	mv $@ Executables/

hash_based_dist: ${objects_h} ${Dir_dist}Hash_based.o
	$(CC) $(CFLAGS) $^ -o $@
	mv $@ Executables/

min_based_dist: ${objects_h} ${Dir_dist}Min_based.o
	$(CC) $(CFLAGS) $^ -o $@
	mv $@ Executables/

min_based_comm_fast: ${objects_h} ${Dir_comms}Min_based_faster.o
	$(CC) $(CFLAGS) $^ -o $@
	mv $@ Executables/
###############################################################


test_object: $(objects_tt)
$(objects_tt): %.o: %.cpp
	$(Compile) -c $< -o $@

#####################################################################


