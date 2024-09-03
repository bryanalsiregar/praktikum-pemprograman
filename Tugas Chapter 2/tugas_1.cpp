#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

typedef unsigned long long ull;

string thousandSeparator(int n) 
{ 
    string ans = ""; 
  
    string num = to_string(n); 
  
    int count = 0; 
    
    for (int i = num.size() - 1; 
         i >= 0; i--) { 
        count++; 
        ans.push_back(num[i]); 
  
        if (count == 3) { 
            ans.push_back('.'); 
            count = 0; 
        } 
    } 
  
    reverse(ans.begin(), ans.end()); 
  

    if (ans.size() % 4 == 0) { 
        ans.erase(ans.begin()); 
    } 
  
    return ans; 
} 

int main(){
	string name;
	ull salary, installment, insurance, tax;
	
	cout << "Input your name" << endl;
	cin >> name;
	cout << "Input your gross salary cost" << endl;
	cin >> salary;
	cout << "Input your installment cost" << endl;
	cin >> installment;
	cout << "Input your insurance cost" << endl;
	cin >> insurance;
	
	tax = salary*0.2;
	cout << " " << endl;
	cout << " " << endl;
	cout << " " << endl;
	cout << " " << endl;
	cout << "Payslip for Employee" << endl;
	cout << "---------------------" << endl;
	cout << "Name: " << name << endl;
	cout << "Gross Salary: Rp" << thousandSeparator(salary) << ",00" << endl;
	cout << "Tax (20%): Rp" << thousandSeparator(tax) << ",00" << endl;
	cout << "Installment: Rp" << thousandSeparator(installment) << ",00" << endl;
	cout << "Insurance: Rp" << thousandSeparator(insurance) << ",00" << endl;
	cout << "Net Salary: Rp" << thousandSeparator(salary-tax-installment-insurance) << ",00" << endl;
	return 0;
}
