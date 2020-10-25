// Example program
#include <iostream>
#include <vector>

using namespace std;

// �����`�I 
struct Node {
	//�Y�� 
    int c;
    // ���� 
    int e;
    //�U�@�Ӷ�����} 
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
    
    // �[�W�@�Ӧh���� 
    Poly operator+(const Poly& p) {
        Poly ret = *this;
        ret += p;
        return ret;
    }
    
    // �[�W�@�Ӧh���� 
    Poly& operator+=(const Poly& p) {
        Node* cur = p.root;
        // ���O�[�WP���C�@�� 
        while (cur != NULL) {
            (*this) += (*cur);
            cur = cur->next;
        }
        return *this;
    }
    
     // �[�W�@�Ӷ� 
    Poly& operator+=(const Node& n) {
        if (root == NULL || (root != NULL && root->e < n.e)) {
        	// ��ثe���h�������ũι�趵��������ɡA�ι�誺���@���Ĥ@�� 
            root = new Node({0, n.e, root});
        }
        
        // ���B�Q�Ψ��node�h�䶵����m 
        Node* prev_match = NULL;
        Node* match = root;
        while (match != NULL && match->e > n.e) {
            prev_match = match;
            match = match->next;
        }
        
        if (match == NULL) {
            if (prev_match == NULL) {
                root = new Node({n.c, n.e, NULL});
            } else { // prev_match->e > n.e && prev_match->next == NULL �N��n�[��̫�@�� 
                prev_match->next = new Node({n.c, n.e, NULL});
            }
        } else {
            if (match->e == n.e) {
                match->c += n.c;
                
                // �B�z�[����Y�ƩM��0�����p 
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
    
    // ���W�h���� 
    Poly operator*(const Poly& p) {
        if (root == NULL || p.root == NULL) {
            return Poly();
        }
        
        Poly ret;
        Node* cur = p.root;
        // �̧ǭ��Wp���� 
        while (cur != NULL) {
            ret += (*this * *cur);
            cur = cur->next;
        }
        
        return ret;
    }
    
    // ���W�@�Ӷ� 
    Poly operator*(const Node& n) {
        Poly ret = *this;
        ret *= n;
        return ret;
    }
    
    // ���W�@�Ӷ�
    Poly& operator*=(const Node& n) {        
        Node* cur = root;
        while (cur != NULL) {
            cur->c *= n.c;
            cur->e += n.e;
            cur = cur->next;
        }
        return *this;
    }
    
    // �M���h���� 
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
    
    // �L�X�榡 
    void formula() {
        if (root == NULL) {
            cout << 0 << endl;
        }
        
        // �L�X�榡�� x^2 + 2x + 1 
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
	// �Ĥ@��node 
    Node* root = NULL;
};

void solve( Poly& A,  Poly& B) {
    
    // ���եή榡 
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

