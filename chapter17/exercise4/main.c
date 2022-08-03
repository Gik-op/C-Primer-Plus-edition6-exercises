// main.c -- use the Queue interface
// compile with queue.c
#include <stdio.h>
#include <stdlib.h>    // for rand() and srand()
#include <time.h>      // for time()
#include "queue.h"     // change Item typedef
#define MIN_PER_HR 60.0

bool newcustomer(double x);   // is there a new customer?
Item customertime(long when); // set customer parameters

int main(void)
{
    Queue line[2];
    Item temp;                // new customer data
    int hours;                // hours of simulation
    int perhour;              // average # of arrivals per hour
    long cycle, cyclelimit;   // loop counter, limit
    long turnaways = 0;       // turned away by full queue
    long customers = 0;       // joined the queue
    long served = 0;          // served during the simulation
    long sum_line[2] = {0,0};        // cumulative line length
    int wait_time[2] ={0,0};        // time until Sigmund is free
    double min_per_cust;      // average time between arrivals
    long line_wait[2] = {0,0};       // cumulative time in line

    InitializeQueue(&line[0]);
    InitializeQueue(&line[1]);
    srand((unsigned int) time(0)); // random initializing of rand()
    puts("Case Study: Sigmund Lander's Advice Booth");
    puts("Enter the number of simulation hours:");
    scanf("%d", &hours);
    cyclelimit = MIN_PER_HR * hours;
    puts("Enter the average number of customers per hour:");
    scanf("%d", &perhour);
    min_per_cust = MIN_PER_HR / perhour;

    for (cycle = 0; cycle < cyclelimit; cycle++)
    {
        if (newcustomer(min_per_cust))
        {
            if (QueueIsFull(&line[0])&& QueueIsFull(&line[1]))
                turnaways++;
            else
            {
                customers++;
                temp = customertime(cycle);
                if(QueueItemCount(&line[0])<=QueueItemCount(&line[1]))
                    EnQueue(temp, &line[0]);
                else
                    EnQueue(temp,&line[1]);
            }
        }
        for(int index=0;index<2;index++)
        {
            if (wait_time[index] <= 0 && !QueueIsEmpty(&line[index]))
            {
                DeQueue (&temp, &line[index]);
                wait_time[index] = temp.processtime;
                line_wait[index] += cycle - temp.arrive;
                served++;
            }
            if (wait_time[index] > 0)
                wait_time[index]--;
            sum_line[index] += QueueItemCount(&line[index]);
        }
    }

    if (customers > 0)
    {
        printf("customers accepted: %ld\n", customers);
        printf("  customers served: %ld\n", served);
        printf("         turnaways: %ld\n", turnaways);
        printf("average queue size: %.2f %.2f\n",
               (double)sum_line[0]/cyclelimit,(double)sum_line[1]/cyclelimit);
        printf(" average wait time: %.2f minutes\n",
               (double)(line_wait[0]+line_wait[1])/served);
    }
    else
        puts("No customers!");
    EmptyTheQueue(&line[0]);
    EmptyTheQueue(&line[1]);
    puts("Bye!");

    return 0;
}

// x = average time, in minutes, between customers
// return value is true if customer shows up this minute
bool newcustomer(double x)
{
    if (rand() * x / RAND_MAX < 1)
        return true;
    else
        return false;
}

// when is the time at which the customer arrives
// function returns an Item structure with the arrival time
// set to when and the processing time set to a random value
// in the range 1 - 3
Item customertime(long when)
{
    Item cust;

    cust.processtime = rand() % 3 + 1;
    cust.arrive = when;

    return cust;
}
