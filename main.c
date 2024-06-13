#include<stdlib.h>
#include <stdio.h>
#include<string.h>
#include<conio.h>
int k=0;
void create(char [],int);
void display();
void insert_end();
void delete_pos();
void billing();
void record();
int tbill(int);
void arad(int,int);
struct cus{
    char name[20];
    int ap,tb;
    long long int mbo;
}c[1000];

struct node
{
    int price;
        int info;
        struct node *next;
};
struct node *start=NULL;
int main()
{
    create("Sugar",50);
    create("Suji",48);
    create("Bambino",88);
    create("Red Gram",90);
    create("Poha",60);
    create("Cumin",98);
    create("Chana",80);
    create("Salt",30);
    create("Honey",95);
    create("Ketchup",60);
    create("Soy_Sauce",50);

        int choice;
        while(1){
                char pro[20];
        int price;

        printf("\n                MENU                             \n");
                printf("\n 1.Display");
                printf("\n 2.Billing");
                printf("\n 3.Add new product   ");
                printf("\n 4.Delete any unavailable product  ");
                printf("\n 5.Record of customers");
                printf("\n 6.Exit      ");
                printf("\n\nEnter your choice:");
                scanf("%d",&choice);
                switch(choice)
                {

                        case 1:
                                        display();
                                        break;
                       case 2:
                                        billing();
                                        break;
                        case 3:
                            printf("\nEnter the product name to be inserted:" );
                            scanf("%s",pro );
                            printf("\nEnter the price of the product:");
                            scanf("%d",&price);
                                        insert_end(pro,price);
                                        break;
                        case 4:
                                        delete_pos();
                                        break;
                        case 5:
                                        record();
                                        break;

                        case 6:
                                        exit(0);
                                        break;

                        default:
                                        printf("n Wrong Choice:n");
                                        break;
                }
        }
        return 0;
}
void create(char item[20],int x)
{

        struct node *temp,*ptr;
        temp=(struct node *)malloc(sizeof(struct node));
        if(temp==NULL)
        {
                printf("nOut of Memory Space:n");
                exit(0);
        }
        temp->info=item;
        temp->price=x;
        temp->next=NULL;
        if(start==NULL)
        {
                start=temp;
        }
        else
        {
                ptr=start;
                while(ptr->next!=NULL)
                {
                        ptr=ptr->next;
                }
                ptr->next=temp;
        }
}
void display()
{
    int m=1;
        struct node *ptr;
        if(start==NULL)
        {
                printf("\nList is empty:\n");
                return;
        }
        else
        {
                ptr=start;
                printf("_______________________\n|S.No|   ITEM    |PRICE|\n");
                while(ptr!=NULL)
                {
                    if(m<=9){
                        printf("|____|___________|_____|\n|%d   |%s",m,ptr->info );
                        int r;
                        r=strlen(ptr->info);
                        for (int k=r;k<=10;k++)
                            printf(" ");
                        printf("|Rs.%d|\n",ptr->price);
                    }else{
                        printf("|____|___________|_____|\n|%d  |%s",m,ptr->info );
                        int r;
                        r=strlen(ptr->info);
                        for (int k=r;k<=10;k++)
                            printf(" ");
                        printf("|Rs.%d|\n",ptr->price);
                    }
                        ptr=ptr->next ;
                        m=m+1;
                }
                 printf("|____|___________|_____|\n");
        }
}

void insert_end(char pro[20],int p)
{
        struct node *temp,*ptr;
        temp=(struct node *)malloc(sizeof(struct node));
        if(temp==NULL)
        {
                printf("nOut of Memory Space:n");
                return;
        }
        temp->info=pro;
        temp->price=p;
        temp->next =NULL;
        if(start==NULL)
        {
                start=temp;
        }
        else
        {
                ptr=start;
                while(ptr->next !=NULL)
                {
                        ptr=ptr->next ;
                }
                ptr->next =temp;
        }
}
void delete_pos()
{
        int i,pos;
        struct node *temp,*ptr;
        if(start==NULL)
        {
                printf("nThe List is Empty:n");
                exit(0);
        }
        else
        {
            int posi;
                printf("\nEnter the position of the product to be deleted:");
                scanf("%d",&posi);
                pos=posi-1;
                if(pos==0)
                {
                        ptr=start;
                        start=start->next ;
                        printf("\nThe deleted product is:%s\n",ptr->info  );
                        free(ptr);
                }
                else
                {
                        ptr=start;
                        for(i=0;i<pos;i++) {
                                temp=ptr; ptr=ptr->next ;
                                if(ptr==NULL)
                                {
                                        printf("\nPosition not Found:\n");
                                }
                        }
                        temp->next =ptr->next ;
                        printf("nThe deleted product is:%s\n",ptr->info );
                        free(ptr);
                }
        }
}
void billing(){
    int n,i;
    char cha='a';
            int noo1;
          printf("How many orders you wanna make:\n");
              scanf("%d",&noo1);
for(i=k;cha!='e';i=i+0){
              printf("Enter your name:\n");
              scanf("%s",c[i].name);
              char mb[20];
              printf("Enter your mobile number:\n");
              scanf("%lld",&c[i].mbo);
                c[i].tb=tbill(noo1);
                printf("Total bill is:%d",c[i].tb);
              printf("\nEnter the amount:\n");
             scanf("%d",&c[i].ap);
              arad(c[i].ap,c[i].tb);
             printf("Thankyou for visiting us!! See you again(Enter e)\n");
             scanf(" %c",&cha);
}
              k=i+1;


}
int tbill(int noo){

    struct node *temp,*ptr;
   int bill=0;
    for(int j=0;j<noo;j++){
    int posi,pos,i;
                printf("\nEnter the position of the product you want to buy:");
                scanf("%d",&posi);
                pos=posi-1;
                ptr=start;
                        for(i=0;i<pos;i++) {
                                temp=ptr;
                                ptr=ptr->next ;
                                if(ptr==NULL)
                                {
                                        printf("\nPosition not Found:\n");
                                }
                        }
                        bill=bill+(ptr->price);

}

return(bill);
}
void record(){
    int i;
for(i=0;i<k;i++){
               if(c[i].ap>c[i].tb){
              printf("\n\n\nName:%s\nMobile Number:%lld\nTotal Bill:%d\nAmount Paid:%d\nAmount Returned:%d\n\n",c[i].name,c[i].mbo,c[i].tb,c[i].ap,c[i].ap-c[i].tb);
               }
               else if(c[i].ap<c[i].tb){
              printf("\n\nName:%s\nMobile Number:%lld\nTotal Bill:%d\nAmount Paid:%d\nAmount Due:%d\n\n",c[i].name,c[i].mbo,c[i].tb,c[i].ap,c[i].tb-c[i].ap);
               }
              else if(c[i].ap==c[i].tb){
                  printf("\n\nName:%s\nMobile Number:%lld\nTotal Bill:%d\nAmount Paid:%d\n\n",c[i].name,c[i].mbo,c[i].tb,c[i].ap);
              }
          }
}
void arad(int amp,int tob){
    int ar,ad;
    if(amp>tob){
                  ar=amp-tob;
                  printf("Here is your change:%d\n",ar);
              }
              else if(amp<tob){
                  ad=tob-amp;
                  printf("Amount due:%d\n",ad);
              }
}
