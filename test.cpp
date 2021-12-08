#include <iostream>
#include "findpeaks.h"
using namespace std;
int main() {
    std::vector<int> a{0,1,0,1,2,3,5,3,0,2,0,1};
    auto ans= findPeaks(a);
    cout<<"peaks with distance 0:\n";
    for_each(ans.begin(),ans.end(),[](int x){
        cout<<x<<",";
    });
    cout<<endl;
    ans= findPeaks(a,3);
    cout<<"peaks with distance 3:\n";
    for_each(ans.begin(),ans.end(),[](int x){
        cout<<x<<",";
    });
    return 0;
}
