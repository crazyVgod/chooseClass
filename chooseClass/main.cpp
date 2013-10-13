#include<iostream>
#include<string.h>
using namespace std;
void list();
void addStudent();
void deleteStudent();
void gradesEntry();
int find(float x);
int findAgain(char name[20]);
void input(struct Student &otherStudent);
struct Student{
	char name[20];
	float studentNumber;
	int grade;
	int order;
}student[400];
int studentCount=0;	
int main(){
	int action;
	while(1){
		cout<<"~~~~~~~~~~~~~~�˵�~~~~~~~~~~~~~"<<endl;
		cout<<"1.�鿴ѧ���ɼ�"<<endl;
		cout<<"2.ѡ��"<<endl;
		cout<<"3.��ѡ"<<endl;
		cout<<"4.¼��ɼ�"<<endl;
		cout<<"5.�˳�����"<<endl;
	cin>>action;
	switch(action){
		case 1: list();
			break;
		case 2: addStudent();
			break;
		case 3: deleteStudent();
			break;
		case 4: gradesEntry();
			break;
		case 5: return 0;
		default :{
		cout<<"������������������"<<endl;return 0;
} 
}
}	
}
void list(){
	cout<<"--------�鿴ѧ���ɼ�--------"<<endl;
	cout<<"����\t"<<"ѧ��\t"<<"ѡ�α��\t"<<"�ɼ�"<<endl;
	for(int i=0;i<studentCount;i++){
		cout<<student[i].name<<"\t"<<student[i].studentNumber<<"\t"<<student[i].order<<"\t"<<student[i].grade<<endl;
}
}
void addStudent(){
	struct Student otherStudent;
	input(otherStudent);
	int i=find(otherStudent.studentNumber);
	if(i==studentCount){
		strcpy(student[i].name , otherStudent.name);
		student[i].studentNumber=otherStudent.studentNumber;
		for(int x=0;x<=7;x++){
		student[i].grade=otherStudent.grade;
		}
		studentCount++;
		student[i].order=studentCount;
}
	else{
		cout<<"ͬѧ����ѡ���γ�"<<endl;
}		
}
void deleteStudent(){
	struct Student otherStudent;
	input(otherStudent);
	int i=find(otherStudent.studentNumber);
	int j=findAgain(otherStudent.name);
	if(i==studentCount){
		cout<<"���޴���!"<<endl;
}
	if(i!=studentCount&&i==j) {
		cout<<"��ɾ��,"<<student[i].name<<"ͬѧ!"<<endl;
		for(i;i<studentCount;i++){
			student[i]=student[i+1];			
}
		studentCount--;
}
	else {
		cout<<"ѧ�ź�������ƥ��!"<<endl;
}
}
void gradesEntry(){
	int startNumber;
	int i,k;
	cout<<"�����뿪ʼ��ѡ�κ� :"<<endl;
	cin>>startNumber;
	for( int j=startNumber;j<=studentCount;j++){
	cout<<"������ɼ� :"<<endl;{
	cin>>student[startNumber-1].grade;
	if(j>=studentCount){
		cout<<"�ѵ����!"<<endl;
		break;
}
	cout<<"�Ƿ����? 1.���� 2.�˳�"<<endl;
	cin>>k;
	if(2==k)break;
	startNumber++;
}
}
}
int find(float studentNumber ){
	int i;
	for(i=-1;i<studentCount;i++){
		if(student[i].studentNumber==studentNumber)
			break;
}
	return i;
}
int findAgain(char name[20]){
	int j;
	for(j=-1;j<=studentCount;j++){
		if(strcmp(student[j].name,name)==0)
			break;
}
	return j;
}
void input(struct Student &otherStudent){
	cout<<"���������� :";
	cin>>otherStudent.name;
	cout<<"������ѧ��: ";
	cin>>otherStudent.studentNumber;
}