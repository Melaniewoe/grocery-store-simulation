//
//  main.cpp
//  Woe_HW6
//
//  Copyright © 2016 Melanie Woe. All rights reserved.
//
/*
#include <iostream>
#include <queue>
#include <cstdlib>
#include <time.h>
#include "grocery.h"
#include "sim_data_type.h"
#include <fstream>

using namespace std;



int main()
{
    ifstream FileIn;
    queue<unsigned int> next_customerarrive;
    TicketInfo Customer;
    
    TicketQueue.initializeQueue();
    while(!FileIn.eof())
    {
        FileIn >> Customer.stampHour;
        FileIn >> Customer.stampMinute;
        FileIn >> Customer.cashier;
        FileIn >> Customer.average time;
        TicketQueue.addQueue(Customer.stampHour);
        TicketQueue.addQueue(Customer.stampMinute);
        TicketQueue.addQueue(Customer.cashier);
        TicketQueue.addQueue(Customer.average time);
        
    }
    cout << "Customer # " << "Ticket Time " << "Option " <<" Average Time" <<
    "Start Time " << "Finish Time " << "Wait Time " << "Cashier\n";
    
    while(!TicketQueue.isEmptyQueue())
    {
        
    }
    
    system("pause");
    return 0;
}
*/
/*
int getRandomNumber(int range)
{
    int randomNumber = 1 + rand() % range;
    return randomNumber;
}

*/

/*
void register_simulate(unsigned int register_time, double arrival_probability, unsigned int time_total)
{
 
    
    
    queue<unsigned int> next_customerarrive;
   
    unsigned next = 0;
    bool_source arrive(arrival_probability);
    Register machine(register_time);
    averager timewait;
    unsigned int current_time;
    
    //int register_time = getRandomNumber(int range);
    
    //srand(time (0)); //randomize the random number generator
    
    
    
    //parameters for cout
    cout << "Time to check out a customer: " << register_time << endl;
    cout << "Probablily of the next customer arrive during a second: " << arrival_probability << endl;
    cout << "Total simulation time: " << time_total << endl;
    
    for (current_time = 1; current_time <= time_total; ++current_time)//simulate the passeage of one second of time
    {
        //check wether a new customer come
        if (arrive.query())
            next_customerarrive.push(current_time);
        
        //check wether we can start the next one
        if ((!machine._busy()) && (!next_customerarrive.empty()))
        {
            //next = next_customerarrive.front();
            next_customerarrive.pop();
            timewait.nextnum(current_time - next);
            machine.start_register();
            
        }
        
        machine.one_sec();
        
    }
    
    //summary information
    cout << "Customer served: " << timewait.numbers_count() << endl;   //numbers counted
    if (timewait.numbers_count() > 0)
        cout << "Average wait: " << timewait.average() << "sec" << endl;    //average
}




*/

#include <iostream>
#include <queue>
#include <fstream>
#include <stdlib.h>
using namespace std;

#include "grocery.h"

