#include <vector>
#include <cmath>
using namespace std;
vector<int> solve(int n) {
    int temp=n;
    vector<int>prime(n/2+1,false);
    vector<int>res;
    res.clear();
    res={};

    for(int i=2; i<=sqrt(temp); i++){
        if(prime[i]) continue;
        if(n<1) return res;

        while(n % i == 0){
            res.push_back(i);
            n /= i;
        }

        for(int j=1; i*j<=sqrt(temp); j++){
            prime[i*j] = true;
        }
    }
    if(res.size()==0) return {temp};
    return res;
}
