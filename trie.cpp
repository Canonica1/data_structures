const int alpha = 26;
struct node
{
    node* to[alpha] = { 0 };
    bool term = false;

};
node* root = new node();

void add(string& s) {
    node* v = root;
    for (char c : s)
    {
        c -= 'a';
        if (!v->to[c])
        {
            v->to[c] = new node();
        }
        v = v->to[c];
    }
    v->term = true;
};
bool find(string& s) {
    node* v = root;
    for (char c : s)
    {
        c -= 'a';
        if (!v->to[c])
        {
            return false;
        }
        v = v->to[c];
    }
    return v->term;
};
void erase(string& s) {
    node* v = root;
    for (char c : s)
        v = v->to[c - 'a'];
    v->term = false;
};
