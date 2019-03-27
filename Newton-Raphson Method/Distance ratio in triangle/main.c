#include <stdio.h>
#include "triangleRatio.h"

int main(){
	
	double xA, xB, xC, yA, yB, yC, ratA, ratB, ratC;
	scanf("%lf %lf", &xA , &yA);
	scanf("%lf %lf", &xB , &yB);
	scanf("%lf %lf", &xC , &yC);
	scanf("%lf %lf %lf", &ratA, &ratB, &ratC);

	triangleRatio(xA, xB, xC, yA, yB, yC, ratA, ratB, ratC);
}