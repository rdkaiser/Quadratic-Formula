//*******************************************************
//
//   Given a quadratic equation, find the roots. Also, 
//   print a table of values determined by the user
//
//*******************************************************
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double x1,x2;                                    // roots of the quadratic. values assigned in quad_form(), printed in main()
int coeff_check(double);                         // function to check whether input for coefficients a,b,c are valid
int quad_form(double,double,double);             // updates global variables x1 & x2 for printing in main() and returns the number of real roots for given quadratic.
int IntCheck(double);                            // checks whether a number is an integer

int main (void)
{
    double a,b,c;    // quadratic coefficeints
    int check_sw;    // general purpose working variable
    char ans;        // whether user wants to enter a range of x-values. must be 'y' or 'n'

    cout << "\nFor the quatratic equation y = ax^2 + bx + c, enter the values of a, b, and c";
    cout << "\nNOTE: values must be +-1000000000";

//***********************************************
//  Get value of a & check for proper data type 
//*********************************************** 
	check_sw=0;
	do {
		cout << "\na= "; cin >> a;

	        if(a==0){
	            cout << "A quadratic, by definition, cannot have a zero value for 'a'." << endl;
	            check_sw=0;
	        }
	        else
	            check_sw = coeff_check(a);
	}
	while(check_sw==0);

//*********************************************
// Get value of b & check for proper data type 
//*********************************************
	check_sw=0;
	do {
		cout << "\nb= "; cin >> b;
		check_sw = coeff_check(b);
	}
	while(check_sw==0);

//*********************************************
// Get value of c & check for proper data type 
//*********************************************
	check_sw=0;
	do {
		cout << "\nc= "; cin >> c;
		check_sw = coeff_check(c);
	}
	while(check_sw==0);

//*********************************************
//  Apply the Quadratic Formula
//*********************************************
	check_sw=0;
	check_sw=quad_form(a,b,c);

//*******************************************************
// Print the number of real roots for the given quadratic
//*******************************************************
	switch (check_sw)
    {
        case 0:cout << "The are no real roots." << endl;
                break;
        case 1:cout << setprecision(3) << fixed << "There is only one real root:\nx1 = x2 = " << x1 << endl;
                break;
        case 2:cout << setprecision(3) << fixed << "There are two real roots:\nx1= " << x1 << "\nx2= " << x2 << endl;
                break;
    }

//**************************************************************
// A response of 'n' ends the program. Character input required 
//**************************************************************
    check_sw=0;
    do {
        cout << "\nWould you like to enter a range of x-values for the quadratic equation" << endl;
        cout << "\t\ty = (" << a << ")x^2 + (" << b << ")x + (" << c <<") " << endl;
        cout << "and see a table with the cooresponding y-values? (y/n): ";
        cin >> ans;

        if (ans=='y' || ans=='n')
            check_sw=1;
    }
    while(check_sw==0);


    if (ans=='y') {

        double xmin,xmax;  // allow initial non-integer input, but force if necessary using IntCheck()

        cout << "\nEnter the lower x-value (integer from -100 to 99):" << endl;
        cout << "xmin= ";
        cin >> xmin;

        check_sw=1;
		check_sw=IntCheck(xmin);

//***************************************************
// Only enter the loops if initial input is invalid  
//***************************************************
	while((check_sw==0 || (xmin < -100 || xmin > 99))){
            cout << "\nEnter the lower x-value (integer from -100 to 99):" << endl;
            cout << "xmin= ";
            cin >> xmin;
			check_sw=IntCheck(xmin);
        }

        cout << "\nEnter the upper x-value (integer xmin+1 to 100): " << endl;
        cout << "xmax= " ;
        cin >> xmax;

        check_sw=1;
        check_sw=IntCheck(xmax);

        while((check_sw==0 || (xmax <= xmin || xmax > 100))){
            cout << "\nEnter the upper x-value (integer xmin+1 to 100): " << endl;
            cout << "xmax= ";
            cin >> xmax;
            check_sw=IntCheck(xmax);
        }

//***************************************************
// Print a table of the requested x and y values.  
//***************************************************
        double y;
        double x=0;

        cout << "\nx\t y\n" <<  endl;
        for(x=xmin; x<=xmax; x++){
			y = a*pow(x,2) + (b*x) + c;        
			cout << setprecision(2) << fixed << static_cast<int>(x) << "\t" << y << endl;
        }
    }
return 0;
}

int coeff_check(double coeff)
{
	bool valid;
	if ((coeff >= -1000000000.0) && (coeff <= 1000000000.0))
		valid = true;
	else{
        	valid = false;
       		cout << "ERROR: Invalid Input. Try again" << endl;
       		cout << "Values must be +-1,000,000,000 " << endl;
	}
   	return (valid);
}

 int quad_form(double A, double B, double C)
{
//*************************************************************************************
// Seperate root arguments. If negative, roots are imaginary and the function exits.  
//*************************************************************************************
    double root_args = pow(B,2) - 4 * A * C; 
    double deno = 2 * A;

    int num_roots = 0;

    if (root_args >= 0) {

        x1=0;
        x1 = (-B + sqrt(root_args)) / deno;

        x2=0;
        x2 = (-B - sqrt(root_args)) / deno;

        if(x1 != x2)
            num_roots = 2;
        else
            num_roots = 1;
    }
    else
        num_roots = 0;

    return(num_roots);
}

//*********************************************************
// Returns 1 for an integer, 0 for floating point.
// NOTE: This does not work for invalid character input.
//********************************************************
int IntCheck(double X)
{
    int Xint=static_cast<int>(X);

    if (X-static_cast<double>(Xint) != 0) {
        cout << "\nThat's not an integer." << endl;
        return 0;
    }
    else
        return 1;
}
