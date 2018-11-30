//Program made by Mengxi (William) Lei
//Assisted Debug and Modified by Tishko Aratz
//Date: 2018/11/24
//Last modified at 2018/11/28

//Fulfill the requirement of SFWRENG 2S03 Assignment 4



//===============================================================================================================================



//Import Libraries
#include "a4.h"
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

//Declear functions
int compare_fitness (const void *first, const void *second);



//===============================================================================================================================



//Runner function that evolves the image through multiple generations
PPM_IMAGE *evolve_image (const PPM_IMAGE *image, int num_generations, int population_size, double rate) {
	
	//Declear variables
	Individual *populations;
	PPM_IMAGE *finalImage;
	int step = num_generations/100;
	double newRate;
	//double temp; //Used for debugging
	//double diff; //Used for debugging
	
	//Make sure step size will at least be 100
	if (step < 100)
		step = 100;
	
	//Initialize variables
	srand(time(NULL));
	
	//Generate a random population of given size
	populations = generate_population(population_size, image->width, image->height, image->max_color);
	
	//Compute the fitness of each individual	
	comp_fitness_population(image->data, populations, population_size);
	
	//Sort the individuals in increasing order of fitness
	qsort(populations, population_size, sizeof(Individual), compare_fitness);
	
	//Do a crossover on the population, sort them, mutate part of the population, compute the fitness and sort them again.
	//Rate will be decreasing by 1% from the original rate for every 1% of the total generations passed by.
	//Write down the image for one in every 100 generations
	//temp = populations->fitness; //Used for debugging
	for (int i = 0; i < num_generations; i++) {
		newRate = (100-(i/step))/100.0*rate;
		crossover(populations, population_size);
		qsort(populations, population_size, sizeof(Individual), compare_fitness);
		mutate_population(populations, population_size, newRate);
		comp_fitness_population(image->data, populations, population_size);
		qsort(populations, population_size, sizeof(Individual), compare_fitness);
		/*diff = populations->fitness - temp; //Used for debugging
		temp = populations->fitness; //Used for debugging
		printf("%d:  %f  %f\n", i, temp, diff); //Used for debugging
		if ((i%100) == 0) { //Write down the image for videoing purposes
			char name[20];
			sprintf(name, "image%d.ppm", i/100);
			write_ppm(name, &(populations->image));
		} //End of if statement */
	} //End of for loop
	
	//Copy the info to finalImage
	finalImage = malloc(sizeof(PPM_IMAGE));
	finalImage->data = populations->image.data;
	finalImage->width = populations->image.width;
	finalImage->height = populations->image.height;
	finalImage->max_color = populations->image.max_color;
	
	//Free the memories for the individuals
	for (int i = 1; i < population_size; i++) {
		free((populations+i)->image.data);
	} //End of for loop
	free(populations);
	
	return finalImage;
	
} //End of evolve_image



//===============================================================================================================================



//Releases the memory associated with the image
void free_image (PPM_IMAGE *p) {
	
	free(p->data);
	free(p);
	
} //End of free_image function



//===============================================================================================================================



//Helper function (compare) for the built in qsort function
//Compare the fitness level of two image
int compare_fitness (const void *first, const void *second) {
	
	//Declare variables
	double difference;
	
	//Compare the fitness level of the two
	difference = ((Individual *)first)->fitness - ((Individual *)second)->fitness;
	
	//Return the result
	if (difference > 0)
		return 1;
	else if (difference < 0)
		return -1;
	else
		return 0;
	
} //End of compare_fitness function