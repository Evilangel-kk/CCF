#include<stdio.h>
typedef long long LL;

int r,y,g;//���̵����� 
int n;
int k,t;
LL ans=0;

/*
k=1: ���r [0,r)
k=2: �Ƶ�y [r+g,r+g+y)
k=3: �̵�g [r,r+g)

������������ 
�� |__________|__________|___|
	   ���       �̵�    �Ƶ� 
*/

int judge(LL tt){ //�ж�ttʱ�̸ô��ĺ��̵����
	if(tt>=0 && tt<r) return 1;	//���
	if(tt>=r+g && tt<r+g+y) return 2; //�Ƶ�
	if(tt>=r && tt<r+g) return 3; //�̵�
}

int main(){
	scanf("%d%d%d",&r,&y,&g);
	scanf("%d",&n);
	for(LL i=0;i<n;i++){
		scanf("%d%d",&k,&t);
		if(k==0){	//����·��
			ans+=t;
		}
		else if(k==1){	//�տ�ʼ�����Ǻ�ƣ��жϴ�ʱ����ʲô��
			LL tt=r-t;
			tt=(tt+ans)%(r+y+g);
			int flag=judge(tt);
			if(flag==1){	//����˺��
				ans+=r-tt;
			}
			else if(flag==2){	//����˻Ƶ�
				ans+=r+y+g-tt+r;
			}
		}
		else if(k==2){  //�տ�ʼ�����ǻƵƣ��жϴ�ʱ����ʲô��
			LL tt=r+g+y-t;
			tt=(tt+ans)%(r+y+g);
			int flag=judge(tt);
			if(flag==1){ 	//����˺��
				ans+=r-tt;
			}
			else if(flag==2){	//����˻Ƶ�
				ans+=r+y+g-tt+r;
			}
		}
		else if(k==3){  //�տ�ʼ�������̵ƣ��жϴ�ʱ����ʲô��
			LL tt=r+g-t;
			tt=(tt+ans)%(r+y+g);
			int flag=judge(tt);
			if(flag==1){	//����˺��
				ans+=r-tt;
			}
			else if(flag==2){	//����˻Ƶ�
				ans+=r+y+g-tt+r;
			}
		}
	}
	printf("%lld\n",ans);
	return 0;
}

