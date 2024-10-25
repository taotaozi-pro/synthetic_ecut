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

void menu ();         //���˵�
void menu1();         //���˵�
void initial(struct staff sta[]);               //��ʼ��
void txt_sale(struct staff sta[],int n);        //���� 
void SUM(struct staff sta[],int n);             //ͳ��
void txt_prize(struct staff sta[],int n);       //���㽱�� 
void modify(struct staff sta[],int n);          //�޸���Ϣģ��
void add(struct staff sta[],int n,int k);       //���
int del(struct staff sta[],int n);              //ɾ��
void mod(struct staff sta[],int n);             //�޸�

int main(){
	int choice,n;
	do{
		menu();
		scanf("%d",&choice);
	    switch(choice){
		case 1:{	 
			printf("\t\t\t\t������Ա����������");
			scanf("%d",&n);
		    initial(staff,n);
			   }break;
	case 2:txt_sale(staff,n);break;
	case 3:SUM(staff,n);break;
	case 4:txt_prize(staff,n);break;
	case 5:modify(staff,n);break;
	case 6:printf("\t\t\t\t�˳�����");exit(0);        
	default:printf("\t\t\t\t�����������������룡\n");
	}
		system("pause");
	    system("cls");                     //����
	}while(1);
	return 0;
}

void menu(){                                //���˵�
	printf("\n\n\n\n\n");
	printf("\t\t\t\tԱ������ͳ�Ƽ����𷢷�ϵͳ\n");
	printf("\t\t\t\t �T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T\n");
	printf("\t\t\t\t�U                      �U\n");
	printf("\t\t\t\t�U   1.��Ϣ��ʼ��       �U\n");
	printf("\t\t\t\t�U   2.����Ա�����۶�   �U\n");
	printf("\t\t\t\t�U   3.ͳ����Ϣ         �U\n");
	printf("\t\t\t\t�U   4.���𷢷�         �U\n");
	printf("\t\t\t\t�U   5.�޸���Ϣ         �U\n");
	printf("\t\t\t\t�U   6.�˳�����         �U\n");
	printf("\t\t\t\t�U                      �U\n");
	printf("\t\t\t\t �T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T\n");
	printf("\t\t\t\t����������ѡ�����ȳ�ʼ��ϵͳ����\n");
	printf("\t\t\t\t��λ����Ԫ��\n\t\t\t\t");
}

void initial(struct staff sta[],int n){                //�Զ����ʼ������
	int i=0;
	if((fp=fopen("staff.txt","w"))==NULL)            // �ļ�ָ��fpָ������ļ�
         {	  
			 printf("�޷��򿪴��ļ�\n"); 
             exit(0);
         }
	for(i=0;i<n;i++)
	{
		printf("\t\t\t\t������Ա��%d�Ĺ��ţ�",i+1);        //���빤��
		scanf("%d",&sta[i].id);
	}
	for(i=0;i<n;i++)
     { 	fprintf(fp,"%d\t\n",sta[i].id);        //д���ļ�      
     }
	printf("\t\t\t\t��ʼ����ϣ���ӭ�ٴ�ʹ�ã�\n");
	fclose(fp);
}

void txt_sale(struct staff sta[],int n){                   //�Զ��庯���������۶�
	int i;
	if((fp=fopen("staff.txt","w"))==NULL)          // �ļ�ָ��fpָ������ļ�
         {	  
			 printf("\t\t\t\t�޷��򿪴��ļ�\n"); 
             exit(0);
         }
	printf("\t\t\t\t������Ա���ĸ����ȵ����۶��λ����Ԫ��\n");
	printf("\t\t\t\tԱ��\tһ��\t����\t����\t�ļ�\n");
	for(i=0;i<n;i++)             //�������������������۶�
	{
		printf("\t\t\t\t%d��",sta[i].id);
		scanf("%f%f%f%f",&sta[i].s.s1,&sta[i].s.s2,&sta[i].s.s3,&sta[i].s.s4);
	}
	
	fprintf(fp,"����\t��һ����\t�ڶ�����\t��������\t���ļ���\n",0);
	for(i=0;i<n;i++)            //д���ļ�
	{ 	
		fprintf(fp,"%d\t%-9.2f\t\t%-9.2f\t\t%-9.2f\t\t%-9.2f\t\n",sta[i].id,sta[i].s.s1,sta[i].s.s2,sta[i].s.s3,sta[i].s.s4);          
     }
	printf("\t\t\t\t��д���ļ�����ӭ�ٴ�ʹ�ã�");
	fclose(fp);
}

