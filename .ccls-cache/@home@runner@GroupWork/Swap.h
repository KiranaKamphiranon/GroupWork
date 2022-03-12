/*#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "store.h"*/
/*
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
  int i,j,sorted;
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
      swap(setpre, setcur);
      sorted=1;
     }
     setcur=setcur->next;
   }
   if(sorted==0) 
    break;
  }
}*/
/*
void SwapQty(NodePtr *STOCK)
{
  int i=0,j=0,n[50],temp,size=0;
  NodePtr stock,stock1;
  stock = *STOCK;
  stock1= *STOCK;
  //puts( "The Stock:" );
  while ( stock != NULL )
  { 
    n[j]=stock->qty;
    printf( " %d \n", n[j] );
    stock = stock->next; 
    j++;
    size++;
  }
  i=0;
  j=1;
  while ( stock1 != NULL )
  { 
    while(j>i){
    if(n[j-1]>n[j]){
      temp=n[j-1];
      n[j-1]=n[j];
      n[j]=temp;
    }
    stock1 = stock1->next; 
    j++;
    }
    
    i++;
    j=i+1;
  }
  for(int j=0;j<size;j++)
    {
      printf("%d\t",n[j]);
    }
  
}

void SwapName(NodePtr *STOCK)
{
  
}
*/