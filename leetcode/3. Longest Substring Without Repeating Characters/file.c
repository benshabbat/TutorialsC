int lengthOfLongestSubstring(char* s) {
    int n = strlen(s);
    int maxLength = 0;
    int charIndex[256]; // Assuming ASCII characters
    
    memset(charIndex, -1, sizeof(charIndex));
    
    int start = 0;
    for (int end = 0; end < n; end++) {
        if (charIndex[s[end]] != -1) {
            start = (charIndex[s[end]] >= start) ? charIndex[s[end]] + 1 : start;
        }
        maxLength = (end - start + 1 > maxLength) ? end - start + 1 : maxLength;
        charIndex[s[end]] = end;
    }
    
    return maxLength;
}