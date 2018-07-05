#include<bits/stdc++.h>
using namespace std;
int M=6;
string v[100];
int k=0;
struct BTreeNode
{
    string *data;
    string *number;
    BTreeNode **child_ptr;
    bool leaf;
    int n;
}*root = NULL, *np = NULL, *x = NULL;
BTreeNode * init()
{
    int i;
    np = new BTreeNode;
    np->data = new string[M-1];
    np->number = new string[M-1];
    np->child_ptr = new BTreeNode *[M];
    np->leaf = true;
    np->n = 0;
    for (i = 0; i < M; i++)
    {
        np->child_ptr[i] = NULL;
    }
    return np;
}
void displayContacts(BTreeNode *p,string str)
{
	
   int i;
   
    for (i = 0; i < p->n; i++)
    {
        if (p->leaf == false)
        {
            displayContacts(p->child_ptr[i],str);
        }
        int val=p->data[i].find(str);
		if(val>=0){
		 cout << " " << p->data[i]<<p->number[i]<<endl;
        //v[k++]=p->number[i];
		}
    } 
    if (p->leaf == false)
    {
        displayContacts(p->child_ptr[i],str);
    }

 
   
}
/*void traverse(BTreeNode *p)
{
    cout<<endl;
    int i;
    for (i = 0; i < p->n; i++)
    {
        if (p->leaf == false)
        {
            traverse(p->child_ptr[i]);
        }
        cout << " " << p->data[i];
    } 
    if (p->leaf == false)
    {
        traverse(p->child_ptr[i]);
    }
    cout<<endl;
}*/
void sort(string *p, int n,string *q)
{
    int i, j;
	string temp="";
    for (i = 0; i < n; i++)
    {
        for (j = i; j <= n; j++)
        {
         if (p[i] > p[j])
            {
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;

                temp = q[i];
                q[i] = q[j];
                q[j] = temp; 
            }
         
        }
    }
    
}
string split_child(BTreeNode *x, int i)
{
    int j;
	string mid= "";
    string mno= "";
    BTreeNode *np1, *np3, *y;
    np3 = init();
    np3->leaf = true;
    if (i == -1)
    {
        mid = x->data[2];
        mno = x->number[2];
        x->data[2] = '0';
        x->number[2] = '0';
        x->n--;
        np1 = init();
        np1->leaf = false;
        x->leaf = true;
        for (j = 3; j < 5; j++)
        {
            np3->data[j - 3] = x->data[j];
            np3->number[j - 3] = x->number[j];
            np3->child_ptr[j - 3] = x->child_ptr[j];
            np3->n++;
            x->data[j] = '0';
            x->number[j] = '0';
            x->n--;
        }
        for (j = 0; j < 6; j++)
        {
            x->child_ptr[j] = NULL;
        }
        np1->data[0] = mid;
         np1->number[0]=mno;
        np1->child_ptr[np1->n] = x;
        np1->child_ptr[np1->n + 1] = np3;
        np1->n++;
        root = np1;
    }
    else
    {
        y = x->child_ptr[i];
        mid = y->data[2];
        mno = y->number[2];
        y->data[2] = '0';
        y->number[2] = '0';
        y->n--;
        for (j = 3; j < 5; j++)
        {
            np3->data[j - 3] = y->data[j];
            np3->number[j - 3] = y->number[j];
            np3->n++;
            y->data[j] = '0';
             y->number[j] = '0';
            y->n--;
        }
        x->child_ptr[i + 1] = y;
        x->child_ptr[i + 1] = np3; 
    }
    return mid;
}
void insert(string s,string cno)
{
    int i;
	string temp="";
    x = root;
    if (x == NULL)
    {
        root = init();
        x = root;
    }
    else
    {
        if (x->leaf == true && x->n == 5)
        {
            temp = split_child(x, -1);
            x = root;
            for (i = 0; i < (x->n); i++)
            {
                if ((s > x->data[i]) && (s < x->data[i + 1]))
                {
                    i++;
                    break;
                }
                else if (s < x->data[0])
                {
                    break;
                }
                else
                {
                    continue;
                }
            }
            x = x->child_ptr[i];
        }
        else
        {
            while (x->leaf == false)
            {
            for (i = 0; i < (x->n); i++)
            {
                if ((s > x->data[i]) && (s < x->data[i + 1]))
                {
                    i++;
                    break;
                }
                else if (s < x->data[0])
                {
                    break;
                }
                else
                {
                    continue;
                }
            }
                if ((x->child_ptr[i])->n == 5)
                {
                    temp = split_child(x, i);
                    x->data[x->n] = temp;
    
                    x->n++;
                    continue;
                }
                else
                {
                    x = x->child_ptr[i];
                }
            }
        }
    }
    x->data[x->n] = s;
    x->number[x->n] = cno;
    sort(x->data, x->n,x->number);
    x->n++;
}
int main()
{
     int n=200;
   insert("souvik Mondal","5664556655");
    insert("souvik ","9874894778");
    insert("avik","11122334333");
    insert("asik das","5664556655");
    insert("ajoy","1234324");
    insert("ajay","2222222");
    insert("anil","234235432");
    insert("sanjit","2134214");
    insert("sudip ","65656776");
    insert("subra","167653471");
    insert("nil","8723542534");
    insert("nilu","7826");
    insert("dipsita","764321734815");
    insert("dipu","2343242");
     insert("binu","3245322");
    insert("vivek","12343532");
    insert("vijay","324532");
    insert("nilesh","3");
    insert("rajnee","34564645");
    insert("soura","5644e54455");
    insert("ranjit","6785754");
        insert("rani","5567876");
    insert("diptesh ","984564");
    insert("prasen","1112224234334333");
    insert("avijit","554564564");
    insert("prem","687841545");
    insert("rajat","8544545");
    insert("sibha","8154455");
        insert("akash","145345");
    insert("sayan","21874545");
    insert("binay","312453345");
    insert("sunil","2138585545");
    insert("bikram","12874745245");
    insert("bisu","817874545");
    insert("sourav","187874523411452");
        insert("subir","852774552");
    insert("sam","14455655");
    insert("milon","48547555");
    insert("debasish","1257445");
    insert("arpita","8575451");
    insert("sumita","784785421451452");
    insert("sutapa","578175414");
        insert("rinky","787486124545");
    insert("ipsita","7684512452");
    insert("dinesh","78485142142");
    insert("amir","784854145");
    insert("avi","1141011454");
    insert("vijoy","76845214545");
    insert("ranbir","48674545548");
        insert("debu","784512155");
    insert("jhon","47684514521452");
    insert("ariya","47845145");
    insert("sansa","0000006655");
    insert("rikon","768451452145222222222222");
    insert("branden","746845415145");
    insert("ned","78461451452");
        insert("khalisa","478451452");
    insert("jafry","74864515145");
    insert("imp","78451251452214");
    insert("robart","4578452124");
    insert("michal","784584475655");
    insert("kamla","487645142548");
    insert("arijit","47684353454");
        insert("amitav","4784551415");
    insert("avishek","9874894778");
    insert("yashmin","11122334333");
    insert("ranjana","5664556655");
    insert("santu","5664556655");
    insert("suman","5664556655");
    insert("jemsh","5664556655");
        insert("rudra","5664556655");
    insert("samapti","9874894778");
    insert("anjan datta","11122334333");
    insert("anik","5664556655");
    insert("ashu","5664556655");
    insert("bivas","5664556655");
    insert("chinu","5664556655");
        insert("rupin","5664556655");
    insert("arnob ","9874894778");
    insert("atree","11122334333");
    insert("aditiya","5664556655");
    insert("bishnu","5664556655");
    insert("pratik","5664556655");
    insert("rajdeep","5664556655");
        insert("nitish","5664556655");
    insert("sushil","9874894778");
    insert("amul","11122334333");
    insert("nandini","5664556655");
    insert("choclate","5664556655");
    insert("ronaldo","5664556655");
    insert("kartik","5664556655");
        insert("sourav ganguly","5664556655");
    insert("indrani","9874894778");
    insert("potato","11122334333");
    insert("chicken","5664556655");
    insert("prown","5664556655");
    insert("fish","5664556655");
    insert("rupa","5664556655");
        insert("priyanka","5664556655");
    insert("debjit","9874894778");
    insert("alok","11122334333");
    insert("mansi","5664556655");
    insert("nitu","5664556655");
    insert("piu","5664556655");
    insert("ghou","5664556655");
        insert("souvik Mon","5664556655");
    insert("souvik ds","9874894778");
    insert("avik ja","11122334333");
    insert("asik mos","5664556655");
    insert("souvik M","5664556655");
    insert("souvik al","5664556655");
    insert("souvik d","5664556655");
        insert("sou","5664556655");
    string str;
    cout<<"Enter the element to search:";
    cin>>str;
    displayContacts(root,str);

    //cout<<"travarse"; 
    //traverse(root);   
   
   /*cout<<"most closest numbers are:";
   for(int i=0;i<k;i++){
       cout<<v[i]<<endl;
   }*/
  return 0;
}
