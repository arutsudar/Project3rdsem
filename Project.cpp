#include"stdio.h"
#include"iostream.h"
#include"string.h"
#include"fstream.h"
#include"stdlib.h"
#include"conio.h"
class ingredients
{
public :

    ingredients()
    {
	ofstream fout ("ingredient.txt");
	fout<<"Water- "<<"L\n";
	fout<<"Oil- "<<"L\n";
	fout<<"Carrot- "<<"Kg\n";
	fout<<"Ginger- "<<"Kg\n";
	fout<<"Garlic- "<<"Kg\n";
	fout<<"Capsicum- "<<"Kg\n";
	fout<<"BlackPepper- "<<"g\n";
	fout.close();
    }
    void value();
};
void ingredients::value()
{
	float x;
	int s;
	char ch[30];
	fstream fout("ingredient.txt",ios::in|ios::out);
	fstream file("temp.txt",ios::in|ios::out);
	if((!fout)||(!file))
	{
		cout<<"file not opened"<<endl;
		getch();
		return ;
	}
	while(!fout.eof())
	{
		fout>>ch;
		s=strlen(ch);
		if(ch[s-1]=='-')
		{
			file<<ch;
			if(fout.eof())
				break;
			cout<<"\nEnter "<<ch<<"\b quantity ";
			cin>>x;
			cout<<x;
			file<<x;
		}
		else
		{
			file<<ch;
			file<<'\n';
		}
	}
	fout.close();
	file.close();
	remove("ingredients.txt");
	rename("temp.txt","ingredients.txt");
}
class choice
{
	int c,s;
	char ch;
	public :
		choice()
		{
			clrscr();
			cout<<"\nEnter your choice of food :\n1.Noodles.\n2.Exit.\n";
			cin>>c;
			if(c==1)
			{
				fstream fout("ingredient.txt",ios::in|ios::out);
				for(int i=0;!fout.eof();i++)
				{
					if(ch=='-')
					{

					}
				}
				fout.close();
			}
		}
};
int main()
{
    clrscr();
    ingredients ing;
    ing.value();
    choice cho;
    getch();
    return 0;
}
