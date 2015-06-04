// AVL tree

#include <iostream>
#include <ctime>

using namespace std;

struct node {
    int key;
    node * left;
    node * right;
    int height;
    int bf; // balance factor
};

class AVL {
private:
    node* root;
    node* R_rotate(node*);
    node* L_rotate(node*);
    node* RL_rotate(node*);
    node* LR_rotate(node*);
    node* insert_avl(int, node*);
    node* delete_avl();
    void display_avl(int, node*);
    int search_avl(int, node*);
    int avl_height(node *r) {
        if(r == NULL) return -1;
        else return r->height;
    }
    int maximum(int a, int b) {
        return (a>b)?a:b;
    }
    void preorder(node*);
    void postorder(node*);
    void inorder(node*);
public:
    void ins();
    void del();
    void src();
    void dis(int l);
};

void AVL::postorder(node* r) {
    if(r != NULL) {
        postorder(r->left);
        postorder(r->right);
        cout << r->key << " ";
    }
}

void AVL::preorder(node* r) {
    if(r != NULL) {
        cout << r->key << " ";
        preorder(r->left);
        preorder(r->right);
    }
}

void AVL::inorder(node* r) {
    if(r != NULL) {
        inorder(r->left);
        cout << r->key << " ";
        inorder(r->right);
    }
}

void AVL::src() {
    cout << "ENTER THE VALUE TO SEARCH: ";
    int s;
    cin >> s;
    if(search_avl(s, root))
        cout << "KEY FOUND!" << endl;
    else
        cout << "KEY NOT FOUND!" << endl;
}

int AVL::search_avl(int a, node* r) {
    if(r == NULL) return 0;
    else if(r->key == a) return 1;
    else if(a < r->key) return search_avl(a, r->left);
    else return search_avl(a, r->right);
}

node* AVL::R_rotate(node* r) {
	node* t = r->left;
	r->left = t->right;
	t->right = r;
	r->height = maximum(avl_height(r->left), avl_height(r->right))+1;
	t->height = maximum(avl_height(t->left), avl_height(t->right))+1;
	return t;
}

node* AVL::L_rotate(node* r) {
	node* t = r->right;
	r->right = t->left;
	t->left = r;
	r->height = maximum(avl_height(r->left), avl_height(r->right))+1;
	t->height = maximum(avl_height(t->left), avl_height(t->right))+1;
	return t;
}

node* AVL::LR_rotate(node* r) {
	r->left = L_rotate(r->left);
	return R_rotate(r);
}

node* AVL::RL_rotate(node* r) {
	r->right = R_rotate(r->right);
	return L_rotate(r);
}

void AVL::dis(int l) {
    display_avl(l, root);
    cout << "Preorder" << endl;
    preorder(root);
    cout << "\npostorder" << endl;
    postorder(root);
    cout << "\ninorder" << endl;
    inorder(root);
    cout << endl;
}

void AVL::display_avl(int l, node* r) {
    if(r != NULL) {
        display_avl(l+1, r->right);
        for(int i = 0; i < l; i++)
            cout << "--";
        cout << r->key << endl;
        display_avl(l+1, r->left);
    }
}

void AVL::ins() {
    cout << "Enter the value to insert: ";
    int val;
    cin >> val;
    root = insert_avl(val, root);
}

node* AVL::insert_avl(int val, node* r) {
    if(r == NULL) {
        r = new node;
        r->key = val;
        r->bf = r->height = 0;
        r->left = r->right = NULL;
        return r;
    }
    else if(r->key == val) {
        cout << "DUPLICATES NOT ALLOWED!" << endl;
        return r;
    }
    else if(r->key < val)
        r->right = insert_avl(val, r->right);
    else
        r->left = insert_avl(val, r->left);

    r->height = maximum(avl_height(r->left), avl_height(r->right))+1;
    r->bf = avl_height(r->left) - avl_height(r->right);

    if(r->bf < -1) {
        if(val < (r->right)->key)
            r = RL_rotate(r);
        else
            r = L_rotate(r);
    }
    if(r->bf > 1) {
        if(val > (r->left)->key)
            r = LR_rotate(r);
        else
            r = R_rotate(r);
    }
    return r;
}

int main(void) {
    cout << "1> insert\n3> display tree\n4> search\n5>exit" << endl;
    AVL avl_t = AVL();
    while(1) {
        cout << "Enter your option: ";
        int ch;
        cin >> ch;
        switch(ch) {
            case 1: avl_t.ins(); break;
            case 3: avl_t.dis(0); break;
            case 4: avl_t.src(); break;
            case 5: return 0; break;
            default: cout << "Enter correct choice!" << endl;
        }
    }
    return 0;
}
