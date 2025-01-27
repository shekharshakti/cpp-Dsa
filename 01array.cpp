#include<iostream>
#include<limits.h>
using namespace std;
// void printArray(int arr[],int size){
//     for(int i=0;i<size;i++){
//         cout<<arr[i]<<" ";
//     }
// }

bool linearSearch(int arr[],int size,int target){
    for(int i=0;i<size;i++){
        if(arr[i]==target){
            return true;
        }
    }
    return false;
}
int findMinimumInArray(int arr[],int size){
    int minAns=INT_MAX;
    for(int i=0;i<size;i++){
        if(arr[i]<minAns){
            minAns=arr[i];
        }

    }
    return minAns;
}
void countZerosOrones(int arr[],int size){
    int zeroCount=0;
    int oneCount=0;
    for(int i=0;i<size;i++){
        if(arr[i]==0){
            zeroCount++;
        }
        if(arr[i]==1){
            oneCount++;
        }
    }
    cout<<"ZeroCount :-"<<zeroCount<<endl;
    cout<<"OneCount:-"<<oneCount<<endl;
}
void reverseArray(int arr[],int size){
    int left =0;
    int right=size-1;
    while(left<=right){
        swap(arr[left],arr[right]);
        left++;
        right--;
        }
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    }
void extremePrint(int arr[],int size){
    int left=0;
    int right =size-1;
    while(left<=right){
        if(left==right){
            cout<<arr[left]<<endl;
        }
        else{
            cout<<arr[left]<<" ";
            cout<<arr[right]<<" ";

        }
        left++;
        right--;
    }
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
}


int main(){
    int arr[10]={5,4,6,0,0,1,1,12,15,45};
    int size =10;
    int target=6;
    int minimum=findMinimumInArray(arr,size);
    cout<<"minimum number is:-"<<minimum<<endl;
    bool ans=linearSearch(arr,size,target);
    if(ans==1){
        cout<<"Target found"<<endl;
    }
    else{
        cout<<"target nOt Found"<<endl;
    }
    countZerosOrones(arr,size);
    cout<<"reversed array is :-";
    reverseArray(arr,size);
    cout<<endl;
    // printArray(arr,size);
    cout<<"extremePrint;-";
    extremePrint(arr,size);
    // printArray(arr,size);

}