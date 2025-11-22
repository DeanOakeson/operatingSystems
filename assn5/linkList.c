#include "linkList.h"

bool isEmpty(struct LinkList *linkList) {
  if (linkList->count == 0) {
    return true;
  } else {
    return false;
  }
}

void initLinkList(struct LinkList *linkList) {
  linkList->root = NULL;
  linkList->count = 0;
  return;
}

struct Node *initNode(process *value) {
  struct Node *node = (struct Node *)malloc(sizeof(struct Node));
  node->next = NULL;
  node->last = NULL;
  node->process = value;

  return node;
};

process *popShortest(struct LinkList *linkList) {

  if (isEmpty(linkList)) {
    return NULL;
  }

  struct Node *oldRoot = linkList->root;
  process *popped = oldRoot->process;
  linkList->root = oldRoot->next;

  if (linkList->root != NULL) {
    linkList->root->last = NULL;
  }

  free(oldRoot);
  linkList->count--;
  return popped;
}

int peekShortest(struct LinkList *linkList) {
  if (isEmpty(linkList)) {
    return -1;
  }
  return linkList->root->process->duration;
}

void insertHelper(struct Node *node, struct Node *curr) {
  // Base case: we've reached the end of the list
  if (curr->next == NULL) {
    curr->next = node;
    node->last = curr;
    return;
  }

  // If the new node should go after curr->next, keep searching
  if (node->process->duration >= curr->next->process->duration) {
    insertHelper(node, curr->next);
  }
  // Otherwise, insert between curr and curr->next
  else {
    node->next = curr->next;
    node->last = curr;
    curr->next->last = node;
    curr->next = node;
  }
  return;
}

void insert(struct LinkList *linkList, process *value) {
  struct Node *newNode = initNode(value);

  if (isEmpty(linkList)) {
    linkList->root = newNode;
    linkList->count++;
    return;
  }

  if (linkList->root->process->duration >= newNode->process->duration) {
    newNode->next = linkList->root;
    linkList->root->last = newNode;
    linkList->root = newNode;
    linkList->count++;
    return;
  }

  if (linkList->root->process->duration < newNode->process->duration) {
    insertHelper(newNode, linkList->root);
    linkList->count++;
    return;
  }
}
