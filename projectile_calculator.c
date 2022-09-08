/*
 *  Completed by: Aditya Prasad
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

const double G = 9.8;   /* gravitation acceleration 9.8 m/s^2 */
const double PI = 3.141592654;

void create_table(double v);
double Projectile_travel_time(double a, double v);
double Projectile_travel_distance(double a, double v);
double degree_to_radian(double d);

int main(void)
{
    int n;
    double velocity;
    
    printf ("Please enter the velocity at which the projectile is launched (m/sec): ");
    n = scanf("%lf" ,&velocity);
    
    if(n != 1)
    {
        printf("Invlid input. Bye...");
        exit(1);
    }
    
    while (velocity < 0 )
    {
        printf ("please enter a positive number for velocity: ");
        n = scanf("%lf", &velocity);
        if(n != 1)
        {
            printf("Invlid input. Bye...");
            exit(1);
        }
    }
	
    create_table(velocity);
    return 0;
}
double degree_to_radian(double input_degrees){
	double radian = input_degrees * PI/180.0;
	return radian;
}
double Projectile_travel_distance(double a1, double v1){
	double distance = (v1*v1* sin(2 * a1)/(G));
	return distance;
}
double Projectile_travel_time(double a1, double v1){
	double time = ((2*v1*sin(a1))/(G));
	return time;
}
void create_table(double v1){
	double i;
	for( i = 0.0; i <= 90.0; i += 5){
	printf("Angle in (deg) is: %f     ", i);	
	printf("t in (sec) is: %f     ", Projectile_travel_time(degree_to_radian(i),v1));
	printf("d in (m) is: %f    \n", Projectile_travel_distance(degree_to_radian(i),v1));	
	}
}