/*Valid Anagram
Given two strings s and t , write a function to determine if t is an anagram of s.

Input: s = "anagram", t = "nagaram"
Output: true

*/

bool isAnagram(char * s, char * t){
    int len1 = strlen(s);
    int len2 = strlen(t);

    if(len1 != len2) 
        return false;
    else
    {
        int mapS[26] = {0};
        int mapT[26] = {0};

        for(int i = 0; i < len1; ++i) 
            mapS[s[i] - 'a']++;
        for(int i = 0; i < len2; ++i) 
            mapT[t[i] - 'a']++;

        for(int i = 0; i < 26; i++)
        {
            if(mapS[i] != mapT[i]) 
                return false; 
        }
        return true;
    } 
}
