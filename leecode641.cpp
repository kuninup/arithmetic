typedef struct DequeNode {
    int value;
    struct DequeNode *pre, *next;
} Deque;

typedef struct {
    int maxSize;
    int curSize;
    Deque *dequeHead;
} MyCircularDeque;

/** Initialize your data structure here. Set the size of the deque to be k. */
MyCircularDeque* myCircularDequeCreate(int k) {
    MyCircularDeque *myCircularDeque = (MyCircularDeque*)malloc(sizeof(MyCircularDeque));
    myCircularDeque->maxSize = k;
    myCircularDeque->curSize = 0;
    myCircularDeque->dequeHead = (Deque*)malloc(sizeof(Deque));
    myCircularDeque->dequeHead->next = myCircularDeque->dequeHead->pre = myCircularDeque->dequeHead;
    return myCircularDeque;
}

/** Adds an item at the front of Deque. Return true if the operation is successful. */
bool myCircularDequeInsertFront(MyCircularDeque* obj, int value) {
    Deque *head = obj->dequeHead;
    Deque *deque = NULL;
    
    if (obj->curSize == obj->maxSize) {
        return false;
    }
    if ((deque = (Deque*)malloc(sizeof(Deque))) == NULL) {
        return false;
    }
    
    deque->value = value;
    deque->pre = head;
    deque->next = head->next;
    head->next->pre = deque;
    head->next = deque;
    obj->curSize++;
    return true;
}

/** Adds an item at the rear of Deque. Return true if the operation is successful. */
bool myCircularDequeInsertLast(MyCircularDeque* obj, int value) {
    Deque *head = obj->dequeHead;
    Deque *deque = NULL;
    
    if (obj->curSize == obj->maxSize) {
        return false;
    }
    if ((deque = (Deque*)malloc(sizeof(Deque))) == NULL) {
        return false;
    }
    
    deque->value = value;
    deque->next = head;
    deque->pre = head->pre;
    head->pre->next = deque;
    head->pre = deque;
    obj->curSize++;
    return true;
}

/** Deletes an item from the front of Deque. Return true if the operation is successful. */
bool myCircularDequeDeleteFront(MyCircularDeque* obj) {
    Deque *head = obj->dequeHead;
    Deque *front = head->next;
    
    if (obj->curSize == 0) {
        return false;
    }
    
    head->next = front->next;
    front->next->pre = head;
    free(front);
    obj->curSize--;
    return true;
}

/** Deletes an item from the rear of Deque. Return true if the operation is successful. */
bool myCircularDequeDeleteLast(MyCircularDeque* obj) {
    Deque *head = obj->dequeHead;
    Deque *tail = head->pre;
    
    if (obj->curSize == 0) {
        return false;
    }
    
    head->pre = tail->pre;
    tail->pre->next = head;
    free(tail);
    obj->curSize--;
    return true;
}

/** Get the front item from the deque. */
int myCircularDequeGetFront(MyCircularDeque* obj) {
    return obj->curSize == 0 ? -1 : obj->dequeHead->next->value;
}

/** Get the last item from the deque. */
int myCircularDequeGetRear(MyCircularDeque* obj) {
    return obj->curSize == 0 ? -1 : obj->dequeHead->pre->value;
}

/** Checks whether the circular deque is empty or not. */
bool myCircularDequeIsEmpty(MyCircularDeque* obj) {
    return obj->curSize == 0 ? true : false;
}

/** Checks whether the circular deque is full or not. */
bool myCircularDequeIsFull(MyCircularDeque* obj) {
    return obj->curSize == obj->maxSize ? true : false;
}

void myCircularDequeFree(MyCircularDeque* obj) {
    Deque *deque = obj->dequeHead->next;
    obj->dequeHead->pre->next = NULL;
    while (deque) {
        free(obj->dequeHead);
        obj->dequeHead = deque;
        deque = deque->next;
    }
    free(obj->dequeHead);
    free(obj);
}

/**
 * Your MyCircularDeque struct will be instantiated and called as such:
 * MyCircularDeque* obj = myCircularDequeCreate(k);
 * bool param_1 = myCircularDequeInsertFront(obj, value);
 
 * bool param_2 = myCircularDequeInsertLast(obj, value);
 
 * bool param_3 = myCircularDequeDeleteFront(obj);
 
 * bool param_4 = myCircularDequeDeleteLast(obj);
 
 * int param_5 = myCircularDequeGetFront(obj);
 
 * int param_6 = myCircularDequeGetRear(obj);
 
 * bool param_7 = myCircularDequeIsEmpty(obj);
 
 * bool param_8 = myCircularDequeIsFull(obj);
 
 * myCircularDequeFree(obj);
*/
