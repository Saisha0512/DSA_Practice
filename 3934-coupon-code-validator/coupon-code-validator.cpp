// Custom Class to store the details of each coupon : 
class coupon {
public : 
    string code;
    string businessLine;
    bool isActive;

    coupon(string code, string businessLine, bool isActive){
        this -> code = code;
        this -> businessLine = businessLine;
        this -> isActive = isActive;
    }
};

class Solution {
    // Static Comparing function to compare each coupon according the conditions mentioned : 
    static bool compare (coupon &a, coupon &b){
        if (a.businessLine == b.businessLine){
            return a.code < b.code;
        }

        return a.businessLine < b.businessLine;
    }

    // Function to check if the code is valid or invalid : 
    bool checkCode(string code){
        if (code == ""){ // Empty code is invalid
            return false;
        }

        for (char ch : code){
            // All conditions are applied : 
            if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9') || ch == '_'){
                continue;
            }
            else {
                return false;
            }
        }

        return true;
    }

public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        int n = code.size();
        vector<coupon> validate; // Vector to store each valid coupon including its details
        
        for (int i = 0; i < n; i ++){
            // Checking if the coupon is valid :
            if (checkCode(code[i]) && isActive[i] && (businessLine[i] == "electronics" || businessLine[i] == "grocery" || businessLine[i] == "pharmacy" || businessLine[i] == "restaurant")){
                coupon c(code[i], businessLine[i], isActive[i]);
                validate.push_back(c);
            } 
        }

        // Sorting according to the conditions : 
        sort(validate.begin(), validate.end(), compare);

        // Resultant Vector : 
        vector<string> res;
        for (auto &c : validate){
            res.push_back(c.code);
        }

        return res;
    }
};