// Name: Josiah Sanchez
// Date: 07/20/2021
// Title: Lab 4 - Memory Management
// Description: This program is designed to implement FIFO
// (aka first in first out). Here we will output every page
// number not found in the cache. In total, there should be two numbers
// that we will see in stdout.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

//insert queue and node packages
#include "queue.h"
#include "node.h"

//create queue variable
struct queue *q;

typedef struct {//to
   int pageno;
} ref_page;

int main(int argc, char *argv[]){
   int C_SIZE = atoi(argv[1]); //size of cache passed by user
   ref_page cache[C_SIZE]; // cache that stores pages
   char pageCache[100]; // keeps track of the total page faults
   q = queue_create(); //create a queue

   int i;
   int totalFaults = 0; // keeps track of the total page faults
   int pagesRead = 0; //keeps track of pages read
   for (i = 0; i < C_SIZE; i++){//initialise cache array
	cache[i].pageno = -1;
   }

   while (fgets(pageCache, C_SIZE, stdin)){
	int page_num = atoi(pageCache); // stores number read from file as int
        int c;
    
        for(c=0; c<C_SIZE; c++){
	   //if page is not in queue
	   if(queue_find(q, page_num) == NULL && queue_length(q) < C_SIZE
		&& pageCache != ""){
		enqueue(q, page_num);
		totalFaults++;
	   }
	   //if page is in the queue
	   else if(queue_find(q, page_num) != NULL && queue_length(q) < C_SIZE){
		pagesRead++;
           }
	   //if queue is full and page is not in queue
	   else if(queue_find(q, page_num) == NULL && C_SIZE == queue_length(q)){
		dequeue(q);
		enqueue(q, page_num);
		totalFaults++;
	   }

	   pagesRead++;	   
	}
	
   }

   printf("%d Total Page Faults", totalFaults);
   printf("\n%d Total Page Reads\n", pagesRead);
   return 0;
}
