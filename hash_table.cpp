#include "hash_table.h"
#include <cstring>
#include <iostream>

#define ABS(x) (x)<0?-(x):(x)

hashLink::hashLink()
{
next=NULL;
value=NULL;
key=-1;

}

hashLink::~hashLink()
{
hashLink *temp,*prev;
temp=this;
prev=this;
while(temp->next!=NULL){
    temp=prev->next;
    delete prev;
    prev=temp;
}

}

void hashLink::setFields(char* str,int k){
    value = new char[100];
    strcpy(value,str);
    key=k;
}

hashTable::hashTable(int length)
{
    len=length;
    arr= new hashLink[len];

}

hashTable::~hashTable()
{
}

int hashTable::hashFunc(char* str)
{
if(str==NULL || *str=='\0')
 return -1;

char* temp=str;
int key=0;
while((*temp)!='\0'){
    int digit = (int)ABS('A' - (*temp));
    key= key + digit;
    temp++;
    
}

return key;
}


int hashTable::hashInsert(char *str,bool duplicate) // 0 means no collision. 1 means collision occured; 2 means already in hash; -1 not succed 
{
    int key = hashFunc(str);
    if(key==-1)
        return -1;
    if(!duplicate && hashFind(str)!=-1)
        return 2;    

    

    int arrindex= key%len;
    hashLink *linkPtr= &arr[arrindex];
    int collision=0;
    //printf("index %d\n",arrindex);

    if(linkPtr->next!=NULL)
        collision=1;
    while(linkPtr->next!=NULL){
        //printf("collision %d\n",key);
        linkPtr = linkPtr->next;
        
    }

    if(linkPtr!=NULL){
        linkPtr->setFields(str,key);
        linkPtr->next = new hashLink;
    }
    return collision;
}

int hashTable::hashFind(char* str)
{
    int key = hashFunc(str);
    if(key==-1)
        return key;

    int arrindex= key%len;
    hashLink *linkPtr= &arr[arrindex];
        
    while(linkPtr->next!=NULL)
    {
        if(strcmp(linkPtr->value,str)==0)
            return key%len;
        linkPtr= linkPtr->next;
    }
    
    return -1;

}

void hashTable::print()
{
hashLink *ptr;
for(int i=0;i<len;i++){
    ptr= &arr[i];
    if(ptr->next!=NULL){
        printf("hashtable[%d] =>",i);
        while(ptr!=NULL)
        {
            printf("key=%d str=%s ->",ptr->key, ptr->value, ptr->next);
            ptr=ptr->next;

        }
        printf("\n \n");
    }
}

}

                

