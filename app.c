#include<stdio.h>
#include<string.h>
#include<windows.h>
#include<ctype.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>

void welcome();
void login();
void menu();
void addnewalbum();
void editalbum();
void viewalbum();
void deletealbum();
void searchalbum();

struct Album
{
	char year[20];
	char name[30];
	char artist[30];
	float price;
}s;


int main()
{
	welcome();
	login();
}

void welcome()
{
	int i;
	
	time_t t;
	time(&t);
	
	system("COLOR 3F");
	printf("\n");
	printf("\n");
	for(i=0;i<320;i++)
		printf("-");
	printf("\n");
	printf("\n                          *o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*     ");
	printf("\n                          *                                                 *     ");
	printf("\n                          *                                                 *     ");
	printf("\n                          *                   WELCOME TO                    *     ");
	printf("\n                          *                                                 *     ");
	printf("\n                          *              | ALBUM MANAGEMENT |               *     ");
	printf("\n                          *                                                 *     ");
	printf("\n                          *                                                 *     ");
	printf("\n                          *                                                 *     ");
	printf("\n                          *             Press ENTER to continue. .          *     ");
	printf("\n                          *                                                 *     ");
	printf("\n                          *o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*o*     ");
	printf("\n\n");
	

	for(i=0;i<320;i++)
		printf("-");
			printf("\nCurrent date and time : %s",ctime(&t));
		
	
	getchar();
	system("cls");

//	return 0;

}

void login()
{	
	system("cls");
	char name[20];
	char pass[20];
	char Username[20]="Album";
	char Password[20]="mgmt";
	int i,j;
	
	
	printf("\n");
	printf("\n");
	printf("\n"); 
	printf("                        ALBUM MANAGEMENT                         ");
	printf("\n                                                                               ");
	printf("\n                          LOGIN MENU                              ");
	printf("\n                                                                               ");
	printf("\nUsername :  ");
	scanf(" %s", name                );
	printf("\n                                                                               ");
	printf("\nPassword :  ");
	scanf(" %s", pass                );
	
	
	if (strcmp(name,Username) == 0 && strcmp(pass,Password) == 0)
	
	{
		system("cls");
		printf("\n");
		for(i=0;i<160;i++)
		printf("-");
		printf("\n");
		printf("\n"); 
		printf("                         WELCOME USER !                                                ");
		printf("\n                                                                                  ");
		printf("\n                    You are Logged in.                                                    ");
		printf("\n                                                                                           ");
		printf("\n                                                                               ");
		printf("\n                                                                                         ");
		printf("\n           	  Press any key to Continue...                                          ");
		printf("\n\n");
		for(i=0;i<160;i++)
		printf("-");
		getch();
		system("cls");
	}
	
	else
	{
		printf("\n");
		printf("\n");
		printf("\n");
		printf("\n");
		printf("                     SORRY,                                                              ");
		printf("\n                   The Username or the Password is Incorrect.                                         ");
		printf("\n                                                                                   ");
		printf("\n                                           Please Try Again !                         ");
		getch();
		system("cls");
		login();
	}

void menu();
{
	time_t t;
	time(&t);
	int Password;
	char choice;
	system("cls");
	while(1)
	{
		system("COLOR 5F");
		system("cls");
		printf("\n");
		for(i=0;i<80;i++)
		printf("-");
		for(j=0;j<80;j++)
		printf("-");
		for(i=0;i<80;i++)
		printf("-");
		printf("\n");
		printf("\n                             ALBUM MANAGEMENT                         ");
		printf("\n");
		printf("\n                                 *MENU*               ");
		printf("\n\n                       Press  1 :  >> ADD NEW ALBUM                           ");
		printf("\n\n                       Press  2 :  >> EDIT EXISTING ALBUM                     ");
		printf("\n\n                       Press  3 :  >> VIEW ALBUMS                             ");
		printf("\n\n                       Press  4 :  >> SEARCH ALBUMS                           ");
		printf("\n\n                       Press  5 :  >> DELETE ALBUM                            ");
		printf("\n\n                       Press  6 :  >> EXIT.                                   ");
		printf("\n\n");
		for(i=0;i<80;i++)
		printf("-");
	    printf("\nCurrent date and time : %s",ctime(&t));
	    for(i=0;i<80;i++)
		printf("-");
		
		choice=getch();
		choice=toupper(choice);
		switch(choice)
		
		{
			case '1':
				addnewalbum();
				break;
			case '2':
				editalbum();
				break;
			case '3':
				viewalbum();
				break;
            case '4':
				searchalbum();
				break;
			case '5':
				deletealbum();
				break;
			case '6':
				system("cls");
				printf("\n\n                      :-)  THANK YOU !!                                     ");
				Sleep(2000);
				exit(0);
				break;
			default:
 				system("cls");
				printf("INVALID KEYWORD. PLEASE ENTER A VALID KEYWORD TO CHOOSE. ");
				printf("\nPRESs any key to continue..........");
				getch();
		}
	}
}
}

void addnewalbum()
{
	FILE *Album;
	char test;
	Album=fopen("Album.txt","a");
	if(Album==0)
	{
		Album=fopen("Album.txt","w");
		system("cls");
		getch();
	}
	while(1)
	{
		system("cls");
		printf("\nEnter Album Name: ");
		fflush(stdin);
		scanf("%[^\n]",&s.name);	
		printf("\nEnter Album Year: ");
		scanf("%s",&s.year);
		printf("\nEnter Album Artist: ");
		fflush(stdin);
		scanf("%[^\n]",&s.artist);
		printf("\nEnter Album Price: ");
		scanf("%f",&s.price);
		fwrite(&s,sizeof(s),1,Album);
		fflush(stdin);
		system("cls");
		
		printf("\n\n");
		printf("   * The Album is Successfully recorded. \n\n");
		printf("\n     * Press any Key to Continue ");
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n                                 Press ESC to return back to < MAIN MENU >");
		test=getche();
		if(test==27)
			break;
	}
	fclose(Album);
}

