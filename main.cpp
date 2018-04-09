#include "hash_table.h"
#include <cstring>
#ifndef __IOSTREAM_H
#include <iostream>
#endif



bool IsPermutation(char* str1, char* str2)
{
//int len1= strlen(str1);
//int len2= strlen(str2);
//if(len1!=len2)
//    return false;

char p[2];
char *temp1=str1;
char *temp2=str2;
p[1]='\0';
hashTable myhash(150);
while(*temp1)
{
    p[0]=*temp1;
    myhash.hashInsert(p);
    temp1++;
}

while(*temp2)
{
    p[0]=*temp2;
    int insert= myhash.hashInsert(p,true);
    temp2++;
}

myhash.print();
hashLink *hl;
for(int i=0;i<(myhash.len);i++)
{
    hl= &myhash.arr[i];
    if(hl!=NULL && hl->key!=-1 && hl->next!=NULL && hl->next->next==NULL)
        return false;
}


return true;   



}







int main()
{


hashTable myhash(10);
char str[20] = "This is test";
myhash.hashInsert(str);

myhash.hashInsert("is This test"); // collision with str

myhash.hashInsert("This is test3");
myhash.hashInsert("This is test4");
myhash.hashInsert("This is test5");
myhash.print();

printf("finding str \"%s\"...at %d\n",str,myhash.hashFind(str));

printf("finding str \"%s\"...at %d\n","not exist",myhash.hashFind("not exist"));


//following checks if string has unique characters using hashtable;
char p[2];
p[1]='\0';
char* test_str=str;
hashTable hash(10);
bool unique=true;
while(*test_str!='\0'){
    p[0]=(*test_str);
    int hash_insert = hash.hashInsert(p);
    if(hash_insert==2)
    {
        printf("no unique character. repeated character = %s\n\n",p);
        unique=false;
        break;
    }
    test_str++;
}
if(unique)
   printf("String \"%s\" has all unique characters",str); 

     
//
bool permut=IsPermutation("thiss","sihst");
if(permut)
    printf("strings are permutations\n");
else
    printf("strings are NOt permutations\n");



 
}
