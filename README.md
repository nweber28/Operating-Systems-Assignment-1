Operating-Systems-Assignment-1
Submission for Operating Systems Assignment 1
Nick Weber
4/7/22


 This is a repository for my files for OS Project 1.
 Within you should find 3 .c files, a .h and a Makefile

First download all of these files to a directory of your choice.
Then open a Linux terminal where you stored these files.

Run the command "make" to compile all of the files.

Next run the consumer program by using:
          ./consumer.elf
From here the consumer is waiting for the producer to produce items

To run the producer, you use this command in a seperate terminal:
          ./producer.elf 
This will start a loop that writes to the shared memory. Now you will see that the consumer is reading in what the producer is writing.

------------------------------------------------------------------------------------
Documentation:

The table.h and table.c files are made to hold the shared memory and the functions that both the producer and consumer use.

When the producer is run, it creates a random integer, converts it to a string, and this value is placed in a memory block that is stored in a table that
holds two memory blocks total.

Through the use of two semaphores, the producer and consumer communicate when each other enter the critical section, so that the other does not perform
any changes to memory during this time.

The two memory blocks are created as shared memory object instances.

The producer has 10 integers that it wants to play into memory for the consumer to consume.

Once all 10 integers have been produced the producer program terminates.

The consumer.elf program can be terminated by using Ctrl + C in the terminal.

At the end of this program ten integers will be produced and placed into memory and all ten will be consumed. However, only two integers may be in the memory buffer at once.

An example of this process occurring is located in 'prodConsExample.png' in the repo folder where the .c files are stored as well.

-Nick Weber
