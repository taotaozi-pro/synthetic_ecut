#include<stdio.h>
#include<stdlib.h>
#define N 100

FILE *fp;
int *q;

typedef struct sale{
	float s1;
	float s2;
	float s3;
	float s4;
}SALE;
struct staff{
	int id;
	SALE s;
	float sum;
	float prize;
}staff[N];

void menu ();         //主菜单
void menu1();         //副菜单
void initial(struct staff sta[]);               //初始化
void txt_sale(struct staff sta[],int n);        //输入 
void SUM(struct staff sta[],int n);             //统计
void txt_prize(struct staff sta[],int n);       //计算奖金 
void modify(struct staff sta[],int n);          //修改信息模块
void add(struct staff sta[],int n,int k);       //添加
int del(struct staff sta[],int n);              //删除
void mod(struct staff sta[],int n);             //修改

int main(){
	int choice,n;
	do{
		menu();
		scanf("%d",&choice);
	    switch(choice){
		case 1:{	 
			printf("\t\t\t\t请输入员工总人数：");
			scanf("%d",&n);
		    initial(staff,n);
			   }break;
	case 2:txt_sale(staff,n);break;
	case 3:SUM(staff,n);break;
	case 4:txt_prize(staff,n);break;
	case 5:modify(staff,n);break;
	case 6:printf("\t\t\t\t退出程序！");exit(0);        
	default:printf("\t\t\t\t输入有误，请重新输入！\n");
	}
		system("pause");
	    system("cls");                     //擦屏
	}while(1);
	return 0;
}

void menu(){                                //主菜单
	printf("\n\n\n\n\n");
	printf("\t\t\t\t员工销售统计及奖金发放系统\n");
	printf("\t\t\t\t ══════════════════════\n");
	printf("\t\t\t\t║                      ║\n");
	printf("\t\t\t\t║   1.信息初始化       ║\n");
	printf("\t\t\t\t║   2.输入员工销售额   ║\n");
	printf("\t\t\t\t║   3.统计信息         ║\n");
	printf("\t\t\t\t║   4.奖金发放         ║\n");
	printf("\t\t\t\t║   5.修改信息         ║\n");
	printf("\t\t\t\t║   6.退出程序         ║\n");
	printf("\t\t\t\t║                      ║\n");
	printf("\t\t\t\t ══════════════════════\n");
	printf("\t\t\t\t请输入您的选择（请先初始化系统）：\n");
	printf("\t\t\t\t单位（万元）\n\t\t\t\t");
}

void initial(struct staff sta[],int n){                //自定义初始化函数
	int i=0;
	if((fp=fopen("staff.txt","w"))==NULL)            // 文件指针fp指向输出文件
         {	  
			 printf("无法打开此文件\n"); 
             exit(0);
         }
	for(i=0;i<n;i++)
	{
		printf("\t\t\t\t请输入员工%d的工号：",i+1);        //输入工号
		scanf("%d",&sta[i].id);
	}
	for(i=0;i<n;i++)
     { 	fprintf(fp,"%d\t\n",sta[i].id);        //写入文件      
     }
	printf("\t\t\t\t初始化完毕，欢迎再次使用！\n");
	fclose(fp);
}

void txt_sale(struct staff sta[],int n){                   //自定义函数输入销售额
	int i;
	if((fp=fopen("staff.txt","w"))==NULL)          // 文件指针fp指向输出文件
         {	  
			 printf("\t\t\t\t无法打开此文件\n"); 
             exit(0);
         }
	printf("\t\t\t\t请输入员工四个季度的销售额（单位：万元）\n");
	printf("\t\t\t\t员工\t一季\t二季\t三季\t四季\n");
	for(i=0;i<n;i++)             //根据所给工号输入销售额
	{
		printf("\t\t\t\t%d：",sta[i].id);
		scanf("%f%f%f%f",&sta[i].s.s1,&sta[i].s.s2,&sta[i].s.s3,&sta[i].s.s4);
	}
	
	fprintf(fp,"工号\t第一季度\t第二季度\t第三季度\t第四季度\n",0);
	for(i=0;i<n;i++)            //写入文件
	{ 	
		fprintf(fp,"%d\t%-9.2f\t\t%-9.2f\t\t%-9.2f\t\t%-9.2f\t\n",sta[i].id,sta[i].s.s1,sta[i].s.s2,sta[i].s.s3,sta[i].s.s4);          
     }
	printf("\t\t\t\t已写入文件，欢迎再次使用！");
	fclose(fp);
}

