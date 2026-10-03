#include <iostream>
using namespace std;

const int DAYS = 7;
double temp[DAYS];

void readTemp(double temp[], int size){
    for(int i = 0; i<size; i++){
        cout<<"Enter Temperature on Day "<<(i+1)<<endl;
        cin>>temp[i];
    }
}
void display(const double temp[], int size){
    for(int i =0; i<size; i++){
        cout<<"Temperature on Day "<<(i+1)<<": "<<temp[i]<<endl;
    }
}
double getAvg(const double temp[], int size){
    if (size <= 0) {
        return 0.0; // Prevent division by zero
    }
    double sum = 0;
    for(int i = 0; i<size; i++){
        sum += temp[i];
        
    }
    return sum/size;
}
int countAboveavg(const double temp[], int size){
    double Avg = getAvg(temp, size);
    int count =0;
    
    for(int i = 0; i<size; i++){
        if(temp[i]>Avg){
            count++;
          
        }
            
    }
    return count;
    
}
void celtofa(double temp[], int size){
    for(int i=0; i<size; i++){
        temp[i]= temp[i]*9.0/5.0 +32;
    }
}
void showaddress(const double temp[], int size){
    for(int i=0; i<size; i++){
        cout<<&temp[i]<<endl;
    }
}
int main()
{
    double temp[DAYS];
    readTemp(temp, DAYS);
    display(temp, DAYS);
    cout<<getAvg(temp,DAYS)<<endl;
    cout<<countAboveavg(temp,DAYS)<<endl;
    showaddress(temp, DAYS);
    celtofa(temp,DAYS);
}
