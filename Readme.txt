*******************************************************
*  Name      :  Melanie Woe        
*  Student ID:  105557790              
*  Class     :  CSC 2421           
*  HW#       :  6                
*  Due Date  :  March. 8, 2016
*******************************************************


                 Read Me


*******************************************************
*  Description of the program
*******************************************************

The program “grocery” implement a class that provides a simulation 
of the lines at a grocery store. The program is similar to the car 
wash simulation from the text but utilizes 5 queues instead of 1 to 
represent five cashiers with checkout lines. Customers enter the 
shortest line (queue) to check out.

*******************************************************
*  Source files
*******************************************************

Name:  main.cpp
   Main program. The file that contains the queue

Name:  grocery.h
   Contains the definition for the class bool_source, averager, 
register, customer, and sim_data_type.  

Name: my_random.cpp
   Defines and implements the classes for providing the 
   simulation of the lines.
   
*******************************************************
*  Circumstances of programs
*******************************************************

   The program compiles but did not run successfully.  
   
   The program was developed and tested on Xcode. 


*******************************************************
*  How to build and run the program
*******************************************************

1. Uncompress the homework.  The homework file is compressed.  
   To uncompress it use the following commands 
       % unzip [WoeHW6]

   Now you should see a directory named homework with the files:
        main.cpp
        grocery.h
        grocery.cpp
	output.dat
        makefile
        Readme.txt

2. Build the program.

    Change to the directory that contains the file by:
    % cd [WoeHW6] 

    Compile the program by:
    % make

3. Run the program by:
   % ./[grocery]

4. Delete the obj files, executables, and core dump by
   %./make clean