void SUM(struct staff sta[],int n){                      //自定义统计函数
	int i,j=0,k=0,c[4];int max1;
	float max2,sum1=0;
	//统计每个人的总销售额
	for(i=0;i<n;i++)                    
	{
		sta[i].sum=sta[i].s.s1+sta[i].s.s2+sta[i].s.s3+sta[i].s.s4;
	}
	 //统计企业年度总销售额
	for(i=0;i<n;i++)                 
	{
		sum1=sum1+sta[i].sum;
	}
	printf("\t\t\t\t企业的总销售额是%.2f。\n",sum1);
	printf("\t\t\t\t员工\t一季\t二季\t三季\t四季\t总销售额\n");
	for(i=0;i<n;i++)
	{
		printf("\t\t\t\t%d\t%-.2f\t%-.2f\t%-.2f\t%-.2f\t%-.2f\n",sta[i].id,sta[i].s.s1,sta[i].s.s2,sta[i].s.s3,sta[i].s.s4,sta[i].sum);
	}
	//评选年度之星
	j=0;
	max2=sta[0].sum;
	for(i=1;i<n;i++)
	{
		if(max2<sta[i].sum)
			max2=sta[i].sum;
	}
	for(i=0;i<n;i++)
	{
		if(max2==sta[i].sum)  
		{
			j++;c[j-1]=i;
		}
	}
	printf("\t\t\t\t本年的销售之星有%d个，是员工",j);
	for(i=0;i<j;i++){ k=c[i];  printf(" %d ",staff[k].id);}
	printf("，总销售额为%.2f.\n",max2);
	
	//第一季度季度之星
	j=0;
	max2=sta[0].s.s1;
	for(i=1;i<n;i++)
	{
		if(max2<sta[i].s.s1)
			max2=sta[i].s.s1;
	}
	for(i=0;i<n;i++)
	{
		if(max2==sta[i].s.s1)  
		{
			j++;c[j-1]=i;
		}
	}
	printf("\t\t\t\t第一季度的季度之星有%d个，是员工",j);
	for(i=0;i<j;i++){ k=c[i];  printf(" %d ",staff[k].id);}
	printf("，销售额为%.2f.\n",max2);
	//第二季度季度之星
	j=0;
	max2=sta[0].s.s2;
	for(i=1;i<n;i++)
	{
		if(max2<sta[i].s.s2)
			max2=sta[i].s.s2;
	}
	for(i=0;i<n;i++)
	{
		if(max2==sta[i].s.s2)  
		{
			j++;c[j-1]=i;
		}
	}
	printf("\t\t\t\t第二季度的季度之星有%d个，是员工",j);
	for(i=0;i<j;i++){ k=c[i];  printf(" %d ",staff[k].id);}
	printf("，销售额为%.2f.\n",max2);
	//第三季度季度之星
	j=0;
	max2=sta[0].s.s3;
	for(i=1;i<n;i++)
	{
		if(max2<sta[i].s.s3)
			max2=sta[i].s.s3;
	}
	for(i=0;i<n;i++)
	{
		if(max2==sta[i].s.s3)  
		{
			j++;c[j-1]=i;
		}
	}
	printf("\t\t\t\t第三季度的季度之星有%d个，是员工",j);
	for(i=0;i<j;i++){ k=c[i];  printf(" %d ",staff[k].id);}
	printf("，销售额为%.2f.\n",max2);
	//第四季度季度之星
	j=0;
	max2=sta[0].s.s4;
	for(i=1;i<n;i++)
	{
		if(max2<sta[i].s.s4)
			max2=sta[i].s.s4;
	}
	for(i=0;i<n;i++)
	{
		if(max2==sta[i].s.s4)  
		{
			j++;c[j-1]=i;
		}
	}
	printf("\t\t\t\t第四季度的季度之星有%d个，是员工",j);
	for(i=0;i<j;i++){ k=c[i];  printf(" %d ",staff[k].id);}
	printf("，销售额为%.2f.\n",max2);
	
	if((fp=fopen("staff.txt","w"))==NULL)             // 文件指针fp指向输出文件
         {	  
			 printf("\t\t\t\t无法打开此文件\n"); 
             exit(0);
         }
	fprintf(fp,"工号\t第一季度\t第二季度\t第三季度\t第四季度\t总销售额\n",0);
	for(i=0;i<n;i++)                                   //写入文件
	{ 	
		fprintf(fp,"%d\t%-9.2f\t\t%-9.2f\t\t%-9.2f\t\t%-9.2f\t\t%-9.2f\n",sta[i].id,sta[i].s.s1,sta[i].s.s2,sta[i].s.s3,sta[i].s.s4,sta[i].sum);          
     }
	printf("\t\t\t\t已写入文件，欢迎再次使用！\n");
	fclose(fp);
}

