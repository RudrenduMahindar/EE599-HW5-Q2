#include <iostream>
#include "src/lib/solution.h"
using namespace std;

int main()
{
    vector<int> v={3,2,20,15,27};
    BST s(v);
    vector<int> v1=s.inorder_recursive();
    cout<<"Output: [ ";
    for(auto& i:v1)
        cout<<i<<" ";
    cout<<"]"<<endl;
    vector<int> v2=s.inorder_nonrecursive();
    cout<<"Output: [ ";
    for(auto& i:v2)
        cout<<i<<" ";
    cout<<"]"<<endl;
    
    /*int val=14;
    cout<<" Find val = "<<val<<" Found = "<<s.find(val)<<endl;
    val=0;
    s.push(val);
    v1 = s.TreeToVector();
    cout<<"after push val = "<<val<<endl;
    for(auto& i:v1)
        cout<<" "<<i;
    val=20;
    cout<<"\nerase = "<<s.erase(val)<<" val = "<<val<<endl;*/
    /*v1 = s.TreeToVector();
    for(auto& i:v1)
        cout<<" "<<i;
    cout<<endl;*/        
    return EXIT_SUCCESS;
}