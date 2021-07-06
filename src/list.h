
#define ARRAY_LIST_DEFAULT_SIZE 2

typedef struct {
  void *data;
  int ele_size; // 元素的大小
  int size; // 元素的个数
  int max_size; // 最大容量
} array_list;

void arrayListInit(array_list *al,int eleSize);
void arrayListRemove(array_list *al);
void *arrayListGet(array_list *al, int index);
void arrayListSet(array_list *al, int index, void *val);
void arrayListSize(array_list *al);
void arrayListAdd(array_list *al, void *val);
void arrayListPop(array_list *al);
