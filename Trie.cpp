    struct Node{
        Node* links[26];
        bool f = false;
        bool containsKey(char ch){
            return links[ch-'a']!=NULL;
        }
        void put(char ch,Node* newNode){
            links[ch-'a'] = newNode;
        }
        Node* get(char ch){
            return links[ch-'a'];
        }
        void setEnd(){
            f = true;
            return;
        }
        bool isEnd(){
            return f;
        }
    };
    class Trie{
        private: Node* root;
        public:
        Trie(){
            root = new Node();
        }
        void insert(string word){
            Node* node = root;
            for(int i=0;i<word.size();i++){
                if(!node->containsKey(word[i])){
                    node->put(word[i],new Node());
                }
                node = node->get(word[i]);
            }
            node->setEnd();
        }
        bool search(string word){
            Node* node = root;
            for(int i=0;i<word.size();i++){
                if(node->containsKey(word[i])){
                    node = node->get(word[i]);
                }
                else return false;
            }
            return node->isEnd();
        }
    };
