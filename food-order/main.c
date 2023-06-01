#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void mainMenu(void);

void checkPassword(void);
void administrator(void);
void addRecord(void);
void deleteRecord(void);
//  void viewRecord(void);
void customer(void);

void vegetarian(void);
void nonVegetarian(void);
void beverages(void);

void details(void);
bool password(void);

int getData();
void returnFunc(void);

struct employee
{
    char name[30];
    int id;
    int dd, mm, yyyy;
    int YOJ;
    char place[20];
    char department[20];

    int quantity;
};

struct employee emp;

FILE *fp,*ft,*dp,*dt;

int s;
char findRecord;
int again;
int quantity;
double total = 0;
int t;

int main()
{
    mainMenu();
    return 0;
}

void mainMenu(void)          // Main Menu Function
{
	system("cls");
	printf("                       **************************************************************************\n");
	printf("                                                 WELCOME TO QWIK ORDER\n");
	printf("                       **************************************************************************\n\n\n");
	printf("          1. ADMINISTRATOR --> \n\n          2. CUSTOMER --> \n\n          3. EXIT --> \n\n\n             Enter Your Choice ---> ");
	int choice;
	scanf("%d", &choice);
	if(choice==1)
	{
		checkPassword();
	}
	else if(choice==2)
	{
		customer();
	}
	else if(choice==3)
	{
		system("cls");
		exit(0);
	}
}

void administrator(void)          // Administrator Function
{
    system("cls");
        printf("               *********************** HELLO ADMIN ******************************\n\n");
        printf("          1. Add New Record\n\n          2. Delete Record\n\n          3. Back To Main Menu \n\n             Enter Your Choice ---> ");
        int n;
        scanf("%d", &n);
		printf("\n\n");
        int wait;
        //printf("In progress :");
        for(wait=0;wait<=10000;wait++)
        {
            printf("\rIn progress : %d", wait/100);
        }
        printf("\n\n");
        if(n==1)
        {
    		addRecord();
        }
        else if(n==2)
        {
            deleteRecord();
        }
        else if(n==3)
        {
            system("cls");
            mainMenu();
        }
        else
        {
            printf("Wrong Input !! PLease Re-enter The Correct Option");
            if(getch())
            administrator();
        }
}

void addRecord(void)          // Add Record Function
{
	system("cls");
	fp=fopen("record1.txt","a");
	if(getData()==1)
	{
		fseek(fp,0,SEEK_END);
		fwrite(&emp,sizeof(emp),1,fp);
		fclose(fp);
		printf("\n\n");
		printf("Record Added Successfully!!!\n\n");
		printf("Save any more?(y / n): ");
		if(getch()=='n')
	    	administrator();
		else
	    	system("cls");
	    	addRecord();
	}
}

void deleteRecord(void)          // Delete Record Function
{
	system("cls");
    int recordID;
    char another='y';
    while(another=='y')  //infinite loop
    {
	system("cls");
	printf("                Enter Record ID To Delete: ");
	scanf(" %d", &recordID);
	fp=fopen("record1.txt","r+");
	rewind(fp);
	while(fread(&emp, sizeof(emp),1,fp)==1)
	{
	    if(emp.id==recordID)
	    {
			printf("\n\n");
			printf("                               .....................Employee Record Found....................\n\n");
			printf("               Employee Name Is %s\n\n",emp.name);
//			printf("               Employee's Date  OF Birth Is %d/%d/%d\n\n",e.dd,e.mm,e.yyyy);
			findRecord='t';
	    }
	}
	if(findRecord!='t')
	{
	    printf("\n\n");
	    printf("                     ......................No Record Found With ID: %d......................\n\n", recordID);
	    printf("                     Press Enter to Return...\n\n");
	    if(getch())
	    administrator();
	}
	if(findRecord=='t' )
	{
	    printf("Do You Want To Delete THe Record ? (Y/N) ");
	    if(getch()=='y')
	    {
			ft=fopen("test1.txt","w");  //temporary file for delete
			rewind(fp);
			while(fread(&emp,sizeof(emp),1,fp)==1)
			{
		    	if(emp.id!=recordID)
		    	{
					fseek(ft,0,SEEK_CUR);
					fwrite(&emp,sizeof(emp),1,ft); //write all in tempory file except that
		    	}                              //we want to delete
			}
			fclose(ft);
			fclose(fp);
			remove("record1.txt");
			rename("test1.txt", "record1.txt"); //copy all item from temporary file to fp except that
			fp=fopen("record1.txt", "r");    //we want to delete
			if(findRecord=='t')
			{
		    	printf("        RECORD SUCCESSFULLY DELETED!!!.\n\n");
		    	printf("        Delete Another Record ? (Y/N): ");
			}
	    }
		else
		administrator();
		fflush(stdin);
		another=getch();
	}
}
administrator();
}

