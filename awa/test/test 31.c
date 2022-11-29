//
// Created by 86183 on 2022/10/22.
//
#include <stdio.h>
#include <string.h>
int main()
{
    char choice;
    char enter[100];                   /*放需要加密的斯巴达密码的明文*/
    char caesar[100];              /*放需要加密的凯撒密码的明文*/
    int a=10,b,c,d,e=0,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t=1,v;
    char jiemi[100];                /*放需要解密的斯巴达密码的密文*/
    char jiemikaisa[100];               /*放需要解密的凯撒密码的密文*/
    char xiaoxie[]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    int choice_,choice__;
    printf("Please enter 'E' for encrypting or 'D' for decoding:");
    choice = getchar();
    if(choice=='E')
    {
        printf("Please enter 0 for spartan password or 1 for Caesar cipher:");
        scanf("%d",&choice_);
        if(choice_==0)/*斯巴达密码加密*/
        {
            printf("Please enter the message you want to encrypt: ");
            getchar();
            gets(enter);
            q=strlen(enter);
            if(q==8||q==9)  /*之前写的，不想改了*/
            {
                while (a<11)
                {
                    printf("The words encrypted is: ");
                    for(b=0;enter[b]!='\0';b+=3)
                    {
                        printf("%c",enter[b]);
                    }
                    for(c=1;enter[c]!='\0';c+=3)
                    {
                        printf("%c",enter[c]);
                    }
                    for(d=2;enter[d]!='\0';d+=3)
                    {
                        printf("%c",enter[d]);
                    }
                    a+=1;
                }
            }
            else if(q==1)
            {
                printf("What the fuck do you think just one word needs encrypting?");
            }
            else if(q==2)
            {
                printf("The words encrypted is: ");
                for(s=0;s<2;s++)
                {
                    printf("%c",enter[t]);
                    t=t-1;
                }
            }
            else
            {
                printf("The words encrypted is: ");
                for(v=0;enter[v]!='\0';v+=2)
                {
                    printf("%c",enter[v]);
                }
                for(v=1;enter[v]!='\0';v+=2)
                {
                    printf("%c",enter[v]);
                }
            }
        }
        else if (choice_==1) /*凯撒密码加密*/
        {
            printf("Please enter a numb you want to move to(1~25): ");
            scanf("%d",&l);
            printf("Please enter the message you want to encrypt: ");
            getchar();
            gets(caesar);
            for ( i = 0; caesar[i]!='\0'; i++)
            {
                if(caesar[i]>='a'&&caesar[i]<='z')
                {
                    j=caesar[i]-'a';
                    k=(j+l)%26;
                    caesar[i]=xiaoxie[k];
                }
            }
            printf("The words encrypted is: ");
            puts(caesar);
        }
        else
        {
            printf("Sorry,please enter 0 or 1");
        }


    }
    else if (choice=='D')
    {
        printf("Please enter 0 for spartan password or 1 for Caesar cipher: ");
        scanf("%d",&choice__);
        if(choice__==0)/*解密斯巴达*/
        {
            printf("Please enter the words you want to decode: ");
            getchar();
            gets(jiemi);
            r=strlen(jiemi);
            if(r==8||r==9)  /*懒狗一波*/
            {
                while (e<1)
                {
                    printf("The words decoded is: ");
                    for ( f = 0; f < r; f+=3)
                    {
                        printf("%c",jiemi[f]);
                    }
                    for(g=1;g<r;g+=3)
                    {
                        printf("%c",jiemi[g]);
                    }
                    for(h=2;h<r;h+=3)
                    {
                        printf("%c",jiemi[h]);
                    }
                    e+=1;
                }
            }
            else if(r==1)
            {
                printf("......");
            }
            else if (r==2)
            {
                printf("The words decoded is: ");
                for(s=0;s<2;s++)
                {
                    printf("%c",enter[t]);
                    t=t-1;
                }
            }
            else
            {
                printf("The words encrypted is: ");
                for(v=0;jiemi[v]!='\0';v+=3)
                {
                    printf("%c",jiemi[v]);
                }
                for(v=1;jiemi[v]!='\0';v+=3)
                {
                    printf("%c",jiemi[v]);
                }
                for(v=2;jiemi[v]!='\0';v+=3)
                {
                    printf("%c",jiemi[v]);
                }
            }
        }
        else if (choice__==1)/*解密凯撒*/
        {
            getchar();
            printf("What is the numb the words move? Please enter here: ");
            scanf("%d",&m);
            printf("Enter the words encrypted: ");
            getchar();
            gets(jiemikaisa);
            for(n=0;jiemikaisa[n]!='\0';n++)
            {
                if(jiemikaisa[n]>='a'&&jiemikaisa[n]<='z')
                {
                    o=jiemikaisa[n]-'a';
                    p=o-m;
                    if(p<0) p=26+p;
                    else if(p>0) p=p%26;
                    jiemikaisa[n]=xiaoxie[p];
                }
            }
            printf("The words decoded is: ");
            puts(jiemikaisa);
        }
        else if(choice__!=0&&choice__!=1)
        {
            printf("You don't understand the words above?");
        }
    }
    else if(choice!='E'&&choice!='D')
    {
        printf("What fucking do you want to do?");
    }


}