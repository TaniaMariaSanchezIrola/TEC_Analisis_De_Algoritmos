#include <stdio.h>
#include <time.h>
#include <sys/time.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/resource.h>
#include <errno.h>
#include <unistd.h>
// test
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
      printf("Error in getrusage. errno = %d\n", errno);
   }
}

int main() {

   //fill the list

   
   printf("Reference machine with following specifications:\n\n");
   printf("    -Device Name: LAPTOP-1OL20O36\n");
   printf("    -Processor: Intel(R) Core(TM) i5-9300H CPU @ 2.40GHz   2.40 GHz\n");
   printf("    -Installed RAM: 8.00 GB (7.84 GB usable)\n");
   printf("    -Graphic Card: Nvidia GeForce GTX 1650\n\n");
   printf("Running N problem, counting time for 1000000 elements");
   
   int numArray[1000000];
   for(int index = 0; index <1000000; index++){
      numArray[index] = getRandom();
   }

   //get InitialTime here
   struct timeval start, stop;
   double secs = 0;
   gettimeofday(&start, NULL);

   //Secuencial Search for the last of the numbers (Worst Case O(n) with n = list size)
   int searchedNum = numArray[999999];
   bool foundFlag = false;
   printf("\nLet's look for %d", searchedNum);
   for(int index = 0; index <1000000; index++){
      if(numArray[index] = searchedNum){
         foundFlag = true;
      }
   }
   if(foundFlag){
      printf("\n-----------\nNumber found!");
   }
   else{
      printf("\n-----------\nNumber not found");
   }

   //Get FinalTime here
   gettimeofday(&stop, NULL);
   //TotalTime = FinalTime - InitialTime
   secs = (double)(stop.tv_usec - start.tv_usec) / 1000000 + (double)(stop.tv_sec - start.tv_sec);
   printf("\nTime taken %f\n",secs);
   getMemoryUsage();
   return 0;
}