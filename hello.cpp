// hello.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
//#include <gmpxx>
using namespace std;
void dispreg(string a)
{
	for (int i = 0; i < 16; i++)
	{
		cout << a[i];
	}

}
uint16_t AX = 0;
string ax = "0000000000000000";
uint16_t BX = 0;
string bx = "0000000000000000";
uint16_t  CX = 0;
string cx = "0000000001110000";
uint16_t DX = 0;
string dx = "0000001001000000";
uint16_t SP = 0;
string sp = "0001010100000000";
uint16_t BP = 0;
string bp = "0000000000000000";
uint16_t SI = 0;
string si = "0000000000000000";
uint16_t DI = 0;
string di = "0000000000000000";
uint16_t CS = 0;
string cs = "0000000000000000";
uint16_t DS;
string ds = "0000000000000000";
uint16_t SS = 0;
string ss = "0000000000000000";
uint16_t ES = 0;
string es = "0000000000000000";
uint16_t IP = 0;
string ip = "0000000000000000";
int cf=0; int sf = 0; int zf = 0; int af = 0; int of = 0;
void refresh()
 {
	cf = 0;
	of = 0;

} 

string adder(string one, string two)
{

	string res = "0000000000000000";


	for (int i = 15; i >= 0; --i)
	{
		switch (cf)
		{
		case 0:

			if (one[i] == '0' && two[i] == '0')
			{

				res[i] = '0';
				cf = 0;
			}

			if (one[i] == '1' && two[i] == '0' || one[i] == '0' && two[i] == '1')
			{
				res[i] = '1';
				cf = 0;
			}

			if (one[i] == '1' && two[i] == '1')
			{
				res[i] = '0';
				cf = 1;
			}
			break;



		case 1:

			if (one[i] == '0' && two[i] == '0')
			{
				res[i] = '1';
				cf = 0;
			}

			if (one[i] == '1' && two[i] == '0' || one[i] == '0' && two[i] == '1')
			{
				res[i] = '0';
				cf = 1;
			}

			if (one[i] == '1' && two[i] == '1')
			{
				res[i] = '1';
				cf = 1;
			}
			break;

		}

		if (i == 0 && cf == 1)
		{
			of = 1;
		}

	}

	cout << "of flag was set to- " << of << "  cf flag was set to-  " << cf;

	refresh();

	//cout<<res<<" of ="<<of;
	return res;
}

string Twoscomp(string n)
{
	string nr = n;
	for (int i = 0; i < n.length(); ++i)
	{
		if (n[i] == '0')
		{
			nr[i] = '1';
		}

		if (n[i] == '1')
		{
			nr[i] = '0';
		}
	}
	string a;
	a = adder(nr, "0000000000000001");
	refresh();
	return a;
}

void regvalues()
{
	cout << "AX == "; cout << ax << '\n';
	cout << "BX==  "; cout<< bx<< '\n';
	cout << "CX== "; cout<<cx << '\n';
	cout << "DX== "; cout<<dx << '\n';
	cout << "SP==  "; cout<<sp<< '\n';
	cout << "BP== "; cout <<bp<< '\n';
	cout << "SI== "; cout <<si<< '\n';
	cout << "DI== "; cout <<di<< '\n';
	cout << "CS== "; cout <<cs<< '\n';
	cout << "DS== "; cout << ds<<'\n';
	cout << "SS== "; cout <<ss<< '\n';
	cout << "ES== "; cout <<es <<'\n';
	cout << "IP== "; cout <<ip<< '\n';
	cout << "cf= " << cf << " of=" << of << " zf="<<zf << " sf=" << sf<<" af=" << af;

}

string subtrct(string a, string b)
{

	string e = Twoscomp(b);
	string f = adder(a, e);
	refresh();
	return f;
}

string *REG(string r)
{
	if (r == "000")
	{
		string * p = &ax;
		return p;
	}
	if (r == "011")
	{
		string * p = &bx;
		return p;
	}
	if (r == "001")
	{
		string * p = &cx;
		return p;
	}
	if (r == "010")
	{
		string * p = &dx;
		return p;
	}
	if (r == "100")
	{
		string * p = &sp;
		return p;
	}
	if (r == "101")
	{

		string * p = &bp;
		return p;
	}
	if (r == "110")
	{
		string * p = &si;
		return p;
	}
	if (r == "111")
	{
		string * p = &di;
		return p;
	}
	
}

