#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

#define TRUE		1
#define FALSE		0
#define MAX_TRIES	3
#define EXIT_SUCESS	1
#define EXIT_APP	9
#define MILIMETER	1
#define CENTIMETER	2
#define METER		3
#define KILOMETER	4
#define INCH		5
#define FOOT		6
#define YARD		7
#define MILE 		8
void Exit_application(void);
void Do_conversion(int, int, double);
int Get_choice(const char*, int , int);
double milimeter_centimeter(double);
double milimeter_kilometer(double);
double milimeter_meter(double);
double milimeter_inch(double);
double milimeter_foot(double);
double milimeter_yard(double);
double milimeter_mile(double);

double centimeter_milimeter(double);
double centimeter_kilometer(double);
double centimeter_inch(double);
double centimeter_foot(double);
double meter_milimeter(double);
double kilometer_milimeter(double);
double inch_milimeter(double);
double foot_milimeter(double);
double yard_milimeter(double);
double mile_milimeter(double);
int main(void)
{
	int From_choice;
	int To_choice;
	double Input_number;

	while(TRUE)
	{	
		puts("................................................................");
		puts("1.Millimeter(mm)\n2.Centimeter(cm)\n3.Meter(m)\n4.Kilometer(km)");
		puts("5.Inch(in)\n6.Foot(ft)\n7Yard(yd)\n8.Mile(mi)\n9.Exit\n");
		
		From_choice = Get_choice("convert_from",1,9);
		if(From_choice == EXIT_APP)
		{
			Exit_application();
		}

		puts("Enter a magnitude");
		scanf("%lf",&Input_number);

		To_choice = Get_choice("convert to",1,9);
		Do_conversion(From_choice,To_choice,Input_number);
	}
}
int Get_choice(const char* Prompt_message, int From_start_number, int To_end_number)
{
	int Choice;
	int Retry_count;
	int Flag = FALSE;

	for(Retry_count = 0; Retry_count < MAX_TRIES ; Retry_count++)
	{
		puts(Prompt_message);
		printf("enter your choice\n");
		scanf("%d",&Choice);
		if(Choice >= From_start_number && Choice <= To_end_number)
		{		
				Flag = TRUE;
				break;
		}		
		puts("Please enter correct number");

	}
		if(Flag == FALSE)
		{
			Exit_application();
		}
	return Choice;

}
void Exit_application()
{
	puts("Thank you using the application");
	_getch();
	exit(EXIT_SUCESS);
}
void Do_conversion(int From_choice, int To_choice , double Input_number)
{
	double Output_number=0.0;
	char* input_unit = NULL;
	char* output_unit = NULL;

	if(From_choice == MILIMETER && To_choice == MILIMETER)
	{
		Output_number = Input_number;
		input_unit ="mm";
       		output_unit="mm";		
	}
	else if(From_choice == MILIMETER && To_choice == CENTIMETER)
	{
		Output_number = milimeter_centimeter(Input_number);
		input_unit = "mm";
		output_unit = "cm";
	}
	else if(From_choice == MILIMETER && To_choice == METER)
	{
		Output_number = milimeter_meter(Input_number);
		input_unit = "mm";
		output_unit ="m";
	}	
	else if(From_choice == MILIMETER && To_choice == KILOMETER)
	{	
		Output_number = milimeter_kilometer(Input_number);
		input_unit = "mm";
		output_unit = "km";
	}
	else if(From_choice == MILIMETER && To_choice == INCH)
	{
		Output_number = milimeter_inch(Input_number);
		input_unit = "mm";
		output_unit = "in";
	}
	else if(From_choice == MILIMETER && To_choice == FOOT)
	{
		Output_number = milimeter_foot(Input_number);
		input_unit  = "mm";
		output_unit = "ft";
	}
	else if (From_choice == MILIMETER && To_choice == YARD)
	{
		Output_number = milimeter_yard(Input_number);
		input_unit  = "mm";
		output_unit = "yd";	
	}
	else if(From_choice == MILIMETER && To_choice == MILE)
	{
		Output_number = milimeter_mile(Input_number);
		input_unit = "mm";
		output_unit = "mi";
	}
	//Centimeter Conversion
	else if(From_choice == CENTIMETER && To_choice == CENTIMETER)
	{
		Output_number = Input_number;
		output_unit = "cm";
		input_unit = "cm";
	}
	else if(From_choice == CENTIMETER && To_choice == MILIMETER)
	{
		Output_number = centimeter_milimeter(Input_number);
		input_unit = "cm";
		output_unit = "ml";

	}
	else if(From_choice == CENTIMETER && To_choice == METER)
	{
		Output_number = milimeter_meter(centimeter_milimeter(Input_number));
		input_unit ="cm";
		output_unit ="m";
	}
	else if(From_choice == CENTIMETER && To_choice == KILOMETER)
	{
		Output_number = centimeter_kilometer(Input_number);
		input_unit = "cm";
		output_unit = "km";
	}
	else if(From_choice == CENTIMETER && To_choice == INCH)
	{
		Output_number = centimeter_inch(Input_number);
		input_unit = "cm";
		output_unit = "inch";
	}
	else if(From_choice == CENTIMETER && To_choice == FOOT)
	{
		Output_number = centimeter_foot(Input_number);
		input_unit = "cm";
		output_unit = "ft";
	}
	else if(From_choice == CENTIMETER && To_choice == YARD)
	{
		Output_number = milimeter_yard(centimeter_milimeter(Input_number));
		input_unit = "cm";
		output_unit = "yd";
	}
	else if(From_choice == CENTIMETER && To_choice == MILE)
	{
		Output_number = milimeter_mile(centimeter_milimeter(Input_number));
		input_unit = "cm";
		output_unit = "mi";
	}	
	else if(From_choice == METER && To_choice == METER)
	{
		Output_number = Input_number;
		input_unit = "m";
		output_unit = "m";
	}
	else if(From_choice == METER && To_choice == CENTIMETER)
	{
		Output_number = milimeter_centimeter(meter_milimeter(Input_number));
		input_unit = "m";
		output_unit ="cm";
	}
	else if(From_choice == METER && To_choice == MILIMETER)
	{
		Output_number = meter_milimeter(Input_number);
		input_unit ="m";
		output_unit ="mm";
	}
	else if(From_choice == METER && To_choice == KILOMETER)
	{
		Output_number = milimeter_kilometer(meter_milimeter(Input_number));
		input_unit = "m";
		output_unit = "km";
	}
	else if(From_choice == METER && To_choice == INCH) 
	{
		Output_number = milimeter_inch(meter_milimeter(Input_number));
		input_unit = "m";
		output_unit = "inch";
	}
	else if (From_choice == METER && To_choice == FOOT)
	{	
		Output_number = milimeter_foot(meter_milimeter(Input_number));
		input_unit = "m";
		output_unit = "ft";
	}
	else if(From_choice == METER && To_choice == YARD)
	{
		Output_number = milimeter_yard(meter_milimeter(Input_number));
		input_unit = "m";
		output_unit ="yard";
	}
	else if(From_choice == METER && To_choice == MILE)
	{
		Output_number = milimeter_mile(meter_milimeter(Input_number));
		output_unit = "m";
		input_unit = "mile";
	}
	else if(From_choice == KILOMETER && To_choice == KILOMETER)
	{
		Output_number = Input_number;
		output_unit = "km";
		input_unit = "km";
	}
	else if(From_choice == KILOMETER && To_choice == CENTIMETER)
	{
		Output_number = milimeter_centimeter(kilometer_milimeter(Input_number));
		input_unit = "km";
		output_unit = "cm";
	}
	else if(From_choice == KILOMETER && To_choice == METER)
	{
		Output_number = milimeter_meter(kilometer_milimeter(Input_number));
		input_unit = "km";
		output_unit = "m";
	}
	else if(From_choice == KILOMETER && To_choice == MILIMETER)
	{
		Output_number = kilometer_milimeter(Input_number);
		input_unit = "km";
		output_unit ="mm";
	}
	else if(From_choice == KILOMETER && To_choice == INCH)
	{
		Output_number = milimeter_inch(kilometer_milimeter(Input_number));
		input_unit ="km";
		output_unit = "inch";
	}
	else if(From_choice == KILOMETER && To_choice == FOOT)
	{
		Output_number = milimeter_foot(kilometer_milimeter(Input_number));
		input_unit = "km";
		output_unit = "ft";
	}
	else if (From_choice == KILOMETER && To_choice == YARD)
	{
		Output_number = milimeter_yard(kilometer_milimeter(Input_number));
		input_unit = "km";
		output_unit ="yard";
	}
	else if (From_choice == KILOMETER && To_choice == MILE)
	{
		Output_number = milimeter_mile(kilometer_milimeter(Input_number));
		input_unit  = "km";
		output_unit = "mile";
	}
	else if (From_choice == INCH && To_choice == INCH)
	{
		Output_number = Input_number;
		input_unit ="inch";
		output_unit = "inch";
	}
	else if(From_choice == INCH && To_choice == MILIMETER)
	{
		Output_number = inch_milimeter(Input_number);
		input_unit = "inch";
		output_unit = "milimeter";
	}
	else if(From_choice == INCH && To_choice == CENTIMETER)
	{
		Output_number = milimeter_centimeter(inch_milimeter(Input_number));
		input_unit = "inch";
		output_unit = "cm";
	}
	else if(From_choice == INCH && To_choice == METER)
	{
		Output_number = milimeter_meter(inch_milimeter(Input_number));
		input_unit = "in";
		output_unit = "cm";
	}
	else if(From_choice == INCH && To_choice == KILOMETER)
	{
		Output_number = milimeter_kilometer(inch_milimeter(Input_number));
		input_unit = "inch";
		output_unit = "km";
	}
	else if(From_choice == INCH && To_choice == FOOT)
	{
		Output_number = milimeter_foot(inch_milimeter(Input_number));
		input_unit = "inch";
		output_unit = "km";
	}
	else if(From_choice == INCH && To_choice == YARD)
	{
			Output_number = milimeter_yard(inch_milimeter(Input_number));
			input_unit = "inch";
			output_unit = "yard";
	}
	else if(From_choice == INCH && To_choice == MILE)
	{
		Output_number = milimeter_mile(inch_milimeter(Input_number));
		input_unit = "inch";
		output_unit = "mile";
	}
	else if(From_choice == FOOT && To_choice == FOOT)
	{
		Output_number = Input_number;
		input_unit = "foot";
		output_unit = "foot";
	}	
	else if(From_choice == FOOT && To_choice == CENTIMETER)
	{
		Output_number = milimeter_centimeter(foot_milimeter(Input_number));
		input_unit = "foot";
		output_unit = "cm";
	}
	else if(From_choice == FOOT && To_choice == METER)
	{
		Output_number = milimeter_meter(foot_milimeter(Input_number));
		input_unit = "foot";
		output_unit = "m";
	}
	else if(From_choice == FOOT && To_choice == KILOMETER)
	{
		Output_number = milimeter_meter(foot_milimeter(Input_number));
		input_unit = "foot";
		output_unit = "m";
	}
	else if(From_choice == FOOT && To_choice == INCH)
	{
		 Output_number = milimeter_meter(foot_milimeter(Input_number));
		 input_unit = "foot";
		 output_unit = "inch";
	}
	else if(From_choice == FOOT && To_choice == YARD)
	{
		Output_number = milimeter_yard(foot_milimeter(Input_number));
		input_unit = "foot";
		output_unit = "yard";
	}
	else if(From_choice == FOOT && To_choice  == MILE)
	{
		Output_number = milimeter_mile(foot_milimeter(Input_number));
		input_unit = "foot";
		output_unit = "mile";
	}
	else if(From_choice == YARD && To_choice == YARD)
	{
		Output_number = Input_number;
		input_unit ="yard";
		output_unit = "yard";
	}
	else if(From_choice == YARD && To_choice == MILIMETER)
	{
		Output_number = yard_milimeter(Input_number);
		input_unit = "yard";
		output_unit = "ml";
	}
	else if(From_choice == YARD && To_choice == CENTIMETER)
	{
		Output_number = milimeter_centimeter(yard_milimeter(Input_number));
		input_unit = "yard";
		output_unit ="cm";
	}
	else if(From_choice == YARD && To_choice == METER)
	{
		Output_number = milimeter_centimeter(yard_milimeter(Input_number));
		input_unit = "yard";
		output_unit = "meter";
	}
	else if(From_choice == YARD && To_choice == KILOMETER)
	{
		Output_number = milimeter_kilometer(yard_milimeter(Input_number));
		input_unit ="yard";
		output_unit = "km";
	}
	else if(From_choice == YARD && To_choice == INCH)
	{
		Output_number =  milimeter_inch(yard_milimeter(Input_number));
		input_unit = "yard";
		output_unit = "inch";
	}
	else if(From_choice == YARD && To_choice == FOOT)
	{
		Output_number = milimeter_foot(yard_milimeter(Input_number));
		input_unit ="yard";
		output_unit = "foot";
	}
	else if(From_choice == YARD && To_choice == MILE)
	{
		Output_number = milimeter_mile(yard_milimeter(Input_number));
		input_unit ="yard";
		output_unit ="mile";
	}
	else if(From_choice == MILE && To_choice == MILE)
	{
		Output_number = Input_number;
		input_unit = "yard";
		output_unit ="mile";
	}
	else if(From_choice == MILE && To_choice == MILIMETER)
	{
		Output_number = mile_milimeter(Input_number);
		input_unit ="mile";
		output_unit = "ml";
	}
	else if(From_choice == MILE && To_choice == CENTIMETER)
	{
		Output_number = milimeter_centimeter(mile_milimeter(Input_number));
		input_unit = "mile";
		output_unit = "cm";
	}
	else if(From_choice == MILE && To_choice == METER)
	{
		Output_number = milimeter_meter(mile_milimeter(Input_number));
		input_unit = "mile";
		output_unit = "m";
	}
	else if(From_choice == MILE && To_choice == KILOMETER)
	{
		Output_number = milimeter_kilometer(mile_milimeter(Input_number));
		input_unit ="mile";
		output_unit ="km";
	}
	else if(From_choice == MILE && To_choice == INCH)
	{
		Output_number = milimeter_inch(mile_milimeter(Input_number));
		input_unit = "mile";
		output_unit = "inch";
	}
	else if(From_choice == MILE && To_choice == FOOT)
	{
		Output_number = milimeter_foot(mile_milimeter(Input_number));
		output_unit = "mile";
		input_unit = "foot";
	}
	else if(From_choice == MILE && To_choice == YARD)
	{
		Output_number = milimeter_yard(mile_milimeter(Input_number));
		input_unit = "mile";
		output_unit = "yard";
	}
	printf("%lf(%s) = %lf(%s)\n",Input_number,input_unit,Output_number,output_unit);
	_getch();
	system("cls");
}
double milimeter_centimeter(double milimeter)
{
	return (milimeter/10.0);
}
double milimeter_meter(double milimeter)
{
	return (milimeter/1000.0);
}
double milimeter_kilometer(double milimeter)
{
	return (milimeter/1000000.0);
}
double milimeter_inch(double milimeter)
{
	return (milimeter/25.4);
}
double milimeter_foot(double milimeter)
{
	return (milimeter/304.8);
}
double milimeter_yard(double milimeter)
{
	return (milimeter/914.4);
}
double milimeter_mile(double milimeter)
{
	return (milimeter/1.609e+6);
}
//Centimeter --> other conversion
double centimeter_milimeter(double centimeter)
{
	return (centimeter * 10.0);
}
double centimeter_kilometer(double centimeter)
{
	return (centimeter * 0.00001);
}
double centimeter_inch(double centimeter)
{
	return (centimeter / 2.54);
}
double centimeter_foot(double centimeter)
{
	return (centimeter / 30.48);
}
double meter_milimeter(double meter)
{
	return (meter * 1000.0);
}
double kilometer_milimeter(double kilometer)
{
	return (kilometer * 1000000.0);
}
double inch_milimeter(double inch)
{
	return (inch * 25.4);
}
double foot_milimeter(double foot)
{
	return (foot * 304.8);
}
double yard_milimeter(double yard)
{
	return (yard * 914.4);
}
double mile_milimeter(double mile)
{
	return (mile * 1.609e+6);
}





