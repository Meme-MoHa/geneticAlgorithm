//Program modified/made by Mengxi (William) Lei
//Assisted Debug and Modified by Tishko Aratz
//Date: 2018/11/28
//Last modified at 2018/11/28

//Fulfill the requirement of SFWRENG 2S03 Assignment 4



//===============================================================================================================================



//Import Libraries
#include "a4.h"
#include <stdlib.h>



//===============================================================================================================================



//Combine the two parents to create two children
void recombine(Individual *parent1, Individual *parent2, Individual *child1, Individual *child2) {
	
	//Declare variables
	int size = parent1->image.width * parent1->image.height;
	int size4 = size/4;
	int size8 = size/8;
	int crossover1;
	int crossover2;
	int crossover3;
	int i; //Counter for the for loops
	
	//Generate the random crossover points
	//They are between 1/8 to 3/8, 3/8 to 5/8, 5/8 to 7/8 respectively
	crossover1 = (rand()%(size4)) + (size8);
	crossover2 = (rand()%(size4)) + (3*size8);
	crossover3 = (rand()%(size4)) + (5*size8);
	
	//The childrens inherits from parent1/2, and switch the parent at crossover points
	for (i = 0; i < crossover1; i++) {
		child1->image.data[i] = parent1->image.data[i];
		child2->image.data[i] = parent2->image.data[i];
	} //End of for loop
	for (i = crossover1; i < crossover2; i++) {
		child1->image.data[i] = parent2->image.data[i];
		child2->image.data[i] = parent1->image.data[i];
	} //End of for loop
	for (i = crossover2; i < crossover3; i++) {
		child1->image.data[i] = parent1->image.data[i];
		child2->image.data[i] = parent2->image.data[i];
	} //End of for loop
	for (i = crossover3; i < size; i++) {
		child1->image.data[i] = parent2->image.data[i];
		child2->image.data[i] = parent1->image.data[i];
	} //End of for loop
	
} //End of recombine function



//===============================================================================================================================



//Combine each two individial from the better fitted half to create two childen replacing the less fitted half
void crossover(Individual *population, int population_size) {
	
	for (int i = 0; i < population_size / 2; i += 2)
		recombine(population + i, population + i + 1, 
				  population + population_size / 2 + i, population + population_size / 2 + i + 1);
	
}