#include "list.h"
#include "mem.h"

void arrayListInit(array_list *al,int eleSize){
    al->data = newMem(ARRAY_LIST_DEFAULT_SIZE);
    al->max_size = ARRAY_LIST_DEFAULT_SIZE;
    al->ele_size = eleSize;
    al->size = 0;
}
void arrayListRemove(array_list *al){
    deleteMem(al->data);
}
void *arrayListGet(array_list *al, int index){
    
}
void arrayListSet(array_list *al, int index, void *val){

}
void arrayListSize(array_list *al){

}
void arrayListAdd(array_list *al, void *val){

}
void arrayListPop(array_list *al){
    
}
