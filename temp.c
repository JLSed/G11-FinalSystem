#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


void reportsIntro();
void reports();

void officerMain();

void attendance();
void attendanceMain();
void intro();

int main()
{
    const char USER[] = "admin";
    const char PASSWORD[] = "pass"; 
    char userin[10];
    char passwordin[15]; 
    bool login;

    printf("\nBARANGAY 171 POLICE SAFETY OFFICER LOGGING SYSTEM\n");
    printf("\nAdmin Login\n");
    do
    {
        login = false;
        printf("Name: ");
        scanf("%s", &userin);
        int compname = strcmp(userin, USER);
        printf("Password: ");
        scanf("%s", &passwordin);
        int comppass = strcmp(passwordin, PASSWORD);
        if (compname == 0 && comppass == 0)
        {
            login = true;
        }
        else
        {
            printf("\nLog in Failed\n");
        }
    } while(login == false);    

    do
    {
    intro();
    const char A[] = "attendance";
    const char B[] = "officers";
    const char C[] = "reports";
    const char D[] = "logout";
    const char BACK[] = "back";
    char chr[20];
    int chrcomp;
    printf(":");
    scanf("%s", &chr);
    strlwr(chr);
    if (strlen(chr) == 10)
    {
        chrcomp = strcmp(chr, A);
    }
    else if (strlen(chr) == 8)
    {
        chrcomp = strcmp(chr, B);
    }
    else if (strlen(chr) == 7)
    {
        chrcomp = strcmp(chr, C);
    }
    else if (strlen(chr) == 6)
    {
        chrcomp = strcmp(chr, D);
    }
        char bck[20];
        //ATTENDANCE//
        if(chrcomp == 0&&strlen(chr) == 10)
        {
            const char tin[] = "time in";
            const char tout[] = "time out";
            const char inWork[] = "currently in work";
            login = false;
            char atnchr[10];
            char time[10];
            bool attendanceOnline;
            int attendanceFalse;
            fgetc(stdin);
            do
            {
            attendanceOnline = false;
            attendance();
            fgets(bck, 20, stdin);
            bck[strlen(bck)-1] = '\0';
                strlwr(bck);
                chrcomp = strcmp(bck, BACK);
                if (chrcomp == 0&&strlen(bck) == 4)
                {
                    login = true;
                    attendanceOnline = false;
                }
                else if (strcmp(bck, tin) == 0&&strlen(bck) == 7)
                {
                    attendanceFalse = 0;
                            printf("\n--------------------TIME IN--------------------\n");
                            printf("Name: ");
                            scanf("%s", atnchr);
                            printf("Time: ");
                            scanf("%s", time);
                    attendanceOnline = true;
                    fgetc(stdin);
                }
                else if (strcmp(bck, inWork) == 0&&strlen(bck) == 17)
                {
                    attendanceFalse = 1;
                    printf("\n---------------CURRENTLY IN WORK---------------\n");       
                    printf("Name: %s\nTime in: %s", atnchr, time);
                    printf("\n-----------------------------------------------\n");
                    attendanceOnline = true;
                }
                else if (strcmp(bck, tout) == 0&&strlen(bck) == 9)
                {
                    attendanceFalse = 2;
                    attendanceMain(attendanceFalse);
                    attendanceOnline = true;
                }
                else
                {
                printf("Invalid Input\n");
                attendanceOnline = true;
                }

            } while(attendanceOnline == true);
                
        }
        //OFFICERS//
        else if(chrcomp == 0&&strlen(chr) == 8)
        { 
        login = false;
            officerMain();
            printf(":");
            scanf("%s", &bck);
                strlwr(bck);
                chrcomp = strcmp(bck, BACK);
                if (chrcomp == 0&&strlen(bck) == 4)
                {
                    login = true;
                }
                else
                {
                    do 
                    {   
                        printf("\tInvalid Input\nAvailable Command(s): Back\n:");
                        scanf("%s", &bck);
                        strlwr(bck);
                        chrcomp = strcmp(bck, BACK);
                        if (chrcomp == 0&&strlen(bck) == 4)
                            {
                                login = true;
                            }
                    } while(login == false);
                }
        }
        //REPORTS//   
        else if(chrcomp == 0&&strlen(chr) == 7)
        {
            const char makeAreport[] = "make a report";
            const char report[] = "reports";
            login = false;
            int reportFalse;
            bool reportOnline; //loop for report section
            fgetc(stdin);
            do
            {
            reportOnline = false;
            reportsIntro();
            fgets(bck, 20, stdin);
            bck[strlen(bck)-1] = '\0';
                strlwr(bck);
                chrcomp = strcmp(bck, BACK);
                if (chrcomp == 0&&strlen(bck) == 4)
                {
                    login = true;
                    reportOnline = false;
                }
                else if (strcmp(bck, makeAreport) == 0&&strlen(bck) == 13)
                {
                reportFalse = 0;
                reports(reportFalse);
                reportOnline = true;

                }
                else if (strcmp(bck, report) == 0&&strlen(bck) == 7)
                {
                reportFalse = 1;
                reports(reportFalse);
                reportOnline = true;
                }
                else
                {
                printf("Invalid Input\n");
                reportOnline = true;

                }

            } while (reportOnline == true);            
        }
        //LOGOUT//  
        else if(chrcomp == 0&&strlen(chr) == 6)
        {
            printf("\nLogged Out.\n");
            login = false;
        }
        else
        {
            printf("Invalid Input");
        }
    } while (login == true);     

    return 0;
}

