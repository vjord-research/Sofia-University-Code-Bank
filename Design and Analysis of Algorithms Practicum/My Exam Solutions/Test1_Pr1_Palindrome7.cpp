#include iostream
#include string
using namespace std;

const char MAX_CHAR = 1000000;

bool isPalindrome(int freq, int len)
{
    int count_odd = 0;
    for (int i=0; iMAX_CHAR; i++)
        if (freq[i]%2 != 0)
            count_odd++;

    if (len%2 == 0)
    {
        if (count_odd  0)
            return false;
        else
            return true;
    }

    if (count_odd != 1)
        return false;

    return true;
}

string palindromeChanges(int freq)
{
    string odd_str = ;
    for (int i=0; iMAX_CHAR; i++)
    {
        if (freq[i]%2 != 0)
        {
            freq[i]--;
            odd_str = odd_str + (char)(i+'a');
            return odd_str;
        }
    }
    return odd_str;
}

void findFrequency(string str, int freq, int len)
{
    for (int i=0; ilen; i++)
        freq[str.at(i) - 'a']++;
}

string findString(string str)
{
    int len = str.length();

    int freq[MAX_CHAR] = {0};
    findFrequency(str, freq, len);

    if (!isPalindrome(freq, len))
        return IMPOSSIBLE;

    string odd_str = palindromeChanges(freq);

    string front_str = , back_str =  ;

    for (int i=0; iMAX_CHAR; i++)
    {
        string temp = ;
        if (freq[i] != 0)
        {
            char ch = (char)(i + 'a');

            for (int j=1; j=freq[i]2; j++)
                temp = temp + ch;

            front_str = front_str + temp;

            back_str = temp + back_str;
        }
    }

    return (front_str + odd_str + back_str);
}

int main()
{
    string str;
    getline(stdcin, str);
    cout  findString(str);
    return 0;
}