// RIFA NADAL

// INCLUDES
#include<iostream>
#include<map>
#include<vector>
#include<set>
using namespace std;


void update(map<int,int>& nums, map<int,int>& tens, int n, int& mn, int& mt){
    ++nums[n]; // Sumem 1 a la freq de n
    ++tens[n%100]; // Sumem 1 a la terminacio d n
    // Si la freq d n es mes gran que la q teniem com a maxima o si son iguals
    // pero n es mes petit, ara el max es n
    if(nums[n] > nums[mn] or (nums[n] == nums[mn] && n < mn)) mn = n;
    if(tens[n%100] > tens[mt] or (tens[n%100] == tens[mt] && n%100 < mt)) mt = n%100;
}

void write(int mn, int mt, map<int,int>& nums, map<int,int>& tens)
{
    cout << mn <<' '<< nums[mn] <<' ';
    if(mt < 10) cout << 0;
    cout << mt <<' '<< tens[mt] << endl;
}

void write_end(map<int,int>& nums)
{
    cout << endl;
    for(auto a : nums){
        cout << a.first << ' ' << a.second << endl;
    }
    cout << "----------" << endl;
}

int main()
{
    int n;
    while(cin >> n){
        map<int,int> nums;
        map<int,int> tens;
        int max_n = n; // La primera vegada q llegim el maxim es n
        int max_t = n%100;
        while(n != -1){
            update(nums, tens, n, max_n, max_t);
            write(max_n, max_t, nums, tens);
            cin >> n;
        }
        write_end(nums);
    }
}
