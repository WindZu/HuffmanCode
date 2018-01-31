#include "stdafx.h"
#include "HuffmanTree.h"

//构造霍夫曼树
HuffmanTree::HuffmanTree()
{
}

void HuffmanTree::HuffmanTreeBuild()
{
	this->GetFrequency();
	for (int i = 0; i < CharCount; i++)//将所需要的字符，叶子结点初始化
	{
		this->charset.insert(i, huff[i].c);//按照读取到字符的先后顺序存储字符
		this->huftree.insert(TriElement(huff[i].count, -1, -1, -1));//初始化叶子节点，n个，权值，父母，左，右  权值所对应的字符在charset中存储
	}

	//以上初始化叶子结点无误


	for (int i = 0; i < CharCount - 1; i++)//构造n-1个二度结点，每次循环构造个度节点
	{
		int min1 = 100000, min2 = min1, x1 = 0, x2 = 0;//权值最小和次最小的结点以及它们的下标
		for (int j = 0; j < CharCount+i ; j++)//查找两个无父母的最小权值结点
		{
			if (huftree.element[j].parent == -1 && huftree.element[j].data < min1)
			{
				min2 = min1;
				x2 = x1;
				min1 = huftree.element[j].data;//min1记录最小权值
				x1 = j;//x1记录最小权值结点下标
			}
			else if (huftree.element[j].parent == -1 && huftree.element[j].data <= min2)
			{
				min2 = huftree.element[j].data;//min2记录次小权值
				x2 = j;//x2记录次小权值结点下标
			}		
		}
		//cout << min1 << " ";
		//cout<< CharCount + i<<" "<<x1<<" "<<x2<<" ";
		huftree[x1].parent = CharCount + i;
		huftree[x2].parent = CharCount + i;
		huftree.insert(TriElement(huftree.element[x1].data + huftree.element[x2].data, -1, x1, x2));

	}


	//生成树测试无误
	//for(int i=0;i<2*CharCount-1;i++)
	//	cout << huftree.element[i]<< " ";
	//cout<<"AAAA"<<huftree.element[CharCount].left<<endl;//生成树没问题
	//cout << "Huffman树的结点顺序表:" << this->huftree;
}

//返回charset[i]字符的编码字符串
MyString HuffmanTree::encode(int i)
{
	MyString str;//以MyString字符串保存Huffman编码
	int child = i;
	int parent = huftree.element[i].parent;
	//cout << huftree[i] << " ";
	while (parent != -1)//由叶结点向上，直到根结点循环
	{
		//cout << huftree[i] << " ";
		str += (huftree.element[parent].left == child ) ? '0' : '1';
		child = parent;
		parent = huftree.element[child].parent;
	}

	//cout<<str.count()<<" ";
	//cout << huftree[child] << " ";
	//编码的位数测试无误



	str.reverse();//将str串逆转，得到编码字符串

	return str;
	//for (int m = 0; m < 4; m++)
	//	cout << str.element[m];
	//cout << endl;

	//for (int m = 0; m < 2; m++)
	//	cout << str.element[m];
	//cout << " ";
	//编码无误
	//cout << str1.n << " ";
	//反转后测试依然无误

	//return str;

	//返回后就错误
}

//将text中的所有字符串压缩，得到编码字符串，返回
MyString HuffmanTree::encode()
{
	ifstream input;
	input.open("111.txt");
	if (!input)
	{
		cerr << "oper error" << endl;
	}
	char temp;
	
	while (!input.eof())
	{
		input >> temp;	
		int j = judge(temp);
		//cout << j << " ";文件字符读入判断无误
		//cout << charset.element[j] << " ";
		//cout << this->encode(j).element[1]<< " ";
		//MyString str;
		//encode(j);
		//codestr = str1;
		//cout << str.n << " ";
		codestr += encode(j);//获得编码
	}


	input.close();

	//for(int i=0;i<100;i++)
	//	cout << codestr.element[i] << " ";
	//cout << endl;

	ofstream output("222.txt", ios::binary);
	if (!output)
	{
		cerr << "open error!" << endl;
	}
	output.write((char*)&CharCount, sizeof(CharCount));//字符种类个数
	output.write((char*)&charset, sizeof(charset));//是哪些字符
	output.write((char*)&huftree, sizeof(huftree));//Huffman树,结点顺序表
	output.write((char*)&codestr.element, sizeof(codestr.element));//字符编码


	output.close();
	return codestr;

}

//将编码串str解压，得到译码字符串，然后返回
void HuffmanTree::decode()
{
	ifstream input("222.txt", ios::binary);//读取二进制文件
	if (!input)
	{
		cerr << "open error" << endl;
	}

	input.read((char*)&charcount,sizeof(charcount));//不同字符的数量
	//cout << charcount << endl;
	input.read((char*)&cc, sizeof(cc));//是哪些字符
	//cout << cc.element << endl;
	input.read((char*)&hh, sizeof(hh));//Huffman树,结点顺序表
	//cout << hh.element[1].data << " " << hh.element[2].data << endl;
	input.read((char*)&str.element, sizeof(str.element));//字符编码
	for(int i = 0; i < 100;i++)
		cout << str.element[i];
	MyString str11(str);
	decode(str11);

	input.close();

}

void HuffmanTree::decode(MyString &str)
{
	ofstream output("333.txt");
	if (!output)
	{
		cerr << "open error" << endl;
	}

	//MyString text;
	int node = hh.count() - 1;//node搜索一条从根到达叶子的路径
	int i = str.count();
	for (int i = 0; i < str.count(); i++)
	{
		if (str.element[i] == '0')
			node = huftree[node].left;
		else
			node = huftree[node].right;

		if (huftree[node].isLeaf())//判断是否到达叶子节点
		{
			cout << this->charset[node];

			output<< this->charset[node];

			//text += this->charset[node];//获得对应字符
			node = this->huftree.count() - 1;//node再从根节点开始
		}
	}
	//output << text;
	output.close();
}


void HuffmanTree::GetFrequency()
{
	ifstream input;
	input.open("111.txt");
	if (!input)
	{
		cerr << "open error!" << endl;
	}

	char temp;
	while (!input.eof())
	{
		input >> temp;
		totalcount++;
		int j = judge(temp);//已经存在的返回其在数组中位置，否则返回-1
		if (j==-1)
		{
			add(temp);
			CharCount++;
		}
		else
		{
			huff[j].count++;
		}
	}
	input.close();

	huff[judge(temp)].count--;
	cout <<"文本文件中字符总数为："<< totalcount << endl;
	cout << "文本文件中不同的字符有：" << CharCount << endl;
	for (int i = 0; i < CharCount; i++)
	{
		cout << huff[i].c << " " << huff[i].count << endl;
	}
}

int HuffmanTree::judge(char c)
{
	for (int i = 0; i < 256; i++)
	{
		if (huff[i].c == c)
			return i;
	}
	return -1;
}

void HuffmanTree::add(char c)
{
	huff[CharCount].c = c;
	huff[CharCount].count = 1;
}