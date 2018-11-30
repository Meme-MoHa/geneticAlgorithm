//Program made by Mengxi (William) Lei
//Assisted Debug and Modified by Tishko Aratz
//Date: 2018/11/23
//Last modified at 2018/11/28

//Fulfill the requirement of SFWRENG 2S03 Assignment 4



//=======================================================================================================================================



//Import Libraries
#include "a4.h"
#include <math.h>



//=======================================================================================================================================



//Compute the distance between image A and image B
double comp_distance (const PIXEL *A, const PIXEL *B, int image_size) {
	
	//Declare variables
	double distance = 0;
	double diffR;
	double diffG;
	double diffB;
	
	//Compute the distance
	for (int i = 0; i < image_size; i++) {
		diffR = (A+i)->r - (B+i)->r;
		diffG = (A+i)->g - (B+i)->g;
		diffB = (A+i)->b - (B+i)->b;
		distance += diffR*diffR + diffG*diffG + diffB*diffB;
	} //End of for loop
	distance = sqrt(distance);
	return distance;
	
} //End of comp_distance function



//=======================================================================================================================================



//Computes the fitness of each individual in the population and save it to fitness
void comp_fitness_population (const PIXEL *image, Individual *individual, int population_size) {
	
	//Calculate the distance between each individual with comp_distance function
	for (int i = 0; i < population_size; i++) {
		individual[i].fitness = comp_distance(image, individual[i].image.data, (individual[i].image.width)*(individual[i].image.height));
	} //End of for loop
	
} //End of comp_fitness_population function