void viewRecord(void) {}       // viewRecord Function

void checkPassword(void)       // checkPassword Function
{
	bool passwordCorrect = password();

	if (passwordCorrect)
    {
        administrator();
    }
    else  // Wrong Password
    {
        system("cls");
        checkPassword();
    }
}

void customer(void)          // Customer Function
{
	system("cls");
	printf("                    *******************************************\n                                    FOOD MENU\n                    *******************************************\n\n");
	printf("               1. Vegetarian\n\n               2. Non-Vegetarian\n\n               3. Beverages\n\n               4. Back to Main Menu\n\n                    Enter Your Choice  --> ");
	int k;
	scanf("%d", &k);
		int load;
	printf("In progress :");
	for(load=0;load<=50000;load++)
	{
		printf("\rIn progress : %d", load/500);
	}
	if(k==1)
	{
		system("cls");
		vegetarian();
	}
	else if(k==2)
	{
		system("cls");
		nonVegetarian();
	}
	else if(k==3)
	{
		system("cls");
		beverages();
	}
	else if(k==4)
	{
		system("cls");
		mainMenu();
	}
	else
	{
		printf("Wrong Input !Please Re-enter The Correct Option......\n\n");
		customer();
	}
}

void vegetarian(void)          // Vegetarian Function
{
	int choice;
	int again;
	int quantity;

	double price=0;

	printf("                    ****************************************\n                                  VEGETARIAN MENU\n                    ****************************************\n\n");
	//     Menu From File is Displayed Here
	char v;
	FILE *vmenu;

    vmenu=fopen("vegmenu.txt" ,"rt");
	while((v=getc(vmenu))!=EOF)
        {
        	printf("%c",v);
		}
         fclose(vmenu);
    printf("\n\nEnter What You Want: ");
	scanf("%d", &choice);
	if(choice==1)
	{
		printf("Quantity:  ");
		scanf("%d", &quantity);
		total = total + 40*(quantity);
		printf("\n");
		printf("          Press 1 To Order Again :\n          Press 2 To Get Your Total:\n\n          Enter Your Choice: ");
		scanf("%d", &again);
		printf("\n");
		if(again==1)
		{
			printf("\n\n");
			vegetarian();
		}
		else if(again==2)
		{
			printf("          Your Total Amount Is : ø. %.2lf\n\n", total);
			int totl = total;
			FILE *ttl;
			ttl = fopen("order.txt","a");
			fprintf(ttl,"\nGrand Total : %d\n", totl);
			fclose(ttl);

			details();
		}
	}
	else if(choice==2)
	{
		printf("Quantity :");
		scanf("%d", &quantity);
		total=total + 60*(quantity);
		printf("          Press 1 To Order Again :\n          Press 2 To Get Your Total:\n\n          Enter Your Choice: ");
		scanf("%d", &again);
		if(again==1)
		{
			printf("\n\n");
			vegetarian();
		}
		else if(again==2)
		{
			printf("         Your Total Amount Is: $. %.2lf\n\n", total);
			int totl = total;
			FILE *ttl;
			ttl = fopen("order.txt","a");
			fprintf(ttl,"\nGrand Total: %d\n", totl);
			fclose(ttl);

			details();
		}
	}
	else if(choice==3)
	{
		printf("Quantity :  ");
		scanf("%d", &quantity);
		total=total + 60*(quantity);
		printf("          Press 1 To Order Again :\n          Press 2 To Get Your Total:\n\n          Enter Your Choice: ");
		scanf("%d", &again);
		if(again==1)
		{
			printf("\n\n");
			vegetarian();
		}
		else if(again==2)
		{
			printf("          Your Total Amount Is: $. %.2lf\n\n", total);
			int totl = total;
			FILE *ttl;
			ttl = fopen("order.txt","a");
			fprintf(ttl,"\nGrand Total: %d\n", totl);
			fclose(ttl);

			details();
		}
	}
	else if(choice==4)
	{
		printf("Quantity :");
		scanf("%d", &quantity);
		total=total + 45*(quantity);
		printf("          Press 1 To Order Again :\n          Press 2 To Get Your Total:\n\n          Enter Your Choice: ");
		scanf("%d", &again);
		if(again==1)
		{
			printf("\n\n");
			vegetarian();
		}
		else if(again==2)
		{
			printf("         Your Total Amount Is : $. %.2lf\n\n", total);
			int totl = total;
			FILE *ttl;
			ttl = fopen("order.txt", "a");
			fprintf(ttl,"\nGrand Total: %d\n", totl);
			fclose(ttl);

			details();
		}
	}
	else if(choice==5)
	{
		printf("Quantity :");
		scanf("%d", &quantity);
		total=total + 35*(quantity);
		printf("          Press 1 To Order Again :\n          Press 2 To Get Your Total:\n\n          Enter Your Choice: ");
		scanf("%d",&again);
		if(again==1)
		{
			printf("\n\n");
			vegetarian();
		}
		else if(again==2)
		{
			printf("          Your Total Amount Is : $. %.2lf\n\n", total);
			int totl = total;
			FILE *ttl;
			ttl = fopen("order.txt", "a");
			fprintf(ttl,"\nGrand Total: %d\n", totl);
			fclose(ttl);

			details();
		}

	}
	else if(choice==6)
	{
		printf("Quantity :");
		scanf("%d", &quantity);
		total=total + 150*(quantity);
		printf("          Press 1 To Order Again :\n          Press 2 To Get Your Total:\n\n          Enter Your Choice: ");
		scanf("%d",&again);
		if(again==1)
		{
			printf("\n\n");
			vegetarian();
		}
		else if(again==2)
		{
			printf("          Your Total Amount Is : $. %.2lf\n\n", total);
			int totl = total;
			FILE *ttl;
			ttl = fopen("order.txt", "a");
			fprintf(ttl,"\nGrand Total: %d\n", totl);
			fclose(ttl);

			details();
		}

	}
	else if(choice==7)
	{
		system("cls");
	//	customer();
	}
	else
	{
		printf("Wrong Input! Re-enter THe Correct Option\n\n");
		if(getch())
		vegetarian();
	}
}

