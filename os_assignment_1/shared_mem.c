//#include <pthread.h>
#include <stdio.h>
//#include <stdbool.h>
//#include <semaphore.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include "shared_mem.h"

#define ERROR (-1)

static int get_shared_block(char *filename, int size, int blockNum){

    key_t key;

    key = ftok(filename, blockNum);
    if (key == ERROR){
        printf("ERROR: in getsharedblock\n");
        return ERROR;
    }
        
    return shmget(key, size, 0644 | IPC_CREAT); 

}

char * attach_memory_block(char *filename, int size, int blockNum) {
    int shared_block_id = get_shared_block(filename, size, blockNum);


    char *result;

    if (shared_block_id == ERROR){
        return NULL;
    }


    result = shmat(shared_block_id, NULL, 0); 
    if (result == (char *)ERROR){
        return NULL;
    }

    return result;
}

bool detach_mem_block(char *block){
    return (shmdt(block) != ERROR); 
}

/*bool destroy_mem_block(char *filename, int size, int blockNum){
    int shared_block_id = get_shared_block(filename, size, blockNum);

    if (shared_block_id == ERROR){
        return NULL;
    }

    return (shmctl(shared_block_id, IPC_RMID, NULL) != ERROR); 
}*/

/*char * connect_to_block(char *filename, int size){
    int block_num = get_block(filename, size);
    char *result;

    //return null if doesnt grab the block
    if(block_num == ERROR){
        return NULL;
    }

    result = shmat(block_num, NULL, 0);
    if (result == (char*)ERROR){
        return NULL;
    }
    return result;

}

*/







