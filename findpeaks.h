//
// created by xjk on 2021/12/7
//
#include <vector>
#include <numeric>
#include <set>
#include <algorithm>
template <class T>
/*
 *  src: 	input array
 *  distance:	minpeakdistance
 *  
 *  return:	peak_index array
*/
std::vector<int> findPeaks(const std::vector<T> &src, int distance=0);

std::vector<int> findPeaks(const std::vector<T> &src, int distance)
{
    int length=src.size();
    std::vector<int> sign(length-1,-1);
    std::vector<T> difference(length,0);
    std::vector<int> temp_out;
    //first-order difference
    adjacent_difference(src.begin(),src.end(),difference.begin());
    difference.erase(difference.begin());
    for (int i = 0; i < difference.size(); ++i) {
        if(difference[i]>=0) sign[i]=1;
    }
    //second-order difference
    T  diff2 = 0;
    for (int j = 1; j < length; ++j)
    {
        int  diff = sign[j] - sign[j - 1];
        diff2 += difference[j-1];
        if ((diff < 0) && diff2 != 0) {
            temp_out.push_back(j);
        } 
    }
    
    if(temp_out.size()==0 || distance==0 ) return temp_out;
    
    //sort peaks from large to small by src value at peaks
    sort(temp_out.begin(),temp_out.end(),[&src](int a,int b){
        return src[a]>=src[b];
    });

    std::vector<int> ans;
    std::set<int> except;

    //Initialize the answer and the collection to be excluded

    ans.push_back(temp_out[0]);
    int left=std::max(0,temp_out[0]-distance);
    int right=std::min(length-1,temp_out[0]+distance);
    for (int i = left;i<=right; ++i) {
        except.insert(i);
    }
    for (int i = 1; i < temp_out.size(); ++i) {
        auto it=except.find(temp_out[i]);
	// if not in except
	// add it to the answer and update except
        if(it==except.end())
        {
            ans.push_back(temp_out[i]);
            int left=std::max(0,temp_out[i]-distance);
            int right=std::min(length-1,temp_out[i]+distance);
            for (int j = left;j<=right; ++j) {
                except.insert(j);
            }
        }
    }
    //sort the ans from small to large by index value
    std::sort(ans.begin(),ans.end());
    return ans;
}
