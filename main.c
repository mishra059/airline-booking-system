#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#define N 200
#define false 0
#define true 1
#define LSIZE 81

struct airinform
{
    char airnum[7];
    char airtype[4];
    char taketim[6];
    char takeplc[12];
    char landtim[6];
    char landplc[12];
    char flighttim[6];
    char perform[3];
    char pilot[81];
    char price[5];
}airin[N];
struct readinform
{
    char userid[11];
    char airnum[7];
    char airtype[4];
    char taketim[6];
    char takeplc[12];
    char landtim[6];
    char landplc[12];
    char flighttim[6];
    char perform[3];
    char price[5];
    char seatnum[4];
}readin[N];

void findtype(int x1);
void findtakeplc(int x1);
void findlandplc(int x1);
void bookticket(char a[7],char b[7],int i);
void strcopy(char[],char[]);

int main()
{

    int idcheck(char[]);
    int phonecheck(char[]);
    int emailcheck(char[]);
    int putincheck(char[],char[]);
    int choice,choice1,choice2,choice3,choice4,choice5,sort;
    int i=0,j,k,m=0,n=0,x=0,y;

    char adid[81],adname[81],ademail[81],adpassword[81],adfirm[81],newadpassword[81],newademail[81];
    char fnum[81],takeoff[81],land[81],atype[81],takeofftime[81],landtime[81],ftime[81];
    char putinname[81],putinword[81];
    char putinadname[81],putinadword[81];
    char airnum1[7],airtype1[4],takeplc1[12],landplc1[12],taketim1[6],landtim1[6],pilot1[10],perform1[3],flighttim1[8],price1[5];
    char userid[81],username[81],gender[81],phone[81],password[81],email[81],newpassword[81],newemail[81],newphone[81];

    FILE *userfile;
    FILE *adminfile;
    FILE *fp;
    FILE *userfiles;
    FILE *adminfiles;
    FILE *timetable;
    FILE *timetable1;
    FILE *addinform;
    FILE *userread;
    FILE *read;

    srand(time(0));
    printf("                         ------------------------------\n");
    printf("                         Welcome to The Avionic System!\n");
    printf("                         ------------------------------\n");
    printf("\nWhat would you want to do: ");
    printf(" 1.Enter the System   2.Exit the System");
    printf("\n\nPlease enter: ");
    scanf("%d",&choice);
    while(choice>=3||choice1<=0)
    {
        printf("Wrong order! Please enter again: ");
        scanf("%d",&choice);
    }

    switch(choice)
    {
        case 1:
        {	system("cls");
            do
            {
                printf("\nUser : 1.Register   2.Log in");
                printf("\nAdmin: 3.Register   4.Log in");
                printf("\n\nPlease enter: ");
                scanf("%d",&choice1);

                while(choice1>=5||choice1<=0)
                {
                    printf("Wrong order!Please enter again: ");
                    scanf("%d",&choice1);
                }
                system("cls");

                switch(choice1)
                {
                    case 1:
                    {
                        printf("Please enter your username: ");
                        scanf("%s",userid);
                        while(idcheck(userid)==0)
                        {
                            printf("Your username must consist of 6-10 letters and digits,please put in again: ");
                            scanf("%s",userid);
                        }

                        printf("Please enter your full name: ");
                        scanf("%s",username);
                        printf("Please enter your gender: ");
                        scanf("%s",gender);
                        printf("Please enter your phone number: ");
                        scanf("%s",phone);
                        while(phonecheck(phone)==0)
                        {
                            printf("Your phone number must consist of 11 pure digits,please put in again: ");
                            scanf("%s",phone);
                        }
                        printf("Please enter your password: ");
                        scanf("%s",password);
                        printf("Please enter your e-mail: ");
                        scanf("%s",email);
                        while(emailcheck(email)==0)
                        {
                            printf("Your form of email is wrong,please put in again: ");
                            scanf("%s",email);
                        }
                        printf("\nSuccess!\n");

                        userfile=fopen("user.txt","w");
                        fprintf(userfile, "%s  %s  %s  %s  %s  %s\n",userid,username,gender,phone,password,email);
                        fclose(userfile);

                        userfiles=fopen("users.txt","a");
                        fprintf(userfiles, "UserID:%s  Name:%s  Gender:%s  Phone:%s  Password:%s  Email:%s",userid,username,gender,phone,password,email);
                        fclose(userfiles);
                        break;
                    }

                    case 2:
                    {
                        if((fp=fopen("user.txt","r"))==NULL)
                        {
                            printf("Error!");
                            return false;
                        }
                        fscanf(fp, "%s  %s  %s  %s  %s  %s \n", userid, username, gender, phone, password, email);
                        fclose(fp);

                        printf("Please enter your username: ");
                        scanf("%s",putinname);
                        printf("please enter your password: ");
                        scanf("%s",putinword);

                        while(putincheck(putinname,userid)==0||putincheck(putinword,password)==0)
                        {
                            printf("\nError!");
                            printf("\nPlease enter your username: ");
                            scanf("%s",putinname);
                            printf("please enter your password: ");
                            scanf("%s",putinword);
                        }

                        printf("\nGreat!\n");
                        printf("\n1.Look through the Flight Information");
                        printf("\n2.Change the Password");
                        printf("\n3.Change the Email");
                        printf("\n4.Change the Phone Number");
                        printf("\n5.Check the Flight Order");
                        printf("\n\nPlease enter: ");
                        scanf("%d",&choice2);
                        while(choice2>=6||choice2<=0)
                        {
                            printf("Wrong order! Please enter again: ");
                            scanf("%d",&choice2);
                        }

                        system("cls");
                        switch(choice2)
                        {
                            case 1:
                            {
                                timetable=fopen("inform.txt","r");
                                while(!feof(timetable))
                                {
                                    fscanf(timetable,"%s %s %s %s %s %s %s %s %s",airin[i].airnum,airin[i].airtype,airin[i].taketim,airin[i].takeplc,airin[i].landtim,airin[i].landplc,airin[i].flighttim,airin[i].perform,airin[i].price);
                                    i++;
                                }
                                fclose(timetable);
                                for(j=0;j<i;j++)
                                {
                                    printf("\n");
                                    printf("%7s | %4s | %6s | %12s | %6s | %12s | %6s | %3s | %s��",airin[j].airnum,airin[j].airtype,airin[j].taketim,airin[j].takeplc,airin[j].landtim,airin[j].landplc,airin[j].flighttim,airin[j].perform,airin[j].price);
                                }

                                do
                                {
                                    printf("\n\nPlease enter the type you want to use to search the aircraft\n(1)Aircraft number\n(2)Aircraft type\n(3)Taking off place\n(4)Landing place\n(5)Taking off time\n(6)Landing time\n(7)Sort by time\n\nPlease enter:");
                                    scanf("%d",&choice3);
                                    switch(choice3)
                                    {
                                        case 1:
                                            printf("\n\nPlease enter the number of the aircraft you want to find:");
                                            scanf("%s",airnum1);
                                            system("cls");
                                            for(k=0;k<i;k++)
                                            {
                                                if(strcmp(airnum1,airin[k].airnum)==0)
                                                {
                                                    printf("\n%7s | %4s | %6s | %12s | %6s | %12s | %6s | %3s | %s��",airin[k].airnum,airin[k].airtype,airin[k].taketim,airin[k].takeplc,airin[k].landtim,airin[k].landplc,airin[k].flighttim,airin[k].perform,airin[k].price);
                                                }
                                                else
                                                    m++;
                                            }

                                            while(m>=i)
                                            {
                                                m=0;
                                                printf("Can not find aircraft,please try again:");
                                                scanf("%s",airnum1);
                                                for(k=0;k<i;k++)
                                                {
                                                    if(strcmp(airnum1,airin[k].airnum)==0)
                                                    {
                                                        printf("\n%7s | %4s | %6s | %12s | %6s | %12s | %6s | %3s | %s��",airin[k].airnum,airin[k].airtype,airin[k].taketim,airin[k].takeplc,airin[k].landtim,airin[k].landplc,airin[k].flighttim,airin[k].perform);
                                                    }
                                                    else
                                                        m++;
                                                }
                                            }
                                            bookticket(airnum1,putinname,i);
                                            break;

                                        case 2:
                                            printf("\n\nPlease enter the type of the aircraft you want to find:");
                                            scanf("%s",airtype1);
                                            system("cls");
                                            for(k=0;k<i;k++)
                                            {
                                                if(strcmp(airtype1,airin[k].airtype)==0)
                                                {
                                                    printf("\n%7s | %4s | %6s | %12s | %6s | %12s | %6s | %3s | %s��",airin[k].airnum,airin[k].airtype,airin[k].taketim,airin[k].takeplc,airin[k].landtim,airin[k].landplc,airin[k].flighttim,airin[k].perform,airin[k].price);
                                                }
                                                else
                                                    m++;
                                            }
                                            if(m>=i)
                                                findtype(i);
                                            printf("\nPlease enter the flight number you would like to book:");
                                            scanf("%s",&airnum1);
                                            for(k=0;k<i;k++)
                                            {
                                                if(strcmp(airnum1,airin[k].airnum)==0)
                                                {
                                                    printf("\n%7s | %4s | %6s | %12s | %6s | %12s | %6s | %3s | %s��",airin[k].airnum,airin[k].airtype,airin[k].taketim,airin[k].takeplc,airin[k].landtim,airin[k].landplc,airin[k].flighttim,airin[k].perform,airin[k].price);
                                                }
                                            }
                                            bookticket(airnum1,putinname,i);
                                            break;

                                        case 3:
                                            printf("\n\nPlease enter the taking off place you want to find:");
                                            scanf("%s",takeplc1);
                                            system("cls");
                                            for(k=0;k<i;k++)
                                            {
                                                if(strcmp(takeplc1,airin[k].takeplc)==0)
                                                {
                                                    printf("\n%7s | %4s | %6s | %12s | %6s | %12s | %6s | %3s | %s��",airin[k].airnum,airin[k].airtype,airin[k].taketim,airin[k].takeplc,airin[k].landtim,airin[k].landplc,airin[k].flighttim,airin[k].perform,airin[k].price);
                                                }
                                                else
                                                    m++;
                                            }
                                            if(m>=i)
                                                findtakeplc(i);
                                            printf("\nPlease enter the flight number you would like to book:");
                                            scanf("%s",&airnum1);
                                            for(k=0;k<i;k++)
                                            {
                                                if(strcmp(airnum1,airin[k].airnum)==0)
                                                {
                                                    printf("\n%7s | %4s | %6s | %12s | %6s | %12s | %6s | %3s | %s��",airin[k].airnum,airin[k].airtype,airin[k].taketim,airin[k].takeplc,airin[k].landtim,airin[k].landplc,airin[k].flighttim,airin[k].perform,airin[k].price);
                                                }
                                            }
                                            bookticket(airnum1,putinname,i);
                                            break;

                                        case 4:
                                            printf("\n\nPlease enter the landing place you want to find:");
                                            scanf("%s",landplc1);
                                            system("cls");
                                            for(k=0;k<i;k++)
                                            {
                                                if(strcmp(landplc1,airin[k].landplc)==0)
                                                {
                                                    printf("\n%7s | %4s | %6s | %12s | %6s | %12s | %6s | %3s | %s��",airin[k].airnum,airin[k].airtype,airin[k].taketim,airin[k].takeplc,airin[k].landtim,airin[k].landplc,airin[k].flighttim,airin[k].perform,airin[k].price);
                                                }
                                                else
                                                    m++;
                                            }
                                            if(m>=i)
                                                findlandplc(i);
                                            printf("\nPlease enter the flight number you would like to book:");
                                            scanf("%s",&airnum1);
                                            for(k=0;k<i;k++)
                                            {
                                                if(strcmp(airnum1,airin[k].airnum)==0)
                                                {
                                                    printf("\n%7s | %4s | %6s | %12s | %6s | %12s | %6s | %3s | %s��",airin[k].airnum,airin[k].airtype,airin[k].taketim,airin[k].takeplc,airin[k].landtim,airin[k].landplc,airin[k].flighttim,airin[k].perform,airin[k].price);
                                                }
                                            }
                                            bookticket(airnum1,putinname,i);
                                            break;

                                        case 5:
                                            printf("\n\nPlease enter the taking off time you want to find:");
                                            scanf("%s",taketim1);
                                            system("cls");
                                            if(strlen(taketim1)==4)
                                            {
                                                for(k=0;k<i;k++)
                                                {
                                                    if(strncmp(taketim1,airin[k].taketim,1)==0)
                                                    {
                                                        printf("\n%7s | %4s | %6s | %12s | %6s | %12s | %6s | %3s | %s��",airin[k].airnum,airin[k].airtype,airin[k].taketim,airin[k].takeplc,airin[k].landtim,airin[k].landplc,airin[k].flighttim,airin[k].perform,airin[k].price);
                                                    }
                                                }
                                            }
                                            else if(strlen(taketim1)==5)
                                            {
                                                for(k=0;k<i;k++)
                                                {
                                                    if(strncmp(taketim1,airin[k].taketim,2)==0)
                                                    {
                                                        printf("\n%7s | %4s | %6s | %12s | %6s | %12s | %6s | %3s | %s��",airin[k].airnum,airin[k].airtype,airin[k].taketim,airin[k].takeplc,airin[k].landtim,airin[k].landplc,airin[k].flighttim,airin[k].perform,airin[k].price);
                                                    }
                                                }
                                            }
                                            else
                                                printf("Can't find aircraft, please try again.");
                                            printf("\nPlease enter the flight number you would like to book:");
                                            scanf("%s",&airnum1);
                                            for(k=0;k<i;k++)
                                            {
                                                if(strcmp(airnum1,airin[k].airnum)==0)
                                                {
                                                    printf("\n%7s | %4s | %6s | %12s | %6s | %12s | %6s | %3s | %s��",airin[k].airnum,airin[k].airtype,airin[k].taketim,airin[k].takeplc,airin[k].landtim,airin[k].landplc,airin[k].flighttim,airin[k].perform,airin[k].price);
                                                }
                                            }
                                            bookticket(airnum1,putinname,i);
                                            break;

                                        case 6:
                                            printf("\n\nPlease enter the landing time you want to find:");
                                            scanf("%s",landtim1);
                                            system("cls");
                                            if(strlen(landtim1)==4)
                                            {
                                                for(k=0;k<i;k++)
                                                {
                                                    if(strncmp(landtim1,airin[k].landtim,1)==0)
                                                    {
                                                        printf("\n%7s | %4s | %6s | %12s | %6s | %12s | %6s | %3s | %s��",airin[k].airnum,airin[k].airtype,airin[k].taketim,airin[k].takeplc,airin[k].landtim,airin[k].landplc,airin[k].flighttim,airin[k].perform,airin[k].price);
                                                    }
                                                }
                                            }
                                            else if(strlen(landtim1)==5)
                                            {
                                                for(k=0;k<i;k++)
                                                {
                                                    if(strncmp(landtim1,airin[k].landtim,2)==0)
                                                    {
                                                        printf("\n%7s | %4s | %6s | %12s | %6s | %12s | %6s | %3s | %s��",airin[k].airnum,airin[k].airtype,airin[k].taketim,airin[k].takeplc,airin[k].landtim,airin[k].landplc,airin[k].flighttim,airin[k].perform,airin[k].price);
                                                    }
                                                }
                                            }
                                            else
                                                printf("Can't find aircraft, please try again.");
                                            printf("\nPlease enter the flight number you would like to book:");
                                            scanf("%s",&airnum1);
                                            for(k=0;k<i;k++)
                                            {
                                                if(strcmp(airnum1,airin[k].airnum)==0)
                                                {
                                                    printf("\n%7s | %4s | %6s | %12s | %6s | %12s | %6s | %3s | %s��",airin[k].airnum,airin[k].airtype,airin[k].taketim,airin[k].takeplc,airin[k].landtim,airin[k].landplc,airin[k].flighttim,airin[k].perform,airin[k].price);
                                                }
                                            }
                                            bookticket(airnum1,putinname,i);
                                            break;

                                        case 7:
                                            printf("\n\n(1)Proper order \n(2)Reverse order \nPlease enter the sort direction you want to use:");
                                            scanf("%d",&sort);
                                            system("cls");
                                            if(sort==1)
                                            {
                                                for(j=0;j<i-1;j++)
                                                {
                                                    printf("\n");
                                                    printf("%7s | %4s | %6s | %12s | %6s | %12s | %6s | %3s | %s��",airin[j].airnum,airin[j].airtype,airin[j].taketim,airin[j].takeplc,airin[j].landtim,airin[j].landplc,airin[j].flighttim,airin[j].perform,airin[j].price);
                                                }
                                            }
                                            else if(sort==2)
                                            {
                                                for(j=i-2;j>=0;j--)
                                                {
                                                    printf("\n");
                                                    printf("%7s | %4s | %6s | %12s | %6s | %12s | %6s | %3s | %s��",airin[j].airnum,airin[j].airtype,airin[j].taketim,airin[j].takeplc,airin[j].landtim,airin[j].landplc,airin[j].flighttim,airin[j].perform,airin[j].price);
                                                }
                                            }
                                            break;

                                        default:
                                            printf("Wrong input, please try again.");
                                            break;
                                    }
                                }while(choice3>=8);
                                break;
                            }

                            case 2:
                            {
                                printf("Please enter your new password: ");
                                scanf("%s",newpassword);
                                strcopy(password, newpassword);
                                printf("\nThe new password is %s!\n",password);

                                userfile=fopen("user.txt","w");
                                fprintf(userfile, "%s  %s  %s  %s  %s  %s\n",userid,username,gender,phone,password,email);
                                fclose(userfile);
                                userfiles=fopen("users.txt","a");
                                fprintf(userfiles, "\nUserID:%s  Name:%s  Gender:%s  Phone:%s  Password:%s  Email:%s\n",userid,username,gender,phone,password,email);
                                fclose(userfiles);
                                break;
                            }

                            case 3:
                            {
                                printf("Please enter your new email: ");
                                scanf("%s",newemail);
                                strcopy(email, newemail);
                                while(emailcheck(email)==0)
                                {
                                    printf("Your form of email is wrong,please put in again: ");
                                    scanf("%s",email);
                                }

                                printf("\nThe new email is %s!",email);
                                adminfile=fopen("user.txt","w");
                                fprintf(adminfile, "%s %s %s %s %s\n",userid,username,gender,phone,password,email);
                                fclose(adminfile);
                                adminfiles=fopen("users.txt","a");
                                fprintf(adminfiles, "\nUserID:%s  Name:%s  Gender:%s  Phone:%s  Password:%s  Email:%s\n",userid,username,gender,phone,password,email);
                                fclose(adminfiles);
                                break;
                            }

                            case 4:
                            {
                                printf("Please enter your new phone number: \n");
                                scanf("%s",newphone);
                                strcopy(phone, newphone);

                                while(phonecheck(phone)==0)
                                {
                                    printf("Your phone number must consist of 11 pure digits,please put in again: ");
                                    scanf("%s",phone);
                                }
                                printf("\nThe new phone number is %s!\n",phone);

                                userfile=fopen("user.txt","w");
                                fprintf(userfile, "%s  %s  %s  %s  %s  %s\n",userid,username,gender,phone,password,email);
                                fclose(userfile);

                                userfiles=fopen("users.txt","a");
                                fprintf(userfiles, "\nUserID:%s  Name:%s  Gender:%s  Phone:%s  Password:%s  Email:%s\n",userid,username,gender,phone,password,email);
                                fclose(userfiles);
                                break;
                            }

                            case 5:
                            {
                                userread=fopen("ticketinform.txt","r");
                                while(!feof(userread))
                                {
                                    fscanf(userread,"%s %s %s %s %s %s %s %s %s %s",readin[x].userid,readin[x].airnum,readin[x].airtype,readin[x].taketim,readin[x].takeplc,readin[x].landtim,readin[x].landplc,readin[x].flighttim,readin[x].price,readin[x].seatnum);
                                    x++;
                                }

                                fclose(userread);
                                for(y=0;y<x;y++)
                                {
                                    if(strcmp(putinname,readin[y].userid)==0)
                                    {
                                        printf("\n%d. \nUserid:%s  \nAircraft Number:%s  \nAircraft Type:%s  \nTaking off Time:%s  \nStart:%s  \nLanding Time:%s  \nEnd:%s  \nFlight Time:%s  \nPrice:%s��  \nSeat number:%s\n",y+1,readin[y].userid,readin[y].airnum,readin[y].airtype,readin[y].taketim,readin[y].takeplc,readin[y].landtim,readin[y].landplc,readin[y].flighttim,readin[y].price,readin[y].seatnum);
                                    }
                                }
                                break;
                            }
                        }

                        break;
                    }

                    case 3:
                    {
                        printf("Please enter your username: ");
                        scanf("%s",adid);
                        while(idcheck(adid)==0)
                        {
                            printf("Your username must consist of 6-10 letters and digits,please put in again: ");
                            scanf("%s",adid);
                        }
                        printf("Please enter your airline: ");
                        scanf("%s",adfirm);
                        printf("Please enter your full name: ");
                        scanf("%s",adname);
                        printf("Please enter your password: ");
                        scanf("%s",adpassword);
                        printf("Please enter your e-mail: ");
                        scanf("%s",ademail);
                        while(emailcheck(ademail)==0)
                        {
                            printf("Your form of email is wrong,please put in again: ");
                            scanf("%s",ademail);
                        }
                        printf("\nSuccess!\n");

                        adminfile=fopen("admin.txt","w");
                        fprintf(adminfile, "%s  %s  %s  %s  %s\n",adid,adfirm,adname,adpassword,ademail);
                        fclose(adminfile);

                        adminfiles=fopen("admins.txt","a");
                        fprintf(adminfiles, "AdName:%s  Firm:%s  Name:%s  Password:%s  Email:%s\n",adid,adfirm,adname,adpassword,ademail);
                        fclose(adminfiles);
                        break;
                    }

                    case 4:
                    {
                        if((fp=fopen("admin.txt","r"))==NULL)
                        {
                            printf("Error!");
                            return false;
                        }
                        fscanf(fp, "%s  %s  %s  %s  %s\n", adid,adfirm,adname,adpassword,ademail);
                        fclose(fp);

                        printf("Please put in your username: ");
                        scanf("%s",putinadname);
                        printf("please put in your password: ");
                        scanf("%s",putinadword);
                        while(putincheck(putinadname,adid)==0||putincheck(putinadword,adpassword)==0)
                        {
                            printf("\nError!");
                            printf("\nPlease enter your username: ");
                            scanf("%s",putinadname);
                            printf("please enter your password: ");
                            scanf("%s",putinadword);
                        }
                        printf("\nGreat!");

                        do
                        {
                            printf("\n");
                            printf("\n1.Look though the Flight Information");
                            printf("\n2.Check the Flight Order");
                            printf("\n3.Add the Flight Information");
                            printf("\n4.Change the Password");
                            printf("\n5.Change the Email");
                            printf("\n\nPlease enter: ");
                            scanf("%d",&choice4);

                            system("cls");
                            switch(choice4)
                            {
                                case 1:
                                {
                                    timetable=fopen("adinform.txt","r");
                                    while(!feof(timetable))
                                    {
                                        fscanf(timetable,"%s %s %s %s %s %s %s %s %s %s",airin[i].airnum,airin[i].airtype,airin[i].taketim,airin[i].takeplc,airin[i].landtim,airin[i].landplc,airin[i].flighttim,airin[i].perform,airin[i].price,airin[i].pilot);
                                        i++;
                                    }
                                    fclose(timetable);
                                    for(j=0;j<i-1;j++)
                                    {
                                        printf("\n");
                                        printf("%7s | %4s | %6s | %12s | %6s | %12s | %6s | %3s | %4s | %10s",airin[j].airnum,airin[j].airtype,airin[j].taketim,airin[j].takeplc,airin[j].landtim,airin[j].landplc,airin[j].flighttim,airin[j].perform,airin[j].price,airin[j].pilot);
                                    }
                                    break;
                                }

                                case 2:
                                {
                                    int x=0,y;
                                    read=fopen("ticketinform.txt","r");
                                    while(!feof(read))
                                    {
                                        fscanf(read,"%s %s %s %s %s %s %s %s %s %s",readin[x].userid,readin[x].airnum,readin[x].airtype,readin[x].taketim,readin[x].takeplc,readin[x].landtim,readin[x].landplc,readin[x].flighttim,readin[x].price,readin[x].seatnum);
                                        x++;
                                    }
                                    fclose(read);
                                    for(y=0;y<x;y++)
                                    {
                                        printf("\n%d. \nUserid:%s  \nAircraft Number:%s  \nAircraft Type:%s  \nTaking off Time:%s  \nStart:%s  \nLanding Time:%s  \nEnd:%s  \nFlight Time:%s  \nPrice:%s��  \nSeat number:%s\n",y+1,readin[y].userid,readin[y].airnum,readin[y].airtype,readin[y].taketim,readin[y].takeplc,readin[y].landtim,readin[y].landplc,readin[y].flighttim,readin[y].price,readin[y].seatnum);
                                    }
                                    break;
                                }

                                case 3:
                                {
                                    timetable=fopen("adinform.txt","r");
                                    while(!feof(timetable))
                                    {
                                        fscanf(timetable,"%s %s %s %s %s %s %s %s %s %s",airin[i].airnum,airin[i].airtype,airin[i].taketim,airin[i].takeplc,airin[i].landtim,airin[i].landplc,airin[i].flighttim,airin[i].perform,airin[i].price,airin[i].pilot);
                                        i++;
                                    }
                                    fclose(timetable);
                                    printf("Please enter these information to add The Flight Information\n(1)Aircraft Number: ");
                                    scanf("%s",airnum1);
                                    printf("(2)Aircraft Type: ");
                                    scanf("%s",airtype1);
                                    printf("(3)Taking off Time: ");
                                    scanf("%s",taketim1);
                                    printf("(4)Take off Place: ");
                                    scanf("%s",takeplc1);
                                    printf("(5)Landing Time: ");
                                    scanf("%s",landtim1);
                                    printf("(6)Landing Place: ");
                                    scanf("%s",landplc1);
                                    printf("(7)Flight Time: ");
                                    scanf("%s",flighttim1);
                                    printf("(8)Performance: ");
                                    scanf("%s",perform1);
                                    printf("(9)Price: ");
                                    scanf("%s",price1);
                                    printf("(10)Pilot: ");
                                    scanf("%s",pilot1);

                                    for(k=0;k<i;k++)
                                    {
                                        if(strcmp(airnum1,airin[k].airnum)==0)
                                            printf("\nExisting Flight Number!\n");
                                        else
                                            m++;
                                    }
                                    for(k=0;k<i;k++)
                                    {
                                        if(strcmp(pilot1,airin[k].pilot)==0)
                                        {
                                            if(strcmp(taketim1,airin[k].taketim)==0)
                                                printf("This pilot could not work in different flights in the same time!");
                                            else
                                                break;
                                        }
                                        else
                                            n++;
                                    }
                                    if((m+n)==2*i)
                                    {
                                        printf("\nFlight Information: %s %s %s %s %s %s %s %s %s %s",airnum1,airtype1,taketim1,takeplc1,landtim1,landplc1,flighttim1,perform1,price1,pilot1);
                                        printf("\n\n1.Public   2.Cancel");
                                        printf("\nPlease enter: ");
                                        scanf("%d",&choice5);
                                        while(choice5>=3||choice5<=0)
                                        {
                                            printf("Wrong order!Please enter again: ");
                                            scanf("%d",&choice5);
                                        }

                                        switch(choice5)
                                        {
                                            case 1:
                                            {
                                                timetable1=fopen("adinform.txt","a");
                                                fprintf(timetable1,"\n%7s   %4s   %6s   %12s   %6s   %12s   %6s   %4s   %5s   %10s ",airnum1,airtype1,taketim1,takeplc1,landtim1,landplc1,flighttim1,perform1,price1,pilot1);
                                                fclose(timetable1);
                                                addinform=fopen("inform.txt","a");
                                                fprintf(addinform,"\n%7s   %4s   %6s   %12s   %6s   %12s   %6s   %4s   %5s",airnum1,airtype1,taketim1,takeplc1,landtim1,landplc1,flighttim1,perform1,price1);
                                                fclose(addinform);
                                                printf("Success!");
                                                break;
                                            }

                                            default:
                                                printf("\nThe information has been cancelled!");
                                                break;
                                        }
                                    }
                                    break;
                                }

                                case 4:
                                {
                                    printf("Please enter your new password: ");
                                    scanf("%s",newadpassword);
                                    strcopy(adpassword, newadpassword);
                                    printf("\nThe new password is %s!\n",adpassword);

                                    adminfile=fopen("admin.txt","w");
                                    fprintf(adminfile, "%s %s %s %s %s\n",adid,adfirm,adname,adpassword,ademail);
                                    fclose(adminfile);
                                    adminfiles=fopen("admins.txt","a");
                                    fprintf(adminfiles, "AdName:%s  Firm:%s  Name:%s  Password:%s  Email:%s\n",adid,adfirm,adname,adpassword,ademail);
                                    fclose(adminfiles);
                                    break;
                                }

                                case 5:
                                {
                                    printf("Please enter your new email: \n");
                                    scanf("%s",newademail);
                                    strcopy(ademail, newademail);
                                    while(emailcheck(ademail)==0)
                                    {
                                        printf("Your form of email is wrong,please put in again: ");
                                        scanf("%s",ademail);
                                    }

                                    printf("\nThe new email is %s!\n",ademail);
                                    adminfile=fopen("admin.txt","w");
                                    fprintf(adminfile, "%s %s %s %s %s\n",adid,adfirm,adname,adpassword,ademail);
                                    fclose(adminfile);
                                    adminfiles=fopen("admins.txt","a");
                                    fprintf(adminfiles,"Adname   Firm   Name   Password   Email\n");
                                    fprintf(adminfiles, "AdName:%s  Firm:%s  Name:%s  Password:%s  Email:%s\n",adid,adfirm,adname,adpassword,ademail);
                                    fclose(adminfiles);
                                    break;
                                }

                            }
                        }while(choice4==1||choice4==2);
                        break;
                    }
                }
            }while(choice1==1||choice1==3||choice2==2||choice2==3||choice2==4||choice4==3||choice4==4||choice4==5);
            break;
        }

        default:
            printf("\nYou have exited successfully!");
            break;
    }
    return 0;
}

