class hashLink
{
public:
    int key;
    char* value;
    hashLink *next;
    
    hashLink();
    ~hashLink();
    void setFields(char* str,int k);
};

class hashTable
{
public:
    hashTable(int length);
    ~hashTable();

    hashLink *arr;
    int len;
    void hashInsert(char* str);
    int hashFind(char* str);
    int hashFunc(char* str);
    void print();

};




