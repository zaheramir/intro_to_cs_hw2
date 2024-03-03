#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

double minMaxGrades(double grades[], int students, bool minima_grade);
double meanGrades(double grades[], int students);
double stdGrades(double grades[], int students, double avg);
void printGrades(double grades[], int students);
void updateGrades(double grades[], int students, double exp_avg, int max_std);
void printGradesOpening();
void printOldGrades(double grades[], int num_of_grades);
void printOldGradesStatistics(double min, double max,double mean, double std);
void printNewGrades(double grades[], int num_of_grades);
void printNewGradesStatistics(double min, double max, double mean, double std);

int main()
{
	int i = 0;
	printGradesOpening();

	double grades[50] = {-1}; // because -1 can't be the grade
	for (i = 0; scanf("%lf", &grades[i]) == 1; i++);
	i -= 1; //because of the expected average
	double min = minMaxGrades(grades, i,true);
	double max = minMaxGrades(grades, i, false);
	double mean = meanGrades(grades, i);
	double std = stdGrades(grades, i, mean);
	printOldGrades(grades, i);
	printOldGradesStatistics(min, max, mean, std);
	updateGrades(grades, i, grades[i], 10);
	printNewGrades(grades, i);
	double new_min = minMaxGrades(grades, i, true);
	double new_max = minMaxGrades(grades, i, false);
	double new_mean = meanGrades(grades, i);
	double new_std = stdGrades(grades, i, new_mean);
	printNewGradesStatistics(new_min, new_max, new_mean, new_std);
	return 0;

}
/// <the function returns the maximum or the minimum according to the boolean value>
/// 
/// <the function checks if the boolean value true or false then 
/// according to it check whats the maximum or minimum>
/// <param name="grades"><the grades array>
/// <param name="students"><the grades number>
/// <param name="minimal_grade"><if U want the minimal value then it's true>
/// <returns></returns the minimal or maximal value>
double minMaxGrades(double grades[], int students, bool minimal_grade)
{
	double min_max = grades[0];
	if (minimal_grade == false)
	{
		for (int i = 0; i < students; i++)
		{
			if (grades[i] > min_max)
				min_max = grades[i];
		}
	}
	else
	{
		for (int i = 0; i < students; i++)
		{
			if (grades[i] < min_max)
				min_max = grades[i];
		}
	}
	return min_max;
}


/// <the function calculate the average of the grades>
/// 
/// <the function sum all the grades then devide them by their number>
/// <param name="grades"><the grades array>
/// <param name="students"><the number of the grades>
/// <returns></returns the average of the grades>
double meanGrades(double grades[], int students)
{
	double avg = 0;
	for (int i = 0; i < students; i++)
		avg += grades[i];
	avg /= students;
	return avg;
}
/// <the function calculate the standard deviaation of the grade>
/// 
/// <sum all the (elements - average) ^ 2 and then multibly the sum by
/// (1/ num of grades) and sqrt the result>
/// <param name="grades"><the grades array>
/// <param name="students"><the grades number>
/// <param name="avg"><the average of the grade>
/// <returns></returns the std deviation value of the entered grades>
double stdGrades(double grades[], int students, double avg)
{
	double s = 0;
	for (int i = 0; i < students ; i++) 
		s += ((grades[i] - avg) * (grades[i] - avg));
	s *= (1 / (double)students);
	s = sqrt(s);
	return s;
}
/// <the function prints all the grades>
///
/// <param name="grades"><the grades array>
/// <param name="students"><the number of the grades>
void printGrades(double grades[], int students)
{
	for (int i = 0; i < students; i++)
		printf("%.1f ",grades[i]);
	printf("\n");
}
/// <the function update the grades according to the std value>
/// 
/// 
/// <param name="grades"><array of the grades>
/// <param name="students"><the number of the grades>
/// <param name="exp_avg"><the average the user expects>
/// <param name="max_std"><the stadard deviatio>
void updateGrades(double grades[], int students, double exp_avg, int max_std)
{
	double cur_std = stdGrades(grades, students, meanGrades(grades, students));
	double new_sum = 0, new_avg = 0, abs_difference = 0;
	if (cur_std > max_std)
	{
		for (int i = 0; i < students; i++)
		{
			grades[i] *= (max_std / cur_std);
			new_sum += grades[i];
		}
		new_avg = new_sum / students;
	}
	else
		new_avg = meanGrades(grades, students);

	if (new_avg - exp_avg > 0)
		abs_difference = new_avg - exp_avg;
	else
		abs_difference = -(new_avg - exp_avg);
	
	if (abs_difference > 1)
	{
		for (int i = 0; i < students; i++)
			grades[i] -= new_avg - exp_avg;
	}
}

/// <the function prints the openning message>
void printGradesOpening() 
{
	printf("Please enter the grades of the examinees");
	printf(" followed by the expected mean\n");
}
// the function prints the grades before updating them
void printOldGrades(double grades[], int num_of_grades) 
{
	printf("Old grades: ");
	printGrades(grades, num_of_grades);
}
/// <the function prints the statistics of the old grades>
/// 
/// <print the minimal, maximal, the average (mean) and the std deviation>
void printOldGradesStatistics(double min, double max,
	double mean, double std)
{
	printf("Old minimum grade: %.1f\n", min);
	printf("Old maximum grade: %.1f\n", max);
	printf("Old mean: %.1f\n", mean);
	printf("Old standard deviation: %.1f\n", std);

}
//the function prints the new grades
void printNewGrades(double grades[], int num_of_grades) 
{
	printf("New grades: ");
	printGrades(grades, num_of_grades);
}
/// <the function prints the statistics of the new grades>
/// 
/// <print the minimal, maximal, the average (mean) and the new std deviation>
void printNewGradesStatistics(double min, double max,double mean, double std) 
{
	printf("New minimum grade: %.1f\n", min);
	printf("New maximum grade: %.1f\n", max);
	printf("New mean: %.1f\n", mean);
	printf("New standard deviation: %.1f\n", std);
}