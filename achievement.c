#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//author�� EugeneJie 

struct students{	//�ṹ��������¼���ѧ����Ϣ 
	long num;	//ѧ�� 
	char name[10];	//���� 
	int score[6];	//ÿ�ſγ̳ɼ� 
}student[30];
void exchange(int rs,int ms,int i,int j)	//���彻��¼���ѧ����Ϣ 
{
	int k,t1;
	long t2;
	char t3[10];
	t2=student[i].num;				//����ѧ�� 
	student[i].num=student[j].num;
	student[j].num=t2;
	strcpy(t3,student[i].name);		//�������� 
	strcpy(student[i].name,student[j].name);
	strcpy(student[j].name,t3);
	for(k=0;k<ms;k++)				//�������Ƴɼ�
	{
		t1=student[i].score[k];
		student[i].score[k]=student[j].score[k];
		student[j].score[k]=t1;
	}
}
void luru(int rs,int ms)	//�ֶ�¼��
{
	int i,j; 
	printf("������ѧ����ѧ�ź�����----\n");
	for(i=0;i<rs;i++)
	{
		printf("��%dλѧ����",i+1);
		scanf("%ld%s",&student[i].num,&student[i].name);
		printf("��¼��%ld %s��%d�ſγ̵Ŀ��Գɼ�:\n",student[i].num,student[i].name,ms); 
		for(j=0;j<ms;j++)
			scanf("%d",&student[i].score[j]); 
	}
	printf("¼��ɹ���\n");
}
void jisuan(int rs,int ms)	//����ÿ�ſγ̵��ֺܷ�ƽ����
{
	int i,j,sum[6]={0};
	float aver[6];
	for(i=0;i<ms;i++)	//����ÿ�ſγ��ֺܷ�ƽ���� 
	{
		for(j=0;j<rs;j++)
			sum[i]+=student[j].score[i];
		aver[i]=sum[i]*1.0/rs;
	}
	printf("\t�ܷ�\tƽ����\n");
	for(i=0;i<ms;i++)
		printf("�γ�%d\t%d\t%.1f\n",i+1,sum[i],aver[i]);
		
	}