int idcheck(char x[])
{
    int i,ac=0,Ac=0,len=strlen(x);

    if(strlen(x)<6||strlen(x)>10)
        return false;

    for(i=0;i<=len;i++)
    {

        if(isdigit(x[i])!=0)
            ac++;
        if(isalpha(x[i])!=0)
            Ac++;
        if(ispunct(x[i])!=0)
            return false;
    }

    if(ac==strlen(x)||Ac==strlen(x))
        return false;
    else
        return true;
}

int phonecheck(char y[])
{
    int j;
    if(strlen(y)!=11)
        return false;

    for(j=0;j<=10;j++)
    {
        if(isdigit(y[j])==0)
            return false;
    }
    return true;
}

int emailcheck(char *z)
{

    char str;
    str = '@';
    if(!memchr(z,str,strlen(z)))
    {
        return false;
    }
    str = '.';
    if(!memchr(z,str,strlen(z)))
    {
        return false;
    }
    if(!strstr(z,"com"))
    {
        return false;
    }
    return true;
}

int putincheck(char n[],char m[])
{
    int i;
    int len1=strlen(n);
    int len2=strlen(m);

    if(len1==len2)
    {
        for(i=0;i<=len1;i++)
        {
            if(n[i]==m[i])
                return true;

            else
                return false;
        }
    }
    else
        return false;
}

