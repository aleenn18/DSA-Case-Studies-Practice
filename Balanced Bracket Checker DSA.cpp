#include<iostream>
#include<string>
using namespace std;


class charstack{
	private:
		int top;
		char stk[30];
	public:
		charstack(){
			top =-1;
		}
		bool isEmpty(){
			return top ==-1;
		}
		bool isFull(){
			return top==29;
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

    bool isOpening(char c){
        return c=='('|| c==  '['||c=='{';
    }
    bool isClosing(char c){
        return c==')'|| c==']'||c=='}';
    }
    bool match(char open, char close){
        return (open =='(' && close ==')') || (open =='[' && close ==']') ||(open =='{' && close =='}');
    }
int checkbrackets(string line){
    charstack letters;
    for(int i =0; i<line.length(); i++){
       char  c = line[i];

        if(isOpening(c)){
                if(letters.isFull()){
                    return 4; //overflow
                }
            letters.push(c);
        }
        if(isClosing(c)){
           if( letters.isEmpty()){
                return 1; //uderflow
           }
            char open = letters.pop();
            if(!match(open, c)){
                return 2; //mismatched
            }
        }
    }
    if(!letters.isEmpty()){
        return 3; //Opening bracket left at the end
    }
    return 0; //balanced!
}
void printstatus(int status){
    if(status ==0){
        cout<<"BALANCED"<<endl;
    }
    else if(status == 1){
        cout<<"ERROR! UNDERFLOW"<<endl;
    }
    else if(status ==2){
        cout<<"ERROR! Mismatched Brackets"<<endl;
    }
        else if(status ==3){
        cout<<"ERROR! Closing Bracket Needed"<<endl;
        }
    else if(status ==4){
        cout<<"ERROR! OVERFLOW"<<endl;

    }
}
    
int main(){
   int opt =0;
    while(opt !=3){
        cout<<"Check a line of code: "<<endl;
        cout<<"Run the built in tests "<<endl;
        cout<<"Exit"<<endl;
        cout<<"Enter your Option (1-3): ";
        cin>>opt;
        cin.ignore();
        
       if(opt ==1){
           string line;
           cout<<"Enter a line: ";
           getline(cin, line);
           int status = checkbrackets(line);
           printstatus(status);
       } 
        else if (opt ==2){
            string testlines[8] = {
                "{[()]y",
                "(a + b) * [c - d]",
                "(]",
                "())",
                "((",
                "if (x > 0) { y = a[i];",
                "}",
                ""
            };
            for(int i =0; i<8; i++){
                int status = checkbrackets(testlines[i]);
                cout << "\"" << testlines[i] << "\" -> Status " << status << ": "; 
                printstatus(status);
            }  
            }
            else if(opt ==3){
            cout<<"Exiting Program"<<endl;
            }
        else{
            cout<<"Invalid Program"<<endl;        }
        }
    return 0;
}
