#include <bits/stdc++.h>

using namespace std;

int main(){
    vector<int>v;

    v.push_back(1);
    v.emplace_back(2);

    vector<int>::iterator it = v.begin();
    it++;
    // cout<<*(it)<<" ";
    vector<int>::iterator i = v.end();
    // cout<<*(i)<<" ";

    // vector<int>::iterator ite = v.rend();
    // cout<<*(ite)<<" ";
    // vector<int>::iterator itr = v.rbegin();
    // cout<<*(itr)<<" ";


    vector<pair<int,int>>vec;
    vec.push_back({1,3});
    vec.emplace_back(1,3);

    vector<int>vct(5,100);

    vector<int>temp;
    temp.push_back(40);
    temp.push_back(30);
    temp.push_back(20);
    temp.push_back(10);

    // temp.erase(temp.begin() +1);
    // temp.push_back(30);
    // temp.erase(temp.begin(), temp.end()-1);

    temp.insert(temp.begin(), 2, 35);
    for(auto it: temp){ 
        cout<<it<<" ";
    }
    cout<<temp.size();
    cout<<temp.empty();
    // cout<<vec[0].first<<endl;

    return 0;
}


