/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: kboss
 *
 * Created on December 16, 2023, 1:13 PM
 */

#include <cstdlib>
#include <stack>
#include <iostream>
using namespace std;

/*
 * 
 */

float h(float, stack<float> &, stack<float>&);
float g(float ,stack<float>&, stack<float>&);

int main(int argc, char** argv) {
    
    
    
    // from -1 to 1 (have to be 1.01 to make sure that it goes through all ); 
    for(float i =-1; i<= 1.01; i+=0.1 ){
        stack<float> cosStack , sinStack ; 
        h(i , sinStack, cosStack); 
        
        cout<<"For the initial hyp sine call( "<<i<<" ), sin: "<< sinStack.size()<<"  cos: "<< cosStack.size()<<endl; 
        
        sinStack= stack<float>(); // clearing stack for next use ; 
        cosStack = stack<float>(); 
        
        g(i, cosStack, sinStack);
        cout << "For the initial hyp cosine call ( "<<i<<" ), sin: " << sinStack.size() << "  cos: " << cosStack.size() << endl; 
        
        cout<<endl; 
    }
    return 0;
}

// sin 
float h(float angR, stack<float> &sinStack, stack<float> &cosStack){
float tol=1e-6;
sinStack.push(angR ); 
if(angR>-tol&&angR<tol)return angR+angR*angR*angR/6;
return 2*h(angR/2, sinStack, cosStack)*g(angR/2, sinStack, cosStack);
}

//cos 
float g(float angR, stack<float>& sinStack , stack<float>& cosStack){
float tol=1e-6;
cosStack.push(angR); 
if(angR>-tol&&angR<tol)return 1+angR*angR/2;
float b=h(angR/2, sinStack, cosStack);
return 1+2*b*b;
}
