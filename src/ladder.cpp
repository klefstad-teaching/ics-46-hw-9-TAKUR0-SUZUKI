#include "ladder.h"
void error(string word1, string word2, string msg){
	cout << "ERROR: " << word1 << " " << word2 << " " << msg << endl;
}

bool edit_distance_within(const std::string& str1, const std::string& str2, int d){
	set<string> wl;
	load_words(wl, "src/words.txt");
	return generate_word_ladder(str1, str2, wl).size() <= d;
}
bool is_adjacent(const string& word1, const string& word2){
	int size1 = word1.size(); 
	int size2 = word2.size(); 
	if(abs(size1 - size2) > 1)
		return false;
	int diff = 0;
	if(size1 == size2){
		int iters = min(size1, size2);
		for(int i = 0; i < iters; ++i){
			if(word1[i] != word2[i])
				++diff;
			if(diff == 2)
				return false;	
		}
		return diff <= 1;
	}
	else{
		int iters = max(size1, size2);
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
			diff = false;
			string smaller = smaller_base;
			smaller.insert(i, 1, bigger[i]);
			for(int j = 0; j < iters; ++j){
				if(smaller[j] != bigger[j]){
					diff = true;
					break;
				}
			}
			if(!diff){
				return true;
			}
				
		}
		return false;
	}

}

vector<string> generate_word_ladder(const string& begin_word, const string& end_word, const set<string>& word_list){
	queue<vector<string>> ladder_queue;
	ladder_queue.push(vector<string>{begin_word});
	set<string> visited; 
	visited.insert(begin_word);
	vector<string> ladder, new_ladder; 
	string last_word;
	while(!ladder_queue.empty()){
		//cout << "Ladder queue size = " << ladder_queue.size();
		ladder = ladder_queue.front();
		ladder_queue.pop();
		last_word = ladder[ladder.size() - 1];
		for(auto word : word_list){
			if(is_adjacent(last_word, word)){
				if(visited.count(word) == 0){
					visited.insert(word);
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
	ifstream ifs(file_name);
	for(string word; ifs >> word;){
		word_list.insert(word);
	}
}
void print_word_ladder(const vector<string>& ladder){
	if(ladder.size() == 0)
		cout << "No word ladder found." << endl;
	for(auto s : ladder)
		cout << s << ' ';
	cout << endl;
}

#define my_assert(e) {cout << #e << ((e) ? " passed": " failed") << endl;}

void verify_word_ladder() {

    set<string> word_list;

    load_words(word_list, "src/words.txt");

	for(auto s : generate_word_ladder("cat", "dog", word_list))
		cout << s << ' ';
	
	cout << "Moving to assertions" << endl;
    my_assert(generate_word_ladder("cat", "dog", word_list).size() == 4);

    my_assert(generate_word_ladder("marty", "curls", word_list).size() == 6);

    my_assert(generate_word_ladder("code", "data", word_list).size() == 6);

    my_assert(generate_word_ladder("work", "play", word_list).size() == 6);

    my_assert(generate_word_ladder("sleep", "awake", word_list).size() == 8);

    my_assert(generate_word_ladder("car", "cheat", word_list).size() == 4);

}
