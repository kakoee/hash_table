#include "hash_table.h"

#ifndef __IOSTREAM_H
#include <iostream>
#endif


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


}