int main (void)
{
    
    //setting up the 5 lines of cashiers
    Register cashier1;
    Register cashier2;
    Register cashier3;
    Register cashier4;
    Register cashier5;
    queue<unsigned int> next_customerarrive;
    
    int register_time;
    
    //unsigned next = 0;
    double arrival_probability;
    unsigned int time_total;
    
    
    bool_source arrive(arrival_probability);
    Register machine(register_time);
    averager timewait;
    //unsigned int current_time;
    
    //int register_time = getRandomNumber(int range);
    
    //range = srand(time (0)); //randomize the random number generator

    //creating Customer variable to temporarily hold input
    Customer cust;
    
    //creating queue to hold input from file
    queue<Customer> custInput;
    
    
    //creating variable to hold simulation data
    Sim_data_type sim; //i think i can change it to average
    
    //file for getting input
    ifstream in_file;
    
    //used to temperarily hold the line obtained from the file
    string line;
    
    //used to temperarily hold the selected substring
    string substring;
    
    //parameters for cout
    cout << "Time to check out a customer: " << register_time << endl;
    cout << "Probablily of the next customer arrive during a second: " << arrival_probability << endl;
    cout << "Total simulation time: " << time_total << endl;
    
     
    //opening file
    in_file.open("output.dat");
    if( in_file.fail() )
    {
        
        cout<<"Could not open file.\n";
        return 0;
    }
    else
    {
        
        //get data from file until end of file
        while( !in_file.eof() )
        {
            
            //gets input until new line
            getline( in_file, line );
            
            //if extracted string isn't empty
            if( line.length() > 0 )
            {
                
                //getting the first digits for (number)
                substring = line.substr(0, 2);
                
                cust.set_number( atoi(substring.c_str()) );
                
                //getting the next digits for (arrival_time)
                substring = line.substr(4, 4);
                
                cust.set_arrival_time( atoi(substring.c_str()) );
                
                //getting the next digits for (serv_time)
                substring = line.substr(9, 3);
                
                cust.set_serv_time( atoi(substring.c_str()) );
                
                //adding newly created customer to the data queue
                custInput.push( cust );
                
            }
        }
        
        //closing file
        in_file.close();
    }
    
    
    //custInput.push( cust );
    
    //while store not closed
    while( sim.get_cnt() < 600 )
    {
        
        //increment minutes
        sim.inc_cnt();
        cashier1.inc_timer();
        cashier2.inc_timer();
        cashier3.inc_timer();
        cashier4.inc_timer();
        cashier5.inc_timer();
        
        //while customers can still be served
        if( sim.get_cnt() < 570 )
        {
            
            //set cust to temporarily hold front of custInput
            cust = custInput.front();
            
            //if the front of queue is ready to join line
            while( cust.get_arrival_time() == sim.get_cnt() )
            {
                
                //set the customer to the first available/shortest
                //lane; if none are open turn them away
                if(
                    cashier1.get_in_line() <= cashier2.get_in_line()||
                    cashier1.get_in_line() <= cashier3.get_in_line()||
                    cashier1.get_in_line() <= cashier4.get_in_line()||
                    cashier1.get_in_line() <= cashier5.get_in_line())
                {
                    
                    //adding customers serv time to cashiers queue
                    cashier1.add_customer( cust.get_serv_time() );
                    
                    //removing customer from input we added to queue
                    custInput.pop();
                    
                    //setting cust to new front so while checks correctly
                    cust = custInput.front();
                }
                else if(
                         cashier2.get_in_line() <= cashier1.get_in_line()||
                         cashier2.get_in_line() <= cashier3.get_in_line()||
                         cashier2.get_in_line() <= cashier4.get_in_line()||
                         cashier2.get_in_line() <= cashier5.get_in_line()
                        )
                {
                    
                    cashier2.add_customer( cust.get_serv_time() );
                    
                    custInput.pop();
                    
                    cust = custInput.front();
                }
                else if(
                         cashier3.get_in_line() <= cashier2.get_in_line()||
                         cashier3.get_in_line() <= cashier1.get_in_line()||
                         cashier3.get_in_line() <= cashier4.get_in_line()||
                         cashier3.get_in_line() <= cashier5.get_in_line()
                        )
                {
                    
                    cashier3.add_customer( cust.get_serv_time() );
                    
                    custInput.pop();
                    
                    cust = custInput.front();
                }
                else if(
                        
                         cashier4.get_in_line() <= cashier2.get_in_line() ||
                         cashier4.get_in_line() <= cashier3.get_in_line() ||
                         cashier4.get_in_line() <= cashier1.get_in_line() ||
                         cashier4.get_in_line() <= cashier5.get_in_line()
                        )
                {
                    
                    cashier4.add_customer( cust.get_serv_time() );
                    
                    custInput.pop();
                    
                    cust = custInput.front();
                }
                else if(
                         cashier5.get_in_line() <= cashier2.get_in_line() ||
                         cashier5.get_in_line() <= cashier3.get_in_line() ||
                         cashier5.get_in_line() <= cashier4.get_in_line() ||
                         cashier5.get_in_line() <= cashier1.get_in_line()
                        )
                {
                    
                    cashier5.add_customer( cust.get_serv_time() );
                    
                    custInput.pop();
                    
                    cust = custInput.front();
                }
                
            }
            
        }
        
        cashier1.one_sec();
        cashier2.one_sec();
        cashier3.one_sec();
        cashier4.one_sec();
        cashier5.one_sec();
        
        
        
    //final output
    cout<<"Total number of customers serviced: "<<timewait.numbers_count();
    //cout<<endl<<"Total number of customers turned away: " <<sim.get_num_turned_away();
    cout<<endl<<"Average wait time: "<<timewait.average()<<endl;
    
    //exit program
    return 0;
    
    }
}
