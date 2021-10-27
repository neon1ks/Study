#include <cstdint>
#include <cstdio>
#include <iostream>
#include <map>
#include <string>

using namespace std;

struct ListNode
{
    ListNode *prev;
    ListNode *next;
    ListNode *
            rand;  // указатель на произвольный элемент данного списка либо NULL
    std::string data;
};

class List
{
public:
    void Gen();
    void Print();
    void Serialize(
            FILE *file);  // сохранение в файл (файл открыт с помощью fopen(path, "wb"))
    void Deserialize(
            FILE *file);  // загрузка из файла (файл открыт с помощью fopen(path, "rb"))
private:
    ListNode *head = nullptr;
    ListNode *tail = nullptr;
    int count = 0;
};

void List::Gen()
{
    if (count) {
        return;
    }
    ListNode *previous = nullptr;
    ListNode *current = new ListNode;
    current->prev = nullptr;
    current->data = string("one1");
    head = current;

    previous = current;

    current = new ListNode;
    current->prev = previous;
    current->data = string("test");
    current->rand = current;

    previous->next = current;
    previous->rand = current;

    previous = current;

    current = new ListNode;
    current->prev = previous;
    current->data = string("two2");
    current->rand = previous;
    current->next = nullptr;

    tail = current;

    previous->next = current;
    count = 3;
}

void List::Print()
{
    auto current = head;
    cout << "count = " << count << endl;

    for (int i = 0; i < count; ++i) {
        cout << "i = " << i << endl;
        cout << "now  = " << current << ' ' << current->data << endl;
        cout << "prev = " << current->prev << ' ';
        cout << (current->prev != nullptr ? current->prev->data : "") << endl;
        cout << "next = " << current->next << ' ';
        cout << (current->next != nullptr ? current->next->data : "") << endl;
        cout << "rand = " << current->rand << ' ';
        cout << (current->rand != nullptr ? current->rand->data : "") << endl;
        cout << endl;
        current = current->next;
    }
}


void List::Serialize(FILE *file)
{

    map<ListNode *, uint32_t> cache;
    cache[nullptr] = 0;

    ListNode *current = head;
    for (uint32_t i = 1; i <= static_cast<uint32_t>(count); ++i) {
        cache[current] = i;
        current = current->next;
    }

    uint32_t size = static_cast<uint32_t>(count);
    fwrite(reinterpret_cast<const void *>(&size), sizeof(size), 1, file);

    current = head;
    for (int i = 0; i < count; ++i) {
        uint32_t index = cache.at(current->rand);
        fwrite(reinterpret_cast<const void *>(&index), sizeof(index), 1, file);

        uint64_t sizeStr = current->data.size();
        fwrite(reinterpret_cast<const void *>(&sizeStr), sizeof(sizeStr), 1,
                file);
        fwrite(reinterpret_cast<const void *>(current->data.c_str()),
                sizeof(char), current->data.size(), file);

        current = current->next;
    }
}

void List::Deserialize(FILE *file)
{

    map<uint32_t, ListNode *> cache;
    cache[0] = nullptr;

    uint32_t size = {};
    fread(reinterpret_cast<void *>(&size), sizeof(size), 1, file);
    count = static_cast<int>(size);
    if (size == 0) {
        return;
    }

    ListNode *previous = nullptr;
    ListNode *current = new ListNode;
    current->prev = nullptr;
    head = current;

    cache[1] = current;
    for (uint32_t i = 2; i <= static_cast<uint32_t>(count); ++i) {
        previous = current;
        current = new ListNode;
        previous->next = current;
        current->prev = previous;
        cache[i] = current;
    }
    current->next = nullptr;
    tail = current;

    current = head;
    for (uint32_t i = 1; i <= static_cast<uint32_t>(count); ++i) {

        uint32_t index = {};
        fread(reinterpret_cast<void *>(&index), sizeof(index), 1, file);
        current->rand = cache.at(index);

        uint64_t sizeStr = {};
        fread(reinterpret_cast<void *>(&sizeStr), sizeof(sizeStr), 1, file);

        char *str = new char[sizeStr + 1];
        str[sizeStr] = '\0';
        fread(reinterpret_cast<void *>(str), sizeof(char), sizeStr, file);
        current->data = string(str);

        current = current->next;
    }
}

int main()
{
    List list;
    list.Gen();
    list.Print();

    FILE *fp = nullptr;
    if ((fp = fopen("testread.data", "wb")) == nullptr) {
        printf("Cannot open file.");
        return 1;
    }
    list.Serialize(fp);

    fclose(fp);
    fp = nullptr;

    List list2;
    if ((fp = fopen("testread.data", "rb")) == nullptr) {
        printf("Cannot open file.");
        return 1;
    }

    list2.Deserialize(fp);
    fclose(fp);
    fp = nullptr;

    cout << "Read" << endl;
    list2.Print();

    return 0;
}
