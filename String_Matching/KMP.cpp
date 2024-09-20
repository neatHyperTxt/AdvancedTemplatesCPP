class KMP{

public:
	vector<ll> lis;
	string txt,pattern;

	KMP(string txt,string pattern){
		this->txt = txt;
		this->pattern = pattern;
		ll n = txt.size(),m = pattern.size();
		lis.resize(m);
		build_lis();
	}
	void build_lis(){
		ll len = 0;
		ll m = pattern.size();
		lis[0] = 0;
		for(ll i=1;i<m;i++){
		    while(len>0 && pattern[len]!=pattern[i]){
				len = lis[len-1];
			}
			if(pattern[i]==pattern[len])len++;
			lis[i] = len;
		}
	}
	vector<int> pattern_match_indexes(){
		ll len = 0;
		vector<int>x;
		for(ll i=0;i<txt.size();i++){
			while(len>0 && txt[i]!=pattern[len]){
				len = lis[len-1];
			}
			if(txt[i]==pattern[len]){
				len++;
				if(len==pattern.size()){
					x.push_back(i-len+1); // zero based indexing 
					len = lis[len-1];
				}
			}
		}
		return x;
	}
};