void mingci(int rs,int ms)	//��ѧ���ܷ��ɸߵ����ų����α� 
{
	int t1,i,j,sum[30]={0};
	long t2;
	char t3[10];
	for(i=0;i<rs;i++)		//����ÿ��ѧ�����ܷ� 
		for(j=0;j<ms;j++)
			sum[i]+=student[i].score[j];
	for(i=0;i<rs-1;i++)		//����ѧ���ܷ�ð������ 
		for(j=i+1;j<rs;j++)
			if(sum[i]<sum[j])
			{
				t1=sum[i];	//�����ܷ� 
				sum[i]=sum[j];
				sum[j]=t1;
				exchange(rs,ms,i,j); 
			}
	printf("����\tѧ��\t����\t�ܷ�\n");	//������α�
	for(i=0;i<rs;i++)
		printf("%2d    %-8ld %s\t%d\n",i+1,student[i].num,student[i].name,sum[i]); 
}
void chengji(int rs,int ms)
{
	int i,j,k,t1,sum[30]={0};
	long t2;
	char t3[10];
	for(i=0;i<rs-1;i++)		//����ѧ��ѧ��ð������ 
		for(j=i+1;j<rs;j++)
			if(student[i].num>student[j].num)
				exchange(rs,ms,i,j);
	for(i=0;i<rs;i++)		//����ÿ��ѧ�����ܷ�  
		for(j=0;j<ms;j++)
			sum[i]+=student[i].score[j];
	printf("  ѧ��\t  ����");	//����ɼ��� 
	for(i=0;i<ms;i++)
		printf("\t�γ�%d",i+1);
	printf("\t�ܷ�\n"); 
	for(i=0;i<rs;i++)
	{
		printf("%-8ld %s",student[i].num,student[i].name);
		for(j=0;j<ms;j++)
			printf("\t%d",student[i].score[j]);
		printf("\t%d\n",sum[i]);
	}
}
void query(int rs,int ms)	//��������ѯѧ���������俼�Գɼ� 
{
	int i,j,k,count,flag=0,t1,sum[30]={0};
	long t2;
	char t3[10];
	for(i=0;i<rs;i++)		//����ÿ��ѧ�����ܷ� 
		for(j=0;j<ms;j++)
			sum[i]+=student[i].score[j];
	for(i=0;i<rs-1;i++)		//����ѧ���ܷ�ð������ 
		for(j=i+1;j<rs;j++)
			if(sum[i]<sum[j])
			{
				t1=sum[i];	//�����ܷ� 
				sum[i]=sum[j];
				sum[j]=t1;
				exchange(rs,ms,i,j);
			}
	printf("������ѧ��������");
	scanf("%s",&t3);
	for(i=0,count=0;i<rs;i++,count++)
		if(strcmp(t3,student[i].name)==0)
		{
			flag=1; 
			break;
		}
	if(flag)	//�ж����޴�ѧ�� 
	{
		printf("  ѧ��\t  ����");	//����ɼ��� 
		for(i=0;i<ms;i++)
			printf("\t�γ�%d",i+1);
		printf("\t�ܷ�\t����\n");
		printf("%-8ld %s",student[count].num,student[count].name);
		for(j=0;j<ms;j++)
			printf("\t%d",student[count].score[j]);
		printf("\t%d\t%d\n",sum[count],count+1);
	}
	else printf("δ��ѯ����ѧ���ɼ��������Ƿ�������ȷ��\n") ;
	
}
void statistics(int rs,int ms)	//��ÿ�ſγ̷ֱ�ͳ��ÿ�����������Լ���ռ�İٷֱ�
{
	int i,j,c1,c2,c3,c4,c5;
	printf("\t����\t\t����\t\t�е�\t\t����\t\t������\n");
	for(i=0;i<ms;i++)
	{	
		c1=c2=c3=c4=c5=0;	//���������� 
		for(j=0;j<rs;j++)
			if(student[j].score[i]<60) c5++;
			else if(student[j].score[i]<70) c4++;
			else if(student[j].score[i]<80) c3++;
			else if(student[j].score[i]<90) c2++;
			else c1++;
		printf("�γ�%d",i+1); 
		printf("\t%d (%.1f%%)",c1,c1*100.0/rs); 
		printf("  \t%d (%.1f%%)",c2,c2*100.0/rs); 
		printf("  \t%d (%.1f%%)",c3,c3*100.0/rs); 
		printf("  \t%d (%.1f%%)",c4,c4*100.0/rs); 
		printf("  \t%d (%.1f%%)",c5,c5*100.0/rs); 
		printf("\n");
	}
}
void output(int rs,int ms)
{
	int i,j,k,t1,sum[30]={0};
	long t2;
	char t3[10];
	float aver[30];
	for(i=0;i<rs-1;i++)	//����ѧ��ѧ��ð������ 
		for(j=i+1;j<rs;j++)
			if(student[i].num>student[j].num)
				exchange(rs,ms,i,j); 
	for(i=0;i<rs;i++)	//����ÿ��ѧ�����ֺܷ�ƽ���� 
	{
		for(j=0;j<ms;j++)
			sum[i]+=student[i].score[j];
		aver[i]=sum[i]*1.0/ms;
	}		
	printf("  ѧ��\t  ����");	//����ɼ��� 
	for(i=0;i<ms;i++)
		printf("\t�γ�%d",i+1);
	printf("\t�ܷ�\tƽ����\n"); 
	for(i=0;i<rs;i++)
	{
		printf("%-8ld %s",student[i].num,student[i].name);
		for(j=0;j<ms;j++)
			printf("\t%d",student[i].score[j]);
		printf("\t%d\t%.1f\n",sum[i],aver[i]);
	}
}
int* read()	//��ȡѧ����Ϣ 
{
	FILE *fp;
	int i,j,rs,ms;
	static int n[2];	//���徲̬����洢�ļ��е�ѧ�������Ϳγ������Է��ظ������� 
	char s[50];
	printf("�������ļ���(�ɰ����ļ�·��)��");
	scanf("%s",&s);
	if((fp=fopen(s,"r"))==NULL)
	{
		printf("�ļ���ʧ�ܣ������Ƿ�������ȷ��\n");
		exit(0);
	}
	for(rs=-1;feof(fp)==0;rs++)		//���ж�ȡѧ����Ϣֱ���ļ�����������-1(��Ϊ¼�����һ��ѧ����������һ��)��Ϊѧ������ 
		fgets(s,50,fp);
	fseek(fp,18,0); 	//��ָ���ƶ�����һ��ѧ������֮�� 
	fgets(s,35,fp);		//��ȡ����ѧ���ɼ�ʹָ���ƶ� 
	ms=((int)(ftell(fp))-18)/5;		//ָ��λ�ü���ʼλ�ó��Ը�ʽ��ÿ�ųɼ���ռ�ֽ�����Ϊ�γ����� 
	rewind(fp);			//ʹָ��ص��ļ��ײ� 
	for(i=0;i<rs;i++)	//��ȡ���洢ѧ����Ϣ 
	{
		fscanf(fp,"%ld%s",&student[i].num,&student[i].name);
		for(j=0;j<ms;j++)
			fscanf(fp,"%d",&student[i].score[j]);
	}
	fclose(fp);		//�ر��ļ� 
	printf("��ȡ�ɹ�����ѯ��%d��ѧ����%d�ſγ̵ĳɼ���\n\n",rs,ms);
	chengji(rs,ms);
	n[0]=rs;
	n[1]=ms;
	return n;
 } 
 void write(int rs,int ms)	//��ѧ����Ϣд���ļ� 
 {
 	FILE *fp;
 	int i,j;
 	char file[50];
 	printf("��Ϊд����ļ�����(��ָ���洢·��)��");
 	scanf("%s",&file);
 	if((fp=fopen(file,"w"))==NULL)
 	{
 		printf("�ļ�д��ʧ�ܣ������ԣ�\n");
 		exit(0);
	}
	for(i=0;i<rs;i++)	//��ָ����ʽ��ѧ����Ϣд���ļ� 
	{
		fprintf(fp,"%-8ld%10s",student[i].num,student[i].name);
		for(j=0;j<ms;j++)
			fprintf(fp,"%5d",student[i].score[j]);
		fprintf(fp,"\n");
	}
	fclose(fp);		//�ر��ļ�  
	printf("�ļ�д��ɹ���\n");
 }
