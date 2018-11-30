//Program made by Tishko Araz and Mengxi (William) Lei
//Assisted Debug and Modified by Tishko Aratz
//Date: 2018/11/22
//Last modified at 2018/11/28

//Fulfill the requirement of SFWRENG 2S03 Assignment 4



//===============================================================================================================================



//Import Libraries
#include "a4.h"
#include <stdlib.h>



//===============================================================================================================================



//Generate a random image with random RGB values
PIXEL *generate_random_image (int width, int height, int max_color) {
	
	//Declare variables
	int size = width * height;
	PIXEL *random = malloc(sizeof(PIXEL)*size);
	int max = max_color + 1;
	
	//Create the pixels with random RGB values
	for (int i = 0; i < size; i++) {
		random[i].r = rand() % max;
		random[i].g = rand() % max;
		random[i].b = rand() % max;
	} //End of for loop
	
	return random;
	
} //End of generate_random_image function



//===============================================================================================================================



//Generate a random set of populations
Individual *generate_population (int population_size, int width, int height, int max_color) {
	
	//Declare variables
	Individual *population = malloc(population_size*sizeof(Individual));
	
	//Generate the random images
	for (int i = 0; i < population_size; i++) {
		population[i].image.data = generate_random_image(width, height, max_color);
		population[i].image.width = width;
		population[i].image.height = height;
		population[i].image.max_color = max_color;
	} //End of for loop
	
	//Return the array
	return population;
	
} //End of generate_population function