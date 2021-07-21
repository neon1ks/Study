#include <algorithm>
#include <cassert>
#include <cstddef>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <tuple>
#include <queue>

class Huffman
{
    struct CharFrequency
    {
        char c;
        int frequency;

        bool operator<(const CharFrequency &other) const
        {
            return std::tie(frequency, c) > std::tie(other.frequency, other.c);
        }
    };
    struct CharSetFrequency
    {
        std::string char_set;
        int frequency;

        bool operator<(const CharSetFrequency &other) const
        {
            return std::tie(frequency, char_set)
                   > std::tie(other.frequency, other.char_set);
        }
    };

    // input array must be sorted by frequency
    // sum of all frequencies must be passed in total_frequency
    static std::unordered_map<char, std::string> shannon_fano_encode(
            const std::vector<CharFrequency> &frequencies, int total_frequency);

public:
    static std::unordered_map<char, std::string> encode(
            const std::string &text);
    static std::unordered_map<char, std::string> encode2(
            const std::string &text);
    static std::string decode(const std::string &text,
            const std::unordered_map<char, std::string> &huffman_encoding);
};

std::unordered_map<char, std::string> Huffman::shannon_fano_encode(
        const std::vector<CharFrequency> &frequencies, int total_frequency)
{

    size_t size = frequencies.size();
    std::unordered_map<char, std::string> result;
    if (size <= 1) {
        for (auto &frequency : frequencies) {
            result[frequency.c] = "";
        }
        return std::move(result);
    }

    // greddy split frequencies into two parts
    // with approximately equal total frequency
    size_t split_pos;
    int first_part_frequency = 0;
    for (split_pos = 0; split_pos < size; ++split_pos) {
        int current_frequency = frequencies[split_pos].frequency;
        if (first_part_frequency
                >= total_frequency
                           - (first_part_frequency + current_frequency)) {
            // adding curent character increases difference
            // between part frequences
            break;
        }
        first_part_frequency += current_frequency;
    }
    assert(split_pos < size);

    // merge part results
    for (auto &encoded : shannon_fano_encode(
                 { frequencies.begin(), frequencies.begin() + split_pos },
                 first_part_frequency)) {
        result[encoded.first] = "0" + encoded.second;
    }
    for (auto &encoded : shannon_fano_encode(
                 { frequencies.begin() + split_pos, frequencies.end() },
                 total_frequency - first_part_frequency)) {
        result[encoded.first] = "1" + encoded.second;
    }
    return std::move(result);
}

std::unordered_map<char, std::string> Huffman::encode(const std::string &text)
{
    std::unordered_map<char, int> char_frequencies;
    for (auto c : text) {
        char_frequencies[c]++;
    }

    std::vector<CharSetFrequency> frequencies;
    for (auto char_frequency : char_frequencies) {
        frequencies.push_back({ std::string(1, char_frequency.first),
                char_frequency.second });
    }

    if (frequencies.size() == 1) {
        std::unordered_map<char, std::string> result;
        result[frequencies[0].char_set[0]] = "0";
        return result;
    }

    std::unordered_map<char, std::string> result;
    std::priority_queue<CharSetFrequency> q(
            frequencies.begin(), frequencies.end());
    while (q.size() >= 2) {
        auto first = q.top();
        q.pop();
        auto second = q.top();
        q.pop();

        for (auto c : first.char_set) {
            //result[c] = "0" + result[c];
            result[c] += "0";
        }

        for (auto c : second.char_set) {
            //result[c] = "1" + result[c];
            result[c] += "1";
        }

        q.push({ first.char_set + second.char_set,
                first.frequency + second.frequency });
    }
    for (auto &it : result) {
        std::reverse(it.second.begin(), it.second.end());
    }

    return result;
}

std::unordered_map<char, std::string> Huffman::encode2(const std::string &text)
{
    std::unordered_map<char, int> char_frequencies;
    for (auto c : text) {
        char_frequencies[c]++;
    }

    std::vector<CharFrequency> frequencies;
    for (auto char_frequency : char_frequencies) {
        frequencies.push_back({ char_frequency.first, char_frequency.second });
    }
    std::sort(frequencies.begin(), frequencies.end());

    if (frequencies.size() == 1) {
        // We can't return empty encoding
        // so this case need to be considered separately
        std::unordered_map<char, std::string> result;
        result[frequencies[0].c] = "0";
        return result;
    }

    return shannon_fano_encode(
            std::move(frequencies), static_cast<int>(text.size()));
}

std::string Huffman::decode(const std::string &text,
        const std::unordered_map<char, std::string> &huffman_encoding)
{
    size_t len = text.size();
    size_t pos = 0;
    std::string result;
    while (pos < len) {
        for (auto &encoded : huffman_encoding) {
            if (text.substr(pos, encoded.second.size()) == encoded.second) {
                result += encoded.first;
                pos += encoded.second.size();
                break;
            }
        }
    }
    return result;
}

int main()
{
    std::string str;
    std::getline(std::cin, str);

    auto huffman_encoding = Huffman::encode(str);
    std::string encoded_text;
    for (auto &c : str) {
        encoded_text += huffman_encoding[c];
    }

    std::cout << huffman_encoding.size() << " " << encoded_text.size()
              << std::endl;

    for (auto &encoded : huffman_encoding) {
        std::cout << encoded.first << ": " << encoded.second << std::endl;
    }
    std::cout << encoded_text << std::endl;
    return 0;
}
