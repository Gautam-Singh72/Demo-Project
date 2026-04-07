#include<iostream>
#include<stack>
using namespace std;
int countPairs(vector<int>& arr) {
    vector<int> freq(60, 0);
    int count = 0;

    for (int time : arr) {
        int rem = time % 60;
        int complement = (60 - rem);
        if(complement==60){
            count+=freq[0];
        }
        else{
            count += freq[complement];
        }
        freq[rem]++;
    }

    return count;
}

int main(){
    string s;
    cin>>s;
    stack<char> st;
    int n=s.size();
    int cnt=0;
    for(int i=0; i<n; i++){
        if(s[i]>='a' && s[i]<='z'){
            if(!st.empty() && st.top()==s[i]){
                st.pop();
                cnt++;
            }else{
                st.push(s[i]);
            }
        }
    }
    cout<<cnt<<endl;

    return 0;
}