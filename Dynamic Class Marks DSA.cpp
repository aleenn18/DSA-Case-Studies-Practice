#include<iostream>
#include<new>
using namespace std;

//create array of marks and check for nullptr
int* createMarks(int n){
    if(n<=0){
        return nullptr;
    }
    int* marks =new(nothrow) int[n]; 
    return marks;
}

//read marks
void readMarks(int *arr, int n){
    for(int i=0; i<n; i++){
        cout<<"Students "<<(i+1)<<": ";
        cin>>arr[i];
    }
}
//display Marks
void displayMarks(int *arr, int n){
    for(int i=0; i<n; i++){
        cout<<"Students "<<(i+1)<<": "<<arr[i]<<endl;
    }
}

//sum
int sum(const int*arr, int n){
    int total =0;
    for(int i=0;i<n; i++){
        total+=*(arr+i);
    }
    return total;
}
//highest marks 
int highest(const int*arr, int n){
    if(n<=0){
        return 0;
    }
    int best = *arr;
    for(int i=0; i<n; i++){
        if(*(arr+i)>best){
            best = *(arr+i);
            
        }
    }
    return best;
}

//Add bonus to every mark
void addbonus(int*arr, int n, int bonus){
    for(int i =0; i<n; i++){
        *(arr+i)+=bonus;
        if(*(arr+i)>100){
            *(arr+i)=100;
        }
    }
}

//prints the address
void showaddress(const int*arr, int n){
    cout<<"Size of one int: "<<sizeof(int)<<" bytes "<<endl;
    for(int i =0; i<n;i++){
        cout<<"Address of element"<<i<<": "<<(arr+i)<<endl;
    }
}
//clears the pointer
void destroy(int*& arr){
    delete[] arr;
    arr = nullptr;
}
int main(){
int n;
cout<<"How many students:";
cin>>n;

int *marks = createMarks(n);
if(marks == nullptr){
    cout<<"ERROR!"<<endl;
}
readMarks(marks, n);

cout<<"Initial Marks"<<endl;
displayMarks(marks, n);
int totalmarks = sum(marks, n);
cout<<"Sum: "<<totalmarks<<endl;
cout<<"Average: "<<totalmarks /n<<endl;
cout<<"Highest Marks: "<<highest(marks, n)<<endl;
addbonus(marks, n, 5);
cout<<"Marks after the bonus"<<endl;
    displayMarks(marks, n);

    showaddress(marks, n);
    destroy(marks);
    return 0;
}

