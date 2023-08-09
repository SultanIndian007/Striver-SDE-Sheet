#include <bits/stdc++.h>

using namespace std;

int main(){
    list<int>ls;

    ls.push_back(2);
    ls.emplace_back(3);

    ls.push_front(1);
    ls.emplace_front(4);

    for(auto it: ls){
        cout<<it<<" ";
    }
}