void nonVegetarian(void)                    // Non Vegetarian Function
{
    int choice, again, quantity;
	double price=0;
	printf("                                    **********************************************\n");
	printf("                                                  Non-Veg. Menu\n");
	printf("                                    **********************************************\n");
    //	Menu from Non Veg. is Displayed Here
	char n;
	FILE *nmenu;
	nmenu = fopen("nonveg.txt","rt");
	while((n=getc(nmenu))!=EOF)
	{
		printf("%c", n);
	}
	printf("\n\n       Enter What You Want: ");
	scanf("%d", &choice);
	if(choice==1)
	{
		printf("       Quantity : ");
		scanf(" %d", &quantity);
		total=total + 150*(quantity);
		printf("\n");
		printf("          Press 1 To Order Again :\n          Press 2 To Get Your Total:\n\n          Enter Your Choice: ");
		scanf(" %d", &again);
		if(again==1)
		{
			printf("\n\n");
			nonVegetarian();
		}
		else if(again==2)
		{
			printf("         Your Total Amount Is: $%.2lf\n\n", total);
			int totl = total;
			FILE *ttl;
			ttl = fopen("order.txt", "a");
			fprintf(ttl,"\nGrand Total: %d\n", totl);
			fclose(ttl);
			details();
		}
	}
	else if(choice==2)
	{
		printf("       Quantity :");
		scanf(" %d", &quantity);
		total=total + 200*(quantity);
		printf("\n");
		printf("          Press 1 To Order Again :\n          Press 2 To Get Your Total:\n\n          Enter Your Choice: ");
		scanf(" %d", &again);
		if(again==1)
		{
			printf("\n\n");
			nonVegetarian();
		}
		else if(again==2)
		{
			printf("          Your Total Amount Is: $%.2lf\n\n", total);
			int totl = total;
			FILE *ttl;
			ttl = fopen("order.txt", "a");
			fprintf(ttl,"\nGrand Total: %d\n", totl);
			fclose(ttl);
			details();
		}
	}
	else if(choice==3)
	{
		printf("       Quantity :");
		scanf(" %d", &quantity);
		total=total + 110*(quantity);
		printf("\n");
		printf("          Press 1 To Order Again :\n          Press 2 To Get Your Total:\n\n          Enter Your Choice: ");
		scanf(" %d",&again);
		if(again==1)
		{
			printf("\n\n");
			nonVegetarian();
		}
		else if(again==2)
		{
			printf("          Your Total Amount Is: $%.2lf\n\n", total);
			int totl = total;
			FILE *ttl;
			ttl = fopen("order.txt","a");
			fprintf(ttl,"\nGrand Total: $%d\n", totl);
			fclose(ttl);
			details();
		}
	}
	else if(choice==4)
	{
		printf("       Quantity :");
		scanf(" %d", &quantity);
		total=total + 30*(quantity);
		printf("\n");
		printf("          Press 1 To Order Again :\n          Press 2 To Get Your Total:\n\n          Enter Your Choice: ");
		scanf(" %d", &again);
		if(again==1)
		{
			printf("\n\n");
			nonVegetarian();
		}
		else if(again==2)
		{
			printf("          Your Total Amount Is: $%.2lf\n\n", total);
			int totl = total;
			FILE *ttl;
			ttl = fopen("order.txt","a");
			fprintf(ttl,"\nGrand Total: $%d\n", totl);
			fclose(ttl);
			details();
		}
	}
	else if(choice==5)
	{
		printf("       Quantity :");
		scanf(" %d", &quantity);
		total=total + 20*(quantity);
		printf("\n");
		printf("          Press 1 To Order Again :\n          Press 2 To Get Your Total:\n\n          Enter Your Choice: ");
		scanf(" %d", &again);
		if(again==1)
		{
			printf("\n\n");
			nonVegetarian();
		}
		else if(again==2)
		{
			printf("          Your Total Amount Is: $%.2lf\n\n", total);
			int totl = total;
			FILE *ttl;
			ttl = fopen("order.txt","a");
			fprintf(ttl,"\nGrand Total: $%d\n", totl);
			fclose(ttl);
			details();
		}
	}
	else if(choice==6)
	{
		printf("       Quantity :");
		scanf(" %d", &quantity);
		total=total + 150*(quantity);
		printf("\n");
		printf("          Press 1 To Order Again :\n          Press 2 To Get Your Total:\n\n          Enter Your Choice: ");
		scanf(" %d", &again);
		if(again==1)
		{
			printf("\n\n");
			nonVegetarian();
		}
		else if(again==2)
		{
			printf("          Your Total Amount Is: $%.2lf\n\n", total);
			int totl = total;
			FILE *ttl;
			ttl = fopen("order.txt","a");
			fprintf(ttl,"\nGrand Total: $%d\n", totl);
			fclose(ttl);
			details();
		}
	}
	else if(choice==7)
	{
		printf("       Quantity :");
		scanf(" %d", &quantity);
		total=total + 300*(quantity);
		printf("\n");
		printf("          Press 1 To Order Again :\n          Press 2 To Get Your Total:\n\n          Enter Your Choice: ");
		scanf(" %d", &again);
		if(again==1)
		{
			printf("\n\n");
			nonVegetarian();
		}
		else if(again==2)
		{
			printf("          Your Total Amount Is: $%.2lf\n\n", total);
			int totl = total;
			FILE *ttl;
			ttl = fopen("order.txt","a");
			fprintf(ttl,"\nGrand Total: $%d\n", totl);
			fclose(ttl);
			details();
		}
	}
	else if(choice==8)
	{
		printf("       Quantity :");
		scanf(" %d", &quantity);
		total=total + 150*(quantity);
		printf("\n");
		printf("          Press 1 To Order Again :\n          Press 2 To Get Your Total:\n\n          Enter Your Choice: ");
		scanf(" %d", &again);
		if(again==1)
		{
			printf("\n\n");
			nonVegetarian();
		}
		else if(again==2)
		{
			printf("          Your Total Amount Is: $%.2lf\n\n", total);
			int totl = total;
			FILE *ttl;
			ttl = fopen("order.txt","a");
			fprintf(ttl,"\nGrand Total: $%d\n", totl);
			fclose(ttl);
			details();
		}
	}
	else if(choice==9)
	{
		system("cls");
		customer();
	}
	else
	{
		printf("Wrong Input! Re-enter THe Correct Option\n\n");
		nonVegetarian();
	}
}

