#include <iostream>
using namespace std;

//��ͨ�������ں�������
class Student{
public:
    //������ı���
    char *name;
    int age;
    float score;
    //������ĺ���
    void say(){
        cout<<name<<"��������"<<age<<"���ɼ���"<<score<<endl;
    }
};

int main(){
    //��������
    Student stu;
    stu.name = "С��";
    stu.age = 15;
    stu.score = 92.5f;
    stu.say();

    system("pause");
    return 0;
}