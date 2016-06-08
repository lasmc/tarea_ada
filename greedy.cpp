//
//  main.cpp
//  greedy
//
//  Created by Luis Alberto Sanchez Moreno on 06/01/16.
//  Copyright © 2016 Luis Alberto Sanchez Moreno. All rights reserved.
//

#include <iostream>

using namespace std;


void recursiveActivitySelector(int s[] , int f[], int k, int n,int i[]){
    int m =k+1;
    while((m<=n) && (s[m] < f[k])){
        m=m+1;
    }
    if(m<=n){
        i[m]=1;
        recursiveActivitySelector(s,f,m,n,i);
    }
    
}

void greedyActivitySelector(int s[],int tam, int f[],int i[]){
    int n=tam;
    int k=1;
    for(int m=2;m<n;m++){
        if(s[m] >= f[k]){
            i[m]=1;
            k=m;
        }
    }
}

int main()
{
    int a[] = {1 ,2 ,3 ,4 ,5 ,6 ,7 ,8 ,9 ,10,11};
    int i[] = {1 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 };
    int s[] = {1 ,3 ,0 ,5 ,3 ,5 ,6 ,8 ,8 ,2 ,12};
    int f[] = {4 ,5 ,6 ,7 ,9 ,9 ,10,11,12,14,16};
    int n =11;
    
    cout<<"A"<<" ";
    for (int i=0;i<n;i++){
        cout<<a[i]<<" | ";
    }
    cout<<endl;
    
    cout<<"s"<<" ";
    for (int i=0;i<n;i++){
        cout<<s[i]<<" | ";
    }
    cout<<endl;
    
    cout<<"f"<<" ";
    for (int i=0;i<n;i++){
        cout<<f[i]<<" | ";
    }
    cout<<endl;
    
    cout<<"recursive"<<" ";
    recursiveActivitySelector(s,f,0,n,a);
    for (int i=0;i<n;i++){
        if (a[i] == 1)
            cout<<"a"<<i+1<<" ";
    }
    cout<<endl;
    cout<<"greedy   "<<" ";
    greedyActivitySelector(s,n,f,a);
    for (int i=0;i<n;i++){
        if (a[i] == 1)
            cout<<"a"<<i+1<<" ";
    }
    cout<<endl;
    return 0;
}