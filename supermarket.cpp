#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
class Bill{
	private:
		string Item;
		int Rate , Quantity;
		public:
		Bill():Item(""),Rate(0),Quantity(0){ }
		void setItem(string item)
		{
			Item=item;
		}
		void setRate(int rate)
		{
			Rate=rate;
		}
		void setQuant(int quantity)
		{
			Quantity=quantity;
		}
		string  getItem(){
			return Item;
		}
		int getRate(){
			return Rate;
		}
		int getQuantity(){
			return Quantity;
		}		
		
};
addItem(Bill b)
{
	 bool close=false;
	 while(!close)
	 {
	 	int choice;
		 cout<<"\t1.Add."<<endl;
		 cout<<"\t2.Close."<<endl;
		 cout<<"\tEnter Choice: ";
		 cin>>choice; 
		 if(choice==1)
		 {
		 	system("cls");
		 	string item;
		 	int rate,quant;
		 	cout<<"\tEnter Item Name:";
		 	cin>>item;
		 	b.setItem(item);
		 	cout<<"\tEnter Rate Of Item:";
		 	cin>>rate;
		 	b.setRate(rate);
		 	cout<<"\tEnter Quantity Of Item:";
		 	cin>>quant;
		 	b.setQuant(quant);
		 	ofstream out("Bill.txt",ios::app);
		 	if(!out)
		 	{
		 		cout<<"\tError: File Can't Open! "<<endl;
		 		
			 }
			 else{
			 	

                out << "\t" << b.getItem() << " : " << b.getRate() << " : " << b.getQuantity() << endl << endl;
                cout << "\tItem Added Successfully!" << endl;
			 }
			 out.close();

		 }
		 else if(choice==2){
		 	close=true;
		 	cout<<"\tBack to Main Menu! "<<endl;
		 }
	}

}
printBill()
{
	int count=0;
	bool close=false;
	while(!close)
	{
		int choice;
		cout<<"\t1.Add Bill."<<endl;
		cout<<"\t2.Close Session."<<endl;
		cout<<"\tEnter Choice:"<<endl;
		cin>>choice;
	
	if(choice==1)
	{
		string item;
		int quant;
		cout<<"\tEnter Item: ";
		cin>>item;
		cout<<"\tEnter Quantity: ";
		cin>>quant;
		ifstream in("Bill.txt");
		ofstream out("Bill Temp.txt");
		string line;
		bool found=false;
		while(getline(in,line))
		{
			stringstream ss;
			ss<<line;
			string itemName;
			int itemRate;
			int itemQuant;
			char delimiter;
			ss>>itemName>>delimiter>>itemRate>>delimiter>>itemQuant;
			if(item == itemName)
			{
				found=true;
				if(quant <= itemQuant )
				{
					int amount = itemRate *quant;
					cout<<"\t Item | Rate | Quantity | Amount "<<endl;
					cout<<"\t"<<itemName<<"\t "<<itemRate<<"\t "<<quant<<"\t "<<amount<<endl;
					int newQuant = itemQuant-quant;
					itemQuant=newQuant;
					count+=amount;
					 out<<"\t"<<itemName<<" : "<<itemRate<<" : "<<itemQuant<<endl;
				}
				else{
				//not quantity < 
					
					cout<<"\tSorry ,"<<item<<"OUT OF STOCK!"<<endl;
				}
			}
			else{
				//not item found
				out<<line<<endl;
				
			}
		}
		if(!found)
		{
			cout<<"\tItem NOT AVAILABLE!"<<endl;
		}
		out.close();
		in.close();
		remove("Bill.txt");
		rename("Bill temp.txt","Bill.txt");
	}
	
	else if(choice==2)
	{
		close=true;
		cout<<"\tCounting Total Bill"<<endl;
		}	
	}
	system("cls");
	cout<<endl<<endl;
	cout<<"\t Total Bill ---------------------- :"<<count<<endl<<endl;
	cout<<"\tThanks For Shopping!"<<endl;
}
int main()
{
	Bill b;
	bool exit=false;
	while(!exit)
	{
		int val;
		cout<<"\tWelcome To Super Market Billing System"<<endl;
		cout<<"\t************************************"<<endl;
		cout<<"\t\t1.Add Item."<<endl;
		cout<<"\t\t2.Print Bill."<<endl;
		cout<<"\t\t3.Exit."<<endl;
		cout<<"\t\tEnter Choice"<<endl;
		cin>>val;
		if(val==1)
		{
			addItem(b);
		}
		else if(val==2)
		{
			printBill();
		}
		else if(val==3)
		{
			exit=true;
			cout<<"\t Good Luck!"<<endl;
		}
	}
}
