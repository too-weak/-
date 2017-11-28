/*
* ��������ı���ӣ�ɾ�������ң�����ͳ�Ƶȹ���
* ÿ�β���ǰ���������ѡ��
*/
#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<string>
#include<list>
#include <algorithm>
using namespace std;

/* Cusor �� */
class Cursor
{
public:
    int line;
    int c;
    Cursor();   // ��ʼ������
    void set(int l, int n);     // ����Cusor����
    /* ������������Ԫ�� */
    friend ostream& operator <<(ostream& out, Cursor& a);
    friend istream& operator >>(istream& in, Cursor& a);
};
Cursor::Cursor()
{
    line = 0;
    c = 0;
}
void Cursor::set(int l, int n)
{
    line = l;
    c = n;
}
ostream& operator <<(ostream& out, Cursor& a)
{
    out<<"(line:"<<a.line<<", char:"<<a.c<<')';
    return out;
}
istream& operator >>(istream& in, Cursor& a)
{

/* TextEditor �࣬ʵ���ı��ı༭ */
    cout<<"line:";
    in>>a.line;
    cout<<"char:";
    in>>a.c;
    return in;
}
class TextEditor
{public:
    list<string> article;
    string name;
    Cursor cursor;  // ������ľۺϹ�ϵ
    int line;   //������

	list<string>::iterator Iterator;