string RorM(string r)
{
	if (r == "000")
	{
		return "ax";
	}
	if (r == "001")
	{
		return "bx";
	}
	if (r == "010")
	{
		return "cx";
	}
	if (r == "011")
	{
		return"dx";
	}
	if (r == "100")
	{
		return "sp";
	}
	if (r == "101")
	{

		return "bp";
	}
	if (r == "110")
	{
		return "si";
	}
	if (r == "111")
	{
		return "di";
	}
}
//////////////////////////////
string addBinary(string a, string b)
{
	string result = ""; // Initialize result 
	int s = 0;          // Initialize digit sum 

	// Traverse both strings starting from last 
	// characters 
	int i = a.size() - 1, j = b.size() - 1;
	while (i >= 0 || j >= 0 || s == 1)
	{
		// Comput sum of last digits and carry 
		s += ((i >= 0) ? a[i] - '0' : 0);
		s += ((j >= 0) ? b[j] - '0' : 0);

		// If current digit sum is 1 or 3, add 1 to result 
		result = char(s % 2 + '0') + result;

		// Compute carry 
		s /= 2;

		// Move to next digits 
		i--; j--;
	}
	return result;
}
///////////////////////////////////////



string getbyte(char *a,int n)
{
	string byte = "00000000";
	for (int i = 0; i < 8; i++)
	{
		byte[i] = a[n * 8 + i];
	}
	return byte;
}

string printBinary16(int c) {
	string num(16, '0');
	for (int i = 15; i >= 0; --i) {
		num[15-i]=char(((c & (1 << i)) ? '1' : '0'));
	}
	return num;
}

string printBinary8(int c) {
	string num(8, '0');
	for (int i = 7; i >= 0; --i) {
		num[7-i] = char(((c & (1 << i)) ? '1' : '0'));
	}
	return num;
}
//////////////////////////////////////////////////// inc

int INCtest(char* a, int *n)
{
	string form1 = "01000";
	

	string b1 = getbyte(a, *n);
	

	string inst = b1.substr(0, 5);
	
	if (form1.compare(inst)==0)
	{
		
		return 3;
	}


	

	else
		return 0;

}
void INCinst(char* a, int *n)
{
	string form1 = "01000";


	string b1 = getbyte(a, *n);


	string inst = b1.substr(0, 5);
	if (form1 == inst)
	{
		string inst1 = b1.substr(5, 3);
		*REG(inst1) = adder("0000000000000001", *REG(inst1) );
		*n = *n + 1;
	}


}
////////////////////////////////////////////////////
int ADDtest(char* a, int *n)
{
	string form1 = "000000";
	//string form2 = "1100011";
	string form3 = "0000010";

	string b1 = getbyte(a, *n);


	string inst = b1.substr(0, 6);
	if (!form1.compare(inst))
	{
		return 2;
	}
	

	string inst2 = b1.substr(0, 7);
	if (inst2 == form3)
	{
		return 2;
	}

	else 
		return 0;

}
void ADDinst(char* a, int* n)
{
	string form1 = "000000";
	string form3 = "0000010";

	string b1 = getbyte(a, *n);
	*n = *n + 1;

	string inst = b1.substr(0, 6);
	if (form1 == inst)
	{
		string act = b1;
		if (act[6] == '1')
		{//reg is the destination reg = r/m
			if (act[7] == '1')
			{/////its a word
				string nxtbt = getbyte(a, *n);
				string regbinary = nxtbt.substr(2, 3);
				string *p1 = REG(regbinary);

				string rorgbinary = nxtbt.substr(5, 3);
				string* p2 = REG(rorgbinary);

				*p1 = adder(*p1, *p2);
				*n = *n + 1;

			}
			if (act[7] == '0')
			{/////its a word
				string nxtbt = getbyte(a, *n);
				string regbinary = nxtbt.substr(2, 3);
				string *p1 = REG(regbinary);

				string rorgbinary = nxtbt.substr(5, 3);
				string* p2 = REG(rorgbinary);

				*p1 = adder(*p1, *p2);
				*n = *n + 1;

			}

		}

		if (act[6] == '0')
		{//r/m is the destination r/m = reg
			if (act[7] == '1')
			{/////its a word
				string nxtbt = getbyte(a, 1);
				string regbinary = nxtbt.substr(2, 3);
				string *p1 = REG(regbinary);

				string rorgbinary = nxtbt.substr(5, 3);
				string* p2 = REG(rorgbinary);

				*p2 = adder(*p1, *p2);

			}
			if (act[7] == '0')
			{/////its a byte
				string nxtbt = getbyte(a, 1);
				string regbinary = nxtbt.substr(2, 3);
				string *p1 = REG(regbinary);

				string rorgbinary = nxtbt.substr(5, 3);
				string* p2 = REG(rorgbinary);

				*p2 = adder(*p1, *p2);

			}

		}
		//return;
	}

	string inst2 = b1.substr(0, 4);


	if (inst2 == form3)
	{

		string act2 = b1;



		if (act2[7] == '1')
		{


			

			
			string by1 = getbyte(a, *n);
			*n = *n + 1;
			string by2 = getbyte(a, *n);
			ax = adder(ax, by2 + by1);


		}


		if (act2[7] == '0')
		{


			
			ax = adder(ax, getbyte(a, *++n));
		}
	}

}


