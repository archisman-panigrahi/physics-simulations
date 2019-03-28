#include <stdio.h>
#include "distanceRatio.h"

int main(){
	
	double latA, latB, latC, longA, longB, longC, ratA, ratB, ratC;
	scanf("%lf %lf", &latA , &longA);
	scanf("%lf %lf", &latB , &longB);
	scanf("%lf %lf", &latC , &longC);
	scanf("%lf %lf %lf", &ratA, &ratB, &ratC);

	triangleRatio(latA, latB, latC, longA, longB, longC, ratA, ratB, ratC);
}