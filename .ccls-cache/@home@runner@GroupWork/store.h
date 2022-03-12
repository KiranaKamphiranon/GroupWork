  #include <stdio.h>
  #include <string.h>
  #include <stdlib.h>

struct node
  {
      int qty,price;
      char bookname[100];
      struct node *next;
  };
  typedef struct node NODE;
  typedef NODE* NodePtr;

void menu(void);
int sell(NodePtr *STOCK , char Bookname[],int price, int qty);
int buy(NodePtr *STOCK , char bookname[],int Qty);
void printStock(NodePtr *STOCK);
int checkstock(NodePtr *STOCK , char Bookname[] );
int checkquan(NodePtr *STOCK , int qty,char bookname[]);
void SwapPrice(NodePtr *STOCK);
void SwapQty(NodePtr *STOCK);
void SwapName(NodePtr *STOCK);


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
    if ( previous == NULL ) { 
      newstock->next = *STOCK;
      *STOCK = newstock;
    } //ตัวแรก
    else if (current == NULL) {
      previous->next = newstock;
    }//ตัวสุดท้าย
    else { 
      previous->next = newstock;
      newstock->next = current;
    } //ระหว่างกลาง
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
        currentPtr = currentPtr->next;
        if(currentPtr != NULL) 
        {
          previousPtr->next = currentPtr;
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
  while ( start != NULL )
  { 
    printf("%-20s%5d bath",start->bookname,(start->price)*140/100);
    printf( " [%2d] \n", start->qty );
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
   for( ;setpre!=NULL;setpre=setpre->next)
   {
      if(setcur != NULL)
      {
        if(setpre->price < setcur->price)
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
        sorted=1;
      }
    }
     if (setcur!=NULL) setcur=setcur->next;
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
