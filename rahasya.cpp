#include<iostream>
#include <fstream>
#include <conio.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<windows.h>
#include<dos.h>
using namespace std;

class cryptography
{
public:
  int  date[3];
  char user[200];
  char pass[200];
  char data[10000];
  char encdata[10000];
  char encuser[200];
  char encpass[200];
  char decuser[200];
  char decpass[200];
  int encdate[3];
  int decdate[3];
  int datasize;

 void enteruserpass();
 void enterdate();
 void filetoarray();
 void encryptdata();
 void encryptdate();
 void encryptuserpass();
 void decryptuserpass();
 void decryptdata();
 void decryptdate();

};

class tofile{

public:
char data[10000];
char user[200];
char pass[200];
int  date[3];
int datasize;
char decuser[200];
char decpass[200];
void decryptuserpass();
};
void tofile::decryptuserpass()
{
 int a=strlen(user);
 int b=strlen(pass);
 int i;
 for(i=0;i<a+1;++i)
 {
  decuser[i]=user[i]-3;
 }
 for(i=0;i<b+1;++i)
 {
  decpass[i]=pass[i]-3;
 }
}

void cryptography:: filetoarray()
{
  char fname[15],inputholder;
  int i=0;
	cout<<"\nSpecify the name of the file you would like to Secure : ";
  gets(fname);
  fstream f;
  f.open(fname,ios::in);
  while(f.get(inputholder))
  {
   data[i]=inputholder;
   ++i;
  }
  datasize = i;
  cout<<"\nYour Data :\n\n";
 for(int j=0;j<i;++j)
 {
   cout<<data[j];
 }
 cout<<endl;
}


void cryptography::enteruserpass()
{
  cout<<"\nPlease enter authentication credentials:-";
  cout<<"\nUsername: ";
  gets(user);
  cout<<"\nPassword: ";
  gets(pass);
}

void cryptography::enterdate()
{
 cout<<"\nSelect the date on which you would like the file to be accesed: ";
 for(int i=0; i<3; ++i)
     cin>>date[i];
}

void cryptography::encryptdata()
{

 for(int i=0;i<datasize;++i)
 {
  encdata[i]=data[i]+3;
 }
}

void cryptography::encryptdate()
{
 for(int i=0;i<3;++i)
 {
  encdate[i]=date[i]+3;
 }
}

void cryptography::encryptuserpass()
{

 int a=strlen(user);
 int b=strlen(pass);
 int i;
 for(i=0;i<a+1;++i)
 {
  encuser[i]=user[i]+3;
 }
 for(i=0;i<b+1;++i)
 {
  encpass[i]=pass[i]+3;
 }
}


void cryptography::decryptuserpass()
{
 int a=strlen(user);
 int b=strlen(pass);
 int i;
 for(i=0;i<a+1;++i)
 {
  decuser[i]=user[i]-3;
 }
 for(i=0;i<b+1;++i)
 {
  decpass[i]=pass[i]-3;
 }
}

void rfile(char file[200], tofile& x)
{
  fstream infile;
  infile.open (file, ios::in);
  while( infile.read ( (char *)&x, sizeof(x) ) )
  infile.close();

}

void wfile(char file[200],tofile x)   //write encrypted data to file
{
fstream outfile;
outfile.open (file, ios::out);
outfile.write ( (char *)(&x), sizeof(x) );
outfile.close();
}
void encrypter()
{
  int i;
  char filename[200];
  tofile x;
  cryptography y;

  y.filetoarray();      //To select the file and copy the data necessary for encryption.
  y.enteruserpass();    //To enter username and password (reqd. for decryption).
  y.enterdate();        //To enter date the file can be opened.

  y.encryptdata();      //Encrypts data.
  y.encryptuserpass();  //Encrypts username and password.
  y.encryptdate();      //Encrypts date.

sleep(0.1);             //Encrytion loading screen.
clrscr();
cout<<"Encrypting";
for(i=0;i<4;++i)
{
    for(int j=0;j<4;++j)
{
    delay(500);
    cout<<".";
}
clrscr();
cout<<"Encrypting";

}
clrscr();
cout<<"Encryption Successful, Your Data is now Secure."
    <<"\nEncrypted using ROT3 - Ceaser Cipher Algorithm.";
  strcpy(x.user,y.encuser);           //copies all data to object 'x'.
  strcpy(x.data,y.encdata);
  strcpy(x.pass,y.encpass);
  for(i=0;i<3;++i)
  {
  x.date[i]=y.encdate[i];
  }
  x.datasize = y.datasize;

  cout<<"\n\nEnter destination filename : ";
  gets(filename);
  wfile(filename,x);                 //Writes object 'x' to file.
}

