#include <iostream>
#include <unistd.h>   
#include <sys/types.h> 
#include <cstdio>     

int main() {
    int processes = 5;
    pid_t processesarray[processes];

    for(int i = 0; i < processes; i++){ //Run multiple processes ( 3 to 4) at the same time.
        processesarray[i] = fork(); // Create a Process

        if (processesarray[i] == 0) {  
            printf("In process %d: PID = %d, Parent PID = %d\n", i, getpid(), getppid()); //Record all the information including PIDs for the processes. 
            sleep(100);  
            exit(0); //4. Find a mechanism to kill the process
        } // end if
    } // end for

    printf("Processes killed.\n");
    return 0;
}