void beverages(void)                    // Beverages Function
{
    int choice, again, quantity;
	double price=0;
	printf("                                    **********************************************\n");
	printf("                                                  Beverage Menu\n");
	printf("                                    **********************************************\n");
     //	Display Menu Items From Beverages File
	char n;
	FILE *nmenu;
	nmenu = fopen("beverages.txt", "rt");
	while((n=getc(nmenu))!=EOF)
	{
		printf("%c", n);
	}
	printf("\n\n          Enter What You Want: ");
	scanf("%d",&choice);
	if(choice==1)
	{
		printf("          Quantity: ");
		scanf(" %d", &quantity);
		total=total + 100*(quantity);
		printf("\n");
		printf("          Press 1 To Order Again :\n          Press 2 To Get Your Total:\n\n          Enter Your Choice: ");
		scanf(" %d", &again);
		if(again==1)
		{
			printf("\n\n");
			beverages();
		}
		else if(again==2)
		{
			printf("          Your Total Amount Is: $%.2lf\n\n", total);
			int totl = total;
			FILE *ttl;
			ttl = fopen("order.txt", "a");
			fprintf(ttl,"\nGrand Total: $%d\n", totl);
			fclose(ttl);
			details();
		}
	}
	else if(choice==2)
	{
		printf("          Quantity: ");
		scanf(" %d", &quantity);
		total=total + 120*(quantity);
		printf("\n");
		printf("          Press 1 To Order Again :\n          Press 2 To Get Your Total:\n\n          Enter Your Choice: ");
		scanf(" %d", &again);
		if(again==1)
		{
			printf("\n\n");
			beverages();
		}
		else if(again==2)
		{
			printf("          Your Total Amount Is: $%.2lf\n\n", total);
			int totl = total;
			FILE *ttl;
			ttl = fopen("order.txt","a");
			fprintf(ttl,"\nGrand Total: $%d\n", totl);
			fclose(ttl);
			details();
		}
	}
	else if(choice==3)
	{
		printf("          Quantity :");
		scanf(" %d", &quantity);
		total=total + 85*(quantity);
		printf("\n");
		printf("          Press 1 To Order Again :\n          Press 2 To Get Your Total:\n\n          Enter Your Choice: ");
		scanf(" %d", &again);
		if(again==1)
		{
			printf("\n\n");
			beverages();
		}
		else if(again==2)
		{
			printf("          Your Total Amount Is: $%.2lf\n\n", total);
			int totl = total;
			FILE *ttl;
			ttl = fopen("order.txt", "a");
			fprintf(ttl,"\nGrand Total: $%d\n", totl);
			fclose(ttl);
			details();
		}
	}
	else if(choice==4)
	{
		printf("          Quantity :");
		scanf(" %d",&quantity);
		total = total + 35*(quantity);
		printf("\n");
		printf("          Press 1 To Order Again :\n          Press 2 To Get Your Total:\n\n          Enter Your Choice: ");
		scanf(" %d",&again);
		if(again==1)
		{
			printf("\n\n");
			beverages();
		}
		else if(again==2)
		{
			printf("          Your Total Amount Is: $%.2lf\n\n", total);
			int totl = total;
			FILE *ttl;
			ttl = fopen("order.txt","a");
			fprintf(ttl,"\nGrand Total: $%d\n", totl);
			fclose(ttl);
			details();
		}
	}
	else if(choice==5)
	{
		system("cls");
		customer();
	}
	else
	{
		printf("Wrong Input! Re-enter The Correct Option\n\n");
		beverages();
	}
}

