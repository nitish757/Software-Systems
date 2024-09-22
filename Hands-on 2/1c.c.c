#include<stdio.h>
#include<stdlib.h>
#include<sys/time.h>
#include<signal.h>

void handle_sigvtalrm(int sig){
    static int i=1;
    printf("ITIMER_VIRTUAL timer expired %d time\n", i);
    i++;
}

void main(){
    struct itimerval timer;

    signal(SIGVTALRM, sigvtalrm);

    timer.it_value.tv_sec=10;
    timer.it_value.tv_usec=10;

    timer.it_interval.tv_sec=10;
    timer.it_interval.tv_usec=10;

    setitimer(ITIMER_VIRTUAL, &timer, NULL);

    while(1){

    }
}