/////////////////////////////////////////////////
int Movtest(char* a,int *n)
{
	string form1 = "100010";
	string form2 = "1100011";
	string form3 = "1011";

	string b1 = getbyte(a, *n);
	

	string inst = b1.substr(0, 6);
	if (form1 == inst)
	{
		return 1;
	}
	
   
   	string inst2 = b1.substr(0, 4);
	if (inst2 == form3)
	{
		return 1;
	}

	else
		return 0;

}

void Movinst(char* a, int* n )
{
	string form1 = "100010";
	string form3 = "1011";

	string b1 = getbyte(a, *n);
	*n = *n + 1;

	string inst = b1.substr(0, 6);
	if (form1 == inst)
	{  string act = b1;
		if (act[6] == '1')
		{//reg is the destination reg = r/m
			if (act[7]=='1')
			{/////its a word
				
				string nxtbt = getbyte(a, *n);
				string regbinary = nxtbt.substr(2, 3);
				string *p1 = REG(regbinary);

				string rorgbinary = nxtbt.substr(5, 3);
				string* p2 = REG(rorgbinary);
				*n = *n + 1;
				*p1 = *p2;
				
		       
			}
			if (act[7] == '0')
			{/////its a word
				string nxtbt = getbyte(a, *n);
				string regbinary = nxtbt.substr(2, 3);
				string *p1 = REG(regbinary);

				string rorgbinary = nxtbt.substr(5, 3);
				string* p2 = REG(rorgbinary);

				*p1 = *p2;
				*n = *n + 1;

			}

		}

		if (act[6] == '0')
		{//r/m is the destination r/m = reg
			if (act[7] == '1')
			{/////its a word
				string nxtbt = getbyte(a, 1);
				string regbinary = nxtbt.substr(2, 3);
				string *p1 = REG(regbinary);

				string rorgbinary = nxtbt.substr(5, 3);
				string* p2 = REG(rorgbinary);

				*p2 = *p1;

			}
			if (act[7] == '0')
			{/////its a byte
				string nxtbt = getbyte(a, 1);
				string regbinary = nxtbt.substr(2, 3);
				string *p1 = REG(regbinary);

				string rorgbinary = nxtbt.substr(5, 3);
				string* p2 = REG(rorgbinary);

				*p2 = *p1;

			}

		}
		//return;
	}

	string inst2 = b1.substr(0, 4);
	
	
	if (inst2 == form3)
	{
		
		string act2 = b1;
		
		
		
		if (act2[4] == '1')
		{
	
			
			string regbinary = act2.substr(5, 3);
			
				string *p = REG(regbinary);

				string by1 = getbyte(a,* n);
			cout << by1 << " byte1   ";
				*n = *n + 1;
				
				string by2 = getbyte(a, *n);
				
				cout << by2 << " byte2   ";
				//cout << *p << "   ---p"<<*n;
				*p = by2 + by1;
				//*n = *n + 1;
				//cout << *p << "   ---p"<<*n;
				

		}
		
		
		if (act2[4] == '0')
		{
			
			
			string regbinary = act2.substr(5, 3);
			string *p = REG(regbinary);
			
			*p = getbyte(a, *n);
			*n = *n + 1;

		}
	}  

}
/////////////////////////////////////////////////move test 

