//Name: Josiah Sanchez
//Date: 07/13/2021
//Title: Lab 3 - Step 3
//Description: This program is designed to implement
//the shell command "cat/etc/passwd | grep root"

/*Program for Step 3*/
//including libraries
#include <sys/types.h>
#include <sys/ipc.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>

//main
int main(int argc, char *argv[]) {
   int fds[2];
   pipe(fds);
  
   /*Child Process*/ 
   if(fork() == 0){/*child 1 duplicates downstream*/
	dup2(fds[0],0);
	//close upstream end of pipe	
	close(fds[1]);
	//search name input files with matching pattern
	execlp("grep", "grep", "root", NULL);
   } 
   else if(fork() == 0){ /*child 2 duplicates upstream*/
	dup2(fds[1],1);
	//close the the downstream end of pipe
	close(fds[0]);
	//concatenate files & print to stdout
	execlp("cat", "cat", "/etc/passwd",  NULL);
   }
   else{ /*parent closes both ends and wait for children*/
	close(fds[0]);
	close(fds[1]);
	wait(0);
	wait(0);
   }
   return 0;
}	 
