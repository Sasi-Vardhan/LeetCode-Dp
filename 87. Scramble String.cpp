class Solution {
public:
    
    //lets try to match individual string see if s1 is dividied as x+y
    // we can also divide s2 as w+z an try to match x and y beacuse even if they are twisted they should be same
    //we can do as like this divide at index i (x,y) & (w,z)
    //w==x either z==x similarly for y==w either y==z

    unordered_map<string,bool>mp;

 
    bool isScramble(string s1, string s2) {
    // base case
    if (s1 == s2) return true;
    if (s1.size() != s2.size() || s1.size() == 0) return false;
    string idx=s1+"#"+s2;
    if(mp.find(idx)!=mp.end())return mp[idx];
    bool flag=false;
    for (int i = 1; i < s1.size(); i++) {
        // no swap
        if (isScramble(s1.substr(0, i), s2.substr(0, i)) &&
            isScramble(s1.substr(i), s2.substr(i))) {
                flag=true;
                break;
            // return true;
        }

        // swap "here you might get confused with different idexes we have used them because 
        // left substr size is same as right sbustr "
        // if length of string 1 is i
        // then the starting index of right string should be from n-i so there will be i length string
        //ex : if length n=5 if s1.len=2 then s2.length#right=5-2 -3 {3-4} will be included
        if (isScramble(s1.substr(0, i), s2.substr(s2.size() - i)) &&
            isScramble(s1.substr(i), s2.substr(0, s2.size() - i))) {
                flag=true;
                break;
            // return true;
        }
    }
    return mp[idx]=flag;
}
};
