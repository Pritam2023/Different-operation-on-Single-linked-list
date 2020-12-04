#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct student
{
	char nm[100];
	int roll;
	struct student *link;
};
struct student *start,*tail;
void create();
void begin();
void after(int pos);
void end();
void display();
void del_begin();
void del_end();
void del_after();
void reverse();
void sort();
int getlen();
void delete_range();
main()
{
	int ch,pos,count=0;
	start=tail=NULL;
	struct student *p;
	while(1)
	{
	printf("Enter 1 for create\n2 for display\n3 for inser begin\n4 for insert end\n5 for insert after\n6 for delete from begining\n7 for delete from the end\n8 for delete from a specific pos\n9 for reverse\n10 for sort\n11 to delete node in a spefic range\n 12 to exit");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
			create();
			break;
		case 2:
			display();
			break;
		case 3:
			begin();
			break;
		case 4:
			end();
			break;
		case 5:
		    printf("Enter the position after which you want to insert");
		    scanf("%d",&pos);
		    p=start;
		    while(p!=NULL)
		      {
			count++;
			p=p->link;
		      }
		    if(pos>count)
		    {
			printf("Invalid position\n");
		    }
		   else
		   after(pos);
		   break;
		case 6:
			del_begin();
			break;
		case 7:
			del_end();
			break;
		case 8:
			del_after();
			break;
		case 9:
			reverse();
			break;
		case 10:
			sort();
			break;
		case 11:
			delete_range();
			break;
		case 12:
			exit(1);
		}
	}
	}
	void create()
	{
		struct student *temp=(struct student*)malloc(sizeof(struct student));
		scanf("%d",&temp->roll);
		fflush(stdin);
		gets(temp->nm);
		temp->link=NULL;
		if(start==NULL)
		start=tail=temp;
		else
		{
			tail->link=temp;
			tail=temp;
		}
		
	}
	void display()
	{
		struct student *t=start;
		if(start==NULL)
		printf("List is empty\n");
		else
		{
		while(t!=NULL)
		{
			puts(t->nm);
			printf("roll no.-%d\n",t->roll);
			t=t->link;
		}
	}
	}
	void begin()
	{
		struct student *temp1=(struct student*)malloc(sizeof(struct student));
		scanf("%d",&temp1->roll);
		fflush(stdin);
		gets(temp1->nm);
		temp1->link=NULL;
		if(start==NULL)
		{
			start=tail=temp1;
		}
		if(start!=NULL)
		{
			temp1->link=start;
			start=temp1;
		}
	}
	void end()
	{
		struct student *temp1=(struct student*)malloc(sizeof(struct student));
		scanf("%d",&temp1->roll);
		fflush(stdin);
		gets(temp1->nm);
		temp1->link=NULL;
		if(start==NULL)
		{
			start=tail=temp1;
		}
		else
		{
			struct student *t=start;
			while(t->link!=NULL)
			t=t->link;
			t->link=temp1;
			tail=temp1;
		}
	}
	void after(int pos)
	{
		struct student *temp1=(struct student*)malloc(sizeof(struct student));
		struct student *t=start;
		scanf("%d",&temp1->roll);
		fflush(stdin);
		gets(temp1->nm);
		temp1->link=NULL;
		int c=1;
			while(c<pos)
			{
				t=t->link;
				c++;
			}
			temp1->link=t->link;
			t->link=temp1;
	}
	void del_begin()
	{
		if(start==NULL)
		printf("List is empty");
		else
		{
		struct student *z=start;
		start=start->link;
		free(z);
	}
	}
	void del_end()
	{
		struct student *t=start;
		struct student *prevnode;
		while(t->link!=NULL)
		{
			prevnode=t;
			t=t->link;
		}
		prevnode->link=NULL;
		free(t);
	}
	 void del_after()
	{
		struct student *t=start;
		int pos1;
		printf("Enter the psition of the node");
		scanf("%d",&pos1);
		int c=1;
		while(c<pos1-1)
		{
			t=t->link;
			c++;
		}
		struct student *next=t->link;
		t->link=next->link;
		free(next);
	}
	void reverse()
	{
		struct student *prevnode,*currentnode,*nextnode;
		prevnode=NULL;
		currentnode=nextnode=start;
		while(nextnode!=NULL)
		{
			nextnode=nextnode->link;
			currentnode->link=prevnode;
			prevnode=currentnode;
			currentnode=nextnode;	
		}
		start=prevnode;
	}
	void sort()
	{
		struct student *i,*j;
		int c,flag;
		char s[100];
		for(i=start;i->link!=NULL;i=i->link)
		{
			flag=0;
			for(j=i->link;j!=NULL;j=j->link)
			{
				if(i->roll>j->roll)
				{
					flag=1;
					c=i->roll;
					i->roll=j->roll;
					j->roll=c;
					strcpy(s,i->nm);
					strcpy(i->nm,j->nm);
					strcpy(j->nm,s);
				}
			}
			if(flag==0)
			break;
		}
	}
	void delete_range()
{
	int l=getlen();
	struct student *t=start;
	struct student *d;
	int pos1,pos2;
	int c=1;
	printf("Enter the starting and ending node-");
	scanf("%d %d",&pos1,&pos2);
	if(pos1==1 && pos2==l)
	{
		struct student *del;
		while(t!=NULL)
		{
			del=t;
			t=t->link;
			free(del);
		}
	}
	else
	{
	while(c<pos1)
	{
		d=t;
		c++;
		t=t->link;
	}
	while(c<=pos2)
	{
		struct student *temp=t;
		t=temp->link;
		c++;
		free(temp);
	}
	if(pos1==1)
	{
	start=t;
    }
    else if(pos2==l)
    {
    	tail=d;
    	tail->link=NULL;
	}
    else
	d->link=t;
}
}
int getlen()
{
	struct student *t=start;
	int count=1;
	while(t!=NULL)
	
{
	count++;
	t=t->link;
}
	return count;
}

