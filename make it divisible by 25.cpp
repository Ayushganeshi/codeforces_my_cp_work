#include<iostream>
using namespace std;
int main()
{
    int arr[5]={4,56,34,9,12};
    int largest=arr[0];
    for(int i=1;i<5;i++)
    {
        if(arr[i]>largest)
        {
            largest=arr[i];
        }
    }
    cout<<"largest element is equal to:"<<largest<<endl;



int seclargest=arr[0];
for(int i=1;i<5;i++)
{
    if(arr[i]!=largest && arr[i]>seclargest){
        seclargest=arr[i];
    }
}
cout<<"second largest element in the array in the element is :"<<seclargest<<endl;
}