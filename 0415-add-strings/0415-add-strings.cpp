class Solution {
public:
    string addStrings(string num1, string num2) {
       string result = "";
        int i = num1.size() - 1; // Pointer for end of num1
        int j = num2.size() - 1; // Pointer for end of num2
        int carry = 0;

        // Loop as long as there are digits to process or a carry remains
        while (i >= 0 || j >= 0 || carry) {
            int digit1 = (i >= 0) ? num1[i] - '0' : 0;
            int digit2 = (j >= 0) ? num2[j] - '0' : 0;

            int sum = digit1 + digit2 + carry;
            carry = sum / 10;          // Get the tens digit (the carry)
            result += (sum % 10) + '0'; // Get the units digit and convert to char

            i--;
            j--;
        }

        // Because we added from right to left, the string is backwards
        reverse(result.begin(), result.end());
        return result;
    }
};