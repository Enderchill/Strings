#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

// Students are required to implement these functions
bool isValidPrice(string);
bool isValidPlu(string);
bool isValidName(string);
bool isValidInv(string);
bool isValidSales(string);
string tokenize(string & s);

// code the rest
int main()
{
    string fileName; //ask for input file and open
    cout << "Enter input file:";
    cout << endl; //format check
    cin >> fileName;
    
    ifstream inputFile(fileName);
    
    //create string variables to hold file input
    
    //input validation
    if(inputFile)
    {
        cout << "Checking " << fileName << endl; //formatting
        string underscores = "Checking " + fileName;
        for (int i =0;i < underscores.length();i++)
        {
            cout << "-";
        }
        cout << endl; //format check
        cout << endl; //format check
        string line;
        int lineCount = 0;
        bool valid = true;
        while(getline(inputFile, line)) //parse
        {
            lineCount++;
            int count = 0; //token count
            string temp = line;
            string token;
            
            token = tokenize(temp);
            if (!token.empty()) {
                count++;
                cout << "Token #" << count << " is " << token << ", ";
                if (isValidPlu(token))
                {
                    cout << "PLU is valid" << endl;
                }
                else
                {
                    cout << "PLU is invalid" << endl;
                    valid = false;
                    break;
                }
            }
            
            token = tokenize(temp);
            if (!token.empty()) {
                count++;
                cout << "Token #" << count << " is " << token << ", ";
                if (isValidName(token))
                {
                    cout << "Product name is valid" << endl;
                }
                else
                {
                    cout << "Product name is invalid" << endl;
                    valid = false;
                    break;
                }
            }
            
            token = tokenize(temp);
            if (!token.empty()) {
                count++;
                cout << "Token #" << count << " is " << token << ", ";
                if (isValidSales(token))
                {
                    cout << "Sales type is valid" << endl;
                }
                else
                {
                    cout << "Sales type is invalid" << endl;
                    valid = false;
                    break;
                }
            }
            
            token = tokenize(temp);
            if (!token.empty()) {
                count++;
                cout << "Token #" << count << " is " << token << ", ";
                if (isValidPrice(token))
                {
                    cout << "Price is valid" << endl;
                }
                else
                {
                    cout << "Price is invalid" << endl;
                    valid = false;
                    break;
                }
            }
            
            token = tokenize(temp);
            if (token.empty()) {
               
                cout << "Inventory is invalid, record has missing items" << endl;
                valid = false;
                break;
            } else {
                count++;
                cout << "Token #" << count << " is " << token << ", ";
                if (isValidInv(token)) {
                    cout << "Inventory is valid" << endl;
                } else {
                    cout << "Inventory is invalid" << endl;
                    valid = false;
                    break;
                }
            }
        
            token = tokenize(temp);
            if (!token.empty())
            {
                count++;
                cout << "Token #" << count << " is " << token << ", Too many items in record" << endl;
                valid = false;
                break;
            }
            
            if (count < 5)
            {
                cout << "Too few items in the record" << endl;
                valid = false;
                break;
            }
            cout << endl;
        }
        
        if (valid)
        {
            cout << "######## " << fileName << " has valid content ########" << endl;
        }
        else
        {
            cout << endl; //format check
            cout << "######## " << fileName << " has invalid content ########" << endl;
        }
    }
    else {
        cout << "Error, cant open file." << endl;
    }
    
    return 0;
}
bool isValidPrice(string holder)
{
    int length = holder.length();
    
    int count = 0;
    int digi = 0;
    bool afterDot = false; //flag
        
    for (size_t i = 0; i < length; i++) {
    
        
        if (isdigit(holder[i])) //cgeck for digits
        {
            if (afterDot)
            {
                digi++;
                
                if (digi > 2)
                {
                    return false;
                }
            }
        }
        // Check if character is a dot
        else if (holder[i] == '.')
        
        {
            count++;
            
            if (count > 1) //only one dot allowed if not then fail
            {
                return false;
            }
            
            afterDot = true;
        }
        
        // if doesnt pass any test cases, invalid price
        else
        {
            return false;
        }
        
        }
        
        return true;
        
}
bool isValidPlu(string holder)
{
    if (holder.length() != 4) {
            return false;
        }
        
    for (int i = 0; i < holder.length(); i++)
    {
        if (!isalnum(holder[i]))
        {
            return false;
        }
    }
    return true;
}
bool isValidName(string holder)
{
    if (holder.empty() || !isalpha(holder[0])) {
            return false;
        }
        
        return true;
    
}
bool isValidInv(string holder)
{
    int length = holder.length();
    for(int i =0;i < length;i++)
    {
        if (!isdigit(holder[i])) {
            return false;
        }
    }
            
    return true;
}
string tokenize(string & s)
{
    
    int first = 0;
    string token = "";
    while (first < s.length() && (s[first] == ' ' || s[first] == '\t' || s[first] == '\n' || s[first] == '\r'))
    {
        first++;
    }
    
    if (first >= s.length())
    {
        s = "";
        return "";
    }
    
    
    int last = first;
    while (last < s.length() && s[last] != ' ' && s[last] != '\t' && s[last] != '\n' && s[last] != '\r')
    {
        last++;
    }
    
    // get token
    token = s.substr(first, last - first);
    
    
    s = s.substr(last);
    
    return token;
}

bool isValidSales(string holder)
{
    
    if (holder.length() == 1 && (holder[0] == '0' || holder[0] == '1'))
    {
        return true;
    }
        
    return false;
    
}
