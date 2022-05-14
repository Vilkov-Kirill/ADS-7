// Copyright 2021 NNTU-CS

#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_

struct SYM {
    char ch;
    int prior;
};

template<typename T>
class TPQueue {
 private:
    struct Item {
        T value;
        Item* next = nullptr;
    };
    Item* top = new Item;
    int count = 0;
 public:
    void push(T var);
    T pop();
    int length() { return count; }
};

template<typename T>
T TPQueue<T>::pop() {
    count--;
    T var = top->value;
    top = top->next;
    return var;
}

template<typename T>
void TPQueue<T>::push(T var) {
    if (count == 0) {
        top->value = var;
        count++;
    } else {
        count++;
        Item* curr = top;
        bool flag = false;
        // less prior
        while (curr->value.prior >= var.prior && curr->next != nullptr) {
            curr = curr->next;
            flag = true;
        }
        Item* n = new Item;
        n->value = var;
        if (flag) {
            if (curr->next == nullptr && curr->value.prior >= var.prior) {
                curr->next = n;
                return;
            } else {
                n->next = curr;
                Item* t = top;
                while (t->next != curr) t = t->next;
                t->next = n;
            }
        // higher prior
        } else if (curr->value.prior >= var.prior && curr->next == nullptr) {
            curr->next = n;
        } else {
            n->next = top;
            top = n;
        }
    }
}


#endif  // INCLUDE_TPQUEUE_H_