/////////////////////////////////

int SUBtest(char* a, int *n)
{
	string form1 = "001010";
	
	string form3 = "0010110";

	string b1 = getbyte(a, *n);


	string inst = b1.substr(0, 6);
	if (form1 == inst)
	{
		return 4;
	}


	string inst2 = b1.substr(0, 7);
	if (inst2 == form3)
	{
		return 4;
	}

	else
		return 0;

}

void SUBinst(char* a, int* n)
{
	string form1 = "001010";

	string form3 = "0010110"; 

	string b1 = getbyte(a, *n);
	*n = *n + 1;

	string inst = b1.substr(0, 6);
	if (form1 == inst)
	{
		string act = b1;
		if (act[6] == '1')
		{//reg is the destination reg = r/m
			if (act[7] == '1')
			{/////its a word

				string nxtbt = getbyte(a, *n);
				string regbinary = nxtbt.substr(2, 3);
				string *p1 = REG(regbinary);

				string rorgbinary = nxtbt.substr(5, 3);
				string* p2 = REG(rorgbinary);
				*n = *n + 1;
				*p1 = subtrct(*p1,*p2);


			}
			if (act[7] == '0')
			{/////its a word
				string nxtbt = getbyte(a, *n);
				string regbinary = nxtbt.substr(2, 3);
				string *p1 = REG(regbinary);

				string rorgbinary = nxtbt.substr(5, 3);
				string* p2 = REG(rorgbinary);

				*p1 = subtrct(*p1, *p2);
				*n = *n + 1;

			}

		}

		if (act[6] == '0')
		{//r/m is the destination r/m = reg
			if (act[7] == '1')
			{/////its a word
				string nxtbt = getbyte(a, 1);
				string regbinary = nxtbt.substr(2, 3);
				string *p1 = REG(regbinary);

				string rorgbinary = nxtbt.substr(5, 3);
				string* p2 = REG(rorgbinary);

				*p2 = subtrct(*p2, *p1);

			}
			if (act[7] == '0')
			{/////its a byte
				string nxtbt = getbyte(a, 1);
				string regbinary = nxtbt.substr(2, 3);
				string *p1 = REG(regbinary);

				string rorgbinary = nxtbt.substr(5, 3);
				string* p2 = REG(rorgbinary);

				*p2 = subtrct(*p2, *p1);

			}

		}
		//return;
	}

	string inst2 = b1.substr(0, 7);


	if (inst2 == form3)
	{

		string act2 = b1;



		if (act2[7] == '1')
		{


			string regbinary = act2.substr(5, 3);

			string *p = REG(regbinary);

			string by1 = getbyte(a, *n);
			cout << by1 << " byte1   ";
			*n = *n + 1;

			string by2 = getbyte(a, *n);

			cout << by2 << " byte2   ";
			//cout << *p << "   ---p"<<*n;
			*p = subtrct(*p,by2 + by1);
			//*n = *n + 1;
			//cout << *p << "   ---p"<<*n;


		}


		if (act2[7] == '0')
		{


			string regbinary = act2.substr(5, 3);

			string *p = REG(regbinary);

			string by1 = getbyte(a, *n);
			cout << by1 << " byte1   ";
			*n = *n + 1;

			string by2 = getbyte(a, *n);

			cout << by2 << " byte2   ";
			//cout << *p << "   ---p"<<*n;
			*p = subtrct(*p, by2 + by1);
			//*n = *n + 1;
			//cout << *p << "   ---p"<<*n;

		}
	}

}

