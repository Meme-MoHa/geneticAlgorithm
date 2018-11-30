//Program made by Mengxi (William) Lei
//Assisted Debug and Modified by Tishko Aratz
//Date: 2018/11/24
//Last modified at 2018/11/28

//Fulfill the requirement of SFWRENG 2S03 Assignment 4



//===============================================================================================================================



//Import Libraries
#include "a4.h"
#include <stdlib.h>



//===============================================================================================================================



//Mutate a random amount of pixel by setting random numbers to its RGB value
void mutate (Individual *individual, double rate) {
	
	//Declear variables
	int size = individual->image.width * individual->image.height;
	int numMutate = (int)(rate/100*size);
	int pixelNum;
	int max = individual->image.max_color + 1;
	
	//Mutate each pixel
	for (int i = 0; i < numMutate; i++) {
		pixelNum = rand() % size;
		individual->image.data[pixelNum].r = rand() % max;
		individual->image.data[pixelNum].g = rand() % max;
		individual->image.data[pixelNum].b = rand() % max;
	} //End of for loop
	
} //End of mutate function



//===============================================================================================================================



//Mutate all individuals with mutate function
void mutate_population (Individual *individual, int population_size, double rate) {
	
	for (int i = 2; i < population_size; i++) {
		mutate(individual+i, rate);
	} //End of for loop
	
} //End of mutate_population function