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
    int hashInsert(char* str,bool duplicate=false);
    int hashFind(char* str);
    int hashFunc(char* str);
    void print();

};




