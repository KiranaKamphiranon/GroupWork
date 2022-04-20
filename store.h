  #include <stdio.h>
  #include <string.h>
  #include <stdlib.h>
  //#include "Swap.h"

  void menu(void)
  {
    printf("-------------------------------------\n");
    printf("|       BOOK SHOP BY VOLUNTEER      |\n");
    printf("|    for buying and selling books   |");
    printf("\n-------------------------------------\n");
    printf("|    [ 1 ] CHECK STOCK              |\n");
    printf("|    [ 2 ] SELL                     |\n");              
    printf("|    [ 3 ] BUY                      |\n");
    printf("|    [ 4 ] DONATE MONEY             |\n");
    printf("|    [ 5 ] EXIT                     |");
    printf("\n-------------------------------------\n");
  }
  
  struct node
  {
      int qty,price;
      char bookname[100];
      struct node *next;
  };
  typedef struct node NODE;
  typedef NODE* NodePtr;
  
  
  //sell รับหนังสือเข้ามา สร้างลิสต์เก็บหนังสือ
  int sell(NodePtr *STOCK, char Bookname[],int price, int qty ){ 
    NodePtr newstock;
    NodePtr previous;
    NodePtr current;
    newstock=(NodePtr) malloc(sizeof(NODE));
    if ( newstock != NULL ){
      newstock->qty = qty;
      newstock->price = price;
      strcpy(newstock->bookname,Bookname);
      newstock->next = NULL; 
      previous = NULL;
      current = *STOCK; 
    }
    while ( current != NULL && strcmp(current->bookname,Bookname) < 0 ){
          previous = current; 
          current = current->next;
      }
    /*if (strcmp(current->bookname,Bookname) == 0){
          printf("The name is unviable!!!\n");
      return 0;
    }*/
    if ( previous == NULL ) { 
      newstock->next = *STOCK;
      *STOCK = newstock;
    } 
    else if (current == NULL) {
      previous->next = newstock;
    }
    else { 
      previous->next = newstock;
      newstock->next = current;
    } 
    return 1;
  }
  
  
  
  //buy เอาหนังสือออก ลบหนังสือที่จะเอาออก
  int buy(NodePtr *STOCK, char bookname[],int Qty)  
  {
    
    int price;
    NODE *previousPtr,*currentPtr,*tempPtr,*previousPtr1,*currentPtr1;
    previousPtr1 = NULL;
    currentPtr1 =  *STOCK;
    while(currentPtr1!=NULL && strcmp(currentPtr1->bookname,bookname)!=0)
      {
        previousPtr1 = currentPtr1;
        currentPtr1 = currentPtr1->next;
      }
    if ( currentPtr1!= NULL )   
    {
      currentPtr1->qty -= Qty;
      price = ((currentPtr1->price)*140/100)*Qty;
      //printf("%d\n",currentPtr1->qty);
    }
    
    if(currentPtr1->qty==0)
    {
      if ( strcmp((*STOCK)->bookname,bookname)==0 ) //กรณีตัวแรก
      { 
      tempPtr = *STOCK;
      if((*STOCK)->next != NULL) //ตัวหน้าแต่ไม่เวรี่เฟิร์ส
      {
        *STOCK = (*STOCK)->next;
      }
      else //เวรี่เฟิร์ส
        *STOCK=NULL;
      free(tempPtr);
      }
      else //กรณีลบระหว่าง
      { 
        previousPtr = *STOCK;
        currentPtr = (*STOCK)->next;
      }
      //หาตำแหน่ง
      while(currentPtr!=NULL && strcmp(currentPtr->bookname,bookname)!=0)
      {
        previousPtr = currentPtr;
        currentPtr = currentPtr->next;
      }
      if(currentPtr!=NULL)
      {
        tempPtr = currentPtr; //ให้ค่านั้นเป็นTemp
        if(currentPtr->next != NULL) //เช็คกรณีกลับตัวแรกNULL
        {
          previousPtr->next = currentPtr->next;
        }
        else
        {
          previousPtr->next = NULL;
        }
        free(tempPtr);
      }
    }
    
  return price;
}

    
void printStock(NodePtr *STOCK)
{
  NodePtr start;
  start = *STOCK;
  puts( "The Stock:" );
  while ( start != NULL )
  { 
    printf("%-20s%4d bath  ",start->bookname,(start->price)*140/100);
    printf( " [%d] \n", start->qty );
    start = start->next;   
  } 
}