void txt_prize(struct staff sta[],int n){                 //自定义计算奖金函数
	int i,j,sum1=0,max1,k=0,c[4];
	float r;
	for(i=0;i<n;i++)                  //统计企业年度总销售额
	{
		sum1+=sta[i].sum;
	}
	//找到对应的提成并计算奖金
	if(sum1<=100)  r=0.1;
	if(sum1>100&&sum1<=150) r=0.11;
	if(sum1>150&&sum1<=200) r=0.12;
	if(sum1>200&&sum1<=250) r=0.13;
	if(sum1>250&&sum1<=300) r=0.14;
	if(sum1>300) r=0.15;
	for(i=0;i<n;i++)
	{
		sta[i].prize=r*sta[i].sum;
	}

	//评选年度之星
	j=0;
	max1=sta[0].sum;
	for(i=1;i<n;i++)
	{
		if(max1<sta[i].sum)
			max1=sta[i].sum;
	}
	for(i=0;i<n;i++)
	{
		if(max1==sta[i].sum)  
		{
			j++;c[j-1]=i;
		}
	}
	for(i=0;i<j;i++){ k=c[i];sta[k].prize++;}         //年度之星额外奖励一万元

	printf("\t\t\t\t员工\t一\t二\t三\t四\t总销售额\t奖金\n");
	for(i=0;i<n;i++)
	{
		printf("\t\t\t\t%d\t%-.2f\t%-.2f\t%-.2f\t%-.2f\t%-.2f\t        %-.2f\n",sta[i].id,sta[i].s.s1,sta[i].s.s2,sta[i].s.s3,sta[i].s.s4,sta[i].sum,sta[i].prize);
	}
	if((fp=fopen("staff.txt","w"))==NULL)      // 文件指针fp指向输出文件
         {	  
			 printf("\t\t\t\t无法打开此文件\n"); 
             exit(0);
         }
	fprintf(fp,"工号\t第一季度\t第二季度\t第三季度\t第四季度\t销售额\t奖金提成\n",0);
	for(i=0;i<n;i++)                   //存放文件
	{ 	
		fprintf(fp,"%d\t%-9.2f\t\t%-9.2f\t\t%-9.2f\t\t%-9.2f\t\t%-9.2f\t\t%-9.2f\n",sta[i].id,sta[i].s.s1,sta[i].s.s2,sta[i].s.s3,sta[i].s.s4,sta[i].sum,sta[i].prize);          
     }
	printf("\t\t\t\t已写入文件，欢迎再次使用！\n");
	fclose(fp);
}

void menu1(){                             //副菜单
			printf("\n");
		printf("\n");
		printf("\n");
		printf("\n");
		printf("\n");
	printf("\t\t\t\t        修改信息     \n");
	printf("\t\t\t\t ══════════════════════\n");
	printf("\t\t\t\t║                      ║\n");
	printf("\t\t\t\t║                      ║\n");
	printf("\t\t\t\t║   1.添加员工信息     ║\n");
	printf("\t\t\t\t║   2.删除员工信息     ║\n");
	printf("\t\t\t\t║   3.修改员工销售额   ║\n");
	printf("\t\t\t\t║   4.返回主菜单       ║\n");
	printf("\t\t\t\t║                      ║\n");
	printf("\t\t\t\t║                      ║\n");
	printf("\t\t\t\t ══════════════════════\n");
	printf("\t\t\t\t请输入您的选择：");
}

