#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define PI 3.14159265

int main(){
	
	FILE *in;
	float dt = 0.00001;
	float dx;
	float c = 250;
	float r;
	float *x;
	float *phi_inic;
	float *phi_prev;
	float *phi_now;
	float *phi_next;
	int points;
	int iter;
	
	/*cuerda*/
	points = 129;
	x = malloc(points*sizeof(float));
	phi_inic = malloc(points*sizeof(float));
	phi_prev = malloc(points*sizeof(float));
	phi_now = malloc(points*sizeof(float));
	phi_next = malloc(points*sizeof(float));
	
	/*extremos fijos*/
	char filename1[100] = "cond_ini_cuerda.dat";

	in = fopen(filename1, "r");
	if(!in){
		printf("No se pudo leer el archivo.\n");
		exit(1);
	}
	for(int i = 0; i<points; i++){
		fscanf(in, "%f %f\n", &x[i], &phi_inic[i]);
	}
	fclose(in);

	dx = x[1];
	r = c*(dt/dx);

	/*primer paso*/
	phi_now[0] = 0;
	phi_now[128] = 0;
	for(int i = 1; i<points-1; i++){
		phi_now[i] = phi_inic[i] + (r*r/2)*(phi_inic[i+1] - 2*phi_inic[i] + phi_inic[i-1]);
	}
	for(int i = 0; i<points; i++){
		phi_prev[i] = phi_inic[i];
	}
	
	/*evolucion temporal*/
	iter = 1/dt;
	phi_next[0] = 0;
	phi_next[128] = 0;
	for(int i = 0; i<iter-1; i++){
		for(int j = 1; j<points-1; j++){
			phi_next[j] = 2*(1 - r*r)*phi_now[j] - phi_prev[j] + r*r*(phi_now[j+1] + phi_now[j-1]);
		}
		for(int j = 0; j<points; j++){
			phi_prev[j] = phi_now[j];
			phi_now[j] = phi_next[j];
		}
		if(i == 50){
			in = fopen("c1.txt", "w");
			for( int i = 0; i<points; i++ ){
				fprintf(in, "%f,%f,%f\n", x[i], phi_inic[i], phi_now[i]);
			}
			fclose(in);
		}
		if(i == 100){
			in = fopen("c2.txt", "w");
			for( int i = 0; i<points; i++ ){
				fprintf(in, "%f,%f\n", x[i], phi_now[i]);
			}
			fclose(in);
		}
		if(i == 150){
			in = fopen("c3.txt", "w");
			for( int i = 0; i<points; i++ ){
				fprintf(in, "%f,%f\n", x[i], phi_now[i]);
			}
			fclose(in);
		}
	}
		
	/*perturbacion periodica*/
	for(int i = 0; i<points; i++){
		phi_inic[i] = 0;
		phi_now[i] = 0;
		phi_prev[i] = phi_inic[i];
		phi_next[i] = 0;
	}
	
	/*primer paso*/
	phi_now[0] = sin((2*PI*c/0.64)*dt);
	for(int i = 1; i<points-1; i++){
		phi_now[i] = phi_inic[i] + (r*r/2)*(phi_inic[i+1] - 2*phi_inic[i] + phi_inic[i-1]);
	}
	
	/*evolucion temporal*/
	for(int i = 2; i<iter+1; i++){
		phi_next[0] = sin((2*PI*c/0.64)*(i*dt));
		for(int j = 1; j<points-1; j++){
			phi_next[j] = 2*(1 - r*r)*phi_now[j] - phi_prev[j] + r*r*(phi_now[j+1] + phi_now[j-1]);
		}
		for(int j = 0; j<points; j++){
			phi_prev[j] = phi_now[j];
			phi_now[j] = phi_next[j];
		}
		if(i == 52){
			in = fopen("c4.txt", "w");
			for( int i = 0; i<points; i++ ){
				fprintf(in, "%f,%f,%f\n", x[i], phi_inic[i], phi_now[i]);
			}
			fclose(in);
		}
		if(i == 102){
			in = fopen("c5.txt", "w");
			for( int i = 0; i<points; i++ ){
				fprintf(in, "%f,%f\n", x[i], phi_now[i]);
			}
			fclose(in);
		}
		if(i == 152){
			in = fopen("c6.txt", "w");
			for( int i = 0; i<points; i++ ){
				fprintf(in, "%f,%f\n", x[i], phi_now[i]);
			}
			fclose(in);
		}
	}
			
	/*tambor*/
	char filename2[100] = "cond_ini_tambor.dat";
	int dim = 101;
	points = dim*dim;
	phi_inic = malloc(points*sizeof(float));
	phi_prev = malloc(points*sizeof(float));
	phi_now = malloc(points*sizeof(float));
	phi_next = malloc(points*sizeof(float));
	
	in = fopen(filename2, "r");
	if(!in){
		printf("No se pudo leer el archivo.\n");
		exit(1);
	}
	for(int i = 0; i<points; i++){
		fscanf(in, "%f", &phi_inic[i]);
	}
	fclose(in);
	
	dx = 0.5/100;
	r = c*(dt/dx);
	
	/*primer paso*/
	for(int i = 0; i<points; i++){
		if(i<dim){
			phi_now[i] = 0;
		}
		if(i>=(dim-1)*dim){
			phi_now[i] = 0;
		}
		if(i%dim == 0){
			phi_now[i] = 0;
			phi_now[i-1] = 0;
		}
	}
	
	for(int i = dim+1; i<(dim-1)*dim - 1; i++){
		if(i%dim != 0 && i%dim != dim-1){
			phi_now[i] = phi_inic[i] + r*r/2*(phi_inic[i+1] - 4*phi_inic[i] + phi_inic[i-1] + phi_inic[i+dim] + phi_inic[i-dim]);
		}
	}
	for(int i = 0; i<points; i++){
		phi_prev[i] = phi_inic[i];
	}
	
	/*evolucion temporal*/
	for(int i = 0; i<points; i++){
		if(i<dim){
			phi_next[i] = 0;
		}
		if(i>=(dim-1)*dim){
			phi_next[i] = 0;
		}
		if(i%dim == 0){
			phi_next[i] = 0;
			phi_next[i-1] = 0;
		}
	}
	for(int j = 0; j<iter-1; j++){
		for(int i = dim+1; i<(dim-1)*dim - 1; i++){
			if(i%dim != 0 && i%dim != dim-1){
				phi_next[i] = 2*(1 - 2*r*r)*phi_now[i] + r*r*(phi_now[i+1] + phi_now[i-1] + phi_now[i+dim] + phi_now[i-dim]) - phi_prev[i];
			}
		}
		for(int i = 0; i<points; i++){
			phi_prev[i] = phi_now[i];
			phi_now[i] = phi_next[i];
		}
		if(j == 50){
			in = fopen("t1.txt", "w");
			for( int i = 0; i<points; i++ ){
				fprintf(in, "%f\n", phi_now[i]);
			}
			fclose(in);
		}
		if(j == 100){
			in = fopen("t2.txt", "w");
			for( int i = 0; i<points; i++ ){
				fprintf(in, "%f\n", phi_now[i]);
			}
			fclose(in);
		}
		if(j == 150){
			in = fopen("t3.txt", "w");
			for( int i = 0; i<points; i++ ){
				fprintf(in, "%f\n", phi_now[i]);
			}
			fclose(in);
		}
	}
	
	
	
	return 0;
	
}