void strcopy (char string1[], char string2[]) {
    int i = 0;

    while (string2[i] != '\0') {
        {
            string1[i] = string2[i];
            i++;
        }
        string1[i] = '\0';
    }
}



void findtype(int i)
{
    int m,k;
    char airtype1[7];
    do
    {
        m=0;
        printf("Can not find aircraft,please try again:");
        scanf("%s",airtype1);
        for(k=0;k<i;k++)
        {
            if(strcmp(airtype1,airin[k].airtype)==0)
            {
                printf("\n%7s | %4s | %6s | %12s | %6s | %12s | %6s | %3s | %s��",airin[k].airnum,airin[k].airtype,airin[k].taketim,airin[k].takeplc,airin[k].landtim,airin[k].landplc,airin[k].flighttim,airin[k].perform,airin[k].price);
            }
            else
                m++;
        }
    }while(m>=i);
}

void findtakeplc(int i)
{
    int m,k;
    char takeplc1[7];
    do
    {
        m=0;
        printf("Can not find aircraft,please try again:");
        scanf("%s",takeplc1);
        for(k=0;k<i;k++)
        {
            if(strcmp(takeplc1,airin[k].takeplc)==0)
            {
                printf("\n%7s | %4s | %6s | %12s | %6s | %12s | %6s | %3s | %s��",airin[k].airnum,airin[k].airtype,airin[k].taketim,airin[k].takeplc,airin[k].landtim,airin[k].landplc,airin[k].flighttim,airin[k].perform,airin[k].price);
            }
            else
                m++;
        }
    }while(m>=i);
}

