// Example program
#include <iostream>
#include <vector>

using namespace std;

// 項的節點 
struct Node {
	//係數 
    int c;
    // 指數 
    int e;
    //下一個項的位址 
    Node* next;
};

class Poly {
public:
    Poly() {}
    
    Poly(const Poly& p) {
        (*this) += p;
    }
    
    virtual ~Poly() {
        reset();    
    }
    
    // 加上一個多項式 
    Poly operator+(const Poly& p) {
        Poly ret = *this;
        ret += p;
        return ret;
    }
    
    // 加上一個多項式 
    Poly& operator+=(const Poly& p) {
        Node* cur = p.root;
        // 分別加上P的每一項 
        while (cur != NULL) {
            (*this) += (*cur);
            cur = cur->next;
        }
        return *this;
    }
    
     // 加上一個項 
    Poly& operator+=(const Node& n) {
        if (root == NULL || (root != NULL && root->e < n.e)) {
        	// 當目前的多項式為空或對方項次比較高時，用對方的項作為第一項 
            root = new Node({0, n.e, root});
        }
        
        // 此處利用兩個node去找項的位置 
        Node* prev_match = NULL;
        Node* match = root;
        while (match != NULL && match->e > n.e) {
            prev_match = match;
            match = match->next;
        }
        
        if (match == NULL) {
            if (prev_match == NULL) {
                root = new Node({n.c, n.e, NULL});
            } else { // prev_match->e > n.e && prev_match->next == NULL 代表要加到最後一項 
                prev_match->next = new Node({n.c, n.e, NULL});
            }
        } else {
            if (match->e == n.e) {
                match->c += n.c;
                
                // 處理加完後係數和為0的情況 
                if (match->c == 0) {
                    if (prev_match == NULL) { // imply match == root
                        root = root->next;
                    } else {
                        prev_match->next = match->next;   
                    }
                    delete match;
                }
            } else { // prev_match->e > n.e && match->e < n.e
                prev_match->next = new Node({n.c, n.e, match});
            }
        }
        
        return *this;
    }
    
    // 乘上多項式 
    Poly operator*(const Poly& p) {
        if (root == NULL || p.root == NULL) {
            return Poly();
        }
        
        Poly ret;
        Node* cur = p.root;
        // 依序乘上p的項 
        while (cur != NULL) {
            ret += (*this * *cur);
            cur = cur->next;
        }
        
        return ret;
    }
    
    // 乘上一個項 
    Poly operator*(const Node& n) {
        Poly ret = *this;
        ret *= n;
        return ret;
    }
    
    // 乘上一個項
    Poly& operator*=(const Node& n) {        
        Node* cur = root;
        while (cur != NULL) {
            cur->c *= n.c;
            cur->e += n.e;
            cur = cur->next;
        }
        return *this;
    }
    
    // 清除多項式 
    void reset() {
        Node* cur = root;
        Node* t;
        while (cur != NULL) {
            t = cur->next;
            delete cur;
            cur = t;
        }
        root = NULL;
    }
    
    void print() {
        if (root == NULL) {
            cout << "0 0" << endl;
        }
        
        Node* cur = root;
        while (cur != NULL) {
            cout << cur->c << " " << cur->e << endl;
            cur = cur->next;
        }
    }
    
    // 印出格式 
    void formula() {
        if (root == NULL) {
            cout << 0 << endl;
        }
        
        // 印出格式為 x^2 + 2x + 1 
        Node* cur = root;
        while (cur != NULL) {
            cout << cur->c;
            
            if (cur->e != 0) {
            	cout << "x^" << cur->e;
            }
            
            if (cur->next == NULL) {
                cout << endl;
            } else {
                cout << " + ";
            }
            
            cur = cur->next;
        }
    }
    
private:
	// 第一個node 
    Node* root = NULL;
};

void solve( Poly& A,  Poly& B) {
    
    // 測試用格式 
    /*cout << "A: ";
    A.formula();
    
    cout << "B: ";
    B.formula();
 
	Poly C = A + B;
	cout << "A + B: ";
    C.formula();
 
    Poly D = A * B;
	cout << "A * B: ";
    D.formula(); */
    
	Poly C = A + B;
	cout << "ADD" << endl;
    C.print();
 
    Poly D = A * B;
	cout << "MULTIPLY" << endl;
    D.print();
    
}

int main()
{
	int P, Q, c, e;
	Poly polyA;
	Poly polyB;
	int count = 1;
	
	while(true){
		cin >> P;
		if(P>0){
			polyA = Poly();
			for(int i =0;i<P;i++){
				cin >> c >> e ;
				Node n  = {c, e, NULL};
				polyA += n; 
			}
		}
		
		cin >> Q;
		if(Q>0){
			polyB = Poly();
			for(int i =0;i<Q;i++){
				cin >> c >> e ;
				Node n  = {c, e, NULL};
				polyB += n; 
			}
		}
		
		if(P==0 && Q ==0){
			break;
		}else{
			cout << "Case" << count++ << ":"<<endl;
			solve(polyA ,polyB);
		}
	}
	cout << 0 << endl;
	cout << 0 << endl;
	return 0;

	
	
	
	
}

