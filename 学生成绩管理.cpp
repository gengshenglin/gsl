#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*定义学生结构体*/


struct Student
{
char ID[20];
char Name[20];
float Mark1;
float Mark2;
float Mark3;
float Mark4;
float Mark5;
float Average;
};




/*声明学生数组及学生数量*/
struct Student students[1000];
int num=0;



/*求平均值*/
float Avg(struct Student stu)
{
return (stu.Mark1+stu.Mark2+stu.Mark3+stu.Mark4+stu.Mark5)/5;
}



/*通过学号返回数组下标*/

int Student_SearchByIndex(char id[])
{
int i;
for (i=0;i<num;i++)
{
if (strcmp(students[i].ID,id)==0){
 return i;
}
}
return -1;


}


/*通过姓名返回数组下标*/


int Student_SearchByName(char name[])
{
int i;
for (i=0;i<num;i++)
{
if (strcmp(students[i].Name,name)==0)
{
return i;}
}
return -1;


}






/*通过ID返回数组下标*/


int Student_SearchByID(char ID[])


{


int i;


for (i=0;i<num;i++)


{


if (strcmp(students[i].ID,ID)==0)


{
return i;
}
}
return -1;
}


/*显示单条学生记录*/


void Student_DisplaySingle(int index)


{


printf("%10s%10s%8s%8s%8s%8s%8s%8s\n","学号","姓名","高数","c语言","物理"," 数字逻辑","英语"," 平均成绩");


printf("-------------------------------------------------------------\n");

printf("%10s%10s%8.2f%8.2f%8.2f%8.2f%8.2f%10.2f\n",students[index].ID,students[index].Name,


students[index].Mark1,students[index].Mark2,students[index].Mark3,students[index].Mark4,students[index].Mark5,students[index].Average);


}



/*插入学生信息*/


void Student_Insert()


{


while(1)
{
printf("请输入学号:");
scanf("%s",&students[num].ID);
getchar();
printf("请输入姓名:");
scanf("%s",&students[num].Name);
getchar();
printf("请输入高数成绩:");
scanf("%f",&students[num].Mark1);
getchar();
printf("请输入c语言成绩:");
scanf("%f",&students[num].Mark2);
getchar();
printf("请输入物理成绩:");
scanf("%f",&students[num].Mark3);
getchar();
printf("请输入数字逻辑成绩:");
scanf("%f",&students[num].Mark4);
getchar();
printf("请输入英语成绩:");
scanf("%f",&students[num].Mark5);
getchar();
students[num].Average=Avg(students[num]);
num++;
printf("插入完成!\n");
printf("是否继续?(y/n):");
if (getchar()=='n')
{
break;
}
}

}





/*修改学生信息*/


void Student_Modify()


{


//float mark1,mark2,mark3;


while(1)
{
char id[20];
int index;
printf("请输入要修改的学生的学号:");
scanf("%s",&id);
getchar();
index=Student_SearchByIndex(id);
if (index==-1)
{
printf("学生不存在!\n");
}
else
{
printf("你要修改的学生信息为:\n");
Student_DisplaySingle(index);
printf("-- 请输入新值--\n");
printf("请输入学号:");
scanf("%s",&students[index].ID);
getchar();
printf("请输入姓名:");
scanf("%s",&students[index].Name);
getchar();
printf("请输入成绩:");
scanf("%f",&students[index].Mark1);
getchar();
printf("请输入成绩:");
scanf("%f",&students[index].Mark2);
getchar();
printf("请输入成绩:");
scanf("%f",&students[index].Mark3);
getchar();
printf("请输入成绩:");
scanf("%f",&students[index].Mark3);
getchar();
printf("请输入成绩:");
scanf("%f",&students[index].Mark3);
getchar();
students[index].Average=Avg(students[index]);
printf("修改完成!\n");
}
printf("是否继续?(y/n):");
if (getchar()=='n')
{
break;
}
}


}





/*删除学生信息*/


void Student_Delete()
{
int i;
while(1)
{
char id[20];
int index;
printf("请输入要删除的学生的学号:");
scanf("%s",&id);
getchar();
index=Student_SearchByIndex(id);
if (index==-1)
{
printf("学生不存在!\n");
}
else
{
printf("你要删除的学生信息为:\n");
Student_DisplaySingle(index);
printf("是否真的要删除?(y/n):");
if (getchar()=='y')
{
for (i=index;i<num-1;i++)
{
students[i]=students[i+1];//把后边的对象都向前移动
}
num--;
printf("删除成功!\n");
}
getchar();
}
printf("是否继续?(y/n):");
if(getchar()=='n')
{
break;
}
}

}

/*按学号查询*/


void ID_Select()
{
while(1)
{
char ID[20];
int index;
printf("请输入要查询的学生的学号:");
scanf("%s",&ID);
getchar();
index=Student_SearchByID(ID);
if (index==-1)
{
printf("学生不存在!\n");
}
{
printf("你要查询的学生信息为:\n");
Student_DisplaySingle(index);
printf("查询完成!\n");
}
printf("是否继续?(y/n):");
if (getchar()=='n')
{
break;
}
}
}


/*按姓名查询*/


void Name_Select()


{
while(1)
{
char name[20];
int index;
printf("请输入要查询的学生的姓名:");
scanf("%s",&name);
getchar();
index=Student_SearchByName(name);
if (index==-1)
{
printf("学生不存在!\n");
}
else
{
 printf("你要查询的学生信息为:\n");
Student_DisplaySingle(index);
printf("查询完成!\n");
}
printf("是否继续?(y/n):");
if (getchar()=='n')
{
break;
}
}


}


/*按平均值排序*/


void Student_SortByAverage()


{
int i,j;
struct Student tmp;
for (i=0;i<num;i++)
{
for (j=1;j<num-i;j++)
{
if (students[j-1].Average<students[j].Average)
{
tmp=students[j-1];
students[j-1]=students[j];
students[j]=tmp;
}
}
}


}

/*显示学生信息*/
void Student_Display()
{
int i;
printf("%10s%10s%8s%8s%8s%8s%8s%8s\n","学号","姓名"," 高数成绩"," c语言成绩"," 物理成绩"," 数字逻辑成绩"," 英语成绩"," 平均成绩");
printf("-------------------------------------------------------------\n");

for (i=0;i<num;i++)
{
printf("%10s%10s%8.2f%8.2f%8.2f%8.2f%8.2f%10.2f\n",students[i].ID,students[i].Name,
students[i].Mark1,students[i].Mark2,students[i].Mark3,students[i].Mark4,students[i].Mark5,students[i].Average);
}
}






/*主程序*/


int main()
{
int choice;
while(1)
{
/*主菜单*/
printf("\n------ 学生成绩管理系统------\n");
printf("1. 增加学生记录\n");
printf("2. 修改学生记录\n");
printf("3. 删除学生记录\n");
printf("4. 按学号查询学生记录\n");
printf("5. 按姓名查询学生记录\n");
printf("6. 按平均成绩排序\n");
printf("7. 退出\n");
printf("请选择(1-7):");
scanf("%d",&choice);
getchar();
switch(choice)
{
case 1:
   Student_Insert();
break;
case 2:
   Student_Modify();
break;
case 3:
   Student_Delete();
    break;
case 4:
    ID_Select();
     break;
case 5:
     Name_Select();
     break;
case 6:
     Student_SortByAverage();
      Student_Display();
      break;
case 7:
  exit(0);
  break;
}
}
return 0;
}