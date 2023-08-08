#include <iostream>

using namespace std;

struct TreapNode
{
    string key;
    float priority;
    TreapNode *left, *right;
};

TreapNode *rightRotate(TreapNode *y)
{
    TreapNode *x = y->left,  *T2 = x->right;

    x->right = y;
    y->left = T2;

    return x;
}

TreapNode *leftRotate(TreapNode *x)
{
    TreapNode *y = x->right, *T2 = y->left;

    y->left = x;
    x->right = T2;

    return y;
}

TreapNode* newNode(string key, float Deathrate)
{
    TreapNode* temp = new TreapNode;
    temp->key = key;
    temp->priority = Deathrate;
    temp->left = temp->right = NULL;
    return temp;
}

TreapNode* search(TreapNode* root, string key)
{
    if (root == NULL || root->key == key)
       return root;

    if (root->key < key)
       return search(root->right, key);

    return search(root->left, key);
}

TreapNode* insert(TreapNode* root, string key, float Deathrate)
{
    if (!root)
        return newNode(key, Deathrate);

    if (key <= root->key) {
        root->left = insert(root->left, key, Deathrate);

        if (root->left->priority > root->priority)
            root = rightRotate(root);
    }
    else {
        root->right = insert(root->right, key, Deathrate);

        if (root->right->priority > root->priority)
            root = leftRotate(root);
    }
    return root;
}

TreapNode* deleteNode(TreapNode* root, string key)
{
    if (root == NULL)
        return root;
  
    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);

    else if (root->left == NULL) {
        TreapNode *temp = root->right;
        delete(root);
        root = temp;
    }

    else if (root->right == NULL) {
        TreapNode *temp = root->left;
        delete(root);
        root = temp;
    }

    else if (root->left->priority < root->right->priority)
    {
        root = leftRotate(root);
        root->left = deleteNode(root->left, key);
    }
    else
    {
        root = rightRotate(root);
        root->right = deleteNode(root->right, key);
    }

    return root;
}

void inorder(TreapNode* root)
{
    if (root) {
        inorder(root->left);
        cout << "key: "<< root->key << " | priority : " << root->priority;
        if (root->left)
            cout << " | left child: " << root->left->key;
        if (root->right)
            cout << " | right child: " << root->right->key;
        cout << endl;
        inorder(root->right);
    }
}

void PrintOneNodeInfo(TreapNode* root, string key)
{
    cout << "key: " << root->key << " | priority : " << root->priority;
    if (root->left)
        cout << " | left child: " << root->left->key;
    if (root->right)
        cout << " | right child: " << root->right->key;
    cout << endl;
}

int main()
{
    srand(time(NULL));

    struct TreapNode *root = NULL;

    root = insert(root, "US", 567610.0f / 31314625.0f * 100.0f); // US : 567,610 / 31,314,625
    root = insert(root, "BR", 328366.0f / 12912379.0f * 100.0f); // BR : 328,366 / 12,912,379
    root = insert(root, "RU", 4186251.0f / 4563056.0f * 100.0f); // RU : 4,186,251 / 4,563,056
    root = insert(root, "GB", 126816.0f / 4353668.0f * 100.0f); // GB : 126,816 / 4,353,668
    root = insert(root, "IT", 110328.0f / 3629000.0f * 100.0f); // IT : 110,328 / 3,629,000
    root = insert(root, "IN", 164141.0f / 12392260.0f * 100.0f); // IN : 164,141 / 12,392,260
    root = insert(root, "FR", 96280.0f / 4741759.0f * 100.0f); // FR : 96,280 / 4,741,759
    root = insert(root, "TR", 31892.0f / 3400296.0f * 100.0f); // TR : 31,892 / 3,400,296
    root = insert(root, "JP", 13523.0f / 760323.0f * 100.0f); // JP : 13,523 / 760,323
    root = insert(root, "KR", 1973.0f / 144152.0f * 100.0f); // KR : 1,973 / 144,152

    cout << " - print tree - \n";
    inorder(root);

    for (int i = 0; i < 3; i++) {
        cout << "\n - Delete RootNode ( " << root->key << " ) - \n";
        root = deleteNode(root, root->key);
        cout << " - print tree - \n";
        inorder(root);
    }

    TreapNode* res = NULL;

    cout << "\n - Search FR - \n";
    res = search(root, "FR");
    if (res == NULL)
        cout << "\n FR Not Found \n";
    else {
        cout << "\n FR found \n";
        PrintOneNodeInfo(root, "FR");
    }

    cout << "\n - Search US - \n";
    res = search(root, "US");
    if (res == NULL)
        cout << "\n US Not Found \n";
    else {
        cout << "\n US found \n";
        PrintOneNodeInfo(root, "US");
    }

    cout << "\n - Search GB - \n";
    res = search(root, "GB");
    if (res == NULL)
        cout << "\n GB Not Found \n";
    else {
        cout << "\n GB found \n";
        PrintOneNodeInfo(root, "GB");
    }

    return 0;
}
