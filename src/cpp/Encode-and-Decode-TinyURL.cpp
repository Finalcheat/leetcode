/**
 * @file Encode-and-Decode-TinyURL.cpp
 * @brief 编码解码url(https://leetcode.com/problems/encode-and-decode-tinyurl/description/)
 * @author Finalcheat
 * @date 2018-04-11
 */

/**
 * TinyURL is a URL shortening service where you enter a URL such as https://leetcode.com/problems/design-tinyurl and it returns a short URL such as http://tinyurl.com/4e9iAk.
 * Design the encode and decode methods for the TinyURL service. There is no restriction on how your encode/decode algorithm should work. You just need to ensure that a URL can be encoded to a tiny URL and the tiny URL can be decoded to the original URL.
 */

/**
 * 随机生成6个字符作为key，原始url作为value存放在map中就行了，注意冲突的时候再次生成即可。
 */


class Solution {
    public:
        Solution() : chars("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789")
        {
        }

        // Encodes a URL to a shortened URL.
        string encode(string longUrl) {
            std::random_device rd;
            while (true) {
                std::string shortUrl;
                for (size_t i = 0; i < 6; ++i) {
                    shortUrl += chars[rd() % 62];
                }
                auto iter = u.find(shortUrl);
                if (iter != u.end()) {
                    continue;
                }
                u[shortUrl] = longUrl;
                return shortUrl;
            }
        }

        // Decodes a shortened URL to its original URL.
        string decode(string shortUrl) {
            auto iter = u.find(shortUrl);
            if (iter != u.end()) {
                return iter->second;
            }
            return "";
        }

    private:
        const char* chars;
        std::unordered_map<string, string> u;
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
