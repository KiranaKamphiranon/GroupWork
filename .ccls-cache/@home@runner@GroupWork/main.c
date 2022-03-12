#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "store.h"

int main() 
{
  /*
  ร้านค้ามีเงิน 5000 บาท
  มี 5 menu 
  1 เช็คหนังสือที่มี (เรียงตามตัวอักษร)
    -เรียงหนังสือตาม A-Z
    -เรียงหนังสือตามราคามากไปน้อย
    -เรียงหนังสือตามจำนวนสินค้า
  2 ลูกค้าขายหนังสือ
  3 ลูกค้าซื้อหนังสือ
  4 บริจ้ากเงิน
  5 ออกโปรแกรม
  */
  
  NodePtr STOCK = NULL,current;
  NODE *head,*temp;
  int choice,before_store,thing;
  int check = 1,check2 = 1,check3 = 1,shop=0,count,profit;
  int cash = 5000,donate,sell1,buy1,chq;
  int price,qty_s,qty_b,earnmoney=0,pay=0,sort=0;
  char bookname[20],key[10];
  while (check == 1)
  {
    menu();
    printf(">> ");
    if(scanf("%d",&choice)) {};
    switch(choice)
    {    
      case 1 :
        if(STOCK!=NULL){
          do{
            printf("\033[0;0H\033[2J");
            menu();
        printf("\t1-Book Name Sort\n\t2-Price Sort\n\t3-Pieces Sort\n\t\t>> ");
            if(scanf("%d",&sort)){};
            printf("\033[0;0H\033[2J");
            if(sort==1){
              printf("The Stock: Name [a->z]\n");
              SwapName(&STOCK);
            }
            else if(sort==2){
              printf("The Stock: Price [high->low]\n");
              SwapPrice(&STOCK);
            }
            else if(sort==3){
              printf("The Stock: Quantity [high->low]\n");
              SwapQty(&STOCK);            
            }
            else sort = 0;
          }while(sort==0);
          printf("-------------------------------------\n");
          printStock(&STOCK);
          printf("-------------------------------------\n");
          printf("Shop cash is %d bath\n",cash);
        }
        else {
          printf("\033[0;0H\033[2J");
          printf("Stock is Empty...\nShop cash is %d bath\n",cash);
        }
        break;
      case 2 : 
        printf("\033[0;0H\033[2J");
        if(sort==1){
          SwapName(&STOCK);
        }
        else if(sort==2){
          SwapPrice(&STOCK);
        }
        else if(sort==3){
          SwapQty(&STOCK);            
        }
        if(STOCK!=NULL){printf("-------------------------------------\n");}
        printStock(&STOCK);
        SwapName(&STOCK);
        if(STOCK!=NULL){printf("-------------------------------------\n");}
        printf("Book Name: ");
        do{
          if(scanf("%s", bookname)) {};
          sell1 = checkstock(&STOCK,bookname); //sell=ขายให้ร้าน
          if (sell1 == 0){
            printf("Price Book: ");
            if(scanf("%d", &price)) {};
            printf("Quantity Book: ");
            if (scanf("%d", &qty_s)) {};
            if (cash-(price*qty_s)>=0) {
              sell(&STOCK,bookname,price*(140/100),qty_s);
              cash=cash-(price*qty_s);
              printf("\033[0;0H\033[2J");
              printf("-------------------------------------\n");
              printf("Thank you for the books ><\nShop cash is %d bath\n",cash);
            }
            else{
              printf("-------------------------------------\n");
              printf("Cannot pay to customer...\nShop cash is %d bath\n",cash);
            }
          }
          else {
            
            printf("The name is unviable!!!\n");
            printf("New Book Name: ");
          }
        }while(sell1 != 0);
        if(sort==1){
          SwapName(&STOCK);
        }
        else if(sort==2){
          SwapPrice(&STOCK);
        }
        else if(sort==3){
          SwapQty(&STOCK);            
        }
        break;
      case 3 :
        printf("\033[0;0H\033[2J");
        if(STOCK!=NULL)
        {
          printf("-------------------------------------\n");
          printStock(&STOCK);
          printf("-------------------------------------\n");
          printf("Choose book [name]: ");
          if(scanf("%s",bookname)) {};
          do{
          buy1=checkstock(&STOCK,bookname);
            if(buy1==0){
              printf("Can't buy a book\n");
              printf("Input again -> ");
              if(scanf("%s",bookname)) {};
              buy1=checkstock(&STOCK,bookname);
            }
          }while(buy1==0);
          printf("Quantity : ");
          if(scanf("%d",&qty_b)) {};
          do{
            chq=checkquan(&STOCK,qty_b,bookname);
            if(chq!=0){
              printf("New Quantity : ");
              if(scanf("%d",&qty_b)) {};
              chq=checkquan(&STOCK,qty_b,bookname);
            }              
          }while(chq!=0);
          earnmoney = buy(&STOCK,bookname,qty_b);
          printf("You have to pay %d\n",earnmoney);
          while(pay<earnmoney)
          {
            printf("Cash : ");
            if(scanf("%u",&pay)){};
          }
          if(pay!=earnmoney)
          {
            pay=pay-earnmoney;
            printf("Change : %d\n",pay);
            pay=0;
          }
            cash = cash + earnmoney ; 
          printf("Finished your order (^_^)\n");
        }
        else 
          puts("Stock is Empty...");
        break;
      case 4 :
        printf("\033[0;0H\033[2J");
        printf("How much do you donate?\n");
        printf("Tam Kam Lung Sattha > ");
        if(scanf("%d",&donate)){};
        cash += donate;
          printf("Thank you for your kindness^^\n");
        break;
      case 5:
        printf("Keywords : ");
        if(scanf("%s",key)) {};
        if (strcmp(key,"Egco_112")==0)
        {
          check=0;
          printf("\033[0;0H\033[2J"); //system clear
          printf("Cash remain = %d\n",cash);
          if(cash<=5000)
          {
            printf("------------------------------------------------\n");
            printf("All of cash and books will donate to foundation.\n");
            printf("------------------------------------------------\n");
          }
          else
          {
            printf("All profit = ");
            profit = cash-5000;
            printf("%d\n",profit);
            while(check2==1)
            {
              printf("1. Donate all cash.\n");
              printf("2. Buy somethings for donate.\n");
              printf("select -> ");
              if(scanf("%d",&before_store)){};             
              switch(before_store)
              {
                case 1:
                  {
                    printf("------------------------------------------------\n");
                    printf("All of cash and books will donate to foundation.\n");
                    printf("------------------------------------------------\n");
                    check2=0;
                  }
                  break;
                case 2:
                      printf("\033[0;0H\033[2J");//system("cls");
                      printf("= = = = = = = = = = = = = = = = = =\n");
                      printf("# 1 Bag  [100]    3 Pencil   [3]  #\n");
                      printf("# 2 Ball [49]     4 Notebook [20] #\n");
                      printf("#                 5 Exit     [:(] #\n");
                      printf("= = = = = = = = = = = = = = = = = =\n");
                    while(check3==1)
                      {
                       printf("\n");
                       if(cash-shop>=0)
                        {
                          cash=cash-shop;
                          printf("Cash = %d\n",cash);
                          if(cash>2){
                              printf("What would you like > ");
                              if(scanf("%d",&thing)){};
                          }
                          else thing = 5;
                          switch(thing)
                            {
                              case 1:
                                {
                                  printf("Bag -> How many?\n= ");
                                  if(scanf("%d",&count)){};
                                  if(count*100>cash)
                                  {
                                    printf("Not enough cash!\n");
                                  }
                                  else
                                  {
                                    printf("Buy 'Bag *%d' finish.\n",count);
                                    shop=count*100;
                                  }
                                  break;
                                }
                              case 2:
                                {
                                  printf("Ball -> How many?\n= ");
                                  if(scanf("%d",&count)){};
                                  if(count*49>cash)
                                  {
                                    printf("Not enough cash!\n");
                                  }
                                  else
                                  {
                                    printf("Buy 'Ball *%d' finish.\n",count);
                                    shop=count*49;
                                  }
                                  break;
                                }
                              case 3:
                                {
                                  printf("Pencil -> How many?\n= ");
                                  if(scanf("%d",&count)){};
                                  if(count*3>cash)
                                  {
                                    printf("Not enough cash!\n");
                                  }
                                  else
                                  {
                                    printf("Buy 'Pencil *%d' finish.\n",count);
                                    shop=count*3;
                                  }
                                  break;
                                }
                              case 4:
                                {
                                  printf("Notebook -> How many?\n= ");
                                  if(scanf("%d",&count)){};
                                  if(count*20>cash)
                                  {
                                    printf("Not enough cash!");
                                  }
                                  else
                                  {
                                    printf("Buy 'Notebook *%d' finish.\n",count);
                                    shop=count*20;
                                  }
                                  break;
                                }
                              case 5: 
                                check3 = 0;
                                printf("\n-------------------------------------\n");
                                printf("       Thank you for being you.\n");
                                printf("-------------------------------------\n");
                                break;
                              default: 
                                printf("!!No command!!\n");
                            }
                        }
                        else shop=0;
                      }
                    check2=0;
                  
                  break;
                
                default: 
                  printf("!!No command!!\n");
                  printf("\033[0;0H\033[2J");//
              }
            }
          
          }
        }
        else 
        {
          printf("\033[0;0H\033[2J"); //system clear
          check = 1;
        }
        break;
      default:
        printf("\033[0;0H\033[2J");
        printf("!!No command!!\n");
    }
  }
  return 0;
}