void findlandplc(int i)
{
    int m,k;
    char landplc1[7];
    do
    {
        m=0;
        printf("Can not find aircraft,please try again:");
        scanf("%s",landplc1);
        for(k=0;k<i;k++)
        {
            if(strcmp(landplc1,airin[k].landplc)==0)
            {
                printf("\n%7s | %4s | %6s | %12s | %6s | %12s | %6s | %3s | %s��",airin[k].airnum,airin[k].airtype,airin[k].taketim,airin[k].takeplc,airin[k].landtim,airin[k].landplc,airin[k].flighttim,airin[k].perform,airin[k].price);
            }
            else
                m++;
        }
    }while(m>=i);
}

void bookticket(char airnum1[7],char putinname[81],int i)
{
    int slevel,x,choice6,seatnum;
    int price[N];
    int ticketprice;
    char *seatlevel;
    FILE *book;

    for(x=0;x<i;x++)
    {
        if(strcmp(airnum1,airin[x].airnum)==0)
        {
            price[x]=atof(airin[x].price);
            break;
        }
    }
    printf("\nPlease choose the seat level you want to book: \n(1)First Class \n(2)Bussiness Class \n(3)Economy Class \nEnter 1, 2 or3 to choose:");
    scanf("%d",&slevel);
    switch(slevel)
    {
        case 1:
            ticketprice=3*price[x];
            seatlevel="First_Class";
            break;

        case 2:
            ticketprice=2*price[x];
            seatlevel="Bussiness_Class";
            break;

        case 3:
            ticketprice=price[x];
            seatlevel="Economy_Class";
            break;

    }
    seatnum=rand()%200;
    printf("\nYour ticket's information is:\nAircraft Number: %7s\nAircraft Type: %4s\nTaking off Time: %6s\nStart: %12s\nLanding Time :%6s\nEnd :%12s\nFlight Time: %6s\nSeat level: %20s\nPrice: %d��\nSeat:%4d",airnum1,airin[x].airtype,airin[x].taketim,airin[x].takeplc,airin[x].landtim,airin[x].landplc,airin[x].flighttim,seatlevel,ticketprice,seatnum+1);
    printf("\n\n1.Purchase Ticket   2.Cancel");
    printf("\nPlease enter: ");
    scanf("%d",&choice6);
    switch(choice6)
    {
        case 1:
        {
            book=fopen("ticketinform.txt","a");
            fprintf(book, "\n%s  %s  %s  %s  %s  %s  %s  %s  %d %d",putinname,airnum1,airin[x].airtype,airin[x].taketim,airin[x].takeplc,airin[x].landtim,airin[x].landplc,airin[x].flighttim,ticketprice,seatnum+1);
            fclose(book);
            printf("\nSuccess!");
            break;
        }
        default:
            printf("\nThe order has been cancelled!");
    }
}