int checkstock(NodePtr *STOCK, char Bookname[]){
  NodePtr currentPtr,previousPtr;
  previousPtr=NULL;
  currentPtr = *STOCK;
  while(currentPtr!=NULL && strcmp(currentPtr->bookname,Bookname)!=0)
      {
        previousPtr = currentPtr;
        currentPtr = currentPtr->next;
      }
  if (currentPtr == NULL){
    return 0;
  }
  else return 1;
}

int checkquan(NodePtr *STOCK, int qty,char bookname[]){
  NodePtr currentPtr,previousPtr;
  previousPtr=NULL;
  currentPtr = *STOCK;
  while(currentPtr!=NULL && strcmp(currentPtr->bookname,bookname)!=0)
      {
        previousPtr = currentPtr;
        currentPtr = currentPtr->next;
      }
  if ((currentPtr->qty)>=qty){
    return 0;
  }
  else return 1;
}

void swap(NodePtr x,NodePtr y)
{
  NodePtr t=x;
  x->price=y->price;
  y->price=t->price;
  x->qty=y->qty;
  y->qty=t->qty;
  strcpy(x->bookname,y->bookname);
  strcpy(y->bookname,t->bookname);
}

void SwapPrice(NodePtr *STOCK)
{
  int sorted;
  NodePtr setpre,setcur,setstock;
  setstock=*STOCK;
  setpre=*STOCK;
  setcur=setpre->next;
  for(;setstock!=NULL;setstock=setstock->next)
  {
  setpre=*STOCK;
  setcur=setpre->next;
  sorted=0;
   for( ;setcur!=NULL;setpre=setpre->next)
   {
     if(setpre->price > setcur->price)
     {
       printf("Hello\n");
      swap(setpre, setcur);
      sorted=1;
     }
     setcur=setcur->next;
     if (setcur==NULL)
       
      if(setpre->price > setcur->price)
     {
       printf("Hello\n");
      swap(setpre, setcur);
      sorted=1;
     }
   }
   if(sorted==0) 
    break;
  }
}

void SwapName(NodePtr *STOCK)
{
  int sorted;
  NodePtr setpre,setcur,setstock;
  setstock=*STOCK;
  setpre=*STOCK;
  setcur=setpre->next;
  for(;setstock!=NULL;setstock=setstock->next)
  {
    setpre=*STOCK;
    setcur=setpre->next;
    sorted=0;
    for( ;setpre!=NULL;setpre=setpre->next)
    {
      if(setcur != NULL)
      {
        if(strcmp(setpre->bookname,setcur->bookname) > 0)
        {
          NodePtr t=(NodePtr) malloc(sizeof(NODE));
          t->price=setpre->price;
          t->qty=setpre->qty;
          strcpy(t->bookname,setpre->bookname);
          setpre->price=setcur->price;
          setcur->price=t->price;
          setpre->qty=setcur->qty;
          setcur->qty=t->qty;
          strcpy(setpre->bookname,setcur->bookname);
          strcpy(setcur->bookname,t->bookname);
          sorted=1;
         }
       }
       if (setcur!=NULL) setcur=setcur->next;
    }
  if(sorted==0) 
    break;
  }
}

void SwapQty(NodePtr *STOCK)
{
  int sorted;
  NodePtr setpre,setcur,setstock;
  setstock=*STOCK;
  setpre=*STOCK;
  setcur=setpre->next;
  for(;setstock!=NULL;setstock=setstock->next)
  {
  setpre=*STOCK;
  setcur=setpre->next;
  sorted=0;
   for( ;setpre!=NULL;setpre=setpre->next)
   {
      if(setcur != NULL)
      {
        if(setpre->qty < setcur->qty)
        {
        NodePtr t=(NodePtr) malloc(sizeof(NODE));
        t->price=setpre->price;
        t->qty=setpre->qty;
        strcpy(t->bookname,setpre->bookname);
        setpre->price=setcur->price;
        setcur->price=t->price;
        setpre->qty=setcur->qty;
        setcur->qty=t->qty;
        strcpy(setpre->bookname,setcur->bookname);
        strcpy(setcur->bookname,t->bookname);
        //swap(setpre, setcur);
        sorted=1;
      }
    }
     if (setcur!=NULL) setcur=setcur->next;
   }
   if(sorted==0) 
    break;
  }
}