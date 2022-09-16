#include <list>
#include <stdio.h>
#include <time.h>
#include <sys/time.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/resource.h>
#include <errno.h>
#include <unistd.h>

int getRandom(){
    int i, n;
    time_t t;
    srand((unsigned) time(&t));
    int random = rand() % 1000000000;
    return random;
}

void getMemoryUsage(){
    struct rusage r_usage;
    int *p = 0;
    p = (int*)malloc(sizeof(int)*1000);
    int ret = getrusage(RUSAGE_SELF,&r_usage);
    if(ret == 0){
        printf("Memory usage: %ld kilobytes\n",r_usage.ru_maxrss);
    }
    else{
        printf("Error in get usage. errno = %d\n", errno);
    }
}

int main() {

    std::cout << "Reference machine with following specifications:\n" << std::endl;
    std::cout << "    -Device Name: LAPTOP-1OL20O36" << std::endl;
    std::cout << "    -Processor: Intel(R) Core(TM) i5-9300H CPU @ 2.40GHz   2.40 GHz" << std::endl;
    std::cout << "    -Installed RAM: 8.00 GB (7.84 GB usable)" << std::endl;
    std::cout << "    -Graphic Card: Nvidia GeForce GTX 1650\n" << std::endl;
    std::cout << "Running N problem, counting time for 1000000 elements" << std::endl;

    std::list<int>* list = new std::list<int>();
    int searchedNumber = 0;
    for(int index = 0; index < 1000000; index++){
        searchedNumber = getRandom();
        list->push_back(searchedNumber);
    }
    //Get Initial time
    struct timeval start, stop;
    double secs = 0;
    gettimeofday(&start, NULL);

    //Secuencial Search here
    std::cout << "\nLet's look for " << searchedNumber << std::endl;
    bool foundFlag = false;
    for(std::list<int>::iterator element = list->begin(); element != list->end(); ++element){
        if(searchedNumber = *element){
            foundFlag = true;
        }
    }
    if(foundFlag){
        std::cout << "Number Found!" << std::endl;
    } else{
        std::cout << "Number not Found!" << std::endl;
    }

    //Get Final time
    gettimeofday(&stop, NULL);

    secs = (double)(stop.tv_usec - start.tv_usec) / 1000000 + (double)(stop.tv_sec - start.tv_sec);
    getMemoryUsage();

    std::cout << "\nTime taken " << secs << std::endl;
    return 0;

}