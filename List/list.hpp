#ifndef __LIST__
#define __LIST__

#include<assert.h>
#include<stdlib.h>
#include<stdio.h>


template <typename T>
class List
{
    private:
        typedef struct Node
        {
            Node* next;
            T value;
        } Node;

        Node* node;
        size_t list_size;
    public:
        List();
        ~List();
        void del_Node(Node* node);
        List(const List& list);
        void* copy_Node(const Node* node);

        void push(T new_el);
        T front();
        void pop();
        size_t size();

        T operator[] (unsigned int index);
        List<T> operator= (const List<T>&);
        List<T> operator+ (const List<T>&);
};


template <typename T>
List<T>::List()
{
   node = NULL;
   list_size = 0;
}


template <typename T>
List<T>::~List()
{
    if(node!=NULL)
        del_Node(node);
}


template <typename T>
void List<T>::del_Node(Node* node)
{
    if(node->next != NULL)
    {
        del_Node(node->next);
        delete node;
    }
}


template <typename T>
List<T>::List(const List& copy_list)
{
    node = (Node*)copy_Node(copy_list.node);
    list_size = copy_list.list_size;
}


template <typename T>
void* List<T>::copy_Node(const Node* node)
{
    if(node)
    {
        Node* ret = new Node;
        ret->value = T(node->value);

        ret->next = (Node*)copy_Node(node->next);

        return ret;
    }
    else return NULL;
}


template <typename T>
void List<T>::push(T new_el)
{
    list_size++;

    Node* added = new Node;
    added->next = node;
    added->value = new_el;
    node = added;
}


template <typename T>
T List<T>::front()
{
    if(node)
        return node->value;
    else
    {
        printf("Empty List\n");
        assert(0);
    }

}


template <typename T>
void List<T>::pop()
{
    if(node)
    {
        if(node->next!=NULL)
        {
            Node* tmp = node;
            node = node->next;
            delete tmp;
        }
        else
        {
            delete node;
            node = NULL;
        }
    }
    else
    {
        printf("Empty List\n");
        assert(0);
    }
}


template <typename T>
T List<T>::operator  [](unsigned int index)
{
    Node* current = node;
    if(index>=list_size)
    {
        printf("Out of list\n");
        assert(0);
    }

    for(int i=0; i<list_size-1-index; i++)
    {
        if(!current)
        {
            printf("Out of list\n");
            assert(0);
        }

        current = current->next;
    }

    return current->value;
}


template <typename T>
size_t List<T>::size()
{
    return list_size;
}


template <typename T>
List<T> List<T>::operator= (const List<T>& list)
{
    return List(list);
}


template <typename T>
List<T> List<T>::operator+ (const List<T>& list)
{
    List<T> ret_list = List(*this);
    if(!node)
    {
        node = new Node;
        node->next = list.node;
    }
    else
    {
        Node* current = ret_list.node;
        while(current->next!=NULL)
        {
            current = current->next;
            assert(current!=NULL);
        }
        current->next = list.node;
        ret_list.list_size+=list.list_size;
    }

    return ret_list;
}

#endif