void SUM(struct staff sta[],int n){                      //�Զ���ͳ�ƺ���
	int i,j=0,k=0,c[4];int max1;
	float max2,sum1=0;
	//ͳ��ÿ���˵������۶�
	for(i=0;i<n;i++)                    
	{
		sta[i].sum=sta[i].s.s1+sta[i].s.s2+sta[i].s.s3+sta[i].s.s4;
	}
	 //ͳ����ҵ��������۶�
	for(i=0;i<n;i++)                 
	{
		sum1=sum1+sta[i].sum;
	}
	printf("\t\t\t\t��ҵ�������۶���%.2f��\n",sum1);
	printf("\t\t\t\tԱ��\tһ��\t����\t����\t�ļ�\t�����۶�\n");
	for(i=0;i<n;i++)
	{
		printf("\t\t\t\t%d\t%-.2f\t%-.2f\t%-.2f\t%-.2f\t%-.2f\n",sta[i].id,sta[i].s.s1,sta[i].s.s2,sta[i].s.s3,sta[i].s.s4,sta[i].sum);
	}
	//��ѡ���֮��
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
	printf("\t\t\t\t���������֮����%d������Ա��",j);
	for(i=0;i<j;i++){ k=c[i];  printf(" %d ",staff[k].id);}
	printf("�������۶�Ϊ%.2f.\n",max2);
	
	//��һ���ȼ���֮��
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
	printf("\t\t\t\t��һ���ȵļ���֮����%d������Ա��",j);
	for(i=0;i<j;i++){ k=c[i];  printf(" %d ",staff[k].id);}
	printf("�����۶�Ϊ%.2f.\n",max2);
	//�ڶ����ȼ���֮��
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
	printf("\t\t\t\t�ڶ����ȵļ���֮����%d������Ա��",j);
	for(i=0;i<j;i++){ k=c[i];  printf(" %d ",staff[k].id);}
	printf("�����۶�Ϊ%.2f.\n",max2);
	//�������ȼ���֮��
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
	printf("\t\t\t\t�������ȵļ���֮����%d������Ա��",j);
	for(i=0;i<j;i++){ k=c[i];  printf(" %d ",staff[k].id);}
	printf("�����۶�Ϊ%.2f.\n",max2);
	//���ļ��ȼ���֮��
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
	printf("\t\t\t\t���ļ��ȵļ���֮����%d������Ա��",j);
	for(i=0;i<j;i++){ k=c[i];  printf(" %d ",staff[k].id);}
	printf("�����۶�Ϊ%.2f.\n",max2);
	
	if((fp=fopen("staff.txt","w"))==NULL)             // �ļ�ָ��fpָ������ļ�
         {	  
			 printf("\t\t\t\t�޷��򿪴��ļ�\n"); 
             exit(0);
         }
	fprintf(fp,"����\t��һ����\t�ڶ�����\t��������\t���ļ���\t�����۶�\n",0);
	for(i=0;i<n;i++)                                   //д���ļ�
	{ 	
		fprintf(fp,"%d\t%-9.2f\t\t%-9.2f\t\t%-9.2f\t\t%-9.2f\t\t%-9.2f\n",sta[i].id,sta[i].s.s1,sta[i].s.s2,sta[i].s.s3,sta[i].s.s4,sta[i].sum);          
     }
	printf("\t\t\t\t��д���ļ�����ӭ�ٴ�ʹ�ã�\n");
	fclose(fp);
}

void txt_prize(struct staff sta[],int n){                 //�Զ�����㽱����
	int i,j,sum1=0,max1,k=0,c[4];
	float r;
	for(i=0;i<n;i++)                  //ͳ����ҵ��������۶�
	{
		sum1+=sta[i].sum;
	}
	//�ҵ���Ӧ����ɲ����㽱��
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

	//��ѡ���֮��
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
	for(i=0;i<j;i++){ k=c[i];sta[k].prize++;}         //���֮�Ƕ��⽱��һ��Ԫ

	printf("\t\t\t\tԱ��\tһ\t��\t��\t��\t�����۶�\t����\n");
	for(i=0;i<n;i++)
	{
		printf("\t\t\t\t%d\t%-.2f\t%-.2f\t%-.2f\t%-.2f\t%-.2f\t        %-.2f\n",sta[i].id,sta[i].s.s1,sta[i].s.s2,sta[i].s.s3,sta[i].s.s4,sta[i].sum,sta[i].prize);
	}
	if((fp=fopen("staff.txt","w"))==NULL)      // �ļ�ָ��fpָ������ļ�
         {	  
			 printf("\t\t\t\t�޷��򿪴��ļ�\n"); 
             exit(0);
         }
	fprintf(fp,"����\t��һ����\t�ڶ�����\t��������\t���ļ���\t���۶�\t�������\n",0);
	for(i=0;i<n;i++)                   //����ļ�
	{ 	
		fprintf(fp,"%d\t%-9.2f\t\t%-9.2f\t\t%-9.2f\t\t%-9.2f\t\t%-9.2f\t\t%-9.2f\n",sta[i].id,sta[i].s.s1,sta[i].s.s2,sta[i].s.s3,sta[i].s.s4,sta[i].sum,sta[i].prize);          
     }
	printf("\t\t\t\t��д���ļ�����ӭ�ٴ�ʹ�ã�\n");
	fclose(fp);
}

