#include <iostream>
#include <string>
#define SET_SIZE 256
using namespace std;
 
 
class TSet {
public: 
	string setName; //集合的名稱 
	char s[SET_SIZE] = {}; //集合 
	
public:
	//constructor
	TSet(string name) {
		setName = name;
	}
	
	//add string to set
	void setStr(string setStr) {
		TSet tset(setName);
		for(int i=0;i<setStr.length();i++){
			char c = setStr[i]; //字串中的字元 
			this->s[c] = 1; //將字元對應的陣列位置設成1 
		} 
	}
 
 	// 聯集 + 取or(|) 
	TSet operator+(const TSet& other) {
		TSet tset(setName +"+"+other.setName);
		for (int i=0; i<SET_SIZE; i++) {
			tset.s[i] = s[i] | other.s[i];
		}
		return tset;
	}
	
	// 交集 * 取and(&) 
	TSet operator*(const TSet& other) {
		TSet tset(setName +"*"+other.setName);
		for (int i=0; i<SET_SIZE; i++) {
			tset.s[i] = s[i] & other.s[i];
		}
		return tset;
	}
	
	// 差集 - 取and not(& !) 
	TSet operator-(const TSet& other) {
		TSet tset(setName +"-"+other.setName);
		for (int i=0; i<SET_SIZE; i++) {
			tset.s[i] = s[i] & !other.s[i];
		}
		return tset;
	}
	
	// 包含 >= (a*b==a)
	string operator>=(const TSet& other) {
		int result;
		bool flag=true;
		for (int i=0; i<SET_SIZE; i++) {
			result = s[i] & other.s[i];
			if(result!=other.s[i]){
				flag = false;
				break;
			}
		}
		if(flag){
			return setName + " contains " + other.setName;
		}else{
			return setName + " dose not contain " + other.setName; 
		}
	}

	// 屬於 in [a]是否包含於b([a]>=b) 
	string in(const char inputChar) {
	    string str(1,inputChar); //將char轉為字串用以輸出 
	    if(s[(int)inputChar]){ //檢查s在這個位置是否為1 
            return "\'"+str+"\' is in "+setName;
	    }
        return "\'"+str+"\' is not in "+setName;
	}
	
	// 覆寫輸入流 
	friend istream& operator>>(istream& in,TSet& set){
	    string cinstr;
	    getline(in,cinstr);
	    int i;
	    for(i=0;i<cinstr.length();i++){
            set.s[(int)cinstr[i]]=1;
	    }
		return in;
	}
 
 	// 覆寫輸出流
	friend ostream& operator<<(ostream& out, TSet set) {
		out << set.setName << ": " << '{';
		for (int i=0; i<SET_SIZE; i++) {
			if (set.s[i] == 1) out << (char) i;
		}
		out << '}';
		return out;
	}
 

};
 
int main() {
	int N = 0;
	
	cin >> N;
	for(int i=0; i<N; i++){
		char x;
		TSet A("A"), B("B");
		
		cin.ignore();
		cin >> A >> B;
		cin.get(x);
		
		TSet C = A+B;
		TSet D = A*B;
		
		cout << "Test Case " << (i+1) << ":" << endl;
		cout << A << endl;
		cout << B << endl;
		cout << C << endl;
		cout << D << endl;

		cout << (A-B) << endl;
		cout << (B-A) << endl;
		cout << (A>=B) << endl;
		cout << (B>=A) << endl;
		cout << A.in(x) << endl;
		cout << B.in(x) << endl;
		
		cout << endl;
		
	}

	return 0;
}
