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
		cout<<"~~~~~~~~~~~~~~菜单~~~~~~~~~~~~~"<<endl;
		cout<<"1.查看学生成绩"<<endl;
		cout<<"2.选课"<<endl;
		cout<<"3.退选"<<endl;
		cout<<"4.录入成绩"<<endl;
		cout<<"5.退出程序"<<endl;
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
		cout<<"输入有误，请重新输入"<<endl;return 0;
} 
}
}	
}
void list(){
	cout<<"--------查看学生成绩--------"<<endl;
	cout<<"姓名\t"<<"学号\t"<<"选课编号\t"<<"成绩"<<endl;
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
		cout<<"同学你已选过课程"<<endl;
}		
}
void deleteStudent(){
	struct Student otherStudent;
	input(otherStudent);
	int i=find(otherStudent.studentNumber);
	int j=findAgain(otherStudent.name);
	if(i==studentCount){
		cout<<"查无此人!"<<endl;
}
	if(i!=studentCount&&i==j) {
		cout<<"已删除,"<<student[i].name<<"同学!"<<endl;
		for(i;i<studentCount;i++){
			student[i]=student[i+1];			
}
		studentCount--;
}
	else {
		cout<<"学号和姓名不匹配!"<<endl;
}
}
void gradesEntry(){
	int startNumber;
	int i,k;
	cout<<"请输入开始的选课号 :"<<endl;
	cin>>startNumber;
	for( int j=startNumber;j<=studentCount;j++){
	cout<<"请输入成绩 :"<<endl;{
	cin>>student[startNumber-1].grade;
	if(j>=studentCount){
		cout<<"已到最后!"<<endl;
		break;
}
	cout<<"是否继续? 1.继续 2.退出"<<endl;
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
	cout<<"请输入姓名 :";
	cin>>otherStudent.name;
	cout<<"请输入学号: ";
	cin>>otherStudent.studentNumber;
}