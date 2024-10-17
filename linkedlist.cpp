#include<iostream>
#include<vector>

using namespace std;
typedef struct list_node *list_pointer;
typedef struct list_node{
    int data;
    list_pointer link;
};
 
list_pointer invert(list_pointer lead){
    list_pointer middle, trail;
    middle = NULL;
    while(lead){
        trail = middle;
        middle = lead;
        lead = lead -> link;
        middle -> link = trail;
    }
    return middle;
}

list_pointer search(list_pointer lead, int item){
    list_pointer cur = lead;
    while(cur -> link){
        if(cur->data == item) return cur;
        cur = cur->link;
    }
    return NULL;
}

void insert(list_pointer pre, int item){
    list_pointer node = (list_pointer)malloc(sizeof(list_node));
    node->data = item;
    node->link = pre -> link;
    pre ->link = node;
    
}

void push_front(list_pointer lead, int item){
    list_pointer node = (list_pointer)malloc(sizeof(list_node));
    node->data=item;
    node->link = lead;
    lead = node;
}

void push_back(list_pointer lead, int item){
    list_pointer node = (list_pointer)malloc(sizeof(list_node));
    node -> data = item;
    node->link = NULL;
    if(!lead){
        lead = node;
    }
    else{
        list_pointer cur = lead;
        while(cur->link)cur = cur->link;
        cur->link = node;
    }
}

list_pointer deleteNode(list_pointer lead, list_pointer node){
    list_pointer ptr = lead;
    if(node == lead){
        lead = lead->link;
        free(ptr);
        return lead;
    }
    else if(!lead) return NULL;
    else{
        while(ptr->link != node) ptr = ptr->link;
        ptr->link = node ->link;
        free(node);
        return lead;
    }
}

void print(list_pointer ptr){
    list_pointer cur = ptr;
    while(cur){
        cout << cur->data ;
        cur = cur->link;
        if(cur) cout << " ";
    }
    cout << endl;
}

int main(){
    int n;
    cin >> n;
    list_pointer ptr, cur, pre;
    ptr = (list_pointer)malloc(sizeof(list_node));

    for(int i = 0; i < n; i++){
        cur = (list_pointer)malloc(sizeof(list_node));

        scanf("%d",&(cur->data));
        if(i == 0){
            ptr ->data = cur->data;
            pre = ptr;
        }
        else{
            pre->link = cur;
            cur->link = NULL;
            pre = cur;
        }
    }
    free(cur);
    ptr = invert(ptr);
    print(ptr);

    list_pointer a = search(cur, 9);
    insert(a, 100);
    print(cur);
    a = search(cur, 3);
    deleteNode(cur, a);
    print(cur);


}