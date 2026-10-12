#include <iostream>
#include <string.h>
#include <cctype>
#include <iomanip>
using namespace std;

//function prototypes
void laundryMenu();
float price_laundryWeight(int);
float priceLaundry_DryClean(char temp);

//constant
const int size = 6;
const int sizes = 2;

//global variable
string ID[sizes] = {"1234567890", "1111111111"};
string password[sizes] = {"demo123", "demo456"};


//function definition before main
void opening()
{
	cout<<" _________________________________________________________________________"<<endl;
	cout<<"||               WELCOME TO UITM ARAU LAUNDRY PICKUP SERVICE             ||"<<endl;
	cout<<"||_______________________________________________________________________||"<<endl;
}

void loadingscreen()
{
	cout<<" __________________________________________________________________________"<<endl;
	cout<<"||                         PROCESSING YOUR ORDER....                      ||"<<endl;
	cout<<"||________________________________________________________________________||"<<endl;
}

void closing()
{
	cout<<" __________________________________________________________________________"<<endl;
	cout<<"||               THANK YOU FOR USING UITM ARAU LAUNDRY SERVICE            ||"<<endl;
	cout<<"||                    YOUR LAUNDRY WILL BE PICKED UP SOON!                ||"<<endl;
	cout<<"||                 -WE HAVE PREPARE A RECEIPT FOR YOUR ORDER-             ||"<<endl;
	cout<<"||________________________________________________________________________||"<<endl;
}

void receipt(string id, string cr, string nameService, float tp)
{
	cout<<" --------------------------------------------------------------------------"<<endl;
	cout<<" __________________________________________________________________________"<<endl;
	cout<<"||                    ~RECEIPT UITM ARAU LAUNDRY SERVICE~                 ||"<<endl;
	cout<<"||________________________________________________________________________||"<<endl;
	cout<<" --------------------------------------------------------------------------"<<endl;
	cout<<"                            STUDENT ID : "<<id<<endl;
	cout<<"                   COLLEGE RESIDENTIAL : "<<cr<<endl;
	cout<<"                       TYPE OF SERVICE : "<<nameService<<endl;
	cout<<fixed<<showpoint;
	cout<<"                         TOTAL PAYMENT : RM"<<setprecision(2)<<tp<<endl;
	cout<<" --------------------------------------------------------------------------"<<endl;
	cout<<"               PLEASE PAY USING CASH ONLY, PROVIDE ENOUGH MONEY   "<<endl;
	cout<<" --------------------------------------------------------------------------"<<endl;
}

void reminder()
{
	cout<<" __________________________________________________________________________"<<endl;
	cout<<"||!! PLEASE MAKE SURE THAT YOUR LAUNDRY BAGS HAVE YOUR STUDENT ID         ||"<<endl;
	cout<<"||!! ARRANGE YOUR LAUNDRY BAGS IN THE GIVEN SPACE THAT WE PROVIDED        ||"<<endl;
	cout<<"||________________________________________________________________________||"<<endl;
}

//main function
int main() 
{
	cout<<" _________________________________________________________________________"<<endl;
	cout<<"||                      UITM ARAU LAUNDRY PICKUP SERVICE                 ||"<<endl;
	cout<<"||***********************************************************************||"<<endl;
	cout<<"||                  PLEASE ENTER YOUR STUDENT ID & PASSWORD              ||"<<endl;
	cout<<"||_______________________________________________________________________||"<<endl;
    
	//login system
	string studentID, pass;
	bool loggedIn = false;
	while(!loggedIn) 
	{
		cout<<">>>>> STUDENT ID: ";
		cin>>studentID;
		cout<<">>>>> PASSWORD: ";
		cin>>pass;
		
		//to check whether the ID is digit by checking every character
		bool isDigits = true;
		int len = studentID.length();
		for(int i = 0; i < len; i++) 
		{
			if(!isdigit(studentID[i])) 
			{
		    	isDigits = false;
		    	break;
			}
		}
		
		//check whether ID and password are inside database
		if(isDigits) 
		{
			for(int index = 0; index < sizes; index++)
			{
				if(studentID == ID[index] && pass == password[index]) 
				{
					studentID = ID[index];
					opening();
					loggedIn = true;
					break;
				}
			}	
		}
		
		if(!loggedIn) 
			cout<<"LOGIN FAILED! PLEASE TRY AGAIN."<<endl;
	}   
    
	//input
	int college;
	cout<<"\n>>>>> COLLEGE RESIDENTIAL (1-DAHLIA / 2-CENGAL / 3-KESINAI): ";
	cin>>college;
	
	//for display purposes
	string college_name;
	if(college == 1)
		college_name = "DAHLIA";
	else if(college == 2)
		college_name = "CENGAL";
	else if(college == 3)
		college_name = "KESINAI";
	
	cout<<endl;
	laundryMenu();
	cout<<endl;
	
	int service;
	cout<<">>>>> ENTER CODE FOR TYPE OF SERVICE: ";
	cin>>service;
	
	int weight_kg;
	cout<<">>>>> ENTER YOUR LAUNDRY WEIGHTAGE(KG): ";
	cin>>weight_kg;
	
	string name_service;
	char tempLaundry, tempDry;
	float temp_price, price1, price2;
	if(service == 1)
	{
		name_service = "LAUNDRY";
		
		cout<<">>>>> ENTER CODE TEMPERATURE FOR LAUNDRY: ";
		cin>>tempLaundry;
		temp_price = priceLaundry_DryClean(tempLaundry);
	}
	else if(service == 2)
	{
		name_service = "DRY-CLEANING";
		
		cout<<">>>>> ENTER CODE TEMPERATURE FOR DRY-CLEANING: ";
		cin>>tempDry;
		temp_price = priceLaundry_DryClean(tempDry);
	}
	else if(service == 3)
	{
		name_service = "LAUNDRY & DRY-CLEANING";
		
		cout<<">>>>> ENTER CODE TEMPERATURE FOR LAUNDRY: ";
		cin>>tempLaundry;
		price1 = priceLaundry_DryClean(tempLaundry);
		
		cout<<">>>>> ENTER CODE TEMPERATURE FOR DRY-CLEANING: ";
		cin>>tempDry;
		price2 = priceLaundry_DryClean(tempDry);
		
		temp_price = price1 + price2;
	}
	
	//calculate the total payment
	float laundry_price = price_laundryWeight(weight_kg);
	float totalPayment = laundry_price + temp_price;
	
	cout<<endl;
	loadingscreen();
	cout<<endl;
	closing();
	
	receipt(studentID, college_name, name_service, totalPayment);
	reminder();
}


