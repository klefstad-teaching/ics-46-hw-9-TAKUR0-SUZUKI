#include "ladder.h"
void error(string word1, string word2, string msg){
	cout << "ERROR: " << word1 << " " << word2 << " " << msg << endl;
}

bool edit_distance_within(const std::string& str1, const std::string& str2, int d){
	unordered_map<string, set<string>> adjacent_words;
	for(auto s1 : word_list){
		for(auto s2 : word_list){
			if(is_adjacent(s1, s2))
				adjacent_words[s1].insert(s2);
		}
	}
	queue<string> q;
	set<string> visited;
	q.push(str1);
	int distance = 0;
	while(!q.empty()){
		string curr = q.front();
		q.pop();
		distance++;
		for(auto s : adjacent_words[curr]){
			if(vistied.count[s] == 0){
				q.push(s);
				visited.insert(s);
			}
			if(s == str2){
				q.empty();
				break;
			}
				
		}
		
	}
	return distance <= d;
}
bool is_adjacent(const string& word1, const string& word2){
	int size1 = word1.size(); 
	int size2 = word2.size(); 
	int iters = min(size1, size2);

	if(abs(size1 - size2) > 1)
		return false;

	int diff = 0;
	if(size1 == size2){
		for(int i = 0; i < iters; ++i){
			if(word1[i] != word2[i])
				++diff;
			if(diff == 2)
				return false;	
		}
		return diff == 1;
	}
	else{
		string smaller_base, bigger;
		if(size1 < size2){
			smaller_base = word1;
			bigger = word2;
		}
		else{
			smaller_base = word2;
			bigger = word1;
		}
			
		for(int i = 0; i < iters; ++i){
			diff = 0;
			string smaller = smaller_base;
			smaller.insert(i, '*');
			for(int j = 0; j < iters; ++j){
				if(smaller[j] != bigger[j])
					++diff;
				if(diff == 2)
					break;
			}
			if(diff == 1) 
				return true;
		}
		return false;
	}

}

	/*
	bool diff = size1 != size2;
	string smaller;
	int smaller_size;
	if(size1 < size2){
		smaller = word1;
		smaller_size = size1;
	}
	else{
		smaller = word2;
		smaller_size = size2;
	}
	for(int i = 0; i < size1; ++i){
		if(diff){
			smaller = smaller.substr(0,i) + '*' + smaller.substr(i, smaller_size);
		}
		else
			word1 = word1.substr(0,i)
		for(int j = 0; j < size1; ++j){

		}
	}
	*/

//}
vector<string> generate_word_ladder(const string& begin_word, const string& end_word, const set<string>& word_list){
	queue<vector<string>> ladder_queue;
	ladder_queue.push(vector<string>{begin_word});
	set<string> visited; 
	visited.insert(begin_word);
	while(!ladder_queue.empty()){
		ladder = ladder_queue.front();
		last_word = ladder[ladder.size() - 1];
		for(auto word : word_list){
			if(is_adjacent(last_word, word)){
				if(visited.count(word) == 0){
					vistied.insert(word);
					new_ladder = vector<string>(ladder.begin(), ladder.end());
					new_ladder.push_back(word);
					if(word == end_word)
						return new_ladder;
					ladder_queue.push(new_ladder);
			}
		}
		}
		
	}
	return vector<string>{};
}


void load_words(set<string> & word_list, const string& file_name){
	ifstream(file_name) ifs;
	for(string word; ifs >> word;){
		word_list.insert(word);
	}
}
void print_word_ladder(const vector<string>& ladder){
	for(auto s : ladder)
		cout << s << ' ';
}
void verify_word_ladder();
