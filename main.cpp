#include <iostream>
#include <string>
#include <windows.h>
#include <fstream>
using namespace std;
int totalbookingregister=0;
int totallabA=0;
int totallabB=0;
int totallMMU=0;
int totallabD=0;
int totalMechanical=0;
int totalonApproval=0;
int totalonBook=0;
void col(int color)
{
HANDLE hcon= GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleTextAttribute(hcon,color);
}
//Class
class Lab
{ friend void EditApproval();
friend void AddApproval();
friend void AddBooking();
friend void EditBooking();
protected:
int LabID;
string LabName;
string Code;
string session;
public:
void displayLab(){
cout<<"\t| ";
cout.width(3);cout<<LabID<<" | ";
cout.width(17);cout<<LabName<<"| ";
cout.width(13);cout<<Code<<"| ";
cout.width(2);cout<<session<<" |";
cout<<endl;
}
};
//Inheritance Lab
class DataComm : public Lab {
public:
void regLab(int id, string name, string s, string a){
LabID=id;
LabName=name;
Code=s;
session=a;
totallabA++;
totalbookingregister++;
}
~DataComm(){};
};
class AI: public Lab {
public:
void regLab(int id, string name, string s, string a){
LabID=id;
LabName=name;
Code=s;
session=a;
totallabB++;
totalbookingregister++;
}
~AI(){};
};
class SecuTech : public Lab {
public:
void regLab(int id, string name, string s, string a){
LabID=id;
LabName=name;
Code=s;
session=a;
totallMMU++;
totalbookingregister++;
}
~ SecuTech(){}
};
class Robotics : public Lab {
public:
void regLab(int id, string name, string s, string a){
LabID=id;
LabName=name;
Code=s;
session=a;
totallabD++;
totalbookingregister++;
}
~Robotics(){};
};
class Mechanical : public Lab {
public:
void regLab(int id, string name, string s, string a){
LabID=id;
LabName=name;
Code=s;
session=a;
totalMechanical++;
totalbookingregister++;
}
~Mechanical(){};
};
class ApprovalManage
{
friend void AddApproval();
friend void DisplayStats();
public:
char ApprovalManageID[3];
string ApprovalManageName;
public:
void addApprovalManage(char *a,string b, int c)
{strcpy (ApprovalManageID,a);
ApprovalManageName=b;
};
void displayApprovalRecord(int i)
{
cout<<"\t| ";
cout.width(3);cout<<i+1<<" | ";
cout.width(5);cout<<ApprovalManageID<<"| ";
cout.width(10);cout<<ApprovalManageName<<" | ";
cout<<endl;
}
};
class Bookingbooking
{
friend void AddBooking();
//friend void DisplayStats();
public:
char BookingbookingID[3];
string BookingbookingName;
public:
void addBookingbooking(char *a,string b, int c)
{strcpy (BookingbookingID,a);
BookingbookingName=b;
};
void displayBookRecord(int i)
{
//display Booking Time table
cout<<"\t| ";
cout.width(3);cout<<i+1<<" | ";
cout.width(5);cout<<BookingbookingID<<"| ";
cout.width(7);cout<<BookingbookingName<<" | ";
cout<<endl;
}
};
class Sitting
{
friend void AssignBooking();
friend void deAssignBooking();
protected:
int SittingNumber;
string SittingCode;
int LabonSittingID;
string csize;
public :
void makeBooking (int a, string b, int c,string d){
SittingNumber=a;
SittingCode=b;
LabonSittingID=c;
csize=d;
}
void printSitting(){
cout<<"\t| ";
cout.width(3);cout<<SittingNumber<<" | ";
cout.width(9);cout<<SittingCode<<" | ";
cout.width(11);
if(LabonSittingID == 0)
cout<<"Empty";
else cout<<LabonSittingID; cout<<" | ";
cout.width(11);cout<<csize<<" | ";
cout<<endl;
}
void assignBooking(int a)
{
LabonSittingID=a;
};
void deassignBooking()
{
LabonSittingID=0;
};
};
class onApproval
{
public:
string Approvalsts;
int LabID;
char ApprovalManageID[3];
public:
void displayApprovalRecord(int i)
{
cout<<"\t| ";
cout.width(3);cout<<i+1<<" | ";
cout.width(11);cout<<Approvalsts<<" | ";
cout.width(8);cout<<LabID<<" | ";
//cout.width(12);cout<<ApprovalManageID<<" |";
cout<<endl;
};
void printOneRecord ()
{
cout<<"\tYour Lab ID : "<<LabID<<endl;
cout<<"\tYour new Approval Code : "<<ApprovalManageID<<endl<<endl;
};
void addrecord(string a,int b, char *c)
{Approvalsts = a;
LabID=b;
strcpy (ApprovalManageID,c);
totalonApproval++;
};
void editrecord(char *x)
{
strcpy (ApprovalManageID,x);};
};
class onBook
{
public:
string bookingsts;
int LabID;
char BookingbookingID[3];
public:
void displayBookRecord(int i)
{
cout<<"\t| ";
cout.width(2);cout<<i+1<<" | ";
cout.width(10);cout<<LabID<<" | ";
cout.width(9);cout<<bookingsts<<" | ";
// cout.width(12);cout<<BookingbookingID<<" |";
cout<<endl;
};
void printOneRecord ()
{
cout<<"\tLab ID : "<<LabID<<endl;
cout<<"\tCode : "<<BookingbookingID<<endl<<endl;
};
void addrecord(string a,int b, char *c)
{bookingsts = a;
LabID=b;
strcpy (BookingbookingID,c);
totalonBook++;
};
void editrecord(char *x)
{
strcpy (BookingbookingID,x);};
};
class Instructor
{
friend class Bill;
private:
int InstructorID;
string InstructorName;
string Expertise;
public:
void loadInstructor(int a,string b,string c)
{
InstructorID=a;
InstructorName=b;
Expertise=c;
}
void printInstructor()
{
cout<<"\t| ";
cout.width(8);cout<<InstructorID<<" | ";
cout.width(16);cout<<InstructorName<<" | ";
cout.width(10);cout<<Expertise<<" | ";
cout<<endl;
}
};
//Class end
//declare
DataComm a [20];
AI b [20];
SecuTech c [20];
Robotics d [20];
Mechanical e [20];
ApprovalManage display[2];
Instructor Instructorlist[2];
onApproval Approvallist[100];
Bookingbooking display1[2];
onBook BookList[100];
Sitting Bookinglist [20];
//load approval code
void loadApprovalManagedata(){
display[0].addApprovalManage("G","Good",0);
display[1].addApprovalManage("B" ,"Bad",0);
}
//load booking information
void loadBookingbookingdata(){
display1[0].addBookingbooking("S1","10.00AM",0);
display1[1].addBookingbooking("S2","2.00PM",0);
}
//load Booking information
void loadBookingdata(){
Bookinglist[0].makeBooking(1,"DataComm",0,"Big");
Bookinglist[1].makeBooking(2,"DataComm",0,"Big");
Bookinglist[2].makeBooking(3,"DataComm",0,"Big");
Bookinglist[3].makeBooking(4,"DataComm",0,"Medium");
Bookinglist[4].makeBooking(5,"DataComm",0,"Medium");
Bookinglist[5].makeBooking(6,"DataComm",0,"Medium");
Bookinglist[6].makeBooking(7,"AI",0,"Big");
Bookinglist[7].makeBooking(8,"AI",0,"Big");
Bookinglist[8].makeBooking(9,"AI",0,"Medium");
Bookinglist[9].makeBooking(10,"AI",0,"Medium");
Bookinglist[10].makeBooking(11,"Robotics",0,"Big");
Bookinglist[11].makeBooking(12,"Robotics",0,"Big");
Bookinglist[12].makeBooking(13,"Robotics",0,"Medium");
Bookinglist[13].makeBooking(14,"SecuTech",0,"Big");
Bookinglist[14].makeBooking(15,"SecuTech",0,"Big");
Bookinglist[15].makeBooking(16,"SecuTech",0,"Medium");
Bookinglist[16].makeBooking(17,"SecuTech",0,"Medium");
Bookinglist[17].makeBooking(18,"Mechanical",0,"Big");
Bookinglist[18].makeBooking(19,"Mechanical",0,"Big");
Bookinglist[19].makeBooking(20,"Mechanical",0,"Medium");
}
//load Instructor information
void loadInstructordata(){
Instructorlist[0].loadInstructor(801, "Gopinath Ulaganathan","AI");
Instructorlist[1].loadInstructor(802, "Bee Loon","Tiger");
}
//Header
void header () {
col(14);
col(5);
col(7);
cout<<endl<<endl;
}
void DisplayLablist()
{
system("cls");
cout<<"\t|--------------------------------------------------------|"<<endl;
cout<<"\t| ___MMM___ MMU LAB ___MMM___ |"<<endl;
cout<<"\t| (0-0) Laboratories List (0-0) |"<<endl;
cout<<"\t| ---oOOCYBEROOo-- ---oOOCYBEROOo-- |"<<endl;
cout<<"\t|--------------------------------------------------------|"<<endl;
cout<<"\t==================================================="<<endl;
cout<<"\t| DataComm |"<<endl;
cout<<"\t==================================================="<<endl;
cout<<"\t| ID | Lab Name | Code | Session |"<<endl;
cout.setf(ios::left);
cout<<"\t|--------------------------------------------------|"<<endl;
for(int i=0;i<totallabA;i++)
{
a[i].displayLab();
}
cout<<"\t|-------------------------------------------------|"<<endl;
if (totallabA ==0){
cout<<"\t| NONE |\n";
}
cout<<"\n\t==================================================="<<endl;
cout<<"\t| AI |"<<endl;
cout<<"\t==================================================="<<endl;
cout<<"\t| ID | Lab Name | Code |Session|"<<endl;
cout.setf(ios::left);
cout<<"\t|-------------------------------------------------|"<<endl;
for(int i=0;i<totallabB;i++)
{
b[i].displayLab();
}
cout<<"\t|-------------------------------------------------|"<<endl;
if (totallabB ==0){
cout<<"\t| NONE |\n";
cout<<"\t|-------------------------------------------------|"<<endl;
}
cout<<"\n\t==================================================="<<endl;
cout<<"\t| SecuTech |"<<endl;
cout<<"\t==================================================="<<endl;
cout<<"\t| ID | Lab Name | Code |Session|"<<endl;
cout.setf(ios::left);
cout<<"\t|-------------------------------------------------|"<<endl;
for(int i=0;i<totallMMU ;i++)
{
d[i].displayLab();
}
cout<<"\t|-------------------------------------------------|"<<endl;
if (totallMMU ==0){
cout<<"\t| NONE |\n";
cout<<"\t|-------------------------------------------------|"<<endl;
}
cout<<"\n\t==================================================="<<endl;
cout<<"\t| Robotics |"<<endl;
cout<<"\t==================================================="<<endl;
cout<<"\t| ID | Lab Name | Code |Session|"<<endl;
cout.setf(ios::left);
cout<<"\t|-------------------------------------------------|"<<endl;
for(int i=0;i<totallabD;i++)
{
c[i].displayLab();
}
cout<<"\t|-------------------------------------------------|"<<endl;
if (totallabD ==0){
cout<<"\t| NONE |\n";
cout<<"\t|-------------------------------------------------|"<<endl;
}
cout<<"\n\t==================================================="<<endl;
cout<<"\t| Mechanical |"<<endl;
cout<<"\t==================================================="<<endl;
cout<<"\t| ID | Lab Name | Code |Session|"<<endl;
cout.setf(ios::left);
cout<<"\t|-------------------------------------------------|"<<endl;
for(int i=0;i<totalMechanical;i++)
{
e[i].displayLab();
}
cout<<"\t|-------------------------------------------------|"<<endl;
if (totalMechanical ==0){
cout<<"\t| NONE |\n";
}
cout.unsetf(ios::left);
cout<<"\t___________________________________________________"<<endl;
cout<<"\t==================================================="<<endl;
cout.unsetf(ios::internal);
}
//Register Lab (menu 1)
void registernewLab(){
system ("cls");
int choice;
string LabName;
string Approval;
string session;
char choose[1];
//header();
cout<<"\t|---------------------------------------------------------|"<<endl;
cout<<"\t| ___MMM___ MMU LAB ___MMM___ |"<<endl;
cout<<"\t| (0-0) New Lab Registration (0-0) |"<<endl;
cout<<"\t| ---oOOCYBEROOo-- ---oOOCYBEROOo-- |"<<endl;
cout<<"\t|-------------------------------------------------------- |"<<endl;
do{
cout<<"\tPlease insert Lab name (3-24 characters): ";
cin>>LabName; //
}while (LabName.length() || LabName.length() >25);
do{
cout<<"\tPlease insert Lab Code (4-6 characters): ";
cin>>Approval;
} while (Approval.length() <4 || Approval.length() >6);
do{
cout<<"\tPlease insert Lab session (1-2 characters): ";
cin>>session;
}while (session.length() <1|| session.length() >2);
cout<<"\n\tPlease choose Lab categories: "<<endl;
cout<<"\t 1. DataComm"<<endl;
cout<<"\t 2. AI"<<endl;
cout<<"\t 3. SecuTech"<<endl;
cout<<"\t 4. Robotics"<<endl;
cout<<"\t 5. Mechanical"<<endl<<endl;
cout<<"\t 0. Exit"<<endl;
cout<<"\tPlease choose : ";
cin>>choice;
switch(choice)
{
case 1:
cout<<"\n\n\tRegistration for your DataComm was succesful!"<<endl;
a[totallabA].regLab(100+totallabA,LabName,Approval,session);
system ("cls");
break;
case 2:
cout<<"\n\n\tRegistration for your AI was succesful!"<<endl;
b[totallabB].regLab(200+totallabB,LabName,Approval,session);
system ("cls");
break;
case 3:
cout<<"\n\n\tRegistration for your SecuTech was succesful!"<<endl;
c[totallMMU].regLab(300+totallMMU,LabName,Approval,session);
system ("cls");
break;
case 4:
cout<<"\n\n\tRegistration for your Robotics was succesful!"<<endl;
d[totallabD].regLab(400+totallabD,LabName,Approval,session);
;
system ("cls");
break;
case 5:
cout<<"\n\n\tRegistration for your Mechanical was succesful!"<<endl;
e[totalMechanical].regLab(500+totalMechanical,LabName,Approval,session);
system ("cls");
break;
case 0: return;
}
return;
}
//display Approval status code (Menu 2)
void printApprovalManage()
{
system("cls");
cout<<"\t|---------------------------------------------------------|"<<endl;
cout<<"\t| ___MMM___ MMU LAB ___MMM___ |"<<endl;
cout<<"\t| (0-0) Lab Approval Status (0-0) |"<<endl;
cout<<"\t| ---oOO--(_)--OOo-- ---oOO--(_)--OOo-- |"<<endl;
cout<<"\t|---------------------------------------------------------|"<<endl;
cout<<"\t==================================="<<endl;
cout<<"\t| No. | Code | Approval Status |"<<endl;
cout<<"\t==================================="<<endl;
cout.setf(ios::left);
for(int i=0;i<2;i++)
{
display[i].displayApprovalRecord(i);
}
cout.unsetf(ios::left);
cout<<"\t___________________________________"<<endl;
cout<<"\t==================================="<<endl;
}
//display Approval status
void DisplayApprovalStatus ()
{
cout<<"\t======================================"<<endl;
cout<<"\t| No. | Approval Status | Lab ID | "<<endl;
cout<<"\t======================================"<<endl;
for(int i=0;i<totalonApproval;i++)
{
Approvallist[i].displayApprovalRecord(i);
}
cout<<"\t======================================"<<endl;
}
//add Lab Approval status (Menu 3-1)
void AddApproval()
{ string sts;
int LabID;
int checkLab=0;
char confirm[1];
string confirmbill;
char ApprovalManagechoosed[1];
DisplayLablist();
do{
do{
cout<<"\n\n\tPlease insert your Lab ID : ";
cin>>LabID;
checkLab=0;
for(int i=0;i<totallabA;i++){if(LabID == a[i].LabID){checkLab++;}};
for(int j=0;j<totallabB;j++){if(LabID == b[j].LabID){checkLab++;}};
for(int k=0;k<totallMMU;k++){if(LabID == c[k].LabID){checkLab++;}};
for(int l=0;l<totallabD;l++){if(LabID == d[l].LabID){checkLab++;}};
for(int m=0;m<totalMechanical;m++){if(LabID == e[m].LabID){checkLab++;}};
if (checkLab ==0){cout<<"\tThere is no such id.\n";}
}while(LabID<100||LabID>600 ||checkLab == 0);
printApprovalManage();
do{
cout<<"\tPlease choose Approval Code for Lab : ";
cout<<"\n\tG = Approved || B = Not Approved : ";
cin>>ApprovalManagechoosed;
cout<<endl;
}while(strcmp("G",ApprovalManagechoosed) != 0 && strcmp("B",ApprovalManagechoosed) != 0 );
string temp ="G";
if (ApprovalManagechoosed != temp )
sts = "Bad";
else
sts = "Good";
cout<<"\tLab Approval status : "<<endl;
cout<<"\tYour Lab ID : "<<LabID<<endl;
cout<<"\tApproval Status : "<<sts<<endl;
cout<<"\tIs this correct? (Y/N) : ";
cin>>confirm;
} while (strcmpi("Y",confirm) !=0);
string newid = sts;
Approvallist[totalonApproval].addrecord(newid,LabID, ApprovalManagechoosed);
cout<<"\tData saved...\n"<<endl;
};
//update Lab status (Menu 3-2)
void EditApproval(){
DisplayApprovalStatus();
string sts;
int LabID;
int checkLab=0;
string seemembers;
char confirm[1];
string confirmbill;
char ApprovalManagechoosed[3];
int choose;
do{
cout<<"\tPlease select the no. which to update : ";
cin>>choose;} while (choose<0 || choose>totalonApproval);
choose-=1;
for (int i=choose;i<=totalonApproval;i++)
{
Approvallist[i].Approvalsts = Approvallist[i+1].Approvalsts;
Approvallist[i].LabID = Approvallist[i+1].LabID;
strcpy(Approvallist[i].ApprovalManageID,Approvallist[i+1].ApprovalManageID);
}
strcpy(Approvallist[totalonApproval].ApprovalManageID,"");
totalonApproval--;
do{
do{
cout<<"\n\n\tPlease insert again Lab ID : ";
cin>>LabID;
checkLab=0;
for(int i=0;i<totallabA;i++){if(LabID == a[i].LabID){checkLab++;}};
for(int j=0;j<totallabB;j++){if(LabID == b[j].LabID){checkLab++;}};
for(int k=0;k<totallMMU;k++){if(LabID == c[k].LabID){checkLab++;}};
for(int l=0;l<totallabD;l++){if(LabID == d[l].LabID){checkLab++;}};
for(int m=0;m<totalMechanical;m++){if(LabID == e[m].LabID){checkLab++;}};
if (checkLab ==0){cout<<"\tLab id not in the list...\n";}
}while(LabID<100||LabID>600 ||checkLab == 0);
printApprovalManage();
do{
cout<<"\tPlease choose Approval Code for Lab : ";
cout<<"\n\tG = Good || B = Bad : ";
cin>>ApprovalManagechoosed;
cout<<endl;
}while(strcmp("G",ApprovalManagechoosed) != 0 && strcmp("B",ApprovalManagechoosed) != 0 );
string temp ="G";
if (ApprovalManagechoosed != temp )
sts = "Bad";
else
sts = "Good";
cout<<"\tLab Approval status : "<<endl;
cout<<"\tYour Lab ID : "<<LabID<<endl;
cout<<"\tApproval Status : "<<sts<<endl;
cout<<"\tIs this correct? (Y/N) : ";
cin>>confirm;
} while (strcmpi("Y",confirm) !=0);
string newid = sts;
Approvallist[totalonApproval].addrecord(newid,LabID, ApprovalManagechoosed);
cout<<"\tData saved.\n"<<endl;
};
//delete Lab Approval status (Menu 3-3)
void DeleteApproval(){
DisplayApprovalStatus();
int choose;
do{
cout<<"\tPlease select the no. to delete : ";
cin>>choose;} while (choose<0 || choose>totalonApproval);
choose-=1;
for (int i=choose;i<=totalonApproval;i++)
{
Approvallist[i].Approvalsts = Approvallist[i+1].Approvalsts;
Approvallist[i].LabID = Approvallist[i+1].LabID;
strcpy(Approvallist[i].ApprovalManageID,Approvallist[i+1].ApprovalManageID);
}
strcpy(Approvallist[totalonApproval].ApprovalManageID,"");
totalonApproval--;
};
//main menu for menu 3
void Approvalmenu()
{
int choice;
system("cls");
cout<<"\t|--------------------------------------------------------|"<<endl;
cout<<"\t| ___MMM___ MMU LAB ___MMM___ |"<<endl;
cout<<"\t| (0-0) Lab Approval Status (0-0) |"<<endl;
cout<<"\t| ---oOO--(_)--OOo-- Management ---oOO--(_)--OOo-- |"<<endl;
cout<<"\t|--------------------------------------------------------|"<<endl;
do
{
cout<<"\n\tPlease select option: "<<endl;
cout<<"\t 1. Add New Lab Approval Status"<<endl;
cout<<"\t 2. Update Lab Approval Status"<<endl;
cout<<"\t 3. Delete Lab Approval Status"<<endl;
cout<<"\t 4. Display Lab Approval Status"<<endl;
cout<<"\t 0. Exit"<<endl;
cout<<"\tPlease select option: ";
cin>>choice;
switch(choice)
{case 1: AddApproval();
break;
case 2: EditApproval();
break;
case 3: system("cls");
DeleteApproval();
break;
case 4: system("cls");
DisplayApprovalStatus();
break;
Default : cout<<"Invalid choose "<<endl;
break;
case0:return;
}
} while (choice !=0);
}
void printBookingbooking()
{
system("cls");
cout<<"\t|---------------------------------------------------------|"<<endl;
cout<<"\t| Lab Booking Time Table |"<<endl;
cout<<"\t|---------------------------------------------------------|"<<endl<<endl;
cout<<"\t==================================="<<endl;
cout<<"\t| No. | Code | Booking Time |"<<endl;
cout<<"\t==================================="<<endl;
cout.setf(ios::left);
for(int i=0;i<2;i++)
{
display1[i].displayBookRecord(i);
}
cout.unsetf(ios::left);
cout<<"\t____________________________________"<<endl;
cout<<"\t===================================="<<endl;
}
void DisplaybookingStatus ()
{
cout<<"\t======================================"<<endl;
cout<<"\t| No. | Lab ID | Booking Time |"<<endl;
cout<<"\t======================================"<<endl;
for(int i=0;i<totalonBook;i++)
{
BookList[i].displayBookRecord(i);
}
cout<<"\t======================================"<<endl;
}
// Add Lab Booking time (menu 5-1)
void AddBooking()
{ string sts;
int LabID;
int checkLab=0;
char confirm[1];
string confirmbill;
char Bookingbookingchoosed[8];
//cin>>seemembers;
DisplayLablist();
do{
do{
cout<<"\n\n\tPlease insert your Lab ID : ";
cin>>LabID;
checkLab=0;
for(int i=0;i<totallabA;i++){if(LabID == a[i].LabID){checkLab++;}};
for(int j=0;j<totallabB;j++){if(LabID == b[j].LabID){checkLab++;}};
for(int k=0;k<totallMMU;k++){if(LabID == c[k].LabID){checkLab++;}};
for(int l=0;l<totallabD;l++){if(LabID == d[l].LabID){checkLab++;}};
for(int m=0;m<totalMechanical;m++){if(LabID == e[m].LabID){checkLab++;}};
if (checkLab ==0){cout<<"\tThere is no such id.\n";}
}while(LabID<100||LabID>600 ||checkLab == 0);
printBookingbooking();
do{
cout<<"\tPlease choose Booking Time code for Lab : ";
cout<<"\n\tS1 = 10.00AM || S2 = 2.00PM : ";
cin>>Bookingbookingchoosed;
cout<<endl;
}while(strcmp("S1",Bookingbookingchoosed) != 0 && strcmp("S2",Bookingbookingchoosed) != 0 );
string chk ="S1";
if (Bookingbookingchoosed != chk )
sts = "2.00PM";
else
sts = "10.00AM";
cout<<"\tYour Lab ID : "<<LabID<<endl;
cout<<"\tBooking Time : "<<sts<<endl;
cout<<"\tIs this correct? (Y/N) : ";
cin>>confirm;
} while (strcmpi("Y",confirm) !=0);
string newid = sts;
BookList[totalonBook].addrecord(newid,LabID, Bookingbookingchoosed);
cout<<"\tData saved...\n"<<endl;
};
// Edit (5-2)
void EditBooking(){
DisplaybookingStatus();
string sts;
int LabID;
int checkLab=0;
string seemembers;
char confirm[1];
string confirmbill;
char Bookingbookingchoosed[8];
int choose;
do{
cout<<"\tPlease select the no. which to update : ";
cin>>choose;} while (choose<0 || choose>totalonBook);
choose-=1;
for (int i=choose;i<=totalonBook;i++)
{
BookList[i].bookingsts = BookList[i+1].bookingsts;
BookList[i].LabID = BookList[i+1].LabID;
strcpy(BookList[i].BookingbookingID,BookList[i+1].BookingbookingID);
}
strcpy(BookList[totalonBook].BookingbookingID,"---");
totalonBook--;
do{
do{
cout<<"\n\nPlease insert again Lab ID : ";
cin>>LabID;
checkLab=0;
for(int i=0;i<totallabA;i++){if(LabID == a[i].LabID){checkLab++;}};
for(int j=0;j<totallabB;j++){if(LabID == b[j].LabID){checkLab++;}};
for(int k=0;k<totallMMU;k++){if(LabID == c[k].LabID){checkLab++;}};
for(int l=0;l<totallabD;l++){if(LabID == d[l].LabID){checkLab++;}};
for(int m=0;m<totalMechanical;m++){if(LabID == e[m].LabID){checkLab++;}};
if (checkLab ==0){cout<<"\tLab id not in the list...\n";}
}while(LabID<100||LabID>600 ||checkLab == 0);
printBookingbooking();
do{
cout<<"\tPlease choose Booking Time code for Lab : ";
cout<<"\n\tS1 = 10.00AM || S2 = 2.00PM : ";
cin>>Bookingbookingchoosed;
cout<<endl;
}while(strcmp("S1",Bookingbookingchoosed) != 0 && strcmp("S2",Bookingbookingchoosed) != 0 );
string chk ="S1";
if (Bookingbookingchoosed != chk )
sts = "2.00PM";
else
sts = "10.00AM";
cout<<"\tYour Lab ID : "<<LabID<<endl;
cout<<"\tBooking Time : "<<sts<<endl;
cout<<"\tIs this correct? (Y/N) : ";
cin>>confirm;
} while (strcmpi("Y",confirm) !=0);
string newid = sts;
BookList[totalonBook].addrecord(newid,LabID, Bookingbookingchoosed);
cout<<"\tData saved.\n"<<endl;
};
void DeleteBooking(){
DisplaybookingStatus();
int choose;
do{
cout<<"\tPlease select the no. to delete : ";
cin>>choose;} while (choose<0 || choose>totalonBook);
choose-=1;
for (int i=choose;i<=totalonBook;i++)
{
BookList[i].bookingsts = BookList[i+1].bookingsts;
BookList[i].LabID = BookList[i+1].LabID;
strcpy(BookList[i].BookingbookingID,BookList[i+1].BookingbookingID);
}
strcpy(BookList[totalonBook].BookingbookingID,"---");
totalonBook--;
};
void Bookingmenu()
{
int choice;
system("cls");
cout<<"\t|--------------------------------------------------------|"<<endl;
cout<<"\t| ___MMM___ MMU LAB ___MMM___ |"<<endl;
cout<<"\t| (0-0) Lab Booking Time Management (0-0) |"<<endl;
cout<<"\t| ---oOOCYBERMelakaOOo-- ---oOOCYBEROOo-- |"<<endl;
cout<<"\t|--------------------------------------------------------|"<<endl;
do
{
cout<<"\n\tPlease select option: "<<endl;
cout<<"\t 1. Add Lab Booking Time"<<endl;
cout<<"\t 2. Update Lab Booking Time"<<endl;
cout<<"\t 3. Delete Lab Booking Time"<<endl;
cout<<"\t 4. Display Lab Booking Time"<<endl;
cout<<"\t 0. Exit"<<endl;
cout<<"\tPlease select option: ";
cin>>choice;
switch(choice)
{case 1: AddBooking();
break;
case 2: EditBooking();
break;
case 3: system("cls");
DeleteBooking();
break;
case 4: system("cls");
DisplaybookingStatus();
break;
Default : cout<<"Invalid choose "<<endl;
break;
case0:return;
}
} while (choice !=0);
}
//Assign Lab booking menu 4-1
void AssignBooking(){
DisplayApprovalStatus();
int id;
int Sittings;
bool BookingLab=false;
cout<<"\tPlease insert no. ";
cin>>id;
int x = Approvallist[id-1].LabID;
cout<<"\tLab ID : "<<x<<endl;
do {
if (x<=199){
do {cout<<"\tPlease select Lab booking : ";
cin>>Sittings;}while (Sittings<1||Sittings>6);}
else if (x<=299){do {cout<<"\tPlease select Lab booking : ";
cin>>Sittings;}while (Sittings<7||Sittings>10);}
else if (x<=399){do {cout<<"\tPlease select Lab booking : ";
cin>>Sittings;}while (Sittings<11||Sittings>13);}
else if (x<=499){do {cout<<"\tPlease select Lab booking : ";
cin>>Sittings;}while (Sittings<14||Sittings>17);}
else if (x<=599){do {cout<<"\tPlease select Lab booking : ";
cin>>Sittings;}while (Sittings<18||Sittings>20);}
if (Bookinglist[Sittings-1].LabonSittingID ==0){
Bookinglist[Sittings-1].assignBooking(x);
BookingLab = true;
cout<<"\n\tBookingd Completed\n"<<endl;
}
else
cout<<"\tThe Booking you select is full, please select another. "<<endl;
} while (BookingLab ==false);
};
//De assigning Lab booking (Menu 4.2)
void deAssignBooking(){
int Sittings;
bool BookingLab;
do {
cout<<"\tPlease select Lab booking you which to de assign"<<endl;
cout<<"\tPlease press 0 to cancel. :";
cin>>Sittings;
if (Bookinglist[Sittings-1].LabonSittingID !=0){
Bookinglist[Sittings-1].deassignBooking();
BookingLab = true;
cout<<"\n\tLab had de assign\n"<<endl;
}
else if(Sittings==0){}
else
cout<<"\tthe Sitting is empty, please select another: "<<endl;
} while (BookingLab ==false && Sittings!=0);
};
//statistics. (Menu 7)
void DisplayStats(){
cout<<"\t|---------------------------------------------------------|"<<endl;
cout<<"\t| ___MMM___ MMU LAB ___MMM___ |"<<endl;
cout<<"\t| (0-0) Statistic (0-0) |"<<endl;
cout<<"\t| ---oOO--(_)--OOo-- ---oOO--(_)--OOo-- |"<<endl;
cout<<"\t|---------------------------------------------------------|"<<endl;
//cout<<"\t\tLabs Good Status |"<<endl;
DisplayApprovalStatus();
cout<<"\t============================================================="<<endl;
cout<<"\tToday Lab Booking : "<<totalonBook<<" Bookings"<<endl;
cout<<"\tTotal DataComms Lab : "<<totallabA<<" Labs"<<endl;
cout<<"\tTotal AI Lab : "<<totallabB<<" Labs"<<endl;
cout<<"\tTotal SecuTechs Lab : "<<totallMMU<<" Labs"<<endl;
cout<<"\tTotal Robotics Lab : "<<totallabD<<" Labs"<<endl;
cout<<"\tTotal Mechanical Lab : "<<totalMechanical<<" Labs"<<endl;
cout<<"\tTotal All Lab : "<<totalbookingregister-1<<" Labs"<<endl;
cout<<"\t============================================================="<<endl;
};
//display Instructor table (menu 6)
void printInstructordata(){
{system("cls");
header();
cout<<"\t==================================================== "<<endl;
cout<<"\t| Instructor ID | Instructor Name | Field |"<<endl;
cout<<"\t===================================================="<<endl;
cout.setf(ios::left);
for(int i=0; i<2; i++)
{
Instructorlist[i].printInstructor();
}
cout.unsetf(ios::left);
cout<<"\t====================================================="<<endl;
}
};
//display Booking place menu
void Managebooking(){
system ("cls");
cout<<"\t|---------------------------------------------------------|"<<endl;
cout<<"\t| ___MMM___ MMU LAB ___MMM___ |"<<endl;
cout<<"\t| (0-0) Lab Booking Management (0-0) |"<<endl;
cout<<"\t| CYBER CYBER |"<<endl;
cout<<"\t|---------------------------------------------------------|"<<endl;
cout<<"\t===================================================="<<endl;
cout<<"\t| No. | Categories | Lab ID | Lab Size |"<<endl;
cout<<"\t====================================================="<<endl;
for (int x=0;x<20;x++)
{Bookinglist[x].printSitting();}
cout<<"\t===================================================="<<endl;
int choose;
do {
cout<<"\tPlease choose below option : "<<endl;
cout<<"\t 1. Assign Lab Booking"<<endl;
cout<<"\t 2. De assign Lab from Booking"<<endl;
cout<<"\t 3. Display Labs Booking"<<endl;
cout<<"\t 0. Exit"<<endl;
cout<<"\tInsert your choice : ";
cin>>choose;
switch (choose)
{case 1: AssignBooking();
break;
case 2: deAssignBooking();
break;
case 3: Managebooking();
break;
case 0:return;
default : system ("cls");cout<<"Invalid command."<<endl;
}
} while (choose !=0);
}
//main menu
void menu (){
system ("cls");
header ();
cout<<"\t\tWelcome to Lab Booking System"<<endl;
cout<<"\t\tPlease select the option: "<<endl<<endl;
cout<<"\t\t1. Register new Lab"<<endl;
cout<<"\t\t2. Lab Categories List"<<endl;
cout<<"\t\t3. Lab Approval Status Management"<<endl;
cout<<"\t\t4. Lab Booking Management"<<endl;
cout<<"\t\t5. Lab Booking Time"<<endl;
cout<<"\t\t6. Instructor Information"<<endl;
cout<<"\t\t7. Statistics"<<endl;
cout<<"\t\t8. Exit program"<<endl;
cout<<"\t\tPlease enter your choice : ";
}
void LoginMenu()
{
string Susername ="staff1",user;
string Spassword ="pass1",pass;
system("cls");
int i=0;
do
{
if( i==0 )
{
cout<<"\t|-----------------------------------------------------------|"<<endl;
cout<<"\t| ___MMM___ MMU LAB ___MMM___ |"<<endl;
cout<<"\t| (0-0) Management System (0-0) |"<<endl;
cout<<"\t| ---CYBER-- ---CYBER-- |"<<endl;
cout<<"\t|-----------------------------------------------------------|"<<endl;
}
cout<<"\tPlease Enter Your Username and Password"<<endl;
cout<<"\tUsername: ";
cin>>user;
cout<<"\tPassword: ";
cin>>pass;
if ((Susername == user) && (Spassword ==pass))
{
i=3;
}
else
{
i++;
system("cls");
cout<<endl<<"\tWrong password please insert correct password or check case sensetive"<<endl<<endl;
if (i==3)
{
cout<<"\tYou had failed to authenticate for 3 Times, system will Termination ! "<<endl<<endl;
cout<<"\tSystem Is Shutting Down !";
Sleep(3000);
exit(1);
}
}
}while(i<3);
}
//Main
int main () {
loadApprovalManagedata();
loadBookingbookingdata();
loadBookingdata();
loadInstructordata();
system ("Lab Booking System");
totalbookingregister++;
cout<<totalbookingregister;
int choice;
LoginMenu();
do {
menu();
cin>>choice;
switch(choice)
{case 1:
registernewLab();
break;
case 2:
DisplayLablist();
system ("pause");
break;
case 3:Approvalmenu();
break;
case 4:Managebooking();
break;
case 5:Bookingmenu();
break;
case 6: printInstructordata();
system ("pause");
break;
case 7:system("cls");
DisplayStats();
system ("pause");
break;
default :
cout<<"\tPlease Insert again..."<<endl;
break;
case 8:;
}
} while (choice !=8);
cout<<endl<<"System Close !"<<endl;
system ("pause");
return 0;
}
