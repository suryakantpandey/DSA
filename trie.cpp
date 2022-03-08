struct node
{
    node* adj[26];
    bool end;
};

node* create_node()
{
    node* tmp = new node();
    tmp->end = 0;
    for(int i =0 ; i<26 ; i++)
    {
       tmp->adj[i] = NULL;
    }
    return tmp;
}
node* root = create_node();

void insert(string &s)
{
   node* cur = root;
   for(char &c: s){
      int x = c - 'a';
      if(cur->adj[x] == NULL){
         cur->adj[x] = create_node();
      }
      cur = cur->adj[x];
   }
   cur->end = 1;
}

bool find(string &s)
{
    node*cur = root;
    for(char &c:s)
    {
      int x = c - 'a';
      if(cur->adj[x] == NULL){
         return 0;
      }
      cur = cur->adj[x];

    }
    return (cur->end);
}

void erase(string &s)
{
     node* cur = root;
     for(char &c:s)
    {
      int x = c - 'a';
      if(cur->adj[x] == NULL){
         return;
      }
      cur = cur->adj[x];
    }
    cur->end = 0;
}