	int total;  //������
    TextEditor();
	void mmm();
    string getname();
    void setname();
    Cursor getcursor();
    void movecursor();   //�ƶ�����L�е�C���ַ���
    void movecursor(int l, int c);
    void AddText();          //���ĵ�ĩβ����ı�
    void InsertText();    //��index���ַ�������ı�
    void DeleteText();      //ɾ����ǰ���ǰlen���ַ�
    void Findtext();        //�����ַ�������������ƶ����Ӵ���ͷ
	void Conttext();	//ͳ���ַ�
    void run();
    friend ostream& operator <<(ostream& out, TextEditor& t);
    friend istream& operator >>(istream& in, TextEditor& t);
};
//void TextEditor::mmm(){Iterator=article.iterator;}
TextEditor::TextEditor()
{
    name = "blank";
    line = 0;
    total = 0;
}
string TextEditor::getname()
{
    return name;
}
void TextEditor::setname()
{
    cout<<"�����µ��ĵ�����"<<endl;
    cin>>name;
}
Cursor TextEditor::getcursor()
{
    return cursor;
}
void TextEditor::movecursor()   //�ƶ�����L�е�C���ַ���
{
    cin>>cursor;
}
void TextEditor::movecursor(int l, int c)   //�ƶ�����L�е�C���ַ���
{
    cursor.set(l,c);
}
void TextEditor::AddText()          //���ĵ�ĩβ����ı�
{
    cout<<"add:";
    string a;
    getchar();
    getline(cin,a);
    if(a!="")           //�������ַ�����Ϊ�գ����ǻس���
    {
        if(line!=0)
        {
            *(article.rbegin())+=a;
        }
        else
        {
            article.push_back(a);
            line++;
        }
        total+=a.length();
    }
    while(a=="")        //���Իس���ͷ
    {
        getline(cin,a);
        article.push_back(a);
        line++;
        total+=a.length();
    }
    movecursor(line,article.rbegin()->length());     //�ƶ���굽���
}
void TextEditor::InsertText()    //�ڵ�ǰ��������ı�
{
    string s;
    if(cursor.line>line)      //��������������������Ĭ��Ϊ���һ��
        cursor.line = line;
    if(cursor.line<0)
        cursor.line = 1;

    list<string>::iterator i = article.begin();
    for(int j = 1; j<cursor.line; j++,i++);

    if(cursor.c>(*i).length())     //�����ַ�λ�ó���������Ĭ��Ϊ���
        cursor.c = (*i).length();
    if(cursor.c<0)
        cursor.c = 0;
    getchar();
    cout<<"insert:";
    getline(cin,s);
    if(s!="")
        (*i).insert(cursor.c,s);   //��c�����봮s
    while(s=="")    //������س�
    {
        string temp;
        temp = (*i).substr(cursor.c+1,(*i).length()-cursor.c);
        (*i) = (*i).erase(cursor.c+1, (*i).length()-cursor.c);
        i++;
        getline(cin,s);
        s+=temp;
        article.insert(i,s);
        total+=s.length();
    }
    movecursor(line,article.rbegin()->length());     //�ƶ���굽���
}
void TextEditor::DeleteText()      //ɾ����ǰ���ǰlen���ַ�
{
    if(article.empty())
        return ;

    int len, len_deleted = 0;
    cout<<"detele length:";
    cin>>len;

    list<string>::iterator i = article.begin();
    for(int j = 1; j<cursor.line; i++,j++);

    if(len<0)
        len = 0;

    if(len<=cursor.c)       //ɾ��������һ��
    {
        (*i) = (*i).erase(cursor.c - len, len);
        len_deleted = len;
    }
    else        //����ɾ��
    {
        //�ȴ���ǰ��������У�temp����ʣ���ַ���
        list<string>::iterator de = i;
        string temp = (*i).substr(cursor.c,(*i).length()-1);
        len_deleted = cursor.c;
        i--;
        article.remove(*de);
        line--;
        //ѭ����ɾ��len���ַ����ĵ���ͷ
        while(len_deleted!=len && i!=(--article.begin()))
        {
            if((*i).length() > len-len_deleted)
            {
                (*i) = (*i).erase((*i).length()-(len-len_deleted), len-len_deleted);
                len_deleted = len;
                (*i) += temp;       //�����������
            }
            else
            {
                len_deleted += (*i).length();
                de = i;
                i--;
                article.remove(*de);
                line--;
            }
        }
        //��ɾ�����ĵ���ͷ����ʣ��Ĵ�temp�����мӻ�
        if(i==(--article.begin()))
        {
            article.push_front(temp);
            line++;
        }
    }
    total -= len_deleted;
    movecursor(line,article.rbegin()->length());     //�ƶ���굽���
}
void TextEditor::Findtext()        //�����ַ�������������ƶ����Ӵ���ͷ
{
    string s;
    cout<<"input what you want to find: ";
    cin>>s;
    if(s=="" || s.length()>total)
    {
        movecursor(line,article.rbegin()->length());     //�ƶ���굽���
        return ;
    }

    list<string>::iterator i = article.begin();
    cursor.line = 1;
    while(i!=article.end())
    {
        cursor.c = (*i).find(s,0);
        if(cursor.c==string::npos)
        {
            i++;
            cursor.line++;
        }
        else
            break;
    }
    if(i==article.end())
        movecursor(line,article.rbegin()->length());
}
void TextEditor::Conttext()
{
	//cout<<article.front()[0]<<endl;
	int a1=0,a2=0,a3=0,a4=0,a5=0;//��ĸ�����֣���㣬�ո�����
	int i;
	for(i=0;i<total;++a5,++i)
	{

		if(article.front()[i]>=65&&article.front()[i]<=90||article.front()[i]>=97&&article.front()[i]<=122)
			a1++;
		else if(article.front()[i]>=48&&article.front()[i]<=57)
			a2++;
		else if(article.front()[i]==32)
			a4++;
		else
			a3++;
			//cout<<article.front()[i]<<endl;
	}
	cout<<"���ַ�����Ϊ��"<<a5<<endl;
	cout<<"��ĸ����Ϊ��"<<a1<<endl;
	cout<<"���ָ���Ϊ��"<<a2<<endl;
	cout<<"������Ϊ��"<<a3<<endl;
	cout<<"�ո����Ϊ��"<<a4<<endl;system("Pause");

}
void TextEditor::run()
{
    char chose = ' ';
    while(chose!='q')
    {
        cout<<"�ĵ�����"<<name<<endl;
        cout<<*this;
        cout<<"----------------------"<<endl;
        cout<<"��ǰ������";
        cout<<"cursor: "<<cursor<<endl;
        cout<<"line:"<<line<<endl;
        cout<<"length:"<<total<<endl;
        cout<<"���ܣ�\n";
        cout<<"1: AddText;\n2: DeleteText; \n3: FindText; \n4: InsertText;\n5: MoveCursor;\n6: SetName; \n7: Count;\n8: Quit; "<<endl;
        cout<<"����������еĲ�����"<<endl;
        cin>>chose;
        switch(chose)
        {
            case '1': AddText(); break;
            case '4': InsertText(); break;
            case '2': DeleteText(); break;
            case '3': Findtext(); break;
            case '5': movecursor(); break;
            case '6': setname(); break;
			case '7': Conttext();break;
			case '8': return;
            default :  break;
        }
        system("cls");
    }
}
ostream& operator <<(ostream& out, TextEditor& t)
{
    list<string>::iterator i = t.article.begin();
    for( ; i != t.article.end(); i++)
    {
        out<<(*i)<<endl;
    }
    return out;
}

int main()
{
    TextEditor test;
    test.run();

	system("Pause");
	return 0;
}
