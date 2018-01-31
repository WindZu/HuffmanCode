#include "stdafx.h"
#include "HuffmanTree.h"

//�����������
HuffmanTree::HuffmanTree()
{
}

void HuffmanTree::HuffmanTreeBuild()
{
	this->GetFrequency();
	for (int i = 0; i < CharCount; i++)//������Ҫ���ַ���Ҷ�ӽ���ʼ��
	{
		this->charset.insert(i, huff[i].c);//���ն�ȡ���ַ����Ⱥ�˳��洢�ַ�
		this->huftree.insert(TriElement(huff[i].count, -1, -1, -1));//��ʼ��Ҷ�ӽڵ㣬n����Ȩֵ����ĸ������  Ȩֵ����Ӧ���ַ���charset�д洢
	}

	//���ϳ�ʼ��Ҷ�ӽ������


	for (int i = 0; i < CharCount - 1; i++)//����n-1�����Ƚ�㣬ÿ��ѭ��������Ƚڵ�
	{
		int min1 = 100000, min2 = min1, x1 = 0, x2 = 0;//Ȩֵ��С�ʹ���С�Ľ���Լ����ǵ��±�
		for (int j = 0; j < CharCount+i ; j++)//���������޸�ĸ����СȨֵ���
		{
			if (huftree.element[j].parent == -1 && huftree.element[j].data < min1)
			{
				min2 = min1;
				x2 = x1;
				min1 = huftree.element[j].data;//min1��¼��СȨֵ
				x1 = j;//x1��¼��СȨֵ����±�
			}
			else if (huftree.element[j].parent == -1 && huftree.element[j].data <= min2)
			{
				min2 = huftree.element[j].data;//min2��¼��СȨֵ
				x2 = j;//x2��¼��СȨֵ����±�
			}		
		}
		//cout << min1 << " ";
		//cout<< CharCount + i<<" "<<x1<<" "<<x2<<" ";
		huftree[x1].parent = CharCount + i;
		huftree[x2].parent = CharCount + i;
		huftree.insert(TriElement(huftree.element[x1].data + huftree.element[x2].data, -1, x1, x2));

	}


	//��������������
	//for(int i=0;i<2*CharCount-1;i++)
	//	cout << huftree.element[i]<< " ";
	//cout<<"AAAA"<<huftree.element[CharCount].left<<endl;//������û����
	//cout << "Huffman���Ľ��˳���:" << this->huftree;
}

//����charset[i]�ַ��ı����ַ���
MyString HuffmanTree::encode(int i)
{
	MyString str;//��MyString�ַ�������Huffman����
	int child = i;
	int parent = huftree.element[i].parent;
	//cout << huftree[i] << " ";
	while (parent != -1)//��Ҷ������ϣ�ֱ�������ѭ��
	{
		//cout << huftree[i] << " ";
		str += (huftree.element[parent].left == child ) ? '0' : '1';
		child = parent;
		parent = huftree.element[child].parent;
	}

	//cout<<str.count()<<" ";
	//cout << huftree[child] << " ";
	//�����λ����������



	str.reverse();//��str����ת���õ������ַ���

	return str;
	//for (int m = 0; m < 4; m++)
	//	cout << str.element[m];
	//cout << endl;

	//for (int m = 0; m < 2; m++)
	//	cout << str.element[m];
	//cout << " ";
	//��������
	//cout << str1.n << " ";
	//��ת�������Ȼ����

	//return str;

	//���غ�ʹ���
}

//��text�е������ַ���ѹ�����õ������ַ���������
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
		//cout << j << " ";�ļ��ַ������ж�����
		//cout << charset.element[j] << " ";
		//cout << this->encode(j).element[1]<< " ";
		//MyString str;
		//encode(j);
		//codestr = str1;
		//cout << str.n << " ";
		codestr += encode(j);//��ñ���
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
	output.write((char*)&CharCount, sizeof(CharCount));//�ַ��������
	output.write((char*)&charset, sizeof(charset));//����Щ�ַ�
	output.write((char*)&huftree, sizeof(huftree));//Huffman��,���˳���
	output.write((char*)&codestr.element, sizeof(codestr.element));//�ַ�����


	output.close();
	return codestr;

}

//�����봮str��ѹ���õ������ַ�����Ȼ�󷵻�
void HuffmanTree::decode()
{
	ifstream input("222.txt", ios::binary);//��ȡ�������ļ�
	if (!input)
	{
		cerr << "open error" << endl;
	}

	input.read((char*)&charcount,sizeof(charcount));//��ͬ�ַ�������
	//cout << charcount << endl;
	input.read((char*)&cc, sizeof(cc));//����Щ�ַ�
	//cout << cc.element << endl;
	input.read((char*)&hh, sizeof(hh));//Huffman��,���˳���
	//cout << hh.element[1].data << " " << hh.element[2].data << endl;
	input.read((char*)&str.element, sizeof(str.element));//�ַ�����
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
	int node = hh.count() - 1;//node����һ���Ӹ�����Ҷ�ӵ�·��
	int i = str.count();
	for (int i = 0; i < str.count(); i++)
	{
		if (str.element[i] == '0')
			node = huftree[node].left;
		else
			node = huftree[node].right;

		if (huftree[node].isLeaf())//�ж��Ƿ񵽴�Ҷ�ӽڵ�
		{
			cout << this->charset[node];

			output<< this->charset[node];

			//text += this->charset[node];//��ö�Ӧ�ַ�
			node = this->huftree.count() - 1;//node�ٴӸ��ڵ㿪ʼ
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
		int j = judge(temp);//�Ѿ����ڵķ�������������λ�ã����򷵻�-1
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
	cout <<"�ı��ļ����ַ�����Ϊ��"<< totalcount << endl;
	cout << "�ı��ļ��в�ͬ���ַ��У�" << CharCount << endl;
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