void intro()
{
    printf("\n--------------------LOGBOOK--------------------\n");
    printf("       \"Attendance\"         \"Officers\"\n");
    printf("       \"Reports\"            \"Logout\"\n");
    printf("-----------------------------------------------\n");
}
void attendance()
{
    printf("\n------------------ATTENDANCE-------------------\n");
    printf("     \"Time in\"                 \"Time out\"\n");
    printf("     \"Currently In Work\"       \"Back\"\n");
    printf("-----------------------------------------------\n");
}
void officerMain()
{
    const char BACK[] = "back";
    struct info
    {
        char firstname[30];
        char middlename;
        char lastname[30];
        char address[100];
        int age;
        float temp;      
    };
    struct info officer1;
    strcpy(officer1.firstname, "Renato");
    officer1.middlename = 'T';
    strcpy(officer1.lastname, "Batumbakal");
    strcpy(officer1.address, "567 Taas Rd, Barangay 171, Caloocan, Metro Manila");
    officer1.age = 35;
    struct info officer2;
    strcpy(officer2.firstname, "Rodolfo");
    officer2.middlename = 'B';
    strcpy(officer2.lastname, "Ragunton");
    strcpy(officer2.address, "382 Bagumbong Taas, Barangay 171, Caloocan, 1421 Metro Manila");
    officer2.age = 43;
    struct info officer3;
    strcpy(officer3.firstname, "Banjo");
    officer3.middlename = 'C';
    strcpy(officer3.lastname, "Renealo");
    strcpy(officer3.address, "318 Taas Rd, Barangay 171, Caloocan, Metro Manila");
    officer3.age = 49;
    struct info officer4;
    strcpy(officer4.firstname, "Marites");
    officer4.middlename = 'H';
    strcpy(officer4.lastname, "Dela Cruz");
    strcpy(officer4.address, "Cypress, Barangay 171, Caloocan, Metro Manila");
    officer4.age = 36;
    struct info officer5;
    strcpy(officer5.firstname, "Joan");
    officer5.middlename = 'G';
    strcpy(officer5.lastname, "Cayabyab");
    strcpy(officer5.address, "Rainbow Ave, Barangay 171, Caloocan, Metro Manila");
    officer5.age = 27;
    struct info officer6;
    strcpy(officer6.firstname, "Elsa");
    officer6.middlename = 'L';
    strcpy(officer6.lastname, "Santos");
    strcpy(officer6.address, "9 Congressional Rd Ext, Barangay 171, Caloocan, 1400 Metro Manila");
    officer6.age = 32;
    struct info officer7;
    strcpy(officer7.firstname, "Juliet");
    officer7.middlename = 'T';
    strcpy(officer7.lastname, "Panganiban");
    strcpy(officer7.address, "Mahogany, 173, Caloocan, North Caloocan");
    officer7.age = 46;
    struct info officer8;
    strcpy(officer8.firstname, "Carlos");
    officer8.middlename = 'A';
    strcpy(officer8.lastname, "Pengpengan");
    strcpy(officer8.address, "Camarin Road Brgy 173 Congress Village, Caloocan, 1422 Metro Manila");
    officer8.age = 43;
        printf("-----------------OFFICERS LIST-----------------\n");
        printf("                    \"Back\"                     \n\n");
        printf("Name: %s %c. %s\n", officer1.firstname, officer1.middlename, officer1.lastname);
        printf("Age: %d\n", officer1.age);
        printf("Address: %s\n\n", officer1.address);
        printf("Name: %s %c. %s\n", officer2.firstname, officer2.middlename, officer2.lastname);
        printf("Age: %d\n", officer2.age);
        printf("Address: %s\n\n", officer2.address);
        printf("Name: %s %c. %s\n", officer3.firstname, officer3.middlename, officer3.lastname);
        printf("Age: %d\n", officer3.age);
        printf("Address: %s\n\n", officer3.address);
        printf("Name: %s %c. %s\n", officer4.firstname, officer4.middlename, officer4.lastname);
        printf("Age: %d\n", officer4.age);
        printf("Address: %s\n\n", officer4.address);
        printf("Name: %s %c. %s\n", officer5.firstname, officer5.middlename, officer5.lastname);
        printf("Age: %d\n", officer5.age);
        printf("Address: %s\n\n", officer5.address);
        printf("Name: %s %c. %s\n", officer6.firstname, officer6.middlename, officer6.lastname);
        printf("Age: %d\n", officer6.age);
        printf("Address: %s\n\n", officer6.address);
        printf("Name: %s %c. %s\n", officer7.firstname, officer7.middlename, officer7.lastname);
        printf("Age: %d\n", officer7.age);
        printf("Address: %s\n\n", officer7.address);
        printf("Name: %s %c. %s\n", officer8.firstname, officer8.middlename, officer8.lastname);
        printf("Age: %d\n", officer8.age);
        printf("Address: %s\n\n", officer8.address);
        printf("\t\t    \"Back\"\n-----------------------------------------------\n");       
}

