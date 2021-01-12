class Solution {
    /*
     * Firstly, I'll create the array for the input.
     * What I want to do here is that, I want a loop for each possible value of a digit
     * and there can be n digits in total(length of input string).
     * So, I will create a helper recursive function which take a string(empty initially),
     * runs a for loop for each of the alphabets which can occur for digit on the ith position of the input string,
     * append it to the output string(combination) and call the function again with the newly formed combination.
     * This chain will terminate, when we have the size of input string equal to the ouput string.
     * Then we will push the combination formed into the reference of the output array.   
     */
public:
    
    void solve(string& digits, vector<string>& input, vector<string>& output, string combination) {
        if(combination.size() == digits.size()) {
            output.push_back(combination);
            return;
        }
        int pos = combination.size();
        int num = digits[pos]-'0';
        for(int i = 0; i<input[num].size(); ++i) {
            solve(digits, input, output, combination + input[num][i]);
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0)
            return {};
        vector<string> input(10);
        input[2]="abc";
        input[3]="def";
        input[4]="ghi";
        input[5]="jkl";
        input[6]="mno";
        input[7]="pqrs";
        input[8]="tuv";
        input[9]="wxyz";
        string combination = "";
        vector<string> output;
        solve(digits, input, output, combination);      
        return output;
    }
};