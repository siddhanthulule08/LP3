#include<iostream>
#include<queue>
using namespace std;

struct MinHeapNode
{
	char data;
	int freq;
	MinHeapNode * left, *right;
	MinHeapNode(char data, int freq)
	{
		left=right=nullptr;
		this->data = data;
		this->freq = freq;
	}
};

struct compare
{
	bool operator()(MinHeapNode* a, MinHeapNode* b)
	{
		return (a->freq > b->freq);
	}
};

class huffmancoding
{
	public:
		void HuffmanCode(char data[], int freq[], int size);
		void printCodes(struct MinHeapNode* root, string str);

};

void huffmancoding:: HuffmanCode(char data[], int freq[], int size)
{
	struct 	MinHeapNode *left, *right, *temp;
	
	priority_queue<MinHeapNode*, vector<MinHeapNode*>, compare> minHeap;
	
	for(int i = 0; i < size; i++)
	{
		minHeap.push(new MinHeapNode(data[i], freq[i]));
	}
	
	while(minHeap.size() != 1)
	{
		left = minHeap.top();
		minHeap.pop();
		right = minHeap.top();
		minHeap.pop();
		temp = new MinHeapNode('$', left->freq + right->freq);
		temp->left = left;
		temp->right = right;
		minHeap.push(temp);
	}
	printCodes(minHeap.top(), "");
}

void huffmancoding::printCodes(struct MinHeapNode* root, string str)
{
	if(root == nullptr)
	{
		return;
	}
	if(root->data != '$')
	{
		cout << root->data << ": " << str << endl;
	}
	printCodes(root->left, str + "0");
	printCodes(root->right, str + "1");
}

int main()
{
	huffmancoding h1;
	char data[] = {'A', 'B', 'C', 'D','E','F'};
	int freq[] = {5,9,12,13,16,45};
	h1.HuffmanCode(data, freq, 6);
	return 0;
}