class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> codes = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        set<string> m;
        for(int i=0;i<words.size();i++){
            string s="";
            for(int j=0;j<words[i].size();j++){
                s+=codes[words[i][j]-'a'];
            }
            m.insert(s);
        }
        return m.size();
    }
};
