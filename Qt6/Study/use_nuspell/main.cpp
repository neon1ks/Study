#include <iostream>
#include <nuspell/dictionary.hxx>
#include <nuspell/finder.hxx>

#include <fstream>

using namespace std;

const std::string file_name_dic = {
    "C:/Users/neon1/Maksim/WritingBooks/resources/dictionaries/ru_RU/ru_RU.dic"
};
const std::string file_name_aff = {
    "C:/Users/neon1/Maksim/WritingBooks/resources/dictionaries/ru_RU/ru_RU.aff"
};

/*
const std::string file_name_dic = {
    "C:/Users/neon1/Maksim/WritingBooks/resources/dictionaries/en/en_US.dic"
};
const std::string file_name_aff = {
    "C:/Users/neon1/Maksim/WritingBooks/resources/dictionaries/en/en_US.aff"
};
*/

void test(nuspell::v4::Dictionary &dict, const std::string &word)
{
    auto sugs = vector<string>();

    if (dict.spell(word)) {
        cout << "Word \"" << word << "\" is ok.\n";
        return;
    }

    cout << "Word \"" << word << "\" is incorrect.\n";
    dict.suggest(word, sugs);
    if (sugs.empty())
        return;
    cout << "  Suggestions are: ";
    for (auto &sug : sugs)
        cout << sug << ' ';
    cout << '\n';
}

int translate()
{
    /* the commented out code does not work correctly on windows 10
    auto dict_list = vector<pair<string, string>>();
    std::vector<string> paths = {
        { R"(C:/Users/neon1/Maksim/WritingBooks/resources/dictionaries/ru_RU/)" }
    };
    std::vector<string> libreoffice_dir = {
        { "C:/Program Files/LibreOffice/" }
    };
    nuspell::append_default_dir_paths(paths);
    nuspell::append_libreoffice_dir_paths(libreoffice_dir);
    nuspell::search_default_dirs_for_dicts(dict_list);
    for (const auto &p : dict_list) {
        cout << p.first << "\t" << p.second << std::endl;
    }
    cout << std::endl;
    auto dict_name_and_path = nuspell::find_dictionary(dict_list, "ru_RU");
    if (dict_name_and_path == end(dict_list)) {
        std::cout << "No find" << std::endl;
        return 1; // Return error because we can not find the requested
                  // dictionary in the list.
    }
    auto &dict_path = dict_name_and_path->second;
    auto dict = nuspell::Dictionary::load_from_path(dict_path);
    */

    std::ifstream file_aff;
    std::ifstream file_dic;

    file_aff.open(file_name_aff);
    file_dic.open(file_name_dic);

    if (!file_aff.is_open() || !file_dic.is_open()) {
        std::cout << "Could not open the files" << std::endl;
    }
    auto dict = nuspell::Dictionary();
    try {
        dict = nuspell::Dictionary::load_from_aff_dic(file_aff, file_dic);

    } catch (const nuspell::Dictionary_Loading_Error &e) {
        cerr << e.what() << '\n';
        return 1;
    }

    test(dict, "Привет");
    test(dict, "Превет");
    /*
    auto word = string();
    auto sugs = vector<string>();
    while (cin >> word) {
        if (dict.spell(word)) {
            cout << "Word \"" << word << "\" is ok.\n";
            continue;
        }

        cout << "Word \"" << word << "\" is incorrect.\n";
        dict.suggest(word, sugs);
        if (sugs.empty())
            continue;
        cout << "  Suggestions are: ";
        for (auto &sug : sugs)
            cout << sug << ' ';
        cout << '\n';
    }
    */
    return 0;
}

int main()
{
    int status = translate();
    return status;
}
