class Solution {
public:
    // Rotate string clockwise by 1 position
    void rotateClockwise(string& s) {
        char lastChar = s.back();
        for (int i = s.size() - 1; i > 0; i--) {
            s[i] = s[i - 1];
        }
        s[0] = lastChar;
    }

    // Rotate string anticlockwise by 1 position
    void rotateAnticlockwise(string& s) {
        char firstChar = s[0];
        for (int i = 0; i < s.size() - 1; i++) {
            s[i] = s[i + 1];
        }
        s.back() = firstChar;
    }

    bool isRotated(string& s1, string& s2) {
        if (s1.size() != s2.size()) return false;

        string clockwiseRotated = s1;
        // Rotate clockwise twice
        rotateClockwise(clockwiseRotated);
        rotateClockwise(clockwiseRotated);
        if (clockwiseRotated == s2) return true;

        string anticlockwiseRotated = s1;
        // Rotate anticlockwise twice
        rotateAnticlockwise(anticlockwiseRotated);
        rotateAnticlockwise(anticlockwiseRotated);
        if (anticlockwiseRotated == s2) return true;

        return false;
    }
};
