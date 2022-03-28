/*
	YOUR NAME AND COMMENT AND STUFF GO HERE.  PLEASE DELETE THIS LINE.
*/


/*
I can't wait. Wait, can't I?
You can cage a swallow, can’t you, but you can’t swallow a cage, can you?
We will rock you, you rock will we
It saves some time, but time some some saves it.
How goes it? It goes how.
Pay me $37! $37 me pay.
Run dash run.
Palindrome

"Fall leaves after leaves fall"
"First Ladies rule the State and state the rule: ladies first"
"Girl, bathing on Bikini, eyeing boy, sees boy eyeing bikini on bathing girl".
"Level, madam, level!

Oh man, my eyes! Your watch! What is it? Rolex? Yes, Rolex it is. What? Watch your eyes, my man. Oh.

Oh man, my eyes! Your watch! What is it? Rolex?
Rolex it is.
What?
Watch your eyes, my man.
Oh.
*/

#include <iostream>
#include <string> //technically don't need string since included with iostream, but in case we want to change this in the future, better to have this
#include "our_deque.h" //provides our_deque class which will be used to 

using namespace std;

int main()
{
    our_deque pal;

    string line, word = "";
    bool is_pal = true; //assumed a word-by-word plaindrome until proven not
	
	cout << "Enter a line of text and I will tell you if it is a word-by-word palindrome: ";

	getline(cin, line);
	
	for(int i = 0; i < line.length(); i++)
	{
		// cout << "i = " << i << endl;
		// cout << "line[i] = " << line[i] << endl;
		if(isspace(line[i]))
		{
			pal.push(word);
		//	cout << word <<" pushed."<<endl;
			word = "";
		}
		else if(isalnum(line[i])  || line[i] == '\'')
			word += tolower(line[i]);
	}

	if (word != "")
		pal.push(word);
//	pal.push(word);
	//cout << word <<" pushed."<<endl;

	while(!pal.single() && !pal.empty())
	{
		//cout << count << endl;
		if(pal.front() != pal.back())
		{
			is_pal = false;
			break;
		}
		else
		{
			pal.pop_front();
			pal.pop_back();
		}
	}
	
	if(is_pal)
		cout << "That is a word-by-word palindrome!" << endl;
	else
		cout << "Not a word-by-word palindrome!" << endl;

 
    return 0;
}