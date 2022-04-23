class Solution {
public:

    // Encodes a URL to a shortened URL.
    string s1, s2;
    string encode(string longUrl) {
        s1 = longUrl.substr(8, longUrl.length());
        string str = longUrl.substr(0, 8) + to_string(s1.length()) + s1.substr(0, 3) + s1.substr(5, 2);
        return str;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        string str = shortUrl.substr(0, 8) + s1;
        return str;
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));