void add(struct staff sta[],int n,int k){             //自定义添加员工信息函数
	int i;
	//printf("\t\t\t\t请输入需要添加几位员工：");
	//scanf("%d",&k);                                //输入需要添加几位员工
	for(i=n;i<n+k;i++)
	{
		printf("\t\t\t\t请输入员工%d的工号：",i+1);
		scanf("%d",&sta[i].id);                    //输入员工的工号
	}
	printf("\t\t\t\t请输入员工四个季度的销售额\n");
	printf("\t\t\t\t员工  一 二 三 四\n");
	for(i=n;i<n+k;i++)
	{
		printf("\t\t\t\t%d：",sta[i].id);
		scanf("%f %f %f %f",&sta[i].s.s1,&sta[i].s.s2,&sta[i].s.s3,&sta[i].s.s4);      //输入销售额
	}
	printf("\t\t\t\t添加信息成功！\n");
	n=n+k;                                      //更新后的员工总数
	SUM(staff,n);
	txt_prize(staff,n);
	system("pause");
}

int del(struct staff sta[],int n){                     //自定义删除员工信息函数  
	int i,j,a;

	printf("\t\t\t\t员工\t一\t二\t三\t四\t总销售额\n");
	for(i=0;i<n;i++)
	{
		printf("\t\t\t\t%d\t%-.2f\t%-.2f\t%-.2f\t%-.2f\t%-.2f\n",sta[i].id,sta[i].s.s1,sta[i].s.s2,sta[i].s.s3,sta[i].s.s4,sta[i].sum);
	}

	printf("\t\t\t\t请输入要删除的员工的工号：");
	scanf("%d",&a);
	for(i=0;i<n;i++)                           //将员工信息删除
	{
		if(a==sta[i].id) 
		{
			for(j=i;j<n-1;j++)
			{
				sta[j]=sta[j+1];
			}
			i--;
		}
	}
	printf("\t\t\t\t删除信息成功！\n");
	n--;                                         //更新后员工数量为n-1
	SUM(staff,n);
	txt_prize(staff,n);
	system("pause");
	return n;
}

void mod(struct staff sta[],int n){                   //自定义修改数据函数
	int i,a,b; 
	float k;
	SALE *p;                                         //定义SALE型指针

	printf("\t\t\t\t员工\t一\t二\t三\t四\t总销售额\n");
	for(i=0;i<n;i++)
	{
		printf("\t\t\t\t%d\t%-.2f\t%-.2f\t%-.2f\t%-.2f\t%-.2f\n",sta[i].id,sta[i].s.s1,sta[i].s.s2,sta[i].s.s3,sta[i].s.s4,sta[i].sum);
	}

	printf("\t\t\t\t请输入需要修改数据的员工工号、和第几季度的销售额：");
	scanf("%d %d",&a,&b);
	printf("\t\t\t\t将该值修改为：");
	scanf("%f",&k);
	for(i=0;i<n;i++)
	{
		if(a==sta[i].id)
		{
			p=&sta[i].s;                   //将指针指向sta[i].s
			if(b==1)  p->s1=k;
			if(b==2)  p->s2=k;
			if(b==3)  p->s3=k;
			if(b==4)  p->s4=k;
		}
	}
	printf("\t\t\t\t修改成功！\n");
	SUM(staff,n);
	txt_prize(staff,n);
	system("pause");
}

void modify(struct staff sta[],int n){                       
	int i,j,k,l;
	do{
		system("cls");                    //擦屏
		menu1();
		scanf("%d",&l);
		if(l==4)  {printf("\t\t\t\t按任意键返回主菜单!\n");break;}     //返回主菜单
		switch(l)
		{
		case 1: {
			printf("\t\t\t\t请输入需要添加几位员工：");
	        scanf("%d",&k);                            //输入需要添加几位员工
			add(staff,n,k);n=n+k;}break;
		case 2:n=del(staff,n);break;
		case 3:mod(staff,n);break;
		}
	}while(1);
}