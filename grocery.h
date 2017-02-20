//
//  grocery.hpp
//  Woe_HW6
//
//  Copyright © 2016 Melanie Woe. All rights reserved.
//

#ifndef grocery_h
#define grocery_h

#include <cstdlib>
#include <queue>


class bool_source
{
    public :
        //constructor
        bool_source (double p = 0.5);
        //const member function
        bool query() const;
    
    private:
        //probablity returning true
        double probability;
};

class averager
{
    public :
        //constuctor
        averager();
        //member funct
        void nextnum(double val);
        //const member funct
        std::size_t numbers_count() const
        {
            return count;
        }
        double average() const;
    
    private:
        //numbers in the averager
        std::size_t count;
        //sum of all the numbers in the averager
        double sum;
    
};

class Register
{
    private:
        unsigned int seconds_for_register; //time needed for register
        unsigned int register_time_left;   //time until the next register is available
        char status; //if the lines is available
        int in_line;
        int timer; //minutes in use
        std::queue<int> time_limit;
    public:
        //constructor
        Register(unsigned int t = 60);
        //modif member function
        void one_sec();
        void start_register();
        //const member funct
        bool _busy() const
        {
            return (register_time_left > 0);
        }
    /*
        char get_status()
    {
        return status;
    }
    */
    int get_in_line()
    {
        return in_line;
    }
    
    void add_customer( int serv_time )
    {
        
        //sets timer to 0 for first input, since i reset it on pop its
        //needed for first entry.
        if( time_limit.empty() )
        {
            timer = 0;
        }
        
        //puts the serv_time on the queue of time_limits
        time_limit.push( serv_time );
        
        //add customer to line
        in_line++;
        
    }
    void inc_timer()
    {
        timer++;
    }
    
    int get_timer()
    {
        return timer;
    }
 
    int get_curr_cust_time_limit()
    {
        return time_limit.front();
    }
    
    void rmv_frnt_cust()
    {
        time_limit.pop();
        
        timer = 0;
        
        in_line--;
        
        status = 'a';
        
    }

    
    
  
};

//customer class to hold information pulled from notepad
class Customer
{
    //all information on the customer pulled from notepad
    int number;
    int arrival_time;
    int serv_time;
    
public:
    Customer()
    {
        number = 0;
        arrival_time = 0;
        serv_time = 0;
    }
    
    void set_number(int x)
    {
        number = x;
    }
    
    void set_arrival_time(int x)
    {
        arrival_time = x;
    }
    
    int get_arrival_time()
    {
        return arrival_time;
    }
    
    void set_serv_time(int x)
    {
        serv_time = x;
    }
    
    int get_serv_time()
    {
        return serv_time;
    }
    
};

class Sim_data_type
{
    int time_cnt;        // ranges in values from 0 to 600
    int num_serviced;    // number of customers serviced so far
    int wait_time;  // of all customers in the queues
    //int num_turned_away; // count of customers turned away
    
public:
    Sim_data_type()
    {
        time_cnt = 0;
        num_serviced = 0;
        wait_time = 0;
        //num_turned_away = 0;
    }
    
    void inc_cnt()
    {
        time_cnt++;
    }
    
    int get_cnt()
    {
        return time_cnt;
    }
    
    //void inc_num_turned_away()
    //{
    //    num_turned_away++;
    //}
    
    //int get_num_turned_away()
    //{
    //    return num_turned_away;
    //}
    
    void inc_num_serviced()
    {
        num_serviced++;
    }
    
    int get_num_serviced()
    {
        return num_serviced;
    }
    
    int get_avg_wait_time()
    {
        return wait_time / num_serviced;;
    }
    
    void add_tot_wait_time ( int x )
    {
        wait_time = wait_time + x;
    }
    
};



#endif /* grocery_h */
