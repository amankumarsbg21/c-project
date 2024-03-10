#include<stdio.h>
#include<stdlib.h>
struct student{
    char name[20];
    int roll;
    int mark[3];
    float percentage;
    struct student *next;

}*head=NULL;
void append(void);
void insert(void);
void display_all(void);
void display_node(void);
void edit_node(void);
void search(void);
void delete_node(void);
void delete_all(void);
void mid_point(void);
void rev_display(void);
void sort(void);
struct student* searchName(void);
struct student* searchRoll(void);
struct student* newlist(void);
void display_pointer(struct student *t);
void swap(struct student*t , struct student *temp);
void main(void){
    int ch=0;
    do{
        printf("\nEnter your choice\n");
        printf("1. Append\t\t2. insert\t\t3. display all\t\t4. display node\n5. edit node\t\t6. search\t\t7. delete all\t\t8. delete node\n9. mid point\t\t10. rev display\t\t11. sort \t\t12. Exit\t\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: append();
                    break;
            case 2: insert();
                    break;
            case 3: display_all();
                    break;
            case 4: display_node();
                    break;
            case 5: edit_node();
                    break;
            case 6: search();
                    break;
            case 7: delete_all();
                    break;
            case 8: delete_node();
                    break;
            case 9: mid_point();
                    break;
            case 10:rev_display();
                    break;
            case 11:sort();
                    break;
            case 12: printf("\nExit\n");
                    break;
            default: printf("\nInvalid choice");
                    break;

        }
    }while(ch!=12);

}
void append(void)
{
    struct student *p=NULL;
    p=newlist();
    if(p==NULL)return;
    if(!head){
        head=p;
    }
    else{
        struct student *t=NULL;
        for(t=head;t->next;t=t->next);
        t->next=p;
    }
}
void display_all(void)
{
    if(!head){
        printf("\nlinked list not present");
    }else{
        struct student *t=NULL;
        for(t=head;t;t=t->next){
            printf("\nname:%s\troll:%d",t->name,t->roll);
            for(int i=0;i<3;i++){
                printf("\tSub %d mark: %d",(i+1),t->mark[i]);
            }
            printf("\tpercentage:%.2f\n",t->percentage);

        }

    }
}
void display_node(void)
{
    if(!head){
        printf("\nlinked list not present");
        return;
    }
    int ch=0;
    printf("\nEnter your choice\n1.Display using name \t2. Display using roll \t");
    scanf("%d",&ch);
    if(ch==1){
        struct student *t=NULL;
        t=searchName();
        if(t==NULL)printf("invalid name");
        else{
            display_pointer(t);
        }


    }else if(ch==2){

        struct student *t=NULL;
        t=searchRoll();
        if(t==NULL)printf("invalid roll");
        else{
            display_pointer(t);
        }
    }else{
        printf("invalid choice");
    }



}
void display_pointer(struct student *t){
    printf("\nname:%s\troll:%d",t->name,t->roll);
    for(int i=0;i<3;i++){
        printf("\tSub %d mark: %d",(i+1),t->mark[i]);
    }
    printf("\tpercentage:%.2f\n",t->percentage);
}
void edit_node(void)
{
    if(!head){
        printf("\nlinked list not present");
        return;
    }
    int ch=0;
    printf("\nEnter your choice\n1.edit by using name \t2. edit by using roll \t");
    scanf("%d",&ch);
    if(ch==1){
        struct student *t=NULL;
        t=searchName();
        if(t==NULL)printf("invalid name");
        else{
            printf("\nEnter new name:");
            fflush(stdin);
            gets(t->name);
            printf("\nEnter new roll:");
            scanf("%d",&t->roll);
            int add=0;
            for(int i=1;i<=3;i++){
                printf("\nEnter new marks of Sub %d : ",i);
                scanf("%d",&t->mark[(i-1)]);
                add+=t->mark[i-1];
            }
            t->percentage=add/3.0;

        }


    }else if(ch==2){

        struct student *t=NULL;
        t=searchRoll();
        if(t==NULL)printf("invalid roll");
        else{
            printf("\nEnter new name:");
            fflush(stdin);
            gets(t->name);
            printf("\nEnter new roll:");
            scanf("%d",&t->roll);
            int add=0;
            for(int i=1;i<=3;i++){
                printf("\nEnter new marks of Sub %d : ",i);
                scanf("%d",&t->mark[(i-1)]);
                add+=t->mark[i-1];
            }
            t->percentage=add/3.0;
        }
    }else{
        printf("invalid choice");
    }



}
void insert(void)
{
    struct student *p=NULL;
    p=newlist();
    if(p==NULL)return;
    int ch=0;
    printf("\nEnter your choice\n1.insert after name \t2. insert after roll \t");
    scanf("%d",&ch);
    if(ch==1){
        struct student *t=NULL;
        t=searchName();
        if(t==NULL)printf("invalid name");
        else{
            p->next=t->next;
            t->next=p;
        }


    }else if(ch==2){


        struct student *t=NULL;
        t=searchRoll();
        if(t==NULL)printf("invalid roll");
        else{

            p->next=t->next;
            t->next=p;
        }
    }else{
        printf("invalid choice");
    }

}
void search(void){
    if(!head){
        printf("\nlinked list not present");
        return;
    }
    int ch=0;
    printf("\nEnter your choice\n1.Search using name \t2. Search using roll \t");
    scanf("%d",&ch);
    if(ch==1){
        struct student *t=NULL;
        t=searchName();
        if(t==NULL)printf("Name is not present");
        else{
            printf("Name is present");
        }


    }else if(ch==2){

        struct student *t=NULL;
        t=searchRoll();
        if(t==NULL)printf("Roll is not present");
        else{
            printf("Roll is present");
        }
    }else{
        printf("invalid choice");
    }

}
struct student* searchRoll(void){
    int r=0;
    printf("\nEnter roll for search : ");
    scanf("%d",&r);
    struct student *t=NULL;
    for(t=head;t!=NULL && t->roll!=r;t=t->next);
    return t;
}
struct student* searchName(void){
    char n[20];
    printf("\nEnter name for search : ");
    fflush(stdin);
    gets(n);
    struct student *t=NULL;
    for(t=head;t!=NULL;t=t->next){
        int i=0;
        for(i=0;n[i]!='\0'||t->name[i]!='\0';i++){
            if(n[i]!=t->name[i] && (n[i]+32)!=t->name[i] && n[i]!=t->name[i]+32)break;
        }
        if(n[i]=='\0'&& t->name[i]=='\0')return t;
    }
    return NULL;

}
struct student* newlist(void){
    struct student *p=NULL;
    p=(struct student*)malloc(sizeof(struct student));
    if(!p)
    {
        printf("\nMemory is not available");
        return;
    }else{
        printf("\nEnter name:");
        fflush(stdin);
        gets(p->name);
        printf("\nEnter roll:");
        scanf("%d",&p->roll);
        int add=0;
        for(int i=1;i<=3;i++){
            printf("\nEnter marks of Sub %d : ",i);
            scanf("%d",&p->mark[(i-1)]);
            add+=p->mark[i-1];
        }
        p->percentage=add/3.0;
        p->next=NULL;
    }

}
void delete_all(void)
{
    struct student *t=NULL;
    char ch;
    printf("are you sure for delete (y/n): ");
    fflush(stdin);
    scanf("%c",&ch);
    if(ch=='y'||ch=='Y'){
        for(t=head;head!=NULL ;t=head){
            head=t->next;
            free(t);
        }
    }
}
void delete_node(void){
    int ch=0;
    printf("\nEnter your choice\n1. Delete using name \t2. Delete using roll \t");
    scanf("%d",&ch);
    struct student *t=NULL,*prev=NULL;
    if(ch==1){

        t=searchName();
        if(t==NULL)printf("Invalid Name");
        else{
            if(t==head){
                head=t->next;
                free(t);
            }else{
                for(prev=head;prev->next!=t;prev=prev->next);
                prev->next=t->next;
                free(t);
            }
        }


    }else if(ch==2){
        t=searchRoll();
        if(t==NULL)printf("Invalid Roll");
        else{
            for(prev=head;prev->next!=t;prev=prev->next);
            if(t==head){
                head=t->next;
                free(t);
            }else{
                prev->next=t->next;
                free(t);
            }
        }
    }else{
        printf("invalid choice");
    }



}
void mid_point(void)
{
    if(!head){
        printf("\nlinked list not present");
        return;
    }
    struct student *t=NULL,*p=NULL,*prev=NULL;
    for(t=head,p=head;t!=NULL && t->next!=NULL;t=t->next->next,p=p->next){
        prev=p;
    }
    if(t==NULL){
        printf("2 mid point - total(even value)");
        printf("\n1st mid ");
        display_pointer(prev);
        printf("\n2nd mid ");
        display_pointer(p);
    }else if(t->next==NULL){
        display_pointer(p);
    }
}
void rev_display(void)
{
    if(!head){
        printf("\nlinked list not present");
        return;
    }
    printf("Reverse display");
    revdis(head);

}
void revdis(struct student *t)
{

    if(t->next!=NULL){
        revdis(t->next);
    }
    display_pointer(t);
}
void sort(void){
    if(!head){
        printf("\nlinked list not present");
        return;
    }
    int ch=0;
    printf("\nEnter your choice\n1.Sort by name \t2. Sort by roll \t");
    scanf("%d",&ch);
    if(ch==1){
        struct student *t=NULL,*p=NULL;
        for(t=head;t->next!=NULL;t=t->next){
            int f=0;
            struct student *temp=NULL;
            temp=t;
            for(p=t->next;p!=NULL;p=p->next){
                for(int k=0;temp->name[k]!='\0' || p->name[k]!='\0';k++){
                    char ct=temp->name[k];
                    char cp=p->name[k];
                    if(ct>='A'&& ct<='Z')ct+=32;
                    if(cp>='A'&& cp<='Z')cp+=32;
                    if(ct<cp)break;
                    if(ct>cp){f=1;temp=p; break;}
                    if(ct=='\0'){break;}
                    if(cp=='\0'){f=1;temp=p;break;}
                }
            }
            if(f==1){
                swap(t,temp);
            }
        }
        printf("list Sorted by Name");


    }else if(ch==2){

        struct student *t=NULL,*p=NULL;
        for(t=head;t->next!=NULL;t=t->next){
            int f=0;
            struct student *temp=NULL;
            temp=t;
            for(p=t->next;p!=NULL;p=p->next){
                if(temp->roll > p->roll){
                    temp=p;
                    f=1;
                }
            }
            if(f==1){
                swap(t,temp);
            }
        }
        printf("list Sorted by Roll");
    }else{
        printf("invalid choice");
    }


}
void swap(struct student*t , struct student *temp){
                char namet[20];
                int i=0;
                for(i=0;t->name[i]!='\0';i++){
                    namet[i]=t->name[i];
                }namet[i]='\0';
                int rollt=t->roll;
                int markt[3];
                for(int i=0;i<3;i++){
                    markt[i]=t->mark[i];
                }
                float percentaget=t->percentage;

                for(i=0;temp->name[i]!='\0';i++){
                    t->name[i]=temp->name[i];
                }t->name[i]='\0';
                t->roll=temp->roll;
                for(int i=0;i<3;i++){
                    t->mark[i]=temp->mark[i];
                }
                t->percentage=temp->percentage;


                for(i=0;namet[i]!='\0';i++){
                    temp->name[i]=namet[i];
                }temp->name[i]='\0';
                temp->roll=rollt;
                for(int i=0;i<3;i++){
                    temp->mark[i]=markt[i];
                }
                temp->percentage=percentaget;
}
