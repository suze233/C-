## 大一C语言结课作业
###	函数实现
1.	void menu();//菜单<br>
包含主菜单，供用户选择
2.	void write();//写入文件<br>
保存文件到程序目录下的students.csv文件
3.	void add();//添加学生信息<br>
依次输入学生的成绩，最多添加N个学生信息
4.	void check();//查询学生信息<br>
按学号对学生信息进行查询
5.	void alter();//修改学生信息<br>
按学号查找学生信息，并进行修改，并利用switch实现一个子菜单，供用户选择修改的信息。
6.	void del();//删除学生信息<br>
按学号查找学生信息，并返回给用户，让用户确认是否真的删除，不是手滑。<br>
Y：删除该学号所处的整个结构体数组<br>
N：结束del函数
7.	void sort();//按总分成绩排序<br>
利用冒泡排序对学生总成绩有大到小排序，其中使用了stu[N]暂存学生信息
8.	void show();//显示所有学生信息<br>
将程序中所有的结构体数组全部输出
9.	void sum_aver(struct students* p);//计算总分和平均分<br>
在用户输入添加或修改学生三门课的成绩后进行计算，并存储到相应的结构体数组中
### 程序流程图
![image](http://github.com/suz233/C-StudentManagement/raw/master/流程图.png)
