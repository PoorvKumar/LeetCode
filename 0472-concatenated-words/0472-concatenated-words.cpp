class Solution {
public:
     bool isconcatenated(string word,unordered_set<string> &st){

       for(int i=0;i<word.size();i++){
           string prefix = word.substr(0,i+1);
           string suffix = word.substr(i+1);

           if(st.find(prefix)!=st.end() && isconcatenated(suffix,st) || st.find(prefix)!=st.end() && st.find(suffix)!=st.end()){
               return true;
           }
       }
       return false;

   }

    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        int n=words.size();

        unordered_set<string> st(words.begin(),words.end()); //push all element of vector<int> words in set;

        vector<string> result;
        for(int i=0;i<words.size();++i){
             string word = words[i];

             if(isconcatenated(word,st)){
                 result.push_back(word);
             }
        }
        return result;
    }
};