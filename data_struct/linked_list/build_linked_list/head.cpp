#include "head.h"

Head::Head() {
    this->count = 0;
    this->head = nullptr;
}

void Head::add_node(Node* node) {
    this->count ++;
    Node** cur = &head;

    if(head == nullptr){
        this->head = node;
        return;
    }
    
    while(*cur != nullptr) {
        if((*cur)->next == nullptr) {
            (*cur)->next = node;
            return ;
        }
        cur = &((*cur)->next);
    }
}

void Head::print_list() {
    Node** cur = &head;
    while(*cur != nullptr) {
        std::cout << (*cur)->value << " ";
        cur = &((*cur)->next);
    }
    std::cout << std::endl << std::flush;
}

void Head::insert(int pos, Node* node) {
    Node **cur = &head;
    
    if(pos == 0){
        node->next = head;
        head = node;
        return ;
    }else if(pos > this->count){
        return;
    }

    for(int i = 0; i < pos-1; i++)
        cur = &((*cur)->next);

    node->next = (*cur)->next;
    (*cur)->next = node;

    this->count ++;
}

void Head::del(int pos) {
    Node **cur = &head;
    Node **pre = &head;
    this->count --;
    
    if(pos == 0){
        Node *del_node = head;
        head = head->next;
        del_node->next = nullptr;
        delete del_node;
        return ;
    }else if(pos >= this->count){
        this->count ++;        
        return;
    }

    for(int i = 0; i < pos; i++){
        pre = cur;
        cur = &((*cur)->next); 
    }
    Node *del_node = *cur;
    //std::cout << (*pre)->value << " " << (*cur)->value << std::endl;
    (*pre)->next = (*cur)->next;
    //std::cout << (*pre)->value << " " << (*cur)->value << std::endl;
    del_node->next = nullptr;
    delete del_node;

}