int main()
{
	int s,s1,s2,rs,ms,*p;
	system("title ѧ���ɼ�����ϵͳ");                       //����̨���� 
	do{														//ѭ����ʾ�˵� 
		printf("\n1.��ȡ�ļ�����\n");
		printf("2.�ֶ�¼��\n");
		printf("3.����ÿ�ſγ̵��ֺܷ�ƽ����\n");
		printf("4.��ѧ���ܷ��ɸߵ����ų����α�\n");
		printf("5.��ѧ����С�����ų��ɼ���\n");
		printf("6.��������ѯѧ���������俼�Գɼ�\n");
		printf("7.ͳ��\n");
		printf("8.���\n");
		printf("9.д���ļ�\n");
		printf("0.�˳�ϵͳ\n");
		printf("��ѡ�������Ӧ�Ĳ˵��");
		scanf("%d",&s);
		if(s==1)											//�ж�����Ĳ˵��ִ����Ӧ���� 
		{
			p=read();		//pָ�����ѧ�������Ϳγ�����������
			rs=*p;			//*pΪѧ������
			ms=*(p+1);		//*(p+1)Ϊ�γ�����
		}
		else if(s==2) 
		{
			printf("������ѧ�������Ϳγ�������");
			scanf("%d%d",&s1,&s2);		//Ϊ������������ʹ����ms,rs�п��ܴ��е����ݶ�ʧ ����˽������������ʱ������������������� 
			if(s1<0||s1>30||s2<0||s2>6)
				printf("����������������룡\n");
			else 
			{
				rs=s1;
				ms=s2; 
				luru(rs,ms);
			}
		}
		else if(s==3) jisuan(rs,ms);
		else if(s==4) mingci(rs,ms);
		else if(s==5) chengji(rs,ms);
		else if(s==6) query(rs,ms);	
		else if(s==7) statistics(rs,ms);
		else if(s==8) output(rs,ms);
		else if(s==9) write(rs,ms);
		else if(s==0) ;
		else printf("����������������룡\n");	
	}while(s!=0);
	return 0;
}