void details(void)              // Customer Details
{
	char name1[20], name2[20];
	long long int phone;
	char address[40], landmark[30];
	printf("       Please Give Your Contact Details \n");
	printf("       First Name : ");
	scanf("%s", name1);
	printf("       Last Name : ");
	scanf("%s", name2);
	printf("       Phone : ");
	scanf("%lld",&phone);
	printf("       Address : ");
	scanf("%s", address);
	printf("       Landmark : ");
	scanf("%s", landmark);
	printf("\n\n");
	printf("       Your Entered Details Are:....\n");
	FILE *cust;
	cust = fopen("order.txt","a");
	fprintf(cust,"Order Placed By : %s %s\nPhone number : %lld\n", name1, name2, phone);
	fclose(cust);
	printf("    --> First Name :  %s\n    --> Last Name   :  %s\n    --> Phone     :%lld \n    --> Address  :%s \n    --> Landmark  :%s \n", name1, name2, phone, address, landmark);
	printf("\n\n\n");
	printf("                       *********************************************************************************************\n");
	printf("                                             Your Order Will Be At Your Door In 30 minutes.\n");
	printf("                                                       .....THANK YOU FOR CHOOSING US.....\n");
	printf("                       *********************************************************************************************\n");

	printf("Press Any Key To Return To The main Menu.");
	if(getch())
	customer();
}

bool password(void)     // Password Function
{
    system("cls");
    int pin;
    printf("             ***************** Enter PIN: ******************\n\n");
    scanf("%d", &pin);

    if(pin==1234)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int checkid(int c)  //check whether the record is exist in list or not
{
	rewind(fp);
	while(fread(&emp, sizeof(emp), 1, fp)==1)
	if(emp.id==c)

	return 0;  //returns 0 if employee exits

	return 1; //return 1 if it not
}

int getData()
{
	//*int t;
	printf("        Employee ID :\t");
	scanf("%d", &t);
	if(checkid(t)==0)
	{
		printf("\n\n");
		printf("\a                        The Employee Record Already Exists !!!\a");
		getch();
		mainMenu();
		return 0;
	}
	emp.id = t;
	printf("        Employee Name : ");
	scanf("%s", emp.name);
	printf("        Department :");
	scanf("%s", emp.department);
	return 1;
}

void returnFunc(void)
{
    {
		printf(" Press ENTER to return to main menu");
    }
    e:
    if(getch()==13) //allow only use of enter
    administrator();
    else
    goto e;
}
