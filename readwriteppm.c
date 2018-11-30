//Program made by Tishko Araz
//Assisted Debug and Modified by Mengxi (William) Lei
//Date: 2018/11/22
//Last modified at 2018/11/26

//Fulfill the requirement of SFWRENG 2S03 Assignment 4



//===============================================================================================================================



//Import Libraries
#include <stdio.h>
#include <stdlib.h>
#include "a4.h"



//===============================================================================================================================



//Reads PPM image and returns pointer to ppm image struct (data, height, width, max color)
PPM_IMAGE *read_ppm (const char *file_name) {
	
	//Pointer to ppm image that contains data
	PPM_IMAGE *p1 = malloc(sizeof(PPM_IMAGE));
	char type[3];
	
	//Pointer to pixel
	PIXEL *p;
	
	//File to read from
	FILE *imageFile;
	imageFile = fopen(file_name, "r");
	
	//Gets first 3 peices of information from PPM file
	fscanf(imageFile, "%s %d %d %d", type, &(p1->width), &(p1->height), &(p1->max_color));
	
	//Puts information into the PPM image struture
	int size = p1->width * p1->height;
	p1->data = malloc(size*sizeof(PIXEL));
	p = p1->data;
	for (int i = 0; i < size; i++) {
		fscanf(imageFile, "%hhu %hhu %hhu", &(p->r), &(p->g), &(p->b));
		p++;
	} //End of for loop
	
	fclose(imageFile);
	return p1;
	
} //End of read_ppm function



//===============================================================================================================================



//Writes ppm image into ppm file format
void write_ppm (const char *file_name, const PPM_IMAGE *image) {
	
	int width = image->width;
	int height = image->height;
	PIXEL *data = image->data;
	int maxColor = image->max_color;
	FILE *ppmImage;
	
	//Writes to the file
	ppmImage = fopen(file_name, "w");
	fprintf(ppmImage, "P3\n");
	fprintf(ppmImage, "%d %d\n", width, height);
	fprintf(ppmImage, "%d\n", maxColor);
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			fprintf(ppmImage, "%hhu %hhu %hhu ", (data+j+i*width)->r, (data+j+i*width)->g, (data+j+i*width)->b);
		} //End of for loop
		fprintf(ppmImage, "\n");
	} //End of for loop
	
	fclose(ppmImage);
	
} //End of write_ppm function