void decrypter()
{

  char filename[200];
  tofile x;
  int i;
  int datecomp[3],date[3];
  int dayu,monthu,yearu;
  char localuser[20],localpass[20];
  char entereduser[20],enteredpass[20];

  cryptography y;
  cout<<"\nEnter the name of the file you would like to access : ";
  gets(filename);
  rfile(filename,x);             //Reads data from .txt flie to object 'x'.

   y.enteruserpass();           //To enter username and password.


   x.decryptuserpass();    //Decrypts username and password from object 'x'.

   strcpy(localuser,x.decuser); //Copies decrypted username,password to local variable (read from file).
   strcpy(localpass,x.decpass);
   strcpy(entereduser,y.user);  //Copies username,password (entered by user).
   strcpy(enteredpass,y.pass);

   dayu=x.date[0];       //Copies date to local variable from object 'x'.
   monthu=x.date[1];
   yearu=x.date[2];

     struct dosdate_t d;                //To get system date.
    _dos_getdate(&d);
     for(i=0;i<3;++i)
     {
      if(i==0)
      {
      date[i]=d.day;
      datecomp[i]=date[i]+3;
      }
      else if(i==1)
      {
      date[i]=d.month;
      datecomp[i]=date[i]+3;
      }
      else
      {
      date[i]=d.year;
      datecomp[i]=date[i]+3;
      }
     }
				      //datecomp is present system date.



  if ( dayu==datecomp[0] &&  monthu==datecomp[1] &&  yearu==datecomp[2])  //check date.
  {
  if((strcmp(localuser,entereduser)==0) && (strcmp(localpass,enteredpass)==0))  //check username and password.
  {
      char ddata[10000];
      delay(100);
      clrscr();

     cout<<"Checking system date";
     for(int i=0;i<4;++i)
   {
      for(int j=0;j<4;++j)
     {
       delay(500);
       cout<<".";
     }
    clrscr();
    cout<<"Checking system date";
    cout<<"... [Done]"<<"\nDecrypting";

   }
    cout<<"\nDecryption Successful, You now have access to your data.\n\n";

    for(int i=0;i<x.datasize;i++)
    ddata[i]=x.data[i]-3;
    puts(ddata);
    cout<<"\n\n\nPress any key to continue.";
   }

  else
  {
  cout<<"\nThe Username-Password combination you have entered is incorrect.\nPress any key to continue.\n";
  }
 }
  else
  cout<<"\nThe File cannot be accessed today, please try again later.";
  getch();

}



int main()
{
	_setcursortype(_NOCURSOR);             //to remove cursor (under conio.h)
	int menu_choice = 0;
	clrscr();
	cout<<"\n\n\n\n\n\n\n\t\tRahasya is a tool that provides Protection \n\t\tfor your data by Encryption Files and allowing safe\n\t\taccess through Decryption.";
	delay(4000);
	clrscr();
	cout<<"OH NO, YOU DIDN'T SEE THIS";   //Sublimal
	delay(100);                           //Sublimal
	clrscr();                             //Sublimal
	cout<<"\n\n\n\n\n\n\n\t\tRahasya/R`a`hasya.\n\t\t1.Discretion \n\t\t2.A Highly Restricted Piece of \n\t\tInformation meant for few eyes only.";
	delay(4000);
	clrscr();
	
	_setcursortype(_NORMALCURSOR);         //to show cursor (under conio.h)
	do{
		cout<<"\n\t\tRAHASYA - A tool for fortification of your data\n";
		cout<<"\t\t-----------------------------------------------";
		cout<<" \nWhat would you like to do?\n 1) Encrypt \n 2) Decrypt \n"
    		<<" 9) Exit\n \n--> ";
		cin>>menu_choice;
		switch(menu_choice)
		{
  			case 1: encrypter();break;       //To encrypt data.
  			case 2: decrypter();break;       //To decrypt data.
  			case 9: clrscr();                //To exit program.
  			_setcursortype(_NOCURSOR);
  			cout<<"\n\n\n\n\n\n\t\t\tThank you for using Rahasya.";
  			delay(1500);
  			exit(0);
  			default: break;
		}
		clrscr();
	}while(menu_choice != 9);
	return 0;
}

