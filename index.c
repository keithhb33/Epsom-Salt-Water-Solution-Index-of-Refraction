#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    double x;
    printf("Enter the length of the base, x: "); // Prompts user for length of x
    scanf("%lf", &x); // Assigns value entered by user to variable x
    
    double theta_incidence = atan(2);
    double incidence_uncertainty = 0.452;
    
    double calculation = x / 12.7; // Converts fraction into decimal to be evaluated by arctangent
    double theta_refraction = atan(calculation) * 180 / (3.1415926536); // Performs arctangent & converts to degrees
    double refraction_uncertainty = (180/3.1415926536)*((0.05*x+0.635)/(pow(x, 2)+(pow(12.7, 2)))); // Calculates uncertainty using Delta_2 formula
    
    printf("Refraction angle: %f +- %f degrees", theta_refraction, refraction_uncertainty); // Prints out theta and its uncertainty
    
    theta_refraction = atan(calculation); // Calculates theta_refraction in radians
    
    double index_of_refraction = sin(theta_incidence) / ( sin(theta_refraction)); // Calculates index of refraction given theta_1 and theta_2
    
    double index_uncertainity_incidence = fabs(.5*((sin((theta_incidence + incidence_uncertainty)*(180/3.1415926536) - sin(theta_incidence)*(180/3.1415926536)) - (sin(theta_incidence)*(180/3.1415926536) - sin(theta_incidence - incidence_uncertainty)*(180/3.1415926536))) / (sin(theta_incidence)*(180/3.1415926536)))); // Finds the uncertainty associated with computing sin(theta_1)
    
    double index_uncertainity_refraction = fabs(.5*((sin((theta_refraction + refraction_uncertainty)*(180/3.1415926536) - sin(theta_refraction)*(180/3.1415926536)) - (sin(theta_refraction)*(180/3.1415926536) - sin(theta_refraction - refraction_uncertainty)*(180/3.1415926536))) / (sin(theta_refraction)*(180/3.1415926536)))); // Finds the uncertainty associated with computing sin(theta_2)
    
    double index_uncertainty = (index_uncertainity_incidence + index_uncertainity_refraction) * (index_of_refraction); // Combines the two proportional uncertainties and converts back to absolute uncertainty
    
    printf("\nIndex of refraction: %f +- %f", index_of_refraction, index_uncertainty); // Prints out the calculated index of refraction and its uncertainty
    
    return 0; // Ends the program
}
