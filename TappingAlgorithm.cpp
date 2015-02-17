
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void UTIL_DifferenceFinder(float x, float y)
{
	//finds the difference between x and y and returns the answer
	//static int count = 0;
	if((10-y)> x)
		x = (10-y);
	printf("This is count %f\n", x);
}

float UTIL_Ave(float x, float prevave, int count)
{
	//determines new average value as weighted value across measured average time
	float ave = prevave*count;
	ave = (ave + x)/(count + 1);
	return ave;
}

void Threshold(int x, float aveX, float scale, bool mult_add, float *Xdelta)
{
	//mult_add is true denotes multiply
	if(mult_add)
	{
		if((float)x >= aveX*scale)
		{
			*Xdelta = (float)x - (aveX*scale);
		}
	}
	//mult_add is false denotes adding
	else
	{
	}
}


int main(void)
{
	int filesize = 0;
	int x, y, z;
	int *X, *Y, *Z, *XThresholdDelta;
	float Xave=0., Yave=0.;

	//======PARAMETERS TO BE ALTERED DURING RUNTIME======
	float threshold_scale = 2.5;//this will increment up to 5 for multiply scale


	//===================================================
	FILE *infile, *outfile;
	char INFILE[100];

	scanf("%s", &INFILE);

	infile = fopen(INFILE, "r");
	if(infile == NULL)
		printf("ERROR: Failed to Read Specified Input File");
	else
	{
		while((fscanf(infile, "%i,%i,%i", &x, &y, &z)) != EOF)
		{
			filesize++;
		}
		rewind(infile);
		X = (int*)calloc(sizeof(int), filesize);
		Y = (int*)calloc(sizeof(int), filesize);
		Z = (int*)calloc(sizeof(int), filesize);

		for(int i = 0; i < filesize; i++)
			fscanf(infile, "%i, %i, %i", &X[i], &Y[i], &Z[i]);
		
		for(int i = 0; i < filesize; i++)
		{//NEED TO DO DERIVATIVE FIRST
			Xave = UTIL_Ave(abs(X[i]), Xave, i);
			Yave = UTIL_Ave(abs(Y[i]), Yave, i);
			//Threshold(X[i], Xave, threshold_scale, true, 
		}

		//outfile = fopen("test.txt", "w");
		//for(int i = 0; i < filesize; i++)
			//fprintf(outfile, "%i, %i, %i\n", X[i], Y[i], Z[i]);

		free(X);
		free(Y);
		free(Z);
		fclose(infile);
	}

	getch();
	return 0;
}
