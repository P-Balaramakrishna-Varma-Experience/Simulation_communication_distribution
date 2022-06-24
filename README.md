# Simulation_communication_distribution
This repo is for simulation of communication cost and distribution efficiency of different minimizers and hash based approach.


# learning
- interface choice (where to use (what all available), what all needed to run)

- work simplistic (do not work for future tasks complicating)
    - cannot consider all things that are there. 
    - no progress in the strart (not that recomended in software)
    - Changes to correct code are common (go with the task)

- Debugging why something is happening
    - guessing randomly (frustrating)
    - guessing based on data (scientific)
        - all data (collect linearly) [overlkill sometimes]
        - do binary search 

- Desing and implemntation of small code
    - composition structed programming composition.
    - error in composstiion. (idea is not correct)
    - error in implementation idea step correct but did not implement that step correctly.
    - check the abstract constructs which are beings used ? correctly??

- verify results



//Taking t to be prime number gives much better performance
//printing output of dist
//varaince
//format
k,t,hash,var

# interface
- for every input file run every program.
    - batch file telling which all programs to run for a input file
    - to complie for different minimizer themes.(huge work)
- file wise seperation parallesim across machines.
- Run report.py with all files in the experiment directory.


# hash function extension
- The complication is that we are trying to reduce disk acess.
- Not makeing any new .cpp files

## Declaring (explicit human searching net , using intellegecne)
- hash function.cpp and hash function.h
- Integrate it to hash_interface.h hash_interface.cpp

## Defininig (can be automed/do not try)
- Every file using hash_based.cpp
    - Every for loop add a line for the new hash table

## Build system
- add to object_h 

## Running system
- No change needed

## Reporting system
- Hash function array insert an element

# Minimizer extension Simple 1
Allows any form of minimizers to implemented simply
- write Minimizer.cpp and Minimzer.h with only function to give minimizer.
- extend by creating a super_reader for each of the executabe (small change in code base??)
- write a new executable for very minimizer function.
- Build system Write a new exectuable to be build.
- Running sytem array in HigherRunner.sh add executable.
- Reporting system No change
** Perfect way expect for beings slow by a factor of K ** (200??)



### Version names meant for naming graphs