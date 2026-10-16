#include<iostream>
#include<string>
using namespace std;

class charstack{
	private:
		int top;
		char stk[20];
	public:
		charstack(){
			top =-1;
		}
		bool isEmpty(){
			return top ==-1;
		}
		bool isFull(){
			return top==19;
		}
		bool push(char letter){
			if(isFull()){
				return false; //failed
			}
			top++;
			stk[top]=letter;
			return true;
		}
		char pop(){
			if(isEmpty()){
				return '\0';
			}
			char letter = stk[top];
			top--;
			return letter;
		}
		char peek(){
			if(isEmpty()){
				return '\0';
			}
			return stk[top];
		}
		int count(){
			return top+1;
		}
		void clear(){
			top =-1;
		}
};
int main(){
	charstack letters; 
	string word;
	
	cout<<"Enter a word to reverse (0-20 Characters): ";
	cin>>word;
	
	while(word != "0"){
		int len = word.length();
		
		if(len>20){
			cout<<"ERROR! You entered a word more than 20 Characters!"<<endl;
		}
			else
			{
				for(int i =0; i<len; i++){
					letters.push(word[i]);
			}
			cout<<"Reversed: ";
			while(!letters.isEmpty()){
				
				cout<<letters.pop();
			}
			cout<<endl;
			}
			cout << "Enter a word to reverse (0 to 20): ";   // NEW
    cin >> word;
		}
		return 0;
		}
	

