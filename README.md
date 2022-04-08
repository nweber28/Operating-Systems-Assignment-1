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

When the producer is run, it writes a random number to one of the two memory blocks.
Once both memory blocks are full it has to wait for the consumer to consume an item before it can produce another item to the block.

The producer has 10 integers that it wants to play into memory for the consumer to consume.

Once all 10 integers have been produced the producer program terminates.

The consumer.elf program can be terminated by using Ctrl + C in the terminal.

At the conclusion of this program, the producer will have produced ten integers and the consumer will consume all ten using a memory buffer that can
hold two integer values at a time.
