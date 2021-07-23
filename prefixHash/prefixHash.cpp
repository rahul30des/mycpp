class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        stringstream ss;
        string word;
        ss<<sentence;
        bool found = false;
        int ctr = 0;
        string out;

        while(ss>>word) {
            if (ctr != 0) {
                out = out + " ";
            }
            found = false;
            for (auto entry: dictionary) {
                if (word.find(entry) != std::string::npos) {
                    out = out + entry;
                    found = true;
                    break;
                } 
            }
            if (found == false) {
                out = out + word;
            }
            ctr++;
        }
        return out;
    }
};
