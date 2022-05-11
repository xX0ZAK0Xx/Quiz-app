#include <iostream>
using  namespace std;

struct question{
    string qstn;
    string options[3];// this is to store 3 options
    int ans;
    question(string q, string o1, string o2, string o3, int a){
        qstn = q;
        options[0] = o1;
        options[1] = o2;
        options[2] = o3;
        ans = a;
    }
};

struct person{
    string name;
    int score=0;
    void setname(){
        cout<<"\nEnter your name: ";
        getline(cin,name);
    }
};


class Quiz{
private:
    static string maxPerson;
    static int maxScore;
public:
    void setMax(person a){
        if( maxScore<a.score ){
            maxScore = a.score;
            maxPerson = a.name;
        }
    }

    void getMax(){
        cout<<"\nCurrent Highest: \n";
        cout<<"Name  : "<< maxPerson<<endl;
        cout<<"Score : "<<maxScore<<endl;
    }
    
};
int Quiz::maxScore;
string Quiz::maxPerson;

ostream & operator << (ostream & COUT, question & q){
    COUT<<"\n"<< q.qstn <<endl;
    COUT<<"1. "<<q.options[0]<<endl;
    COUT<<"2. "<<q.options[1]<<endl;
    COUT<<"3. "<<q.options[2]<<endl;
    COUT<<"Enter your answer(1-3)"<<endl;
    return COUT;
}

void startTest(question set[],person p, Quiz q){
    cout<<"\nBest of luck "<<p.name<<endl;
    int arrSize = 5;
    for(int i=0 ; i<arrSize ; i++){
        int a;
        cout<<set[i];
        cin>>a;
        if(i==arrSize-1)
            cin.ignore();
        if (a==set[i].ans ){
            p.score++;
            cout<<"Correct !!\n";
        }
        else
            cout<<"Wrong   !!\n";
    }
    cout<<"Your total score "<<p.score<<endl;
    q.setMax(p);
    q.getMax();
};


int main(){
    Quiz q1;

    int prt;
    cout<<"Welcome to the game.\n";
    cout<<"Here you will be asked 5 questions based on programming.\n";
    cout<<"How many participants are there ?"<<endl;
    cin>>prt;
    cin.ignore();
    
    question set1("Which one is a programming language ?","Java","English","Bangla",1);
    question set2("Which one is an IDE ?","VS Code","Excel","MS Word",1);
    question set3("What do we need to write a program ?","Printer","Computer","Calculator",2);
    question set4("Which one is not an OOP Language ?","Java","C++","C",3);
    question set5("How do we start writing code ?","ATM project", "Hello world","Building Calculator",2);

    question fullset[5]={set1, set2, set3, set4, set5};

    person p[prt];
    for (int i = 0; i < prt; i++){
        cout<<"Press Enter to continue..."<<endl;
        cin.ignore();
        system("cls");
        p[i].setname();
        startTest(fullset,p[i],q1);

    }
    cout<<"Thank you all for participating.\n";
    cout<<"See you in a new quiz.\n";
    cout<<"Till then learn more .\n";
    system("pause>0");

    return 0;
}