void menu1(){                             //���˵�
			printf("\n");
		printf("\n");
		printf("\n");
		printf("\n");
		printf("\n");
	printf("\t\t\t\t        �޸���Ϣ     \n");
	printf("\t\t\t\t �T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T\n");
	printf("\t\t\t\t�U                      �U\n");
	printf("\t\t\t\t�U                      �U\n");
	printf("\t\t\t\t�U   1.���Ա����Ϣ     �U\n");
	printf("\t\t\t\t�U   2.ɾ��Ա����Ϣ     �U\n");
	printf("\t\t\t\t�U   3.�޸�Ա�����۶�   �U\n");
	printf("\t\t\t\t�U   4.�������˵�       �U\n");
	printf("\t\t\t\t�U                      �U\n");
	printf("\t\t\t\t�U                      �U\n");
	printf("\t\t\t\t �T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T\n");
	printf("\t\t\t\t����������ѡ��");
}

void add(struct staff sta[],int n,int k){             //�Զ������Ա����Ϣ����
	int i;
	//printf("\t\t\t\t��������Ҫ��Ӽ�λԱ����");
	//scanf("%d",&k);                                //������Ҫ��Ӽ�λԱ��
	for(i=n;i<n+k;i++)
	{
		printf("\t\t\t\t������Ա��%d�Ĺ��ţ�",i+1);
		scanf("%d",&sta[i].id);                    //����Ա���Ĺ���
	}
	printf("\t\t\t\t������Ա���ĸ����ȵ����۶�\n");
	printf("\t\t\t\tԱ��  һ �� �� ��\n");
	for(i=n;i<n+k;i++)
	{
		printf("\t\t\t\t%d��",sta[i].id);
		scanf("%f %f %f %f",&sta[i].s.s1,&sta[i].s.s2,&sta[i].s.s3,&sta[i].s.s4);      //�������۶�
	}
	printf("\t\t\t\t�����Ϣ�ɹ���\n");
	n=n+k;                                      //���º��Ա������
	SUM(staff,n);
	txt_prize(staff,n);
	system("pause");
}

int del(struct staff sta[],int n){                     //�Զ���ɾ��Ա����Ϣ����  
	int i,j,a;

	printf("\t\t\t\tԱ��\tһ\t��\t��\t��\t�����۶�\n");
	for(i=0;i<n;i++)
	{
		printf("\t\t\t\t%d\t%-.2f\t%-.2f\t%-.2f\t%-.2f\t%-.2f\n",sta[i].id,sta[i].s.s1,sta[i].s.s2,sta[i].s.s3,sta[i].s.s4,sta[i].sum);
	}

	printf("\t\t\t\t������Ҫɾ����Ա���Ĺ��ţ�");
	scanf("%d",&a);
	for(i=0;i<n;i++)                           //��Ա����Ϣɾ��
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
	printf("\t\t\t\tɾ����Ϣ�ɹ���\n");
	n--;                                         //���º�Ա������Ϊn-1
	SUM(staff,n);
	txt_prize(staff,n);
	system("pause");
	return n;
}

void mod(struct staff sta[],int n){                   //�Զ����޸����ݺ���
	int i,a,b; 
	float k;
	SALE *p;                                         //����SALE��ָ��

	printf("\t\t\t\tԱ��\tһ\t��\t��\t��\t�����۶�\n");
	for(i=0;i<n;i++)
	{
		printf("\t\t\t\t%d\t%-.2f\t%-.2f\t%-.2f\t%-.2f\t%-.2f\n",sta[i].id,sta[i].s.s1,sta[i].s.s2,sta[i].s.s3,sta[i].s.s4,sta[i].sum);
	}

	printf("\t\t\t\t��������Ҫ�޸����ݵ�Ա�����š��͵ڼ����ȵ����۶");
	scanf("%d %d",&a,&b);
	printf("\t\t\t\t����ֵ�޸�Ϊ��");
	scanf("%f",&k);
	for(i=0;i<n;i++)
	{
		if(a==sta[i].id)
		{
			p=&sta[i].s;                   //��ָ��ָ��sta[i].s
			if(b==1)  p->s1=k;
			if(b==2)  p->s2=k;
			if(b==3)  p->s3=k;
			if(b==4)  p->s4=k;
		}
	}
	printf("\t\t\t\t�޸ĳɹ���\n");
	SUM(staff,n);
	txt_prize(staff,n);
	system("pause");
}

void modify(struct staff sta[],int n){                       
	int i,j,k,l;
	do{
		system("cls");                    //����
		menu1();
		scanf("%d",&l);
		if(l==4)  {printf("\t\t\t\t��������������˵�!\n");break;}     //�������˵�
		switch(l)
		{
		case 1: {
			printf("\t\t\t\t��������Ҫ��Ӽ�λԱ����");
	        scanf("%d",&k);                            //������Ҫ��Ӽ�λԱ��
			add(staff,n,k);n=n+k;}break;
		case 2:n=del(staff,n);break;
		case 3:mod(staff,n);break;
		}
	}while(1);
}