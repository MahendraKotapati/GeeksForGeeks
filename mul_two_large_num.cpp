#include<bits/stdc++.h>
using namespace std;
 
string multiplyStrings(string , string );
 
int main() {
     
    int t;
    cin>>t;
    while(t--)
    {
        int num1,num2;
    	string a;
    	string b;
    	cin>>a>>b;
    	//cin>>num1>>num2;
    	cout<<multiplyStrings(a,b)<<endl;

        //cout<<num1*num2<<"\n";
    }
     
}


string multiplyStrings(string s1, string s2) {

    //if(s1.length()<s2.length())
    //    swap(s1,s2);

    long int len1,len2,i,j,carry=0,temp,start,pre,maxi=0;
    vector <long int> ans(1000005,0);
    int flag1=0,flag2=0;

    
    if(s1[0]=='-')
    {
        flag1=1;
        s1=s1.substr(1,s1.length()-1);
    }
    if(s2[0]=='-')
    {
        flag2=1; 
        s2=s2.substr(1,s2.length()-1);
    }
    
    len1=s1.length();len2=s2.length();
       
    reverse(s1.begin(),s1.end());
    reverse(s2.begin(),s2.end());
    for(i=0;i<len2;i++)
    {   
        carry=0;start=i;
        for(j=0;j<len1;j++)
        {
            temp=(s2[i]-'0')*(s1[j]-'0');
            temp+=carry;
            ans[start]+=temp%10;
            pre=ans[start];  
            ans[start]%=10;
            carry=temp/10+pre/10;
            start++;
        }
        if(carry)
            ans[start]=carry%10;start++; 
       
        maxi=max(maxi,start);
    }
    string res;

    while(maxi>=0 &&ans[maxi]==0)
        maxi--;

    for(i=maxi;i>=0;i--)
        res.push_back(ans[i]+'0');

    if(flag1^flag2)
        res="-"+res;
 
    return res;
    
}