//////////////////////////////////
int XCHGtest(char* a, int *n)
{
	string form1 = "1000011";
	string form3 = "10010";

	string b1 = getbyte(a, *n);


	string inst = b1.substr(0, 7);
	if (form1 == inst)
	{
		return 5;
	}


	string inst2 = b1.substr(0, 5);
	if (inst2 == form3)
	{
		return 5;
	}

	else
		return 0;

}

void XCHGinst(char* a, int* n)
{
	string form1 = "1000011";
	string form3 = "10010";

	string b1 = getbyte(a, *n);
	*n = *n + 1;

	string inst = b1.substr(0, 7);
	if (form1 == inst)
	{
		string act = b1;
		if (act[7] == '1' || act[7]=='1')
		{//reg is the destination reg = r/m
			
			string b2 = getbyte(a, *n);
			string* p = REG(b2.substr(2, 3));

			string* p2 = REG(b2.substr(5, 3));

			string temp;
			temp = *p;
			*p = *p2;
			*p2 = *p;
			*n = *n + 1;
		
			
		}

		
		//return;
	}


}


//////////////////////////////////

void opcode(char *a, int *i)
{
	int decision = 0;

	decision = Movtest(a, i);
	regvalues();
	
	if (decision == 1)
	{
		Movinst(a, i);
		cout << "  current pos of pointer " << *i<<'\n';
		return ;
	}
	
decision = ADDtest(a, i);
 if (decision == 2)
	{ 
	 
		
		ADDinst(a, i);
		cout << " current pos of pointer "<< *i<<'\n';
		return;
	}

 decision = INCtest(a, i);
 if (decision == 3)
 {

	 
	 INCinst(a, i);
	 cout << " current pos of pointer " << *i << '\n';
	 return;
 }

 decision = SUBtest(a, i);
 if (decision == 4)
 {


	 SUBinst(a, i);
	 cout << " current pos of pointer " << *i << '\n';
	 return;
 }
 
 decision = XCHGtest(a, i);
 if (decision == 5)
 {
	 XCHGinst(a, i);
	 cout << " current pos of pointer " << *i << '\n';
	 return;
 }
}
/////////////////////////////////////

int main()
{
	int * inpointer = new int;
	char *arr = new char[256];
	int lenarr;
	ifstream is("C:\\CSC210\\CDRIVE\\TEXT2.COM", ios::out | ios::binary);
	if (! is.fail() ) {
		// get length of file:
		is.seekg(0, is.end);
		int length = is.tellg();
		is.seekg(0, is.beg);

		char *buffer = new char[length];


		std::cout << "Reading " << length << " characters... ";
		// read data as a block:
		is.read(buffer, length);
		if (is)
			std::cout << "all characters read successfully." << '\n';
		else
			std::cout << "error: only " << is.gcount() << " could be read";
		is.close();
		lenarr = length ;
		
		for (int i = 0; i < length; i ++) {
			for (int j= 7; j >= 0; --j) {
				arr[(i*8)+ 7-j] = ((buffer[i] & (1 << j)) ? '1' : '0');
				//cout << '\n';
				
				//arr[7 - j] = ((buffer[i] & (1 << j)) ? '1' : '0');
			}
			cout << '\n';
			
		}

		// ...buffer contains the entire file...
		//strToBinary(buffer);
		//delete[] buffer;
		

	}
	else
		std::cout<< "somethings wrong";

     cout<< "PRINTING MACHINE CODE............" << '\n';

	for (int i = 0; i <= lenarr; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			cout<< arr[(i * 8) + j];
			
		}
		cout<< '\n';
	}

	cout << "MACHINE CODE. ENDED" << '\n'<<'\n';


	

	

	
	regvalues();
	
	
	
	cout<< endl;
	regvalues();
	cout << endl;
	cout << getbyte(arr, 0)<<'\n';
	;
	//cout << "opcode succesfully determines" << opcode(arr, 0);
	
	int counter = 0;
	while (counter < lenarr)
	{
		opcode(arr, &counter);
	}
	
	//INCinst(arr, &counter);
	

	regvalues();
	cout << '\n';
	

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
