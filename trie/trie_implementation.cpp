#include<bits/stdc++.h>
using namespace std;

struct TrieNode {

    //pointer array for child nodes of each node
	TrieNode *childNode[26];
	int wordEndCnt;

	TrieNode()
	{
		// constructor 
		//initialize the wordCnt variable with 0
		//initialize every index of childNode array with NULL
		wordEndCnt = 0;
		for (int i = 0; i < 26; i++)
		{
			childNode[i] = NULL;
		}
	}
};

TrieNode * insert_key(TrieNode *root, string &key)
{
	//initialize the currentNode pointer with the root node
	TrieNode *currentNode = root;

	//Store the length of the key string 
	int length = key.size();

	//iterate across the length of the string
	for (int i = 0; i < length; i++)
	{

		//Check X-'a' th index is NULL or not
		if (currentNode->childNode[key[i] - 'a'] == NULL)
		{
			//If null make a new node
			TrieNode * newNode = new TrieNode();

			//Point the X-'a' th index of current node to the new node
			currentNode->childNode[key[i] - 'a'] = newNode;
		}

		//Move the current node pointer to the newly created node.

		currentNode = currentNode->childNode[key[i] - 'a'];
	}

	//Increment the wordEndCnt for the last currentNode pointer as it will point 
	//the string that is the end of the string key. 
	currentNode->wordEndCnt++;

	//return the updated root node
	return root;
}

bool search_key(TrieNode *root, string &queryString)
{
	//Initialize the currentNode pointer with the root node
	TrieNode *currentNode = root;

	//Store the length of the query string
	int length = queryString.size();

	for (int i = 0; i < length; i++)
	{
		//Check if the X-'a' th index is NULL or not
		if (currentNode->childNode[queryString[i] - 'a'] == NULL)
		{
			//If null then the query string is not present in the Trie
			//return false
			return false;
		}
		//If not NULL
		//Move the currentNode pointer to the node pointed by X-'a' th index of the
		//current node
		currentNode = currentNode->childNode[queryString[i] - 'a'];
	}

	//If currentNode pointer is not NULL
	//and wordEndCnt for the currentNode pointer 
	//is greater than 0 then return true else
	//return false

	return currentNode != NULL && currentNode->wordEndCnt > 0;

}

bool delete_key(TrieNode *root, string &queryString)
{

	//Initialize the currentNode pointer with the root node
	TrieNode *currentNode = root;

	//Store the length of the queryString
	int length = queryString.size();

	for (int i = 0; i < length; i++)
	{
		//Check if the X-'a' th index is NULL or not 
		if (currentNode->childNode[queryString[i] - 'a'] == NULL)
		{
			//If null the query string is not present in the Trie
			//return false
			return false;
		}
		//Move the currentNode pointer to the next node
		currentNode = currentNode->childNode[queryString[i] - 'a'];
	}

	//If currentNode pointer is not NULL and 
	//wordEndCnt for the currentNode is greater than 0

	if (currentNode != NULL && currentNode->wordEndCnt > 0)
	{
		//then decrement the wordEndCnt for the
		//currentNode
		currentNode->wordEndCnt--;

		//return true
		return true;
	}

	//If the wordEndCnt for the currentNode is equal to 0
	//Then that string is not present in Trie 
	//return false

	return false;
}

int main()
{
	//make a root node for the Trie
	TrieNode *root = new TrieNode();

	//stores the strings that we want to insert in the
	//Trie
	vector<string> inputStrings = {"tea", "ten", "eat", "ear", "bat", "ball"};

	//number of insert operations in the Trie
	int n = inputStrings.size();

	for (int i = 0; i < n; i++)
	{
		root = insert_key(root, inputStrings[i]);
	}

	//stores the strings that we want to search in the Trie
	vector<string>searchQueryStrings = {"tea", "to", "bal"};

	//number of search operations in the Trie
	int searchQueries = searchQueryStrings.size();

	for (int i = 0; i < searchQueries; i++)
	{
		cout << "Query String : " << searchQueryStrings[i] << "\n";
		if (search_key(root, searchQueryStrings[i]))
		{
			//the queryString is present in the Trie
			cout << "The query string is present in the Trie\n";
		}
		else
		{
			//the queryString is not present in the Trie
			cout << "The query string is not present in the Trie\n";
		}
	}

	//stores the strings that we want to delete from the Trie
	vector<string>deleteQueryStrings = {"tea", "tea"};

	//number of delete operations from the Trie
	int deleteQueries = deleteQueryStrings.size();

	for (int i = 0; i < deleteQueries; i++)
	{
		cout << "Query String : " << deleteQueryStrings[i] << "\n";
		if (delete_key(root, deleteQueryStrings[i]))
		{
			//The queryString is successfully deleted from 
			//the Trie
			cout << "The query string is successfully deleted\n";
		}
		else
		{
			//The query string is not present in the Trie
			cout << "The query string is not present in the Trie\n";
		}
	}


	return 0;
}