//function definition after main
void laundryMenu()
{
	cout<<"======================LAUNDRY AND DRY CLEANING SERVICE======================"<<endl;
	cout<<"                   ___________________________________"<<endl;
	cout<<"                  |  CODE |  TYPE OF SERVICE PROVIDED |"<<endl;
	cout<<"                  |-------+---------------------------|"<<endl;
	cout<<"                  |   1   |        LAUNDRY ONLY       |"<<endl;
	cout<<"                  |   2   |     DRY-CLEANING ONLY     |"<<endl;
	cout<<"                  |   3   |  LAUNDRY & DRY-CLEANING   |"<<endl;
	cout<<"                  |_______|___________________________|"<<endl;
	cout<<endl;
	cout<<"                            __________________"<<endl;
	cout<<"                           |LAUNDRY WEIGHTAGE |"<<endl;
	cout<<"                           |------------------|"<<endl;
	cout<<"                           |5 KG   -  RM 3.00 |"<<endl;
	cout<<"                           |10 KG  -  RM 3.50 |"<<endl;
	cout<<"                           |15 KG  -  RM 4.00 |"<<endl;
	cout<<"                           |20 KG  -  RM 4.50 |"<<endl;
	cout<<"                           |25 KG  -  RM 5.00 |"<<endl;
	cout<<"                           |30 KG  -  RM 5.50 |"<<endl;
	cout<<"                           |__________________|"<<endl;
	cout<<"                       # 1 laundry bag = 5 kg only"<<endl;
	cout<<endl;
	cout<<"             ________________________________________________"<<endl;
	cout<<"            |                   TEMPERATURE                  |"<<endl;
	cout<<"            |------------------------+-----------------------|"<<endl;
	cout<<"            |      LAUNDRY ONLY      |   DRY-CLEANING ONLY   |"<<endl;
	cout<<"            |------------------------+-----------------------|"<<endl;
	cout<<"            |(A)COLD  -  RM4.00      |(A)LOW     -  RM4.00   |"<<endl;
	cout<<"            |(B)WARM  -  RM5.00      |(B)MEDIUM  -  RM5.00   |"<<endl;
	cout<<"            |(C)HOT   -  RM6.00      |(C)HIGH    -  RM6.00   |"<<endl;
	cout<<"            |________________________|_______________________|"<<endl;
}

float price_laundryWeight(int weightKG)
{
	//for laundry weightage
	int weight[size] = {5,10,15,20,25,30};
	float price;
	for(int index = 0; index < size; index++)
	{
		if(weightKG == weight[index])
		{
			//price for laundry
			switch(weightKG)
			{
				case 5 :
					price = 3.00;
					break;
				case 10 :
					price = 3.50;
					break;
				case 15 :
					price = 4.00;
					break;
				case 20 :
					price = 4.50;
					break;
				case 25 :
					price = 5.00;
					break;
				case 30 :
					price = 5.50;
					break;
				default :
					price = 0;
			}
		}
	}
	return price;
}

float priceLaundry_DryClean(char temp)
{
	// price for laundry and dry cleaning
	float price;
	switch(temp)
	{
		case 'A':
		case 'a':
			price = 4.00;
			break;
		case 'B':
		case 'b':
			price = 5.00;
			break;
		case 'C':
		case 'c':
			price = 6.00;
			break;
		default :
			price = 0;
	}
		
	return price;
}