void reportsIntro()
{
    printf("--------------------REPORTS--------------------\n");
    printf("     \"Make a report\"\t    \"Reports\"\n     \"Back\"\nNote: Can only make one report*");       
    printf("\n-----------------------------------------------\n");       
}
void reports(int rpt)
{
    struct blotterReport
    {
        int caseNo;
        char from[50];
        char to[50];
        char subject[100];
        char date[20];
        char detailOfEvent[500];
        char actionTaken[500];
        char summary[500];
    };
    struct blotterReport case1;
        if (rpt == 0)
        {
        printf("Case No: ");
        scanf("%d", &case1.caseNo);
        printf("Date: ");
        scanf("%s", case1.date);
        printf("From: ");
        scanf("%s", case1.from);
        printf("To: ");
        scanf("%s", case1.to);
        fgetc(stdin);
        printf("Subject: ");
        fgets(case1.subject, 100, stdin);
        case1.subject[strlen(case1.subject)-1] = '\0';
        printf("Detail of Event: ");
        fgets(case1.detailOfEvent, 500, stdin);
        case1.detailOfEvent[strlen(case1.detailOfEvent)-1] = '\0';
        printf("Actions Taken: ");
        fgets(case1.actionTaken, 500, stdin);
        case1.actionTaken[strlen(case1.actionTaken)-1] = '\0';
        printf("Summary: ");
        fgets(case1.summary, 500, stdin);
        case1.summary[strlen(case1.summary)-1] = '\0';
        }
        else if (rpt == 1)
        {
            printf("\t\tPOLICE REPORT\n\n");
            printf("Case No: %d\t\tDate: %s\n", case1.caseNo, case1.date);       
            printf("From: %s\t\tTo: %s\n", case1.from, case1.to);
            printf("Subject: %s", case1.subject);
            printf("\n-----------------------------------------------\n");       
            printf("Detail of Event:\n%s\n\n", case1.detailOfEvent);
            printf("Actions Taken:\n%s\n\n", case1.actionTaken);
            printf("Summary:\n%s\n", case1.summary);
            printf("\n-----------------------------------------------\n\n");       
        }

}

