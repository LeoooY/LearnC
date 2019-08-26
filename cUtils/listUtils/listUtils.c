#include <stdio.h>

typedef struct node
{
  int val;
  struct node *next;
} listNode;

/* 
  初始化链表
  useage:  
  listNode * head=initANode(2);
  head->next=initANode(9); 
 */
listNode *initANode(int value)
{
  listNode *node = NULL;
  node = malloc(sizeof(listNode));

  node->val = value;
  node->next = NULL;
  return node;
}

/* 
  遍历链表

*/
void iterateList(listNode *head)
{
  listNode *curNode = head;

  while (curNode->val != NULL)
  {
    printf("%d\n", curNode->val) : curNode = curNode->next;
  }
}

/* 
  在链表尾部添加元素

*/
void pushToEnd(listNode *head, int pushVal)
{
  listNode *curNode = head;
  while (curNode->next != NULL)
  {
    curNode = curNode->next;
  }

  listNode *newNode = malloc(sizeof(listNode));
  curNode->next = newNode;
  newNode->val = pushVal;
  newNode->next = NULL;

  /* is almost the same as below*/
  /* 
    current->next = malloc(sizeof(node_t));
    current->next->val = val;
    current->next->next = NULL;
  */
}

/* 
  在链表头部添加元素
  思路：
  1 Create a new item and set its value
    创建一个新节点，并附上值
  2 Link the new item to point to the head of the list
    将新节点指向现在的 head
  3 Set the head of the list to be our new item
    修改现在的head,为新节点
  要实现以上操作，需要传递一个指向head的指针，
  加上head本身为一个指针，即为传递一个双重指针head.
*/
void pushToStart(listNode **head, int pushVal)
{
  listNode *newNode = malloc(sizeof(listNode));

  newNode->val = pushVal;
  newNode->next = *head;
  *head = newNode;
}

void pushToStart2(listNode *head, int pushVal)
{
  listNode *newNode = malloc(sizeof(listNode));

  newNode->val = head->val;
  newNode->next = head->next;
  head->next = newNode;
  head->val = pushVal;
}

void delFirst(listNode **head)
{
  int isSucess = -1;

  if (*head == NULL)
  {
    return isSucess;
  }

  /*
    head->next在创建时候就已经为动态分配内存的
    所以不需要再使用 malloc(sizeof())
  */
  listNode *nextNode = head->next;
  // isSucess = (*head)->val;
  isSucess = 1;
  free(*head);
  *head = nextNode;

  return isSucess;
}

void delLast(listNode *head)
{
  int isSuccess = -1;
  if (head == NULL)
  {
    return isSuccess;
  }
  if (head->next = NULL)
  {
    free(head);
    isSuccess = 1;
    return isSuccess;
  }

  listNode *cur = malloc(sizeof(listNode));

  while (cur->next->next != NULL)
  {
    cur = cur->next;
  }

  free(cur->next);
  cur->next = NULL;
  isSuccess = 1;

  return isSuccess;
}

void delOneByIdx(listNode **head, int idx)
{
  if (idx == 0)
  {
    return delFirst(head);
  }
  listNode *cur = malloc(sizeof(listNode));

  /* 
    取到idx的前一个元素
   */
  for (int i = 0; i < idx; i++)
  {
    if (cur->next == NULL)
    {
      /* 
      事先不知道链表长度
      所以有可能idx超过链表长度
    */
      return -1;
    }
    cur = cur->next;
  }

  listNode *tmpNode = cur->next;
  cur->next = cur->next->next;
  free(tmpNode);

  return 1;
}