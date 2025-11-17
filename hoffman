#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

// Huffman Tree Node
struct HuffmanNode {
    char ch;
    int freq;
    HuffmanNode *left, *right;

    HuffmanNode(char c, int f) : ch(c), freq(f), left(nullptr), right(nullptr) {}
    HuffmanNode(int f, HuffmanNode* l, HuffmanNode* r) 
        : ch('\0'), freq(f), left(l), right(r) {}
};

// Min-Heap comparator
struct Compare {
    bool operator()(HuffmanNode* a, HuffmanNode* b) {
        return a->freq > b->freq;
    }
};

// Recursively build Huffman codes
void buildCodes(HuffmanNode* root, const string& code, unordered_map<char, string>& huffmanCode) {
    if (!root) return;

    if (!root->left && !root->right) {
        huffmanCode[root->ch] = code;
    }

    buildCodes(root->left, code + "0", huffmanCode);
    buildCodes(root->right, code + "1", huffmanCode);
}

// Encode text into binary string
string encodeText(const string& text, unordered_map<char, string>& huffmanCode) {
    string encodedString;
    for (char ch : text) {
        encodedString += huffmanCode[ch];
    }
    return encodedString;
}

// Decode binary string back to original text
string decodeText(const string& encodedStr, HuffmanNode* root) {
    string decodedString;
    HuffmanNode* curr = root;

    for (char bit : encodedStr) {
        curr = (bit == '0') ? curr->left : curr->right;

        if (!curr->left && !curr->right) {
            decodedString += curr->ch;
            curr = root;
        }
    }
    return decodedString;
}

// Build Huffman Tree from text input
HuffmanNode* buildHuffmanTree(const string& text) {
    unordered_map<char, int> freq;
    for (char ch : text) {
        freq[ch]++;
    }

    priority_queue<HuffmanNode*, vector<HuffmanNode*>, Compare> pq;
    for (auto& pair : freq) {
        pq.push(new HuffmanNode(pair.first, pair.second));
    }

    while (pq.size() > 1) {
        HuffmanNode* left = pq.top(); pq.pop();
        HuffmanNode* right = pq.top(); pq.pop();

        HuffmanNode* parent = new HuffmanNode(left->freq + right->freq, left, right);
        pq.push(parent);
    }

    return pq.top();
}

int main() {
    string text;

    cout << "Enter input text: ";
    getline(cin, text);

    if (text.empty()) {
        cout << "Error: empty input!" << endl;
        return 1;
    }

    HuffmanNode* root = buildHuffmanTree(text);

    unordered_map<char, string> huffmanCode;
    buildCodes(root, "", huffmanCode);

    cout << "\nHuffman Codes:\n";
    for (auto& pair : huffmanCode) {
        cout << pair.first << ": " << pair.second << endl;
    }

    string encoded = encodeText(text, huffmanCode);
    cout << "\nEncoded String:\n" << encoded << endl;

    string decoded = decodeText(encoded, root);
    cout << "\nDecoded String:\n" << decoded << endl;

    int originalSize = text.length() * 8; // each char = 8 bits
    int compressedSize = encoded.length();

    cout << "\nCompression Ratio:\n";
    cout << "Original size: " << originalSize << " bits\n";
    cout << "Compressed size: " << compressedSize << " bits\n";
    cout << "Compression ratio: " 
         << fixed << (double)originalSize / compressedSize << endl;

    return 0;
}
